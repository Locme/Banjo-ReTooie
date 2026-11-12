#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _baeggfire_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B28: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B28);
    return;
    // 0x80084B2C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808002EC_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808002F0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808002F4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x808002F8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808002FC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800300: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800304: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800308: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080030C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800310: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800314: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800318: jal         0x80100094
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800320: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80800324: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80800328: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080032C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800330: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    // 0x80800334: jal         0x8008A0C0
    // 0x80800338: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800338: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080033C: addiu       $a0, $s5, 0x18
    ctx->r4 = ADD32(ctx->r21, 0X18);
    // 0x80800340: jal         0x800EE7F8
    // 0x80800344: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800344: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80800348: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080034C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800350: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800354: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80800358: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
L_8080035C:
    // 0x8080035C: jal         0x800EFD24
    // 0x80800360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80800360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80800364: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800368: slti        $at, $s1, 0x18
    ctx->r1 = SIGNED(ctx->r17) < 0X18 ? 1 : 0;
    // 0x8080036C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80800370: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80800374: bne         $at, $zero, L_8080035C
    if (ctx->r1 != 0) {
        // 0x80800378: swc1        $f20, 0x14($s3)
        MEM_W(0X14, ctx->r19) = ctx->f20.u32l;
            goto L_8080035C;
    }
    // 0x80800378: swc1        $f20, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f20.u32l;
    // 0x8080037C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800380: addiu       $s1, $s6, 0x3C
    ctx->r17 = ADD32(ctx->r22, 0X3C);
    // 0x80800384: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80800388:
    // 0x80800388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080038C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800390: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800394: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    // 0x80800398: addiu       $a2, $s0, 0x33
    ctx->r6 = ADD32(ctx->r16, 0X33);
    // 0x8080039C: jal         0x8008A0C8
    // 0x808003A0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808003A0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_4:
    // 0x808003A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003A8: jal         0x800EE7F8
    // 0x808003AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808003AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x808003B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808003B4: bne         $s0, $s2, L_80800388
    if (ctx->r16 != ctx->r18) {
        // 0x808003B8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800388;
    }
    // 0x808003B8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808003BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808003C0: addiu       $a1, $s6, 0x24
    ctx->r5 = ADD32(ctx->r22, 0X24);
    // 0x808003C4: jal         0x8008A2A0
    // 0x808003C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808003C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808003CC: jal         0x8008A2F8
    // 0x808003D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808003D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808003D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808003D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808003DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808003E0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808003E4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808003E8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808003EC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808003F0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808003F4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808003F8: jr          $ra
    // 0x808003FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808003FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void _idworldmake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F48: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F48);
    return;
    // 0x80088F4C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800F2984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2984: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F2988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F298C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800F2990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F2994: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800F2998: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800F299C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800F29A0: jal         0x800EFB24
    // 0x800F29A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F29A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800F29A8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800F29AC: jal         0x800EF368
    // 0x800F29B0: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF368(rdram, ctx);
        goto after_1;
    // 0x800F29B0: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_1:
    // 0x800F29B4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800F29B8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800F29BC: jal         0x800EE97C
    // 0x800F29C0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EE97C(rdram, ctx);
        goto after_2;
    // 0x800F29C0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x800F29C4: jal         0x800EF2A0
    // 0x800F29C8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x800F29C8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800F29CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800F29D0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800F29D4: jal         0x800EE97C
    // 0x800F29D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EE97C(rdram, ctx);
        goto after_4;
    // 0x800F29D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x800F29DC: jal         0x800EF2A0
    // 0x800F29E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800EF2A0(rdram, ctx);
        goto after_5;
    // 0x800F29E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_5:
    // 0x800F29E4: jal         0x800F274C
    // 0x800F29E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F274C(rdram, ctx);
        goto after_6;
    // 0x800F29E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x800F29EC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800F29F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800F29F4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800F29F8: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x800F29FC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
L_800F2A00:
    // 0x800F2A00: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F2A04: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800F2A08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800F2A0C: swc1        $f4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800F2A10: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F2A14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F2A18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F2A1C: swc1        $f6, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f6.u32l;
    // 0x800F2A20: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800F2A24: bne         $v1, $a2, L_800F2A00
    if (ctx->r3 != ctx->r6) {
        // 0x800F2A28: swc1        $f8, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
            goto L_800F2A00;
    }
    // 0x800F2A28: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800F2A2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F2A30: jal         0x800EEAA4
    // 0x800F2A34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAA4(rdram, ctx);
        goto after_7;
    // 0x800F2A34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x800F2A38: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800F2A3C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800F2A40: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    // 0x800F2A44: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800F2A48: jal         0x800EEAA4
    // 0x800F2A4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800EEAA4(rdram, ctx);
        goto after_8;
    // 0x800F2A4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x800F2A50: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800F2A54: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x800F2A58: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800F2A5C: swc1        $f16, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f16.u32l;
    // 0x800F2A60: jal         0x800EEAA4
    // 0x800F2A64: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800EEAA4(rdram, ctx);
        goto after_9;
    // 0x800F2A64: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x800F2A68: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800F2A6C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x800F2A70: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800F2A74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800F2A78: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800F2A7C: swc1        $f18, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f18.u32l;
    // 0x800F2A80: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800F2A84: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F2A88: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800F2A8C: mul.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800F2A90: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2A94: nop

    // 0x800F2A98: bc1fl       L_800F2AAC
    if (!c1cs) {
        // 0x800F2A9C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2AAC;
    }
    goto skip_0;
    // 0x800F2A9C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x800F2AA0: b           L_800F2AAC
    // 0x800F2AA4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2AAC;
    // 0x800F2AA4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2AA8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2AAC:
    // 0x800F2AAC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2AB0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800F2AB4: nop

    // 0x800F2AB8: sb          $t1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r9;
    // 0x800F2ABC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F2AC0: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800F2AC4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2AC8: nop

    // 0x800F2ACC: bc1fl       L_800F2AE0
    if (!c1cs) {
        // 0x800F2AD0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2AE0;
    }
    goto skip_1;
    // 0x800F2AD0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x800F2AD4: b           L_800F2AE0
    // 0x800F2AD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2AE0;
    // 0x800F2AD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2ADC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2AE0:
    // 0x800F2AE0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2AE4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800F2AE8: nop

    // 0x800F2AEC: sb          $t4, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r12;
    // 0x800F2AF0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F2AF4: mul.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800F2AF8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2AFC: nop

    // 0x800F2B00: bc1fl       L_800F2B14
    if (!c1cs) {
        // 0x800F2B04: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2B14;
    }
    goto skip_2;
    // 0x800F2B04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x800F2B08: b           L_800F2B14
    // 0x800F2B0C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2B14;
    // 0x800F2B0C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2B10: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2B14:
    // 0x800F2B14: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2B18: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800F2B1C: nop

    // 0x800F2B20: sb          $t7, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r15;
    // 0x800F2B24: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800F2B28: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800F2B2C: mul.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800F2B30: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2B34: nop

    // 0x800F2B38: bc1fl       L_800F2B4C
    if (!c1cs) {
        // 0x800F2B3C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2B4C;
    }
    goto skip_3;
    // 0x800F2B3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x800F2B40: b           L_800F2B4C
    // 0x800F2B44: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2B4C;
    // 0x800F2B44: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2B48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2B4C:
    // 0x800F2B4C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2B50: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800F2B54: nop

    // 0x800F2B58: sb          $t1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r9;
    // 0x800F2B5C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800F2B60: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800F2B64: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800F2B68: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2B6C: nop

    // 0x800F2B70: bc1fl       L_800F2B84
    if (!c1cs) {
        // 0x800F2B74: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2B84;
    }
    goto skip_4;
    // 0x800F2B74: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_4:
    // 0x800F2B78: b           L_800F2B84
    // 0x800F2B7C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2B84;
    // 0x800F2B7C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2B80: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2B84:
    // 0x800F2B84: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2B88: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800F2B8C: nop

    // 0x800F2B90: sb          $t5, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r13;
    // 0x800F2B94: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800F2B98: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800F2B9C: mul.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800F2BA0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F2BA4: nop

    // 0x800F2BA8: bc1fl       L_800F2BBC
    if (!c1cs) {
        // 0x800F2BAC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F2BBC;
    }
    goto skip_5;
    // 0x800F2BAC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
    // 0x800F2BB0: b           L_800F2BBC
    // 0x800F2BB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F2BBC;
    // 0x800F2BB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2BB8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F2BBC:
    // 0x800F2BBC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2BC0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800F2BC4: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800F2BC8: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x800F2BCC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800F2BD0: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800F2BD4: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800F2BD8: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x800F2BDC: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x800F2BE0: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x800F2BE4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x800F2BE8: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x800F2BEC: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x800F2BF0: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x800F2BF4: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x800F2BF8: sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // 0x800F2BFC: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800F2C00: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x800F2C04: sb          $t9, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r25;
    // 0x800F2C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F2C0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F2C10: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800F2C14: jr          $ra
    // 0x800F2C18: nop

    return;
    // 0x800F2C18: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800330: jr          $ra
    // 0x80800334: lwc1        $f0, 0x75D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75D8);
    return;
    // 0x80800334: lwc1        $f0, 0x75D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75D8);
;}
RECOMP_FUNC void func_800CB124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB124: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CB128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB12C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CB130: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CB134: lwc1        $f2, 0xEC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800CB138: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800CB13C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CB140: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800CB144: lwc1        $f14, 0xF0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x800CB148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CB14C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CB150: bc1f        L_800CB15C
    if (!c1cs) {
        // 0x800CB154: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800CB15C;
    }
    // 0x800CB154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CB158: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800CB15C:
    // 0x800CB15C: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800CB160: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800CB164: nop

    // 0x800CB168: bc1fl       L_800CB178
    if (!c1cs) {
        // 0x800CB16C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800CB178;
    }
    goto skip_0;
    // 0x800CB16C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x800CB170: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800CB174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800CB178:
    // 0x800CB178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CB17C: lwc1        $f18, 0x5974($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5974);
    // 0x800CB180: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CB184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CB188: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800CB18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CB190: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CB194: nop

    // 0x800CB198: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CB19C: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CB1A0: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CB1A4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800CB1A8: nop

    // 0x800CB1AC: bc1t        L_800CB1C8
    if (c1cs) {
        // 0x800CB1B0: nop
    
            goto L_800CB1C8;
    }
    // 0x800CB1B0: nop

    // 0x800CB1B4: lwc1        $f6, 0x5978($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5978);
    // 0x800CB1B8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800CB1BC: nop

    // 0x800CB1C0: bc1fl       L_800CB214
    if (!c1cs) {
        // 0x800CB1C4: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800CB214;
    }
    goto skip_1;
    // 0x800CB1C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    skip_1:
L_800CB1C8:
    // 0x800CB1C8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800CB1CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CB1D0: bc1f        L_800CB1E4
    if (!c1cs) {
        // 0x800CB1D4: nop
    
            goto L_800CB1E4;
    }
    // 0x800CB1D4: nop

    // 0x800CB1D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CB1DC: b           L_800CB1E8
    // 0x800CB1E0: lwc1        $f18, 0x597C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X597C);
        goto L_800CB1E8;
    // 0x800CB1E0: lwc1        $f18, 0x597C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X597C);
L_800CB1E4:
    // 0x800CB1E4: lwc1        $f18, 0x5980($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5980);
L_800CB1E8:
    // 0x800CB1E8: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CB1EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CB1F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CB1F4: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    // 0x800CB1F8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CB1FC: nop

    // 0x800CB200: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CB204: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800CB208: div.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800CB20C: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800CB210: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
L_800CB214:
    // 0x800CB214: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CB218: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800CB21C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x800CB220: jal         0x800F274C
    // 0x800CB224: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800F274C(rdram, ctx);
        goto after_0;
    // 0x800CB224: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800CB228: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB22C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800CB230: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800CB234: lwc1        $f4, 0xF4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF4);
    // 0x800CB238: lwc1        $f6, 0xE8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XE8);
    // 0x800CB23C: add.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800CB240: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CB244: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800CB248: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CB24C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CB250: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CB254: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800CB258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CB25C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CB260: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800CB264: div.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800CB268: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800CB26C: lwc1        $f8, 0xF4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XF4);
    // 0x800CB270: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x800CB274: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800CB278: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x800CB27C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB280: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CB284: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800CB288: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800CB28C: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CB290: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800CB294: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CB298: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CB29C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CB2A0: mul.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CB2A4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CB2A8: beq         $v1, $a0, L_800CB2EC
    if (ctx->r3 == ctx->r4) {
        // 0x800CB2AC: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_800CB2EC;
    }
    // 0x800CB2AC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_800CB2B0:
    // 0x800CB2B0: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CB2B4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CB2B8: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CB2BC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CB2C0: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CB2C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CB2C8: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CB2CC: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CB2D0: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x800CB2D4: mul.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CB2D8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800CB2DC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CB2E0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CB2E4: bne         $v1, $a0, L_800CB2B0
    if (ctx->r3 != ctx->r4) {
        // 0x800CB2E8: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800CB2B0;
    }
    // 0x800CB2E8: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800CB2EC:
    // 0x800CB2EC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CB2F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CB2F4: swc1        $f14, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f14.u32l;
    // 0x800CB2F8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CB2FC: nop

    // 0x800CB300: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CB304: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800CB308: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CB30C: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800CB310: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CB314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CB318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB31C: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x800CB320: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x800CB324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CB328: bc1fl       L_800CB33C
    if (!c1cs) {
        // 0x800CB32C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800CB33C;
    }
    goto skip_2;
    // 0x800CB32C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x800CB330: b           L_800CB3D4
    // 0x800CB334: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
        goto L_800CB3D4;
    // 0x800CB334: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800CB338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800CB33C:
    // 0x800CB33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB340: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CB344: div.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800CB348: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CB34C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CB350: nop

    // 0x800CB354: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CB358: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CB35C: nop

    // 0x800CB360: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CB364: beql        $v0, $zero, L_800CB3B4
    if (ctx->r2 == 0) {
        // 0x800CB368: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_800CB3B4;
    }
    goto skip_3;
    // 0x800CB368: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800CB36C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CB370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB374: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CB378: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CB37C: nop

    // 0x800CB380: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CB384: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CB388: nop

    // 0x800CB38C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CB390: bne         $v0, $zero, L_800CB3A8
    if (ctx->r2 != 0) {
        // 0x800CB394: nop
    
            goto L_800CB3A8;
    }
    // 0x800CB394: nop

    // 0x800CB398: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800CB39C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CB3A0: b           L_800CB3C0
    // 0x800CB3A4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800CB3C0;
    // 0x800CB3A4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800CB3A8:
    // 0x800CB3A8: b           L_800CB3C0
    // 0x800CB3AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CB3C0;
    // 0x800CB3AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CB3B0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_800CB3B4:
    // 0x800CB3B4: nop

    // 0x800CB3B8: bltz        $v0, L_800CB3A8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CB3BC: nop
    
            goto L_800CB3A8;
    }
    // 0x800CB3BC: nop

L_800CB3C0:
    // 0x800CB3C0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CB3C4: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800CB3C8: bgtz        $t7, L_800CB3D4
    if (SIGNED(ctx->r15) > 0) {
        // 0x800CB3CC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_800CB3D4;
    }
    // 0x800CB3CC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800CB3D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800CB3D4:
    // 0x800CB3D4: jr          $ra
    // 0x800CB3D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CB3D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CB3DC: nop

;}
RECOMP_FUNC void func_800BABB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BABB0: jr          $ra
    // 0x800BABB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800BABB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800FB6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB6E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FB6E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB6E8: addiu       $v0, $v0, 0x59B4
    ctx->r2 = ADD32(ctx->r2, 0X59B4);
    // 0x800FB6EC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800FB6F0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800FB6F4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FB6F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FB6FC: addiu       $v1, $v1, 0x59B8
    ctx->r3 = ADD32(ctx->r3, 0X59B8);
    // 0x800FB700: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800FB704: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800FB708: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x800FB70C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FB710: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800FB714: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FB718: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800FB71C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FB720: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x800FB724: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800FB728: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800FB72C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FB730: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x800FB734: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800FB738: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800FB73C: sh          $t6, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r14;
    // 0x800FB740: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
    // 0x800FB744: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800FB748: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x800FB74C: sb          $zero, 0x31($a0)
    MEM_B(0X31, ctx->r4) = 0;
    // 0x800FB750: sb          $zero, 0x32($a0)
    MEM_B(0X32, ctx->r4) = 0;
    // 0x800FB754: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
    // 0x800FB758: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800FB75C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800FB760: bne         $a1, $zero, L_800FB76C
    if (ctx->r5 != 0) {
        // 0x800FB764: swc1        $f10, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
            goto L_800FB76C;
    }
    // 0x800FB764: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x800FB768: sb          $zero, 0x33($a0)
    MEM_B(0X33, ctx->r4) = 0;
L_800FB76C:
    // 0x800FB76C: jr          $ra
    // 0x800FB770: nop

    return;
    // 0x800FB770: nop

;}
RECOMP_FUNC void sccustom_big_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808002E4: jal         0x80800044
    // 0x808002E8: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_80800044_sccustom_big(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x808002EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808002F8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808002FC: jal         0x808000B4
    // 0x80800300: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_808000B4_sccustom_big(rdram, ctx);
        goto after_1;
    // 0x80800300: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void func_800F212C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F212C: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800F2130: abs.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = fabsf(ctx->f14.fl);
    // 0x800F2134: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F2138: bc1t        L_800F2144
    if (c1cs) {
        // 0x800F213C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800F2144;
    }
    // 0x800F213C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F2140: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800F2144:
    // 0x800F2144: jr          $ra
    // 0x800F2148: nop

    return;
    // 0x800F2148: nop

;}
RECOMP_FUNC void func_800EA358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA358: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA35C: jr          $ra
    // 0x800EA360: lh          $v0, 0x2DCC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DCC);
    return;
    // 0x800EA360: lh          $v0, 0x2DCC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DCC);
;}
RECOMP_FUNC void func_800A7FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7FBC: jal         0x800A7584
    // 0x800A7FC0: nop

    func_800A7584(rdram, ctx);
        goto after_0;
    // 0x800A7FC0: nop

    after_0:
    // 0x800A7FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7FCC: jr          $ra
    // 0x800A7FD0: nop

    return;
    // 0x800A7FD0: nop

;}
RECOMP_FUNC void func_80802594_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080259C: jal         0x80100094
    // 0x808025A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808025A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808025A8: lbu         $t6, 0x57($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X57);
    // 0x808025AC: beql        $t6, $zero, L_808025D0
    if (ctx->r14 == 0) {
        // 0x808025B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808025D0;
    }
    goto skip_0;
    // 0x808025B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808025B4: jal         0x800F54E4
    // 0x808025B8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808025B8: nop

    after_1:
    // 0x808025BC: jal         0x800F4B20
    // 0x808025C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_2;
    // 0x808025C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808025C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808025C8: sb          $zero, 0x57($t7)
    MEM_B(0X57, ctx->r15) = 0;
    // 0x808025CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808025D0:
    // 0x808025D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808025D4: jr          $ra
    // 0x808025D8: nop

    return;
    // 0x808025D8: nop

;}
RECOMP_FUNC void chlighthalo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2432, 0X6A8) << 16);
    // 0x8080063C: jr          $ra
    // 0x80800640: addiu       $v0, $v0, 0x6A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2432, 0X6A8));
    return;
    // 0x80800640: addiu       $v0, $v0, 0x6A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2432, 0X6A8));
    // 0x80800644: nop

    // 0x80800648: nop

    // 0x8080064C: nop

;}
RECOMP_FUNC void func_800A042C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A042C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A0438: jal         0x8009BF5C
    // 0x800A043C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x800A043C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x800A0440: jal         0x8009BFBC
    // 0x800A0444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009BFBC(rdram, ctx);
        goto after_1;
    // 0x800A0444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A0448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A044C: jal         0x8009C4CC
    // 0x800A0450: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x800A0450: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x800A0454: jal         0x8009C52C
    // 0x800A0458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baroll_applyIdeal(rdram, ctx);
        goto after_3;
    // 0x800A0458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800A045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0464: jr          $ra
    // 0x800A0468: nop

    return;
    // 0x800A0468: nop

;}
RECOMP_FUNC void func_800E4BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4BC0: jal         0x800E4730
    // 0x800E4BC4: nop

    func_800E4730(rdram, ctx);
        goto after_0;
    // 0x800E4BC4: nop

    after_0:
    // 0x800E4BC8: bgez        $v0, L_800E4BD8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E4BCC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800E4BD8;
    }
    // 0x800E4BCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E4BD0: b           L_800E4BE4
    // 0x800E4BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4BE4;
    // 0x800E4BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4BD8:
    // 0x800E4BD8: jal         0x800E4B1C
    // 0x800E4BDC: nop

    func_800E4B1C(rdram, ctx);
        goto after_1;
    // 0x800E4BDC: nop

    after_1:
    // 0x800E4BE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4BE4:
    // 0x800E4BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E4BEC: jr          $ra
    // 0x800E4BF0: nop

    return;
    // 0x800E4BF0: nop

;}
RECOMP_FUNC void func_80800CAC_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB4: jal         0x8008FFBC
    // 0x80800CB8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008FFBC(rdram, ctx);
        goto after_0;
    // 0x80800CB8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800CBC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800CC0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800CC4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800CC8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80800CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CD4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800CD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800CDC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80800CE0: add.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800CE4: jr          $ra
    // 0x80800CE8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80800CE8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void _chmole_cuckoo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086ED0: syscall     469
    recomp_syscall_handler(rdram, ctx, 0x80086ED0);
    return;
    // 0x80086ED4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A0C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0C20: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0C24: jr          $ra
    // 0x800A0C28: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    return;
    // 0x800A0C28: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_808008CC_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808008D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008DC: jal         0x800F54E4
    // 0x808008E0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808008E0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808008E4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808008E8: bnel        $v0, $a0, L_80800E2C
    if (ctx->r2 != ctx->r4) {
        // 0x808008EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_0;
    // 0x808008EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808008F0: jal         0x800F5410
    // 0x808008F4: nop

    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x808008F4: nop

    after_1:
    // 0x808008F8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808008FC: bne         $v0, $at, L_80800DF8
    if (ctx->r2 != ctx->r1) {
        // 0x80800900: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800DF8;
    }
    // 0x80800900: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800904: jal         0x80015E80
    // 0x80800908: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80015E80(rdram, ctx);
        goto after_2;
    // 0x80800908: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8080090C: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800910: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    // 0x80800914: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800918: jal         0x800DA298
    // 0x8080091C: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080091C: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    after_3:
    // 0x80800920: bnel        $v0, $zero, L_8080094C
    if (ctx->r2 != 0) {
        // 0x80800924: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_8080094C;
    }
    goto skip_1;
    // 0x80800924: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800928: jal         0x800DA544
    // 0x8080092C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080092C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    after_4:
    // 0x80800930: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800934: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800938: addiu       $a1, $zero, 0x11DD
    ctx->r5 = ADD32(0, 0X11DD);
    // 0x8080093C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800940: jal         0x8008A208
    // 0x80800944: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800944: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800948: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8080094C:
    // 0x8080094C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800950: bnel        $t9, $at, L_80800E2C
    if (ctx->r25 != ctx->r1) {
        // 0x80800954: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_2;
    // 0x80800954: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800958: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8080095C: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800960: bltzl       $t2, L_80800E2C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800964: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_3;
    // 0x80800964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800968: jal         0x800DA298
    // 0x8080096C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x8080096C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_6:
    // 0x80800970: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800974: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_4;
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800978: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x8080097C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800980: sltiu       $at, $t4, 0x11
    ctx->r1 = ctx->r12 < 0X11 ? 1 : 0;
    // 0x80800984: beq         $at, $zero, L_80800E28
    if (ctx->r1 == 0) {
        // 0x80800988: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80800E28;
    }
    // 0x80800988: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8080098C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1720, 0X1010) << 16);
    // 0x80800990: addu        $at, $at, $t4
    gpr jr_addend_80800998 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800994: lw          $t4, 0x1010($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1720, 0X1010));
    // 0x80800998: jr          $t4
    // 0x8080099C: nop

    switch (jr_addend_80800998 >> 2) {
        case 0: goto L_808009A0; break;
        case 1: goto L_808009C0; break;
        case 2: goto L_808009E4; break;
        case 3: goto L_808009F8; break;
        case 4: goto L_80800A0C; break;
        case 5: goto L_80800A20; break;
        case 6: goto L_80800A34; break;
        case 7: goto L_80800A54; break;
        case 8: goto L_80800A74; break;
        case 9: goto L_80800A94; break;
        case 10: goto L_80800B24; break;
        case 11: goto L_80800AA8; break;
        case 12: goto L_80800B90; break;
        case 13: goto L_80800BE0; break;
        case 14: goto L_80800C04; break;
        case 15: goto L_80800C70; break;
        case 16: goto L_80800CDC; break;
        default: switch_error(__func__, 0x80800998, 0x80801010);
    }
    // 0x8080099C: nop

L_808009A0:
    // 0x808009A0: jal         0x800DA298
    // 0x808009A4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808009A4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_7:
    // 0x808009A8: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x808009AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: jal         0x8080063C
    // 0x808009B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_8;
    // 0x808009B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x808009B8: b           L_80800E2C
    // 0x808009BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x808009BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009C0:
    // 0x808009C0: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    // 0x808009C4: jal         0x800DA564
    // 0x808009C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_9;
    // 0x808009C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x808009CC: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x808009D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: jal         0x8080063C
    // 0x808009D8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_10;
    // 0x808009D8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x808009DC: b           L_80800E2C
    // 0x808009E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x808009E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009E4:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: jal         0x8080063C
    // 0x808009EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_11;
    // 0x808009EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x808009F0: b           L_80800E2C
    // 0x808009F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x808009F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009F8:
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: jal         0x8080063C
    // 0x80800A00: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_12;
    // 0x80800A00: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_12:
    // 0x80800A04: b           L_80800E2C
    // 0x80800A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A0C:
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: jal         0x8080063C
    // 0x80800A14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_13;
    // 0x80800A14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x80800A18: b           L_80800E2C
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A20:
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A24: jal         0x8080063C
    // 0x80800A28: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_14;
    // 0x80800A28: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_14:
    // 0x80800A2C: b           L_80800E2C
    // 0x80800A30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A34:
    // 0x80800A34: jal         0x800DA298
    // 0x80800A38: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800A38: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    after_15:
    // 0x80800A3C: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: jal         0x8080063C
    // 0x80800A48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_16;
    // 0x80800A48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_16:
    // 0x80800A4C: b           L_80800E2C
    // 0x80800A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A54:
    // 0x80800A54: jal         0x800DA298
    // 0x80800A58: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x80800A58: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_17:
    // 0x80800A5C: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x8080063C
    // 0x80800A68: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_18;
    // 0x80800A68: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_18:
    // 0x80800A6C: b           L_80800E2C
    // 0x80800A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A74:
    // 0x80800A74: jal         0x800DA298
    // 0x80800A78: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x80800A78: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_19:
    // 0x80800A7C: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800A80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: jal         0x8080063C
    // 0x80800A88: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_20;
    // 0x80800A88: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_20:
    // 0x80800A8C: b           L_80800E2C
    // 0x80800A90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800A90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A94:
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x8080063C
    // 0x80800A9C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_21;
    // 0x80800A9C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_21:
    // 0x80800AA0: b           L_80800E2C
    // 0x80800AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AA8:
    // 0x80800AA8: jal         0x800DA298
    // 0x80800AAC: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x80800AAC: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    after_22:
    // 0x80800AB0: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800AB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_5;
    // 0x80800AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80800AB8: jal         0x800DA298
    // 0x80800ABC: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x80800ABC: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    after_23:
    // 0x80800AC0: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800AC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_6;
    // 0x80800AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80800AC8: jal         0x800DA298
    // 0x80800ACC: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_24;
    // 0x80800ACC: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_24:
    // 0x80800AD0: bne         $v0, $zero, L_80800AE8
    if (ctx->r2 != 0) {
        // 0x80800AD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE8;
    }
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x8080063C
    // 0x80800ADC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_25;
    // 0x80800ADC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_25:
    // 0x80800AE0: b           L_80800E2C
    // 0x80800AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AE8:
    // 0x80800AE8: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80800AEC: addiu       $a1, $zero, 0x11E9
    ctx->r5 = ADD32(0, 0X11E9);
    // 0x80800AF0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800AF4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80800AF8: bltz        $t7, L_80800E28
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800AFC: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_80800E28;
    }
    // 0x80800AFC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800B00: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x80800B04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B08: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80800B0C: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80800B10: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    // 0x80800B14: jal         0x8008A208
    // 0x80800B18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800B18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_26:
    // 0x80800B1C: b           L_80800E2C
    // 0x80800B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B24:
    // 0x80800B24: jal         0x800DA298
    // 0x80800B28: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800B28: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_27:
    // 0x80800B2C: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800B30: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_7;
    // 0x80800B30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80800B34: jal         0x800DA298
    // 0x80800B38: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    func_800DA298(rdram, ctx);
        goto after_28;
    // 0x80800B38: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    after_28:
    // 0x80800B3C: bne         $v0, $zero, L_80800B54
    if (ctx->r2 != 0) {
        // 0x80800B40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B54;
    }
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x8080063C
    // 0x80800B48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_29;
    // 0x80800B48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x80800B4C: b           L_80800E2C
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B54:
    // 0x80800B54: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80800B58: addiu       $a1, $zero, 0x11E9
    ctx->r5 = ADD32(0, 0X11E9);
    // 0x80800B5C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800B60: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80800B64: bltz        $t4, L_80800E28
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800B68: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_80800E28;
    }
    // 0x80800B68: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800B6C: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x80800B70: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B74: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80800B78: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80800B7C: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x80800B80: jal         0x8008A208
    // 0x80800B84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_30;
    // 0x80800B84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_30:
    // 0x80800B88: b           L_80800E2C
    // 0x80800B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B90:
    // 0x80800B90: jal         0x800DA298
    // 0x80800B94: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800DA298(rdram, ctx);
        goto after_31;
    // 0x80800B94: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_31:
    // 0x80800B98: beql        $v0, $zero, L_80800BD0
    if (ctx->r2 == 0) {
        // 0x80800B9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD0;
    }
    goto skip_8;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x80800BA0: jal         0x800DA298
    // 0x80800BA4: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    func_800DA298(rdram, ctx);
        goto after_32;
    // 0x80800BA4: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    after_32:
    // 0x80800BA8: beql        $v0, $zero, L_80800BD0
    if (ctx->r2 == 0) {
        // 0x80800BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD0;
    }
    goto skip_9;
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x80800BB0: jal         0x800DA298
    // 0x80800BB4: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    func_800DA298(rdram, ctx);
        goto after_33;
    // 0x80800BB4: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    after_33:
    // 0x80800BB8: beql        $v0, $zero, L_80800BD0
    if (ctx->r2 == 0) {
        // 0x80800BBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD0;
    }
    goto skip_10;
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x80800BC0: jal         0x800DA298
    // 0x80800BC4: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x80800BC4: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    after_34:
    // 0x80800BC8: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800BCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BD0:
    // 0x80800BD0: jal         0x8080063C
    // 0x80800BD4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_35;
    // 0x80800BD4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_35:
    // 0x80800BD8: b           L_80800E2C
    // 0x80800BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BE0:
    // 0x80800BE0: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x80800BE4: jal         0x800DA564
    // 0x80800BE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_36;
    // 0x80800BE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_36:
    // 0x80800BEC: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800BF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: jal         0x8080063C
    // 0x80800BF8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_37;
    // 0x80800BF8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_37:
    // 0x80800BFC: b           L_80800E2C
    // 0x80800C00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800C00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C04:
    // 0x80800C04: jal         0x800DA298
    // 0x80800C08: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    func_800DA298(rdram, ctx);
        goto after_38;
    // 0x80800C08: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    after_38:
    // 0x80800C0C: beql        $v0, $zero, L_80800C38
    if (ctx->r2 == 0) {
        // 0x80800C10: lw          $t9, 0x74($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X74);
            goto L_80800C38;
    }
    goto skip_11;
    // 0x80800C10: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    skip_11:
    // 0x80800C14: jal         0x800DA298
    // 0x80800C18: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    func_800DA298(rdram, ctx);
        goto after_39;
    // 0x80800C18: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    after_39:
    // 0x80800C1C: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x80800C20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: jal         0x8080063C
    // 0x80800C28: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_40;
    // 0x80800C28: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_40:
    // 0x80800C2C: b           L_80800E2C
    // 0x80800C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C34:
    // 0x80800C34: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
L_80800C38:
    // 0x80800C38: addiu       $a1, $zero, 0x11EC
    ctx->r5 = ADD32(0, 0X11EC);
    // 0x80800C3C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800C40: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80800C44: bltz        $t1, L_80800E28
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800C48: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_80800E28;
    }
    // 0x80800C48: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800C4C: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800C50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800C54: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80800C58: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800C5C: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    // 0x80800C60: jal         0x8008A208
    // 0x80800C64: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_41;
    // 0x80800C64: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_41:
    // 0x80800C68: b           L_80800E2C
    // 0x80800C6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800C6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C70:
    // 0x80800C70: jal         0x800DA298
    // 0x80800C74: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    func_800DA298(rdram, ctx);
        goto after_42;
    // 0x80800C74: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    after_42:
    // 0x80800C78: bnel        $v0, $zero, L_80800CA4
    if (ctx->r2 != 0) {
        // 0x80800C7C: lw          $t6, 0x74($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X74);
            goto L_80800CA4;
    }
    goto skip_12;
    // 0x80800C7C: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    skip_12:
    // 0x80800C80: jal         0x800DA298
    // 0x80800C84: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    func_800DA298(rdram, ctx);
        goto after_43;
    // 0x80800C84: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    after_43:
    // 0x80800C88: beq         $v0, $zero, L_80800CA0
    if (ctx->r2 == 0) {
        // 0x80800C8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CA0;
    }
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: jal         0x8080063C
    // 0x80800C94: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_44;
    // 0x80800C94: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_44:
    // 0x80800C98: b           L_80800E2C
    // 0x80800C9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800C9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CA0:
    // 0x80800CA0: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
L_80800CA4:
    // 0x80800CA4: addiu       $a1, $zero, 0x11EC
    ctx->r5 = ADD32(0, 0X11EC);
    // 0x80800CA8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800CAC: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80800CB0: bltz        $t8, L_80800E28
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800CB4: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_80800E28;
    }
    // 0x80800CB4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800CB8: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x80800CBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CC0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80800CC4: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800CC8: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    // 0x80800CCC: jal         0x8008A208
    // 0x80800CD0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_45;
    // 0x80800CD0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_45:
    // 0x80800CD4: b           L_80800E2C
    // 0x80800CD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800CD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CDC:
    // 0x80800CDC: jal         0x800DA298
    // 0x80800CE0: addiu       $a0, $zero, 0x4F3
    ctx->r4 = ADD32(0, 0X4F3);
    func_800DA298(rdram, ctx);
        goto after_46;
    // 0x80800CE0: addiu       $a0, $zero, 0x4F3
    ctx->r4 = ADD32(0, 0X4F3);
    after_46:
    // 0x80800CE4: beq         $v0, $zero, L_80800D8C
    if (ctx->r2 == 0) {
        // 0x80800CE8: nop
    
            goto L_80800D8C;
    }
    // 0x80800CE8: nop

    // 0x80800CEC: jal         0x800DA298
    // 0x80800CF0: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_47;
    // 0x80800CF0: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_47:
    // 0x80800CF4: bne         $v0, $zero, L_80800D8C
    if (ctx->r2 != 0) {
        // 0x80800CF8: nop
    
            goto L_80800D8C;
    }
    // 0x80800CF8: nop

    // 0x80800CFC: jal         0x800C0638
    // 0x80800D00: nop

    func_800C0638(rdram, ctx);
        goto after_48;
    // 0x80800D00: nop

    after_48:
    // 0x80800D04: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800D08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_13;
    // 0x80800D08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x80800D0C: jal         0x800DA298
    // 0x80800D10: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_49;
    // 0x80800D10: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_49:
    // 0x80800D14: beq         $v0, $zero, L_80800D30
    if (ctx->r2 == 0) {
        // 0x80800D18: addiu       $a0, $zero, 0x6DB
        ctx->r4 = ADD32(0, 0X6DB);
            goto L_80800D30;
    }
    // 0x80800D18: addiu       $a0, $zero, 0x6DB
    ctx->r4 = ADD32(0, 0X6DB);
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D20: jal         0x8080063C
    // 0x80800D24: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_8080063C_chmumbopad(rdram, ctx);
        goto after_50;
    // 0x80800D24: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_50:
    // 0x80800D28: b           L_80800E2C
    // 0x80800D2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800D2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D30:
    // 0x80800D30: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800D34: jal         0x800DA298
    // 0x80800D38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_51;
    // 0x80800D38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_51:
    // 0x80800D3C: beq         $v0, $zero, L_80800D64
    if (ctx->r2 == 0) {
        // 0x80800D40: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D64;
    }
    // 0x80800D40: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D48: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80800D4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800D50: addiu       $a1, $zero, 0x150E
    ctx->r5 = ADD32(0, 0X150E);
    // 0x80800D54: jal         0x8008A208
    // 0x80800D58: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_52;
    // 0x80800D58: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_52:
    // 0x80800D5C: b           L_80800E2C
    // 0x80800D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D64:
    // 0x80800D64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D68: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80800D6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800D70: addiu       $a1, $zero, 0x150F
    ctx->r5 = ADD32(0, 0X150F);
    // 0x80800D74: jal         0x8008A208
    // 0x80800D78: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_53;
    // 0x80800D78: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_53:
    // 0x80800D7C: jal         0x800DA544
    // 0x80800D80: addiu       $a0, $zero, 0x6DB
    ctx->r4 = ADD32(0, 0X6DB);
    func_800DA544(rdram, ctx);
        goto after_54;
    // 0x80800D80: addiu       $a0, $zero, 0x6DB
    ctx->r4 = ADD32(0, 0X6DB);
    after_54:
    // 0x80800D84: b           L_80800E2C
    // 0x80800D88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800D88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D8C:
    // 0x80800D8C: jal         0x800C0638
    // 0x80800D90: nop

    func_800C0638(rdram, ctx);
        goto after_55;
    // 0x80800D90: nop

    after_55:
    // 0x80800D94: bne         $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800D98: addiu       $a0, $zero, 0x6DC
        ctx->r4 = ADD32(0, 0X6DC);
            goto L_80800E28;
    }
    // 0x80800D98: addiu       $a0, $zero, 0x6DC
    ctx->r4 = ADD32(0, 0X6DC);
    // 0x80800D9C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800DA0: jal         0x800DA298
    // 0x80800DA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_56;
    // 0x80800DA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_56:
    // 0x80800DA8: beq         $v0, $zero, L_80800DD0
    if (ctx->r2 == 0) {
        // 0x80800DAC: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800DD0;
    }
    // 0x80800DAC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DB4: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80800DB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800DBC: addiu       $a1, $zero, 0x150D
    ctx->r5 = ADD32(0, 0X150D);
    // 0x80800DC0: jal         0x8008A208
    // 0x80800DC4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_57;
    // 0x80800DC4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_57:
    // 0x80800DC8: b           L_80800E2C
    // 0x80800DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DD0:
    // 0x80800DD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DD4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80800DD8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800DDC: addiu       $a1, $zero, 0x150C
    ctx->r5 = ADD32(0, 0X150C);
    // 0x80800DE0: jal         0x8008A208
    // 0x80800DE4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_58;
    // 0x80800DE4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_58:
    // 0x80800DE8: jal         0x800DA544
    // 0x80800DEC: addiu       $a0, $zero, 0x6DC
    ctx->r4 = ADD32(0, 0X6DC);
    func_800DA544(rdram, ctx);
        goto after_59;
    // 0x80800DEC: addiu       $a0, $zero, 0x6DC
    ctx->r4 = ADD32(0, 0X6DC);
    after_59:
    // 0x80800DF0: b           L_80800E2C
    // 0x80800DF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E2C;
    // 0x80800DF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DF8:
    // 0x80800DF8: jal         0x800DA298
    // 0x80800DFC: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    func_800DA298(rdram, ctx);
        goto after_60;
    // 0x80800DFC: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    after_60:
    // 0x80800E00: bnel        $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800E04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_14;
    // 0x80800E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
    // 0x80800E08: jal         0x800DA544
    // 0x80800E0C: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    func_800DA544(rdram, ctx);
        goto after_61;
    // 0x80800E0C: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    after_61:
    // 0x80800E10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E18: addiu       $a1, $zero, 0x11DC
    ctx->r5 = ADD32(0, 0X11DC);
    // 0x80800E1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800E20: jal         0x8008A208
    // 0x80800E24: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_62;
    // 0x80800E24: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_62:
L_80800E28:
    // 0x80800E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E2C:
    // 0x80800E2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800E34: jr          $ra
    // 0x80800E38: nop

    return;
    // 0x80800E38: nop

;}
RECOMP_FUNC void chhoneyb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D7C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800D80: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800D84: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80800D88: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800D8C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80800D90: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800D94: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80800D98: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80800D9C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80800DA0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800DA4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800DA8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800DAC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800DB0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800DB4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800DB8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800DBC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800DC0: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80800DC4: jal         0x800D674C
    // 0x80800DC8: addiu       $a0, $zero, 0xB4D
    ctx->r4 = ADD32(0, 0XB4D);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800DC8: addiu       $a0, $zero, 0xB4D
    ctx->r4 = ADD32(0, 0XB4D);
    after_0:
    // 0x80800DCC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800DD0: jal         0x8008A5D8
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800DD8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800DDC: jal         0x8008A610
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DE4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800DE8: jal         0x8008A5F0
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DF0: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800DF4: lwc1        $f22, 0x84($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800DF8: jal         0x8008A618
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E00: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800E04: jal         0x8008A620
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E0C: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80800E10: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800E14: addiu       $s5, $sp, 0x70
    ctx->r21 = ADD32(ctx->r29, 0X70);
    // 0x80800E18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800E1C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800E20: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800E24: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80800E28: nop

    // 0x80800E2C: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800E30: beq         $at, $zero, L_80800E74
    if (ctx->r1 == 0) {
        // 0x80800E34: subu        $t8, $v1, $s4
        ctx->r24 = SUB32(ctx->r3, ctx->r20);
            goto L_80800E74;
    }
    // 0x80800E34: subu        $t8, $v1, $s4
    ctx->r24 = SUB32(ctx->r3, ctx->r20);
    // 0x80800E38: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800E3C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80800E40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E44: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800E48: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800E4C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800E50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800E58: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800E5C: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80800E60: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800E64: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800E68: mfc1        $s6, $f18
    ctx->r22 = (int32_t)ctx->f18.u32l;
    // 0x80800E6C: b           L_80800E84
    // 0x80800E70: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
        goto L_80800E84;
    // 0x80800E70: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_80800E74:
    // 0x80800E74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E78: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800E7C: addiu       $s6, $zero, 0x100
    ctx->r22 = ADD32(0, 0X100);
    // 0x80800E80: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_80800E84:
    // 0x80800E84: bltz        $v1, L_80800F90
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800E88: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_80800F90;
    }
    // 0x80800E88: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80800E8C: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x80800E90: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x80800E94: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80800E98: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
L_80800E9C:
    // 0x80800E9C: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x80800EA0: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80800EA4: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80800EA8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800EAC: sll         $a0, $s6, 8
    ctx->r4 = S32(ctx->r22 << 8);
    // 0x80800EB0: subu        $a0, $a0, $s6
    ctx->r4 = SUB32(ctx->r4, ctx->r22);
    // 0x80800EB4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800EB8: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80800EBC: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x80800EC0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800EC4: sra         $t3, $a0, 8
    ctx->r11 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80800EC8: addiu       $t4, $s0, 0x1
    ctx->r12 = ADD32(ctx->r16, 0X1);
    // 0x80800ECC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800ED0: mfc1        $s2, $f16
    ctx->r18 = (int32_t)ctx->f16.u32l;
    // 0x80800ED4: beql        $at, $zero, L_80800F88
    if (ctx->r1 == 0) {
        // 0x80800ED8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800F88;
    }
    goto skip_0;
    // 0x80800ED8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x80800EDC: bne         $t1, $t4, L_80800F40
    if (ctx->r9 != ctx->r12) {
        // 0x80800EE0: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80800F40;
    }
    // 0x80800EE0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800EE4: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x80800EE8: nop

    // 0x80800EEC: bc1fl       L_80800F44
    if (!c1cs) {
        // 0x80800EF0: slt         $at, $s4, $s2
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80800F44;
    }
    goto skip_1;
    // 0x80800EF0: slt         $at, $s4, $s2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r18) ? 1 : 0;
    skip_1:
    // 0x80800EF4: addiu       $s1, $s1, -0x14
    ctx->r17 = ADD32(ctx->r17, -0X14);
    // 0x80800EF8: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80800EFC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80800F00: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    // 0x80800F04: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F08: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80800F0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800F10: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800F14: nop

    // 0x80800F18: subu        $t6, $s2, $v0
    ctx->r14 = SUB32(ctx->r18, ctx->r2);
    // 0x80800F1C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800F20: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800F24: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F28: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800F2C: mul.s       $f6, $f22, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x80800F30: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800F34: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800F38: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x80800F3C: nop

L_80800F40:
    // 0x80800F40: slt         $at, $s4, $s2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r18) ? 1 : 0;
L_80800F44:
    // 0x80800F44: beq         $at, $zero, L_80800F50
    if (ctx->r1 == 0) {
        // 0x80800F48: nop
    
            goto L_80800F50;
    }
    // 0x80800F48: nop

    // 0x80800F4C: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80800F50:
    // 0x80800F50: jal         0x800E257C
    // 0x80800F54: nop

    func_800E257C(rdram, ctx);
        goto after_6;
    // 0x80800F54: nop

    after_6:
    // 0x80800F58: jal         0x800E253C
    // 0x80800F5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E253C(rdram, ctx);
        goto after_7;
    // 0x80800F5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x80800F60: addu        $t8, $fp, $s2
    ctx->r24 = ADD32(ctx->r30, ctx->r18);
    // 0x80800F64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800F68: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x80800F6C: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80800F70: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800F74: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800F78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F7C: jal         0x800E30E0
    // 0x80800F80: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_800E30E0(rdram, ctx);
        goto after_8;
    // 0x80800F80: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_8:
    // 0x80800F84: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80800F88:
    // 0x80800F88: bgez        $s0, L_80800E9C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80800F8C: addiu       $s1, $s1, -0x14
        ctx->r17 = ADD32(ctx->r17, -0X14);
            goto L_80800E9C;
    }
    // 0x80800F8C: addiu       $s1, $s1, -0x14
    ctx->r17 = ADD32(ctx->r17, -0X14);
L_80800F90:
    // 0x80800F90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800F94: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800F98: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800F9C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800FA0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800FA4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800FA8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800FAC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FB0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800FB4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80800FB8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800FBC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80800FC0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80800FC4: jr          $ra
    // 0x80800FC8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800FC8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80800FCC: nop

;}
RECOMP_FUNC void func_80800DFC_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E08: jal         0x800DA298
    // 0x80800E0C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800E0C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x80800E10: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800E14: beq         $t6, $zero, L_80800E40
    if (ctx->r14 == 0) {
        // 0x80800E18: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800E40;
    }
    // 0x80800E18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800E1C: jal         0x80090128
    // 0x80800E20: nop

    func_80090128(rdram, ctx);
        goto after_1;
    // 0x80800E20: nop

    after_1:
    // 0x80800E24: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E28: beq         $t7, $zero, L_80800E40
    if (ctx->r15 == 0) {
        // 0x80800E2C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800E40;
    }
    // 0x80800E2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800E30: jal         0x8010C500
    // 0x80800E34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010C500(rdram, ctx);
        goto after_2;
    // 0x80800E34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800E38: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80800E40:
    // 0x80800E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E48: jr          $ra
    // 0x80800E4C: nop

    return;
    // 0x80800E4C: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C9C: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80801CA0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801CA4: bnel        $t6, $zero, L_80801CB8
    if (ctx->r14 != 0) {
        // 0x80801CA8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80801CB8;
    }
    goto skip_0;
    // 0x80801CA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x80801CAC: lbu         $t7, 0x76($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X76);
    // 0x80801CB0: beq         $t7, $zero, L_80801D00
    if (ctx->r15 == 0) {
        // 0x80801CB4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80801D00;
    }
    // 0x80801CB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80801CB8:
    // 0x80801CB8: jal         0x80800C54
    // 0x80801CBC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80800C54_gcmapsects(rdram, ctx);
        goto after_0;
    // 0x80801CBC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801CC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801CC4: jal         0x8001B084
    // 0x80801CC8: lw          $a0, 0x68($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X68);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x80801CC8: lw          $a0, 0x68($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X68);
    after_1:
    // 0x80801CCC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801CD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CD8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80801CDC: sw          $zero, 0x68($a1)
    MEM_W(0X68, ctx->r5) = 0;
    // 0x80801CE0: sb          $zero, 0x77($a1)
    MEM_B(0X77, ctx->r5) = 0;
    // 0x80801CE4: sb          $zero, 0x76($a1)
    MEM_B(0X76, ctx->r5) = 0;
    // 0x80801CE8: sb          $zero, 0x78($a1)
    MEM_B(0X78, ctx->r5) = 0;
    // 0x80801CEC: sb          $v0, 0x7B($a1)
    MEM_B(0X7B, ctx->r5) = ctx->r2;
    // 0x80801CF0: sb          $v0, 0x7E($a1)
    MEM_B(0X7E, ctx->r5) = ctx->r2;
    // 0x80801CF4: sb          $zero, 0x7C($a1)
    MEM_B(0X7C, ctx->r5) = 0;
    // 0x80801CF8: sb          $t8, 0x7F($a1)
    MEM_B(0X7F, ctx->r5) = ctx->r24;
    // 0x80801CFC: swc1        $f4, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f4.u32l;
L_80801D00:
    // 0x80801D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D08: jr          $ra
    // 0x80801D0C: nop

    return;
    // 0x80801D0C: nop

;}
RECOMP_FUNC void chping_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "chping_entrypoint_0");
    // 0x80800384: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080038C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800390: jal         0x800F5A00
    // 0x80800394: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x80800394: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800398: addiu       $a0, $zero, 0x169
    ctx->r4 = ADD32(0, 0X169);
    // 0x8080039C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808003A0: jal         0x80108474
    // 0x808003A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808003A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808003A8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003B0: jal         0x80100094
    // 0x808003B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808003B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003BC: nop

    // 0x808003C0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808003C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808003C8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x808003CC: jal         0x8010A570
    // 0x808003D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808003D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808003D4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003DC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x808003E0: jr          $ra
    // 0x808003E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808003E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AA0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082AA0);
    return;
    // 0x80082AA4: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80800600_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800608: jal         0x80088848
    // 0x8080060C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080060C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800610: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x80800614: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800620;
    }
    // 0x80800614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800618: jal         0x80102424
    // 0x8080061C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080061C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
L_80800620:
    // 0x80800620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void func_800F7A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7A80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F7A84: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F7A88: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7A8C: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800F7A90: lw          $s0, 0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5490);
    // 0x800F7A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7A98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7A9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F7AA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7AA4: jal         0x8009AD38
    // 0x800F7AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AD38(rdram, ctx);
        goto after_0;
    // 0x800F7AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F7AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7AB0: jal         0x8009AD20
    // 0x800F7AB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD20(rdram, ctx);
        goto after_1;
    // 0x800F7AB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F7AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7ABC: jal         0x8009AD2C
    // 0x800F7AC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD2C(rdram, ctx);
        goto after_2;
    // 0x800F7AC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800F7AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7AC8: jal         0x8009AD44
    // 0x800F7ACC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8009AD44(rdram, ctx);
        goto after_3;
    // 0x800F7ACC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800F7AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7AD4: jal         0x8009E7C8
    // 0x800F7AD8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8009E7C8(rdram, ctx);
        goto after_4;
    // 0x800F7AD8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_4:
    // 0x800F7ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7AE0: xori        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 ^ 0X2;
    // 0x800F7AE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F7AE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7AEC: jr          $ra
    // 0x800F7AF0: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x800F7AF0: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_800A22C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A22C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A22CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A22D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A22D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800A22D8:
    // 0x800A22D8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A22DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800A22E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A22E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A22E8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A22EC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800A22F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800A22F4: bgez        $t8, L_800A2304
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A22F8: sra         $t9, $t8, 8
        ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
            goto L_800A2304;
    }
    // 0x800A22F8: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800A22FC: addiu       $at, $t8, 0xFF
    ctx->r1 = ADD32(ctx->r24, 0XFF);
    // 0x800A2300: sra         $t9, $at, 8
    ctx->r25 = S32(SIGNED(ctx->r1) >> 8);
L_800A2304:
    // 0x800A2304: bne         $v0, $a0, L_800A22D8
    if (ctx->r2 != ctx->r4) {
        // 0x800A2308: sw          $t9, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r25;
            goto L_800A22D8;
    }
    // 0x800A2308: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x800A230C: jr          $ra
    // 0x800A2310: nop

    return;
    // 0x800A2310: nop

;}
RECOMP_FUNC void func_80800B08_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B10: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800B14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800B18: jal         0x808001A8
    // 0x80800B1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80800B1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800B20: jal         0x8008CABC
    // 0x80800B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800B28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B2C: jal         0x8008AF24
    // 0x80800B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B38: jal         0x8008B1A0
    // 0x80800B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x80800B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x8008AED4
    // 0x80800B48: addiu       $a1, $zero, 0x355
    ctx->r5 = ADD32(0, 0X355);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800B48: addiu       $a1, $zero, 0x355
    ctx->r5 = ADD32(0, 0X355);
    after_4:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800B54: jal         0x8008B1D4
    // 0x80800B58: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80800B58: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_5:
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: jal         0x8008B1BC
    // 0x80800B64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800B64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80800B68: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800B6C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B70: jal         0x8008B24C
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x8008B134
    // 0x80800B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800B84: jal         0x8008B064
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B8C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800B90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B9C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800BA0: jal         0x8009FFD8
    // 0x80800BA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800BA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800BA8: jal         0x808000BC
    // 0x80800BAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_11;
    // 0x80800BAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800BB0: jal         0x8009EF04
    // 0x80800BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_12;
    // 0x80800BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800BB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800BBC: nop

    // 0x80800BC0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800BC4: nop

    // 0x80800BC8: bc1t        L_80800BE4
    if (c1cs) {
        // 0x80800BCC: nop
    
            goto L_80800BE4;
    }
    // 0x80800BCC: nop

    // 0x80800BD0: jal         0x8009EEB8
    // 0x80800BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_13;
    // 0x80800BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800BD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BDC: jal         0x8009C914
    // 0x80800BE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_14;
    // 0x80800BE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
L_80800BE4:
    // 0x80800BE4: jal         0x8009C990
    // 0x80800BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_15;
    // 0x80800BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800BEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BF0: jal         0x8009B9C0
    // 0x80800BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_16;
    // 0x80800BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800BF8: jal         0x80800000
    // 0x80800BFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bswasher(rdram, ctx);
        goto after_17;
    // 0x80800BFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800C00: jal         0x8009C990
    // 0x80800C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_18;
    // 0x80800C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800C08: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800C0C: jal         0x8009BB00
    // 0x80800C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80800C14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C1C: jal         0x8009BA68
    // 0x80800C20: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x80800C20: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800C24: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80800C28: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80800C2C: jal         0x8009BA58
    // 0x80800C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80800C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C38: jal         0x8009BCB4
    // 0x80800C3C: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_22;
    // 0x80800C3C: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    after_22:
    // 0x80800C40: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80800C44: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x80800C48: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800C4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800C50: jal         0x8009D7A4
    // 0x80800C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_23;
    // 0x80800C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800C58: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800C5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C60: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800C64: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800C6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800224_subaddieitem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800234: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x80800238: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080023C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800240: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80800244: beql        $t6, $zero, L_80800260
    if (ctx->r14 == 0) {
        // 0x80800248: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_80800260;
    }
    goto skip_0;
    // 0x80800248: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    skip_0:
    // 0x8080024C: jal         0x800FC660
    // 0x80800250: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80800250: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800254: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800258: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8080025C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
L_80800260:
    // 0x80800260: beq         $t7, $zero, L_80800278
    if (ctx->r15 == 0) {
        // 0x80800264: nop
    
            goto L_80800278;
    }
    // 0x80800264: nop

    // 0x80800268: beq         $a2, $zero, L_80800278
    if (ctx->r6 == 0) {
        // 0x8080026C: nop
    
            goto L_80800278;
    }
    // 0x8080026C: nop

    // 0x80800270: jal         0x800FFAB0
    // 0x80800274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80800278:
    // 0x80800278: jal         0x8008A020
    // 0x8080027C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080027C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x80800280: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80800284: beql        $t8, $zero, L_808002A8
    if (ctx->r24 == 0) {
        // 0x80800288: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002A8;
    }
    goto skip_1;
    // 0x80800288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x8080028C: jal         0x800D1B34
    // 0x80800290: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800D1B34(rdram, ctx);
        goto after_3;
    // 0x80800290: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_3:
    // 0x80800294: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x80800298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080029C: jal         0x800D175C
    // 0x808002A0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_800D175C(rdram, ctx);
        goto after_4;
    // 0x808002A0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_4:
    // 0x808002A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808002A8:
    // 0x808002A8: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x808002AC: jal         0x8010108C
    // 0x808002B0: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x808002B0: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    after_5:
    // 0x808002B4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808002B8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void func_80800058_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800064: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080006C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800070: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800074: beq         $t6, $at, L_8080008C
    if (ctx->r14 == ctx->r1) {
        // 0x80800078: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080008C;
    }
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: beql        $t6, $at, L_8080018C
    if (ctx->r14 == ctx->r1) {
        // 0x80800080: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800084: b           L_8080018C
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080008C:
    // 0x8080008C: jal         0x800DA298
    // 0x80800090: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800090: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x80800094: bne         $v0, $zero, L_80800118
    if (ctx->r2 != 0) {
        // 0x80800098: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800118;
    }
    // 0x80800098: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080009C: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    // 0x808000A0: jal         0x8010CAC0
    // 0x808000A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_1;
    // 0x808000A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000A8: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x808000AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800188;
    }
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x808000B4: jal         0x8010CD88
    // 0x808000B8: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8010CD88(rdram, ctx);
        goto after_2;
    // 0x808000B8: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_2:
    // 0x808000BC: beql        $v0, $zero, L_8080018C
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080018C;
    }
    goto skip_1;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000C4: jal         0x800F54E4
    // 0x808000C8: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808000C8: nop

    after_3:
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808000D4: jal         0x800F4B8C
    // 0x808000D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F4B8C(rdram, ctx);
        goto after_4;
    // 0x808000D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808000DC: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x808000E0: addiu       $a1, $zero, 0x16C2
        ctx->r5 = ADD32(0, 0X16C2);
            goto L_80800188;
    }
    // 0x808000E0: addiu       $a1, $zero, 0x16C2
    ctx->r5 = ADD32(0, 0X16C2);
    // 0x808000E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000E8: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x808000EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000F0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808000F4: jal         0x8008A208
    // 0x808000F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808000F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80101FDC
    // 0x80800104: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800104: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800108: jal         0x800DA544
    // 0x8080010C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x8080010C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_7:
    // 0x80800110: b           L_8080018C
    // 0x80800114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x80800114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800118:
    // 0x80800118: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8080011C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800120: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    // 0x80800124: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80800128: beq         $t8, $zero, L_80800138
    if (ctx->r24 == 0) {
        // 0x8080012C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800138;
    }
    // 0x8080012C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800130: b           L_80800138
    // 0x80800134: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80800138;
    // 0x80800134: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80800138:
    // 0x80800138: beq         $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x8080013C: nop
    
            goto L_80800148;
    }
    // 0x8080013C: nop

    // 0x80800140: b           L_80800148
    // 0x80800144: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
        goto L_80800148;
    // 0x80800144: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
L_80800148:
    // 0x80800148: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080014C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80800150: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800154: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800158: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8080015C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800160: jal         0x8008A1E0
    // 0x80800164: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800164: nop

    after_8:
    // 0x80800168: beql        $v0, $zero, L_8080018C
    if (ctx->r2 == 0) {
        // 0x8080016C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080018C;
    }
    goto skip_2;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800170: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x8080017C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800180: jal         0x80800274
    // 0x80800184: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    func_80800274_chsignpost(rdram, ctx);
        goto after_9;
    // 0x80800184: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    after_9:
L_80800188:
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080018C:
    // 0x8080018C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void capod_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800328: jal         0x8008FFE8
    // 0x8080032C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x8080032C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800330: jal         0x80110024
    // 0x80800334: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800334: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800338: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x8080033C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800348;
    }
    // 0x8080033C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800340: jal         0x80089588
    // 0x80800344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_25(rdram, ctx);
        goto after_2;
    // 0x80800344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80800348:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void func_8011114C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011114C: jr          $ra
    // 0x80111150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80111150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_808011D0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011D8: jal         0x808004CC
    // 0x808011DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808011DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011E0: jal         0x800839C8
    // 0x808011E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808011E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011F0: jr          $ra
    // 0x808011F4: nop

    return;
    // 0x808011F4: nop

;}
RECOMP_FUNC void func_808002E0_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x808002EC: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808002F0: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x808002F4: jal         0x8010A570
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800304: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80800308: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080030C: jal         0x80101FDC
    // 0x80800310: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800310: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    after_1:
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B88: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B88);
    return;
    // 0x80089B8C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void subaddiemulti_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080013C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800140: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800144: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800148: addiu       $s5, $sp, 0x30
    ctx->r21 = ADD32(ctx->r29, 0X30);
    // 0x8080014C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800154: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800158: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080015C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800160: jal         0x800EFD24
    // 0x80800164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800164: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80800168: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080016C: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80800170: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
L_80800174:
    // 0x80800174: jal         0x800F6438
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080017C: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x80800180: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001E4;
    }
    // 0x80800180: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800184: jal         0x800882E8
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080018C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800190: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800194: jal         0x800EE88C
    // 0x80800198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x80800198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8080019C: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x808001A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: srl         $t7, $t6, 23
    ctx->r15 = S32(U32(ctx->r14) >> 23);
    // 0x808001AC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808001B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808001B4: bgez        $t7, L_808001C8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808001B8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001C8;
    }
    // 0x808001B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001C0: nop

    // 0x808001C4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808001C8:
    // 0x808001C8: jal         0x800F8294
    // 0x808001CC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800F8294(rdram, ctx);
        goto after_4;
    // 0x808001CC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x800F832C
    // 0x808001D8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F832C(rdram, ctx);
        goto after_5;
    // 0x808001D8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x808001DC: jal         0x800878F8
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_808001E4:
    // 0x808001E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001E8: bne         $s0, $s4, L_80800174
    if (ctx->r16 != ctx->r20) {
        // 0x808001EC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800174;
    }
    // 0x808001EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808001F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800204: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800210: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800E88_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E88: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800E8C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800E90: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800E94: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800E98: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800E9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800EA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800EA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800EA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800EAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EB0: jal         0x80100094
    // 0x80800EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800EB8: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80800EBC: jal         0x801039E4
    // 0x80800EC0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800EC0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_1:
    // 0x80800EC4: jal         0x800B27E0
    // 0x80800EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_2;
    // 0x80800EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800ECC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800ED0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800ED4: jal         0x80100094
    // 0x80800ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800EDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800EE0: jal         0x801015D0
    // 0x80800EE4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_801015D0(rdram, ctx);
        goto after_4;
    // 0x80800EE4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x80800EE8: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80800EEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800EF0: jal         0x800ADD80
    // 0x80800EF4: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800ADD80(rdram, ctx);
        goto after_5;
    // 0x80800EF4: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_5:
    // 0x80800EF8: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80800EFC: jal         0x800AE080
    // 0x80800F00: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_6;
    // 0x80800F00: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_6:
    // 0x80800F04: lw          $t8, 0x6C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X6C);
    // 0x80800F08: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800F0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800F10: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800F14: beq         $t9, $zero, L_80800FB8
    if (ctx->r25 == 0) {
        // 0x80800F18: addiu       $s3, $sp, 0x4C
        ctx->r19 = ADD32(ctx->r29, 0X4C);
            goto L_80800FB8;
    }
    // 0x80800F18: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x80800F1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800F20:
    // 0x80800F20: jal         0x80087A28
    // 0x80800F24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800F24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800F28: jal         0x80019CD4
    // 0x80800F2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    func_80019CD4(rdram, ctx);
        goto after_8;
    // 0x80800F2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_8:
    // 0x80800F30: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800F34: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800F38: jal         0x80019C84
    // 0x80800F3C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    mlMtxTranslate(rdram, ctx);
        goto after_9;
    // 0x80800F3C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    after_9:
    // 0x80800F40: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800F44: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800F48: jal         0x80019C84
    // 0x80800F4C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    mlMtxTranslate(rdram, ctx);
        goto after_10;
    // 0x80800F4C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_10:
    // 0x80800F50: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800F54: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800F58: jal         0x80019110
    // 0x80800F5C: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    mlMtxRotatePYR(rdram, ctx);
        goto after_11;
    // 0x80800F5C: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    after_11:
    // 0x80800F60: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800F64: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800F68: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800F6C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800F70: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80800F74: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800F78: jal         0x80019C84
    // 0x80800F7C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_12;
    // 0x80800F7C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_12:
    // 0x80800F80: jal         0x80018AD0
    // 0x80800F84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mlMtxGet(rdram, ctx);
        goto after_13;
    // 0x80800F84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80800F88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800F8C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800F90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800F94: jal         0x800ADEC4
    // 0x80800F98: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800ADEC4(rdram, ctx);
        goto after_14;
    // 0x80800F98: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_14:
    // 0x80800F9C: lw          $t0, 0x6C($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X6C);
    // 0x80800FA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800FA4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80800FA8: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800FAC: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x80800FB0: bnel        $at, $zero, L_80800F20
    if (ctx->r1 != 0) {
        // 0x80800FB4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800F20;
    }
    goto skip_0;
    // 0x80800FB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_80800FB8:
    // 0x80800FB8: jal         0x800DF72C
    // 0x80800FBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800DF72C(rdram, ctx);
        goto after_15;
    // 0x80800FBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_15:
    // 0x80800FC0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80800FC4: jal         0x800DF758
    // 0x80800FC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800DF758(rdram, ctx);
        goto after_16;
    // 0x80800FC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_16:
    // 0x80800FCC: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800FD0: lbu         $v0, 0xF5($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0XF5);
    // 0x80800FD4: beq         $v0, $zero, L_80800FE4
    if (ctx->r2 == 0) {
        // 0x80800FD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800FE4;
    }
    // 0x80800FD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FDC: jal         0x800DF6BC
    // 0x80800FE0: lbu         $a1, 0x9B($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X9B);
    func_800DF6BC(rdram, ctx);
        goto after_17;
    // 0x80800FE0: lbu         $a1, 0x9B($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X9B);
    after_17:
L_80800FE4:
    // 0x80800FE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800FF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800FFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801000: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801004: jr          $ra
    // 0x80801008: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80801008: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800FE4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE4E4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FE4E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FE4EC: lbu         $t6, 0x59D7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X59D7);
    // 0x800FE4F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800FE4F4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800FE4F8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800FE4FC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800FE500: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800FE504: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800FE508: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800FE50C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800FE510: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800FE514: beq         $t6, $zero, L_800FE524
    if (ctx->r14 == 0) {
        // 0x800FE518: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_800FE524;
    }
    // 0x800FE518: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800FE51C: b           L_800FE5E4
    // 0x800FE520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE5E4;
    // 0x800FE520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE524:
    // 0x800FE524: jal         0x800C77DC
    // 0x800FE528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_0;
    // 0x800FE528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800FE52C: jal         0x800FDC28
    // 0x800FE530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x800FE530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800FE534: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE538: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    // 0x800FE53C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE540: beq         $a0, $at, L_800FE550
    if (ctx->r4 == ctx->r1) {
        // 0x800FE544: nop
    
            goto L_800FE550;
    }
    // 0x800FE544: nop

    // 0x800FE548: jal         0x800FC74C
    // 0x800FE54C: nop

    func_800FC74C(rdram, ctx);
        goto after_2;
    // 0x800FE54C: nop

    after_2:
L_800FE550:
    // 0x800FE550: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800FE554: addiu       $s5, $s5, 0x5A40
    ctx->r21 = ADD32(ctx->r21, 0X5A40);
    // 0x800FE558: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800FE55C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FE560: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800FE564: blez        $t7, L_800FE5D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800FE568: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_800FE5D4;
    }
    // 0x800FE568: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FE56C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800FE570: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FE574: addiu       $s6, $s6, 0x5A3C
    ctx->r22 = ADD32(ctx->r22, 0X5A3C);
    // 0x800FE578: addiu       $s2, $s2, 0x5A20
    ctx->r18 = ADD32(ctx->r18, 0X5A20);
    // 0x800FE57C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_800FE580:
    // 0x800FE580: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800FE584: addu        $s0, $s6, $s1
    ctx->r16 = ADD32(ctx->r22, ctx->r17);
    // 0x800FE588: beql        $a0, $zero, L_800FE5C8
    if (ctx->r4 == 0) {
        // 0x800FE58C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FE5C8;
    }
    goto skip_0;
    // 0x800FE58C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800FE590: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x800FE594: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FE598: addiu       $t9, $t9, 0x5A30
    ctx->r25 = ADD32(ctx->r25, 0X5A30);
    // 0x800FE59C: beql        $t8, $zero, L_800FE5C8
    if (ctx->r24 == 0) {
        // 0x800FE5A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FE5C8;
    }
    goto skip_1;
    // 0x800FE5A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800FE5A4: jal         0x800FC74C
    // 0x800FE5A8: addu        $s4, $s3, $t9
    ctx->r20 = ADD32(ctx->r19, ctx->r25);
    func_800FC74C(rdram, ctx);
        goto after_3;
    // 0x800FE5A8: addu        $s4, $s3, $t9
    ctx->r20 = ADD32(ctx->r19, ctx->r25);
    after_3:
    // 0x800FE5AC: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x800FE5B0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800FE5B4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800FE5B8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800FE5BC: swc1        $f20, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f20.u32l;
    // 0x800FE5C0: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x800FE5C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FE5C8:
    // 0x800FE5C8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800FE5CC: bne         $s1, $s7, L_800FE580
    if (ctx->r17 != ctx->r23) {
        // 0x800FE5D0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800FE580;
    }
    // 0x800FE5D0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800FE5D4:
    // 0x800FE5D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800FE5D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE5DC: sb          $t2, 0x5A01($at)
    MEM_B(0X5A01, ctx->r1) = ctx->r10;
    // 0x800FE5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FE5E4:
    // 0x800FE5E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE5E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800FE5EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE5F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800FE5F4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800FE5F8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800FE5FC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800FE600: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800FE604: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x800FE608: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800FE60C: jr          $ra
    // 0x800FE610: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800FE610: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _suquiz_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A810: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A810);
    return;
    // 0x8008A814: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void sufreezy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: jal         0x80106790
    // 0x80800194: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800194: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800198: jal         0x8010A570
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001A0: jal         0x8008A340
    // 0x808001A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808001A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808001A8: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001AC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808001BC;
    }
    // 0x808001AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808001B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001B4: jal         0x8010114C
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_808001BC:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_808001A0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808001B4: jal         0x80100094
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001BC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808001C0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001C8: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x808001CC: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808001D0: beq         $t7, $at, L_808003F8
    if (ctx->r15 == ctx->r1) {
        // 0x808001D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003F8;
    }
    // 0x808001D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001D8: beq         $t7, $at, L_808001F8
    if (ctx->r15 == ctx->r1) {
        // 0x808001DC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808001F8;
    }
    // 0x808001DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001E0: beq         $t7, $at, L_80800350
    if (ctx->r15 == ctx->r1) {
        // 0x808001E4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800350;
    }
    // 0x808001E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001E8: beq         $t7, $at, L_808003B0
    if (ctx->r15 == ctx->r1) {
        // 0x808001EC: addiu       $a0, $zero, 0x3B
        ctx->r4 = ADD32(0, 0X3B);
            goto L_808003B0;
    }
    // 0x808001EC: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x808001F0: b           L_808003FC
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003FC;
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001F8:
    // 0x808001F8: jal         0x800F54E4
    // 0x808001FC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001FC: nop

    after_1:
    // 0x80800200: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800204: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800208: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080020C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800210: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80800214: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80800218: jal         0x800D2498
    // 0x8080021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x8080021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800220: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80800224: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800228: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080022C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800230: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80800234: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800238: addu        $s1, $t1, $t3
    ctx->r17 = ADD32(ctx->r9, ctx->r11);
L_8080023C:
    // 0x8080023C: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x80800240: lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X40);
    // 0x80800244: jal         0x800D2498
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_3;
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8080024C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800254: bne         $s0, $at, L_8080023C
    if (ctx->r16 != ctx->r1) {
        // 0x80800258: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8080023C;
    }
    // 0x80800258: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080025C: jal         0x80800D00
    // 0x80800260: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800D00_chfactorytwinklies(rdram, ctx);
        goto after_4;
    // 0x80800260: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800264: jal         0x800CEAD0
    // 0x80800268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_5;
    // 0x80800268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8080026C: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x80800270: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808002CC;
    }
    // 0x80800270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800274: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800278: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080027C: jal         0x80800B80
    // 0x80800280: addiu       $a1, $a1, 0xA8
    ctx->r5 = ADD32(ctx->r5, 0XA8);
    func_80800B80_chfactorytwinklies(rdram, ctx);
        goto after_6;
    // 0x80800280: addiu       $a1, $a1, 0xA8
    ctx->r5 = ADD32(ctx->r5, 0XA8);
    after_6:
    // 0x80800284: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80800288: jal         0x800F54E4
    // 0x8080028C: sw          $v0, 0xA4($t4)
    MEM_W(0XA4, ctx->r12) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x8080028C: sw          $v0, 0xA4($t4)
    MEM_W(0XA4, ctx->r12) = ctx->r2;
    after_7:
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800298: jal         0x800F7ECC
    // 0x8080029C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7ECC(rdram, ctx);
        goto after_8;
    // 0x8080029C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x808002A0: jal         0x800F54E4
    // 0x808002A4: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808002A4: nop

    after_9:
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002B0: jal         0x800F8300
    // 0x808002B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_10;
    // 0x808002B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808002B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808002BC: jal         0x80101FDC
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x808002C4: b           L_808003FC
    // 0x808002C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003FC;
    // 0x808002C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002CC:
    // 0x808002CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X20D0) << 16);
    // 0x808002D4: jal         0x800DC178
    // 0x808002D8: lwc1        $f14, 0x20D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X20D0));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x808002D8: lwc1        $f14, 0x20D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X20D0));
    after_12:
    // 0x808002DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808002E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002E4: jal         0x800D9154
    // 0x808002E8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9154(rdram, ctx);
        goto after_13;
    // 0x808002E8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_13:
    // 0x808002EC: beql        $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808002F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003FC;
    }
    goto skip_0;
    // 0x808002F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002F4: jal         0x800DC0C0
    // 0x808002F8: nop

    func_800DC0C0(rdram, ctx);
        goto after_14;
    // 0x808002F8: nop

    after_14:
    // 0x808002FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X20D4) << 16);
    // 0x80800300: lwc1        $f4, 0x20D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X20D4));
    // 0x80800304: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800308: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080030C: nop

    // 0x80800310: bc1fl       L_80800324
    if (!c1cs) {
        // 0x80800314: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800324;
    }
    goto skip_1;
    // 0x80800314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80800318: b           L_80800340
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800340;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800324:
    // 0x80800324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800328: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080032C: nop

    // 0x80800330: bc1f        L_80800340
    if (!c1cs) {
        // 0x80800334: nop
    
            goto L_80800340;
    }
    // 0x80800334: nop

    // 0x80800338: b           L_80800340
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800340;
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: jal         0x80108B04
    // 0x80800344: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80108B04(rdram, ctx);
        goto after_15;
    // 0x80800344: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_15:
    // 0x80800348: b           L_808003FC
    // 0x8080034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003FC;
    // 0x8080034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800350:
    // 0x80800350: jal         0x8008A2E8
    // 0x80800354: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x80800354: nop

    after_16:
    // 0x80800358: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x8080035C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808003F8;
    }
    // 0x8080035C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800360: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800368: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080036C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800370: jal         0x8008A2C8
    // 0x80800374: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x80800374: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_17:
    // 0x80800378: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080037C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800380: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x80800384: lw          $a1, 0xA4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA4);
    // 0x80800388: lw          $a2, 0xA8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XA8);
    // 0x8080038C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800394: jal         0x8008A208
    // 0x80800398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80800398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8080039C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808003A0: jal         0x80101FDC
    // 0x808003A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808003A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x808003A8: b           L_808003FC
    // 0x808003AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003FC;
    // 0x808003AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003B0:
    // 0x808003B0: jal         0x800D0B68
    // 0x808003B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_20;
    // 0x808003B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808003B8: beql        $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808003BC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003FC;
    }
    goto skip_2;
    // 0x808003BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808003C0: jal         0x800F54E4
    // 0x808003C4: nop

    func_800F54E4(rdram, ctx);
        goto after_21;
    // 0x808003C4: nop

    after_21:
    // 0x808003C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003D0: jal         0x800F8300
    // 0x808003D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_22;
    // 0x808003D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x808003D8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808003DC: addiu       $t7, $zero, 0xCEB
    ctx->r15 = ADD32(0, 0XCEB);
    // 0x808003E0: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x808003E4: sw          $t7, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r15;
    // 0x808003E8: sw          $t8, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r24;
    // 0x808003EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808003F0: jal         0x80101FDC
    // 0x808003F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_23;
    // 0x808003F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_23:
L_808003F8:
    // 0x808003F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003FC:
    // 0x808003FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: jr          $ra
    // 0x80800408: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800408: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084018: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084018);
    return;
    // 0x8008401C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bainvisible_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854E8: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854E8);
    return;
    // 0x800854EC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FF8: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x80089FF8);
    return;
    // 0x80089FFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _baswim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852B0: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852B0);
    return;
    // 0x800852B4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808000C4_suquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: jal         0x80015E80
    // 0x808000D0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80015E80(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808000D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000E0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808000E4: jr          $ra
    // 0x808000E8: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x808000E8: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_808039D0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808039D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808039D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808039D8: jal         0x80088330
    // 0x808039DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808039DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x808039E0: jal         0x80088350
    // 0x808039E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808039E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808039E8: jal         0x80088348
    // 0x808039EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808039EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x808039F0: jal         0x80088358
    // 0x808039F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808039F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x808039F8: jal         0x80803940
    // 0x808039FC: nop

    func_80803940_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808039FC: nop

    after_4:
    // 0x80803A00: jal         0x80803988
    // 0x80803A04: nop

    func_80803988_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80803A04: nop

    after_5:
    // 0x80803A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803A10: jr          $ra
    // 0x80803A14: nop

    return;
    // 0x80803A14: nop

;}
RECOMP_FUNC void func_8001D9CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D9CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D9D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D9D8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001D9DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D9E0: jal         0x8001D98C
    // 0x8001D9E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001D98C(rdram, ctx);
        goto after_0;
    // 0x8001D9E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001D9E8: jal         0x8001D9AC
    // 0x8001D9EC: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    func_8001D9AC(rdram, ctx);
        goto after_1;
    // 0x8001D9EC: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    after_1:
    // 0x8001D9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D9F8: jr          $ra
    // 0x8001D9FC: nop

    return;
    // 0x8001D9FC: nop

;}
RECOMP_FUNC void func_80116024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80116028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011602C: jal         0x80116218
    // 0x80116030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80116218(rdram, ctx);
        goto after_0;
    // 0x80116030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80116034: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80116038: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8011603C: sb          $zero, 0x2C($t7)
    MEM_B(0X2C, ctx->r15) = 0;
    // 0x80116040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80116044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80116048: jr          $ra
    // 0x8011604C: nop

    return;
    // 0x8011604C: nop

;}
