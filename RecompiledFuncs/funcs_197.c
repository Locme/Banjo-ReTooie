#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bstnt_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F98: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F98);
    return;
    // 0x80083F9C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80093300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093300: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80093304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009330C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093310: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80093314: jal         0x8009332C
    // 0x80093318: swc1        $f12, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f12.u32l;
    func_8009332C(rdram, ctx);
        goto after_0;
    // 0x80093318: swc1        $f12, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f12.u32l;
    after_0:
    // 0x8009331C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093324: jr          $ra
    // 0x80093328: nop

    return;
    // 0x80093328: nop

;}
RECOMP_FUNC void bstnt_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X2408) << 16);
    // 0x80800E48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E4C: jr          $ra
    // 0x80800E50: lw          $v0, 0x2408($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X2408));
    return;
    // 0x80800E50: lw          $v0, 0x2408($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X2408));
;}
RECOMP_FUNC void func_80801120_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801120: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801128: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8080112C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801134: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80801138: srl         $t6, $a1, 26
    ctx->r14 = S32(U32(ctx->r5) >> 26);
    // 0x8080113C: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80801140: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80801144: jal         0x800CC63C
    // 0x80801148: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80801148: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8080114C: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80801150: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801154: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801158: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8080115C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801160: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80801164: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801168: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x8080116C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80801170: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80801174: nop

    // 0x80801178: bc1tl       L_80801198
    if (c1cs) {
        // 0x8080117C: swc1        $f0, 0x1C($a2)
        MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
            goto L_80801198;
    }
    goto skip_0;
    // 0x8080117C: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
    skip_0:
    // 0x80801180: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80801184: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80801188: nop

    // 0x8080118C: bc1fl       L_8080119C
    if (!c1cs) {
        // 0x80801190: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8080119C;
    }
    goto skip_1;
    // 0x80801190: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80801194: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
L_80801198:
    // 0x80801198: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8080119C:
    // 0x8080119C: jal         0x800EEB40
    // 0x808011A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x808011A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x808011A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808011A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808011AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808011B0: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808011B4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x808011B8: bc1fl       L_808011C8
    if (!c1cs) {
        // 0x808011BC: mtc1        $t8, $f16
        ctx->f16.u32l = ctx->r24;
            goto L_808011C8;
    }
    goto skip_2;
    // 0x808011BC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    skip_2:
    // 0x808011C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808011C4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
L_808011C8:
    // 0x808011C8: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x808011CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808011D0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808011D4: nop

    // 0x808011D8: bc1fl       L_808011F4
    if (!c1cs) {
        // 0x808011DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808011F4;
    }
    goto skip_3;
    // 0x808011DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808011E0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808011E4: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x808011E8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808011EC: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x808011F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011F4:
    // 0x808011F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011F8: jr          $ra
    // 0x808011FC: nop

    return;
    // 0x808011FC: nop

;}
RECOMP_FUNC void func_800CB910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB918: jal         0x800CB8F0
    // 0x800CB91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CB91C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CB920: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB928: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CB92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB930: srl         $t8, $t7, 9
    ctx->r24 = S32(U32(ctx->r15) >> 9);
    // 0x800CB934: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CB938: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CB93C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800CB940: jr          $ra
    // 0x800CB944: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x800CB944: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void func_80800318_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800328: jal         0x800C6E38
    // 0x8080032C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8080032C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80800330: beql        $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x80800334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B8;
    }
    goto skip_0;
    // 0x80800334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800338: jal         0x800F5410
    // 0x8080033C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x8080033C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800340: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800344: jal         0x80106790
    // 0x80800348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080034C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800354: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800358: bnel        $t6, $at, L_808003B8
    if (ctx->r14 != ctx->r1) {
        // 0x8080035C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B8;
    }
    goto skip_1;
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800360: lhu         $t7, 0x72($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X72);
    // 0x80800364: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800368: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080036C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800370: beq         $t8, $at, L_80800390
    if (ctx->r24 == ctx->r1) {
        // 0x80800374: addiu       $a1, $zero, 0x3B
        ctx->r5 = ADD32(0, 0X3B);
            goto L_80800390;
    }
    // 0x80800374: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80800378: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x8080037C: jal         0x800F7CF4
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F7CF4(rdram, ctx);
        goto after_3;
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800388: bne         $v0, $at, L_808003B4
    if (ctx->r2 != ctx->r1) {
        // 0x8080038C: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_808003B4;
    }
    // 0x8080038C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800390:
    // 0x80800390: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800394: lbu         $t3, 0x79($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X79);
    // 0x80800398: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080039C: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x808003A0: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808003A4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808003A8: sb          $t5, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r13;
    // 0x808003AC: jal         0x80101FDC
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_808003B4:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B8:
    // 0x808003B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void func_8008C0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C0DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C0E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C0E4: jal         0x8008B954
    // 0x8008C0E8: lh          $a0, 0xA($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XA);
    func_8008B954(rdram, ctx);
        goto after_0;
    // 0x8008C0E8: lh          $a0, 0xA($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XA);
    after_0:
    // 0x8008C0EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0F0: jal         0x8008B954
    // 0x8008C0F4: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    func_8008B954(rdram, ctx);
        goto after_1;
    // 0x8008C0F4: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    after_1:
    // 0x8008C0F8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C100: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x8008C104: bnel        $t8, $at, L_8008C118
    if (ctx->r24 != ctx->r1) {
        // 0x8008C108: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008C118;
    }
    goto skip_0;
    // 0x8008C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008C10C: jal         0x8008B954
    // 0x8008C110: lh          $a0, 0xE($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XE);
    func_8008B954(rdram, ctx);
        goto after_2;
    // 0x8008C110: lh          $a0, 0xE($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XE);
    after_2:
    // 0x8008C114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C118:
    // 0x8008C118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C11C: jr          $ra
    // 0x8008C120: nop

    return;
    // 0x8008C120: nop

;}
RECOMP_FUNC void func_8008CF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CF7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CF84: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CF88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8008CF8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008CF90: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x8008CF94: bnel        $t7, $zero, L_8008CFE4
    if (ctx->r15 != 0) {
        // 0x8008CF98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008CFE4;
    }
    goto skip_0;
    // 0x8008CF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008CF9C: jal         0x8008AD80
    // 0x8008CFA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8008AD80(rdram, ctx);
        goto after_0;
    // 0x8008CFA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008CFA4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8008CFA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CFAC: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x8008CFB0: sw          $v0, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r2;
    // 0x8008CFB4: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x8008CFB8: jal         0x8008B1A0
    // 0x8008CFBC: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008CFBC: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_1:
    // 0x8008CFC0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8008CFC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008CFC8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8008CFCC: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8008CFD0: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8008CFD4: bnel        $t0, $at, L_8008CFE4
    if (ctx->r8 != ctx->r1) {
        // 0x8008CFD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008CFE4;
    }
    goto skip_1;
    // 0x8008CFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8008CFDC: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x8008CFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008CFE4:
    // 0x8008CFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CFE8: jr          $ra
    // 0x8008CFEC: nop

    return;
    // 0x8008CFEC: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084498: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x80084498);
    return;
    // 0x8008449C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bstalk_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000DC: bne         $t6, $zero, L_808000E8
    if (ctx->r14 != 0) {
        // 0x808000E0: nop
    
            goto L_808000E8;
    }
    // 0x808000E0: nop

    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808000E8:
    // 0x808000E8: jal         0x8009E5C8
    // 0x808000EC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    bs_setState(rdram, ctx);
        goto after_0;
    // 0x808000EC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_0:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void _chheggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087798: syscall     622
    recomp_syscall_handler(rdram, ctx, 0x80087798);
    return;
    // 0x8008779C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chweather_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859E0: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859E0);
    return;
    // 0x800859E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800A4DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4E04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A4E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A4E0C: jal         0x800A3F14
    // 0x800A4E10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4E10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800A4E14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A4E18: jal         0x800A3B78
    // 0x800A4E1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A3B78(rdram, ctx);
        goto after_1;
    // 0x800A4E1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A4E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4E28: jr          $ra
    // 0x800A4E2C: nop

    return;
    // 0x800A4E2C: nop

;}
RECOMP_FUNC void func_80800FBC_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FCC: jal         0x80100094
    // 0x80800FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FD4: jal         0x800DC0C0
    // 0x80800FD8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800FD8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800FDC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800FE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FE4: nop

    // 0x80800FE8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800FEC: nop

    // 0x80800FF0: bc1f        L_80801000
    if (!c1cs) {
        // 0x80800FF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801000;
    }
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FF8: jal         0x80801D3C
    // 0x80800FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801D3C_chchuffy(rdram, ctx);
        goto after_2;
    // 0x80800FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80801000:
    // 0x80801000: jal         0x8080059C
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080059C_chchuffy(rdram, ctx);
        goto after_3;
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801008: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x8080100C: lui         $a2, 0x3F38
    ctx->r6 = S32(0X3F38 << 16);
    // 0x80801010: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x80801014: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801018: jal         0x80102320
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801020: beq         $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80801024: nop
    
            goto L_80801030;
    }
    // 0x80801024: nop

    // 0x80801028: jal         0x80801EAC
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EAC_chchuffy(rdram, ctx);
        goto after_5;
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80801030:
    // 0x80801030: jal         0x80801F04
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F04_chchuffy(rdram, ctx);
        goto after_6;
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801038: jal         0x80801DDC
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DDC_chchuffy(rdram, ctx);
        goto after_7;
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801040: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X24D0) << 16);
    // 0x80801044: addiu       $a1, $a1, 0x24D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X24D0));
    // 0x80801048: jal         0x80101E4C
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_8;
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801050: beq         $v0, $zero, L_80801088
    if (ctx->r2 == 0) {
        // 0x80801054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801088;
    }
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801058: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080105C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X238C) << 16);
    // 0x80801060: addiu       $a2, $a2, 0x238C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X238C));
    // 0x80801064: jal         0x80089D18
    // 0x80801068: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801068: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_9:
    // 0x8080106C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801070: jal         0x80801D94
    // 0x80801074: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801D94_chchuffy(rdram, ctx);
        goto after_10;
    // 0x80801074: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80801078: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2310) << 16);
    // 0x8080107C: lwc1        $f6, 0x2310($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2310));
    // 0x80801080: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80801084: swc1        $f6, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f6.u32l;
L_80801088:
    // 0x80801088: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X24E8) << 16);
    // 0x8080108C: addiu       $a1, $a1, 0x24E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X24E8));
    // 0x80801090: jal         0x80101E4C
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_11;
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801098: beq         $v0, $zero, L_808010B4
    if (ctx->r2 == 0) {
        // 0x8080109C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010B4;
    }
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X238C) << 16);
    // 0x808010A8: addiu       $a2, $a2, 0x238C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X238C));
    // 0x808010AC: jal         0x80089D18
    // 0x808010B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808010B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_12:
L_808010B4:
    // 0x808010B4: lui         $a1, 0x3F6C
    ctx->r5 = S32(0X3F6C << 16);
    // 0x808010B8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010BC: jal         0x80101E14
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808010C4: bne         $v0, $zero, L_808010E0
    if (ctx->r2 != 0) {
        // 0x808010C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010E0;
    }
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010CC: lui         $a1, 0x3F77
    ctx->r5 = S32(0X3F77 << 16);
    // 0x808010D0: jal         0x80101E14
    // 0x808010D4: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x808010D4: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_14:
    // 0x808010D8: beql        $v0, $zero, L_80801108
    if (ctx->r2 == 0) {
        // 0x808010DC: lui         $a1, 0x3F33
        ctx->r5 = S32(0X3F33 << 16);
            goto L_80801108;
    }
    goto skip_0;
    // 0x808010DC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    skip_0:
L_808010E0:
    // 0x808010E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X23A0) << 16);
    // 0x808010E8: addiu       $a2, $a2, 0x23A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X23A0));
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F0: jal         0x80089D18
    // 0x808010F4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x808010F4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_15:
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010FC: jal         0x80801CF8
    // 0x80801100: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801CF8_chchuffy(rdram, ctx);
        goto after_16;
    // 0x80801100: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x80801104: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
L_80801108:
    // 0x80801108: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080110C: jal         0x80101E14
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801114: beq         $v0, $zero, L_8080112C
    if (ctx->r2 == 0) {
        // 0x80801118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080112C;
    }
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080111C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801120: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801124: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80801128: swc1        $f8, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f8.u32l;
L_8080112C:
    // 0x8080112C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X23C8) << 16);
    // 0x80801134: lui         $a3, 0x3F61
    ctx->r7 = S32(0X3F61 << 16);
    // 0x80801138: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x8080113C: addiu       $a2, $a2, 0x23C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X23C8));
    // 0x80801140: jal         0x80089D20
    // 0x80801144: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80801144: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    after_18:
    // 0x80801148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080114C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801150: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801154: jr          $ra
    // 0x80801158: nop

    return;
    // 0x80801158: nop

;}
RECOMP_FUNC void func_808081AC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808081AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808081B0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808081B4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808081B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808081BC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808081C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808081C4: jal         0x800EE7F8
    // 0x808081C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808081C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808081CC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808081D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808081D4: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    // 0x808081D8: jal         0x800EF1B8
    // 0x808081DC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808081DC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x808081E0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808081E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808081E8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808081EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808081F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808081F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808081F8: jal         0x800EE7F8
    // 0x808081FC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808081FC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80808200: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80808204: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80808208: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080820C: lwc1        $f10, 0x48($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80808210: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80808214: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80808218: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080821C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80808220: jal         0x800EF1B8
    // 0x80808224: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80808224: nop

    after_3:
    // 0x80808228: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(1480, 0XA16C) << 16);
    // 0x8080822C: addiu       $t8, $t8, -0x5E94
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1480, 0XA16C));
    // 0x80808230: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80808234: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80808238: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080823C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80808240: jal         0x800BBCB8
    // 0x80808244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80808244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80808248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080824C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80808250: jr          $ra
    // 0x80808254: nop

    return;
    // 0x80808254: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AE0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087AE0);
    return;
    // 0x80087AE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800EFC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFC7C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EFC80: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFC84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EFC88: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EFC8C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EFC90: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFC94: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800EFC98: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EFC9C: bc1f        L_800EFCB4
    if (!c1cs) {
        // 0x800EFCA0: nop
    
            goto L_800EFCB4;
    }
    // 0x800EFCA0: nop

    // 0x800EFCA4: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800EFCA8: nop

    // 0x800EFCAC: bc1tl       L_800EFCCC
    if (c1cs) {
        // 0x800EFCB0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800EFCCC;
    }
    goto skip_0;
    // 0x800EFCB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
L_800EFCB4:
    // 0x800EFCB4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EFCB8: nop

    // 0x800EFCBC: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EFCC0: jr          $ra
    // 0x800EFCC4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    return;
    // 0x800EFCC4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800EFCC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800EFCCC:
    // 0x800EFCCC: nop

    // 0x800EFCD0: jr          $ra
    // 0x800EFCD4: nop

    return;
    // 0x800EFCD4: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EE8: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084EE8);
    return;
    // 0x80084EEC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void fxsplash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x80800064
    // 0x80800030: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    fxsplash_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800030: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_0:
    // 0x80800034: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2846, 0X130) << 16);
    // 0x80800038: addiu       $t6, $t6, 0x130
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2846, 0X130));
    // 0x8080003C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080004C: jal         0x800BABB8
    // 0x80800050: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800050: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800000_chswappy(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800010: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2156, 0X680) << 16);
    // 0x80800014: lwc1        $f6, 0x680($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2156, 0X680));
    // 0x80800018: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080001C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800020: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800024: jal         0x80102FDC
    // 0x80800028: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800028: nop

    after_0:
    // 0x8080002C: jal         0x800F8B88
    // 0x80800030: nop

    func_800F8B88(rdram, ctx);
        goto after_1;
    // 0x80800030: nop

    after_1:
    // 0x80800034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800038: bne         $v0, $at, L_80800074
    if (ctx->r2 != ctx->r1) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x80089C98
    // 0x80800048: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_2:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x80103110
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800058: jal         0x8010A590
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x808000B0
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080006C: b           L_808000A0
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000A0;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800074:
    // 0x80800074: jal         0x80089C98
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x80103110
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800088: jal         0x8010A570
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x808000B0
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_9;
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_800157EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800157EC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800157F0: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x800157F4: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800157F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800157FC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80015800: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80015804: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80015808: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001580C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80015810: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80015814: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x80015818: addiu       $t1, $t1, -0x6848
    ctx->r9 = ADD32(ctx->r9, -0X6848);
    // 0x8001581C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80015820: jr          $ra
    // 0x80015824: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x80015824: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void func_800BA54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA54C: jr          $ra
    // 0x800BA550: sh          $a1, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r5;
    return;
    // 0x800BA550: sh          $a1, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800178_sumissilehome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080017C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80800188: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080018C: jal         0x800EEF94
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800198: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: jal         0x800EFB24
    // 0x808001A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x808001AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B0: jal         0x800EF368
    // 0x808001B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x808001B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800854: jal         0x80800798
    // 0x80800858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800798_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080085C: bne         $v0, $zero, L_8080086C
    if (ctx->r2 != 0) {
        // 0x80800860: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080086C;
    }
    // 0x80800860: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800864: b           L_80800878
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800878;
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080086C:
    // 0x8080086C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80800870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800874: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_80800878:
    // 0x80800878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080087C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800880: jr          $ra
    // 0x80800884: nop

    return;
    // 0x80800884: nop

;}
RECOMP_FUNC void func_8080009C_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000B0: lhu         $a1, 0x76($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X76);
    // 0x808000B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808000B8: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x808000BC: jal         0x800DF744
    // 0x808000C0: addiu       $a1, $t7, -0x31
    ctx->r5 = ADD32(ctx->r15, -0X31);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808000C0: addiu       $a1, $t7, -0x31
    ctx->r5 = ADD32(ctx->r15, -0X31);
    after_0:
    // 0x808000C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: jal         0x80101870
    // 0x808000CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808000CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088168: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088168);
    return;
    // 0x8008816C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80803888_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080388C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803894: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803898: beq         $a2, $zero, L_808038A8
    if (ctx->r6 == 0) {
        // 0x8080389C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_808038A8;
    }
    // 0x8080389C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808038A0: b           L_808038AC
    // 0x808038A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_808038AC;
    // 0x808038A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_808038A8:
    // 0x808038A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808038AC:
    // 0x808038AC: jal         0x80016BDC
    // 0x808038B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80016BDC(rdram, ctx);
        goto after_0;
    // 0x808038B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x808038B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808038B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808038BC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x808038C0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808038C4: addiu       $a1, $a1, -0x7E90
    ctx->r5 = ADD32(ctx->r5, -0X7E90);
    // 0x808038C8: jal         0x800C9E20
    // 0x808038CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800C9E20(rdram, ctx);
        goto after_1;
    // 0x808038CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808038D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808038D4: jal         0x80800478
    // 0x808038D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800478_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808038D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x808038DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808038E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808038E4: jr          $ra
    // 0x808038E8: nop

    return;
    // 0x808038E8: nop

;}
RECOMP_FUNC void func_80804A38_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804A48: jal         0x80802C48
    // 0x80804A4C: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_80802C48_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804A4C: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x80804A50: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80804A54: jal         0x808026C8
    // 0x80804A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80804A5C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80804A60: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80804A64: beql        $a0, $zero, L_80804A7C
    if (ctx->r4 == 0) {
        // 0x80804A68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804A7C;
    }
    goto skip_0;
    // 0x80804A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804A6C: jal         0x800FFA88
    // 0x80804A70: nop

    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80804A70: nop

    after_2:
    // 0x80804A74: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80804A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804A7C:
    // 0x80804A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804A84: jr          $ra
    // 0x80804A88: nop

    return;
    // 0x80804A88: nop

;}
RECOMP_FUNC void badialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800100: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800104: jal         0x800DA298
    // 0x80800108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8080010C: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800110: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080011C;
    }
    // 0x80800110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: b           L_80800140
    // 0x80800118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800140;
    // 0x80800118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080011C:
    // 0x8080011C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: jal         0x8080007C
    // 0x80800124: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    badialog_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800124: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800128: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x8080012C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800138;
    }
    // 0x8080012C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800130: jal         0x800DA3B8
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800138:
    // 0x80800138: jal         0x800DA298
    // 0x8080013C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080013C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
L_80800140:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void bapackctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A8: jal         0x80800150
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bapackctrl_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void func_80802550_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802550: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080255C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802560: jal         0x80100094
    // 0x80802564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802568: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080256C: jal         0x808040D8
    // 0x80802570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808040D8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80802570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802574: jal         0x808049A8
    // 0x80802578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808049A8_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080257C: jal         0x808053BC
    // 0x80802580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808053BC_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80802580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802584: jal         0x80807664
    // 0x80802588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807664_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80802588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080258C: jal         0x80808000
    // 0x80802590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808000_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80802590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802594: jal         0x80808948
    // 0x80802598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808948_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80802598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080259C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808025A0: jal         0x801069A4
    // 0x808025A4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_801069A4(rdram, ctx);
        goto after_7;
    // 0x808025A4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_7:
    // 0x808025A8: beq         $v0, $zero, L_808025C0
    if (ctx->r2 == 0) {
        // 0x808025AC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_808025C0;
    }
    // 0x808025AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808025B0: jal         0x800FFA88
    // 0x808025B4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808025B4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_8:
    // 0x808025B8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808025BC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_808025C0:
    // 0x808025C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808025C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808025C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808025CC: jr          $ra
    // 0x808025D0: nop

    return;
    // 0x808025D0: nop

;}
RECOMP_FUNC void func_808046D0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808046D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808046D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808046D8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808046DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808046E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808046E4: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(804, 0X83E0) << 16);
    // 0x808046E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808046EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808046F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808046F4: addiu       $s1, $s1, -0x7C20
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(804, 0X83E0));
    // 0x808046F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808046FC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80804700:
    // 0x80804700: jal         0x80804948
    // 0x80804704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804948_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80804708: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080470C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804710: jal         0x808049E8
    // 0x80804714: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808049E8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804714: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80804718: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080471C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804720: jal         0x80087D90
    // 0x80804724: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x80804724: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    after_2:
    // 0x80804728: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080472C: bne         $s0, $s3, L_80804700
    if (ctx->r16 != ctx->r19) {
        // 0x80804730: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80804700;
    }
    // 0x80804730: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80804734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80804738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080473C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80804740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80804744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80804748: jr          $ra
    // 0x8080474C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080474C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80090220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090228: jal         0x800F54E4
    // 0x8009022C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009022C: nop

    after_0:
    // 0x80090230: jal         0x800F6C1C
    // 0x80090234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C1C(rdram, ctx);
        goto after_1;
    // 0x80090234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009023C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090240: jr          $ra
    // 0x80090244: nop

    return;
    // 0x80090244: nop

;}
RECOMP_FUNC void func_8001BF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001BF84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF88: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001BF8C: addiu       $s2, $s2, -0x1670
    ctx->r18 = ADD32(ctx->r18, -0X1670);
    // 0x8001BF90: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001BF94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001BF98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BFA0: blez        $a0, L_8001BFB0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001BFA4: lw          $s0, 0x14($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X14);
            goto L_8001BFB0;
    }
    // 0x8001BFA4: lw          $s0, 0x14($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X14);
    // 0x8001BFA8: b           L_8001BFB4
    // 0x8001BFAC: nop

        goto L_8001BFB4;
    // 0x8001BFAC: nop

L_8001BFB0:
    // 0x8001BFB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001BFB4:
    // 0x8001BFB4: jal         0x8001BD30
    // 0x8001BFB8: nop

    func_8001BD30(rdram, ctx);
        goto after_0;
    // 0x8001BFB8: nop

    after_0:
    // 0x8001BFBC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8001BFC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001BFC4: subu        $t8, $t7, $s0
    ctx->r24 = SUB32(ctx->r15, ctx->r16);
    // 0x8001BFC8: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8001BFCC: sltu        $at, $t9, $v0
    ctx->r1 = ctx->r25 < ctx->r2 ? 1 : 0;
    // 0x8001BFD0: beql        $at, $zero, L_8001C038
    if (ctx->r1 == 0) {
        // 0x8001BFD4: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_8001C038;
    }
    goto skip_0;
    // 0x8001BFD4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8001BFD8: jal         0x8001B3E8
    // 0x8001BFDC: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001BFDC: nop

    after_1:
    // 0x8001BFE0: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8001BFE4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8001BFE8: addiu       $t0, $v1, 0x20
    ctx->r8 = ADD32(ctx->r3, 0X20);
    // 0x8001BFEC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8001BFF0: beql        $t0, $t2, L_8001C038
    if (ctx->r8 == ctx->r10) {
        // 0x8001BFF4: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_8001C038;
    }
    goto skip_1;
    // 0x8001BFF4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8001BFF8: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
L_8001BFFC:
    // 0x8001BFFC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8001C000: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x8001C004: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x8001C008: sltu        $at, $t5, $s1
    ctx->r1 = ctx->r13 < ctx->r17 ? 1 : 0;
    // 0x8001C00C: beql        $at, $zero, L_8001C038
    if (ctx->r1 == 0) {
        // 0x8001C010: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_8001C038;
    }
    goto skip_2;
    // 0x8001C010: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x8001C014: jal         0x8001B3E8
    // 0x8001C018: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_2;
    // 0x8001C018: nop

    after_2:
    // 0x8001C01C: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8001C020: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001C024: addiu       $t6, $v1, 0x20
    ctx->r14 = ADD32(ctx->r3, 0X20);
    // 0x8001C028: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001C02C: bnel        $t6, $t8, L_8001BFFC
    if (ctx->r14 != ctx->r24) {
        // 0x8001C030: lw          $t3, 0x4($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X4);
            goto L_8001BFFC;
    }
    goto skip_3;
    // 0x8001C030: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x8001C034: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_8001C038:
    // 0x8001C038: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C03C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001C040: subu        $t1, $t9, $s0
    ctx->r9 = SUB32(ctx->r25, ctx->r16);
    // 0x8001C044: addiu       $t0, $t1, -0x10
    ctx->r8 = ADD32(ctx->r9, -0X10);
    // 0x8001C048: sltu        $at, $t0, $s1
    ctx->r1 = ctx->r8 < ctx->r17 ? 1 : 0;
    // 0x8001C04C: beq         $at, $zero, L_8001C05C
    if (ctx->r1 == 0) {
        // 0x8001C050: lw          $s1, 0x1C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X1C);
            goto L_8001C05C;
    }
    // 0x8001C050: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C054: b           L_8001C060
    // 0x8001C058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8001C060;
    // 0x8001C058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C05C:
    // 0x8001C05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001C060:
    // 0x8001C060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C068: jr          $ra
    // 0x8001C06C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8001C06C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8001D3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D3DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D3E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D3E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D3E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D3EC: lh          $a3, 0x26($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X26);
    // 0x8001D3F0: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8001D3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D3F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D3FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D400: sw          $t6, -0x2EA0($at)
    MEM_W(-0X2EA0, ctx->r1) = ctx->r14;
    // 0x8001D404: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x8001D408: jal         0x8001D9CC
    // 0x8001D40C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    func_8001D9CC(rdram, ctx);
        goto after_0;
    // 0x8001D40C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_0:
    // 0x8001D410: or          $a3, $sp, $zero
    ctx->r7 = ctx->r29 | 0;
    // 0x8001D414: addiu       $a3, $a3, 0x2F
    ctx->r7 = ADD32(ctx->r7, 0X2F);
    // 0x8001D418: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001D41C: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x8001D420: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001D424: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    // 0x8001D428: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8001D42C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D430: jal         0x80030B30
    // 0x8001D434: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _Printf(rdram, ctx);
        goto after_1;
    // 0x8001D434: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8001D438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D43C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D440: jr          $ra
    // 0x8001D444: nop

    return;
    // 0x8001D444: nop

    // 0x8001D448: nop

    // 0x8001D44C: nop

;}
RECOMP_FUNC void _chlagoonlockerdoorhits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087100: syscall     516
    recomp_syscall_handler(rdram, ctx, 0x80087100);
    return;
    // 0x80087104: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F21C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F21C4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F21C8: lui         $t0, 0x7F
    ctx->r8 = S32(0X7F << 16);
    // 0x800F21CC: srl         $a1, $a2, 23
    ctx->r5 = S32(U32(ctx->r6) >> 23);
    // 0x800F21D0: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x800F21D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F21D8: and         $a2, $a2, $t0
    ctx->r6 = ctx->r6 & ctx->r8;
    // 0x800F21DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800F21E0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800F21E4: bne         $a1, $t0, L_800F222C
    if (ctx->r5 != ctx->r8) {
        // 0x800F21E8: andi        $a0, $a0, 0x100
        ctx->r4 = ctx->r4 & 0X100;
            goto L_800F222C;
    }
    // 0x800F21E8: andi        $a0, $a0, 0x100
    ctx->r4 = ctx->r4 & 0X100;
    // 0x800F21EC: bne         $a2, $zero, L_800F220C
    if (ctx->r6 != 0) {
        // 0x800F21F0: nop
    
            goto L_800F220C;
    }
    // 0x800F21F0: nop

    // 0x800F21F4: bne         $a0, $zero, L_800F2204
    if (ctx->r4 != 0) {
        // 0x800F21F8: nop
    
            goto L_800F2204;
    }
    // 0x800F21F8: nop

    // 0x800F21FC: jr          $ra
    // 0x800F2200: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800F2200: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F2204:
    // 0x800F2204: jr          $ra
    // 0x800F2208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800F2208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800F220C:
    // 0x800F220C: lui         $t0, 0x40
    ctx->r8 = S32(0X40 << 16);
    // 0x800F2210: and         $a0, $a2, $t0
    ctx->r4 = ctx->r6 & ctx->r8;
    // 0x800F2214: beq         $a0, $zero, L_800F2224
    if (ctx->r4 == 0) {
        // 0x800F2218: nop
    
            goto L_800F2224;
    }
    // 0x800F2218: nop

    // 0x800F221C: jr          $ra
    // 0x800F2220: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x800F2220: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800F2224:
    // 0x800F2224: jr          $ra
    // 0x800F2228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F2228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F222C:
    // 0x800F222C: bne         $a1, $zero, L_800F226C
    if (ctx->r5 != 0) {
        // 0x800F2230: nop
    
            goto L_800F226C;
    }
    // 0x800F2230: nop

    // 0x800F2234: bne         $a2, $zero, L_800F2254
    if (ctx->r6 != 0) {
        // 0x800F2238: nop
    
            goto L_800F2254;
    }
    // 0x800F2238: nop

    // 0x800F223C: bne         $a0, $zero, L_800F224C
    if (ctx->r4 != 0) {
        // 0x800F2240: nop
    
            goto L_800F224C;
    }
    // 0x800F2240: nop

    // 0x800F2244: jr          $ra
    // 0x800F2248: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800F2248: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800F224C:
    // 0x800F224C: jr          $ra
    // 0x800F2250: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x800F2250: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800F2254:
    // 0x800F2254: bne         $a0, $zero, L_800F2264
    if (ctx->r4 != 0) {
        // 0x800F2258: nop
    
            goto L_800F2264;
    }
    // 0x800F2258: nop

    // 0x800F225C: jr          $ra
    // 0x800F2260: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x800F2260: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800F2264:
    // 0x800F2264: jr          $ra
    // 0x800F2268: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x800F2268: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800F226C:
    // 0x800F226C: bne         $a0, $zero, L_800F227C
    if (ctx->r4 != 0) {
        // 0x800F2270: nop
    
            goto L_800F227C;
    }
    // 0x800F2270: nop

    // 0x800F2274: jr          $ra
    // 0x800F2278: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800F2278: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800F227C:
    // 0x800F227C: jr          $ra
    // 0x800F2280: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800F2280: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
;}
RECOMP_FUNC void func_808002D8_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002E8: jal         0x8008CABC
    // 0x808002EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808002F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002F4: jal         0x8008AF24
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x8008B1A0
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x8008AED4
    // 0x80800310: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800310: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x8008B1BC
    // 0x8080031C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x8080031C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x8008B134
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080032C: jal         0x8008B064
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800334: jal         0x800A3394
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A3394(rdram, ctx);
        goto after_7;
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080033C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800344: jal         0x800917A8
    // 0x80800348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_set(rdram, ctx);
        goto after_8;
    // 0x80800348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080034C: jal         0x800C77DC
    // 0x80800350: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C77DC(rdram, ctx);
        goto after_9;
    // 0x80800350: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x80800354: jal         0x800C3BDC
    // 0x80800358: lbu         $a0, 0x160($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X160);
    func_800C3BDC(rdram, ctx);
        goto after_10;
    // 0x80800358: lbu         $a0, 0x160($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X160);
    after_10:
    // 0x8080035C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800360: sw          $t6, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r14;
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800368: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080036C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800370: jr          $ra
    // 0x80800374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800005EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800005EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800005F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800005F4: jal         0x800016CC
    // 0x800005F8: nop

    func_800016CC(rdram, ctx);
        goto after_0;
    // 0x800005F8: nop

    after_0:
    // 0x800005FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000604: jr          $ra
    // 0x80000608: nop

    return;
    // 0x80000608: nop

;}
RECOMP_FUNC void func_800A5144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A514C: jal         0x8008FFE8
    // 0x800A5150: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A5150: nop

    after_0:
    // 0x800A5154: jal         0x8010FD88
    // 0x800A5158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FD88(rdram, ctx);
        goto after_1;
    // 0x800A5158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A515C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5164: jr          $ra
    // 0x800A5168: nop

    return;
    // 0x800A5168: nop

;}
RECOMP_FUNC void func_800A6EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6EF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A6EF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6EFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6F00: jal         0x800EA05C
    // 0x800A6F04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800A6F04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A6F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A6F0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800A6F10: jal         0x8010A800
    // 0x800A6F14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x800A6F14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A6F18: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x800A6F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6F24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800A6F28: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x800A6F2C: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x800A6F30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A6F34: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x800A6F38: lh          $t8, -0x5D20($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5D20);
    // 0x800A6F3C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A6F40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A6F44: beq         $a0, $t8, L_800A6F78
    if (ctx->r4 == ctx->r24) {
        // 0x800A6F48: addiu       $v0, $t9, -0x5D20
        ctx->r2 = ADD32(ctx->r25, -0X5D20);
            goto L_800A6F78;
    }
    // 0x800A6F48: addiu       $v0, $t9, -0x5D20
    ctx->r2 = ADD32(ctx->r25, -0X5D20);
    // 0x800A6F4C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_800A6F50:
    // 0x800A6F50: bnel        $a2, $v1, L_800A6F6C
    if (ctx->r6 != ctx->r3) {
        // 0x800A6F54: lh          $v1, 0x2($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X2);
            goto L_800A6F6C;
    }
    goto skip_0;
    // 0x800A6F54: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    skip_0:
    // 0x800A6F58: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x800A6F5C: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x800A6F60: b           L_800A6F78
    // 0x800A6F64: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
        goto L_800A6F78;
    // 0x800A6F64: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    // 0x800A6F68: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
L_800A6F6C:
    // 0x800A6F6C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800A6F70: bne         $a0, $v1, L_800A6F50
    if (ctx->r4 != ctx->r3) {
        // 0x800A6F74: nop
    
            goto L_800A6F50;
    }
    // 0x800A6F74: nop

L_800A6F78:
    // 0x800A6F78: jal         0x800A9C98
    // 0x800A6F7C: nop

    func_800A9C98(rdram, ctx);
        goto after_2;
    // 0x800A6F7C: nop

    after_2:
    // 0x800A6F80: beq         $v0, $zero, L_800A6F9C
    if (ctx->r2 == 0) {
        // 0x800A6F84: nop
    
            goto L_800A6F9C;
    }
    // 0x800A6F84: nop

    // 0x800A6F88: jal         0x800A9CD0
    // 0x800A6F8C: nop

    func_800A9CD0(rdram, ctx);
        goto after_3;
    // 0x800A6F8C: nop

    after_3:
    // 0x800A6F90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A6F94: bnel        $v0, $at, L_800A6FD4
    if (ctx->r2 != ctx->r1) {
        // 0x800A6F98: lbu         $t4, 0x74($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X74);
            goto L_800A6FD4;
    }
    goto skip_1;
    // 0x800A6F98: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    skip_1:
L_800A6F9C:
    // 0x800A6F9C: jal         0x800BCC84
    // 0x800A6FA0: nop

    func_800BCC84(rdram, ctx);
        goto after_4;
    // 0x800A6FA0: nop

    after_4:
    // 0x800A6FA4: bnel        $v0, $zero, L_800A6FD4
    if (ctx->r2 != 0) {
        // 0x800A6FA8: lbu         $t4, 0x74($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X74);
            goto L_800A6FD4;
    }
    goto skip_2;
    // 0x800A6FA8: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    skip_2:
    // 0x800A6FAC: jal         0x800D3948
    // 0x800A6FB0: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x800A6FB0: nop

    after_5:
    // 0x800A6FB4: bnel        $v0, $zero, L_800A6FD4
    if (ctx->r2 != 0) {
        // 0x800A6FB8: lbu         $t4, 0x74($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X74);
            goto L_800A6FD4;
    }
    goto skip_3;
    // 0x800A6FB8: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    skip_3:
    // 0x800A6FBC: jal         0x800A946C
    // 0x800A6FC0: nop

    func_800A946C(rdram, ctx);
        goto after_6;
    // 0x800A6FC0: nop

    after_6:
    // 0x800A6FC4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A6FC8: bnel        $at, $zero, L_800A6FE0
    if (ctx->r1 != 0) {
        // 0x800A6FCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6FE0;
    }
    goto skip_4;
    // 0x800A6FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800A6FD0: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
L_800A6FD4:
    // 0x800A6FD4: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x800A6FD8: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x800A6FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6FE0:
    // 0x800A6FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A6FE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A6FE8: jr          $ra
    // 0x800A6FEC: nop

    return;
    // 0x800A6FEC: nop

;}
RECOMP_FUNC void func_808009DC_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808009E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808009EC: jal         0x80100094
    // 0x808009F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808009F8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808009FC: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    // 0x80800A00: beql        $a2, $a0, L_80800C30
    if (ctx->r6 == ctx->r4) {
        // 0x80800A04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C30;
    }
    goto skip_0;
    // 0x80800A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A08: beq         $a0, $zero, L_80800A34
    if (ctx->r4 == 0) {
        // 0x80800A0C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800A34;
    }
    // 0x80800A0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A14: beq         $a0, $v0, L_80800B28
    if (ctx->r4 == ctx->r2) {
        // 0x80800A18: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B28;
    }
    // 0x80800A18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A1C: beq         $a0, $at, L_80800A84
    if (ctx->r4 == ctx->r1) {
        // 0x80800A20: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A84;
    }
    // 0x80800A20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A24: beq         $a0, $at, L_80800B28
    if (ctx->r4 == ctx->r1) {
        // 0x80800A28: nop
    
            goto L_80800B28;
    }
    // 0x80800A28: nop

    // 0x80800A2C: b           L_80800C28
    // 0x80800A30: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
        goto L_80800C28;
    // 0x80800A30: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80800A34:
    // 0x80800A34: beq         $a2, $at, L_80800A44
    if (ctx->r6 == ctx->r1) {
        // 0x80800A38: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80800A44;
    }
    // 0x80800A38: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800A3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A40: bne         $a2, $at, L_80800C24
    if (ctx->r6 != ctx->r1) {
        // 0x80800A44: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_80800C24;
    }
L_80800A44:
    // 0x80800A44: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80800A48: jal         0x800904F4
    // 0x80800A4C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800904F4(rdram, ctx);
        goto after_1;
    // 0x80800A4C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800A50: jal         0x80104268
    // 0x80800A54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80104268(rdram, ctx);
        goto after_2;
    // 0x80800A54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800A58: jal         0x80801428
    // 0x80800A5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801428_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80800A5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800A60: jal         0x800F54E4
    // 0x80800A64: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800A64: nop

    after_4:
    // 0x80800A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A6C: jal         0x800F4CEC
    // 0x80800A70: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    func_800F4CEC(rdram, ctx);
        goto after_5;
    // 0x80800A70: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    after_5:
    // 0x80800A74: jal         0x80802CF0
    // 0x80800A78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_6;
    // 0x80800A78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800A7C: b           L_80800C24
    // 0x80800A80: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
        goto L_80800C24;
    // 0x80800A80: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_80800A84:
    // 0x80800A84: beq         $a2, $v0, L_80800A94
    if (ctx->r6 == ctx->r2) {
        // 0x80800A88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A94;
    }
    // 0x80800A88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A8C: bnel        $a2, $at, L_80800C28
    if (ctx->r6 != ctx->r1) {
        // 0x80800A90: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80800C28;
    }
    goto skip_1;
    // 0x80800A90: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_80800A94:
    // 0x80800A94: jal         0x800904C8
    // 0x80800A98: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800904C8(rdram, ctx);
        goto after_7;
    // 0x80800A98: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_7:
    // 0x80800A9C: jal         0x800F54E4
    // 0x80800AA0: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800AA0: nop

    after_8:
    // 0x80800AA4: jal         0x800F4CC0
    // 0x80800AA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_9;
    // 0x80800AA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AB0: jal         0x800BF4A4
    // 0x80800AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF4A4(rdram, ctx);
        goto after_10;
    // 0x80800AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800AB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800ABC: jal         0x800BF4A4
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF4A4(rdram, ctx);
        goto after_11;
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800AC4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800AC8: lbu         $t8, 0x75($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X75);
    // 0x80800ACC: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800AD0: jal         0x8008FFE8
    // 0x80800AD4: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
    func_8008FFE8(rdram, ctx);
        goto after_12;
    // 0x80800AD4: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
    after_12:
    // 0x80800AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800ADC: jal         0x8010FD38
    // 0x80800AE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8010FD38(rdram, ctx);
        goto after_13;
    // 0x80800AE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x80800AE4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AE8: jal         0x80104200
    // 0x80800AEC: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    func_80104200(rdram, ctx);
        goto after_14;
    // 0x80800AEC: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    after_14:
    // 0x80800AF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800AF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AF8: jal         0x8008AED4
    // 0x80800AFC: addiu       $a1, $zero, 0x486
    ctx->r5 = ADD32(0, 0X486);
    anctrl_setIndex(rdram, ctx);
        goto after_15;
    // 0x80800AFC: addiu       $a1, $zero, 0x486
    ctx->r5 = ADD32(0, 0X486);
    after_15:
    // 0x80800B00: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800B04: jal         0x8008B1BC
    // 0x80800B08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_16;
    // 0x80800B08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80800B0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800B10: jal         0x8008B134
    // 0x80800B14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_17;
    // 0x80800B14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800B18: jal         0x8008B064
    // 0x80800B1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_start(rdram, ctx);
        goto after_18;
    // 0x80800B1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x80800B20: b           L_80800C24
    // 0x80800B24: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
        goto L_80800C24;
    // 0x80800B24: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_80800B28:
    // 0x80800B28: beq         $a2, $zero, L_80800C00
    if (ctx->r6 == 0) {
        // 0x80800B2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C00;
    }
    // 0x80800B2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B30: bnel        $a2, $at, L_80800C28
    if (ctx->r6 != ctx->r1) {
        // 0x80800B34: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80800C28;
    }
    goto skip_2;
    // 0x80800B34: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80800B38: jal         0x800F54E4
    // 0x80800B3C: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800B3C: nop

    after_19:
    // 0x80800B40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B44: jal         0x800F4CEC
    // 0x80800B48: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_800F4CEC(rdram, ctx);
        goto after_20;
    // 0x80800B48: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_20:
    // 0x80800B4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B50: jal         0x800BF4A4
    // 0x80800B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF4A4(rdram, ctx);
        goto after_21;
    // 0x80800B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800B58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800B5C: jal         0x800BF4A4
    // 0x80800B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF4A4(rdram, ctx);
        goto after_22;
    // 0x80800B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800B64: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800B68: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800B6C: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
    // 0x80800B70: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800B74: jal         0x800904C8
    // 0x80800B78: sb          $t2, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r10;
    func_800904C8(rdram, ctx);
        goto after_23;
    // 0x80800B78: sb          $t2, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r10;
    after_23:
    // 0x80800B7C: jal         0x80802CF0
    // 0x80800B80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_24;
    // 0x80800B80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x80800B84: jal         0x8008FFE8
    // 0x80800B88: nop

    func_8008FFE8(rdram, ctx);
        goto after_25;
    // 0x80800B88: nop

    after_25:
    // 0x80800B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B90: jal         0x8010FD38
    // 0x80800B94: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    func_8010FD38(rdram, ctx);
        goto after_26;
    // 0x80800B94: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    after_26:
    // 0x80800B98: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B9C: jal         0x80104200
    // 0x80800BA0: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    func_80104200(rdram, ctx);
        goto after_27;
    // 0x80800BA0: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    after_27:
    // 0x80800BA4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BA8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800BAC: jal         0x80104200
    // 0x80800BB0: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    func_80104200(rdram, ctx);
        goto after_28;
    // 0x80800BB0: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    after_28:
    // 0x80800BB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800BB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BBC: jal         0x8008AED4
    // 0x80800BC0: addiu       $a1, $zero, 0x484
    ctx->r5 = ADD32(0, 0X484);
    anctrl_setIndex(rdram, ctx);
        goto after_29;
    // 0x80800BC0: addiu       $a1, $zero, 0x484
    ctx->r5 = ADD32(0, 0X484);
    after_29:
    // 0x80800BC4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BC8: jal         0x8008AED4
    // 0x80800BCC: addiu       $a1, $zero, 0x489
    ctx->r5 = ADD32(0, 0X489);
    anctrl_setIndex(rdram, ctx);
        goto after_30;
    // 0x80800BCC: addiu       $a1, $zero, 0x489
    ctx->r5 = ADD32(0, 0X489);
    after_30:
    // 0x80800BD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD4: jal         0x8008B134
    // 0x80800BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_31;
    // 0x80800BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_31:
    // 0x80800BDC: jal         0x8008B064
    // 0x80800BE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_start(rdram, ctx);
        goto after_32;
    // 0x80800BE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_32:
    // 0x80800BE4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE8: jal         0x8008B134
    // 0x80800BEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_33;
    // 0x80800BEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_33:
    // 0x80800BF0: jal         0x8008B064
    // 0x80800BF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_start(rdram, ctx);
        goto after_34;
    // 0x80800BF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_34:
    // 0x80800BF8: b           L_80800C24
    // 0x80800BFC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
        goto L_80800C24;
    // 0x80800BFC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_80800C00:
    // 0x80800C00: jal         0x800904C8
    // 0x80800C04: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_35;
    // 0x80800C04: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_35:
    // 0x80800C08: jal         0x800F54E4
    // 0x80800C0C: nop

    func_800F54E4(rdram, ctx);
        goto after_36;
    // 0x80800C0C: nop

    after_36:
    // 0x80800C10: jal         0x800F4CC0
    // 0x80800C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_37;
    // 0x80800C14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_37:
    // 0x80800C18: jal         0x8080149C
    // 0x80800C1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8080149C_chflysaucer(rdram, ctx);
        goto after_38;
    // 0x80800C1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_38:
    // 0x80800C20: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_80800C24:
    // 0x80800C24: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80800C28:
    // 0x80800C28: sb          $a2, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r6;
    // 0x80800C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C30:
    // 0x80800C30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C34: jr          $ra
    // 0x80800C38: nop

    return;
    // 0x80800C38: nop

;}
RECOMP_FUNC void func_8080047C_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $t6, $a1, -0x17E9
    ctx->r14 = ADD32(ctx->r5, -0X17E9);
    // 0x80800480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800484: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080048C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800490: beq         $at, $zero, L_80800520
    if (ctx->r1 == 0) {
        // 0x80800494: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800520;
    }
    // 0x80800494: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800498: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1408) << 16);
    // 0x808004A0: addu        $at, $at, $t6
    gpr jr_addend_808004A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808004A4: lw          $t6, 0x1408($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1408));
    // 0x808004A8: jr          $t6
    // 0x808004AC: nop

    switch (jr_addend_808004A8 >> 2) {
        case 0: goto L_808004B0; break;
        case 1: goto L_808004C4; break;
        case 2: goto L_808004D8; break;
        case 3: goto L_808004EC; break;
        case 4: goto L_80800514; break;
        default: switch_error(__func__, 0x808004A8, 0x80801408);
    }
    // 0x808004AC: nop

L_808004B0:
    // 0x808004B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004B4: jal         0x80800654
    // 0x808004B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800654_chdippy(rdram, ctx);
        goto after_0;
    // 0x808004B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x808004BC: b           L_80800524
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004C4:
    // 0x808004C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004C8: jal         0x80800654
    // 0x808004CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800654_chdippy(rdram, ctx);
        goto after_1;
    // 0x808004CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x808004D0: b           L_80800524
    // 0x808004D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x808004D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004D8:
    // 0x808004D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004DC: jal         0x80800654
    // 0x808004E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800654_chdippy(rdram, ctx);
        goto after_2;
    // 0x808004E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x808004E4: b           L_80800524
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004EC:
    // 0x808004EC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004F8: jal         0x800D0C78
    // 0x808004FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800D0C78(rdram, ctx);
        goto after_3;
    // 0x808004FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800504: jal         0x80800654
    // 0x80800508: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800654_chdippy(rdram, ctx);
        goto after_4;
    // 0x80800508: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x8080050C: b           L_80800524
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800514:
    // 0x80800514: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800518: jal         0x80800654
    // 0x8080051C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800654_chdippy(rdram, ctx);
        goto after_5;
    // 0x8080051C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
L_80800520:
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800524:
    // 0x80800524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800528: jr          $ra
    // 0x8080052C: nop

    return;
    // 0x8080052C: nop

;}
RECOMP_FUNC void func_808008B4_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008C4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x808008C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808008CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808008D0: beq         $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808008D4: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_808008FC;
    }
    // 0x808008D4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x808008D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008DC: beq         $v0, $at, L_80800914
    if (ctx->r2 == ctx->r1) {
        // 0x808008E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800914;
    }
    // 0x808008E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008E4: beq         $v0, $at, L_8080090C
    if (ctx->r2 == ctx->r1) {
        // 0x808008E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080090C;
    }
    // 0x808008E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008EC: beql        $v0, $at, L_80800910
    if (ctx->r2 == ctx->r1) {
        // 0x808008F0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800910;
    }
    goto skip_0;
    // 0x808008F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x808008F4: b           L_80800928
    // 0x808008F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800928;
    // 0x808008F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008FC:
    // 0x808008FC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800900: jal         0x800856B0
    // 0x80800904: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800904: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800908: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8080090C:
    // 0x8080090C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800910:
    // 0x80800910: sw          $t6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r14;
L_80800914:
    // 0x80800914: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800918: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080091C: jal         0x800856D0
    // 0x80800920: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800920: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800928:
    // 0x80800928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void _fxtwinkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AA8: syscall     720
    recomp_syscall_handler(rdram, ctx, 0x80088AA8);
    return;
    // 0x80088AAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncbadive_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x80800064: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800068: jal         0x801120CC
    // 0x8080006C: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x8080006C: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void bsrest_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008EC: jal         0x80800864
    // 0x808008F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bsrest_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808008F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808008F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008FC: jr          $ra
    // 0x80800900: nop

    return;
    // 0x80800900: nop

;}
RECOMP_FUNC void func_80091EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091ED0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80091ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80091ED8: jal         0x80091F74
    // 0x80091EDC: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    func_80091F74(rdram, ctx);
        goto after_0;
    // 0x80091EDC: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    after_0:
    // 0x80091EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091EE8: jr          $ra
    // 0x80091EEC: nop

    return;
    // 0x80091EEC: nop

;}
RECOMP_FUNC void func_8080086C_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800870: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800878: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080087C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800884: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800888: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8080088C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80800890: jal         0x8010A654
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A654(rdram, ctx);
        goto after_0;
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800898: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080089C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808008A0: jal         0x800EE7F8
    // 0x808008A4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808008A4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_1:
    // 0x808008A8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808008AC: jal         0x800EE7F8
    // 0x808008B0: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808008B0: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x808008B4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808008B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008C0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808008C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008C8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808008CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808008D0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808008D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808008D8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808008DC: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x808008E0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x808008E4: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x808008E8: jal         0x800C6A7C
    // 0x808008EC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x808008EC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x808008F0: bne         $v0, $zero, L_80800950
    if (ctx->r2 != 0) {
        // 0x808008F4: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80800950;
    }
    // 0x808008F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808008F8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x808008FC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800900: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800904: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800908: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080090C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800910: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800914: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800918: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8080091C: jal         0x800C6A7C
    // 0x80800920: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_4;
    // 0x80800920: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x80800924: bne         $v0, $zero, L_80800950
    if (ctx->r2 != 0) {
        // 0x80800928: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80800950;
    }
    // 0x80800928: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080092C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800930: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80800934: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800938: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8080093C: jal         0x8010A654
    // 0x80800940: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8010A654(rdram, ctx);
        goto after_5;
    // 0x80800940: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800944: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80800948: b           L_808009E0
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009E0;
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800950:
    // 0x80800950: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800958: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8080095C: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
    // 0x80800960: jal         0x8010A654
    // 0x80800964: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8010A654(rdram, ctx);
        goto after_6;
    // 0x80800964: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800968: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080096C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800970: jal         0x800EE7F8
    // 0x80800974: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800974: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_7:
    // 0x80800978: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8080097C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800980: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800984: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80800988: jal         0x800F0E00
    // 0x8080098C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    func_800F0E00(rdram, ctx);
        goto after_8;
    // 0x8080098C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    after_8:
    // 0x80800990: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80800994: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800998: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080099C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808009A0: jal         0x800F1988
    // 0x808009A4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    func_800F1988(rdram, ctx);
        goto after_9;
    // 0x808009A4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    after_9:
    // 0x808009A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808009B4: jal         0x8010279C
    // 0x808009B8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_8010279C(rdram, ctx);
        goto after_10;
    // 0x808009B8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x808009BC: lh          $t2, 0x8E($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8E);
    // 0x808009C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009C4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808009C8: beq         $t2, $zero, L_808009DC
    if (ctx->r10 == 0) {
        // 0x808009CC: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_808009DC;
    }
    // 0x808009CC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808009D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808009D4: jal         0x801045AC
    // 0x808009D8: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    func_801045AC(rdram, ctx);
        goto after_11;
    // 0x808009D8: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    after_11:
L_808009DC:
    // 0x808009DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009E0:
    // 0x808009E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808009E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808009EC: jr          $ra
    // 0x808009F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808009F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808009F4: nop

    // 0x808009F8: nop

    // 0x808009FC: nop

;}
RECOMP_FUNC void _fxsparkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888C8: syscall     709
    recomp_syscall_handler(rdram, ctx, 0x800888C8);
    return;
    // 0x800888CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
