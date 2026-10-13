#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808007E0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808007EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808007F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808007F8: jal         0x80100094
    // 0x808007FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800800: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800804: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800808: jal         0x8010262C
    // 0x8080080C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8010262C(rdram, ctx);
        goto after_1;
    // 0x8080080C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80800810: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080081C: jal         0x808042FC
    // 0x80800820: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_808042FC_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80800820: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080082C: jal         0x80804A7C
    // 0x80800830: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_80804A7C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80800830: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080083C: jal         0x80809078
    // 0x80800840: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_80809078_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80800840: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800844: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080084C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80800850: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80800854: beql        $t7, $zero, L_80800878
    if (ctx->r15 == 0) {
        // 0x80800858: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80800878;
    }
    goto skip_0;
    // 0x80800858: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080085C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800860: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800864: lui         $a3, 0xC301
    ctx->r7 = S32(0XC301 << 16);
    // 0x80800868: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080086C: jal         0x800E0AFC
    // 0x80800870: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80800870: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80800874: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800878:
    // 0x80800878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080087C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80800880: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x80800884: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800888: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080088C: beql        $t9, $zero, L_808008B0
    if (ctx->r25 == 0) {
        // 0x80800890: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008B0;
    }
    goto skip_1;
    // 0x80800890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800898: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080089C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808008A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808008A4: jal         0x800E0C20
    // 0x808008A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0C20(rdram, ctx);
        goto after_6;
    // 0x808008A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x808008AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008B0:
    // 0x808008B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808008B8: jr          $ra
    // 0x808008BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808008BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void boot___osPiCreateAccessQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_808007B0_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B8: jal         0x80082FE8
    // 0x808007BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808007BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007C0: jal         0x808003BC
    // 0x808007C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808007C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_80800850_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1224, 0XA00) << 16);
    // 0x8080085C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800860: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800864: addiu       $a2, $a2, 0xA00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1224, 0XA00));
    // 0x80800868: jal         0x80089D20
    // 0x8080086C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080086C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800878: jr          $ra
    // 0x8080087C: nop

    return;
    // 0x8080087C: nop

;}
RECOMP_FUNC void susplinet_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808011DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808011E4: jal         0x808011B8
    // 0x808011E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808011B8_susplinet(rdram, ctx);
        goto after_0;
    // 0x808011E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808011EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808011F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011F8: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808011FC: mflo        $v1
    ctx->r3 = lo;
    // 0x80801200: addiu       $v0, $v1, 0x5C
    ctx->r2 = ADD32(ctx->r3, 0X5C);
    // 0x80801204: jr          $ra
    // 0x80801208: nop

    return;
    // 0x80801208: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1C0: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1C0);
    return;
    // 0x8008A1C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800C75A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75A0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800C75A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C75A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800C75AC: jr          $ra
    // 0x800C75B0: lh          $v0, -0x56F0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X56F0);
    return;
    // 0x800C75B0: lh          $v0, -0x56F0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X56F0);
;}
RECOMP_FUNC void func_800F10B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F10B4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800F10B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800F10BC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F10C0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800F10C4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800F10C8: c.eq.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl == ctx->f14.fl;
    // 0x800F10CC: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F10D0: bc1tl       L_800F118C
    if (c1cs) {
        // 0x800F10D4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F118C;
    }
    goto skip_0;
    // 0x800F10D4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x800F10D8: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F10DC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F10E0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800F10E4: nop

    // 0x800F10E8: bc1fl       L_800F113C
    if (!c1cs) {
        // 0x800F10EC: sub.s       $f6, $f12, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_800F113C;
    }
    goto skip_1;
    // 0x800F10EC: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    skip_1:
    // 0x800F10F0: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F10F4: sub.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800F10F8: sub.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800F10FC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F1100: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800F1104: add.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800F1108: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x800F110C: nop

    // 0x800F1110: bc1fl       L_800F1124
    if (!c1cs) {
        // 0x800F1114: c.lt.s      $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
            goto L_800F1124;
    }
    goto skip_2;
    // 0x800F1114: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    skip_2:
    // 0x800F1118: b           L_800F118C
    // 0x800F111C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800F118C;
    // 0x800F111C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F1120: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
L_800F1124:
    // 0x800F1124: nop

    // 0x800F1128: bc1f        L_800F1180
    if (!c1cs) {
        // 0x800F112C: nop
    
            goto L_800F1180;
    }
    // 0x800F112C: nop

    // 0x800F1130: b           L_800F118C
    // 0x800F1134: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_800F118C;
    // 0x800F1134: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800F1138: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
L_800F113C:
    // 0x800F113C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800F1140: sub.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800F1144: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F1148: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800F114C: add.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800F1150: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800F1154: nop

    // 0x800F1158: bc1fl       L_800F116C
    if (!c1cs) {
        // 0x800F115C: c.lt.s      $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
            goto L_800F116C;
    }
    goto skip_3;
    // 0x800F115C: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    skip_3:
    // 0x800F1160: b           L_800F118C
    // 0x800F1164: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800F118C;
    // 0x800F1164: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F1168: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
L_800F116C:
    // 0x800F116C: nop

    // 0x800F1170: bc1f        L_800F1180
    if (!c1cs) {
        // 0x800F1174: nop
    
            goto L_800F1180;
    }
    // 0x800F1174: nop

    // 0x800F1178: b           L_800F118C
    // 0x800F117C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_800F118C;
    // 0x800F117C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F1180:
    // 0x800F1180: b           L_800F118C
    // 0x800F1184: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_800F118C;
    // 0x800F1184: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x800F1188: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F118C:
    // 0x800F118C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800F1190: jr          $ra
    // 0x800F1194: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800F1194: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80800CB0_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB8: jal         0x80800028
    // 0x80800CBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800028_bstnt(rdram, ctx);
        goto after_0;
    // 0x80800CBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CC0: jal         0x800951B4
    // 0x80800CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80800CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CD0: jr          $ra
    // 0x80800CD4: nop

    return;
    // 0x80800CD4: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E58: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E58);
    return;
    // 0x80082E5C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_800D58FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D58FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D5900: lw          $t6, -0x4700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4700);
    // 0x800D5904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D590C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D5910: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5914: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5918: jal         0x8001E210
    // 0x800D591C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800D591C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800D5920: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5924: lw          $v0, -0x4BC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BC0);
    // 0x800D5928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D592C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5930: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800D5934: jr          $ra
    // 0x800D5938: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800D5938: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_808018DC_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808018E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808018E8: jal         0x80100094
    // 0x808018EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018F0: jal         0x8008A040
    // 0x808018F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808018F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808018F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808018FC: jal         0x8010D254
    // 0x80801900: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x80801900: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80801904: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801908: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8080190C: jal         0x800EEB40
    // 0x80801910: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801910: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80801914: jal         0x800BDC5C
    // 0x80801918: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800BDC5C(rdram, ctx);
        goto after_4;
    // 0x80801918: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8080191C: jal         0x800BDC5C
    // 0x80801920: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800BDC5C(rdram, ctx);
        goto after_5;
    // 0x80801920: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80801924: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801928: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8080192C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801930: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80801934: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080193C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801944: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801948: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080194C: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80801950: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80801954: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80801958: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080195C: nop

    // 0x80801960: bc1f        L_80801978
    if (!c1cs) {
        // 0x80801964: nop
    
            goto L_80801978;
    }
    // 0x80801964: nop

    // 0x80801968: jal         0x80801A6C
    // 0x8080196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801A6C_chevilspirit(rdram, ctx);
        goto after_6;
    // 0x8080196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801970: b           L_8080197C
    // 0x80801974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080197C;
    // 0x80801974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801978:
    // 0x80801978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080197C:
    // 0x8080197C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801980: jr          $ra
    // 0x80801984: nop

    return;
    // 0x80801984: nop

;}
RECOMP_FUNC void ncbafixpos_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bstaxi_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E08: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E08);
    return;
    // 0x80083E0C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x8080000C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800010: beql        $a2, $zero, L_80800028
    if (ctx->r6 == 0) {
        // 0x80800014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800028;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800018: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080001C: jal         0x800C31DC
    // 0x80800020: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    func_800C31DC(rdram, ctx);
        goto after_0;
    // 0x80800020: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800028:
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void chdrawbridgeswitches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2060, 0X210) << 16);
    // 0x80800120: jr          $ra
    // 0x80800124: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X210));
    return;
    // 0x80800124: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X210));
;}
RECOMP_FUNC void suquiz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080058C: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800590: jal         0x800DA564
    // 0x80800594: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800594: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800598: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080059C: beq         $v0, $at, L_808005C0
    if (ctx->r2 == ctx->r1) {
        // 0x808005A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005C0;
    }
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005A8: beq         $v0, $at, L_808005C8
    if (ctx->r2 == ctx->r1) {
        // 0x808005AC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808005C8;
    }
    // 0x808005AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005B0: beq         $v0, $at, L_808005D0
    if (ctx->r2 == ctx->r1) {
        // 0x808005B4: nop
    
            goto L_808005D0;
    }
    // 0x808005B4: nop

    // 0x808005B8: b           L_808005D8
    // 0x808005BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005D8;
    // 0x808005BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005C0:
    // 0x808005C0: b           L_808005D8
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005D8;
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C8:
    // 0x808005C8: b           L_808005D8
    // 0x808005CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808005D8;
    // 0x808005CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808005D0:
    // 0x808005D0: b           L_808005D8
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808005D8;
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005D8:
    // 0x808005D8: jr          $ra
    // 0x808005DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808005DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _suexpression_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089818: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089818);
    return;
    // 0x8008981C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_808010A0_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x808010A4: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x808010A8: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x808010AC: xori        $v0, $t7, 0x1CE
    ctx->r2 = ctx->r15 ^ 0X1CE;
    // 0x808010B0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808010B4: bne         $v0, $zero, L_808010D4
    if (ctx->r2 != 0) {
        // 0x808010B8: nop
    
            goto L_808010D4;
    }
    // 0x808010B8: nop

    // 0x808010BC: xori        $v0, $t7, 0x1CF
    ctx->r2 = ctx->r15 ^ 0X1CF;
    // 0x808010C0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808010C4: bne         $v0, $zero, L_808010D4
    if (ctx->r2 != 0) {
        // 0x808010C8: nop
    
            goto L_808010D4;
    }
    // 0x808010C8: nop

    // 0x808010CC: xori        $v0, $t7, 0x4A6
    ctx->r2 = ctx->r15 ^ 0X4A6;
    // 0x808010D0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_808010D4:
    // 0x808010D4: jr          $ra
    // 0x808010D8: nop

    return;
    // 0x808010D8: nop

    // 0x808010DC: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088040: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088040);
    return;
    // 0x80088044: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80111018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011101C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80111024: jal         0x80113410
    // 0x80111028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80113410(rdram, ctx);
        goto after_0;
    // 0x80111028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8011102C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80111030: lh          $a2, 0x7372($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7372);
    // 0x80111034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80111038: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8011103C: addiu       $a2, $a2, -0x98
    ctx->r6 = ADD32(ctx->r6, -0X98);
    // 0x80111040: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x80111044: jal         0x8001BBA0
    // 0x80111048: addiu       $a1, $a1, 0x98
    ctx->r5 = ADD32(ctx->r5, 0X98);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80111048: addiu       $a1, $a1, 0x98
    ctx->r5 = ADD32(ctx->r5, 0X98);
    after_1:
    // 0x8011104C: jal         0x8011337C
    // 0x80111050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8011337C(rdram, ctx);
        goto after_2;
    // 0x80111050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80111054: jal         0x800893D0
    // 0x80111058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _ncba1p_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80111058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8011105C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111064: jr          $ra
    // 0x80111068: nop

    return;
    // 0x80111068: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_52(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D60: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D60);
    return;
    // 0x80082D64: addi        $t0, $zero, 0xD0
    ctx->r8 = ADD32(0, 0XD0);
;}
RECOMP_FUNC void func_80800028_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: lbu         $a1, 0x160($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X160);
    // 0x80800034: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800038: beq         $a1, $zero, L_8080004C
    if (ctx->r5 == 0) {
        // 0x8080003C: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_8080004C;
    }
    // 0x8080003C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800040: jal         0x800C2FDC
    // 0x80800044: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800048: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8080004C:
    // 0x8080004C: sb          $zero, 0x160($a2)
    MEM_B(0X160, ctx->r6) = 0;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void _dbvpl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879A0: syscall     644
    recomp_syscall_handler(rdram, ctx, 0x800879A0);
    return;
    // 0x800879A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_chjiggypost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A568: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A568);
    return;
    // 0x8008A56C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_8080000C_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800EA05C
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800020: jal         0x80105494
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80105494(rdram, ctx);
        goto after_1;
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800044;
    }
    // 0x8080002C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800034: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800038: jal         0x80105A9C
    // 0x8080003C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x8080003C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800040: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80800044:
    // 0x80800044: addiu       $at, $zero, 0xEA
    ctx->r1 = ADD32(0, 0XEA);
    // 0x80800048: beq         $v1, $at, L_80800068
    if (ctx->r3 == ctx->r1) {
        // 0x8080004C: addiu       $at, $zero, 0xEC
        ctx->r1 = ADD32(0, 0XEC);
            goto L_80800068;
    }
    // 0x8080004C: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x80800050: beq         $v1, $at, L_808000C4
    if (ctx->r3 == ctx->r1) {
        // 0x80800054: addiu       $at, $zero, 0x121
        ctx->r1 = ADD32(0, 0X121);
            goto L_808000C4;
    }
    // 0x80800054: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80800058: beq         $v1, $at, L_808000E4
    if (ctx->r3 == ctx->r1) {
        // 0x8080005C: nop
    
            goto L_808000E4;
    }
    // 0x8080005C: nop

    // 0x80800060: b           L_80800110
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800068:
    // 0x80800068: jal         0x800DA298
    // 0x8080006C: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080006C: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_3:
    // 0x80800070: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800074: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80800084;
    }
    // 0x80800074: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800078: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x8080007C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800080: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
L_80800084:
    // 0x80800084: jal         0x800DA298
    // 0x80800088: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_4:
    // 0x8080008C: bne         $v0, $zero, L_808000A4
    if (ctx->r2 != 0) {
        // 0x80800090: nop
    
            goto L_808000A4;
    }
    // 0x80800090: nop

    // 0x80800094: jal         0x800DA298
    // 0x80800098: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_5:
    // 0x8080009C: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x808000A0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000B4;
    }
    // 0x808000A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808000A4:
    // 0x808000A4: jal         0x800FFAB0
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x808000AC: b           L_80800110
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B4:
    // 0x808000B4: jal         0x80102424
    // 0x808000B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808000B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808000BC: b           L_80800110
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C4:
    // 0x808000C4: jal         0x80088840
    // 0x808000C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x808000C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_8:
    // 0x808000CC: bnel        $v0, $zero, L_80800110
    if (ctx->r2 != 0) {
        // 0x808000D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000D4: jal         0x800FFAB0
    // 0x808000D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808000D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808000DC: b           L_80800110
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E4:
    // 0x808000E4: jal         0x800DA298
    // 0x808000E8: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808000E8: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_10:
    // 0x808000EC: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800104;
    }
    // 0x808000F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000F4: jal         0x80102424
    // 0x808000F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808000F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x808000FC: b           L_80800110
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800104:
    // 0x80800104: jal         0x800FFAB0
    // 0x80800108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800110:
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_800E2C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2C54: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E2C58: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800E2C5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E2C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E2C64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2C68: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800E2C6C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800E2C70: beq         $t6, $zero, L_800E2C94
    if (ctx->r14 == 0) {
        // 0x800E2C74: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_800E2C94;
    }
    // 0x800E2C74: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800E2C78: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800E2C7C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800E2C80: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800E2C84: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800E2C88: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800E2C8C: b           L_800E2CAC
    // 0x800E2C90: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_800E2CAC;
    // 0x800E2C90: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_800E2C94:
    // 0x800E2C94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2C98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E2C9C: nop

    // 0x800E2CA0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800E2CA4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800E2CA8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_800E2CAC:
    // 0x800E2CAC: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x800E2CB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800E2CB4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800E2CB8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800E2CBC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800E2CC0: jal         0x800E1C00
    // 0x800E2CC4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800E1C00(rdram, ctx);
        goto after_0;
    // 0x800E2CC4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800E2CC8: bne         $v0, $zero, L_800E2CE0
    if (ctx->r2 != 0) {
        // 0x800E2CCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E2CE0;
    }
    // 0x800E2CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2CD0: jal         0x800E23A4
    // 0x800E2CD4: nop

    func_800E23A4(rdram, ctx);
        goto after_1;
    // 0x800E2CD4: nop

    after_1:
    // 0x800E2CD8: b           L_800E2DE0
    // 0x800E2CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E2DE0;
    // 0x800E2CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E2CE0:
    // 0x800E2CE0: jal         0x800E1DF4
    // 0x800E2CE4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800E1DF4(rdram, ctx);
        goto after_2;
    // 0x800E2CE4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_2:
    // 0x800E2CE8: jal         0x80019CD4
    // 0x800E2CEC: nop

    func_80019CD4(rdram, ctx);
        goto after_3;
    // 0x800E2CEC: nop

    after_3:
    // 0x800E2CF0: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800E2CF4: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800E2CF8: jal         0x800191F8
    // 0x800E2CFC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800191F8(rdram, ctx);
        goto after_4;
    // 0x800E2CFC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800E2D00: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800E2D04: beql        $v0, $zero, L_800E2D20
    if (ctx->r2 == 0) {
        // 0x800E2D08: lw          $t8, 0x68($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X68);
            goto L_800E2D20;
    }
    goto skip_0;
    // 0x800E2D08: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x800E2D0C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E2D10: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800E2D14: jal         0x80019110
    // 0x800E2D18: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    mlMtxRotatePYR(rdram, ctx);
        goto after_5;
    // 0x800E2D18: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_5:
    // 0x800E2D1C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
L_800E2D20:
    // 0x800E2D20: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2D24: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2D28: bne         $t8, $zero, L_800E2D38
    if (ctx->r24 != 0) {
        // 0x800E2D2C: lwc1        $f14, 0x48($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800E2D38;
    }
    // 0x800E2D2C: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800E2D30: beq         $t9, $zero, L_800E2D54
    if (ctx->r25 == 0) {
        // 0x800E2D34: nop
    
            goto L_800E2D54;
    }
    // 0x800E2D34: nop

L_800E2D38:
    // 0x800E2D38: beq         $t0, $zero, L_800E2D4C
    if (ctx->r8 == 0) {
        // 0x800E2D3C: lwc1        $f12, 0x4C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_800E2D4C;
    }
    // 0x800E2D3C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800E2D40: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800E2D44: b           L_800E2D4C
    // 0x800E2D48: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800E2D4C;
    // 0x800E2D48: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800E2D4C:
    // 0x800E2D4C: jal         0x80019D30
    // 0x800E2D50: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    mlMtxScale_xyz(rdram, ctx);
        goto after_6;
    // 0x800E2D50: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_6:
L_800E2D54:
    // 0x800E2D54: jal         0x80018C28
    // 0x800E2D58: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_7;
    // 0x800E2D58: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x800E2D5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2D60: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800E2D64: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800E2D68: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800E2D6C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E2D70: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800E2D74: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800E2D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2D7C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E2D80: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x800E2D84: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x800E2D88: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E2D8C: jal         0x800E204C
    // 0x800E2D90: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800E204C(rdram, ctx);
        goto after_8;
    // 0x800E2D90: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x800E2D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2D98: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800E2D9C: jal         0x800E2180
    // 0x800E2DA0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    func_800E2180(rdram, ctx);
        goto after_9;
    // 0x800E2DA0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x800E2DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2DA8: jal         0x800E2260
    // 0x800E2DAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800E2260(rdram, ctx);
        goto after_10;
    // 0x800E2DAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_10:
    // 0x800E2DB0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2DB4: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800E2DB8: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800E2DBC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E2DC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E2DC4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800E2DC8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E2DCC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E2DD0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800E2DD4: jal         0x800E22F0
    // 0x800E2DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E22F0(rdram, ctx);
        goto after_11;
    // 0x800E2DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800E2DDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E2DE0:
    // 0x800E2DE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2DE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E2DE8: jr          $ra
    // 0x800E2DEC: nop

    return;
    // 0x800E2DEC: nop

;}
RECOMP_FUNC void func_80800840_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080084C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80800850: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80800854: jal         0x80086880
    // 0x80800858: addiu       $a3, $zero, 0x355
    ctx->r7 = ADD32(0, 0X355);
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800858: addiu       $a3, $zero, 0x355
    ctx->r7 = ADD32(0, 0X355);
    after_0:
    // 0x8080085C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800860: jal         0x800868A8
    // 0x80800864: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800864: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_1:
    // 0x80800868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080086C: jal         0x800868B0
    // 0x80800870: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800870: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800878: jal         0x800868C0
    // 0x8080087C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x8080087C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void func_800CF734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CF73C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CF740: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CF744: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CF748: jal         0x800CF640
    // 0x800CF74C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800CF640(rdram, ctx);
        goto after_0;
    // 0x800CF74C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CF750: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x800CF754: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CF758: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CF75C: addiu       $a0, $a0, -0x5580
    ctx->r4 = ADD32(ctx->r4, -0X5580);
    // 0x800CF760: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF764: mflo        $t6
    ctx->r14 = lo;
    // 0x800CF768: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800CF76C: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800CF770: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800CF774: nop

    // 0x800CF778: bc1f        L_800CF798
    if (!c1cs) {
        // 0x800CF77C: nop
    
            goto L_800CF798;
    }
    // 0x800CF77C: nop

    // 0x800CF780: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CF784: mflo        $t8
    ctx->r24 = lo;
    // 0x800CF788: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x800CF78C: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CF790: jal         0x800CF160
    // 0x800CF794: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    func_800CF160(rdram, ctx);
        goto after_1;
    // 0x800CF794: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    after_1:
L_800CF798:
    // 0x800CF798: jal         0x800CEAA8
    // 0x800CF79C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEAA8(rdram, ctx);
        goto after_2;
    // 0x800CF79C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800CF7A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF7A4: blez        $v0, L_800CF7C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CF7A8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800CF7C4;
    }
    // 0x800CF7A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800CF7AC:
    // 0x800CF7AC: jal         0x800CF494
    // 0x800CF7B0: nop

    func_800CF494(rdram, ctx);
        goto after_3;
    // 0x800CF7B0: nop

    after_3:
    // 0x800CF7B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CF7B8: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CF7BC: bne         $at, $zero, L_800CF7AC
    if (ctx->r1 != 0) {
        // 0x800CF7C0: nop
    
            goto L_800CF7AC;
    }
    // 0x800CF7C0: nop

L_800CF7C4:
    // 0x800CF7C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF7C8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF7CC: sh          $s1, -0x4E98($at)
    MEM_H(-0X4E98, ctx->r1) = ctx->r17;
    // 0x800CF7D0: addiu       $a1, $a1, -0x8CC
    ctx->r5 = ADD32(ctx->r5, -0X8CC);
    // 0x800CF7D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF7D8: jal         0x800CE928
    // 0x800CF7DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_4;
    // 0x800CF7DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800CF7E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF7E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CF7E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CF7EC: jr          $ra
    // 0x800CF7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CF7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EECE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EECE0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EECE4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EECE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EECEC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800EECF0: nop

    // 0x800EECF4: bc1f        L_800EED00
    if (!c1cs) {
        // 0x800EECF8: nop
    
            goto L_800EED00;
    }
    // 0x800EECF8: nop

    // 0x800EECFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EED00:
    // 0x800EED00: beq         $v0, $zero, L_800EED50
    if (ctx->r2 == 0) {
        // 0x800EED04: nop
    
            goto L_800EED50;
    }
    // 0x800EED04: nop

    // 0x800EED08: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EED0C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EED10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EED14: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800EED18: nop

    // 0x800EED1C: bc1f        L_800EED28
    if (!c1cs) {
        // 0x800EED20: nop
    
            goto L_800EED28;
    }
    // 0x800EED20: nop

    // 0x800EED24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EED28:
    // 0x800EED28: beq         $v0, $zero, L_800EED50
    if (ctx->r2 == 0) {
        // 0x800EED2C: nop
    
            goto L_800EED50;
    }
    // 0x800EED2C: nop

    // 0x800EED30: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EED34: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EED38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EED3C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800EED40: nop

    // 0x800EED44: bc1f        L_800EED50
    if (!c1cs) {
        // 0x800EED48: nop
    
            goto L_800EED50;
    }
    // 0x800EED48: nop

    // 0x800EED4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EED50:
    // 0x800EED50: jr          $ra
    // 0x800EED54: nop

    return;
    // 0x800EED54: nop

;}
RECOMP_FUNC void babee_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800334: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80800338: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080033C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800340: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800344: nop

    // 0x80800348: bc1fl       L_8080036C
    if (!c1cs) {
        // 0x8080034C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080036C;
    }
    goto skip_0;
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800350: jal         0x800D8FF8
    // 0x80800354: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800354: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80800358: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080035C: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800360: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800364: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080036C:
    // 0x8080036C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800370: jr          $ra
    // 0x80800374: nop

    return;
    // 0x80800374: nop

;}
RECOMP_FUNC void func_80100F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100F0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80100F10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80100F14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100F18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80100F1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100F20: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    // 0x80100F24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100F28: jal         0x800B301C
    // 0x80100F2C: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80100F2C: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    after_0:
    // 0x80100F30: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80100F34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100F38: beq         $t6, $zero, L_80100FF4
    if (ctx->r14 == 0) {
        // 0x80100F3C: andi        $a1, $t6, 0xFF
        ctx->r5 = ctx->r14 & 0XFF;
            goto L_80100FF4;
    }
    // 0x80100F3C: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x80100F40: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    // 0x80100F44: jal         0x800B301C
    // 0x80100F48: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    freelist_at(rdram, ctx);
        goto after_1;
    // 0x80100F48: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80100F4C: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x80100F50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100F54: beql        $t7, $zero, L_80100FF8
    if (ctx->r15 == 0) {
        // 0x80100F58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80100FF8;
    }
    goto skip_0;
    // 0x80100F58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80100F5C: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80100F60: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80100F64: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80100F68: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80100F6C: slti        $at, $t9, 0x3666
    ctx->r1 = SIGNED(ctx->r25) < 0X3666 ? 1 : 0;
    // 0x80100F70: beq         $at, $zero, L_80100F9C
    if (ctx->r1 == 0) {
        // 0x80100F74: nop
    
            goto L_80100F9C;
    }
    // 0x80100F74: nop

    // 0x80100F78: jal         0x80100938
    // 0x80100F7C: lbu         $a0, 0x8($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X8);
    func_80100938(rdram, ctx);
        goto after_2;
    // 0x80100F7C: lbu         $a0, 0x8($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X8);
    after_2:
    // 0x80100F80: jal         0x801006E0
    // 0x80100F84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_801006E0(rdram, ctx);
        goto after_3;
    // 0x80100F84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80100F88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80100F8C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80100F90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100F94: b           L_80100FA4
    // 0x80100F98: sb          $t1, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r9;
        goto L_80100FA4;
    // 0x80100F98: sb          $t1, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r9;
L_80100F9C:
    // 0x80100F9C: jal         0x800887A0
    // 0x80100FA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _glpackvtx_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80100FA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
L_80100FA4:
    // 0x80100FA4: jal         0x800D674C
    // 0x80100FA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80100FA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80100FAC: jal         0x800B2840
    // 0x80100FB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2840(rdram, ctx);
        goto after_6;
    // 0x80100FB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80100FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100FB8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80100FBC: jal         0x80088798
    // 0x80100FC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _glpackvtx_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80100FC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80100FC4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80100FC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80100FCC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80100FD0: addiu       $v1, $v1, 0x5A60
    ctx->r3 = ADD32(ctx->r3, 0X5A60);
    // 0x80100FD4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x80100FD8: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x80100FDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80100FE0: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x80100FE4: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80100FE8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80100FEC: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80100FF0: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_80100FF4:
    // 0x80100FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80100FF8:
    // 0x80100FF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100FFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80101000: jr          $ra
    // 0x80101004: nop

    return;
    // 0x80101004: nop

    // 0x80101008: nop

    // 0x8010100C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC8: jal         0x80110024
    // 0x80800ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800ED0: jal         0x80089638
    // 0x80800ED4: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800ED4: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800ED8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EDC: jal         0x80089670
    // 0x80800EE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _ncpoducam_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800EE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EEC: jr          $ra
    // 0x80800EF0: nop

    return;
    // 0x80800EF0: nop

;}
RECOMP_FUNC void func_80100B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100B3C: addiu       $t6, $zero, 0x3667
    ctx->r14 = ADD32(0, 0X3667);
    // 0x80100B40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100B44: jr          $ra
    // 0x80100B48: sw          $t6, 0x5A68($at)
    MEM_W(0X5A68, ctx->r1) = ctx->r14;
    return;
    // 0x80100B48: sw          $t6, 0x5A68($at)
    MEM_W(0X5A68, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800C810C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C810C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C8114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8118: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800C811C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C8120: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C8124: jal         0x800C7980
    // 0x800C8128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C7980(rdram, ctx);
        goto after_0;
    // 0x800C8128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C812C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C8130: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C8134: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C8138: lbu         $a1, 0x2($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2);
    // 0x800C813C: jalr        $v0
    // 0x800C8140: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800C8140: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x800C8144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C8148: jal         0x800F1A88
    // 0x800C814C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F1A88(rdram, ctx);
        goto after_2;
    // 0x800C814C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800C8150: jal         0x800136E4
    // 0x800C8154: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x800C8154: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x800C8158: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C815C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8160: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C8164: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800C8168: jal         0x800136E4
    // 0x800C816C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x800C816C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x800C8170: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C8174: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800C8178: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800C817C: jal         0x800EF2A0
    // 0x800C8180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EF2A0(rdram, ctx);
        goto after_5;
    // 0x800C8180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800C8184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C818C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8190: jr          $ra
    // 0x800C8194: nop

    return;
    // 0x800C8194: nop

;}
RECOMP_FUNC void func_800CFC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFC8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CFC90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CFC94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CFC98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CFC9C: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x800CFCA0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800CFCA4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800CFCA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CFCAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CFCB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CFCB4: beq         $at, $zero, L_800CFF98
    if (ctx->r1 == 0) {
        // 0x800CFCB8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800CFF98;
    }
    // 0x800CFCB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CFCBC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CFCC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CFCC4: addu        $at, $at, $t6
    gpr jr_addend_800CFCCC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CFCC8: lw          $t6, 0x59D0($at)
    ctx->r14 = ADD32(ctx->r1, 0X59D0);
    // 0x800CFCCC: jr          $t6
    // 0x800CFCD0: nop

    switch (jr_addend_800CFCCC >> 2) {
        case 0: goto L_800CFCD4; break;
        case 1: goto L_800CFD38; break;
        case 2: goto L_800CFD98; break;
        case 3: goto L_800CFDF8; break;
        case 4: goto L_800CFE58; break;
        case 5: goto L_800CFEB8; break;
        case 6: goto L_800CFED8; break;
        case 7: goto L_800CFF58; break;
        case 8: goto L_800CFF78; break;
        default: switch_error(__func__, 0x800CFCCC, 0x801259D0);
    }
    // 0x800CFCD0: nop

L_800CFCD4:
    // 0x800CFCD4: jal         0x800D0820
    // 0x800CFCD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800CFCD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800CFCDC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFCE0: jal         0x800D0894
    // 0x800CFCE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800CFCE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x800CFCE8: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFCEC: bne         $at, $zero, L_800CFD30
    if (ctx->r1 != 0) {
        // 0x800CFCF0: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_800CFD30;
    }
    // 0x800CFCF0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800CFCF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CFCF8: addiu       $t8, $t8, -0x54C0
    ctx->r24 = ADD32(ctx->r24, -0X54C0);
    // 0x800CFCFC: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x800CFD00: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800CFD04: lbu         $t9, -0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X3);
L_800CFD08:
    // 0x800CFD08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFD0C: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x800CFD10: bne         $s4, $t9, L_800CFD1C
    if (ctx->r20 != ctx->r25) {
        // 0x800CFD14: nop
    
            goto L_800CFD1C;
    }
    // 0x800CFD14: nop

    // 0x800CFD18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800CFD1C:
    // 0x800CFD1C: jal         0x800D0894
    // 0x800CFD20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_2;
    // 0x800CFD20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x800CFD24: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFD28: beql        $at, $zero, L_800CFD08
    if (ctx->r1 == 0) {
        // 0x800CFD2C: lbu         $t9, -0x3($s0)
        ctx->r25 = MEM_BU(ctx->r16, -0X3);
            goto L_800CFD08;
    }
    goto skip_0;
    // 0x800CFD2C: lbu         $t9, -0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X3);
    skip_0:
L_800CFD30:
    // 0x800CFD30: b           L_800CFF9C
    // 0x800CFD34: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFD34: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFD38:
    // 0x800CFD38: jal         0x800D0820
    // 0x800CFD3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_3;
    // 0x800CFD3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x800CFD40: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFD44: jal         0x800D0894
    // 0x800CFD48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_4;
    // 0x800CFD48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800CFD4C: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFD50: bne         $at, $zero, L_800CFD90
    if (ctx->r1 != 0) {
        // 0x800CFD54: sll         $t0, $s1, 1
        ctx->r8 = S32(ctx->r17 << 1);
            goto L_800CFD90;
    }
    // 0x800CFD54: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x800CFD58: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CFD5C: addiu       $t1, $t1, -0x5438
    ctx->r9 = ADD32(ctx->r9, -0X5438);
    // 0x800CFD60: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x800CFD64: lbu         $t2, -0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, -0X2);
L_800CFD68:
    // 0x800CFD68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFD6C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CFD70: bne         $s4, $t2, L_800CFD7C
    if (ctx->r20 != ctx->r10) {
        // 0x800CFD74: nop
    
            goto L_800CFD7C;
    }
    // 0x800CFD74: nop

    // 0x800CFD78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800CFD7C:
    // 0x800CFD7C: jal         0x800D0894
    // 0x800CFD80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_5;
    // 0x800CFD80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800CFD84: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFD88: beql        $at, $zero, L_800CFD68
    if (ctx->r1 == 0) {
        // 0x800CFD8C: lbu         $t2, -0x2($s0)
        ctx->r10 = MEM_BU(ctx->r16, -0X2);
            goto L_800CFD68;
    }
    goto skip_1;
    // 0x800CFD8C: lbu         $t2, -0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, -0X2);
    skip_1:
L_800CFD90:
    // 0x800CFD90: b           L_800CFF9C
    // 0x800CFD94: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFD94: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFD98:
    // 0x800CFD98: jal         0x800D0820
    // 0x800CFD9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_6;
    // 0x800CFD9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800CFDA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFDA4: jal         0x800D0894
    // 0x800CFDA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_7;
    // 0x800CFDA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x800CFDAC: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFDB0: bne         $at, $zero, L_800CFDF0
    if (ctx->r1 != 0) {
        // 0x800CFDB4: sll         $t3, $s1, 1
        ctx->r11 = S32(ctx->r17 << 1);
            goto L_800CFDF0;
    }
    // 0x800CFDB4: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800CFDB8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CFDBC: addiu       $t4, $t4, -0x5384
    ctx->r12 = ADD32(ctx->r12, -0X5384);
    // 0x800CFDC0: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x800CFDC4: lbu         $t5, -0x2($s0)
    ctx->r13 = MEM_BU(ctx->r16, -0X2);
L_800CFDC8:
    // 0x800CFDC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFDCC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CFDD0: bne         $s4, $t5, L_800CFDDC
    if (ctx->r20 != ctx->r13) {
        // 0x800CFDD4: nop
    
            goto L_800CFDDC;
    }
    // 0x800CFDD4: nop

    // 0x800CFDD8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800CFDDC:
    // 0x800CFDDC: jal         0x800D0894
    // 0x800CFDE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_8;
    // 0x800CFDE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x800CFDE4: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFDE8: beql        $at, $zero, L_800CFDC8
    if (ctx->r1 == 0) {
        // 0x800CFDEC: lbu         $t5, -0x2($s0)
        ctx->r13 = MEM_BU(ctx->r16, -0X2);
            goto L_800CFDC8;
    }
    goto skip_2;
    // 0x800CFDEC: lbu         $t5, -0x2($s0)
    ctx->r13 = MEM_BU(ctx->r16, -0X2);
    skip_2:
L_800CFDF0:
    // 0x800CFDF0: b           L_800CFF9C
    // 0x800CFDF4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFDF4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFDF8:
    // 0x800CFDF8: jal         0x800D0820
    // 0x800CFDFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_9;
    // 0x800CFDFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x800CFE00: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFE04: jal         0x800D0894
    // 0x800CFE08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_10;
    // 0x800CFE08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x800CFE0C: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFE10: bne         $at, $zero, L_800CFE50
    if (ctx->r1 != 0) {
        // 0x800CFE14: sll         $t6, $s1, 1
        ctx->r14 = S32(ctx->r17 << 1);
            goto L_800CFE50;
    }
    // 0x800CFE14: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x800CFE18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CFE1C: addiu       $t7, $t7, -0x5350
    ctx->r15 = ADD32(ctx->r15, -0X5350);
    // 0x800CFE20: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800CFE24: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
L_800CFE28:
    // 0x800CFE28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFE2C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CFE30: bne         $s4, $t8, L_800CFE3C
    if (ctx->r20 != ctx->r24) {
        // 0x800CFE34: nop
    
            goto L_800CFE3C;
    }
    // 0x800CFE34: nop

    // 0x800CFE38: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800CFE3C:
    // 0x800CFE3C: jal         0x800D0894
    // 0x800CFE40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_11;
    // 0x800CFE40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x800CFE44: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFE48: beql        $at, $zero, L_800CFE28
    if (ctx->r1 == 0) {
        // 0x800CFE4C: lbu         $t8, -0x2($s0)
        ctx->r24 = MEM_BU(ctx->r16, -0X2);
            goto L_800CFE28;
    }
    goto skip_3;
    // 0x800CFE4C: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
    skip_3:
L_800CFE50:
    // 0x800CFE50: b           L_800CFF9C
    // 0x800CFE54: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFE54: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFE58:
    // 0x800CFE58: jal         0x800D0820
    // 0x800CFE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_12;
    // 0x800CFE5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x800CFE60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFE64: jal         0x800D0894
    // 0x800CFE68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_13;
    // 0x800CFE68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x800CFE6C: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFE70: bne         $at, $zero, L_800CFEB0
    if (ctx->r1 != 0) {
        // 0x800CFE74: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_800CFEB0;
    }
    // 0x800CFE74: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x800CFE78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CFE7C: addiu       $t0, $t0, -0x532C
    ctx->r8 = ADD32(ctx->r8, -0X532C);
    // 0x800CFE80: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x800CFE84: lbu         $t1, -0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, -0X2);
L_800CFE88:
    // 0x800CFE88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFE8C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CFE90: bne         $s4, $t1, L_800CFE9C
    if (ctx->r20 != ctx->r9) {
        // 0x800CFE94: nop
    
            goto L_800CFE9C;
    }
    // 0x800CFE94: nop

    // 0x800CFE98: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800CFE9C:
    // 0x800CFE9C: jal         0x800D0894
    // 0x800CFEA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_14;
    // 0x800CFEA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x800CFEA4: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFEA8: beql        $at, $zero, L_800CFE88
    if (ctx->r1 == 0) {
        // 0x800CFEAC: lbu         $t1, -0x2($s0)
        ctx->r9 = MEM_BU(ctx->r16, -0X2);
            goto L_800CFE88;
    }
    goto skip_4;
    // 0x800CFEAC: lbu         $t1, -0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, -0X2);
    skip_4:
L_800CFEB0:
    // 0x800CFEB0: b           L_800CFF9C
    // 0x800CFEB4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFEB4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFEB8:
    // 0x800CFEB8: jal         0x800D0894
    // 0x800CFEBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_15;
    // 0x800CFEBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
    // 0x800CFEC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CFEC4: jal         0x800D0820
    // 0x800CFEC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_16;
    // 0x800CFEC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x800CFECC: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x800CFED0: b           L_800CFF9C
    // 0x800CFED4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800CFF9C;
    // 0x800CFED4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800CFED8:
    // 0x800CFED8: jal         0x800D0820
    // 0x800CFEDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_17;
    // 0x800CFEDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x800CFEE0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CFEE4: jal         0x800D0894
    // 0x800CFEE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_18;
    // 0x800CFEE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
    // 0x800CFEEC: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFEF0: bne         $at, $zero, L_800CFF50
    if (ctx->r1 != 0) {
        // 0x800CFEF4: sll         $t2, $s1, 1
        ctx->r10 = S32(ctx->r17 << 1);
            goto L_800CFF50;
    }
    // 0x800CFEF4: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x800CFEF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CFEFC: addiu       $t3, $t3, -0x52F8
    ctx->r11 = ADD32(ctx->r11, -0X52F8);
    // 0x800CFF00: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x800CFF04: lbu         $t4, -0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, -0X2);
L_800CFF08:
    // 0x800CFF08: bnel        $s4, $t4, L_800CFF38
    if (ctx->r20 != ctx->r12) {
        // 0x800CFF0C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800CFF38;
    }
    goto skip_5;
    // 0x800CFF0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x800CFF10: lbu         $t5, -0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, -0X1);
    // 0x800CFF14: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    // 0x800CFF18: beq         $t5, $zero, L_800CFF28
    if (ctx->r13 == 0) {
        // 0x800CFF1C: nop
    
            goto L_800CFF28;
    }
    // 0x800CFF1C: nop

    // 0x800CFF20: b           L_800CFF28
    // 0x800CFF24: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
        goto L_800CFF28;
    // 0x800CFF24: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
L_800CFF28:
    // 0x800CFF28: jal         0x80085AD8
    // 0x800CFF2C: nop

    _chnests_entrypoint_13(rdram, ctx);
        goto after_19;
    // 0x800CFF2C: nop

    after_19:
    // 0x800CFF30: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x800CFF34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CFF38:
    // 0x800CFF38: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CFF3C: jal         0x800D0894
    // 0x800CFF40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_20;
    // 0x800CFF40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_20:
    // 0x800CFF44: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800CFF48: beql        $at, $zero, L_800CFF08
    if (ctx->r1 == 0) {
        // 0x800CFF4C: lbu         $t4, -0x2($s0)
        ctx->r12 = MEM_BU(ctx->r16, -0X2);
            goto L_800CFF08;
    }
    goto skip_6;
    // 0x800CFF4C: lbu         $t4, -0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, -0X2);
    skip_6:
L_800CFF50:
    // 0x800CFF50: b           L_800CFF9C
    // 0x800CFF54: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CFF9C;
    // 0x800CFF54: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CFF58:
    // 0x800CFF58: jal         0x800D0894
    // 0x800CFF5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_21;
    // 0x800CFF5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x800CFF60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CFF64: jal         0x800D0820
    // 0x800CFF68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_22;
    // 0x800CFF68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_22:
    // 0x800CFF6C: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x800CFF70: b           L_800CFF9C
    // 0x800CFF74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800CFF9C;
    // 0x800CFF74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800CFF78:
    // 0x800CFF78: jal         0x800D0894
    // 0x800CFF7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0894(rdram, ctx);
        goto after_23;
    // 0x800CFF7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_23:
    // 0x800CFF80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CFF84: jal         0x800D0820
    // 0x800CFF88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800D0820(rdram, ctx);
        goto after_24;
    // 0x800CFF88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_24:
    // 0x800CFF8C: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x800CFF90: b           L_800CFF9C
    // 0x800CFF94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800CFF9C;
    // 0x800CFF94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800CFF98:
    // 0x800CFF98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CFF9C:
    // 0x800CFF9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFFA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CFFA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFFA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CFFAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CFFB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CFFB4: jr          $ra
    // 0x800CFFB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CFFB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800E90D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E90D8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800E90DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E90E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800E90E4: lhu         $t8, 0x2560($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2560);
    // 0x800E90E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E90EC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800E90F0: addu        $v0, $t8, $a1
    ctx->r2 = ADD32(ctx->r24, ctx->r5);
    // 0x800E90F4: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x800E90F8: addu        $t4, $t2, $a2
    ctx->r12 = ADD32(ctx->r10, ctx->r6);
    // 0x800E90FC: addiu       $t5, $t5, 0x2650
    ctx->r13 = ADD32(ctx->r13, 0X2650);
    // 0x800E9100: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800E9104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9108: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E910C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E9110: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E9114: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800E9118: lbu         $v1, 0x0($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X0);
    // 0x800E911C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800E9120: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E9124: beq         $v1, $at, L_800E916C
    if (ctx->r3 == ctx->r1) {
        // 0x800E9128: addiu       $t1, $t1, -0x2970
        ctx->r9 = ADD32(ctx->r9, -0X2970);
            goto L_800E916C;
    }
    // 0x800E9128: addiu       $t1, $t1, -0x2970
    ctx->r9 = ADD32(ctx->r9, -0X2970);
    // 0x800E912C: jal         0x8001211C
    // 0x800E9130: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x800E9130: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x800E9134: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800E9138: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E913C: addiu       $t1, $t1, -0x2970
    ctx->r9 = ADD32(ctx->r9, -0X2970);
    // 0x800E9140: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800E9144: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x800E9148: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E914C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800E9150: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x800E9154: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x800E9158: sw          $v0, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->r2;
    // 0x800E915C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800E9160: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x800E9164: b           L_800E92F0
    // 0x800E9168: addiu       $v0, $v0, 0x3A8
    ctx->r2 = ADD32(ctx->r2, 0X3A8);
        goto L_800E92F0;
    // 0x800E9168: addiu       $v0, $v0, 0x3A8
    ctx->r2 = ADD32(ctx->r2, 0X3A8);
L_800E916C:
    // 0x800E916C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800E9170: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800E9174: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800E9178: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x800E917C: addiu       $t4, $t4, 0x351C
    ctx->r12 = ADD32(ctx->r12, 0X351C);
    // 0x800E9180: addiu       $t3, $t3, 0x3514
    ctx->r11 = ADD32(ctx->r11, 0X3514);
    // 0x800E9184: addu        $a3, $v0, $t3
    ctx->r7 = ADD32(ctx->r2, ctx->r11);
    // 0x800E9188: addu        $a2, $v0, $t4
    ctx->r6 = ADD32(ctx->r2, ctx->r12);
    // 0x800E918C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800E9190: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800E9194: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x800E9198: lw          $t5, 0x4EC8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4EC8);
    // 0x800E919C: subu        $t6, $v1, $a1
    ctx->r14 = SUB32(ctx->r3, ctx->r5);
    // 0x800E91A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E91A4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800E91A8: bnel        $at, $zero, L_800E9238
    if (ctx->r1 != 0) {
        // 0x800E91AC: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E9238;
    }
    goto skip_0;
    // 0x800E91AC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x800E91B0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800E91B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800E91B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800E91BC: jal         0x800E95AC
    // 0x800E91C0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800E95AC(rdram, ctx);
        goto after_1;
    // 0x800E91C0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x800E91C4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E91C8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800E91CC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800E91D0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800E91D4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800E91D8: lw          $t7, 0x4EC8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4EC8);
    // 0x800E91DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E91E0: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x800E91E4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800E91E8: bne         $at, $zero, L_800E9234
    if (ctx->r1 != 0) {
        // 0x800E91EC: addiu       $t1, $t1, -0x2970
        ctx->r9 = ADD32(ctx->r9, -0X2970);
            goto L_800E9234;
    }
    // 0x800E91EC: addiu       $t1, $t1, -0x2970
    ctx->r9 = ADD32(ctx->r9, -0X2970);
    // 0x800E91F0: jal         0x8001211C
    // 0x800E91F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800E91F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x800E91F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E91FC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E9200: addiu       $t1, $t1, -0x2970
    ctx->r9 = ADD32(ctx->r9, -0X2970);
    // 0x800E9204: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800E9208: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x800E920C: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x800E9210: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E9214: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800E9218: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x800E921C: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x800E9220: sw          $v0, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r2;
    // 0x800E9224: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800E9228: addu        $v0, $t1, $t4
    ctx->r2 = ADD32(ctx->r9, ctx->r12);
    // 0x800E922C: b           L_800E92F0
    // 0x800E9230: addiu       $v0, $v0, 0x3A8
    ctx->r2 = ADD32(ctx->r2, 0X3A8);
        goto L_800E92F0;
    // 0x800E9230: addiu       $v0, $v0, 0x3A8
    ctx->r2 = ADD32(ctx->r2, 0X3A8);
L_800E9234:
    // 0x800E9234: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800E9238:
    // 0x800E9238: beq         $at, $zero, L_800E9268
    if (ctx->r1 == 0) {
        // 0x800E923C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800E9268;
    }
    // 0x800E923C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E9240: sll         $t5, $a1, 1
    ctx->r13 = S32(ctx->r5 << 1);
    // 0x800E9244: addu        $v0, $t1, $t5
    ctx->r2 = ADD32(ctx->r9, ctx->r13);
    // 0x800E9248: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800E924C:
    // 0x800E924C: lh          $t6, 0x190($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X190);
    // 0x800E9250: beql        $a1, $t6, L_800E926C
    if (ctx->r5 == ctx->r14) {
        // 0x800E9254: sll         $t2, $a0, 1
        ctx->r10 = S32(ctx->r4 << 1);
            goto L_800E926C;
    }
    goto skip_1;
    // 0x800E9254: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    skip_1:
    // 0x800E9258: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E925C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E9260: bne         $at, $zero, L_800E924C
    if (ctx->r1 != 0) {
        // 0x800E9264: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800E924C;
    }
    // 0x800E9264: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800E9268:
    // 0x800E9268: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
L_800E926C:
    // 0x800E926C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800E9270: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800E9274: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E9278: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E927C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800E9280: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800E9284: jal         0x800E8F8C
    // 0x800E9288: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800E8F8C(rdram, ctx);
        goto after_3;
    // 0x800E9288: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // 0x800E928C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800E9290: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800E9294: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800E9298: sh          $t7, 0x190($v0)
    MEM_H(0X190, ctx->r2) = ctx->r15;
    // 0x800E929C: jal         0x8001211C
    // 0x800E92A0: sh          $t8, 0x230($v0)
    MEM_H(0X230, ctx->r2) = ctx->r24;
    func_8001211C(rdram, ctx);
        goto after_4;
    // 0x800E92A0: sh          $t8, 0x230($v0)
    MEM_H(0X230, ctx->r2) = ctx->r24;
    after_4:
    // 0x800E92A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800E92A8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E92AC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800E92B0: addiu       $t1, $t1, -0x2970
    ctx->r9 = ADD32(ctx->r9, -0X2970);
    // 0x800E92B4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800E92B8: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x800E92BC: sw          $v0, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r2;
    // 0x800E92C0: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x800E92C4: lw          $t4, 0x4EC8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4EC8);
    // 0x800E92C8: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800E92CC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800E92D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800E92D4: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800E92D8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800E92DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800E92E0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800E92E4: sw          $t5, 0x4EC8($t0)
    MEM_W(0X4EC8, ctx->r8) = ctx->r13;
    // 0x800E92E8: addiu       $v0, $v0, 0x3A8
    ctx->r2 = ADD32(ctx->r2, 0X3A8);
    // 0x800E92EC: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
L_800E92F0:
    // 0x800E92F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E92F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E92F8: jr          $ra
    // 0x800E92FC: nop

    return;
    // 0x800E92FC: nop

;}
RECOMP_FUNC void capod_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800074: jal         0x8008FFE8
    // 0x80800078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080007C: jal         0x80110024
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800084: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800088: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800098;
    }
    // 0x80800088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080008C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: jal         0x80089500
    // 0x80800094: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800094: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800098:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_80800108_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080010C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800114: jal         0x8009E6EC
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080011C: slti        $at, $v0, 0x26
    ctx->r1 = SIGNED(ctx->r2) < 0X26 ? 1 : 0;
    // 0x80800120: bne         $at, $zero, L_8080013C
    if (ctx->r1 != 0) {
        // 0x80800124: addiu       $t6, $v0, -0x15
        ctx->r14 = ADD32(ctx->r2, -0X15);
            goto L_8080013C;
    }
    // 0x80800124: addiu       $t6, $v0, -0x15
    ctx->r14 = ADD32(ctx->r2, -0X15);
    // 0x80800128: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x8080012C: beql        $v0, $at, L_80800174
    if (ctx->r2 == ctx->r1) {
        // 0x80800130: lw          $t7, 0x160($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X160);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800130: lw          $t7, 0x160($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x80800134: b           L_808001C8
    // 0x80800138: nop

        goto L_808001C8;
    // 0x80800138: nop

L_8080013C:
    // 0x8080013C: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x80800140: beq         $at, $zero, L_808001C8
    if (ctx->r1 == 0) {
        // 0x80800144: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808001C8;
    }
    // 0x80800144: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(248, 0X490) << 16);
    // 0x8080014C: addu        $at, $at, $t6
    gpr jr_addend_80800154 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800150: lw          $t6, 0x490($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(248, 0X490));
    // 0x80800154: jr          $t6
    // 0x80800158: nop

    switch (jr_addend_80800154 >> 2) {
        case 0: goto L_8080015C; break;
        case 1: goto L_808001C8; break;
        case 2: goto L_808001C8; break;
        case 3: goto L_808001C8; break;
        case 4: goto L_808001C8; break;
        case 5: goto L_808001C8; break;
        case 6: goto L_808001C8; break;
        case 7: goto L_8080015C; break;
        case 8: goto L_8080015C; break;
        case 9: goto L_8080015C; break;
        case 10: goto L_808001C8; break;
        case 11: goto L_808001C8; break;
        case 12: goto L_808001C8; break;
        case 13: goto L_808001C8; break;
        case 14: goto L_808001C8; break;
        case 15: goto L_808001C8; break;
        case 16: goto L_8080015C; break;
        default: switch_error(__func__, 0x80800154, 0x80800490);
    }
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x8009E830
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800168: b           L_808001D4
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001D4;
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: lw          $t7, 0x160($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X160);
L_80800174:
    // 0x80800174: bnel        $t7, $zero, L_808001B8
    if (ctx->r15 != 0) {
        // 0x80800178: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B8;
    }
    goto skip_1;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080017C: jal         0x80099A4C
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_2;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800184: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80800190: jal         0x8010114C
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800198: bgtzl       $v0, L_808001AC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8080019C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001AC;
    }
    goto skip_2;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808001A0: jal         0x800FC660
    // 0x808001A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808001A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001AC:
    // 0x808001AC: jal         0x8009B800
    // 0x808001B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_5;
    // 0x808001B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001B8:
    // 0x808001B8: jal         0x8009E830
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_6;
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001C0: b           L_808001D4
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001D4;
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001C8:
    // 0x808001C8: jal         0x80099B94
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D4:
    // 0x808001D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void func_80800110_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: addiu       $t6, $zero, 0x7B
    ctx->r14 = ADD32(0, 0X7B);
    // 0x8080011C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800120: jal         0x80800030
    // 0x80800124: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    func_80800030_chminegrill2switches(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    after_0:
    // 0x80800128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void _chamazongoldhordeofficial_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F08: syscall     472
    recomp_syscall_handler(rdram, ctx, 0x80086F08);
    return;
    // 0x80086F0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _suquiz_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A838: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A838);
    return;
    // 0x8008A83C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _glcutDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887B8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887B8);
    return;
    // 0x800887BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D50: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D50);
    return;
    // 0x80087D54: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_800DADEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DADEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DADF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DADF4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800DADF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DADFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DAE00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800DAE04: lwc1        $f4, -0x3898($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3898);
    // 0x800DAE08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DAE0C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800DAE10: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800DAE14: nop

    // 0x800DAE18: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800DAE1C: beql        $v0, $zero, L_800DAE84
    if (ctx->r2 == 0) {
        // 0x800DAE20: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_800DAE84;
    }
    goto skip_0;
    // 0x800DAE20: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x800DAE24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DAE28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DAE2C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DAE30: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800DAE34: nop

    // 0x800DAE38: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800DAE3C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800DAE40: nop

    // 0x800DAE44: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800DAE48: bnel        $v0, $zero, L_800DAE70
    if (ctx->r2 != 0) {
        // 0x800DAE4C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800DAE70;
    }
    goto skip_1;
    // 0x800DAE4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800DAE50: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800DAE54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DAE58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DAE5C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800DAE60: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x800DAE64: jr          $ra
    // 0x800DAE68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800DAE68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800DAE6C:
    // 0x800DAE6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800DAE70:
    // 0x800DAE70: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x800DAE74: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DAE78: jr          $ra
    // 0x800DAE7C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800DAE7C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800DAE80: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_800DAE84:
    // 0x800DAE84: nop

    // 0x800DAE88: bltz        $v0, L_800DAE6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800DAE8C: andi        $t8, $v0, 0xFFFF
        ctx->r24 = ctx->r2 & 0XFFFF;
            goto L_800DAE6C;
    }
    // 0x800DAE8C: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x800DAE90: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DAE94: jr          $ra
    // 0x800DAE98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800DAE98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void sucoasterflydata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800004: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(3286, 0X290) << 16);
    // 0x80800008: lhu         $t8, 0x290($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(3286, 0X290));
    // 0x8080000C: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80800010: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800014: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80800018: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x8080001C: bne         $t7, $t8, L_8080002C
    if (ctx->r15 != ctx->r24) {
        // 0x80800020: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8080002C;
    }
    // 0x80800020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800024: jr          $ra
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080002C:
    // 0x8080002C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80800030: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(3286, 0X290) << 16);
    // 0x80800034: addiu       $t0, $t0, 0x290
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(3286, 0X290));
    // 0x80800038: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8080003C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80800040: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x80800044: bnel        $v0, $t1, L_80800058
    if (ctx->r2 != ctx->r9) {
        // 0x80800048: lhu         $t2, 0x28($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X28);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800048: lhu         $t2, 0x28($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X28);
    skip_0:
    // 0x8080004C: jr          $ra
    // 0x80800050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800054: lhu         $t2, 0x28($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X28);
L_80800058:
    // 0x80800058: bnel        $v0, $t2, L_8080006C
    if (ctx->r2 != ctx->r10) {
        // 0x8080005C: lhu         $t3, 0x50($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X50);
            goto L_8080006C;
    }
    goto skip_1;
    // 0x8080005C: lhu         $t3, 0x50($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X50);
    skip_1:
    // 0x80800060: jr          $ra
    // 0x80800064: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800064: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80800068: lhu         $t3, 0x50($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X50);
L_8080006C:
    // 0x8080006C: bnel        $v0, $t3, L_80800080
    if (ctx->r2 != ctx->r11) {
        // 0x80800070: lhu         $t4, 0x78($a0)
        ctx->r12 = MEM_HU(ctx->r4, 0X78);
            goto L_80800080;
    }
    goto skip_2;
    // 0x80800070: lhu         $t4, 0x78($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X78);
    skip_2:
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x80800078: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x8080007C: lhu         $t4, 0x78($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X78);
L_80800080:
    // 0x80800080: bnel        $v0, $t4, L_80800094
    if (ctx->r2 != ctx->r12) {
        // 0x80800084: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800094;
    }
    goto skip_3;
    // 0x80800084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80800088: jr          $ra
    // 0x8080008C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x8080008C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800094:
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D30: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D30);
    return;
    // 0x80089D34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089978: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089978);
    return;
    // 0x8008997C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800EF6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF6A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800EF6AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EF6B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800EF6B4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EF6B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800EF6BC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800EF6C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800EF6C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF6C8: jal         0x800137F4
    // 0x800EF6CC: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EF6CC: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    after_0:
    // 0x800EF6D0: jal         0x80013788
    // 0x800EF6D4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EF6D4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800EF6D8: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800EF6DC: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800EF6E0: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF6E4: nop

    // 0x800EF6E8: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF6EC: nop

    // 0x800EF6F0: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF6F4: nop

    // 0x800EF6F8: mul.s       $f16, $f14, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF6FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF700: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800EF704: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EF708: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800EF70C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800EF710: jal         0x800137F4
    // 0x800EF714: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x800EF714: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x800EF718: jal         0x80013788
    // 0x800EF71C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x800EF71C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800EF720: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF724: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF728: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF72C: nop

    // 0x800EF730: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF734: nop

    // 0x800EF738: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF73C: nop

    // 0x800EF740: mul.s       $f16, $f14, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF744: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF748: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EF74C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EF750: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800EF754: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800EF758: jal         0x800137F4
    // 0x800EF75C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    func_800137F4(rdram, ctx);
        goto after_4;
    // 0x800EF75C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_4:
    // 0x800EF760: jal         0x80013788
    // 0x800EF764: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_5;
    // 0x800EF764: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800EF768: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EF76C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EF770: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF774: nop

    // 0x800EF778: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF77C: nop

    // 0x800EF780: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF784: nop

    // 0x800EF788: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800EF78C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF790: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800EF794: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EF798: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800EF79C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EF7A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800EF7A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EF7A8: jr          $ra
    // 0x800EF7AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800EF7AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
