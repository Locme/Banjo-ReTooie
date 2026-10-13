#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sujiggy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6C8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6C8);
    return;
    // 0x8008A6CC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855F8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855F8);
    return;
    // 0x800855FC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089888: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089888);
    return;
    // 0x8008988C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_8009FA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FA20: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009FA24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009FA28: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8009FA2C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8009FA30: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8009FA34: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8009FA38: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8009FA3C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009FA40: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8009FA44: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8009FA48: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA4C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8009FA50: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8009FA54: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009FA58: jal         0x800EFA4C
    // 0x8009FA5C: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8009FA5C: nop

    after_0:
    // 0x8009FA60: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009FA64: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8009FA68: jal         0x800A3200
    // 0x8009FA6C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800A3200(rdram, ctx);
        goto after_1;
    // 0x8009FA6C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x8009FA70: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009FA74: jal         0x800F4200
    // 0x8009FA78: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F4200(rdram, ctx);
        goto after_2;
    // 0x8009FA78: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x8009FA7C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009FA80: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009FA84: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009FA88: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009FA8C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8009FA90: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009FA94: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009FA98: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009FA9C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009FAA0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009FAA4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009FAA8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009FAAC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009FAB0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009FAB4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009FAB8: jal         0x800EFA4C
    // 0x8009FABC: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x8009FABC: nop

    after_3:
    // 0x8009FAC0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009FAC4: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009FAC8: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009FACC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8009FAD0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8009FAD4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009FAD8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8009FADC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009FAE0: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009FAE4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8009FAE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009FAEC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009FAF0: add.s       $f20, $f16, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8009FAF4: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x8009FAF8: nop

    // 0x8009FAFC: bc1f        L_8009FB0C
    if (!c1cs) {
        // 0x8009FB00: nop
    
            goto L_8009FB0C;
    }
    // 0x8009FB00: nop

    // 0x8009FB04: b           L_8009FB9C
    // 0x8009FB08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009FB9C;
    // 0x8009FB08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009FB0C:
    // 0x8009FB0C: jal         0x8002DCA0
    // 0x8009FB10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8009FB10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
    // 0x8009FB14: jal         0x800D8FF8
    // 0x8009FB18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x8009FB18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8009FB1C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8009FB20: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8009FB24: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8009FB28: jal         0x800F13F0
    // 0x8009FB2C: sub.s       $f14, $f16, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_6;
    // 0x8009FB2C: sub.s       $f14, $f16, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f20.fl;
    after_6:
    // 0x8009FB30: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009FB34: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8009FB38: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x8009FB3C: nop

    // 0x8009FB40: bc1fl       L_8009FB78
    if (!c1cs) {
        // 0x8009FB44: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8009FB78;
    }
    goto skip_0;
    // 0x8009FB44: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    skip_0:
    // 0x8009FB48: jal         0x800DC0C0
    // 0x8009FB4C: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x8009FB4C: nop

    after_7:
    // 0x8009FB50: jal         0x800DC0C0
    // 0x8009FB54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x8009FB54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x8009FB58: jal         0x800DC0C0
    // 0x8009FB5C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x8009FB5C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8009FB60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009FB64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009FB68: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009FB6C: jal         0x800EFA4C
    // 0x8009FB70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x8009FB70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x8009FB74: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_8009FB78:
    // 0x8009FB78: jal         0x800EF368
    // 0x8009FB7C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_800EF368(rdram, ctx);
        goto after_11;
    // 0x8009FB7C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_11:
    // 0x8009FB80: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009FB84: jal         0x800EF04C
    // 0x8009FB88: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x8009FB88: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x8009FB8C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009FB90: jal         0x800F4648
    // 0x8009FB94: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F4648(rdram, ctx);
        goto after_13;
    // 0x8009FB94: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_13:
    // 0x8009FB98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009FB9C:
    // 0x8009FB9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FBA0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8009FBA4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8009FBA8: jr          $ra
    // 0x8009FBAC: nop

    return;
    // 0x8009FBAC: nop

;}
RECOMP_FUNC void func_80800EC8_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800ECC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800ED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800ED4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800ED8: jal         0x80800694
    // 0x80800EDC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800EDC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EE8: jal         0x8009D2F0
    // 0x80800EEC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x80800EEC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x80800EF0: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x80800EF4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800EF8: jal         0x8008CB10
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F00: beq         $v0, $zero, L_80800F24
    if (ctx->r2 == 0) {
        // 0x80800F04: lui         $a3, 0x3FAC
        ctx->r7 = S32(0X3FAC << 16);
            goto L_80800F24;
    }
    // 0x80800F04: lui         $a3, 0x3FAC
    ctx->r7 = S32(0X3FAC << 16);
    // 0x80800F08: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x80800F0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F10: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: addiu       $a1, $zero, 0x555
    ctx->r5 = ADD32(0, 0X555);
    // 0x80800F1C: jal         0x8009DBB0
    // 0x80800F20: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    func_8009DBB0(rdram, ctx);
        goto after_3;
    // 0x80800F20: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    after_3:
L_80800F24:
    // 0x80800F24: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80800F28: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800F2C: jal         0x8008CB10
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800F34: beq         $v0, $zero, L_80800F58
    if (ctx->r2 == 0) {
        // 0x80800F38: lui         $a3, 0x3FAC
        ctx->r7 = S32(0X3FAC << 16);
            goto L_80800F58;
    }
    // 0x80800F38: lui         $a3, 0x3FAC
    ctx->r7 = S32(0X3FAC << 16);
    // 0x80800F3C: addiu       $t7, $zero, 0x2710
    ctx->r15 = ADD32(0, 0X2710);
    // 0x80800F40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800F44: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F4C: addiu       $a1, $zero, 0x556
    ctx->r5 = ADD32(0, 0X556);
    // 0x80800F50: jal         0x8009DBB0
    // 0x80800F54: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    func_8009DBB0(rdram, ctx);
        goto after_5;
    // 0x80800F54: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    after_5:
L_80800F58:
    // 0x80800F58: jal         0x80800134
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800134_bsbabykaz(rdram, ctx);
        goto after_6;
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800F60: jal         0x8009EF10
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F68: bne         $v0, $zero, L_80800F84
    if (ctx->r2 != 0) {
        // 0x80800F6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F84;
    }
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F70: jal         0x8009BCD4
    // 0x80800F74: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_8;
    // 0x80800F74: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_8:
    // 0x80800F78: beq         $v0, $zero, L_80800F84
    if (ctx->r2 == 0) {
        // 0x80800F7C: addiu       $t8, $zero, 0x136
        ctx->r24 = ADD32(0, 0X136);
            goto L_80800F84;
    }
    // 0x80800F7C: addiu       $t8, $zero, 0x136
    ctx->r24 = ADD32(0, 0X136);
    // 0x80800F80: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800F84:
    // 0x80800F84: jal         0x8008E148
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_9;
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800F8C: beq         $v0, $zero, L_80800FA0
    if (ctx->r2 == 0) {
        // 0x80800F90: nop
    
            goto L_80800FA0;
    }
    // 0x80800F90: nop

    // 0x80800F94: jal         0x800848B0
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_10;
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800F9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800FA0:
    // 0x80800FA0: jal         0x8008DD04
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_11;
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800FA8: beq         $v0, $zero, L_80800FB8
    if (ctx->r2 == 0) {
        // 0x80800FAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FB8;
    }
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB0: addiu       $t9, $zero, 0x133
    ctx->r25 = ADD32(0, 0X133);
    // 0x80800FB4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80800FB8:
    // 0x80800FB8: jal         0x80091A58
    // 0x80800FBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_12;
    // 0x80800FBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80800FC0: beq         $v0, $zero, L_80800FCC
    if (ctx->r2 == 0) {
        // 0x80800FC4: addiu       $t0, $zero, 0x134
        ctx->r8 = ADD32(0, 0X134);
            goto L_80800FCC;
    }
    // 0x80800FC4: addiu       $t0, $zero, 0x134
    ctx->r8 = ADD32(0, 0X134);
    // 0x80800FC8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800FCC:
    // 0x80800FCC: jal         0x808000F8
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F8_bsbabykaz(rdram, ctx);
        goto after_13;
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800FD4: beq         $v0, $zero, L_80800FE4
    if (ctx->r2 == 0) {
        // 0x80800FD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FE4;
    }
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FDC: addiu       $t1, $zero, 0x94
    ctx->r9 = ADD32(0, 0X94);
    // 0x80800FE0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800FE4:
    // 0x80800FE4: jal         0x8009E5C8
    // 0x80800FE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80800FE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x80800FEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800FF8: jr          $ra
    // 0x80800FFC: nop

    return;
    // 0x80800FFC: nop

;}
RECOMP_FUNC void dbmorph_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80800000
    // 0x80800064: nop

    func_80800000_dbmorph(rdram, ctx);
        goto after_0;
    // 0x80800064: nop

    after_0:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B38: jal         0x80800144
    // 0x80800B3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800B44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B54: jal         0x8009FFD8
    // 0x80800B58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800B58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B60: jal         0x8009B9B0
    // 0x80800B64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800B64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800B68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B6C: jal         0x80800A18
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800A18_bstaxi(rdram, ctx);
        goto after_3;
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B7C: jr          $ra
    // 0x80800B80: nop

    return;
    // 0x80800B80: nop

;}
RECOMP_FUNC void func_808005B8_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005C8: jal         0x8010A5B0
    // 0x808005CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_8010A5B0(rdram, ctx);
        goto after_0;
    // 0x808005CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808005D0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808005D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005D8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808005DC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808005E0: bne         $t7, $at, L_80800624
    if (ctx->r15 != ctx->r1) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: bne         $t8, $zero, L_808005F4
    if (ctx->r24 != 0) {
        // 0x808005EC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_808005F4;
    }
    // 0x808005EC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x808005F0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_808005F4:
    // 0x808005F4: jal         0x80103EF4
    // 0x808005F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80103EF4(rdram, ctx);
        goto after_1;
    // 0x808005F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005FC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800600: jal         0x80103EAC
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_2;
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800608: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080060C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800610: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800614: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800618: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080061C: jal         0x80089F20
    // 0x80800620: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800620: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_80800624:
    // 0x80800624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800628: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080062C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void func_80801C9C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CA4: jal         0x80082FE8
    // 0x80801CA8: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801CA8: nop

    after_0:
    // 0x80801CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CB4: jr          $ra
    // 0x80801CB8: nop

    return;
    // 0x80801CB8: nop

;}
RECOMP_FUNC void func_80800CB0_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800CB4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800CB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CBC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800CC0: beq         $a1, $at, L_80800D90
    if (ctx->r5 == ctx->r1) {
        // 0x80800CC4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800D90;
    }
    // 0x80800CC4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800CC8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800CCC: beq         $a1, $at, L_80800E00
    if (ctx->r5 == ctx->r1) {
        // 0x80800CD0: lh          $t6, 0x48($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X48);
            goto L_80800E00;
    }
    // 0x80800CD0: lh          $t6, 0x48($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X48);
    // 0x80800CD4: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800CD8: beq         $a1, $at, L_80800CF4
    if (ctx->r5 == ctx->r1) {
        // 0x80800CDC: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_80800CF4;
    }
    // 0x80800CDC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800CE0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800CE4: beq         $a1, $at, L_80800E1C
    if (ctx->r5 == ctx->r1) {
        // 0x80800CE8: addiu       $a0, $zero, 0x3EA
        ctx->r4 = ADD32(0, 0X3EA);
            goto L_80800E1C;
    }
    // 0x80800CE8: addiu       $a0, $zero, 0x3EA
    ctx->r4 = ADD32(0, 0X3EA);
    // 0x80800CEC: b           L_80800EC4
    // 0x80800CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EC4;
    // 0x80800CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CF4:
    // 0x80800CF4: beq         $t6, $zero, L_80800D1C
    if (ctx->r14 == 0) {
        // 0x80800CF8: addiu       $a0, $zero, 0x6AB
        ctx->r4 = ADD32(0, 0X6AB);
            goto L_80800D1C;
    }
    // 0x80800CF8: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    // 0x80800CFC: lbu         $t8, 0x65($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X65);
    // 0x80800D00: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800D04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D08: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800D0C: sb          $t9, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r25;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800D14: b           L_80800EC4
    // 0x80800D18: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
        goto L_80800EC4;
    // 0x80800D18: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
L_80800D1C:
    // 0x80800D1C: jal         0x800DA298
    // 0x80800D20: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800D20: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800D24: bne         $v0, $zero, L_80800D64
    if (ctx->r2 != 0) {
        // 0x80800D28: nop
    
            goto L_80800D64;
    }
    // 0x80800D28: nop

    // 0x80800D2C: jal         0x80086B58
    // 0x80800D30: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800D30: nop

    after_1:
    // 0x80800D34: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800D38: addiu       $t0, $zero, 0xA3
    ctx->r8 = ADD32(0, 0XA3);
    // 0x80800D3C: addiu       $a1, $zero, 0x133E
    ctx->r5 = ADD32(0, 0X133E);
    // 0x80800D40: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800D44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800D48: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800D4C: jal         0x8008A208
    // 0x80800D50: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800D50: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80800D54: jal         0x800DA544
    // 0x80800D58: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800D58: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    after_3:
    // 0x80800D5C: b           L_80800D70
    // 0x80800D60: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_80800D70;
    // 0x80800D60: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_80800D64:
    // 0x80800D64: jal         0x800CF2D4
    // 0x80800D68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CF2D4(rdram, ctx);
        goto after_4;
    // 0x80800D68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x80800D6C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_80800D70:
    // 0x80800D70: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800D74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D78: lbu         $t1, 0x65($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X65);
    // 0x80800D7C: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80800D80: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x80800D84: sb          $t2, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r10;
    // 0x80800D88: b           L_80800EC4
    // 0x80800D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EC4;
    // 0x80800D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D90:
    // 0x80800D90: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80800D94: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800D98: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80800D9C: bne         $t3, $at, L_80800DF8
    if (ctx->r11 != ctx->r1) {
        // 0x80800DA0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800DF8;
    }
    // 0x80800DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DA4: jal         0x800D0634
    // 0x80800DA8: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_800D0634(rdram, ctx);
        goto after_5;
    // 0x80800DA8: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800DAC: jal         0x80106790
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800DB4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800DB8: jal         0x800EE7F8
    // 0x80800DBC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800DBC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_7:
    // 0x80800DC0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80800DC4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800DC8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800DCC: lwc1        $f0, 0x1C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80800DD0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80800DD4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800DD8: nop

    // 0x80800DDC: bc1fl       L_80800DF0
    if (!c1cs) {
        // 0x80800DE0: swc1        $f10, 0x1C($t5)
        MEM_W(0X1C, ctx->r13) = ctx->f10.u32l;
            goto L_80800DF0;
    }
    goto skip_0;
    // 0x80800DE0: swc1        $f10, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f10.u32l;
    skip_0:
    // 0x80800DE4: b           L_80800DF0
    // 0x80800DE8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_80800DF0;
    // 0x80800DE8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800DEC: swc1        $f10, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f10.u32l;
L_80800DF0:
    // 0x80800DF0: jal         0x80085738
    // 0x80800DF4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _capod_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x80800DF4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_8:
L_80800DF8:
    // 0x80800DF8: b           L_80800EC4
    // 0x80800DFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800EC4;
    // 0x80800DFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800E00:
    // 0x80800E00: addiu       $at, $zero, 0x133E
    ctx->r1 = ADD32(0, 0X133E);
    // 0x80800E04: bne         $t6, $at, L_80800E14
    if (ctx->r14 != ctx->r1) {
        // 0x80800E08: nop
    
            goto L_80800E14;
    }
    // 0x80800E08: nop

    // 0x80800E0C: jal         0x800CF2D4
    // 0x80800E10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CF2D4(rdram, ctx);
        goto after_9;
    // 0x80800E10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
L_80800E14:
    // 0x80800E14: b           L_80800EC4
    // 0x80800E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EC4;
    // 0x80800E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E1C:
    // 0x80800E1C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2308, 0X1028) << 16);
    // 0x80800E20: addiu       $a1, $a1, 0x1028
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2308, 0X1028));
    // 0x80800E24: jal         0x80108474
    // 0x80800E28: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    func_80108474(rdram, ctx);
        goto after_10;
    // 0x80800E28: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    after_10:
    // 0x80800E2C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E34: jal         0x80109F08
    // 0x80800E38: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109F08(rdram, ctx);
        goto after_11;
    // 0x80800E38: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_11:
    // 0x80800E3C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800E40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E44: slti        $at, $t7, 0x64
    ctx->r1 = SIGNED(ctx->r15) < 0X64 ? 1 : 0;
    // 0x80800E48: bnel        $at, $zero, L_80800E78
    if (ctx->r1 != 0) {
        // 0x80800E4C: lw          $t2, 0x0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X0);
            goto L_80800E78;
    }
    goto skip_1;
    // 0x80800E4C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80800E50: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E54: addiu       $a1, $zero, 0x885
    ctx->r5 = ADD32(0, 0X885);
    // 0x80800E58: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800E5C: jal         0x80103140
    // 0x80800E60: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    func_80103140(rdram, ctx);
        goto after_12;
    // 0x80800E60: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    after_12:
    // 0x80800E64: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80800E68: addiu       $t0, $t9, -0x64
    ctx->r8 = ADD32(ctx->r25, -0X64);
    // 0x80800E6C: b           L_80800E84
    // 0x80800E70: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
        goto L_80800E84;
    // 0x80800E70: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80800E74: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
L_80800E78:
    // 0x80800E78: addiu       $a1, $zero, 0x884
    ctx->r5 = ADD32(0, 0X884);
    // 0x80800E7C: jal         0x80103140
    // 0x80800E80: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_13;
    // 0x80800E80: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_13:
L_80800E84:
    // 0x80800E84: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80800E88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800E8C: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800E90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E94: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800E98: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800E9C: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x80800EA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800EA4: jal         0x800F10B4
    // 0x80800EA8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80800EA8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_14:
    // 0x80800EAC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800EB4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800EB8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800EBC: b           L_80800EC4
    // 0x80800EC0: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
        goto L_80800EC4;
    // 0x80800EC0: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_80800EC4:
    // 0x80800EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800ECC: jr          $ra
    // 0x80800ED0: nop

    return;
    // 0x80800ED0: nop

;}
RECOMP_FUNC void chboilerboss_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2CE4) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x2CE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2CE4));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x2CE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2CE4));
;}
RECOMP_FUNC void func_8009E77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E77C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E784: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009E788: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E78C: jal         0x8009CBDC
    // 0x8009E790: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8009CBDC(rdram, ctx);
        goto after_0;
    // 0x8009E790: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8009E794: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E79C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E7A0: xor         $v0, $v0, $t7
    ctx->r2 = ctx->r2 ^ ctx->r15;
    // 0x8009E7A4: jr          $ra
    // 0x8009E7A8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8009E7A8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void _sukickball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AB8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AB8);
    return;
    // 0x80089ABC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bskaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000A8: jal         0x80095774
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808000B0: jal         0x80085048
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bashoes_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: jal         0x80092864
    // 0x808000C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_2;
    // 0x808000C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_80094C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094C88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094C8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80094C90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80094C94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80094C98: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80094C9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094CA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80094CA4: jal         0x80094C64
    // 0x80094CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80094C64(rdram, ctx);
        goto after_0;
    // 0x80094CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80094CAC: beq         $v0, $zero, L_80094CEC
    if (ctx->r2 == 0) {
        // 0x80094CB0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094CEC;
    }
    // 0x80094CB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094CB4:
    // 0x80094CB4: jal         0x800883E8
    // 0x80094CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80094CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80094CBC: beql        $v0, $zero, L_80094CD8
    if (ctx->r2 == 0) {
        // 0x80094CC0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80094CD8;
    }
    goto skip_0;
    // 0x80094CC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80094CC4: jal         0x800883E0
    // 0x80094CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80094CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80094CCC: jal         0x800D1824
    // 0x80094CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1824(rdram, ctx);
        goto after_3;
    // 0x80094CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80094CD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80094CD8:
    // 0x80094CD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80094CDC: jal         0x80094C64
    // 0x80094CE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80094C64(rdram, ctx);
        goto after_4;
    // 0x80094CE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80094CE4: bne         $v0, $zero, L_80094CB4
    if (ctx->r2 != 0) {
        // 0x80094CE8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094CB4;
    }
    // 0x80094CE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094CEC:
    // 0x80094CEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80094CF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80094CF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80094CF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80094CFC: jr          $ra
    // 0x80094D00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80094D00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsturn_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: jal         0x8008CABC
    // 0x80800118: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x8080011C: jal         0x8008B2B4
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800128: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(420, 0X350) << 16);
    // 0x8080012C: lw          $a3, 0x16C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X16C);
    // 0x80800130: lwc1        $f14, 0x350($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(420, 0X350));
    // 0x80800134: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800138: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080013C: jal         0x800F10B4
    // 0x80800140: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800140: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800144: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800148: jal         0x8009B9B0
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800150: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80800154: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x80800158: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8080015C: bne         $at, $zero, L_8080016C
    if (ctx->r1 != 0) {
        // 0x80800160: sw          $v1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r3;
            goto L_8080016C;
    }
    // 0x80800160: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
    // 0x80800164: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800168: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
L_8080016C:
    // 0x8080016C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800170: beq         $v1, $at, L_80800190
    if (ctx->r3 == ctx->r1) {
        // 0x80800174: nop
    
            goto L_80800190;
    }
    // 0x80800174: nop

    // 0x80800178: beq         $v1, $zero, L_808001DC
    if (ctx->r3 == 0) {
        // 0x8080017C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808001DC;
    }
    // 0x8080017C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800180: beq         $v1, $at, L_80800208
    if (ctx->r3 == ctx->r1) {
        // 0x80800184: nop
    
            goto L_80800208;
    }
    // 0x80800184: nop

    // 0x80800188: b           L_8080024C
    // 0x8080018C: nop

        goto L_8080024C;
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: jal         0x8009BB18
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_4;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800198: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080019C: jal         0x8009BB5C
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_5;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808001A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(420, 0X354) << 16);
    // 0x808001B0: lwc1        $f16, 0x354($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(420, 0X354));
    // 0x808001B4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001C0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808001C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808001C8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808001CC: jal         0x800849E0
    // 0x808001D0: nop

    _badust_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808001D0: nop

    after_6:
    // 0x808001D4: b           L_8080024C
    // 0x808001D8: nop

        goto L_8080024C;
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: jal         0x8009BB18
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_7;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001E4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001E8: jal         0x8009BB5C
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_8;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x800849E0
    // 0x808001FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _badust_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808001FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800200: b           L_8080024C
    // 0x80800204: nop

        goto L_8080024C;
    // 0x80800204: nop

L_80800208:
    // 0x80800208: jal         0x8009BB18
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_10;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800210: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800214: jal         0x8009BB5C
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_11;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080021C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(420, 0X358) << 16);
    // 0x80800228: lwc1        $f10, 0x358($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(420, 0X358));
    // 0x8080022C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800238: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080023C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800240: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800244: jal         0x800849E0
    // 0x80800248: nop

    _badust_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800248: nop

    after_12:
L_8080024C:
    // 0x8080024C: jal         0x8008CABC
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_13;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800254: jal         0x8008B324
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_14;
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8080025C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080026C;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800268: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8080026C:
    // 0x8080026C: jal         0x800919F4
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_15;
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800274: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x80800278: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80800280: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800284:
    // 0x80800284: jal         0x80091A58
    // 0x80800288: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80800288: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_16:
    // 0x8080028C: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x800A055C
    // 0x80800298: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800A055C(rdram, ctx);
        goto after_17;
    // 0x80800298: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x8080029C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_808002A0:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80091A58
    // 0x808002A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_18;
    // 0x808002A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x808002AC: beql        $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x808002B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C4;
    }
    goto skip_0;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002B4: jal         0x8009FE84
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_19;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808002BC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002C4:
    // 0x808002C4: jal         0x8009E5C8
    // 0x808002C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x808002C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x808002CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_80800068_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800074: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800078: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080007C: beql        $t6, $zero, L_808000A0
    if (ctx->r14 == 0) {
        // 0x80800080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800084: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x80800088: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x8080008C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800094: jal         0x8010114C
    // 0x80800098: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_0:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_80801B50_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B58: jal         0x80800128
    // 0x80801B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bskazfly(rdram, ctx);
        goto after_0;
    // 0x80801B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801B60: jal         0x80082FE0
    // 0x80801B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801B68: jal         0x80084800
    // 0x80801B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801B70: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80801B74: bne         $v0, $at, L_80801B84
    if (ctx->r2 != ctx->r1) {
        // 0x80801B78: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801B84;
    }
    // 0x80801B78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B7C: jal         0x8009B800
    // 0x80801B80: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_3;
    // 0x80801B80: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
L_80801B84:
    // 0x80801B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B8C: jr          $ra
    // 0x80801B90: nop

    return;
    // 0x80801B90: nop

;}
RECOMP_FUNC void func_80800400_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080040C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800410: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(836, 0X57C) << 16);
    // 0x80800414: addiu       $t7, $t7, 0x57C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(836, 0X57C));
    // 0x80800418: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x8080041C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800420: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800428: jal         0x800BBCB8
    // 0x8080042C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x8080042C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void func_80092D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092DA4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092DA8: jal         0x800921E0
    // 0x80092DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80092DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092DB8: jr          $ra
    // 0x80092DBC: nop

    return;
    // 0x80092DBC: nop

;}
RECOMP_FUNC void func_80800440_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800444: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: beq         $a1, $at, L_80800470
    if (ctx->r5 == ctx->r1) {
        // 0x80800450: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800470;
    }
    // 0x80800450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800454: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800458: beq         $a1, $at, L_80800484
    if (ctx->r5 == ctx->r1) {
        // 0x8080045C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800484;
    }
    // 0x8080045C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800460: beq         $a1, $at, L_808004B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800464: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808004B4;
    }
    // 0x80800464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800468: b           L_808004E8
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E8;
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800470:
    // 0x80800470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800474: jal         0x808004F8
    // 0x80800478: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808004F8_chcactusofstrength(rdram, ctx);
        goto after_0;
    // 0x80800478: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8080047C: b           L_808004E8
    // 0x80800480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x80800480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800484:
    // 0x80800484: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800488: bne         $a2, $at, L_80800498
    if (ctx->r6 != ctx->r1) {
        // 0x8080048C: nop
    
            goto L_80800498;
    }
    // 0x8080048C: nop

    // 0x80800490: jal         0x800FFAB0
    // 0x80800494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800498:
    // 0x80800498: jal         0x800F54E4
    // 0x8080049C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080049C: nop

    after_2:
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A4: jal         0x800F7F98
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808004AC: b           L_808004E8
    // 0x808004B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808004E8;
    // 0x808004B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004B4:
    // 0x808004B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808004B8: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    // 0x808004BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808004C0: jal         0x80089C20
    // 0x808004C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808004C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x808004C8: beq         $v0, $zero, L_808004E4
    if (ctx->r2 == 0) {
        // 0x808004CC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808004E4;
    }
    // 0x808004CC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808004D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808004D4: b           L_808004E4
    // 0x808004D8: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
        goto L_808004E4;
    // 0x808004D8: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x808004DC: b           L_808004E8
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E8;
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004E4:
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E8:
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void _chburgerstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DA0: syscall     239
    recomp_syscall_handler(rdram, ctx, 0x80085DA0);
    return;
    // 0x80085DA4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void babounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C4: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x808004C8: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x808004CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808004D0: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x808004D4: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x808004D8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004DC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x808004E0: jal         0x80800400
    // 0x808004E4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    babounce_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808004E4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    after_0:
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void bswalk_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D74: jal         0x8008E0E8
    // 0x80800D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E0E8(rdram, ctx);
        goto after_0;
    // 0x80800D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D7C: beq         $v0, $zero, L_80800D8C
    if (ctx->r2 == 0) {
        // 0x80800D80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D8C;
    }
    // 0x80800D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D84: jal         0x80084788
    // 0x80800D88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800D88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_80800D8C:
    // 0x80800D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D94: jr          $ra
    // 0x80800D98: nop

    return;
    // 0x80800D98: nop

;}
RECOMP_FUNC void func_80801C18_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C20: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801C24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C28: lw          $v1, 0xA8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA8);
    // 0x80801C2C: beql        $v1, $zero, L_80801C68
    if (ctx->r3 == 0) {
        // 0x80801C30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C68;
    }
    goto skip_0;
    // 0x80801C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801C34: beq         $v1, $at, L_80801C64
    if (ctx->r3 == ctx->r1) {
        // 0x80801C38: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801C64;
    }
    // 0x80801C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801C3C: jal         0x80084AE8
    // 0x80801C40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80801C40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80801C44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C48: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80801C4C: lw          $t6, 0xA8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA8);
    // 0x80801C50: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x80801C54: sw          $t7, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r15;
    // 0x80801C58: sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    // 0x80801C5C: sw          $t6, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r14;
    // 0x80801C60: sw          $t8, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r24;
L_80801C64:
    // 0x80801C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C68:
    // 0x80801C68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C6C: jr          $ra
    // 0x80801C70: nop

    return;
    // 0x80801C70: nop

;}
RECOMP_FUNC void func_800A25DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A25DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A25E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A25E4: beq         $a1, $zero, L_800A25FC
    if (ctx->r5 == 0) {
        // 0x800A25E8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A25FC;
    }
    // 0x800A25E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A25EC: lw          $t7, 0xB4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB4);
    // 0x800A25F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A25F4: b           L_800A2604
    // 0x800A25F8: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
        goto L_800A2604;
    // 0x800A25F8: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
L_800A25FC:
    // 0x800A25FC: lw          $t8, 0xB4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XB4);
    // 0x800A2600: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
L_800A2604:
    // 0x800A2604: lw          $v0, 0xB4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB4);
    // 0x800A2608: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800A260C: beql        $t9, $zero, L_800A2640
    if (ctx->r25 == 0) {
        // 0x800A2610: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_800A2640;
    }
    goto skip_0;
    // 0x800A2610: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800A2614: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800A2618: bnel        $t0, $zero, L_800A2660
    if (ctx->r8 != 0) {
        // 0x800A261C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A2660;
    }
    goto skip_1;
    // 0x800A261C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A2620: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x800A2624: jal         0x800B3310
    // 0x800A2628: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800B3310(rdram, ctx);
        goto after_0;
    // 0x800A2628: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A262C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A2630: lw          $t1, 0xB4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XB4);
    // 0x800A2634: b           L_800A265C
    // 0x800A2638: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
        goto L_800A265C;
    // 0x800A2638: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800A263C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_800A2640:
    // 0x800A2640: beql        $a0, $zero, L_800A2660
    if (ctx->r4 == 0) {
        // 0x800A2644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A2660;
    }
    goto skip_2;
    // 0x800A2644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800A2648: jal         0x800B3370
    // 0x800A264C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800B3370(rdram, ctx);
        goto after_1;
    // 0x800A264C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800A2650: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A2654: lw          $t2, 0xB4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XB4);
    // 0x800A2658: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_800A265C:
    // 0x800A265C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2660:
    // 0x800A2660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2664: jr          $ra
    // 0x800A2668: nop

    return;
    // 0x800A2668: nop

;}
RECOMP_FUNC void func_80800478_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080047C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800488: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8080048C: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800494: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DD4) << 16);
    // 0x80800498: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x8080049C: beq         $a1, $t7, L_808005C0
    if (ctx->r5 == ctx->r15) {
        // 0x808004A0: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_808005C0;
    }
    // 0x808004A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808004A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808004A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808004AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808004B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808004B4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x808004B8: lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DD4));
    // 0x808004BC: beq         $v0, $zero, L_808004D0
    if (ctx->r2 == 0) {
        // 0x808004C0: nop
    
            goto L_808004D0;
    }
    // 0x808004C0: nop

    // 0x808004C4: jalr        $v0
    // 0x808004C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x808004C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_808004D0:
    // 0x808004D0: jal         0x80101FDC
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004D8: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808004DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808004E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808004E4: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x808004E8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808004EC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x808004F0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808004F4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x808004F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808004FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DD0) << 16);
    // 0x80800500: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80800504: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x80800508: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x8080050C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80800510: lw          $v0, 0x7DD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DD0));
    // 0x80800514: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80800518: beql        $v0, $zero, L_8080053C
    if (ctx->r2 == 0) {
        // 0x8080051C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080053C;
    }
    goto skip_0;
    // 0x8080051C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80800520: jalr        $v0
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800528: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080052C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800530: srl         $t3, $v1, 10
    ctx->r11 = S32(U32(ctx->r3) >> 10);
    // 0x80800534: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80800538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8080053C:
    // 0x8080053C: beq         $v1, $at, L_80800588
    if (ctx->r3 == ctx->r1) {
        // 0x80800540: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800588;
    }
    // 0x80800540: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800544: bne         $v1, $at, L_808005A8
    if (ctx->r3 != ctx->r1) {
        // 0x80800548: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808005A8;
    }
    // 0x80800548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080054C: jal         0x80802780
    // 0x80800550: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_80802780_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80800550: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_3:
    // 0x80800554: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080055C: srl         $t4, $a0, 4
    ctx->r12 = S32(U32(ctx->r4) >> 4);
    // 0x80800560: jal         0x8080218C
    // 0x80800564: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80800564: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_4:
    // 0x80800568: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080056C: jal         0x80801658
    // 0x80800570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801658_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80800570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800574: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800578: jal         0x80801714
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801714_chgameselect(rdram, ctx);
        goto after_6;
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800580: b           L_808005AC
    // 0x80800584: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_808005AC;
    // 0x80800584: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800588:
    // 0x80800588: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x8080058C: srl         $t5, $a0, 4
    ctx->r13 = S32(U32(ctx->r4) >> 4);
    // 0x80800590: jal         0x80803DCC
    // 0x80800594: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80803DCC_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80800594: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_7:
    // 0x80800598: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080059C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005A0: jal         0x80803D00
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_808005A8:
    // 0x808005A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_808005AC:
    // 0x808005AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808005B0: beq         $t6, $at, L_808005C0
    if (ctx->r14 == ctx->r1) {
        // 0x808005B4: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_808005C0;
    }
    // 0x808005B4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x808005B8: jal         0x808026C8
    // 0x808005BC: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_9;
    // 0x808005BC: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_9:
L_808005C0:
    // 0x808005C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void func_8080022C_chlagoonlockerdoorhits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800238: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080023C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800240: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800244: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800248: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x8080024C: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    // 0x80800250: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800254: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800258: addiu       $t9, $t8, -0x33
    ctx->r25 = ADD32(ctx->r24, -0X33);
    // 0x8080025C: jal         0x800DA564
    // 0x80800260: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800260: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80800264: bne         $v0, $zero, L_808002C0
    if (ctx->r2 != 0) {
        // 0x80800268: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808002C0;
    }
    // 0x80800268: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080026C: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800270: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8080027C;
    }
    // 0x80800270: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80800274: bnel        $at, $zero, L_808002B4
    if (ctx->r1 != 0) {
        // 0x80800278: addiu       $a0, $zero, 0x3A4
        ctx->r4 = ADD32(0, 0X3A4);
            goto L_808002B4;
    }
    goto skip_0;
    // 0x80800278: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    skip_0:
L_8080027C:
    // 0x8080027C: jal         0x800DC090
    // 0x80800280: nop

    func_800DC090(rdram, ctx);
        goto after_1;
    // 0x80800280: nop

    after_1:
    // 0x80800284: jal         0x800DC090
    // 0x80800288: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    func_800DC090(rdram, ctx);
        goto after_2;
    // 0x80800288: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    after_2:
    // 0x8080028C: addiu       $a0, $zero, 0x39F
    ctx->r4 = ADD32(0, 0X39F);
    // 0x80800290: andi        $a1, $v0, 0x1F
    ctx->r5 = ctx->r2 & 0X1F;
    // 0x80800294: jal         0x800DA7A8
    // 0x80800298: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x80800298: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x8080029C: beq         $s0, $zero, L_8080027C
    if (ctx->r16 == 0) {
        // 0x808002A0: nop
    
            goto L_8080027C;
    }
    // 0x808002A0: nop

    // 0x808002A4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x808002A8: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x808002AC: nop
    
            goto L_8080027C;
    }
    // 0x808002AC: nop

    // 0x808002B0: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
L_808002B4:
    // 0x808002B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002B8: jal         0x800DA7A8
    // 0x808002BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x808002BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
L_808002C0:
    // 0x808002C0: addiu       $a0, $zero, 0x39F
    ctx->r4 = ADD32(0, 0X39F);
    // 0x808002C4: jal         0x800DA564
    // 0x808002C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA564(rdram, ctx);
        goto after_5;
    // 0x808002C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x808002CC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2032, 0X430) << 16);
    // 0x808002D0: addiu       $t0, $t0, 0x430
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2032, 0X430));
    // 0x808002D4: addu        $s2, $v0, $t0
    ctx->r18 = ADD32(ctx->r2, ctx->r8);
    // 0x808002D8: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    // 0x808002DC: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x808002E0: addiu       $s3, $zero, 0x1E
    ctx->r19 = ADD32(0, 0X1E);
L_808002E4:
    // 0x808002E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002E8: jal         0x800BF744
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: jal         0x800BF744
    // 0x808002F8: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    func_800BF744(rdram, ctx);
        goto after_7;
    // 0x808002F8: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_7:
    // 0x808002FC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800300: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80800304: bne         $s0, $s3, L_808002E4
    if (ctx->r16 != ctx->r19) {
        // 0x80800308: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_808002E4;
    }
    // 0x80800308: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080030C: jal         0x808001B0
    // 0x80800310: nop

    func_808001B0_chlagoonlockerdoorhits(rdram, ctx);
        goto after_8;
    // 0x80800310: nop

    after_8:
    // 0x80800314: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    // 0x80800318: jal         0x800DA564
    // 0x8080031C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_9;
    // 0x8080031C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800324: addiu       $t1, $v0, 0x32
    ctx->r9 = ADD32(ctx->r2, 0X32);
    // 0x80800328: lhu         $t2, 0x76($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X76);
    // 0x8080032C: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800330: bnel        $t1, $t3, L_80800348
    if (ctx->r9 != ctx->r11) {
        // 0x80800334: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_80800348;
    }
    goto skip_1;
    // 0x80800334: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800338: jal         0x8010A590
    // 0x8080033C: nop

    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x8080033C: nop

    after_10:
    // 0x80800340: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800344: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
L_80800348:
    // 0x80800348: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2032, 0X3E4) << 16);
    // 0x8080034C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800350: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800354: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80800358: jal         0x80103140
    // 0x8080035C: lhu         $a1, 0x3E4($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(2032, 0X3E4));
    func_80103140(rdram, ctx);
        goto after_11;
    // 0x8080035C: lhu         $a1, 0x3E4($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(2032, 0X3E4));
    after_11:
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800364: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800368: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080036C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800370: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: jr          $ra
    // 0x80800378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801C3C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801C40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C4C: jal         0x8008CABC
    // 0x80801C50: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801C50: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80801C54: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801C58: jal         0x80800164
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_1;
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C64: jal         0x8009BB24
    // 0x80801C68: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_2;
    // 0x80801C68: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80801C6C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80801C70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C78: beq         $v0, $at, L_80801CA8
    if (ctx->r2 == ctx->r1) {
        // 0x80801C7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801CA8;
    }
    // 0x80801C7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C80: beq         $v0, $at, L_80801CF4
    if (ctx->r2 == ctx->r1) {
        // 0x80801C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CF4;
    }
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801C8C: beq         $v0, $at, L_80801D20
    if (ctx->r2 == ctx->r1) {
        // 0x80801C90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D20;
    }
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801C98: beql        $v0, $at, L_80801D58
    if (ctx->r2 == ctx->r1) {
        // 0x80801C9C: lbu         $t6, 0x168($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X168);
            goto L_80801D58;
    }
    goto skip_0;
    // 0x80801C9C: lbu         $t6, 0x168($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X168);
    skip_0:
    // 0x80801CA0: b           L_80801DE4
    // 0x80801CA4: nop

        goto L_80801DE4;
    // 0x80801CA4: nop

L_80801CA8:
    // 0x80801CA8: jal         0x8008DF8C
    // 0x80801CAC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_3;
    // 0x80801CAC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_3:
    // 0x80801CB0: beq         $v0, $zero, L_80801CC8
    if (ctx->r2 == 0) {
        // 0x80801CB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CC8;
    }
    // 0x80801CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CB8: jal         0x80801980
    // 0x80801CBC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801980_bstnt(rdram, ctx);
        goto after_4;
    // 0x80801CBC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80801CC0: b           L_80801CE4
    // 0x80801CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801CE4;
    // 0x80801CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801CC8:
    // 0x80801CC8: jal         0x8008B324
    // 0x80801CCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_5;
    // 0x80801CCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80801CD0: beq         $v0, $zero, L_80801CE0
    if (ctx->r2 == 0) {
        // 0x80801CD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CE0;
    }
    // 0x80801CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD8: jal         0x80801980
    // 0x80801CDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801980_bstnt(rdram, ctx);
        goto after_6;
    // 0x80801CDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_80801CE0:
    // 0x80801CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801CE4:
    // 0x80801CE4: jal         0x808001C8
    // 0x80801CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001C8_bstnt(rdram, ctx);
        goto after_7;
    // 0x80801CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801CEC: b           L_80801DE4
    // 0x80801CF0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80801DE4;
    // 0x80801CF0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80801CF4:
    // 0x80801CF4: jal         0x8008DF8C
    // 0x80801CF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_8;
    // 0x80801CF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_8:
    // 0x80801CFC: beq         $v0, $zero, L_80801D0C
    if (ctx->r2 == 0) {
        // 0x80801D00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D0C;
    }
    // 0x80801D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D04: jal         0x80801980
    // 0x80801D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801980_bstnt(rdram, ctx);
        goto after_9;
    // 0x80801D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
L_80801D0C:
    // 0x80801D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D10: jal         0x808001C8
    // 0x80801D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001C8_bstnt(rdram, ctx);
        goto after_10;
    // 0x80801D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80801D18: b           L_80801DE4
    // 0x80801D1C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80801DE4;
    // 0x80801D1C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80801D20:
    // 0x80801D20: jal         0x8009D3A8
    // 0x80801D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_11;
    // 0x80801D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801D28: jal         0x8008E078
    // 0x80801D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_12;
    // 0x80801D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801D30: beq         $v0, $zero, L_80801D40
    if (ctx->r2 == 0) {
        // 0x80801D34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D40;
    }
    // 0x80801D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D38: jal         0x80801980
    // 0x80801D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801980_bstnt(rdram, ctx);
        goto after_13;
    // 0x80801D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
L_80801D40:
    // 0x80801D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D44: jal         0x808001C8
    // 0x80801D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001C8_bstnt(rdram, ctx);
        goto after_14;
    // 0x80801D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80801D4C: b           L_80801DE4
    // 0x80801D50: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80801DE4;
    // 0x80801D50: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801D54: lbu         $t6, 0x168($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X168);
L_80801D58:
    // 0x80801D58: beql        $t6, $zero, L_80801D78
    if (ctx->r14 == 0) {
        // 0x80801D5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D78;
    }
    goto skip_1;
    // 0x80801D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801D60: jal         0x8008E078
    // 0x80801D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_15;
    // 0x80801D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801D68: beq         $v0, $zero, L_80801D74
    if (ctx->r2 == 0) {
        // 0x80801D6C: addiu       $t7, $zero, 0x10D
        ctx->r15 = ADD32(0, 0X10D);
            goto L_80801D74;
    }
    // 0x80801D6C: addiu       $t7, $zero, 0x10D
    ctx->r15 = ADD32(0, 0X10D);
    // 0x80801D70: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80801D74:
    // 0x80801D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801D78:
    // 0x80801D78: jal         0x8009D3A8
    // 0x80801D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_16;
    // 0x80801D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80801D80: jal         0x8008B324
    // 0x80801D84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_17;
    // 0x80801D84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_17:
    // 0x80801D88: beq         $v0, $zero, L_80801DCC
    if (ctx->r2 == 0) {
        // 0x80801D8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801DCC;
    }
    // 0x80801D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D90: jal         0x8009BB00
    // 0x80801D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80801D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801D98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DA0: addiu       $t8, $zero, 0x10C
    ctx->r24 = ADD32(0, 0X10C);
    // 0x80801DA4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801DA8: nop

    // 0x80801DAC: bc1f        L_80801DC4
    if (!c1cs) {
        // 0x80801DB0: nop
    
            goto L_80801DC4;
    }
    // 0x80801DB0: nop

    // 0x80801DB4: jal         0x80801980
    // 0x80801DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801980_bstnt(rdram, ctx);
        goto after_19;
    // 0x80801DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80801DBC: b           L_80801DD8
    // 0x80801DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801DD8;
    // 0x80801DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801DC4:
    // 0x80801DC4: b           L_80801DD4
    // 0x80801DC8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80801DD4;
    // 0x80801DC8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80801DCC:
    // 0x80801DCC: jal         0x8009B9B0
    // 0x80801DD0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x80801DD0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_20:
L_80801DD4:
    // 0x80801DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801DD8:
    // 0x80801DD8: jal         0x80800218
    // 0x80801DDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80800218_bstnt(rdram, ctx);
        goto after_21;
    // 0x80801DDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_21:
    // 0x80801DE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80801DE4:
    // 0x80801DE4: jal         0x8008E35C
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_22;
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801DEC: beq         $v0, $zero, L_80801DF8
    if (ctx->r2 == 0) {
        // 0x80801DF0: addiu       $t9, $zero, 0x111
        ctx->r25 = ADD32(0, 0X111);
            goto L_80801DF8;
    }
    // 0x80801DF0: addiu       $t9, $zero, 0x111
    ctx->r25 = ADD32(0, 0X111);
    // 0x80801DF4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80801DF8:
    // 0x80801DF8: jal         0x80800F94
    // 0x80801DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80801DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E04: jal         0x8009E5C8
    // 0x80801E08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_24;
    // 0x80801E08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x80801E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801E18: jr          $ra
    // 0x80801E1C: nop

    return;
    // 0x80801E1C: nop

;}
RECOMP_FUNC void bskazglide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAC0) << 16);
    // 0x808006B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006B4: jr          $ra
    // 0x808006B8: lw          $v0, 0xAC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAC0));
    return;
    // 0x808006B8: lw          $v0, 0xAC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAC0));
;}
RECOMP_FUNC void func_80800090_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080009C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x808000A0: bltzl       $t8, L_808000D4
    if (SIGNED(ctx->r24) < 0) {
        // 0x808000A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000A8: jal         0x8001211C
    // 0x808000AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x808000B8: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x808000BC: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808000C0: beql        $at, $zero, L_808000D4
    if (ctx->r1 == 0) {
        // 0x808000C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D4;
    }
    goto skip_1;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000C8: jal         0x8080082C
    // 0x808000CC: nop

    func_8080082C_chbadshad(rdram, ctx);
        goto after_1;
    // 0x808000CC: nop

    after_1:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_8009AD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD88: jr          $ra
    // 0x8009AD8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8009AD8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chcaptainblubber_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873F8: syscall     565
    recomp_syscall_handler(rdram, ctx, 0x800873F8);
    return;
    // 0x800873FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800540_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800548: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080054C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800554: jal         0x800DA298
    // 0x80800558: addiu       $a0, $zero, 0x6E2
    ctx->r4 = ADD32(0, 0X6E2);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800558: addiu       $a0, $zero, 0x6E2
    ctx->r4 = ADD32(0, 0X6E2);
    after_0:
    // 0x8080055C: bne         $v0, $zero, L_80800574
    if (ctx->r2 != 0) {
        // 0x80800560: nop
    
            goto L_80800574;
    }
    // 0x80800560: nop

    // 0x80800564: jal         0x808004C8
    // 0x80800568: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_808004C8_chtoxicroombits(rdram, ctx);
        goto after_1;
    // 0x80800568: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8080056C: jal         0x800DA544
    // 0x80800570: addiu       $a0, $zero, 0x6E2
    ctx->r4 = ADD32(0, 0X6E2);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800570: addiu       $a0, $zero, 0x6E2
    ctx->r4 = ADD32(0, 0X6E2);
    after_2:
L_80800574:
    // 0x80800574: jal         0x80800458
    // 0x80800578: nop

    func_80800458_chtoxicroombits(rdram, ctx);
        goto after_3;
    // 0x80800578: nop

    after_3:
    // 0x8080057C: jal         0x80800410
    // 0x80800580: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    func_80800410_chtoxicroombits(rdram, ctx);
        goto after_4;
    // 0x80800580: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    after_4:
    // 0x80800584: lbu         $t9, 0x79($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X79);
    // 0x80800588: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8080058C: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800590: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800594: jal         0x800DB9B0
    // 0x80800598: sb          $t1, 0x79($s1)
    MEM_B(0X79, ctx->r17) = ctx->r9;
    func_800DB9B0(rdram, ctx);
        goto after_5;
    // 0x80800598: sb          $t1, 0x79($s1)
    MEM_B(0X79, ctx->r17) = ctx->r9;
    after_5:
    // 0x8080059C: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x808005A0: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_808005B4;
    }
    // 0x808005A0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x808005A4: lhu         $t2, 0x6E($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X6E);
    // 0x808005A8: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x808005AC: b           L_808005C4
    // 0x808005B0: sh          $t3, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r11;
        goto L_808005C4;
    // 0x808005B0: sh          $t3, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r11;
L_808005B4:
    // 0x808005B4: lhu         $t4, 0x6E($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X6E);
    // 0x808005B8: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808005BC: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x808005C0: sh          $t6, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r14;
L_808005C4:
    // 0x808005C4: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x808005C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005D0: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x808005D4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808005D8: swc1        $f10, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f10.u32l;
    // 0x808005DC: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    // 0x808005E0: lbu         $v0, 0x79($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X79);
L_808005E4:
    // 0x808005E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005E8: srl         $v1, $v0, 4
    ctx->r3 = S32(U32(ctx->r2) >> 4);
    // 0x808005EC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x808005F0: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x808005F4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808005F8: andi        $t0, $v0, 0xFF0F
    ctx->r8 = ctx->r2 & 0XFF0F;
    // 0x808005FC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800600: bne         $t7, $zero, L_80800610
    if (ctx->r15 != 0) {
        // 0x80800604: sb          $t1, 0x79($s1)
        MEM_B(0X79, ctx->r17) = ctx->r9;
            goto L_80800610;
    }
    // 0x80800604: sb          $t1, 0x79($s1)
    MEM_B(0X79, ctx->r17) = ctx->r9;
    // 0x80800608: jal         0x80800960
    // 0x8080060C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800960_chtoxicroombits(rdram, ctx);
        goto after_6;
    // 0x8080060C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
L_80800610:
    // 0x80800610: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800614: bnel        $s0, $zero, L_808005E4
    if (ctx->r16 != 0) {
        // 0x80800618: lbu         $v0, 0x79($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X79);
            goto L_808005E4;
    }
    goto skip_0;
    // 0x80800618: lbu         $v0, 0x79($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X79);
    skip_0:
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800620: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800624: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800628: jr          $ra
    // 0x8080062C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080062C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800936E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800936E8: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800936EC: jr          $ra
    // 0x800936F0: sb          $a1, 0xA3($t6)
    MEM_B(0XA3, ctx->r14) = ctx->r5;
    return;
    // 0x800936F0: sb          $a1, 0xA3($t6)
    MEM_B(0XA3, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808028E4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808028E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808028E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808028EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808028F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808028F4: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    // 0x808028F8: jal         0x800F1DCC
    // 0x808028FC: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x808028FC: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    after_0:
    // 0x80802900: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80802904: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802908: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080290C: bgezl       $t8, L_8080297C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802910: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8080297C;
    }
    goto skip_0;
    // 0x80802910: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80802914: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802918: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080291C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80802920: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802924: nop

    // 0x80802928: bc1fl       L_80802944
    if (!c1cs) {
        // 0x8080292C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80802944;
    }
    goto skip_1;
    // 0x8080292C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80802930: jal         0x800904C8
    // 0x80802934: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    func_800904C8(rdram, ctx);
        goto after_1;
    // 0x80802934: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    after_1:
    // 0x80802938: b           L_80802CF4
    // 0x8080293C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x8080293C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802940: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80802944:
    // 0x80802944: nop

    // 0x80802948: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080294C: nop

    // 0x80802950: bc1f        L_80802968
    if (!c1cs) {
        // 0x80802954: nop
    
            goto L_80802968;
    }
    // 0x80802954: nop

    // 0x80802958: jal         0x800904C8
    // 0x8080295C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    func_800904C8(rdram, ctx);
        goto after_2;
    // 0x8080295C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_2:
    // 0x80802960: b           L_80802CF4
    // 0x80802964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802968:
    // 0x80802968: jal         0x800904C8
    // 0x8080296C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    func_800904C8(rdram, ctx);
        goto after_3;
    // 0x8080296C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_3:
    // 0x80802970: b           L_80802CF4
    // 0x80802974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802978: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8080297C:
    // 0x8080297C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80802980: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802984: nop

    // 0x80802988: bc1fl       L_80802AB0
    if (!c1cs) {
        // 0x8080298C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80802AB0;
    }
    goto skip_2;
    // 0x8080298C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80802990: jal         0x801022E4
    // 0x80802994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_4;
    // 0x80802994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802998: addiu       $t9, $v0, -0x105
    ctx->r25 = ADD32(ctx->r2, -0X105);
    // 0x8080299C: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x808029A0: beq         $at, $zero, L_80802CF0
    if (ctx->r1 == 0) {
        // 0x808029A4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80802CF0;
    }
    // 0x808029A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808029A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C38) << 16);
    // 0x808029AC: addu        $at, $at, $t9
    gpr jr_addend_808029B4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808029B0: lw          $t9, 0x4C38($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C38));
    // 0x808029B4: jr          $t9
    // 0x808029B8: nop

    switch (jr_addend_808029B4 >> 2) {
        case 0: goto L_808029BC; break;
        case 1: goto L_80802CF0; break;
        case 2: goto L_80802A1C; break;
        case 3: goto L_80802A84; break;
        case 4: goto L_80802A84; break;
        case 5: goto L_80802A84; break;
        case 6: goto L_80802A84; break;
        default: switch_error(__func__, 0x808029B4, 0x80804C38);
    }
    // 0x808029B8: nop

L_808029BC:
    // 0x808029BC: jal         0x80104248
    // 0x808029C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_5;
    // 0x808029C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808029C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808029C8: jal         0x8008AED4
    // 0x808029CC: addiu       $a1, $zero, 0x106
    ctx->r5 = ADD32(0, 0X106);
    anctrl_setIndex(rdram, ctx);
        goto after_6;
    // 0x808029CC: addiu       $a1, $zero, 0x106
    ctx->r5 = ADD32(0, 0X106);
    after_6:
    // 0x808029D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029D4: jal         0x80101CDC
    // 0x808029D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101CDC(rdram, ctx);
        goto after_7;
    // 0x808029D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x808029DC: jal         0x80104248
    // 0x808029E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_8;
    // 0x808029E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808029E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808029E8: jal         0x8008B134
    // 0x808029EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x808029EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808029F0: jal         0x80104248
    // 0x808029F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_10;
    // 0x808029F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808029F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808029FC: jal         0x8008B188
    // 0x80802A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_11;
    // 0x80802A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80802A04: jal         0x80104248
    // 0x80802A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_12;
    // 0x80802A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80802A0C: jal         0x8008B064
    // 0x80802A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x80802A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80802A14: b           L_80802CF4
    // 0x80802A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A1C:
    // 0x80802A1C: jal         0x80104248
    // 0x80802A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_14;
    // 0x80802A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80802A24: jal         0x8008B28C
    // 0x80802A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B28C(rdram, ctx);
        goto after_15;
    // 0x80802A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80802A2C: beq         $v0, $zero, L_80802A5C
    if (ctx->r2 == 0) {
        // 0x80802A30: nop
    
            goto L_80802A5C;
    }
    // 0x80802A30: nop

    // 0x80802A34: jal         0x80104248
    // 0x80802A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_16;
    // 0x80802A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80802A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802A40: jal         0x8008B188
    // 0x80802A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_17;
    // 0x80802A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80802A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A4C: jal         0x80101CDC
    // 0x80802A50: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80101CDC(rdram, ctx);
        goto after_18;
    // 0x80802A50: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_18:
    // 0x80802A54: b           L_80802CF4
    // 0x80802A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A5C:
    // 0x80802A5C: jal         0x80104248
    // 0x80802A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_19;
    // 0x80802A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802A64: jal         0x8008B324
    // 0x80802A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_20;
    // 0x80802A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80802A6C: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802A70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_3;
    // 0x80802A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80802A74: jal         0x80802720
    // 0x80802A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_21;
    // 0x80802A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80802A7C: b           L_80802CF4
    // 0x80802A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A84:
    // 0x80802A84: jal         0x80104248
    // 0x80802A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_22;
    // 0x80802A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80802A8C: jal         0x8008B324
    // 0x80802A90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_23;
    // 0x80802A90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80802A94: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802A98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_4;
    // 0x80802A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80802A9C: jal         0x80802720
    // 0x80802AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_24;
    // 0x80802AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80802AA4: b           L_80802CF4
    // 0x80802AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80802AB0:
    // 0x80802AB0: nop

    // 0x80802AB4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80802AB8: nop

    // 0x80802ABC: bc1f        L_80802BDC
    if (!c1cs) {
        // 0x80802AC0: nop
    
            goto L_80802BDC;
    }
    // 0x80802AC0: nop

    // 0x80802AC4: jal         0x801022E4
    // 0x80802AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_25;
    // 0x80802AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80802ACC: addiu       $t0, $v0, -0x105
    ctx->r8 = ADD32(ctx->r2, -0X105);
    // 0x80802AD0: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x80802AD4: beq         $at, $zero, L_80802CF0
    if (ctx->r1 == 0) {
        // 0x80802AD8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80802CF0;
    }
    // 0x80802AD8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80802ADC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C54) << 16);
    // 0x80802AE0: addu        $at, $at, $t0
    gpr jr_addend_80802AE8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80802AE4: lw          $t0, 0x4C54($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C54));
    // 0x80802AE8: jr          $t0
    // 0x80802AEC: nop

    switch (jr_addend_80802AE8 >> 2) {
        case 0: goto L_80802AF0; break;
        case 1: goto L_80802B50; break;
        case 2: goto L_80802CF0; break;
        case 3: goto L_80802BB4; break;
        case 4: goto L_80802BB4; break;
        case 5: goto L_80802BB4; break;
        case 6: goto L_80802BB4; break;
        default: switch_error(__func__, 0x80802AE8, 0x80804C54);
    }
    // 0x80802AEC: nop

L_80802AF0:
    // 0x80802AF0: jal         0x80104248
    // 0x80802AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_26;
    // 0x80802AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80802AF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802AFC: jal         0x8008AED4
    // 0x80802B00: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    anctrl_setIndex(rdram, ctx);
        goto after_27;
    // 0x80802B00: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    after_27:
    // 0x80802B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B08: jal         0x80101CDC
    // 0x80802B0C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101CDC(rdram, ctx);
        goto after_28;
    // 0x80802B0C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_28:
    // 0x80802B10: jal         0x80104248
    // 0x80802B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_29;
    // 0x80802B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80802B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B1C: jal         0x8008B134
    // 0x80802B20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_30;
    // 0x80802B20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80802B24: jal         0x80104248
    // 0x80802B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_31;
    // 0x80802B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80802B2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B30: jal         0x8008B188
    // 0x80802B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_32;
    // 0x80802B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80802B38: jal         0x80104248
    // 0x80802B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_33;
    // 0x80802B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80802B40: jal         0x8008B064
    // 0x80802B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_start(rdram, ctx);
        goto after_34;
    // 0x80802B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x80802B48: b           L_80802CF4
    // 0x80802B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B50:
    // 0x80802B50: jal         0x80104248
    // 0x80802B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_35;
    // 0x80802B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80802B58: jal         0x8008B28C
    // 0x80802B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B28C(rdram, ctx);
        goto after_36;
    // 0x80802B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x80802B60: beq         $v0, $zero, L_80802B8C
    if (ctx->r2 == 0) {
        // 0x80802B64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802B8C;
    }
    // 0x80802B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B68: jal         0x80101CDC
    // 0x80802B6C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80101CDC(rdram, ctx);
        goto after_37;
    // 0x80802B6C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_37:
    // 0x80802B70: jal         0x80104248
    // 0x80802B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_38;
    // 0x80802B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80802B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B7C: jal         0x8008B188
    // 0x80802B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_39;
    // 0x80802B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80802B84: b           L_80802CF4
    // 0x80802B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B8C:
    // 0x80802B8C: jal         0x80104248
    // 0x80802B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_40;
    // 0x80802B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80802B94: jal         0x8008B324
    // 0x80802B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_41;
    // 0x80802B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x80802B9C: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802BA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_5;
    // 0x80802BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80802BA4: jal         0x80802720
    // 0x80802BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_42;
    // 0x80802BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80802BAC: b           L_80802CF4
    // 0x80802BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802BB4:
    // 0x80802BB4: jal         0x80104248
    // 0x80802BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_43;
    // 0x80802BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80802BBC: jal         0x8008B324
    // 0x80802BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_44;
    // 0x80802BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_44:
    // 0x80802BC4: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802BC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_6;
    // 0x80802BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80802BCC: jal         0x80802720
    // 0x80802BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_45;
    // 0x80802BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80802BD4: b           L_80802CF4
    // 0x80802BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802BDC:
    // 0x80802BDC: jal         0x801022E4
    // 0x80802BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_46;
    // 0x80802BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80802BE4: addiu       $t1, $v0, -0x105
    ctx->r9 = ADD32(ctx->r2, -0X105);
    // 0x80802BE8: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x80802BEC: beq         $at, $zero, L_80802CF0
    if (ctx->r1 == 0) {
        // 0x80802BF0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80802CF0;
    }
    // 0x80802BF0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80802BF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C70) << 16);
    // 0x80802BF8: addu        $at, $at, $t1
    gpr jr_addend_80802C00 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80802BFC: lw          $t1, 0x4C70($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C70));
    // 0x80802C00: jr          $t1
    // 0x80802C04: nop

    switch (jr_addend_80802C00 >> 2) {
        case 0: goto L_80802CF0; break;
        case 1: goto L_80802C08; break;
        case 2: goto L_80802C6C; break;
        case 3: goto L_80802CD0; break;
        case 4: goto L_80802CD0; break;
        case 5: goto L_80802CD0; break;
        case 6: goto L_80802CD0; break;
        default: switch_error(__func__, 0x80802C00, 0x80804C70);
    }
    // 0x80802C04: nop

L_80802C08:
    // 0x80802C08: jal         0x80104248
    // 0x80802C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_47;
    // 0x80802C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80802C10: jal         0x8008B28C
    // 0x80802C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B28C(rdram, ctx);
        goto after_48;
    // 0x80802C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x80802C18: beq         $v0, $zero, L_80802C44
    if (ctx->r2 == 0) {
        // 0x80802C1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C44;
    }
    // 0x80802C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C20: jal         0x80101CDC
    // 0x80802C24: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80101CDC(rdram, ctx);
        goto after_49;
    // 0x80802C24: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_49:
    // 0x80802C28: jal         0x80104248
    // 0x80802C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_50;
    // 0x80802C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80802C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C34: jal         0x8008B188
    // 0x80802C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_51;
    // 0x80802C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80802C3C: b           L_80802CF4
    // 0x80802C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802C44:
    // 0x80802C44: jal         0x80104248
    // 0x80802C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_52;
    // 0x80802C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80802C4C: jal         0x8008B324
    // 0x80802C50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_53;
    // 0x80802C50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_53:
    // 0x80802C54: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_7;
    // 0x80802C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80802C5C: jal         0x80802720
    // 0x80802C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_54;
    // 0x80802C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80802C64: b           L_80802CF4
    // 0x80802C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802C6C:
    // 0x80802C6C: jal         0x80104248
    // 0x80802C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_55;
    // 0x80802C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80802C74: jal         0x8008B28C
    // 0x80802C78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B28C(rdram, ctx);
        goto after_56;
    // 0x80802C78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_56:
    // 0x80802C7C: beq         $v0, $zero, L_80802CA8
    if (ctx->r2 == 0) {
        // 0x80802C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802CA8;
    }
    // 0x80802C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C84: jal         0x80101CDC
    // 0x80802C88: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80101CDC(rdram, ctx);
        goto after_57;
    // 0x80802C88: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_57:
    // 0x80802C8C: jal         0x80104248
    // 0x80802C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_58;
    // 0x80802C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80802C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C98: jal         0x8008B188
    // 0x80802C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_59;
    // 0x80802C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_59:
    // 0x80802CA0: b           L_80802CF4
    // 0x80802CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802CA8:
    // 0x80802CA8: jal         0x80104248
    // 0x80802CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_60;
    // 0x80802CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80802CB0: jal         0x8008B324
    // 0x80802CB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_61;
    // 0x80802CB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_61:
    // 0x80802CB8: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802CBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_8;
    // 0x80802CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80802CC0: jal         0x80802720
    // 0x80802CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_62;
    // 0x80802CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80802CC8: b           L_80802CF4
    // 0x80802CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802CF4;
    // 0x80802CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802CD0:
    // 0x80802CD0: jal         0x80104248
    // 0x80802CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_63;
    // 0x80802CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80802CD8: jal         0x8008B324
    // 0x80802CDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_64;
    // 0x80802CDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_64:
    // 0x80802CE0: beql        $v0, $zero, L_80802CF4
    if (ctx->r2 == 0) {
        // 0x80802CE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CF4;
    }
    goto skip_9;
    // 0x80802CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80802CE8: jal         0x80802720
    // 0x80802CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802720_chdodgemcontrol(rdram, ctx);
        goto after_65;
    // 0x80802CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
L_80802CF0:
    // 0x80802CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802CF4:
    // 0x80802CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802CFC: jr          $ra
    // 0x80802D00: nop

    return;
    // 0x80802D00: nop

;}
RECOMP_FUNC void _chdiggerboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867D0: syscall     377
    recomp_syscall_handler(rdram, ctx, 0x800867D0);
    return;
    // 0x800867D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chpickups_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085888: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085888);
    return;
    // 0x8008588C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800ADC_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE4: jal         0x800F54E4
    // 0x80800AE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800AF4: jal         0x80800824
    // 0x80800AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800824_chbanjoctrl(rdram, ctx);
        goto after_1;
    // 0x80800AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800AFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B00: jal         0x8080091C
    // 0x80800B04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8080091C_chbanjoctrl(rdram, ctx);
        goto after_2;
    // 0x80800B04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B10: jr          $ra
    // 0x80800B14: nop

    return;
    // 0x80800B14: nop

;}
RECOMP_FUNC void _badata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084660: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084660);
    return;
    // 0x80084664: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009B170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B178: jal         0x800D8FF8
    // 0x8009B17C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009B17C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009B180: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8009B184: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8009B188: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8009B18C: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B190: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8009B194: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B198: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009B19C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8009B1A0: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8009B1A4: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B1A8: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8009B1AC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B1B0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8009B1B4: nop

    // 0x8009B1B8: bc1fl       L_8009B1CC
    if (!c1cs) {
        // 0x8009B1BC: addiu       $a0, $v0, 0x28
        ctx->r4 = ADD32(ctx->r2, 0X28);
            goto L_8009B1CC;
    }
    goto skip_0;
    // 0x8009B1BC: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    skip_0:
    // 0x8009B1C0: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8009B1C4: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B1C8: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
L_8009B1CC:
    // 0x8009B1CC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x8009B1D0: jal         0x800EFA20
    // 0x8009B1D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x8009B1D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8009B1D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8009B1DC: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B1E0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8009B1E4: jal         0x800EF04C
    // 0x8009B1E8: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x8009B1E8: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_2:
    // 0x8009B1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B1F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B1F4: jr          $ra
    // 0x8009B1F8: nop

    return;
    // 0x8009B1F8: nop

;}
RECOMP_FUNC void func_80800764_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800764: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080076C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800770: jal         0x80800238
    // 0x80800774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800778: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x8080077C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: jal         0x8008CCBC
    // 0x80800788: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800788: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_1:
    // 0x8080078C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800790: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080079C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808007A0: jal         0x8009FFD8
    // 0x808007A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808007A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: jal         0x800961AC
    // 0x808007B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808007B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: jal         0x80085358
    // 0x808007BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batranslate_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808007BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: jal         0x80800488
    // 0x808007C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800488_bsledge(rdram, ctx);
        goto after_5;
    // 0x808007C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808007CC: jal         0x800A4CA8
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_6;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007D8: jal         0x801124D0
    // 0x808007DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_801124D0(rdram, ctx);
        goto after_7;
    // 0x808007DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x808007E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007EC: jr          $ra
    // 0x808007F0: nop

    return;
    // 0x808007F0: nop

;}
RECOMP_FUNC void func_80090200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090208: jal         0x800F5310
    // 0x8009020C: nop

    func_800F5310(rdram, ctx);
        goto after_0;
    // 0x8009020C: nop

    after_0:
    // 0x80090210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090218: jr          $ra
    // 0x8009021C: nop

    return;
    // 0x8009021C: nop

;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080000C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800010: jal         0x800EC358
    // 0x80800014: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EC358(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: lbu         $t7, 0x74($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X74);
    // 0x80800020: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800024: sb          $t8, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r24;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80802024_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080202C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802034: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80802038: jal         0x80100094
    // 0x8080203C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080203C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802040: jal         0x800C07F4
    // 0x80802044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800C07F4(rdram, ctx);
        goto after_1;
    // 0x80802044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802048: bne         $v0, $zero, L_80802080
    if (ctx->r2 != 0) {
        // 0x8080204C: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80802080;
    }
    // 0x8080204C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80802050: addiu       $at, $zero, 0x15C5
    ctx->r1 = ADD32(0, 0X15C5);
    // 0x80802054: bne         $t6, $at, L_80802080
    if (ctx->r14 != ctx->r1) {
        // 0x80802058: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80802080;
    }
    // 0x80802058: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080205C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802060: bne         $t7, $at, L_80802080
    if (ctx->r15 != ctx->r1) {
        // 0x80802064: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802080;
    }
    // 0x80802064: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802068: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080206C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80802070: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80802074: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802078: jal         0x8008A2D0
    // 0x8080207C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080207C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
L_80802080:
    // 0x80802080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802088: jr          $ra
    // 0x8080208C: nop

    return;
    // 0x8080208C: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800984: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800988: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B18) << 16);
    // 0x8080098C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800990: jr          $ra
    // 0x80800994: lw          $v0, 0x1B18($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B18));
    return;
    // 0x80800994: lw          $v0, 0x1B18($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B18));
;}
RECOMP_FUNC void dblight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x808000D8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808000E8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808000EC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808000F0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808000F4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808000F8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808000FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800100: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800104: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800108: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8080010C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800110: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800114: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800118: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080011C: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x80800120: jal         0x800B2190
    // 0x80800124: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800128: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
    // 0x8080012C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80800130: addiu       $s7, $sp, 0x90
    ctx->r23 = ADD32(ctx->r29, 0X90);
    // 0x80800134: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800138: addu        $fp, $t7, $s0
    ctx->r30 = ADD32(ctx->r15, ctx->r16);
    // 0x8080013C: addiu       $fp, $fp, 0x18
    ctx->r30 = ADD32(ctx->r30, 0X18);
    // 0x80800140: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800144: addu        $a2, $t9, $fp
    ctx->r6 = ADD32(ctx->r25, ctx->r30);
    // 0x80800148: sltu        $at, $fp, $a2
    ctx->r1 = ctx->r30 < ctx->r6 ? 1 : 0;
    // 0x8080014C: beq         $at, $zero, L_80800488
    if (ctx->r1 == 0) {
        // 0x80800150: addiu       $s6, $sp, 0x9C
        ctx->r22 = ADD32(ctx->r29, 0X9C);
            goto L_80800488;
    }
    // 0x80800150: addiu       $s6, $sp, 0x9C
    ctx->r22 = ADD32(ctx->r29, 0X9C);
    // 0x80800154: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800158: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080015C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80800160: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x80800164: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80800168: addiu       $s5, $sp, 0x84
    ctx->r21 = ADD32(ctx->r29, 0X84);
    // 0x8080016C: lh          $a1, 0x0($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X0);
L_80800170:
    // 0x80800170: lw          $v1, 0xD8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD8);
    // 0x80800174: lw          $a0, 0xF0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF0);
    // 0x80800178: sll         $t0, $a1, 4
    ctx->r8 = S32(ctx->r5 << 4);
    // 0x8080017C: jal         0x800879F0
    // 0x80800180: addu        $s4, $t0, $v1
    ctx->r20 = ADD32(ctx->r8, ctx->r3);
    _dbvtxnormal_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800180: addu        $s4, $t0, $v1
    ctx->r20 = ADD32(ctx->r8, ctx->r3);
    after_1:
    // 0x80800184: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x80800188: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2550, 0X4D0) << 16);
    // 0x80800190: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800194: lwc1        $f8, 0x4D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2550, 0X4D0));
    // 0x80800198: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8080019C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001A0: lb          $t3, 0x2($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X2);
    // 0x808001A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2550, 0X4D4) << 16);
    // 0x808001A8: lbu         $s1, 0xC($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0XC);
    // 0x808001AC: lbu         $s2, 0xD($s4)
    ctx->r18 = MEM_BU(ctx->r20, 0XD);
    // 0x808001B0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001B4: mul.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808001B8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x808001BC: lwc1        $f6, 0x4D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2550, 0X4D4));
    // 0x808001C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2550, 0X4D8) << 16);
    // 0x808001C4: lbu         $s3, 0xE($s4)
    ctx->r19 = MEM_BU(ctx->r20, 0XE);
    // 0x808001C8: mul.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001CC: lwc1        $f4, 0x4D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2550, 0X4D8));
    // 0x808001D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808001D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001DC: mul.s       $f28, $f10, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808001E0: jal         0x800C8760
    // 0x808001E4: nop

    func_800C8760(rdram, ctx);
        goto after_2;
    // 0x808001E4: nop

    after_2:
    // 0x808001E8: beq         $v0, $zero, L_80800438
    if (ctx->r2 == 0) {
        // 0x808001EC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800438;
    }
    // 0x808001EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808001F0:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x800C8800
    // 0x808001F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800C8800(rdram, ctx);
        goto after_3;
    // 0x808001F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x808001FC: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x80800200: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800204: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800208: nop

    // 0x8080020C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800210: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800214: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800218: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x8080021C: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
    // 0x80800220: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80800224: nop

    // 0x80800228: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080022C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800230: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800234: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x80800238: lh          $t6, 0x4($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X4);
    // 0x8080023C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800240: nop

    // 0x80800244: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800248: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080024C: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80800250: nop

    // 0x80800254: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80800258: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x8080025C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800260: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80800264: jal         0x8002DCA0
    // 0x80800268: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80800268: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_4:
    // 0x8080026C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x800C8898
    // 0x80800278: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C8898(rdram, ctx);
        goto after_5;
    // 0x80800278: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x8080027C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x80800288: nop

    // 0x8080028C: bc1tl       L_80800424
    if (c1cs) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800424;
    }
    goto skip_0;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800294: jal         0x800C8900
    // 0x80800298: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800C8900(rdram, ctx);
        goto after_6;
    // 0x80800298: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x8080029C: c.eq.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl == ctx->f30.fl;
    // 0x808002A0: nop

    // 0x808002A4: bc1tl       L_80800378
    if (c1cs) {
        // 0x808002A8: lwc1        $f2, 0x9C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_80800378;
    }
    goto skip_1;
    // 0x808002A8: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    skip_1:
    // 0x808002AC: div.s       $f0, $f22, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x808002B0: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808002B4: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x808002B8: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x808002BC: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x808002C0: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x808002C4: nop

    // 0x808002C8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808002CC: nop

    // 0x808002D0: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808002D4: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    // 0x808002D8: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x808002DC: swc1        $f16, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f16.u32l;
    // 0x808002E0: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x808002E4: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    // 0x808002E8: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x808002EC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808002F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808002F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002F8: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x808002FC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80800300: bc1f        L_8080031C
    if (!c1cs) {
        // 0x80800304: nop
    
            goto L_8080031C;
    }
    // 0x80800304: nop

    // 0x80800308: lhu         $t7, 0x6($s4)
    ctx->r15 = MEM_HU(ctx->r20, 0X6);
    // 0x8080030C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80800310: beql        $t8, $zero, L_80800424
    if (ctx->r24 == 0) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800424;
    }
    goto skip_2;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800318: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8080031C:
    // 0x8080031C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800320: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800324: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80800328: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080032C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80800330: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800334: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800338: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8080033C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800340: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800344: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80800348: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080034C: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x80800350: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800354: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800358: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8080035C: nop

    // 0x80800360: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x80800364: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800368: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8080036C: nop

    // 0x80800370: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x80800374: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
L_80800378:
    // 0x80800378: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8080037C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80800380: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x80800384: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80800388: bc1fl       L_808003A4
    if (!c1cs) {
        // 0x8080038C: sub.s       $f4, $f20, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
            goto L_808003A4;
    }
    goto skip_3;
    // 0x8080038C: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
    skip_3:
    // 0x80800390: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x80800394: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
    // 0x80800398: b           L_80800420
    // 0x8080039C: addu        $s3, $s3, $t0
    ctx->r19 = ADD32(ctx->r19, ctx->r8);
        goto L_80800420;
    // 0x8080039C: addu        $s3, $s3, $t0
    ctx->r19 = ADD32(ctx->r19, ctx->r8);
    // 0x808003A0: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
L_808003A4:
    // 0x808003A4: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x808003A8: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x808003AC: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x808003B0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808003B4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808003B8: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x808003BC: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x808003C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808003C4: sub.s       $f0, $f22, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x808003C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808003CC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003D0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808003D4: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x808003D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003DC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x808003E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003E4: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x808003E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808003EC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003F0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808003F4: mtc1        $s3, $f8
    ctx->f8.u32l = ctx->r19;
    // 0x808003F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003FC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800400: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800404: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80800408: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080040C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800410: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800414: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800418: mfc1        $s3, $f6
    ctx->r19 = (int32_t)ctx->f6.u32l;
    // 0x8080041C: nop

L_80800420:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800424:
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800428: jal         0x800C878C
    // 0x8080042C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800C878C(rdram, ctx);
        goto after_7;
    // 0x8080042C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80800430: bne         $v0, $zero, L_808001F0
    if (ctx->r2 != 0) {
        // 0x80800434: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808001F0;
    }
    // 0x80800434: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800438:
    // 0x80800438: slti        $at, $s1, 0x100
    ctx->r1 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x8080043C: bnel        $at, $zero, L_8080044C
    if (ctx->r1 != 0) {
        // 0x80800440: slti        $at, $s2, 0x100
        ctx->r1 = SIGNED(ctx->r18) < 0X100 ? 1 : 0;
            goto L_8080044C;
    }
    goto skip_4;
    // 0x80800440: slti        $at, $s2, 0x100
    ctx->r1 = SIGNED(ctx->r18) < 0X100 ? 1 : 0;
    skip_4:
    // 0x80800444: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x80800448: slti        $at, $s2, 0x100
    ctx->r1 = SIGNED(ctx->r18) < 0X100 ? 1 : 0;
L_8080044C:
    // 0x8080044C: bnel        $at, $zero, L_8080045C
    if (ctx->r1 != 0) {
        // 0x80800450: slti        $at, $s3, 0x100
        ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
            goto L_8080045C;
    }
    goto skip_5;
    // 0x80800450: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
    skip_5:
    // 0x80800454: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x80800458: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
L_8080045C:
    // 0x8080045C: bnel        $at, $zero, L_8080046C
    if (ctx->r1 != 0) {
        // 0x80800460: sb          $s1, 0xC($s4)
        MEM_B(0XC, ctx->r20) = ctx->r17;
            goto L_8080046C;
    }
    goto skip_6;
    // 0x80800460: sb          $s1, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r17;
    skip_6:
    // 0x80800464: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x80800468: sb          $s1, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r17;
L_8080046C:
    // 0x8080046C: sb          $s2, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r18;
    // 0x80800470: sb          $s3, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r19;
    // 0x80800474: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80800478: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // 0x8080047C: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x80800480: bnel        $at, $zero, L_80800170
    if (ctx->r1 != 0) {
        // 0x80800484: lh          $a1, 0x0($fp)
        ctx->r5 = MEM_H(ctx->r30, 0X0);
            goto L_80800170;
    }
    goto skip_7;
    // 0x80800484: lh          $a1, 0x0($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X0);
    skip_7:
L_80800488:
    // 0x80800488: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8080048C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800490: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800494: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800498: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080049C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808004A0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808004A4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808004A8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808004AC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x808004B0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808004B4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x808004B8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x808004BC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x808004C0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x808004C4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x808004C8: jr          $ra
    // 0x808004CC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x808004CC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_800ECEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECEEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ECEF0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800ECEF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ECEF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ECEFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ECF00: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800ECF04: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800ECF08: lwc1        $f6, 0x48($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X48);
    // 0x800ECF0C: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x800ECF10: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800ECF14: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800ECF18: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ECF1C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800ECF20: addiu       $a2, $t6, 0x38
    ctx->r6 = ADD32(ctx->r14, 0X38);
    // 0x800ECF24: addiu       $a1, $t6, 0x2C
    ctx->r5 = ADD32(ctx->r14, 0X2C);
    // 0x800ECF28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800ECF2C: jal         0x800EFE50
    // 0x800ECF30: nop

    func_800EFE50(rdram, ctx);
        goto after_0;
    // 0x800ECF30: nop

    after_0:
    // 0x800ECF34: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800ECF38: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800ECF3C: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x800ECF40: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECF44: beq         $at, $zero, L_800ED050
    if (ctx->r1 == 0) {
        // 0x800ECF48: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800ED050;
    }
    // 0x800ECF48: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ECF4C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECF50: beq         $at, $zero, L_800ECFDC
    if (ctx->r1 == 0) {
        // 0x800ECF54: lh          $t9, -0x10($s0)
        ctx->r25 = MEM_H(ctx->r16, -0X10);
            goto L_800ECFDC;
    }
    // 0x800ECF54: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
L_800ECF58:
    // 0x800ECF58: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800ECF5C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ECF60: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ECF64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECF68: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECF6C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800ECF70: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECF74: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECF78: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800ECF7C: nop

    // 0x800ECF80: sh          $t1, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r9;
    // 0x800ECF84: lh          $t2, -0x1E($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X1E);
    // 0x800ECF88: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ECF8C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800ECF90: nop

    // 0x800ECF94: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ECF98: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ECF9C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800ECFA0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800ECFA4: nop

    // 0x800ECFA8: sh          $t4, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r12;
    // 0x800ECFAC: lh          $t5, -0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X1C);
    // 0x800ECFB0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800ECFB4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800ECFB8: nop

    // 0x800ECFBC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECFC0: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECFC4: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECFC8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800ECFCC: nop

    // 0x800ECFD0: sh          $t7, -0xC($s1)
    MEM_H(-0XC, ctx->r17) = ctx->r15;
    // 0x800ECFD4: bne         $at, $zero, L_800ECF58
    if (ctx->r1 != 0) {
        // 0x800ECFD8: lh          $t9, -0x10($s0)
        ctx->r25 = MEM_H(ctx->r16, -0X10);
            goto L_800ECF58;
    }
    // 0x800ECFD8: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
L_800ECFDC:
    // 0x800ECFDC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800ECFE0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ECFE4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800ECFE8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECFEC: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECFF0: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECFF4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800ECFF8: nop

    // 0x800ECFFC: sh          $t1, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r9;
    // 0x800ED000: lh          $t2, -0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, -0XE);
    // 0x800ED004: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ED008: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800ED00C: nop

    // 0x800ED010: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ED014: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ED018: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800ED01C: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800ED020: nop

    // 0x800ED024: sh          $t4, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r12;
    // 0x800ED028: lh          $t5, -0xC($s0)
    ctx->r13 = MEM_H(ctx->r16, -0XC);
    // 0x800ED02C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800ED030: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800ED034: nop

    // 0x800ED038: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ED03C: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ED040: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ED044: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800ED048: nop

    // 0x800ED04C: sh          $t7, -0xC($s1)
    MEM_H(-0XC, ctx->r17) = ctx->r15;
L_800ED050:
    // 0x800ED050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ED054: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ED058: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ED05C: jr          $ra
    // 0x800ED060: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ED060: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chfantasyeyeball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876D8: syscall     608
    recomp_syscall_handler(rdram, ctx, 0x800876D8);
    return;
    // 0x800876DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void choctopus_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800784: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1028, 0X998) << 16);
    // 0x80800788: jr          $ra
    // 0x8080078C: addiu       $v0, $v0, 0x998
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1028, 0X998));
    return;
    // 0x8080078C: addiu       $v0, $v0, 0x998
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1028, 0X998));
;}
