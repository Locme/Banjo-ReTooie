#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bsbansack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E30) << 16);
    // 0x80800A08: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E30));
    return;
    // 0x80800A10: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E30));
;}
RECOMP_FUNC void sccustom_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800778: jal         0x8008A618
    // 0x8080077C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080077C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800780: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80800784: bne         $v0, $at, L_808007F8
    if (ctx->r2 != ctx->r1) {
        // 0x80800788: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3342, 0X920) << 16);
            goto L_808007F8;
    }
    // 0x80800788: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X920) << 16);
    // 0x8080078C: jal         0x800E7188
    // 0x80800790: lw          $a0, 0x920($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3342, 0X920));
    func_800E7188(rdram, ctx);
        goto after_1;
    // 0x80800790: lw          $a0, 0x920($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3342, 0X920));
    after_1:
    // 0x80800794: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800798: jal         0x8008A610
    // 0x8080079C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x8080079C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x808007A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x808007A8: beql        $at, $zero, L_808007B8
    if (ctx->r1 == 0) {
        // 0x808007AC: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_808007B8;
    }
    goto skip_0;
    // 0x808007AC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    skip_0:
    // 0x808007B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808007B4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_808007B8:
    // 0x808007B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x808007C0: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x808007C4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808007C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808007CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808007DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808007E0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808007E4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x808007E8: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808007EC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x808007F0: b           L_80800810
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800810;
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007F8:
    // 0x808007F8: jal         0x808004C8
    // 0x808007FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808004C8_sccustom(rdram, ctx);
        goto after_3;
    // 0x808007FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800804: jal         0x808006C4
    // 0x80800808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808006C4_sccustom(rdram, ctx);
        goto after_4;
    // 0x80800808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080080C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800810:
    // 0x80800810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800814: jr          $ra
    // 0x80800818: nop

    return;
    // 0x80800818: nop

;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874E8: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874E8);
    return;
    // 0x800874EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C9B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9B84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9B88: lw          $a0, -0x54A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54A0);
    // 0x800C9B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9B94: beql        $a0, $zero, L_800C9BA8
    if (ctx->r4 == 0) {
        // 0x800C9B98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9BA8;
    }
    goto skip_0;
    // 0x800C9B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9B9C: jal         0x800B28B8
    // 0x800C9BA0: nop

    vector_clear(rdram, ctx);
        goto after_0;
    // 0x800C9BA0: nop

    after_0:
    // 0x800C9BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9BA8:
    // 0x800C9BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9BAC: jr          $ra
    // 0x800C9BB0: nop

    return;
    // 0x800C9BB0: nop

;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D70: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D70);
    return;
    // 0x80089D74: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsmum_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083800: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083800);
    return;
    // 0x80083804: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bskazcrouch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083308: syscall     54
    recomp_syscall_handler(rdram, ctx, 0x80083308);
    return;
    // 0x8008330C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A70D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A70D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A70D8: jal         0x80106790
    // 0x800A70DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800A70DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A70E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A70E4: lhu         $t0, 0x76($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X76);
    // 0x800A70E8: sll         $t9, $t7, 7
    ctx->r25 = S32(ctx->r15 << 7);
    // 0x800A70EC: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x800A70F0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800A70F4: sh          $t2, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r10;
    // 0x800A70F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A70FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7100: jr          $ra
    // 0x800A7104: nop

    return;
    // 0x800A7104: nop

;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808002F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002FC: beq         $a2, $zero, L_80800374
    if (ctx->r6 == 0) {
        // 0x80800300: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80800374;
    }
    // 0x80800300: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800304: lbu         $t6, 0x5F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5F);
    // 0x80800308: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080030C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800310: bne         $t6, $zero, L_80800348
    if (ctx->r14 != 0) {
        // 0x80800314: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_80800348;
    }
    // 0x80800314: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800318: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3198, 0X3CC) << 16);
    // 0x8080031C: addiu       $a2, $a2, 0x3CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3198, 0X3CC));
    // 0x80800320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800324: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800328: jal         0x800C4350
    // 0x8080032C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x8080032C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800330: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800334: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3198, 0X3B0) << 16);
    // 0x80800338: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
    // 0x8080033C: lwc1        $f4, 0x3B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3198, 0X3B0));
    // 0x80800340: b           L_80800390
    // 0x80800344: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
        goto L_80800390;
    // 0x80800344: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_80800348:
    // 0x80800348: jal         0x800D9154
    // 0x8080034C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800D9154(rdram, ctx);
        goto after_1;
    // 0x8080034C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800350: beq         $v0, $zero, L_80800390
    if (ctx->r2 == 0) {
        // 0x80800354: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800390;
    }
    // 0x80800354: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    // 0x8080035C: beql        $a0, $zero, L_80800394
    if (ctx->r4 == 0) {
        // 0x80800360: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800364: jal         0x800C3BDC
    // 0x80800368: nop

    func_800C3BDC(rdram, ctx);
        goto after_2;
    // 0x80800368: nop

    after_2:
    // 0x8080036C: b           L_80800394
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800394;
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800374:
    // 0x80800374: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    // 0x80800378: beql        $a0, $zero, L_80800394
    if (ctx->r4 == 0) {
        // 0x8080037C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800394;
    }
    goto skip_1;
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800380: jal         0x800C2FDC
    // 0x80800384: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C2FDC(rdram, ctx);
        goto after_3;
    // 0x80800384: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800388: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: sb          $zero, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = 0;
L_80800390:
    // 0x80800390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800394:
    // 0x80800394: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080039C: jr          $ra
    // 0x808003A0: nop

    return;
    // 0x808003A0: nop

    // 0x808003A4: nop

    // 0x808003A8: nop

    // 0x808003AC: nop

;}
RECOMP_FUNC void _chjiggytemple_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B68: syscall     200
    recomp_syscall_handler(rdram, ctx, 0x80085B68);
    return;
    // 0x80085B6C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void baeggfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E3900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3908: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E390C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E3910: jal         0x800CA3A4
    // 0x800E3914: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA3A4(rdram, ctx);
        goto after_0;
    // 0x800E3914: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E391C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3920: jr          $ra
    // 0x800E3924: nop

    return;
    // 0x800E3924: nop

;}
RECOMP_FUNC void func_80801B90_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801B9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801BA0: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80801BA4: jal         0x800EE7F8
    // 0x80801BA8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801BA8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801BAC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80801BB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801BB4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801BB8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BBC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80801BC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801BC4: beq         $v0, $at, L_80801BD8
    if (ctx->r2 == ctx->r1) {
        // 0x80801BC8: swc1        $f8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
            goto L_80801BD8;
    }
    // 0x80801BC8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80801BCC: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80801BD0: bnel        $v0, $at, L_80801BE4
    if (ctx->r2 != ctx->r1) {
        // 0x80801BD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801BE4;
    }
    goto skip_0;
    // 0x80801BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80801BD8:
    // 0x80801BD8: jal         0x80085738
    // 0x80801BDC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    _capod_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80801BDC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80801BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BE4:
    // 0x80801BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801BE8: jr          $ra
    // 0x80801BEC: nop

    return;
    // 0x80801BEC: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C80: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C80);
    return;
    // 0x80089C84: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808004D0_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808004DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004E0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808004E4: beq         $t6, $at, L_808004FC
    if (ctx->r14 == ctx->r1) {
        // 0x808004E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808004FC;
    }
    // 0x808004E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004EC: beq         $t6, $at, L_808004FC
    if (ctx->r14 == ctx->r1) {
        // 0x808004F0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808004FC;
    }
    // 0x808004F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808004F4: bnel        $t6, $at, L_80800534
    if (ctx->r14 != ctx->r1) {
        // 0x808004F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800534;
    }
    goto skip_0;
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808004FC:
    // 0x808004FC: jal         0x8008A4A8
    // 0x80800500: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800500: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800504: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x80800508: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800514;
    }
    // 0x80800508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080050C: b           L_80800518
    // 0x80800510: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
        goto L_80800518;
    // 0x80800510: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
L_80800514:
    // 0x80800514: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_80800518:
    // 0x80800518: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8080051C: jal         0x8008A128
    // 0x80800520: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    _sucoaster_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800520: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800524: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800528: jal         0x8008A148
    // 0x8080052C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080052C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800534:
    // 0x80800534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_808001CC_fxegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808001D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2834, 0X5D8) << 16);
    // 0x808001D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001DC: addiu       $t6, $t6, 0x5D8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2834, 0X5D8));
    // 0x808001E0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x808001E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001E8: jal         0x800BABB8
    // 0x808001EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808001EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80802064_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080206C: jal         0x80800ECC
    // 0x80802070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802074: jal         0x800839C8
    // 0x80802078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80802078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080207C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802084: jr          $ra
    // 0x80802088: nop

    return;
    // 0x80802088: nop

;}
RECOMP_FUNC void func_80800A30_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800A3C: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x80800A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A44: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800A48: bgezl       $t9, L_80800AA0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800A4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AA0;
    }
    goto skip_0;
    // 0x80800A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A50: jal         0x800DC128
    // 0x80800A54: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800A54: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x80800A58: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80800A5C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2332, 0X13A0) << 16);
    // 0x80800A60: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80800A64: lw          $a1, 0x13A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(2332, 0X13A0));
    // 0x80800A68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A6C: jal         0x8008A0D0
    // 0x80800A70: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800A70: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800A74: beq         $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A9C;
    }
    // 0x80800A78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800A80: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2332, 0X1330) << 16);
    // 0x80800A84: addiu       $t2, $t2, 0x1330
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2332, 0X1330));
    // 0x80800A88: lw          $a3, 0x38($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X38);
    // 0x80800A8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800A90: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800A94: jal         0x800BABB8
    // 0x80800A98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800A98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800A9C:
    // 0x80800A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AA0:
    // 0x80800AA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800AA4: jr          $ra
    // 0x80800AA8: nop

    return;
    // 0x80800AA8: nop

;}
RECOMP_FUNC void func_808002A0_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A8: jal         0x80101870
    // 0x808002AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x808002AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002B4: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x808002B8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808002BC: bgezl       $t8, L_808002E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808002C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E4;
    }
    goto skip_0;
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002C4: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x808002C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002CC: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808002D0: bnel        $t0, $at, L_808002E4
    if (ctx->r8 != ctx->r1) {
        // 0x808002D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E4;
    }
    goto skip_1;
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002D8: jal         0x80103110
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002E4:
    // 0x808002E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_800DAD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAD10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DAD14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DAD18: lwc1        $f8, -0x3860($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3860);
    // 0x800DAD1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DAD20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DAD24: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DAD28: addiu       $v0, $v0, -0x3828
    ctx->r2 = ADD32(ctx->r2, -0X3828);
    // 0x800DAD2C: addiu       $a0, $a0, -0x3858
    ctx->r4 = ADD32(ctx->r4, -0X3858);
    // 0x800DAD30: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DAD34: lwc1        $f6, -0x385C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X385C);
    // 0x800DAD38: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800DAD3C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800DAD40: nop

    // 0x800DAD44: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800DAD48: nop

    // 0x800DAD4C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DAD50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DAD54: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800DAD58: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800DAD5C: nop

    // 0x800DAD60: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
L_800DAD64:
    // 0x800DAD64: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800DAD68: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800DAD6C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DAD70: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DAD74: lwc1        $f18, -0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, -0XC);
    // 0x800DAD78: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800DAD7C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800DAD80: nop

    // 0x800DAD84: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800DAD88: nop

    // 0x800DAD8C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DAD90: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DAD94: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x800DAD98: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800DAD9C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800DADA0: nop

    // 0x800DADA4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800DADA8: nop

    // 0x800DADAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DADB0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DADB4: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x800DADB8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800DADBC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800DADC0: nop

    // 0x800DADC4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800DADC8: nop

    // 0x800DADCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DADD0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800DADD4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800DADD8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800DADDC: bnel        $a0, $v0, L_800DAD64
    if (ctx->r4 != ctx->r2) {
        // 0x800DADE0: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_800DAD64;
    }
    goto skip_0;
    // 0x800DADE0: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_0:
    // 0x800DADE4: jr          $ra
    // 0x800DADE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800DADE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _suspline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DC8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DC8);
    return;
    // 0x80089DCC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _subaddiezone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7B0: syscall     852
    recomp_syscall_handler(rdram, ctx, 0x8008A7B0);
    return;
    // 0x8008A7B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800398_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080039C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A4: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808003A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808003B4: bnel        $t7, $at, L_808004D8
    if (ctx->r15 != ctx->r1) {
        // 0x808003B8: lwc1        $f10, 0x1C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_808004D8;
    }
    goto skip_0;
    // 0x808003B8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x808003BC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808003C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003C4: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808003C8: beq         $t8, $at, L_808003E0
    if (ctx->r24 == ctx->r1) {
        // 0x808003CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003E0;
    }
    // 0x808003CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003D0: beql        $t8, $at, L_80800428
    if (ctx->r24 == ctx->r1) {
        // 0x808003D4: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80800428;
    }
    goto skip_1;
    // 0x808003D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_1:
    // 0x808003D8: b           L_808004D8
    // 0x808003DC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_808004D8;
    // 0x808003DC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
L_808003E0:
    // 0x808003E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003E8: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808003EC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808003F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80800400: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800404: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800408: nop

    // 0x8080040C: bc1fl       L_808004D8
    if (!c1cs) {
        // 0x80800410: lwc1        $f10, 0x1C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_808004D8;
    }
    goto skip_2;
    // 0x80800410: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x80800414: jal         0x80101FDC
    // 0x80800418: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800418: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080041C: b           L_808004D8
    // 0x80800420: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_808004D8;
    // 0x80800420: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800424: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800428:
    // 0x80800428: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080042C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800430: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2004, 0X540) << 16);
    // 0x80800434: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2004, 0X540));
    // 0x80800438: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8080043C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800440: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: bc1f        L_80800490
    if (!c1cs) {
        // 0x8080044C: nop
    
            goto L_80800490;
    }
    // 0x8080044C: nop

    // 0x80800450: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2004, 0X518) << 16);
    // 0x80800458: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8080045C: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80800460: lwc1        $f4, 0x518($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2004, 0X518));
    // 0x80800464: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800468: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080046C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800470: nop

    // 0x80800474: bc1f        L_80800480
    if (!c1cs) {
        // 0x80800478: swc1        $f6, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
            goto L_80800480;
    }
    // 0x80800478: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8080047C: swc1        $f12, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f12.u32l;
L_80800480:
    // 0x80800480: jal         0x80089D50
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800488: b           L_808004D8
    // 0x8080048C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_808004D8;
    // 0x8080048C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
L_80800490:
    // 0x80800490: jal         0x80101FDC
    // 0x80800494: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800494: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800498: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2004, 0X534) << 16);
    // 0x8080049C: addiu       $a2, $a2, 0x534
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2004, 0X534));
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80089D18
    // 0x808004A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808004A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808004AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004B0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x808004B4: jal         0x800E15CC
    // 0x808004B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800E15CC(rdram, ctx);
        goto after_4;
    // 0x808004B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x808004BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2004, 0X51C) << 16);
    // 0x808004C0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808004C4: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, 0X70A8);
    // 0x808004C8: lwc1        $f12, 0x51C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2004, 0X51C));
    // 0x808004CC: jal         0x800C9DE4
    // 0x808004D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C9DE4(rdram, ctx);
        goto after_5;
    // 0x808004D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x808004D4: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
L_808004D8:
    // 0x808004D8: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void bssub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801208: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080120C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18B0) << 16);
    // 0x80801210: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801214: jr          $ra
    // 0x80801218: lw          $v0, 0x18B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18B0));
    return;
    // 0x80801218: lw          $v0, 0x18B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18B0));
;}
RECOMP_FUNC void func_80801660_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801668: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080166C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801670: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801674: jal         0x80100094
    // 0x80801678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080167C: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x80801680: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801684: lwc1        $f10, 0x134($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X134);
    // 0x80801688: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080168C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801690: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801694: lw          $a2, 0x130($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X130);
    // 0x80801698: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080169C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808016A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808016A4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808016A8: jal         0x800EEC30
    // 0x808016AC: nop

    func_800EEC30(rdram, ctx);
        goto after_1;
    // 0x808016AC: nop

    after_1:
    // 0x808016B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808016B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016B8: jr          $ra
    // 0x808016BC: nop

    return;
    // 0x808016BC: nop

;}
RECOMP_FUNC void func_800949BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800949BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800949C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800949C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800949C8: jal         0x8009E674
    // 0x800949CC: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800949CC: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_0:
    // 0x800949D0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800949D4: bne         $t6, $zero, L_80094A00
    if (ctx->r14 != 0) {
        // 0x800949D8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80094A00;
    }
    // 0x800949D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800949DC: jal         0x80084CA0
    // 0x800949E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bafpctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x800949E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800949E4: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800949E8: beq         $t7, $zero, L_80094A00
    if (ctx->r15 == 0) {
        // 0x800949EC: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80094A00;
    }
    // 0x800949EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800949F0: jal         0x80084B50
    // 0x800949F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _baeggfire_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x800949F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800949F8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800949FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80094A00:
    // 0x80094A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094A08: jr          $ra
    // 0x80094A0C: nop

    return;
    // 0x80094A0C: nop

;}
RECOMP_FUNC void chfactorygoblin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1152, 0X298) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1152, 0X298));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1152, 0X298));
;}
RECOMP_FUNC void func_80800128_chclimbbase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080012C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800138: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8080013C: jal         0x80800000
    // 0x80800140: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80800000_chclimbbase(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080014C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800150: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(680, 0X3B0) << 16);
    // 0x80800154: addiu       $v1, $v1, 0x3B0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(680, 0X3B0));
    // 0x80800158: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8080015C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(680, 0X3B0) << 16);
    // 0x80800160: bc1f        L_80800178
    if (!c1cs) {
        // 0x80800164: nop
    
            goto L_80800178;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x808000FC
    // 0x8080016C: nop

    func_808000FC_chclimbbase(rdram, ctx);
        goto after_1;
    // 0x8080016C: nop

    after_1:
    // 0x80800170: b           L_808001CC
    // 0x80800174: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_808001CC;
    // 0x80800174: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_80800178:
    // 0x80800178: lw          $t6, 0x3B0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(680, 0X3B0));
    // 0x8080017C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(680, 0X3B4) << 16);
    // 0x80800184: beql        $v0, $t6, L_808001C8
    if (ctx->r2 == ctx->r14) {
        // 0x80800188: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_808001C8;
    }
    goto skip_0;
    // 0x80800188: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8080018C: lwc1        $f6, 0x3B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(680, 0X3B4));
    // 0x80800190: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800194: nop

    // 0x80800198: bc1tl       L_808001C8
    if (c1cs) {
        // 0x8080019C: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_808001C8;
    }
    goto skip_1;
    // 0x8080019C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x808001A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_808001A4:
    // 0x808001A4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x808001A8: beql        $v0, $t7, L_808001C8
    if (ctx->r2 == ctx->r15) {
        // 0x808001AC: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_808001C8;
    }
    goto skip_2;
    // 0x808001AC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x808001B0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808001B4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x808001B8: nop

    // 0x808001BC: bc1fl       L_808001A4
    if (!c1cs) {
        // 0x808001C0: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_808001A4;
    }
    goto skip_3;
    // 0x808001C0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_3:
    // 0x808001C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_808001C8:
    // 0x808001C8: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
L_808001CC:
    // 0x808001CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001D0: jal         0x800EEAD4
    // 0x808001D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EEAD4(rdram, ctx);
        goto after_2;
    // 0x808001D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808001D8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001DC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x808001E0: nop

    // 0x808001E4: addiu       $t1, $t0, 0x1F4
    ctx->r9 = ADD32(ctx->r8, 0X1F4);
    // 0x808001E8: sh          $t1, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r9;
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80106A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106A64: lw          $a0, 0x6EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EF0);
    // 0x80106A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106A70: beql        $a0, $zero, L_80106A8C
    if (ctx->r4 == 0) {
        // 0x80106A74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106A8C;
    }
    goto skip_0;
    // 0x80106A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106A78: jal         0x800B38E8
    // 0x80106A7C: nop

    func_800B38E8(rdram, ctx);
        goto after_0;
    // 0x80106A7C: nop

    after_0:
    // 0x80106A80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106A84: sw          $v0, 0x6EF0($at)
    MEM_W(0X6EF0, ctx->r1) = ctx->r2;
    // 0x80106A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106A8C:
    // 0x80106A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106A90: jr          $ra
    // 0x80106A94: nop

    return;
    // 0x80106A94: nop

;}
RECOMP_FUNC void bastick_func_8009F198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F198: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009F19C: jr          $ra
    // 0x8009F1A0: sb          $a1, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r5;
    return;
    // 0x8009F1A0: sb          $a1, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _plcamera_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878D8: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878D8);
    return;
    // 0x800878DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: jal         0x80800050
    // 0x8080035C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800050_bsstatue(rdram, ctx);
        goto after_0;
    // 0x8080035C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800360: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080036C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800370: nop

    // 0x80800374: bc1fl       L_80800388
    if (!c1cs) {
        // 0x80800378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080037C: jal         0x80095760
    // 0x80800380: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    baflag_set(rdram, ctx);
        goto after_1;
    // 0x80800380: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800388:
    // 0x80800388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_800C4B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C4B80: jr          $ra
    // 0x800C4B84: sh          $a0, -0x566A($at)
    MEM_H(-0X566A, ctx->r1) = ctx->r4;
    return;
    // 0x800C4B84: sh          $a0, -0x566A($at)
    MEM_H(-0X566A, ctx->r1) = ctx->r4;
    // 0x800C4B88: nop

    // 0x800C4B8C: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C78: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C78);
    return;
    // 0x80083C7C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800CACEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CACF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CACF4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800CACF8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800CACFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CAD00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CAD04: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CAD08: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CAD0C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800CAD10: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800CAD14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CAD18: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CAD1C: addiu       $s1, $a0, 0x24
    ctx->r17 = ADD32(ctx->r4, 0X24);
    // 0x800CAD20: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x800CAD24: addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
    // 0x800CAD28: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800CAD2C: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CAD30: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CAD34: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800CAD38: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800CAD3C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800CAD40: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800CAD44: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CAD48: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_800CAD4C:
    // 0x800CAD4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CAD50: jal         0x800EEAA4
    // 0x800CAD54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_0;
    // 0x800CAD54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800CAD58: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800CAD5C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800CAD60: bc1f        L_800CAD70
    if (!c1cs) {
        // 0x800CAD64: nop
    
            goto L_800CAD70;
    }
    // 0x800CAD64: nop

    // 0x800CAD68: b           L_800CAD7C
    // 0x800CAD6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CAD7C;
    // 0x800CAD6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CAD70:
    // 0x800CAD70: bne         $s0, $s3, L_800CAD4C
    if (ctx->r16 != ctx->r19) {
        // 0x800CAD74: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800CAD4C;
    }
    // 0x800CAD74: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800CAD78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CAD7C:
    // 0x800CAD7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAD80: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CAD84: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAD88: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CAD8C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800CAD90: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800CAD94: jr          $ra
    // 0x800CAD98: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800CAD98: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void boot_inflate_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000080C: sw          $ra, 0xA68($sp)
    MEM_W(0XA68, ctx->r29) = ctx->r31;
    // 0x80000810: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000814: beq         $at, $zero, L_8000083C
    if (ctx->r1 == 0) {
        // 0x80000818: nop
    
            goto L_8000083C;
    }
    // 0x80000818: nop

    // 0x8000081C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000820:
    // 0x80000820: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000824: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000828: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8000082C: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000830: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000834: bnel        $at, $zero, L_80000820
    if (ctx->r1 != 0) {
        // 0x80000838: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000820;
    }
    goto skip_0;
    // 0x80000838: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_8000083C:
    // 0x8000083C: andi        $at, $gp, 0x1
    ctx->r1 = ctx->r28 & 0X1;
    // 0x80000840: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80000844: srl         $t3, $gp, 1
    ctx->r11 = S32(U32(ctx->r28) >> 1);
    // 0x80000848: andi        $t3, $t3, 0x3
    ctx->r11 = ctx->r11 & 0X3;
    // 0x8000084C: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x80000850: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x80000854: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000858: bne         $t3, $at, L_80000870
    if (ctx->r11 != ctx->r1) {
        // 0x8000085C: nop
    
            goto L_80000870;
    }
    // 0x8000085C: nop

    // 0x80000860: jal         0x800008B0
    // 0x80000864: nop

    boot_inflate_dynamic(rdram, ctx);
        goto after_0;
    // 0x80000864: nop

    after_0:
    // 0x80000868: j           L_800008A4
    // 0x8000086C: nop

        goto L_800008A4;
    // 0x8000086C: nop

L_80000870:
    // 0x80000870: bne         $t3, $zero, L_80000888
    if (ctx->r11 != 0) {
        // 0x80000874: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80000888;
    }
    // 0x80000874: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000878: jal         0x80000CB4
    // 0x8000087C: nop

    boot_inflate_stored(rdram, ctx);
        goto after_1;
    // 0x8000087C: nop

    after_1:
    // 0x80000880: j           L_800008A4
    // 0x80000884: nop

        goto L_800008A4;
    // 0x80000884: nop

L_80000888:
    // 0x80000888: bne         $t3, $at, L_800008A0
    if (ctx->r11 != ctx->r1) {
        // 0x8000088C: nop
    
            goto L_800008A0;
    }
    // 0x8000088C: nop

    // 0x80000890: jal         0x80000DDC
    // 0x80000894: nop

    boot_inflate_fixed(rdram, ctx);
        goto after_2;
    // 0x80000894: nop

    after_2:
    // 0x80000898: j           L_800008A4
    // 0x8000089C: nop

        goto L_800008A4;
    // 0x8000089C: nop

L_800008A0:
    // 0x800008A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800008A4:
    // 0x800008A4: lw          $ra, 0xA68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA68);
    // 0x800008A8: jr          $ra
    // 0x800008AC: nop

    return;
    // 0x800008AC: nop

;}
RECOMP_FUNC void func_800A9D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9D98: jal         0x8001AC9C
    // 0x800A9D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    has_free_block_after(rdram, ctx);
        goto after_0;
    // 0x800A9D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A9DA0: bne         $v0, $zero, L_800A9DB0
    if (ctx->r2 != 0) {
        // 0x800A9DA4: nop
    
            goto L_800A9DB0;
    }
    // 0x800A9DA4: nop

    // 0x800A9DA8: jal         0x8008160C
    // 0x800A9DAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8008160C(rdram, ctx);
        goto after_1;
    // 0x800A9DAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
L_800A9DB0:
    // 0x800A9DB0: jal         0x8001AC9C
    // 0x800A9DB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_2;
    // 0x800A9DB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800A9DB8: bne         $v0, $zero, L_800A9DD0
    if (ctx->r2 != 0) {
        // 0x800A9DBC: nop
    
            goto L_800A9DD0;
    }
    // 0x800A9DBC: nop

    // 0x800A9DC0: jal         0x800BFCC4
    // 0x800A9DC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BFCC4(rdram, ctx);
        goto after_3;
    // 0x800A9DC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800A9DC8: jal         0x800D6E54
    // 0x800A9DCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800D6E54(rdram, ctx);
        goto after_4;
    // 0x800A9DCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
L_800A9DD0:
    // 0x800A9DD0: jal         0x8001AC9C
    // 0x800A9DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_5;
    // 0x800A9DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x800A9DD8: bne         $v0, $zero, L_800A9DE8
    if (ctx->r2 != 0) {
        // 0x800A9DDC: nop
    
            goto L_800A9DE8;
    }
    // 0x800A9DDC: nop

    // 0x800A9DE0: jal         0x8008B6E0
    // 0x800A9DE4: nop

    func_8008B6E0(rdram, ctx);
        goto after_6;
    // 0x800A9DE4: nop

    after_6:
L_800A9DE8:
    // 0x800A9DE8: jal         0x8001AC9C
    // 0x800A9DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_7;
    // 0x800A9DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x800A9DF0: bne         $v0, $zero, L_800A9E00
    if (ctx->r2 != 0) {
        // 0x800A9DF4: nop
    
            goto L_800A9E00;
    }
    // 0x800A9DF4: nop

    // 0x800A9DF8: jal         0x800FFD10
    // 0x800A9DFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FFD10(rdram, ctx);
        goto after_8;
    // 0x800A9DFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
L_800A9E00:
    // 0x800A9E00: jal         0x8001AC9C
    // 0x800A9E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_9;
    // 0x800A9E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x800A9E08: bne         $v0, $zero, L_800A9E18
    if (ctx->r2 != 0) {
        // 0x800A9E0C: nop
    
            goto L_800A9E18;
    }
    // 0x800A9E0C: nop

    // 0x800A9E10: jal         0x80100670
    // 0x800A9E14: nop

    func_80100670(rdram, ctx);
        goto after_10;
    // 0x800A9E14: nop

    after_10:
L_800A9E18:
    // 0x800A9E18: jal         0x8001AC9C
    // 0x800A9E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_11;
    // 0x800A9E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_11:
    // 0x800A9E20: beq         $v0, $zero, L_800A9E30
    if (ctx->r2 == 0) {
        // 0x800A9E24: nop
    
            goto L_800A9E30;
    }
    // 0x800A9E24: nop

    // 0x800A9E28: b           L_800A9EAC
    // 0x800A9E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A9EAC;
    // 0x800A9E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A9E30:
    // 0x800A9E30: jal         0x800D58CC
    // 0x800A9E34: nop

    func_800D58CC(rdram, ctx);
        goto after_12;
    // 0x800A9E34: nop

    after_12:
    // 0x800A9E38: jal         0x800A8168
    // 0x800A9E3C: nop

    func_800A8168(rdram, ctx);
        goto after_13;
    // 0x800A9E3C: nop

    after_13:
    // 0x800A9E40: jal         0x8001AC9C
    // 0x800A9E44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_14;
    // 0x800A9E44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_14:
    // 0x800A9E48: bne         $v0, $zero, L_800A9E60
    if (ctx->r2 != 0) {
        // 0x800A9E4C: nop
    
            goto L_800A9E60;
    }
    // 0x800A9E4C: nop

    // 0x800A9E50: jal         0x800BFCC4
    // 0x800A9E54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800BFCC4(rdram, ctx);
        goto after_15;
    // 0x800A9E54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_15:
    // 0x800A9E58: jal         0x800D6E54
    // 0x800A9E5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800D6E54(rdram, ctx);
        goto after_16;
    // 0x800A9E5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
L_800A9E60:
    // 0x800A9E60: jal         0x8001AC9C
    // 0x800A9E64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_17;
    // 0x800A9E64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_17:
    // 0x800A9E68: bne         $v0, $zero, L_800A9E78
    if (ctx->r2 != 0) {
        // 0x800A9E6C: nop
    
            goto L_800A9E78;
    }
    // 0x800A9E6C: nop

    // 0x800A9E70: jal         0x800FFD10
    // 0x800A9E74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FFD10(rdram, ctx);
        goto after_18;
    // 0x800A9E74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
L_800A9E78:
    // 0x800A9E78: jal         0x8001AC9C
    // 0x800A9E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_19;
    // 0x800A9E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_19:
    // 0x800A9E80: bne         $v0, $zero, L_800A9E90
    if (ctx->r2 != 0) {
        // 0x800A9E84: nop
    
            goto L_800A9E90;
    }
    // 0x800A9E84: nop

    // 0x800A9E88: jal         0x800B59E0
    // 0x800A9E8C: nop

    func_800B59E0(rdram, ctx);
        goto after_20;
    // 0x800A9E8C: nop

    after_20:
L_800A9E90:
    // 0x800A9E90: jal         0x8001AC9C
    // 0x800A9E94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    has_free_block_after(rdram, ctx);
        goto after_21;
    // 0x800A9E94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_21:
    // 0x800A9E98: beql        $v0, $zero, L_800A9EAC
    if (ctx->r2 == 0) {
        // 0x800A9E9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A9EAC;
    }
    goto skip_0;
    // 0x800A9E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800A9EA0: b           L_800A9EAC
    // 0x800A9EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A9EAC;
    // 0x800A9EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A9EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A9EAC:
    // 0x800A9EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9EB4: jr          $ra
    // 0x800A9EB8: nop

    return;
    // 0x800A9EB8: nop

;}
RECOMP_FUNC void func_808003E8_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808003F8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003FC: beq         $a1, $at, L_80800448
    if (ctx->r5 == ctx->r1) {
        // 0x80800400: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800448;
    }
    // 0x80800400: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800404: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800408: beq         $a1, $at, L_80800538
    if (ctx->r5 == ctx->r1) {
        // 0x8080040C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800538;
    }
    // 0x8080040C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800410: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800414: beq         $a1, $at, L_808004B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800418: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004B0;
    }
    // 0x80800418: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080041C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800420: beq         $a1, $at, L_808005D8
    if (ctx->r5 == ctx->r1) {
        // 0x80800424: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808005D8;
    }
    // 0x80800424: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800428: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x8080042C: beq         $a1, $at, L_80800548
    if (ctx->r5 == ctx->r1) {
        // 0x80800430: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80800548;
    }
    // 0x80800430: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800434: addiu       $at, $zero, 0xB7
    ctx->r1 = ADD32(0, 0XB7);
    // 0x80800438: beq         $a1, $at, L_80800558
    if (ctx->r5 == ctx->r1) {
        // 0x8080043C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800558;
    }
    // 0x8080043C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800440: b           L_8080063C
    // 0x80800444: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_8080063C;
    // 0x80800444: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800448:
    // 0x80800448: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8080044C: jal         0x800D0B68
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800454: bne         $v0, $zero, L_80800650
    if (ctx->r2 != 0) {
        // 0x80800458: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800650;
    }
    // 0x80800458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080045C: jal         0x80103110
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800464: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800468: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080046C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800470: jal         0x8010114C
    // 0x80800474: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800474: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_2:
    // 0x80800478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080047C: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x80800480: jal         0x800CE8D8
    // 0x80800484: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    func_800CE8D8(rdram, ctx);
        goto after_3;
    // 0x80800484: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x80800488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080048C: jal         0x800CE88C
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800494: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800498: addiu       $a1, $a1, 0x5FB0
    ctx->r5 = ADD32(ctx->r5, 0X5FB0);
    // 0x8080049C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004A0: jal         0x800CE928
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_5;
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808004A8: b           L_80800654
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B0:
    // 0x808004B0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x808004B4: jal         0x800F64A4
    // 0x808004B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x808004B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x808004BC: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x808004C0: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800520;
    }
    // 0x808004C0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808004C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004C8: jal         0x800CEAA8
    // 0x808004CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800CEAA8(rdram, ctx);
        goto after_7;
    // 0x808004CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_7:
    // 0x808004D0: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x808004D4: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800520;
    }
    // 0x808004D4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808004D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004DC: jal         0x800CE95C
    // 0x808004E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800CE95C(rdram, ctx);
        goto after_8;
    // 0x808004E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x808004E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x808004E8: addiu       $v1, $v1, 0x5FB0
    ctx->r3 = ADD32(ctx->r3, 0X5FB0);
    // 0x808004EC: bne         $v0, $v1, L_80800520
    if (ctx->r2 != ctx->r3) {
        // 0x808004F0: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800520;
    }
    // 0x808004F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004F8: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x808004FC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80800500: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80800504: jal         0x800CE8D8
    // 0x80800508: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800CE8D8(rdram, ctx);
        goto after_9;
    // 0x80800508: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_9:
    // 0x8080050C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800510: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800514: jal         0x800CE928
    // 0x80800518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_10;
    // 0x80800518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8080051C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80800520:
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800524: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800528: jal         0x80085820
    // 0x8080052C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x8080052C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800530: b           L_80800658
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800658;
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800538:
    // 0x80800538: jal         0x80103110
    // 0x8080053C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x8080053C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800540: b           L_80800654
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800548:
    // 0x80800548: jal         0x80101074
    // 0x8080054C: addiu       $a0, $a0, -0x5DB8
    ctx->r4 = ADD32(ctx->r4, -0X5DB8);
    func_80101074(rdram, ctx);
        goto after_13;
    // 0x8080054C: addiu       $a0, $a0, -0x5DB8
    ctx->r4 = ADD32(ctx->r4, -0X5DB8);
    after_13:
    // 0x80800550: b           L_80800654
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800558:
    // 0x80800558: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8080055C: bne         $t8, $zero, L_80800650
    if (ctx->r24 != 0) {
        // 0x80800560: sra         $t9, $t7, 16
        ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80800650;
    }
    // 0x80800560: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800564: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80800568: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8080056C: bnel        $t0, $at, L_80800654
    if (ctx->r8 != ctx->r1) {
        // 0x80800570: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800654;
    }
    goto skip_0;
    // 0x80800570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800574: jal         0x800CEAA8
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_14;
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8080057C: beql        $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x80800580: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_808005B8;
    }
    goto skip_1;
    // 0x80800580: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800584: jal         0x800CE95C
    // 0x80800588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CE95C(rdram, ctx);
        goto after_15;
    // 0x80800588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8080058C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80800590: addiu       $t1, $t1, 0x5FB0
    ctx->r9 = ADD32(ctx->r9, 0X5FB0);
    // 0x80800594: bne         $v0, $t1, L_808005B4
    if (ctx->r2 != ctx->r9) {
        // 0x80800598: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808005B4;
    }
    // 0x80800598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005A0: jal         0x800CE928
    // 0x808005A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_16;
    // 0x808005A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x808005A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005AC: jal         0x800CE88C
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_17;
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
L_808005B4:
    // 0x808005B4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_808005B8:
    // 0x808005B8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808005BC: lw          $a0, 0x3C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3C);
    // 0x808005C0: beql        $a0, $zero, L_80800654
    if (ctx->r4 == 0) {
        // 0x808005C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800654;
    }
    goto skip_2;
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808005C8: jal         0x8010114C
    // 0x808005CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_18;
    // 0x808005CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x808005D0: b           L_80800654
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D8:
    // 0x808005D8: lhu         $a2, 0x76($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X76);
    // 0x808005DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808005E0: addiu       $a1, $zero, 0x364
    ctx->r5 = ADD32(0, 0X364);
    // 0x808005E4: srl         $t4, $a2, 7
    ctx->r12 = S32(U32(ctx->r6) >> 7);
    // 0x808005E8: jal         0x80089C70
    // 0x808005EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_19;
    // 0x808005EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_19:
    // 0x808005F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005F8: jal         0x80085820
    // 0x808005FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x808005FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_20:
    // 0x80800600: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800604: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1048, 0XB22) << 16);
    // 0x80800608: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x8080060C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800610: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80800614: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800618: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8080061C: jal         0x800DA298
    // 0x80800620: lhu         $a0, 0xB22($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1048, 0XB22));
    func_800DA298(rdram, ctx);
        goto after_21;
    // 0x80800620: lhu         $a0, 0xB22($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1048, 0XB22));
    after_21:
    // 0x80800624: beq         $v0, $zero, L_80800650
    if (ctx->r2 == 0) {
        // 0x80800628: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800650;
    }
    // 0x80800628: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080062C: jal         0x80103110
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_22;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800634: b           L_80800654
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800640: jal         0x80085820
    // 0x80800644: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80800644: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_23:
    // 0x80800648: b           L_80800658
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800658;
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800650:
    // 0x80800650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800654:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800658:
    // 0x80800658: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void func_800BCC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BCC94: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800BCC98: lui         $t8, 0x13
    ctx->r24 = S32(0X13 << 16);
    // 0x800BCC9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BCCA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BCCA4: addiu       $t8, $t8, -0x7CC8
    ctx->r24 = ADD32(ctx->r24, -0X7CC8);
    // 0x800BCCA8: ori         $t7, $t7, 0x5
    ctx->r15 = ctx->r15 | 0X5;
    // 0x800BCCAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BCCB0: jr          $ra
    // 0x800BCCB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800BCCB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BCCB8: nop

    // 0x800BCCBC: nop

;}
RECOMP_FUNC void func_808003D0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808003E4: jal         0x8009D3A8
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003EC: jal         0x808005DC
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003F4: jal         0x8008CAEC
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_2;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003FC: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080040C;
    }
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: addiu       $t6, $zero, 0x145
    ctx->r14 = ADD32(0, 0X145);
    // 0x80800408: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080040C:
    // 0x8080040C: jal         0x8080020C
    // 0x80800410: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080020C_bstrexsmall(rdram, ctx);
        goto after_3;
    // 0x80800410: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8009E5C8
    // 0x8080041C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x8080041C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800424: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void func_800C67F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67F0: jr          $ra
    // 0x800C67F4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    return;
    // 0x800C67F4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
;}
RECOMP_FUNC void _chdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086248: syscall     293
    recomp_syscall_handler(rdram, ctx, 0x80086248);
    return;
    // 0x8008624C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080002C_glsplinecs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800038: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080003C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800040: jal         0x80105494
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800048: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080004C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800050: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800054: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800058: lwc1        $f4, 0x48($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X48);
    // 0x8080005C: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800068: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080006C: srl         $t9, $v1, 14
    ctx->r25 = S32(U32(ctx->r3) >> 14);
    // 0x80800070: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800074: nop

    // 0x80800078: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080007C: beql        $t7, $zero, L_808000CC
    if (ctx->r15 == 0) {
        // 0x80800080: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_808000CC;
    }
    goto skip_0;
    // 0x80800080: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800084: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800088: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080008C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800090: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800094: nop

    // 0x80800098: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080009C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808000A0: nop

    // 0x808000A4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808000A8: bne         $t7, $zero, L_808000C0
    if (ctx->r15 != 0) {
        // 0x808000AC: nop
    
            goto L_808000C0;
    }
    // 0x808000AC: nop

    // 0x808000B0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808000B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000B8: b           L_808000D8
    // 0x808000BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_808000D8;
    // 0x808000BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_808000C0:
    // 0x808000C0: b           L_808000D8
    // 0x808000C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_808000D8;
    // 0x808000C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808000C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_808000CC:
    // 0x808000CC: nop

    // 0x808000D0: bltz        $t7, L_808000C0
    if (SIGNED(ctx->r15) < 0) {
        // 0x808000D4: nop
    
            goto L_808000C0;
    }
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: xor         $t0, $t7, $t9
    ctx->r8 = ctx->r15 ^ ctx->r25;
    // 0x808000DC: sll         $t1, $t0, 23
    ctx->r9 = S32(ctx->r8 << 23);
    // 0x808000E0: srl         $t2, $t1, 9
    ctx->r10 = S32(U32(ctx->r9) >> 9);
    // 0x808000E4: xor         $t3, $t2, $v1
    ctx->r11 = ctx->r10 ^ ctx->r3;
    // 0x808000E8: sw          $t3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r11;
    // 0x808000EC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808000F0: lhu         $t9, 0x40($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X40);
    // 0x808000F4: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808000F8: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x808000FC: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80800100: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800104: sh          $t1, 0x40($v0)
    MEM_H(0X40, ctx->r2) = ctx->r9;
    // 0x80800108: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080010C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800110: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800114: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80800118: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080011C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800120: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800124: nop

    // 0x80800128: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8080012C: beql        $t3, $zero, L_8080017C
    if (ctx->r11 == 0) {
        // 0x80800130: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_8080017C;
    }
    goto skip_1;
    // 0x80800130: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80800134: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800138: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080013C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800140: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800144: nop

    // 0x80800148: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080014C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800150: nop

    // 0x80800154: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80800158: bne         $t3, $zero, L_80800170
    if (ctx->r11 != 0) {
        // 0x8080015C: nop
    
            goto L_80800170;
    }
    // 0x8080015C: nop

    // 0x80800160: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800164: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800168: b           L_80800188
    // 0x8080016C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80800188;
    // 0x8080016C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80800170:
    // 0x80800170: b           L_80800188
    // 0x80800174: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80800188;
    // 0x80800174: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80800178: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_8080017C:
    // 0x8080017C: nop

    // 0x80800180: bltz        $t3, L_80800170
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800184: nop
    
            goto L_80800170;
    }
    // 0x80800184: nop

L_80800188:
    // 0x80800188: lhu         $t7, 0x42($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X42);
    // 0x8080018C: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x80800190: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80800194: andi        $t6, $t5, 0x3FE0
    ctx->r14 = ctx->r13 & 0X3FE0;
    // 0x80800198: andi        $t9, $t7, 0xC01F
    ctx->r25 = ctx->r15 & 0XC01F;
    // 0x8080019C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x808001A0: sh          $t8, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r24;
    // 0x808001A4: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x808001A8: lhu         $t4, 0x44($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X44);
    // 0x808001AC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808001B0: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x808001B4: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x808001B8: srl         $t8, $t9, 23
    ctx->r24 = S32(U32(ctx->r25) >> 23);
    // 0x808001BC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808001C0: andi        $t3, $t2, 0x1FF0
    ctx->r11 = ctx->r10 & 0X1FF0;
    // 0x808001C4: andi        $t5, $t4, 0xE00F
    ctx->r13 = ctx->r12 & 0XE00F;
    // 0x808001C8: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x808001CC: sh          $t7, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r15;
    // 0x808001D0: bgez        $t8, L_808001E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808001D4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_808001E8;
    }
    // 0x808001D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808001D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E0: nop

    // 0x808001E4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_808001E8:
    // 0x808001E8: swc1        $f18, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f18.u32l;
    // 0x808001EC: lw          $t0, 0x40($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X40);
    // 0x808001F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001F4: sll         $t1, $t0, 18
    ctx->r9 = S32(ctx->r8 << 18);
    // 0x808001F8: srl         $t2, $t1, 23
    ctx->r10 = S32(U32(ctx->r9) >> 23);
    // 0x808001FC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800200: bgez        $t2, L_80800214
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800204: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800214;
    }
    // 0x80800204: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800208: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080020C: nop

    // 0x80800210: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800214:
    // 0x80800214: swc1        $f8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f8.u32l;
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_80800054_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800058: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800064: jal         0x80100094
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080006C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800070: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800074: jal         0x8010D254
    // 0x80800078: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800078: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080007C: jal         0x800D9078
    // 0x80800080: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800080: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800084: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080008C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800090: beq         $t6, $at, L_808000BC
    if (ctx->r14 == ctx->r1) {
        // 0x80800094: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000BC;
    }
    // 0x80800094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800098: beq         $t6, $at, L_80800100
    if (ctx->r14 == ctx->r1) {
        // 0x8080009C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800100;
    }
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000A4: beq         $t6, $at, L_80800134
    if (ctx->r14 == ctx->r1) {
        // 0x808000A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800134;
    }
    // 0x808000A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000AC: beq         $t6, $at, L_808002A8
    if (ctx->r14 == ctx->r1) {
        // 0x808000B0: nop
    
            goto L_808002A8;
    }
    // 0x808000B0: nop

    // 0x808000B4: b           L_808002D0
    // 0x808000B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002D0;
    // 0x808000B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000BC:
    // 0x808000BC: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808000C8: bgez        $t9, L_808000E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808000CC: nop
    
            goto L_808000E0;
    }
    // 0x808000CC: nop

    // 0x808000D0: jal         0x808003C4
    // 0x808000D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003C4_chcrystalbaddie(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000D8: b           L_808002D0
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002D0;
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: jal         0x80800424
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800424_chcrystalbaddie(rdram, ctx);
        goto after_4;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E8: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808000EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x808003C4
    // 0x808000F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003C4_chcrystalbaddie(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808000F8: b           L_808002D0
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002D0;
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800100:
    // 0x80800100: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1384, 0X6AC) << 16);
    // 0x80800104: addiu       $a2, $a2, 0x6AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1384, 0X6AC));
    // 0x80800108: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080010C: jal         0x80089D20
    // 0x80800110: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800110: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x80800114: jal         0x80101DDC
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_7;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080011C: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x808003C4
    // 0x80800128: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003C4_chcrystalbaddie(rdram, ctx);
        goto after_8;
    // 0x80800128: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080012C: b           L_808002D0
    // 0x80800130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002D0;
    // 0x80800130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800134:
    // 0x80800134: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800140: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80800144: bgez        $t2, L_80800194
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800148: nop
    
            goto L_80800194;
    }
    // 0x80800148: nop

    // 0x8080014C: jal         0x80089BF0
    // 0x80800150: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800150: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x80800154: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800158: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080015C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800160: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x8080016C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80800170: jal         0x80102BF8
    // 0x80800174: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_80102BF8(rdram, ctx);
        goto after_10;
    // 0x80800174: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x80800178: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x8080017C: ori         $a1, $a1, 0x5015
    ctx->r5 = ctx->r5 | 0X5015;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x8010C3A8
    // 0x80800188: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_8010C3A8(rdram, ctx);
        goto after_11;
    // 0x80800188: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x8080018C: b           L_80800298
    // 0x80800190: nop

        goto L_80800298;
    // 0x80800190: nop

L_80800194:
    // 0x80800194: jal         0x80089F78
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080019C: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E4;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80102D78
    // 0x808001A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102D78(rdram, ctx);
        goto after_13;
    // 0x808001A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x808001AC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808001B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001B4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808001B8: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808001BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001C0: addiu       $t3, $zero, 0x5800
    ctx->r11 = ADD32(0, 0X5800);
    // 0x808001C4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808001C8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80089F90
    // 0x808001D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x808001D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x808001D8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001DC: lhu         $t4, 0x6($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X6);
    // 0x808001E0: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
L_808001E4:
    // 0x808001E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001E8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808001F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001F8: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x808001FC: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80800200: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080020C: jal         0x80089F80
    // 0x80800210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80800214: jal         0x800D8FF8
    // 0x80800218: nop

    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x80800218: nop

    after_16:
    // 0x8080021C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800220: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800224: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800228: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080022C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800230: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800234: jal         0x800F15F8
    // 0x80800238: nop

    func_800F15F8(rdram, ctx);
        goto after_17;
    // 0x80800238: nop

    after_17:
    // 0x8080023C: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800240: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800244: ori         $a1, $a1, 0x5115
    ctx->r5 = ctx->r5 | 0X5115;
    // 0x80800248: jal         0x8010B990
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_18;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800250: jal         0x80089F78
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800258: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080025C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1384, 0X600) << 16);
            goto L_80800298;
    }
    // 0x8080025C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1384, 0X600) << 16);
    // 0x80800260: jal         0x800DC298
    // 0x80800264: lwc1        $f12, 0x600($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1384, 0X600));
    func_800DC298(rdram, ctx);
        goto after_20;
    // 0x80800264: lwc1        $f12, 0x600($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1384, 0X600));
    after_20:
    // 0x80800268: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080026C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800298;
    }
    // 0x8080026C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800270: jal         0x8010C9B0
    // 0x80800274: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    func_8010C9B0(rdram, ctx);
        goto after_21;
    // 0x80800274: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_21:
    // 0x80800278: beql        $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800290;
    }
    goto skip_0;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800280: jal         0x8010C500
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_22;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800288: bne         $v0, $zero, L_80800298
    if (ctx->r2 != 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800290:
    // 0x80800290: jal         0x808003C4
    // 0x80800294: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808003C4_chcrystalbaddie(rdram, ctx);
        goto after_23;
    // 0x80800294: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_23:
L_80800298:
    // 0x80800298: jal         0x808004B4
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_chcrystalbaddie(rdram, ctx);
        goto after_24;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808002A0: b           L_808002D0
    // 0x808002A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002D0;
    // 0x808002A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002A8:
    // 0x808002A8: jal         0x80101DDC
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_25;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808002B0: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x808003C4
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003C4_chcrystalbaddie(rdram, ctx);
        goto after_26;
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x808002C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1384, 0X604) << 16);
    // 0x808002C4: lwc1        $f4, 0x604($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1384, 0X604));
    // 0x808002C8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808002CC:
    // 0x808002CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002D0:
    // 0x808002D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_800F2454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F2458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F245C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F2460: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F2464: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F2468: jal         0x800EE7F8
    // 0x800F246C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800F246C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800F2470: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800F2474: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F2478: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F247C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800F2480:
    // 0x800F2480: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2484: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F2488: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F248C: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F2490: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800F2494: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F2498: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F249C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F24A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F24A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F24A8: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800F24AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800F24B0: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800F24B4: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800F24B8: bne         $v1, $a1, L_800F2480
    if (ctx->r3 != ctx->r5) {
        // 0x800F24BC: swc1        $f12, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
            goto L_800F2480;
    }
    // 0x800F24BC: swc1        $f12, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800F24C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F24C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F24C8: jr          $ra
    // 0x800F24CC: nop

    return;
    // 0x800F24CC: nop

;}
RECOMP_FUNC void vpmodule_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080009C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808000A4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808000A8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808000AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808000B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808000B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808000B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808000C8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808000CC: lw          $fp, 0x2C($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X2C);
    // 0x808000D0: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x808000D4: bne         $fp, $zero, L_808000E4
    if (ctx->r30 != 0) {
        // 0x808000D8: sll         $v0, $fp, 3
        ctx->r2 = S32(ctx->r30 << 3);
            goto L_808000E4;
    }
    // 0x808000D8: sll         $v0, $fp, 3
    ctx->r2 = S32(ctx->r30 << 3);
    // 0x808000DC: b           L_808001F4
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F4;
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E4:
    // 0x808000E4: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x808000E8: andi        $t6, $a0, 0xF
    ctx->r14 = ctx->r4 & 0XF;
    // 0x808000EC: beql        $t6, $zero, L_80800108
    if (ctx->r14 == 0) {
        // 0x808000F0: lh          $t8, 0x20($s7)
        ctx->r24 = MEM_H(ctx->r23, 0X20);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000F0: lh          $t8, 0x20($s7)
    ctx->r24 = MEM_H(ctx->r23, 0X20);
    skip_0:
    // 0x808000F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_808000F8:
    // 0x808000F8: andi        $t7, $a0, 0xF
    ctx->r15 = ctx->r4 & 0XF;
    // 0x808000FC: bnel        $t7, $zero, L_808000F8
    if (ctx->r15 != 0) {
        // 0x80800100: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_808000F8;
    }
    goto skip_1;
    // 0x80800100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x80800104: lh          $t8, 0x20($s7)
    ctx->r24 = MEM_H(ctx->r23, 0X20);
L_80800108:
    // 0x80800108: lh          $t1, 0x22($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X22);
    // 0x8080010C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800110: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80800114: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800118: jal         0x8001ACCC
    // 0x8080011C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080011C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    after_0:
    // 0x80800120: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800124: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80800128: blez        $fp, L_80800194
    if (SIGNED(ctx->r30) <= 0) {
        // 0x8080012C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800194;
    }
    // 0x8080012C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800130: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3002, 0X8C0) << 16);
    // 0x80800134: addiu       $s5, $s5, 0x8C0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(3002, 0X8C0));
    // 0x80800138: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8080013C: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x80800140: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: lw          $t3, 0x30($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X30);
    // 0x80800148: addu        $s3, $t3, $s7
    ctx->r19 = ADD32(ctx->r11, ctx->r23);
    // 0x8080014C: jal         0x80800000
    // 0x80800150: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_80800000_vpmodule(rdram, ctx);
        goto after_1;
    // 0x80800150: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_1:
    // 0x80800154: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800158: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8080015C: sb          $s4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r20;
    // 0x80800160: sh          $s1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r17;
    // 0x80800164: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800168: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080016C: mflo        $t4
    ctx->r12 = lo;
    // 0x80800170: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x80800174: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80800178: jalr        $t9
    // 0x8080017C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8080017C: nop

    after_2:
    // 0x80800180: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800184: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800188: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8080018C: bne         $s1, $fp, L_80800144
    if (ctx->r17 != ctx->r30) {
        // 0x80800190: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80800144;
    }
    // 0x80800190: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
L_80800194:
    // 0x80800194: andi        $t6, $s0, 0xF
    ctx->r14 = ctx->r16 & 0XF;
    // 0x80800198: beq         $t6, $zero, L_808001B0
    if (ctx->r14 == 0) {
        // 0x8080019C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_808001B0;
    }
    // 0x8080019C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_808001A4:
    // 0x808001A4: andi        $t7, $a1, 0xF
    ctx->r15 = ctx->r5 & 0XF;
    // 0x808001A8: bnel        $t7, $zero, L_808001A4
    if (ctx->r15 != 0) {
        // 0x808001AC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_808001A4;
    }
    goto skip_2;
    // 0x808001AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
L_808001B0:
    // 0x808001B0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x808001B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808001B8: subu        $t1, $a1, $t8
    ctx->r9 = SUB32(ctx->r5, ctx->r24);
    // 0x808001BC: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x808001C0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x808001C4: jal         0x800879A8
    // 0x808001C8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    _dbvpl_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001C8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x808001CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808001D0: lh          $t3, 0x20($s7)
    ctx->r11 = MEM_H(ctx->r23, 0X20);
    // 0x808001D4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x808001D8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x808001DC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x808001E0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808001E4: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x808001E8: jal         0x808005C4
    // 0x808001EC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_808005C4_vpmodule(rdram, ctx);
        goto after_4;
    // 0x808001EC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x808001F0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_808001F4:
    // 0x808001F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808001F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800204: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080020C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800210: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800214: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800218: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8080021C: jr          $ra
    // 0x80800220: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800220: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800134_vplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800138: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080013C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800140: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800144: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80800148: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8080014C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80800150: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
L_80800154:
    // 0x80800154: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800158: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8080015C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800160: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800164: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80800168: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8080016C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800170: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800174: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80800178: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080017C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800180: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80800184: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800188: bc1fl       L_80800198
    if (!c1cs) {
        // 0x8080018C: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_80800198;
    }
    goto skip_0;
    // 0x8080018C: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_0:
    // 0x80800190: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80800194: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
L_80800198:
    // 0x80800198: nop

    // 0x8080019C: bc1fl       L_808001AC
    if (!c1cs) {
        // 0x808001A0: lh          $a2, 0x0($t1)
        ctx->r6 = MEM_H(ctx->r9, 0X0);
            goto L_808001AC;
    }
    goto skip_1;
    // 0x808001A0: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
    skip_1:
    // 0x808001A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808001A8: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
L_808001AC:
    // 0x808001AC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x808001B0: lh          $a3, 0x4($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X4);
    // 0x808001B4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001B8: beql        $at, $zero, L_808001C8
    if (ctx->r1 == 0) {
        // 0x808001BC: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_808001C8;
    }
    goto skip_2;
    // 0x808001BC: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    skip_2:
    // 0x808001C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808001C4: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_808001C8:
    // 0x808001C8: beql        $at, $zero, L_808001D8
    if (ctx->r1 == 0) {
        // 0x808001CC: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_808001D8;
    }
    goto skip_3;
    // 0x808001CC: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_3:
    // 0x808001D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808001D4: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_808001D8:
    // 0x808001D8: beq         $at, $zero, L_808001E4
    if (ctx->r1 == 0) {
        // 0x808001DC: subu        $t8, $v0, $a2
        ctx->r24 = SUB32(ctx->r2, ctx->r6);
            goto L_808001E4;
    }
    // 0x808001DC: subu        $t8, $v0, $a2
    ctx->r24 = SUB32(ctx->r2, ctx->r6);
    // 0x808001E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_808001E4:
    // 0x808001E4: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808001E8: beql        $at, $zero, L_808001F8
    if (ctx->r1 == 0) {
        // 0x808001EC: sw          $t8, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r24;
            goto L_808001F8;
    }
    goto skip_4;
    // 0x808001EC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    skip_4:
    // 0x808001F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808001F4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_808001F8:
    // 0x808001F8: subu        $t9, $a1, $a2
    ctx->r25 = SUB32(ctx->r5, ctx->r6);
    // 0x808001FC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80800200: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80800204: bne         $t0, $t4, L_80800154
    if (ctx->r8 != ctx->r12) {
        // 0x80800208: sw          $t9, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r25;
            goto L_80800154;
    }
    // 0x80800208: sw          $t9, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r25;
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_800FDBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDBB8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FDBBC: lbu         $t6, 0x5A00($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5A00);
    // 0x800FDBC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FDBC4: addiu       $t8, $t8, 0x4224
    ctx->r24 = ADD32(ctx->r24, 0X4224);
    // 0x800FDBC8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800FDBCC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800FDBD0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800FDBD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FDBD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FDBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FDBE0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800FDBE4: beq         $t9, $at, L_800FDC18
    if (ctx->r25 == ctx->r1) {
        // 0x800FDBE8: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_800FDC18;
    }
    // 0x800FDBE8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800FDBEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FDBF0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDBF4: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDBF8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800FDBFC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800FDC00: jal         0x800FCFB0
    // 0x800FDC04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_0;
    // 0x800FDC04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800FDC08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800FDC0C: addiu       $t1, $t1, 0x4010
    ctx->r9 = ADD32(ctx->r9, 0X4010);
    // 0x800FDC10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDC14: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
L_800FDC18:
    // 0x800FDC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FDC1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FDC20: jr          $ra
    // 0x800FDC24: nop

    return;
    // 0x800FDC24: nop

;}
RECOMP_FUNC void chlakemonster_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E9C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1748, 0X22E0) << 16);
    // 0x80801EA0: jr          $ra
    // 0x80801EA4: addiu       $v0, $v0, 0x22E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X22E0));
    return;
    // 0x80801EA4: addiu       $v0, $v0, 0x22E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X22E0));
;}
RECOMP_FUNC void gccubesearch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800464: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2670, 0XEB0) << 16);
    // 0x80800468: addiu       $a1, $a1, 0xEB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2670, 0XEB0));
    // 0x8080046C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800470: jal         0x8080042C
    // 0x80800474: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800474: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x80800478: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8080047C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800480: bltz        $a0, L_808004CC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800484: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808004CC;
    }
    // 0x80800484: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800488: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080048C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2670, 0XEB0) << 16);
    // 0x80800490: addiu       $t7, $t7, 0xEB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2670, 0XEB0));
    // 0x80800494: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2670, 0XEB0) << 16);
    // 0x80800498: addiu       $a0, $a0, 0xEB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2670, 0XEB0));
    // 0x8080049C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808004A0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_808004A4:
    // 0x808004A4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x808004A8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x808004AC: srl         $t0, $t9, 21
    ctx->r8 = S32(U32(ctx->r25) >> 21);
    // 0x808004B0: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x808004B4: beql        $at, $zero, L_808004C4
    if (ctx->r1 == 0) {
        // 0x808004B8: sltu        $at, $v0, $a0
        ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
            goto L_808004C4;
    }
    goto skip_0;
    // 0x808004B8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    skip_0:
    // 0x808004BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808004C0: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
L_808004C4:
    // 0x808004C4: beql        $at, $zero, L_808004A4
    if (ctx->r1 == 0) {
        // 0x808004C8: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_808004A4;
    }
    goto skip_1;
    // 0x808004C8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_808004CC:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808004D8: jr          $ra
    // 0x808004DC: nop

    return;
    // 0x808004DC: nop

;}
