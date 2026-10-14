#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80104130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104130: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80104134: jr          $ra
    // 0x80104138: addiu       $v0, $v0, 0x6BF8
    ctx->r2 = ADD32(ctx->r2, 0X6BF8);
    return;
    // 0x80104138: addiu       $v0, $v0, 0x6BF8
    ctx->r2 = ADD32(ctx->r2, 0X6BF8);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CF0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CF0);
    return;
    // 0x80082CF4: addi        $t0, $zero, 0x98
    ctx->r8 = ADD32(0, 0X98);
;}
RECOMP_FUNC void _chdinoboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086008: syscall     270
    recomp_syscall_handler(rdram, ctx, 0x80086008);
    return;
    // 0x8008600C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chdinocoaster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086030: syscall     273
    recomp_syscall_handler(rdram, ctx, 0x80086030);
    return;
    // 0x80086034: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80012F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F6C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012F70: jr          $ra
    // 0x80012F74: addiu       $v0, $v0, 0x6940
    ctx->r2 = ADD32(ctx->r2, 0X6940);
    return;
    // 0x80012F74: addiu       $v0, $v0, 0x6940
    ctx->r2 = ADD32(ctx->r2, 0X6940);
;}
RECOMP_FUNC void _chevilmumbo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BC8: syscall     426
    recomp_syscall_handler(rdram, ctx, 0x80086BC8);
    return;
    // 0x80086BCC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80804488_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804488: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080448C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804490: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80804494: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80804498: jal         0x800919F4
    // 0x8080449C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    bakey_held(rdram, ctx);
        goto after_0;
    // 0x8080449C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x808044A0: beq         $v0, $zero, L_808044B0
    if (ctx->r2 == 0) {
        // 0x808044A4: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_808044B0;
    }
    // 0x808044A4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808044A8: b           L_808044B4
    // 0x808044AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808044B4;
    // 0x808044AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808044B0:
    // 0x808044B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808044B4:
    // 0x808044B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808044B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808044BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808044C0: jal         0x800919F4
    // 0x808044C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    bakey_held(rdram, ctx);
        goto after_1;
    // 0x808044C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x808044C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808044CC: beq         $v0, $zero, L_808044DC
    if (ctx->r2 == 0) {
        // 0x808044D0: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_808044DC;
    }
    // 0x808044D0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808044D4: b           L_808044E0
    // 0x808044D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808044E0;
    // 0x808044D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808044DC:
    // 0x808044DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808044E0:
    // 0x808044E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x808044E4: beq         $v1, $zero, L_8080450C
    if (ctx->r3 == 0) {
        // 0x808044E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080450C;
    }
    // 0x808044E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808044EC: beq         $v1, $at, L_80804518
    if (ctx->r3 == ctx->r1) {
        // 0x808044F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804518;
    }
    // 0x808044F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808044F4: beq         $v1, $at, L_80804528
    if (ctx->r3 == ctx->r1) {
        // 0x808044F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804528;
    }
    // 0x808044F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808044FC: beql        $v1, $at, L_80804510
    if (ctx->r3 == ctx->r1) {
        // 0x80804500: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80804510;
    }
    goto skip_0;
    // 0x80804500: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80804504: b           L_80804534
    // 0x80804508: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
        goto L_80804534;
    // 0x80804508: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
L_8080450C:
    // 0x8080450C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80804510:
    // 0x80804510: b           L_80804538
    // 0x80804514: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
        goto L_80804538;
    // 0x80804514: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
L_80804518:
    // 0x80804518: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080451C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804520: b           L_80804538
    // 0x80804524: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
        goto L_80804538;
    // 0x80804524: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
L_80804528:
    // 0x80804528: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080452C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804530: nop

L_80804534:
    // 0x80804534: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
L_80804538:
    // 0x80804538: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA464) << 16);
    // 0x8080453C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80804540: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x80804544: nop

    // 0x80804548: bc1fl       L_8080455C
    if (!c1cs) {
        // 0x8080454C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8080455C;
    }
    goto skip_1;
    // 0x8080454C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80804550: b           L_80804584
    // 0x80804554: lwc1        $f2, -0x5B9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA464));
        goto L_80804584;
    // 0x80804554: lwc1        $f2, -0x5B9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA464));
    // 0x80804558: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8080455C:
    // 0x8080455C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA468) << 16);
    // 0x80804560: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x80804564: nop

    // 0x80804568: bc1f        L_80804580
    if (!c1cs) {
        // 0x8080456C: nop
    
            goto L_80804580;
    }
    // 0x8080456C: nop

    // 0x80804570: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804574: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80804578: b           L_80804588
    // 0x8080457C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
        goto L_80804588;
    // 0x8080457C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
L_80804580:
    // 0x80804580: lwc1        $f2, -0x5B98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA468));
L_80804584:
    // 0x80804584: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
L_80804588:
    // 0x80804588: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8080458C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80804590: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80804594: jal         0x800F2100
    // 0x80804598: sub.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f10.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80804598: sub.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f10.fl;
    after_2:
    // 0x8080459C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808045A0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808045A4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808045A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808045AC: nop

    // 0x808045B0: bc1fl       L_808045C8
    if (!c1cs) {
        // 0x808045B4: lwc1        $f0, 0x0($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
            goto L_808045C8;
    }
    goto skip_2;
    // 0x808045B4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x808045B8: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x808045BC: b           L_808045EC
    // 0x808045C0: swc1        $f14, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f14.u32l;
        goto L_808045EC;
    // 0x808045C0: swc1        $f14, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f14.u32l;
    // 0x808045C4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
L_808045C8:
    // 0x808045C8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x808045CC: nop

    // 0x808045D0: bc1fl       L_808045E8
    if (!c1cs) {
        // 0x808045D4: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_808045E8;
    }
    goto skip_3;
    // 0x808045D4: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x808045D8: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808045DC: b           L_808045EC
    // 0x808045E0: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
        goto L_808045EC;
    // 0x808045E0: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x808045E4: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_808045E8:
    // 0x808045E8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_808045EC:
    // 0x808045EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808045F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808045F4: jr          $ra
    // 0x808045F8: nop

    return;
    // 0x808045F8: nop

;}
RECOMP_FUNC void suexpression_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CC0: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80800CC4: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x80800CC8: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80800CCC: beq         $t7, $zero, L_80800CE4
    if (ctx->r15 == 0) {
        // 0x80800CD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800CE4;
    }
    // 0x80800CD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800CD4: jal         0x80100094
    // 0x80800CD8: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CD8: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x80800CDC: b           L_80800CE8
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CE8;
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CE4:
    // 0x80800CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CE8:
    // 0x80800CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CEC: jr          $ra
    // 0x80800CF0: nop

    return;
    // 0x80800CF0: nop

;}
RECOMP_FUNC void bskazdie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800400: jal         0x8009BC6C
    // 0x80800404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x8009BF5C
    // 0x80800410: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800410: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8009C4CC
    // 0x8080041C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x8080041C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800420: jal         0x800A4E30
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_3;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800428: jal         0x800951B4
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_4;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800430: jal         0x800832E8
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080043C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void func_800BFF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFF4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFF50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFF54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BFF58: jal         0x80088060
    // 0x800BFF5C: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    _gcskyDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800BFF5C: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    after_0:
    // 0x800BFF60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFF64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFF68: jr          $ra
    // 0x800BFF6C: nop

    return;
    // 0x800BFF6C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084268: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084268);
    return;
    // 0x8008426C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void bainput_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009811C: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x80098120: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80098124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80098128: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8009812C: lw          $t7, 0xA4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA4);
    // 0x80098130: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x80098134: lw          $t8, 0xA4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XA4);
    // 0x80098138: jr          $ra
    // 0x8009813C: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8009813C: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088348: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088348);
    return;
    // 0x8008834C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800F8D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F8D5C: jal         0x800F88A0
    // 0x800F8D60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8D60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800F8D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F8D68: jal         0x800F8D80
    // 0x800F8D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800F8D80(rdram, ctx);
        goto after_1;
    // 0x800F8D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F8D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8D78: jr          $ra
    // 0x800F8D7C: nop

    return;
    // 0x800F8D7C: nop

;}
RECOMP_FUNC void func_8080003C_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800048: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X918) << 16);
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: jal         0x80086040
    // 0x80800054: addiu       $a1, $a1, 0x918
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X918));
    _chpowerhut_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800054: addiu       $a1, $a1, 0x918
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X918));
    after_0:
    // 0x80800058: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080005C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800060: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800064: beq         $t6, $at, L_80800168
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800168;
    }
    // 0x80800068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080006C: bne         $t6, $at, L_80800168
    if (ctx->r14 != ctx->r1) {
        // 0x80800070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800168;
    }
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80100094
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080007C: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80800080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800084: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800088: bnel        $t7, $at, L_808000A8
    if (ctx->r15 != ctx->r1) {
        // 0x8080008C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A8;
    }
    goto skip_0;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800090: jal         0x800BF744
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080009C: jal         0x800BF744
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000A8:
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000B0: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x808000B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: bne         $t8, $at, L_80800144
    if (ctx->r24 != ctx->r1) {
        // 0x808000C0: nop
    
            goto L_80800144;
    }
    // 0x808000C0: nop

    // 0x808000C4: jal         0x80100094
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808000DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000E4: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808000E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000EC: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808000F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808000F8: jal         0x800F10B4
    // 0x808000FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808000FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80800100: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080010C: jal         0x80100094
    // 0x80800110: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800110: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    after_8:
    // 0x80800114: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X900) << 16);
    // 0x80800118: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(960, 0X90C) << 16);
    // 0x8080011C: addiu       $a2, $a2, 0x90C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(960, 0X90C));
    // 0x80800120: addiu       $a1, $a1, 0x900
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X900));
    // 0x80800124: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800128: jal         0x800F3214
    // 0x8080012C: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    func_800F3214(rdram, ctx);
        goto after_9;
    // 0x8080012C: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    after_9:
    // 0x80800130: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800134: jal         0x800C8F08
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8F08(rdram, ctx);
        goto after_10;
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080013C: jal         0x808002B4
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B4_chstarspinnerctrl(rdram, ctx);
        goto after_11;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800144:
    // 0x80800144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(960, 0X918) << 16);
    // 0x80800148: addiu       $a2, $a2, 0x918
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(960, 0X918));
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x80086058
    // 0x80800154: lui         $a1, 0x412C
    ctx->r5 = S32(0X412C << 16);
    _chpowerhut_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800154: lui         $a1, 0x412C
    ctx->r5 = S32(0X412C << 16);
    after_12:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: nop
    
            goto L_80800168;
    }
    // 0x8080015C: nop

    // 0x80800160: jal         0x800DA544
    // 0x80800164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
L_80800168:
    // 0x80800168: jal         0x8080069C
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080069C_chstarspinnerctrl(rdram, ctx);
        goto after_14;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800174: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800178: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void func_808008E4_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x808008E8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808008EC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808008F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808008F4: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808008F8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808008FC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800900: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800904: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800908: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8080090C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800910: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800914: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800918: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080091C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800920: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800924: jal         0x80100094
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080092C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80800930: lhu         $v1, 0x76($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X76);
    // 0x80800934: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80800938: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x8080093C: addiu       $v1, $t6, -0x32
    ctx->r3 = ADD32(ctx->r14, -0X32);
    // 0x80800940: bltz        $v1, L_80800950
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800944: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80800950;
    }
    // 0x80800944: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80800948: bnel        $at, $zero, L_80800958
    if (ctx->r1 != 0) {
        // 0x8080094C: lhu         $t9, 0x6E($s3)
        ctx->r25 = MEM_HU(ctx->r19, 0X6E);
            goto L_80800958;
    }
    goto skip_0;
    // 0x8080094C: lhu         $t9, 0x6E($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X6E);
    skip_0:
L_80800950:
    // 0x80800950: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800954: lhu         $t9, 0x6E($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X6E);
L_80800958:
    // 0x80800958: andi        $t8, $v1, 0x1FF
    ctx->r24 = ctx->r3 & 0X1FF;
    // 0x8080095C: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x80800960: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800964: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800968: jal         0x800DC128
    // 0x8080096C: sh          $t1, 0x6E($s3)
    MEM_H(0X6E, ctx->r19) = ctx->r9;
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8080096C: sh          $t1, 0x6E($s3)
    MEM_H(0X6E, ctx->r19) = ctx->r9;
    after_1:
    // 0x80800970: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800974: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800978: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080097C: swc1        $f6, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f6.u32l;
    // 0x80800980: lw          $s6, 0x94($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X94);
    // 0x80800984: addiu       $s6, $s6, 0x10
    ctx->r22 = ADD32(ctx->r22, 0X10);
    // 0x80800988: jal         0x80800778
    // 0x8080098C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80800778_chfactorylight(rdram, ctx);
        goto after_2;
    // 0x8080098C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x80800990: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800994: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800998: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080099C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808009A0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808009A4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808009A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808009AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808009B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808009B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808009B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808009BC: lw          $s0, 0x94($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X94);
    // 0x808009C0: addiu       $s4, $s3, 0x4
    ctx->r20 = ADD32(ctx->r19, 0X4);
    // 0x808009C4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x808009C8: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
L_808009CC:
    // 0x808009CC: jal         0x800C8A98
    // 0x808009D0: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x808009D0: nop

    after_3:
    // 0x808009D4: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x808009D8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808009DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808009E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x808009E8: mul.s       $f20, $f10, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x808009EC: jal         0x800C8E84
    // 0x808009F0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x808009F0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    after_4:
    // 0x808009F4: lwc1        $f4, 0x38($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X38);
    // 0x808009F8: lwc1        $f16, 0x48($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X48);
    // 0x808009FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A00: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80800A04: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x80800A08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A0C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800A10: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800A14: jal         0x800EEC30
    // 0x80800A18: nop

    func_800EEC30(rdram, ctx);
        goto after_5;
    // 0x80800A18: nop

    after_5:
    // 0x80800A1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A20: jal         0x800EF04C
    // 0x80800A24: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800A24: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800A28: lwc1        $f8, 0x38($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800A2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A30: lw          $a1, 0x48($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X48);
    // 0x80800A34: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x80800A38: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800A3C: jal         0x800EF1B8
    // 0x80800A40: nop

    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x80800A40: nop

    after_7:
    // 0x80800A44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A48: jal         0x800C8CB8
    // 0x80800A4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80800A4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80800A50: lwc1        $f0, 0x38($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800A54: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800A58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A5C: mul.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80800A60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A64: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800A68: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800A6C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800A70: jal         0x800C8E54
    // 0x80800A74: nop

    func_800C8E54(rdram, ctx);
        goto after_9;
    // 0x80800A74: nop

    after_9:
    // 0x80800A78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800A7C: bne         $s1, $s5, L_808009CC
    if (ctx->r17 != ctx->r21) {
        // 0x80800A80: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808009CC;
    }
    // 0x80800A80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800A84: jal         0x800EA05C
    // 0x80800A88: nop

    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x80800A88: nop

    after_10:
    // 0x80800A8C: addiu       $at, $zero, 0x10D
    ctx->r1 = ADD32(0, 0X10D);
    // 0x80800A90: bnel        $v0, $at, L_80800B10
    if (ctx->r2 != ctx->r1) {
        // 0x80800A94: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80800B10;
    }
    goto skip_1;
    // 0x80800A94: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x80800A98: jal         0x800DA298
    // 0x80800A9C: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800A9C: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_11:
    // 0x80800AA0: beq         $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800AA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800AE4;
    }
    // 0x80800AA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AAC: jal         0x80101FDC
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800AB4: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800ABC: jal         0x800C8FE0
    // 0x80800AC0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_800C8FE0(rdram, ctx);
        goto after_13;
    // 0x80800AC0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_13:
    // 0x80800AC4: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80800AC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800ACC: jal         0x800C8FE0
    // 0x80800AD0: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_800C8FE0(rdram, ctx);
        goto after_14;
    // 0x80800AD0: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_14:
    // 0x80800AD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB80) << 16);
    // 0x80800AD8: lwc1        $f6, 0xB80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB80));
    // 0x80800ADC: b           L_80800B0C
    // 0x80800AE0: swc1        $f6, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f6.u32l;
        goto L_80800B0C;
    // 0x80800AE0: swc1        $f6, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f6.u32l;
L_80800AE4:
    // 0x80800AE4: jal         0x80101FDC
    // 0x80800AE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x80800AE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x80800AEC: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80800AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AF4: jal         0x800C8FE0
    // 0x80800AF8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    func_800C8FE0(rdram, ctx);
        goto after_16;
    // 0x80800AF8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_16:
    // 0x80800AFC: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80800B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B04: jal         0x800C8FE0
    // 0x80800B08: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    func_800C8FE0(rdram, ctx);
        goto after_17;
    // 0x80800B08: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    after_17:
L_80800B0C:
    // 0x80800B0C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80800B10:
    // 0x80800B10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800B14: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800B18: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800B1C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800B20: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800B24: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800B28: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800B2C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B30: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800B34: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800B38: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800B3C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B40: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800B44: jr          $ra
    // 0x80800B48: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800B48: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80800B4C: nop

;}
RECOMP_FUNC void _baduo_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084978: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084978);
    return;
    // 0x8008497C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800018_chfactoryliftdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800024: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800028: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800034: addiu       $v0, $t6, 0xC
    ctx->r2 = ADD32(ctx->r14, 0XC);
    // 0x80800038: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8080003C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800040: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800044: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800048: jal         0x80086898
    // 0x8080004C: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080004C: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_0:
    // 0x80800050: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080006C;
    }
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800868A8
    // 0x8080005C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080005C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x800868C0
    // 0x80800068: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
L_8080006C:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8010A800
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080007C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_800F0BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F0BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0BD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F0BDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F0BE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F0BE4: jal         0x800EEEA8
    // 0x800F0BE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800EEEA8(rdram, ctx);
        goto after_0;
    // 0x800F0BE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F0BEC: beq         $v0, $zero, L_800F0BFC
    if (ctx->r2 == 0) {
        // 0x800F0BF0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800F0BFC;
    }
    // 0x800F0BF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F0BF4: b           L_800F0C58
    // 0x800F0BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0C58;
    // 0x800F0BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0BFC:
    // 0x800F0BFC: jal         0x800EEAA4
    // 0x800F0C00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x800F0C00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800F0C04: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F0C08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F0C0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F0C10: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F0C14: nop

    // 0x800F0C18: bc1f        L_800F0C28
    if (!c1cs) {
        // 0x800F0C1C: nop
    
            goto L_800F0C28;
    }
    // 0x800F0C1C: nop

    // 0x800F0C20: b           L_800F0C58
    // 0x800F0C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0C58;
    // 0x800F0C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0C28:
    // 0x800F0C28: jal         0x800EEF94
    // 0x800F0C2C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800EEF94(rdram, ctx);
        goto after_2;
    // 0x800F0C2C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800F0C30: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F0C34: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F0C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0C3C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F0C40: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800F0C44: nop

    // 0x800F0C48: bc1f        L_800F0C58
    if (!c1cs) {
        // 0x800F0C4C: nop
    
            goto L_800F0C58;
    }
    // 0x800F0C4C: nop

    // 0x800F0C50: b           L_800F0C58
    // 0x800F0C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0C58;
    // 0x800F0C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0C58:
    // 0x800F0C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0C5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F0C60: jr          $ra
    // 0x800F0C64: nop

    return;
    // 0x800F0C64: nop

;}
RECOMP_FUNC void func_8010A79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A79C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A7A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A7A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010A7A8: lh          $t7, 0x7E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X7E);
    // 0x8010A7AC: bgezl       $t7, L_8010A7F4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8010A7B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010A7F4;
    }
    goto skip_0;
    // 0x8010A7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010A7B4: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x8010A7B8: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x8010A7BC: bltzl       $t0, L_8010A7F4
    if (SIGNED(ctx->r8) < 0) {
        // 0x8010A7C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010A7F4;
    }
    goto skip_1;
    // 0x8010A7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8010A7C4: lhu         $t1, 0x64($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X64);
    // 0x8010A7C8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8010A7CC: beql        $t2, $zero, L_8010A7F4
    if (ctx->r10 == 0) {
        // 0x8010A7D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010A7F4;
    }
    goto skip_2;
    // 0x8010A7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010A7D4: jal         0x80100368
    // 0x8010A7D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x8010A7D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010A7DC: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8010A7E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010A7E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A7E8: jalr        $t9
    // 0x8010A7EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8010A7EC: nop

    after_1:
    // 0x8010A7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A7F4:
    // 0x8010A7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A7F8: jr          $ra
    // 0x8010A7FC: nop

    return;
    // 0x8010A7FC: nop

;}
RECOMP_FUNC void func_80801830_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A48) << 16);
    // 0x8080183C: lui         $a3, 0x3E8F
    ctx->r7 = S32(0X3E8F << 16);
    // 0x80801840: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x80801844: addiu       $a2, $a2, 0x2A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A48));
    // 0x80801848: jal         0x80089D20
    // 0x8080184C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080184C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801858: jr          $ra
    // 0x8080185C: nop

    return;
    // 0x8080185C: nop

;}
RECOMP_FUNC void chvolcanobits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1264, 0X119C) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x119C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X119C));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x119C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X119C));
;}
RECOMP_FUNC void func_800E40AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E40AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E40B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E40B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E40B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E40BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E40C0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E40C4: jal         0x800CAF00
    // 0x800E40C8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CAF00(rdram, ctx);
        goto after_0;
    // 0x800E40C8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E40CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E40D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E40D4: jr          $ra
    // 0x800E40D8: nop

    return;
    // 0x800E40D8: nop

;}
RECOMP_FUNC void func_808005D8_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E0: jal         0x80800000
    // 0x808005E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsride(rdram, ctx);
        goto after_0;
    // 0x808005E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005E8: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808005EC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808005F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: jal         0x8008CB3C
    // 0x808005F8: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808005F8: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    after_1:
    // 0x808005FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800604: jr          $ra
    // 0x80800608: nop

    return;
    // 0x80800608: nop

;}
RECOMP_FUNC void _bstalk_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DB0: syscall     95
    recomp_syscall_handler(rdram, ctx, 0x80083DB0);
    return;
    // 0x80083DB4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncbapivot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DF8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DF8);
    return;
    // 0x80087DFC: addi        $t0, $zero, 0xB0
    ctx->r8 = ADD32(0, 0XB0);
;}
RECOMP_FUNC void _chpotogoldbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E0: syscall     594
    recomp_syscall_handler(rdram, ctx, 0x800875E0);
    return;
    // 0x800875E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F18FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F18FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F1900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1904: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F1908: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F190C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F1910: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1914: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F1918: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F191C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F1920: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800F1924: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1928: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F192C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1930: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800F1934: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800F1938: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F193C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F1940: jal         0x8002DCA0
    // 0x800F1944: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1944: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800F1948: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F194C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1950: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F1954: jal         0x80013B70
    // 0x800F1958: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80013B70(rdram, ctx);
        goto after_1;
    // 0x800F1958: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F195C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800F1960: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x800F1964: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1968: jal         0x80013B7C
    // 0x800F196C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x800F196C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800F1970: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800F1974: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800F1978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F197C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F1980: jr          $ra
    // 0x800F1984: nop

    return;
    // 0x800F1984: nop

;}
RECOMP_FUNC void func_800F8418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F841C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8420: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8428: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F842C: jal         0x800F4648
    // 0x800F8430: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F4648(rdram, ctx);
        goto after_0;
    // 0x800F8430: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F843C: jr          $ra
    // 0x800F8440: nop

    return;
    // 0x800F8440: nop

;}
RECOMP_FUNC void func_800D2F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2F44: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D2F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2F4C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D2F50: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800D2F54: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800D2F58: jal         0x800E42C0
    // 0x800D2F5C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_800E42C0(rdram, ctx);
        goto after_0;
    // 0x800D2F5C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D2F60: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800D2F64: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800D2F68: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800D2F6C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800D2F70: bgez        $a2, L_800D2F80
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D2F74: sra         $v0, $a2, 1
        ctx->r2 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800D2F80;
    }
    // 0x800D2F74: sra         $v0, $a2, 1
    ctx->r2 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800D2F78: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x800D2F7C: sra         $v0, $at, 1
    ctx->r2 = S32(SIGNED(ctx->r1) >> 1);
L_800D2F80:
    // 0x800D2F80: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2F84: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800D2F88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D2F8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D2F90: addiu       $t5, $a2, 0x12C
    ctx->r13 = ADD32(ctx->r6, 0X12C);
    // 0x800D2F94: mflo        $t7
    ctx->r15 = lo;
    // 0x800D2F98: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800D2F9C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800D2FA0: nop

    // 0x800D2FA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D2FA8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D2FAC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800D2FB0: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800D2FB4: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800D2FB8: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2FBC: mflo        $t0
    ctx->r8 = lo;
    // 0x800D2FC0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800D2FC4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800D2FC8: nop

    // 0x800D2FCC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D2FD0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D2FD4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800D2FD8: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800D2FDC: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800D2FE0: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2FE4: mflo        $t3
    ctx->r11 = lo;
    // 0x800D2FE8: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800D2FEC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800D2FF0: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x800D2FF4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D2FF8: lwc1        $f8, 0x5B00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B00);
    // 0x800D2FFC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800D3000: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D3004: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800D3008: nop

    // 0x800D300C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D3010: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D3014: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800D3018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D301C: nop

    // 0x800D3020: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D3024: nop

    // 0x800D3028: mul.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800D302C: nop

    tooie_cell_draw_distance(rdram, ctx);
    // 0x800D3030: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D3034: nop

    // 0x800D3038: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800D303C: nop

    // 0x800D3040: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D3044: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800D3048: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D304C: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D3050: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800D3054: nop

    // 0x800D3058: bc1f        L_800D3068
    if (!c1cs) {
        // 0x800D305C: nop
    
            goto L_800D3068;
    }
    // 0x800D305C: nop

    // 0x800D3060: b           L_800D30F4
    // 0x800D3064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D30F4;
    // 0x800D3064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3068:
    // 0x800D3068: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800D306C: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x800D3070: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800D3074: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D3078: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D307C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3080: beq         $v1, $a1, L_800D30C0
    if (ctx->r3 == ctx->r5) {
        // 0x800D3084: multu       $t6, $a2
        result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_800D30C0;
    }
    // 0x800D3084: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800D3088:
    // 0x800D3088: mflo        $t7
    ctx->r15 = lo;
    // 0x800D308C: addiu       $t8, $t7, -0x96
    ctx->r24 = ADD32(ctx->r15, -0X96);
    // 0x800D3090: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800D3094: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3098: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D309C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D30A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D30A4: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800D30A8: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x800D30AC: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800D30B0: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x800D30B4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D30B8: bne         $v1, $a1, L_800D3088
    if (ctx->r3 != ctx->r5) {
        // 0x800D30BC: multu       $t6, $a2
        result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_800D3088;
    }
    // 0x800D30BC: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800D30C0:
    // 0x800D30C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D30C4: addiu       $t8, $t7, -0x96
    ctx->r24 = ADD32(ctx->r15, -0X96);
    // 0x800D30C8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800D30CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D30D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D30D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D30D8: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800D30DC: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x800D30E0: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800D30E4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D30E8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800D30EC: jal         0x800E3D0C
    // 0x800D30F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800E3D0C(rdram, ctx);
        goto after_1;
    // 0x800D30F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
L_800D30F4:
    // 0x800D30F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D30F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D30FC: jr          $ra
    // 0x800D3100: nop

    return;
    // 0x800D3100: nop

;}
RECOMP_FUNC void badrone_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800120: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080012C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800130: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800138: lw          $a1, 0x54($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X54);
    // 0x8080013C: jal         0x800EE7F8
    // 0x80800140: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800140: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x80800144: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
    // 0x80800150: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80800154: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80800158: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x8080015C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800160: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80800164: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_8009640C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009640C: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80096410: lbu         $v0, 0x18($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X18);
    // 0x80096414: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80096418: beq         $t6, $zero, L_8009642C
    if (ctx->r14 == 0) {
        // 0x8009641C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8009642C;
    }
    // 0x8009641C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80096420: lbu         $v0, 0x56($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X56);
    // 0x80096424: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80096428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8009642C:
    // 0x8009642C: jr          $ra
    // 0x80096430: nop

    return;
    // 0x80096430: nop

;}
RECOMP_FUNC void func_800EBC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBC04: jr          $ra
    // 0x800EBC08: nop

    return;
    // 0x800EBC08: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F2C: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80802F30: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80802F34: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80802F38: beq         $v0, $zero, L_80802F44
    if (ctx->r2 == 0) {
        // 0x80802F3C: nop
    
            goto L_80802F44;
    }
    // 0x80802F3C: nop

    // 0x80802F40: slti        $v0, $v1, 0xB
    ctx->r2 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
L_80802F44:
    // 0x80802F44: jr          $ra
    // 0x80802F48: nop

    return;
    // 0x80802F48: nop

;}
RECOMP_FUNC void func_80115EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115EA0: jr          $ra
    // 0x80115EA4: addiu       $v0, $zero, 0x5C
    ctx->r2 = ADD32(0, 0X5C);
    return;
    // 0x80115EA4: addiu       $v0, $zero, 0x5C
    ctx->r2 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842B8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842B8);
    return;
    // 0x800842BC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800104_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: jal         0x800887B0
    // 0x80800110: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800110: nop

    after_0:
    // 0x80800114: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_0;
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080011C: jal         0x800DA298
    // 0x80800120: addiu       $a0, $zero, 0x647
    ctx->r4 = ADD32(0, 0X647);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a0, $zero, 0x647
    ctx->r4 = ADD32(0, 0X647);
    after_1:
    // 0x80800124: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800128: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_1;
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080012C: jal         0x800A9C98
    // 0x80800130: nop

    func_800A9C98(rdram, ctx);
        goto after_2;
    // 0x80800130: nop

    after_2:
    // 0x80800134: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_2;
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080013C: jal         0x800880E8
    // 0x80800140: nop

    _gcintrotext_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800140: nop

    after_3:
    // 0x80800144: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_3;
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8080014C: jal         0x80088840
    // 0x80800150: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800150: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_4:
    // 0x80800154: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800158: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_4;
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8080015C: jal         0x80088848
    // 0x80800160: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800160: nop

    after_5:
    // 0x80800164: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800168: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_5;
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8080016C: jal         0x80088240
    // 0x80800170: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    _gclevel_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800170: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_6:
    // 0x80800174: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800178: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_6;
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8080017C: jal         0x800861A8
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800188:
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_80800098_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(604, 0X1038) << 16);
    // 0x8080009C: addiu       $t7, $t7, 0x1038
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(604, 0X1038));
    // 0x808000A0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x808000A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808000A8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808000B0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x808000B4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808000B8: jr          $ra
    // 0x808000BC: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    return;
    // 0x808000BC: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
;}
RECOMP_FUNC void _subaddielink_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A028: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A028);
    return;
    // 0x8008A02C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080090C_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800918: jal         0x80105834
    // 0x8080091C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x8080091C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800920: jal         0x80105A5C
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_1;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800928: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x8080092C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080095C;
    }
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: jal         0x80100094
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800938: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080093C: jal         0x800DA544
    // 0x80800940: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800940: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_3:
    // 0x80800944: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: jal         0x8008A2C0
    // 0x80800950: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800950: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_4:
    // 0x80800954: jal         0x800FFAB0
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8080095C:
    // 0x8080095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800968: jr          $ra
    // 0x8080096C: nop

    return;
    // 0x8080096C: nop

;}
RECOMP_FUNC void func_80806130_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806130: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806134: jr          $ra
    // 0x80806138: lwc1        $f0, 0x1C8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C8);
    return;
    // 0x80806138: lwc1        $f0, 0x1C8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C8);
;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X2218) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2218
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2218));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2218
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2218));
;}
RECOMP_FUNC void _ncpoddialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895E0: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895E0);
    return;
    // 0x800895E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800140_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8080014C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800150: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1712, 0X230) << 16);
    // 0x80800154: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800158: bgez        $t8, L_80800168
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080015C: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_80800168;
    }
    // 0x8080015C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800160: b           L_80800168
    // 0x80800164: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
        goto L_80800168;
    // 0x80800164: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
L_80800168:
    // 0x80800168: jal         0x80089D50
    // 0x8080016C: addiu       $a3, $a3, 0x230
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1712, 0X230));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080016C: addiu       $a3, $a3, 0x230
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1712, 0X230));
    after_0:
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_8009B414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009B418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B41C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009B420: jal         0x8009C128
    // 0x8009B424: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009B424: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009B428: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009B42C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8009B430: lw          $v0, 0xC8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC8);
    // 0x8009B434: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x8009B438: jal         0x800EFB24
    // 0x8009B43C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x8009B43C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x8009B440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009B448: jr          $ra
    // 0x8009B44C: nop

    return;
    // 0x8009B44C: nop

;}
RECOMP_FUNC void func_8009BDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BDE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BDEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009BDF0: jal         0x800915AC
    // 0x8009BDF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bastatetimer_isDone(rdram, ctx);
        goto after_0;
    // 0x8009BDF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8009BDF8: beq         $v0, $zero, L_8009BE08
    if (ctx->r2 == 0) {
        // 0x8009BDFC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8009BE08;
    }
    // 0x8009BDFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009BE00: jal         0x8009BD38
    // 0x8009BE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009BD38(rdram, ctx);
        goto after_1;
    // 0x8009BE04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8009BE08:
    // 0x8009BE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BE0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BE10: jr          $ra
    // 0x8009BE14: nop

    return;
    // 0x8009BE14: nop

    // 0x8009BE18: nop

    // 0x8009BE1C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084210: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084210);
    return;
    // 0x80084214: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80111F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80111F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111F78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80111F7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80111F80: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80111F84: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80111F88: jal         0x80111DB0
    // 0x80111F8C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_80111DB0(rdram, ctx);
        goto after_0;
    // 0x80111F8C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80111F90: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80111F94: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80111F98: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80111F9C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80111FA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80111FA4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80111FA8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80111FAC: lw          $v0, 0x34($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X34);
    // 0x80111FB0: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80111FB4: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80111FB8: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x80111FBC: jal         0x80111E88
    // 0x80111FC0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80111E88(rdram, ctx);
        goto after_1;
    // 0x80111FC0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80111FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111FC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80111FCC: jr          $ra
    // 0x80111FD0: nop

    return;
    // 0x80111FD0: nop

;}
RECOMP_FUNC void func_8080059C_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808005A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005AC: jal         0x80100094
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808005C0: jal         0x800D8FF8
    // 0x808005C4: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808005C4: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808005C8: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x808005CC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808005D0: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808005D4: bgezl       $t8, L_808005F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808005D8: lwc1        $f2, 0x20($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
            goto L_808005F0;
    }
    goto skip_0;
    // 0x808005D8: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    skip_0:
    // 0x808005DC: jal         0x80801118
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801118_chbadjinjo(rdram, ctx);
        goto after_2;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005E4: b           L_80800C80
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C80;
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005EC: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
L_808005F0:
    // 0x808005F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808005F4: nop

    // 0x808005F8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808005FC: nop

    // 0x80800600: bc1fl       L_8080062C
    if (!c1cs) {
        // 0x80800604: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8080062C;
    }
    goto skip_1;
    // 0x80800604: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800608: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8080060C: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x80800610: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800614: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80800618: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x8080061C: ori         $t1, $t0, 0x8C80
    ctx->r9 = ctx->r8 | 0X8C80;
    // 0x80800620: b           L_8080063C
    // 0x80800624: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
        goto L_8080063C;
    // 0x80800624: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80800628: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8080062C:
    // 0x8080062C: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80800630: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x80800634: ori         $t4, $t3, 0x8C40
    ctx->r12 = ctx->r11 | 0X8C40;
    // 0x80800638: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
L_8080063C:
    // 0x8080063C: jal         0x800D9078
    // 0x80800640: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80800640: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x80800644: jal         0x8010D254
    // 0x80800648: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80800648: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x8080064C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800650: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800654: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800658: jal         0x800F1E6C
    // 0x8080065C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x8080065C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x80800660: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800664: jal         0x800F1DCC
    // 0x80800668: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80800668: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    after_6:
    // 0x8080066C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800670: lh          $t5, 0x8C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8C);
    // 0x80800674: beql        $t5, $zero, L_808006A0
    if (ctx->r13 == 0) {
        // 0x80800678: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_808006A0;
    }
    goto skip_2;
    // 0x80800678: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x8080067C: jal         0x80101F24
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800684: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X1348) << 16);
    // 0x80800688: addiu       $a1, $a1, 0x1348
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X1348));
    // 0x8080068C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800690: jal         0x800F3780
    // 0x80800694: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800F3780(rdram, ctx);
        goto after_8;
    // 0x80800694: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_8:
    // 0x80800698: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8080069C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_808006A0:
    // 0x808006A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808006A4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808006A8: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x808006AC: beq         $at, $zero, L_80800BD8
    if (ctx->r1 == 0) {
        // 0x808006B0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800BD8;
    }
    // 0x808006B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808006B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11A8) << 16);
    // 0x808006B8: addu        $at, $at, $t8
    gpr jr_addend_808006C0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808006BC: lw          $t8, 0x11A8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11A8));
    // 0x808006C0: jr          $t8
    // 0x808006C4: nop

    switch (jr_addend_808006C0 >> 2) {
        case 0: goto L_808006C8; break;
        case 1: goto L_80800738; break;
        case 2: goto L_80800778; break;
        case 3: goto L_808007B8; break;
        case 4: goto L_80800854; break;
        case 5: goto L_80800A54; break;
        case 6: goto L_80800BA4; break;
        default: switch_error(__func__, 0x808006C0, 0x808011A8);
    }
    // 0x808006C4: nop

L_808006C8:
    // 0x808006C8: jal         0x800DC0C0
    // 0x808006CC: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x808006CC: nop

    after_9:
    // 0x808006D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11C4) << 16);
    // 0x808006D4: lwc1        $f10, 0x11C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11C4));
    // 0x808006D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808006DC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1f        L_80800718
    if (!c1cs) {
        // 0x808006E8: nop
    
            goto L_80800718;
    }
    // 0x808006E8: nop

    // 0x808006EC: jal         0x800901CC
    // 0x808006F0: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    func_800901CC(rdram, ctx);
        goto after_10;
    // 0x808006F0: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    after_10:
    // 0x808006F4: beq         $v0, $zero, L_80800710
    if (ctx->r2 == 0) {
        // 0x808006F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x80102424
    // 0x80800704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800708: b           L_80800718
    // 0x8080070C: nop

        goto L_80800718;
    // 0x8080070C: nop

L_80800710:
    // 0x80800710: jal         0x80102424
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_80800718:
    // 0x80800718: jal         0x80800F7C
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F7C_chbadjinjo(rdram, ctx);
        goto after_13;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800720: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800724: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: jal         0x80800E28
    // 0x8080072C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_14;
    // 0x8080072C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x80800730: b           L_80800BD8
    // 0x80800734: nop

        goto L_80800BD8;
    // 0x80800734: nop

L_80800738:
    // 0x80800738: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X1308) << 16);
    // 0x8080073C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800740: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800744: addiu       $a1, $a1, 0x1308
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X1308));
    // 0x80800748: jal         0x80801054
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801054_chbadjinjo(rdram, ctx);
        goto after_15;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800750: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800754: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800758: jal         0x80101E14
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800760: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: jal         0x80800E28
    // 0x8080076C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_17;
    // 0x8080076C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800770: b           L_80800BD8
    // 0x80800774: nop

        goto L_80800BD8;
    // 0x80800774: nop

L_80800778:
    // 0x80800778: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X1324) << 16);
    // 0x8080077C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800780: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800784: addiu       $a1, $a1, 0x1324
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X1324));
    // 0x80800788: jal         0x80801054
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801054_chbadjinjo(rdram, ctx);
        goto after_18;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800790: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800794: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800798: jal         0x80101E14
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808007A0: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: jal         0x80800E28
    // 0x808007AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_20;
    // 0x808007AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808007B0: b           L_80800BD8
    // 0x808007B4: nop

        goto L_80800BD8;
    // 0x808007B4: nop

L_808007B8:
    // 0x808007B8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X137C) << 16);
    // 0x808007BC: addiu       $a1, $a1, 0x137C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X137C));
    // 0x808007C0: jal         0x80105230
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105230(rdram, ctx);
        goto after_21;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808007C8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808007CC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808007D0: jal         0x80101E14
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_22;
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808007D8: beq         $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x808007DC: lwc1        $f16, 0x48($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
            goto L_808007F4;
    }
    // 0x808007DC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x80800E28
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_23;
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x808007EC: b           L_80800BD8
    // 0x808007F0: nop

        goto L_80800BD8;
    // 0x808007F0: nop

L_808007F4:
    // 0x808007F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808007F8: nop

    // 0x808007FC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80800800: nop

    // 0x80800804: bc1f        L_80800830
    if (!c1cs) {
        // 0x80800808: nop
    
            goto L_80800830;
    }
    // 0x80800808: nop

    // 0x8080080C: jal         0x800D8FF8
    // 0x80800810: nop

    func_800D8FF8(rdram, ctx);
        goto after_24;
    // 0x80800810: nop

    after_24:
    // 0x80800814: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800818: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080081C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800820: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800824: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800828: b           L_80800BD8
    // 0x8080082C: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
        goto L_80800BD8;
    // 0x8080082C: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_80800830:
    // 0x80800830: jal         0x800D8FF8
    // 0x80800834: nop

    func_800D8FF8(rdram, ctx);
        goto after_25;
    // 0x80800834: nop

    after_25:
    // 0x80800838: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080083C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800840: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800844: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800848: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080084C: b           L_80800BD8
    // 0x80800850: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
        goto L_80800BD8;
    // 0x80800850: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_80800854:
    // 0x80800854: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800858: jal         0x8010D254
    // 0x8080085C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_26;
    // 0x8080085C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_26:
    // 0x80800860: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x8080086C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800870: bgez        $t1, L_8080090C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800874: nop
    
            goto L_8080090C;
    }
    // 0x80800874: nop

    // 0x80800878: jal         0x80089BF0
    // 0x8080087C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_27;
    // 0x8080087C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_27:
    // 0x80800880: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800884: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800888: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080088C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800894: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800898: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8080089C: jal         0x80102BF8
    // 0x808008A0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80102BF8(rdram, ctx);
        goto after_28;
    // 0x808008A0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_28:
    // 0x808008A4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808008A8: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808008AC: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808008B0: ori         $a1, $a1, 0x5015
    ctx->r5 = ctx->r5 | 0X5015;
    // 0x808008B4: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808008C0: jal         0x8010C3A8
    // 0x808008C4: nop

    func_8010C3A8(rdram, ctx);
        goto after_29;
    // 0x808008C4: nop

    after_29:
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008D0: jal         0x80089BF0
    // 0x808008D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_30;
    // 0x808008D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_30:
    // 0x808008D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11C8) << 16);
    // 0x808008DC: lwc1        $f6, 0x11C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11C8));
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808008E8: nop

    // 0x808008EC: bc1f        L_808008FC
    if (!c1cs) {
        // 0x808008F0: nop
    
            goto L_808008FC;
    }
    // 0x808008F0: nop

    // 0x808008F4: jal         0x80800E28
    // 0x808008F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_31;
    // 0x808008F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
L_808008FC:
    // 0x808008FC: jal         0x808003EC
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003EC_chbadjinjo(rdram, ctx);
        goto after_32;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800904: b           L_80800BD8
    // 0x80800908: nop

        goto L_80800BD8;
    // 0x80800908: nop

L_8080090C:
    // 0x8080090C: jal         0x80089F78
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800914: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080095C;
    }
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: jal         0x80102D78
    // 0x80800920: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80102D78(rdram, ctx);
        goto after_34;
    // 0x80800920: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_34:
    // 0x80800924: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080092C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800930: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800934: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800938: addiu       $t2, $zero, 0x5800
    ctx->r10 = ADD32(0, 0X5800);
    // 0x8080093C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800940: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: jal         0x80089F90
    // 0x8080094C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_35;
    // 0x8080094C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_35:
    // 0x80800950: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80800954: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80800958: sw          $t4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r12;
L_8080095C:
    // 0x8080095C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800960: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800964: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800968: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080096C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800970: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800974: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80800978: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800984: jal         0x80089F80
    // 0x80800988: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_36;
    // 0x80800988: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_36:
    // 0x8080098C: jal         0x800D8FF8
    // 0x80800990: nop

    func_800D8FF8(rdram, ctx);
        goto after_37;
    // 0x80800990: nop

    after_37:
    // 0x80800994: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800998: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080099C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808009A0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808009A4: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808009A8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808009AC: jal         0x800F15F8
    // 0x808009B0: nop

    func_800F15F8(rdram, ctx);
        goto after_38;
    // 0x808009B0: nop

    after_38:
    // 0x808009B4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1576, 0X1370) << 16);
    // 0x808009B8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808009BC: addiu       $t6, $t6, 0x1370
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1576, 0X1370));
    // 0x808009C0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x808009CC: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x808009D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x808009D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808009D8: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x808009DC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808009E0: jal         0x801026CC
    // 0x808009E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_801026CC(rdram, ctx);
        goto after_39;
    // 0x808009E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_39:
    // 0x808009E8: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x808009EC: ori         $a1, $a1, 0x5115
    ctx->r5 = ctx->r5 | 0X5115;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F4: jal         0x8010C3A8
    // 0x808009F8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_8010C3A8(rdram, ctx);
        goto after_40;
    // 0x808009F8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_40:
    // 0x808009FC: jal         0x808003EC
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003EC_chbadjinjo(rdram, ctx);
        goto after_41;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800A04: jal         0x80089F78
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_42;
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800A0C: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800A10: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1576, 0X11CC) << 16);
            goto L_80800BD8;
    }
    // 0x80800A10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11CC) << 16);
    // 0x80800A14: jal         0x800DC298
    // 0x80800A18: lwc1        $f12, 0x11CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11CC));
    func_800DC298(rdram, ctx);
        goto after_43;
    // 0x80800A18: lwc1        $f12, 0x11CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11CC));
    after_43:
    // 0x80800A1C: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800A20: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800BD8;
    }
    // 0x80800A20: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A24: jal         0x8010C9B0
    // 0x80800A28: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010C9B0(rdram, ctx);
        goto after_44;
    // 0x80800A28: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_44:
    // 0x80800A2C: beql        $v0, $zero, L_80800A44
    if (ctx->r2 == 0) {
        // 0x80800A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A44;
    }
    goto skip_3;
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800A34: jal         0x8010C500
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_45;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800A3C: bne         $v0, $zero, L_80800BD8
    if (ctx->r2 != 0) {
        // 0x80800A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A44:
    // 0x80800A44: jal         0x80800E28
    // 0x80800A48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_46;
    // 0x80800A48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_46:
    // 0x80800A4C: b           L_80800BD8
    // 0x80800A50: nop

        goto L_80800BD8;
    // 0x80800A50: nop

L_80800A54:
    // 0x80800A54: jal         0x80800F7C
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F7C_chbadjinjo(rdram, ctx);
        goto after_47;
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800A5C: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x80800A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A6C;
    }
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x80800E28
    // 0x80800A68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_48;
    // 0x80800A68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_48:
L_80800A6C:
    // 0x80800A6C: jal         0x80089F78
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_49;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800A74: beq         $v0, $zero, L_80800ABC
    if (ctx->r2 == 0) {
        // 0x80800A78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ABC;
    }
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: jal         0x80102D78
    // 0x80800A80: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_50;
    // 0x80800A80: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_50:
    // 0x80800A84: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800A88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A8C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800A90: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800A94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800A98: addiu       $t9, $zero, 0x5800
    ctx->r25 = ADD32(0, 0X5800);
    // 0x80800A9C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800AA0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: jal         0x80089F90
    // 0x80800AAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_51;
    // 0x80800AAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_51:
    // 0x80800AB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800AB4: lhu         $t0, 0x6($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X6);
    // 0x80800AB8: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_80800ABC:
    // 0x80800ABC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800AC0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AC8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800ACC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AD0: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800AD4: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80800AD8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800AE4: jal         0x80089F80
    // 0x80800AE8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_52;
    // 0x80800AE8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_52:
    // 0x80800AEC: jal         0x800D8FF8
    // 0x80800AF0: nop

    func_800D8FF8(rdram, ctx);
        goto after_53;
    // 0x80800AF0: nop

    after_53:
    // 0x80800AF4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800AF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800AFC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800B00: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800B04: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800B08: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800B0C: jal         0x800F15F8
    // 0x80800B10: nop

    func_800F15F8(rdram, ctx);
        goto after_54;
    // 0x80800B10: nop

    after_54:
    // 0x80800B14: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1576, 0X1370) << 16);
    // 0x80800B18: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800B1C: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1576, 0X1370));
    // 0x80800B20: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x80800B2C: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x80800B30: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80800B34: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800B38: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x80800B3C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800B40: jal         0x801026CC
    // 0x80800B44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_801026CC(rdram, ctx);
        goto after_55;
    // 0x80800B44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_55:
    // 0x80800B48: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800B4C: ori         $a1, $a1, 0x5115
    ctx->r5 = ctx->r5 | 0X5115;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: jal         0x8010C3A8
    // 0x80800B58: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_8010C3A8(rdram, ctx);
        goto after_56;
    // 0x80800B58: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_56:
    // 0x80800B5C: jal         0x80089F78
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_57;
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80800B64: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800B68: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1576, 0X11D0) << 16);
            goto L_80800BD8;
    }
    // 0x80800B68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11D0) << 16);
    // 0x80800B6C: jal         0x800DC298
    // 0x80800B70: lwc1        $f12, 0x11D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11D0));
    func_800DC298(rdram, ctx);
        goto after_58;
    // 0x80800B70: lwc1        $f12, 0x11D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11D0));
    after_58:
    // 0x80800B74: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800B78: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800BD8;
    }
    // 0x80800B78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B7C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800B80: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800B84: jal         0x800EFFB4
    // 0x80800B88: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_800EFFB4(rdram, ctx);
        goto after_59;
    // 0x80800B88: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_59:
    // 0x80800B8C: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800B90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: jal         0x80800E28
    // 0x80800B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_60;
    // 0x80800B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
    // 0x80800B9C: b           L_80800BD8
    // 0x80800BA0: nop

        goto L_80800BD8;
    // 0x80800BA0: nop

L_80800BA4:
    // 0x80800BA4: jal         0x80101DDC
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_61;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800BAC: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x8008A4B0
    // 0x80800BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_62;
    // 0x80800BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_62:
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC0: jal         0x80107070
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_63;
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_63:
    // 0x80800BC8: bne         $v0, $zero, L_80800BD8
    if (ctx->r2 != 0) {
        // 0x80800BCC: nop
    
            goto L_80800BD8;
    }
    // 0x80800BCC: nop

    // 0x80800BD0: jal         0x80089CA8
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_64;
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
L_80800BD8:
    // 0x80800BD8: jal         0x801022E4
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_65;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80800BE0: addiu       $at, $zero, 0x1AD
    ctx->r1 = ADD32(0, 0X1AD);
    // 0x80800BE4: bne         $v0, $at, L_80800BF4
    if (ctx->r2 != ctx->r1) {
        // 0x80800BE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BF4;
    }
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BEC: jal         0x80105230
    // 0x80800BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_66;
    // 0x80800BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_66:
L_80800BF4:
    // 0x80800BF4: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800BF8: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80800BFC: bltzl       $t7, L_80800C5C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800C00: lhu         $t9, 0x72($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X72);
            goto L_80800C5C;
    }
    goto skip_4;
    // 0x80800C00: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    skip_4:
    // 0x80800C04: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800C08: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800C0C: srl         $t8, $t6, 10
    ctx->r24 = S32(U32(ctx->r14) >> 10);
    // 0x80800C10: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80800C14: beq         $at, $zero, L_80800C58
    if (ctx->r1 == 0) {
        // 0x80800C18: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80800C58;
    }
    // 0x80800C18: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800C1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C20: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C28: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80800C2C: nop

    // 0x80800C30: bc1t        L_80800C50
    if (c1cs) {
        // 0x80800C34: nop
    
            goto L_80800C50;
    }
    // 0x80800C34: nop

    // 0x80800C38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C3C: nop

    // 0x80800C40: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80800C44: nop

    // 0x80800C48: bc1fl       L_80800C5C
    if (!c1cs) {
        // 0x80800C4C: lhu         $t9, 0x72($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X72);
            goto L_80800C5C;
    }
    goto skip_5;
    // 0x80800C4C: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    skip_5:
L_80800C50:
    // 0x80800C50: jal         0x80102424
    // 0x80800C54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_67;
    // 0x80800C54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_67:
L_80800C58:
    // 0x80800C58: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
L_80800C5C:
    // 0x80800C5C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800C60: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80800C64: beq         $at, $zero, L_80800C74
    if (ctx->r1 == 0) {
        // 0x80800C68: nop
    
            goto L_80800C74;
    }
    // 0x80800C68: nop

    // 0x80800C6C: jal         0x8010D690
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010D690(rdram, ctx);
        goto after_68;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
L_80800C74:
    // 0x80800C74: jal         0x80801118
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801118_chbadjinjo(rdram, ctx);
        goto after_69;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80800C7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C80:
    // 0x80800C80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C84: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800C88: jr          $ra
    // 0x80800C8C: nop

    return;
    // 0x80800C8C: nop

;}
