#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080003C_chdinotraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80085808
    // 0x8080004C: addiu       $a1, $zero, 0x164
    ctx->r5 = ADD32(0, 0X164);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x164
    ctx->r5 = ADD32(0, 0X164);
    after_0:
    // 0x80800050: jal         0x80085818
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800058: jal         0x80104E78
    // 0x8080005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80104E78(rdram, ctx);
        goto after_2;
    // 0x8080005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_80100368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100370: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x80100374: jalr        $t9
    // 0x80100378: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80100378: nop

    after_0:
    // 0x8010037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100384: jr          $ra
    // 0x80100388: nop

    return;
    // 0x80100388: nop

;}
RECOMP_FUNC void func_8008CA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA30: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008CA34: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008CA3C: swc1        $f12, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f12.u32l;
    // 0x8008CA40: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA44: jr          $ra
    // 0x8008CA48: sb          $t7, 0x38($t8)
    MEM_B(0X38, ctx->r24) = ctx->r15;
    return;
    // 0x8008CA48: sb          $t7, 0x38($t8)
    MEM_B(0X38, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_80094F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F80: jr          $ra
    // 0x80094F84: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80094F84: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800328_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080032C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x8080033C: srl         $t6, $a0, 5
    ctx->r14 = S32(U32(ctx->r4) >> 5);
    // 0x80800340: jal         0x800F4B4C
    // 0x80800344: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F4B4C(rdram, ctx);
        goto after_0;
    // 0x80800344: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800348: beql        $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x8080034C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080045C;
    }
    goto skip_0;
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800350: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800354: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80800358: addiu       $a1, $a1, -0x5D68
    ctx->r5 = ADD32(ctx->r5, -0X5D68);
    // 0x8080035C: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80800360: beq         $t7, $zero, L_80800384
    if (ctx->r15 == 0) {
        // 0x80800364: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80800384;
    }
    // 0x80800364: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080036C: beq         $t7, $at, L_808003F4
    if (ctx->r15 == ctx->r1) {
        // 0x80800370: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003F4;
    }
    // 0x80800370: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800374: beq         $t7, $at, L_808003B4
    if (ctx->r15 == ctx->r1) {
        // 0x80800378: nop
    
            goto L_808003B4;
    }
    // 0x80800378: nop

    // 0x8080037C: b           L_80800430
    // 0x80800380: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800430;
    // 0x80800380: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800384:
    // 0x80800384: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800388: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    // 0x8080038C: jal         0x800C9E20
    // 0x80800390: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C9E20(rdram, ctx);
        goto after_1;
    // 0x80800390: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80800394: jal         0x8008FC50
    // 0x80800398: nop

    func_8008FC50(rdram, ctx);
        goto after_2;
    // 0x80800398: nop

    after_2:
    // 0x8080039C: jal         0x800FC660
    // 0x808003A0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x808003A0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x808003A4: jal         0x800FFAB0
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003AC: b           L_80800430
    // 0x808003B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800430;
    // 0x808003B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_808003B4:
    // 0x808003B4: jal         0x800FC660
    // 0x808003B8: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x808003B8: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_5:
    // 0x808003BC: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x808003C0: jal         0x800DA9E4
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808003C8: bne         $v0, $zero, L_808003E4
    if (ctx->r2 != 0) {
        // 0x808003CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E4;
    }
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x808000C4
    // 0x808003D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808000C4_chhoney(rdram, ctx);
        goto after_7;
    // 0x808003D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x808003DC: b           L_80800430
    // 0x808003E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800430;
    // 0x808003E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_808003E4:
    // 0x808003E4: jal         0x808000C4
    // 0x808003E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000C4_chhoney(rdram, ctx);
        goto after_8;
    // 0x808003E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808003EC: b           L_80800430
    // 0x808003F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800430;
    // 0x808003F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_808003F4:
    // 0x808003F4: jal         0x800FC660
    // 0x808003F8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800FC660(rdram, ctx);
        goto after_9;
    // 0x808003F8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_9:
    // 0x808003FC: addiu       $a0, $zero, 0x40D
    ctx->r4 = ADD32(0, 0X40D);
    // 0x80800400: jal         0x800DA9E4
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_10;
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800408: bne         $v0, $zero, L_80800424
    if (ctx->r2 != 0) {
        // 0x8080040C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800424;
    }
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x808000C4
    // 0x80800418: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808000C4_chhoney(rdram, ctx);
        goto after_11;
    // 0x80800418: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x8080041C: b           L_80800430
    // 0x80800420: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800430;
    // 0x80800420: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800424:
    // 0x80800424: jal         0x808000C4
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000C4_chhoney(rdram, ctx);
        goto after_12;
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x8080042C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800430:
    // 0x80800430: jal         0x800888C8
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800438: jal         0x8010A570
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_14;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800440: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800444: lbu         $t0, 0x75($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X75);
    // 0x80800448: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x8080044C: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80800450: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800454: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    // 0x80800458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080045C:
    // 0x8080045C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void sucoasterfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3210, 0X2280) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3210, 0X2280));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3210, 0X2280));
;}
RECOMP_FUNC void gcskyDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080044C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800450: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800454: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800458: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080045C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800460: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800468: jal         0x80800000
    // 0x8080046C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800000_gcskyDll(rdram, ctx);
        goto after_0;
    // 0x8080046C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800470: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800474: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800478: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_8080047C:
    // 0x8080047C: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x80800480: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80800484: beql        $t6, $zero, L_808004B4
    if (ctx->r14 == 0) {
        // 0x80800488: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808004B4;
    }
    goto skip_0;
    // 0x80800488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080048C: jal         0x800D5B24
    // 0x80800490: addu        $s2, $s3, $t7
    ctx->r18 = ADD32(ctx->r19, ctx->r15);
    func_800D5B24(rdram, ctx);
        goto after_1;
    // 0x80800490: addu        $s2, $s3, $t7
    ctx->r18 = ADD32(ctx->r19, ctx->r15);
    after_1:
    // 0x80800494: jal         0x800D674C
    // 0x80800498: lh          $a0, 0x4($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X4);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800498: lh          $a0, 0x4($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X4);
    after_2:
    // 0x8080049C: jal         0x800B27FC
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_3;
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808004A4: jal         0x80087A30
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808004AC: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x808004B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808004B4:
    // 0x808004B4: bne         $s0, $s4, L_8080047C
    if (ctx->r16 != ctx->r20) {
        // 0x808004B8: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_8080047C;
    }
    // 0x808004B8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808004BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808004D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808004D4: jr          $ra
    // 0x808004D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808004D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800A9C_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800AA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800AAC: jal         0x801022E4
    // 0x80800AB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800AB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800AB4: addiu       $at, $zero, 0x389
    ctx->r1 = ADD32(0, 0X389);
    // 0x80800AB8: beq         $v0, $at, L_80800AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800ABC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800AE0;
    }
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AC0: addiu       $at, $zero, 0x38A
    ctx->r1 = ADD32(0, 0X38A);
    // 0x80800AC4: beq         $v0, $at, L_80800B78
    if (ctx->r2 == ctx->r1) {
        // 0x80800AC8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B78;
    }
    // 0x80800AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800ACC: addiu       $at, $zero, 0x38B
    ctx->r1 = ADD32(0, 0X38B);
    // 0x80800AD0: beq         $v0, $at, L_80800B38
    if (ctx->r2 == ctx->r1) {
        // 0x80800AD4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B38;
    }
    // 0x80800AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AD8: b           L_80800B94
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B94;
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE0:
    // 0x80800AE0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800AE4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X11B4) << 16);
    // 0x80800AE8: addiu       $a2, $a2, 0x11B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X11B4));
    // 0x80800AEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AF0: jal         0x80089D20
    // 0x80800AF4: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800AF4: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_1:
    // 0x80800AF8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X11D4) << 16);
    // 0x80800AFC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1216, 0X11F4) << 16);
    // 0x80800B00: addiu       $a3, $a3, 0x11F4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1216, 0X11F4));
    // 0x80800B04: addiu       $a2, $a2, 0x11D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X11D4));
    // 0x80800B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B0C: jal         0x80089D28
    // 0x80800B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800B14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X11C4) << 16);
    // 0x80800B18: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1216, 0X11E4) << 16);
    // 0x80800B1C: addiu       $a3, $a3, 0x11E4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1216, 0X11E4));
    // 0x80800B20: addiu       $a2, $a2, 0x11C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X11C4));
    // 0x80800B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B28: jal         0x80089D28
    // 0x80800B2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800B2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800B30: b           L_80800B94
    // 0x80800B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B94;
    // 0x80800B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B38:
    // 0x80800B38: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800B3C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1200) << 16);
    // 0x80800B40: lui         $a3, 0x3DF5
    ctx->r7 = S32(0X3DF5 << 16);
    // 0x80800B44: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80800B48: addiu       $a2, $a2, 0x1200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1200));
    // 0x80800B4C: jal         0x80089D20
    // 0x80800B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800B54: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1208) << 16);
    // 0x80800B58: lui         $a3, 0x3F1E
    ctx->r7 = S32(0X3F1E << 16);
    // 0x80800B5C: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x80800B60: addiu       $a2, $a2, 0x1208
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1208));
    // 0x80800B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B68: jal         0x80089D20
    // 0x80800B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800B70: b           L_80800B94
    // 0x80800B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B94;
    // 0x80800B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B78:
    // 0x80800B78: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1218) << 16);
    // 0x80800B7C: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x80800B80: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800B84: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1218));
    // 0x80800B88: jal         0x80089D20
    // 0x80800B8C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800B8C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_6:
    // 0x80800B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B94:
    // 0x80800B94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80109C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109C4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80109C50: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80109C54: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80109C58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80109C5C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80109C60: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80109C64: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80109C68: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x80109C6C: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80109C70: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80109C74: lhu         $t2, 0x24($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X24);
    // 0x80109C78: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80109C7C: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x80109C80: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80109C84: sh          $t4, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r12;
    // 0x80109C88: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80109C8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80109C90: jal         0x801099D0
    // 0x80109C94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_801099D0(rdram, ctx);
        goto after_0;
    // 0x80109C94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x80109C98: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80109C9C: lhu         $t0, 0x24($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X24);
    // 0x80109CA0: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x80109CA4: andi        $t2, $t0, 0x3F
    ctx->r10 = ctx->r8 & 0X3F;
    // 0x80109CA8: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x80109CAC: sh          $t1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r9;
    // 0x80109CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80109CB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109CB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80109CBC: jr          $ra
    // 0x80109CC0: nop

    return;
    // 0x80109CC0: nop

;}
RECOMP_FUNC void chsecreteggs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2472, 0X50C) << 16);
    // 0x80800480: jr          $ra
    // 0x80800484: addiu       $v0, $v0, 0x50C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2472, 0X50C));
    return;
    // 0x80800484: addiu       $v0, $v0, 0x50C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2472, 0X50C));
;}
RECOMP_FUNC void func_808077E0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808077E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808077E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808077E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808077EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808077F0: jal         0x80801B64
    // 0x808077F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808077F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808077F8: jal         0x80807BB8
    // 0x808077FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808077FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807800: jal         0x800839C8
    // 0x80807804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80807804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807808: jal         0x800A3404
    // 0x8080780C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_3;
    // 0x8080780C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807810: beq         $v0, $zero, L_80807830
    if (ctx->r2 == 0) {
        // 0x80807814: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807830;
    }
    // 0x80807814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080781C: addiu       $a1, $zero, 0x272
    ctx->r5 = ADD32(0, 0X272);
    // 0x80807820: jal         0x8008CB3C
    // 0x80807824: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80807824: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x80807828: b           L_80807850
    // 0x8080782C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
        goto L_80807850;
    // 0x8080782C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80807830:
    // 0x80807830: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x80807834: jal         0x8008CBB0
    // 0x80807838: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_5;
    // 0x80807838: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_5:
    // 0x8080783C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807840: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x80807844: jal         0x80800488
    // 0x80807848: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_80800488_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80807848: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x8080784C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80807850:
    // 0x80807850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807854: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080785C: jr          $ra
    // 0x80807860: nop

    return;
    // 0x80807860: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808009B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808009C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808009C4: jal         0x8008CABC
    // 0x808009C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808009C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808009CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(292, 0X11F4) << 16);
    // 0x808009D0: lwc1        $f4, 0x11F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(292, 0X11F4));
    // 0x808009D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009DC: jal         0x8008AF24
    // 0x808009E0: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808009E0: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: jal         0x8008AED4
    // 0x808009EC: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808009EC: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    after_2:
    // 0x808009F0: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x808009F4: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x808009F8: jal         0x8008B1C8
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: jal         0x8008B1BC
    // 0x80800A08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800A08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: jal         0x8008B24C
    // 0x80800A14: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800A14: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    after_5:
    // 0x80800A18: lui         $a2, 0x3ED7
    ctx->r6 = S32(0X3ED7 << 16);
    // 0x80800A1C: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A24: jal         0x8008B1D4
    // 0x80800A28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800A28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A30: jal         0x8008B134
    // 0x80800A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800A38: jal         0x8008B064
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A40: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800A44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A54: jal         0x8009FFD8
    // 0x80800A58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800A58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800A5C: jal         0x8009EF04
    // 0x80800A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x80800A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800A64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800A68: nop

    // 0x80800A6C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800A70: nop

    // 0x80800A74: bc1t        L_80800A90
    if (c1cs) {
        // 0x80800A78: nop
    
            goto L_80800A90;
    }
    // 0x80800A78: nop

    // 0x80800A7C: jal         0x8009EEB8
    // 0x80800A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x80800A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800A84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A88: jal         0x8009C914
    // 0x80800A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x80800A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_80800A90:
    // 0x80800A90: jal         0x8009C990
    // 0x80800A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x80800A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800A98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A9C: jal         0x8009B9C0
    // 0x80800AA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x80800AA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800AA4: jal         0x80800064
    // 0x80800AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800064_bskazstilt(rdram, ctx);
        goto after_15;
    // 0x80800AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800AAC: jal         0x8009C990
    // 0x80800AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x80800AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800AB4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800AB8: jal         0x8009BB00
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800AC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AC8: jal         0x8009BA68
    // 0x80800ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AD4: jal         0x8009BA58
    // 0x80800AD8: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80800AD8: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_19:
    // 0x80800ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AE0: jal         0x8009BCB4
    // 0x80800AE4: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x80800AE4: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    after_20:
    // 0x80800AE8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800AEC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AF4: jal         0x8009DE38
    // 0x80800AF8: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    func_8009DE38(rdram, ctx);
        goto after_21;
    // 0x80800AF8: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    after_21:
    // 0x80800AFC: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800B00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B04: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800B08: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B0C: jr          $ra
    // 0x80800B10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800B10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bsswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800AB8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(384, 0XBC4) << 16);
    // 0x80800ABC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800AC0: jr          $ra
    // 0x80800AC4: lw          $v0, 0xBC4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBC4));
    return;
    // 0x80800AC4: lw          $v0, 0xBC4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBC4));
;}
RECOMP_FUNC void _gspropmarker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C48: syscall     730
    recomp_syscall_handler(rdram, ctx, 0x80088C48);
    return;
    // 0x80088C4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808003DC_ncba1p(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808003EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003F8: jal         0x801163A0
    // 0x808003FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_801163A0(rdram, ctx);
        goto after_0;
    // 0x808003FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80800400: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: jal         0x800EE7F8
    // 0x8080040C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080040C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x80800410: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800414: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800418: lbu         $t6, 0x50($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X50);
    // 0x8080041C: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    // 0x80800420: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    // 0x80800424: beq         $t6, $zero, L_8080043C
    if (ctx->r14 == 0) {
        // 0x80800428: addiu       $a0, $s0, 0xC
        ctx->r4 = ADD32(ctx->r16, 0XC);
            goto L_8080043C;
    }
    // 0x80800428: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8080042C: jal         0x80111410
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80111410(rdram, ctx);
        goto after_2;
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800434: b           L_80800448
    // 0x80800438: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
        goto L_80800448;
    // 0x80800438: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8080043C:
    // 0x8080043C: jal         0x800EE7F8
    // 0x80800440: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800440: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    after_3:
    // 0x80800444: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800448:
    // 0x80800448: jal         0x800EE7F8
    // 0x8080044C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080044C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x80800450: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80800454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800458: jal         0x800EE7F8
    // 0x8080045C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080045C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_5:
    // 0x80800460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800464: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void badata_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D08: jal         0x80800000
    // 0x80800D0C: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800D0C: nop

    after_0:
    // 0x80800D10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D18: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X2018) << 16);
    // 0x80800D1C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D20: lh          $v0, 0x2018($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X2018));
    // 0x80800D24: jr          $ra
    // 0x80800D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8011106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011106C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111070: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80111074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8011107C: jal         0x800EE7F8
    // 0x80111080: addiu       $a1, $a3, 0x8C
    ctx->r5 = ADD32(ctx->r7, 0X8C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80111080: addiu       $a1, $a3, 0x8C
    ctx->r5 = ADD32(ctx->r7, 0X8C);
    after_0:
    // 0x80111084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011108C: jr          $ra
    // 0x80111090: nop

    return;
    // 0x80111090: nop

;}
RECOMP_FUNC void func_8080090C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800918: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080091C: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80800920: jal         0x8008CB3C
    // 0x80800924: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800924: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_0:
    // 0x80800928: jal         0x80800000
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_1;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800930: jal         0x80800030
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_2;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x800852B8
    // 0x80800940: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800940: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_3:
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: jal         0x800852A8
    // 0x8080094C: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x8080094C: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_4:
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: jal         0x8009BC5C
    // 0x80800958: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_5;
    // 0x80800958: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x800910BC
    // 0x80800964: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800910BC(rdram, ctx);
        goto after_6;
    // 0x80800964: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080096C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800974: jr          $ra
    // 0x80800978: nop

    return;
    // 0x80800978: nop

;}
RECOMP_FUNC void func_800D3DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DD0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3DD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D3DD8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D3DDC: lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4A48);
    // 0x800D3DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3DE8: beql        $v0, $zero, L_800D3E04
    if (ctx->r2 == 0) {
        // 0x800D3DEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D3E04;
    }
    goto skip_0;
    // 0x800D3DEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D3DF0: jal         0x800DA298
    // 0x800D3DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800D3DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x800D3DF8: b           L_800D3E08
    // 0x800D3DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3E08;
    // 0x800D3DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3E04:
    // 0x800D3E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3E08:
    // 0x800D3E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3E0C: jr          $ra
    // 0x800D3E10: nop

    return;
    // 0x800D3E10: nop

;}
RECOMP_FUNC void func_800C5770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5770: jr          $ra
    // 0x800C5774: nop

    return;
    // 0x800C5774: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800340: jal         0x80100094
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800348: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080034C: sb          $t6, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r14;
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void fxrain_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C4: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x808002C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808002CC: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x808002D0: beql        $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002EC;
    }
    goto skip_0;
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002D8: jal         0x800B2928
    // 0x808002DC: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x808002DC: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x808002E0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808002E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808002E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002EC:
    // 0x808002EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F0: jr          $ra
    // 0x808002F4: nop

    return;
    // 0x808002F4: nop

;}
RECOMP_FUNC void chnests_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1428) << 16);
    // 0x80800F9C: jr          $ra
    // 0x80800FA0: addiu       $v0, $v0, 0x1428
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1428));
    return;
    // 0x80800FA0: addiu       $v0, $v0, 0x1428
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1428));
;}
RECOMP_FUNC void func_808008EC_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F4: jal         0x800839B8
    // 0x808008F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808008F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008FC: jal         0x80800000
    // 0x80800900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bskazpaddle(rdram, ctx);
        goto after_1;
    // 0x80800900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080090C: jr          $ra
    // 0x80800910: nop

    return;
    // 0x80800910: nop

;}
RECOMP_FUNC void func_80807F5C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807F64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80807F68: jal         0x800A3544
    // 0x80807F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3544(rdram, ctx);
        goto after_0;
    // 0x80807F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80807F70: jal         0x80807DD4
    // 0x80807F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80807F78: jal         0x80801A5C
    // 0x80807F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801A5C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80807F80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80807F84: jal         0x8009E5C8
    // 0x80807F88: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80807F88: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    after_3:
    // 0x80807F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807F94: jr          $ra
    // 0x80807F98: nop

    return;
    // 0x80807F98: nop

;}
RECOMP_FUNC void _chnests_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AB8: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AB8);
    return;
    // 0x80085ABC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _sukickball_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B08: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B08);
    return;
    // 0x80089B0C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void gztrace_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800844: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800848: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8080084C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800850: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800854: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800858: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080085C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800860: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800864: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800868: lw          $t6, 0x11C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X11C);
    // 0x8080086C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800870: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0XA08) << 16);
    // 0x80800874: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80800878: lw          $t9, 0xF4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XF4);
    // 0x8080087C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80800880: addiu       $a1, $a1, 0xA08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0XA08));
    // 0x80800884: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80800888: bne         $a2, $zero, L_8080089C
    if (ctx->r6 != 0) {
        // 0x8080088C: lw          $s1, 0x104($a0)
        ctx->r17 = MEM_W(ctx->r4, 0X104);
            goto L_8080089C;
    }
    // 0x8080088C: lw          $s1, 0x104($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X104);
    // 0x80800890: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X9F8) << 16);
    // 0x80800894: b           L_8080089C
    // 0x80800898: addiu       $a1, $a1, 0x9F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X9F8));
        goto L_8080089C;
    // 0x80800898: addiu       $a1, $a1, 0x9F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X9F8));
L_8080089C:
    // 0x8080089C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3390, 0X9C4) << 16);
    // 0x808008A0: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0X9C4));
    // 0x808008A4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x808008A8: jal         0x8001D37C
    // 0x808008AC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_8001D37C(rdram, ctx);
        goto after_0;
    // 0x808008AC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // 0x808008B0: jal         0x80800000
    // 0x808008B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80800000_gztrace(rdram, ctx);
        goto after_1;
    // 0x808008B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x808008B8: bne         $v0, $zero, L_808008E4
    if (ctx->r2 != 0) {
        // 0x808008BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808008E4;
    }
    // 0x808008BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808008C4: jal         0x80800000
    // 0x808008C8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80800000_gztrace(rdram, ctx);
        goto after_2;
    // 0x808008C8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_2:
    // 0x808008CC: bne         $v0, $zero, L_808008E4
    if (ctx->r2 != 0) {
        // 0x808008D0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3390, 0XA0C) << 16);
            goto L_808008E4;
    }
    // 0x808008D0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3390, 0XA0C) << 16);
    // 0x808008D4: jal         0x8001D37C
    // 0x808008D8: addiu       $a0, $a0, 0xA0C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0XA0C));
    func_8001D37C(rdram, ctx);
        goto after_3;
    // 0x808008D8: addiu       $a0, $a0, 0xA0C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0XA0C));
    after_3:
    // 0x808008DC: b           L_80800948
    // 0x808008E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800948;
    // 0x808008E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808008E4:
    // 0x808008E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808008E8: beq         $s0, $zero, L_80800928
    if (ctx->r16 == 0) {
        // 0x808008EC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800928;
    }
    // 0x808008EC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808008F0: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x808008F4: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x808008F8: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x808008FC: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
L_80800900:
    // 0x80800900: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800904: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800908: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080090C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800910: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800914: jal         0x808004B0
    // 0x80800918: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_808004B0_gztrace(rdram, ctx);
        goto after_4;
    // 0x80800918: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_4:
    // 0x8080091C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800920: bne         $s0, $zero, L_80800900
    if (ctx->r16 != 0) {
        // 0x80800924: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800900;
    }
    // 0x80800924: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80800928:
    // 0x80800928: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8080092C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800930: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800934: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800938: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8080093C: jal         0x808005C4
    // 0x80800940: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_808005C4_gztrace(rdram, ctx);
        goto after_5;
    // 0x80800940: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
    // 0x80800944: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800948:
    // 0x80800948: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080094C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800950: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800954: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800958: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8080095C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800960: jr          $ra
    // 0x80800964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void func_80800F98_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800F9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800FA0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80800FA4:
    // 0x80800FA4: lh          $t6, 0x82($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X82);
    // 0x80800FA8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800FAC: beq         $t6, $zero, L_80800FBC
    if (ctx->r14 == 0) {
        // 0x80800FB0: nop
    
            goto L_80800FBC;
    }
    // 0x80800FB0: nop

    // 0x80800FB4: jr          $ra
    // 0x80800FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FBC:
    // 0x80800FBC: bne         $v1, $v0, L_80800FA4
    if (ctx->r3 != ctx->r2) {
        // 0x80800FC0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80800FA4;
    }
    // 0x80800FC0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800FC8: jr          $ra
    // 0x80800FCC: nop

    return;
    // 0x80800FCC: nop

;}
RECOMP_FUNC void func_80800994_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080099C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808009A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808009A4: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808009A8: jal         0x80102BF8
    // 0x808009AC: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_80102BF8(rdram, ctx);
        goto after_0;
    // 0x808009AC: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_0:
    // 0x808009B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void func_80806528_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806528: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080652C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806530: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80806534: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80806538: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080653C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80806540: jal         0x80100094
    // 0x80806544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806548: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080654C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80806550: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80806554: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80806558: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080655C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80806560: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80806564: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80806568: jal         0x800E0AFC
    // 0x8080656C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_1;
    // 0x8080656C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80806570: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80806574: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80806578: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080657C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x80806580: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80806584: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80806588: jal         0x800E0AFC
    // 0x8080658C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x8080658C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80806590: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80806594: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80806598: beql        $t6, $zero, L_80806638
    if (ctx->r14 == 0) {
        // 0x8080659C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80806638;
    }
    goto skip_0;
    // 0x8080659C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808065A0: jal         0x80802228
    // 0x808065A4: nop

    func_80802228_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808065A4: nop

    after_3:
    // 0x808065A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808065AC: jal         0x80100094
    // 0x808065B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808065B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808065B4: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x808065B8: beql        $t7, $zero, L_80806638
    if (ctx->r15 == 0) {
        // 0x808065BC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80806638;
    }
    goto skip_1;
    // 0x808065BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808065C0: jal         0x800E8C58
    // 0x808065C4: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    func_800E8C58(rdram, ctx);
        goto after_5;
    // 0x808065C4: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    after_5:
    // 0x808065C8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808065CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808065D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808065D4: jal         0x800B27E0
    // 0x808065D8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800B27E0(rdram, ctx);
        goto after_6;
    // 0x808065D8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x808065DC: jal         0x80087A10
    // 0x808065E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808065E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808065E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808065E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808065EC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808065F0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808065F4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808065F8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808065FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80806600: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80806604: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80806608: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080660C: jal         0x800E0C20
    // 0x80806610: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800E0C20(rdram, ctx);
        goto after_8;
    // 0x80806610: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x80806614: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80806618: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8080661C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80806620: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x80806624: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80806628: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080662C: jal         0x800E0C20
    // 0x80806630: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800E0C20(rdram, ctx);
        goto after_9;
    // 0x80806630: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80806634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80806638:
    // 0x80806638: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080663C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80806640: jr          $ra
    // 0x80806644: nop

    return;
    // 0x80806644: nop

;}
RECOMP_FUNC void func_80800A34_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800A54: jal         0x800DC178
    // 0x80800A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A60: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80800A64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X13F8) << 16);
    // 0x80800A68: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800A6C: lwc1        $f12, 0x13F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X13F8));
    // 0x80800A70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A78: jal         0x800DC178
    // 0x80800A7C: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800A7C: nop

    after_1:
    // 0x80800A80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X13FC) << 16);
    // 0x80800A84: lwc1        $f6, 0x13FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X13FC));
    // 0x80800A88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1400) << 16);
    // 0x80800A8C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800A90: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80800A94: lwc1        $f12, 0x1400($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1400));
    // 0x80800A98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1404) << 16);
    // 0x80800A9C: jal         0x800DC178
    // 0x80800AA0: lwc1        $f14, 0x1404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1404));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800AA0: lwc1        $f14, 0x1404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1404));
    after_2:
    // 0x80800AA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1408) << 16);
    // 0x80800AA8: lwc1        $f10, 0x1408($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1408));
    // 0x80800AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800AB4: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800AB8: jal         0x800DC128
    // 0x80800ABC: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80800ABC: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80800AC0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80800AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AD0: jr          $ra
    // 0x80800AD4: nop

    return;
    // 0x80800AD4: nop

;}
RECOMP_FUNC void func_8008FAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FAC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008FACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008FAD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008FAD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008FAD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008FADC: jal         0x800F54E4
    // 0x8008FAE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FAE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FAE4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008FAE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FAEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8008FAF0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8008FAF4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008FAF8: jal         0x800F4D74
    // 0x8008FAFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4D74(rdram, ctx);
        goto after_1;
    // 0x8008FAFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8008FB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FB04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008FB08: jr          $ra
    // 0x8008FB0C: nop

    return;
    // 0x8008FB0C: nop

;}
RECOMP_FUNC void chlavaentrancebridge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1980, 0X230) << 16);
    // 0x80800204: jr          $ra
    // 0x80800208: addiu       $v0, $v0, 0x230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1980, 0X230));
    return;
    // 0x80800208: addiu       $v0, $v0, 0x230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1980, 0X230));
    // 0x8080020C: nop

;}
RECOMP_FUNC void _badust_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849D0: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849D0);
    return;
    // 0x800849D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080066C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080066C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800674: jal         0x8009E6EC
    // 0x80800678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080067C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80800680: bne         $v0, $at, L_808006A4
    if (ctx->r2 != ctx->r1) {
        // 0x80800684: nop
    
            goto L_808006A4;
    }
    // 0x80800684: nop

    // 0x80800688: jal         0x808000F0
    // 0x8080068C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bsride(rdram, ctx);
        goto after_1;
    // 0x8080068C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800690: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800694: jal         0x8009E830
    // 0x80800698: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80800698: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080069C: b           L_808006B0
    // 0x808006A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808006B0;
    // 0x808006A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006A4:
    // 0x808006A4: jal         0x80099B94
    // 0x808006A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x808006A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808006AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006B0:
    // 0x808006B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085808: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085808);
    return;
    // 0x8008580C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800A98_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A9C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800AA0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AB4: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80800AB8: jal         0x80100094
    // 0x80800ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AC0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80800AC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800AC8: slti        $at, $a2, 0x97
    ctx->r1 = SIGNED(ctx->r6) < 0X97 ? 1 : 0;
    // 0x80800ACC: bne         $at, $zero, L_80800AF0
    if (ctx->r1 != 0) {
        // 0x80800AD0: addiu       $t6, $a2, -0x6
        ctx->r14 = ADD32(ctx->r6, -0X6);
            goto L_80800AF0;
    }
    // 0x80800AD0: addiu       $t6, $a2, -0x6
    ctx->r14 = ADD32(ctx->r6, -0X6);
    // 0x80800AD4: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800AD8: beq         $a2, $at, L_80800E9C
    if (ctx->r6 == ctx->r1) {
        // 0x80800ADC: addiu       $at, $zero, 0xA2
        ctx->r1 = ADD32(0, 0XA2);
            goto L_80800E9C;
    }
    // 0x80800ADC: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80800AE0: beql        $a2, $at, L_80800ED4
    if (ctx->r6 == ctx->r1) {
        // 0x80800AE4: lw          $t4, 0x7C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X7C);
            goto L_80800ED4;
    }
    goto skip_0;
    // 0x80800AE4: lw          $t4, 0x7C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x80800AE8: b           L_80800F70
    // 0x80800AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AF0:
    // 0x80800AF0: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x80800AF4: bne         $at, $zero, L_80800B0C
    if (ctx->r1 != 0) {
        // 0x80800AF8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80800B0C;
    }
    // 0x80800AF8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800AFC: beq         $a2, $at, L_80800E64
    if (ctx->r6 == ctx->r1) {
        // 0x80800B00: nop
    
            goto L_80800E64;
    }
    // 0x80800B00: nop

    // 0x80800B04: b           L_80800F70
    // 0x80800B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B0C:
    // 0x80800B0C: slti        $at, $a2, 0x41
    ctx->r1 = SIGNED(ctx->r6) < 0X41 ? 1 : 0;
    // 0x80800B10: bne         $at, $zero, L_80800B28
    if (ctx->r1 != 0) {
        // 0x80800B14: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800B28;
    }
    // 0x80800B14: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800B18: beql        $a2, $at, L_80800E48
    if (ctx->r6 == ctx->r1) {
        // 0x80800B1C: lbu         $t2, 0x496($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X496);
            goto L_80800E48;
    }
    goto skip_1;
    // 0x80800B1C: lbu         $t2, 0x496($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X496);
    skip_1:
    // 0x80800B20: b           L_80800F70
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B28:
    // 0x80800B28: sltiu       $at, $t6, 0x3B
    ctx->r1 = ctx->r14 < 0X3B ? 1 : 0;
    // 0x80800B2C: beq         $at, $zero, L_80800F64
    if (ctx->r1 == 0) {
        // 0x80800B30: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800F64;
    }
    // 0x80800B30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800B34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2B9C) << 16);
    // 0x80800B38: addu        $at, $at, $t6
    gpr jr_addend_80800B40 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800B3C: lw          $t6, 0x2B9C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(832, 0X2B9C));
    // 0x80800B40: jr          $t6
    // 0x80800B44: nop

    switch (jr_addend_80800B40 >> 2) {
        case 0: goto L_80800DBC; break;
        case 1: goto L_80800F64; break;
        case 2: goto L_80800F64; break;
        case 3: goto L_80800F64; break;
        case 4: goto L_80800DCC; break;
        case 5: goto L_80800B48; break;
        case 6: goto L_80800F64; break;
        case 7: goto L_80800F64; break;
        case 8: goto L_80800F64; break;
        case 9: goto L_80800F64; break;
        case 10: goto L_80800F64; break;
        case 11: goto L_80800F64; break;
        case 12: goto L_80800F64; break;
        case 13: goto L_80800F64; break;
        case 14: goto L_80800F64; break;
        case 15: goto L_80800F64; break;
        case 16: goto L_80800F64; break;
        case 17: goto L_80800F64; break;
        case 18: goto L_80800F64; break;
        case 19: goto L_80800F64; break;
        case 20: goto L_80800F64; break;
        case 21: goto L_80800F64; break;
        case 22: goto L_80800F64; break;
        case 23: goto L_80800F64; break;
        case 24: goto L_80800F64; break;
        case 25: goto L_80800EB8; break;
        case 26: goto L_80800F64; break;
        case 27: goto L_80800F64; break;
        case 28: goto L_80800F64; break;
        case 29: goto L_80800F64; break;
        case 30: goto L_80800F64; break;
        case 31: goto L_80800F64; break;
        case 32: goto L_80800F64; break;
        case 33: goto L_80800F64; break;
        case 34: goto L_80800F64; break;
        case 35: goto L_80800F64; break;
        case 36: goto L_80800F64; break;
        case 37: goto L_80800F64; break;
        case 38: goto L_80800F64; break;
        case 39: goto L_80800F64; break;
        case 40: goto L_80800C1C; break;
        case 41: goto L_80800C38; break;
        case 42: goto L_80800F64; break;
        case 43: goto L_80800F64; break;
        case 44: goto L_80800CC4; break;
        case 45: goto L_80800F64; break;
        case 46: goto L_80800F64; break;
        case 47: goto L_80800F64; break;
        case 48: goto L_80800F64; break;
        case 49: goto L_80800F64; break;
        case 50: goto L_80800F64; break;
        case 51: goto L_80800F64; break;
        case 52: goto L_80800F64; break;
        case 53: goto L_80800F64; break;
        case 54: goto L_80800F64; break;
        case 55: goto L_80800C54; break;
        case 56: goto L_80800F64; break;
        case 57: goto L_80800D8C; break;
        case 58: goto L_80800DA4; break;
        default: switch_error(__func__, 0x80800B40, 0x80802B9C);
    }
    // 0x80800B44: nop

L_80800B48:
    // 0x80800B48: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800B4C: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x80800B50: sltiu       $at, $t8, 0x2F
    ctx->r1 = ctx->r24 < 0X2F ? 1 : 0;
    // 0x80800B54: beq         $at, $zero, L_80800BB0
    if (ctx->r1 == 0) {
        // 0x80800B58: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800BB0;
    }
    // 0x80800B58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800B5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2C88) << 16);
    // 0x80800B60: addu        $at, $at, $t8
    gpr jr_addend_80800B68 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800B64: lw          $t8, 0x2C88($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(832, 0X2C88));
    // 0x80800B68: jr          $t8
    // 0x80800B6C: nop

    switch (jr_addend_80800B68 >> 2) {
        case 0: goto L_80800BB8; break;
        case 1: goto L_80800BB0; break;
        case 2: goto L_80800BB0; break;
        case 3: goto L_80800BB0; break;
        case 4: goto L_80800BB0; break;
        case 5: goto L_80800BF8; break;
        case 6: goto L_80800BB0; break;
        case 7: goto L_80800BDC; break;
        case 8: goto L_80800BB0; break;
        case 9: goto L_80800BE8; break;
        case 10: goto L_80800BB0; break;
        case 11: goto L_80800BB0; break;
        case 12: goto L_80800BB0; break;
        case 13: goto L_80800BB0; break;
        case 14: goto L_80800BB0; break;
        case 15: goto L_80800BB0; break;
        case 16: goto L_80800BB0; break;
        case 17: goto L_80800B70; break;
        case 18: goto L_80800BB0; break;
        case 19: goto L_80800BB0; break;
        case 20: goto L_80800BB0; break;
        case 21: goto L_80800BB0; break;
        case 22: goto L_80800BE8; break;
        case 23: goto L_80800BB0; break;
        case 24: goto L_80800BB0; break;
        case 25: goto L_80800BB0; break;
        case 26: goto L_80800BB0; break;
        case 27: goto L_80800BB0; break;
        case 28: goto L_80800BB0; break;
        case 29: goto L_80800BB0; break;
        case 30: goto L_80800BB0; break;
        case 31: goto L_80800BE8; break;
        case 32: goto L_80800BB0; break;
        case 33: goto L_80800BB0; break;
        case 34: goto L_80800BB0; break;
        case 35: goto L_80800BB0; break;
        case 36: goto L_80800BB0; break;
        case 37: goto L_80800BB0; break;
        case 38: goto L_80800BB0; break;
        case 39: goto L_80800BB0; break;
        case 40: goto L_80800BB0; break;
        case 41: goto L_80800BB0; break;
        case 42: goto L_80800BB0; break;
        case 43: goto L_80800BB0; break;
        case 44: goto L_80800BB0; break;
        case 45: goto L_80800BB0; break;
        case 46: goto L_80800BA4; break;
        default: switch_error(__func__, 0x80800B68, 0x80802C88);
    }
    // 0x80800B6C: nop

L_80800B70:
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B74: jal         0x80800F84
    // 0x80800B78: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x80800B78: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_1:
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800B84: jal         0x80802A00
    // 0x80800B88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x80800B88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x80800B8C: addiu       $a0, $zero, 0x46E
    ctx->r4 = ADD32(0, 0X46E);
    // 0x80800B90: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800B94: jal         0x80101180
    // 0x80800B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800B9C: b           L_80800F70
    // 0x80800BA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F70;
    // 0x80800BA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800BA4:
    // 0x80800BA4: sb          $zero, 0x49D($a1)
    MEM_B(0X49D, ctx->r5) = 0;
    // 0x80800BA8: jal         0x800FFAB0
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800BB0:
    // 0x80800BB0: b           L_80800F70
    // 0x80800BB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F70;
    // 0x80800BB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800BB8:
    // 0x80800BB8: lbu         $t9, 0x49C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X49C);
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800BC4: bne         $t9, $zero, L_80800BB0
    if (ctx->r25 != 0) {
        // 0x80800BC8: nop
    
            goto L_80800BB0;
    }
    // 0x80800BC8: nop

    // 0x80800BCC: jal         0x80802A00
    // 0x80800BD0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_5;
    // 0x80800BD0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x80800BD4: b           L_80800F70
    // 0x80800BD8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F70;
    // 0x80800BD8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800BDC:
    // 0x80800BDC: sb          $zero, 0x49D($v0)
    MEM_B(0X49D, ctx->r2) = 0;
    // 0x80800BE0: b           L_80800F70
    // 0x80800BE4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F70;
    // 0x80800BE4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800BE8:
    // 0x80800BE8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800BEC: sb          $t1, 0x49A($v0)
    MEM_B(0X49A, ctx->r2) = ctx->r9;
    // 0x80800BF0: b           L_80800F70
    // 0x80800BF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F70;
    // 0x80800BF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800BF8:
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BFC: jal         0x80108B04
    // 0x80800C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_6;
    // 0x80800C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C08: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800C0C: jal         0x80802A00
    // 0x80800C10: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_7;
    // 0x80800C10: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x80800C14: b           L_80800F70
    // 0x80800C18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F70;
    // 0x80800C18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800C1C:
    // 0x80800C1C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80800C20: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800C24: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800C28: jal         0x80801958
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801958_chinflatableboss(rdram, ctx);
        goto after_8;
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800C30: b           L_80800F70
    // 0x80800C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C38:
    // 0x80800C38: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80800C3C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800C40: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800C44: jal         0x80801AD8
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AD8_chinflatableboss(rdram, ctx);
        goto after_9;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C4C: b           L_80800F70
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C54:
    // 0x80800C54: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800C58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C5C: beq         $v0, $zero, L_80800C84
    if (ctx->r2 == 0) {
        // 0x80800C60: nop
    
            goto L_80800C84;
    }
    // 0x80800C60: nop

    // 0x80800C64: beq         $v0, $at, L_80800C94
    if (ctx->r2 == ctx->r1) {
        // 0x80800C68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C94;
    }
    // 0x80800C68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C6C: beq         $v0, $at, L_80800CA4
    if (ctx->r2 == ctx->r1) {
        // 0x80800C70: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800CA4;
    }
    // 0x80800C70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C74: beq         $v0, $at, L_80800CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80800C78: nop
    
            goto L_80800CB4;
    }
    // 0x80800C78: nop

    // 0x80800C7C: b           L_80800F70
    // 0x80800C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C84:
    // 0x80800C84: jal         0x80801DE0
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DE0_chinflatableboss(rdram, ctx);
        goto after_10;
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800C8C: b           L_80800F70
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C94:
    // 0x80800C94: jal         0x80801D38
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D38_chinflatableboss(rdram, ctx);
        goto after_11;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800C9C: b           L_80800F70
    // 0x80800CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CA4:
    // 0x80800CA4: jal         0x80801EA0
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EA0_chinflatableboss(rdram, ctx);
        goto after_12;
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800CAC: b           L_80800F70
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: jal         0x80801F4C
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F4C_chinflatableboss(rdram, ctx);
        goto after_13;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800CBC: b           L_80800F70
    // 0x80800CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CC4:
    // 0x80800CC4: lbu         $t2, 0x498($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X498);
    // 0x80800CC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CCC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80800CD0: bne         $t2, $at, L_80800D6C
    if (ctx->r10 != ctx->r1) {
        // 0x80800CD4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80800D6C;
    }
    // 0x80800CD4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800CD8: sb          $t3, 0x498($a1)
    MEM_B(0X498, ctx->r5) = ctx->r11;
    // 0x80800CDC: sb          $zero, 0x49A($a1)
    MEM_B(0X49A, ctx->r5) = 0;
    // 0x80800CE0: jal         0x800F54E4
    // 0x80800CE4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x80800CE4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_14:
    // 0x80800CE8: jal         0x800F497C
    // 0x80800CEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_15;
    // 0x80800CEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80800CF0: jal         0x800F54E4
    // 0x80800CF4: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x80800CF4: nop

    after_16:
    // 0x80800CF8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800CFC: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80800D00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D04: jal         0x800F49D4
    // 0x80800D08: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_17;
    // 0x80800D08: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_17:
    // 0x80800D0C: jal         0x800F54E4
    // 0x80800D10: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800D10: nop

    after_18:
    // 0x80800D14: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D1C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80800D20: jal         0x800F4A58
    // 0x80800D24: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    func_800F4A58(rdram, ctx);
        goto after_19;
    // 0x80800D24: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    after_19:
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80800D30: jal         0x80802A00
    // 0x80800D34: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_20;
    // 0x80800D34: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_20:
    // 0x80800D38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D3C: addiu       $t4, $zero, 0x3A
    ctx->r12 = ADD32(0, 0X3A);
    // 0x80800D40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800D44: addiu       $a1, $zero, 0x10CC
    ctx->r5 = ADD32(0, 0X10CC);
    // 0x80800D48: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800D4C: jal         0x8008A208
    // 0x80800D50: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800D50: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x80800D54: addiu       $a0, $zero, 0x46E
    ctx->r4 = ADD32(0, 0X46E);
    // 0x80800D58: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800D5C: jal         0x80101180
    // 0x80800D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_22;
    // 0x80800D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80800D64: b           L_80800F70
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D6C:
    // 0x80800D6C: jal         0x800F54E4
    // 0x80800D70: sb          $t5, 0x499($a1)
    MEM_B(0X499, ctx->r5) = ctx->r13;
    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x80800D70: sb          $t5, 0x499($a1)
    MEM_B(0X499, ctx->r5) = ctx->r13;
    after_23:
    // 0x80800D74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D7C: jal         0x800F8300
    // 0x80800D80: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_24;
    // 0x80800D80: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x80800D84: b           L_80800F70
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D8C:
    // 0x80800D8C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80800D90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D94: jal         0x808010BC
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010BC_chinflatableboss(rdram, ctx);
        goto after_25;
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800D9C: b           L_80800F70
    // 0x80800DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DA4:
    // 0x80800DA4: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80800DA8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800DAC: jal         0x80801164
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801164_chinflatableboss(rdram, ctx);
        goto after_26;
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800DB4: b           L_80800F70
    // 0x80800DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DBC:
    // 0x80800DBC: jal         0x80101010
    // 0x80800DC0: addiu       $a0, $a1, 0x1C
    ctx->r4 = ADD32(ctx->r5, 0X1C);
    func_80101010(rdram, ctx);
        goto after_27;
    // 0x80800DC0: addiu       $a0, $a1, 0x1C
    ctx->r4 = ADD32(ctx->r5, 0X1C);
    after_27:
    // 0x80800DC4: b           L_80800F70
    // 0x80800DC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800DC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DCC:
    // 0x80800DCC: jal         0x800F54E4
    // 0x80800DD0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_28;
    // 0x80800DD0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_28:
    // 0x80800DD4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800DD8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800DDC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DE4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800DE8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800DEC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DF0: jal         0x800F497C
    // 0x80800DF4: sb          $t9, 0x498($t1)
    MEM_B(0X498, ctx->r9) = ctx->r25;
    func_800F497C(rdram, ctx);
        goto after_29;
    // 0x80800DF4: sb          $t9, 0x498($t1)
    MEM_B(0X498, ctx->r9) = ctx->r25;
    after_29:
    // 0x80800DF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800DFC: jal         0x800F49A8
    // 0x80800E00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_30;
    // 0x80800E00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800E04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800E08: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80800E0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E10: jal         0x800F49D4
    // 0x80800E14: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_31;
    // 0x80800E14: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_31:
    // 0x80800E18: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E1C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E20: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80800E24: jal         0x800F4A58
    // 0x80800E28: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_800F4A58(rdram, ctx);
        goto after_32;
    // 0x80800E28: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_32:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800E34: jal         0x80802A00
    // 0x80800E38: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_33;
    // 0x80800E38: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_33:
    // 0x80800E3C: b           L_80800F70
    // 0x80800E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E44: lbu         $t2, 0x496($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X496);
L_80800E48:
    // 0x80800E48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E4C: beql        $t2, $zero, L_80800F70
    if (ctx->r10 == 0) {
        // 0x80800E50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F70;
    }
    goto skip_2;
    // 0x80800E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800E54: jal         0x800FDC28
    // 0x80800E58: sb          $zero, 0x496($a1)
    MEM_B(0X496, ctx->r5) = 0;
    func_800FDC28(rdram, ctx);
        goto after_34;
    // 0x80800E58: sb          $zero, 0x496($a1)
    MEM_B(0X496, ctx->r5) = 0;
    after_34:
    // 0x80800E5C: b           L_80800F70
    // 0x80800E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E64:
    // 0x80800E64: jal         0x800D395C
    // 0x80800E68: nop

    func_800D395C(rdram, ctx);
        goto after_35;
    // 0x80800E68: nop

    after_35:
    // 0x80800E6C: bne         $v0, $zero, L_80800E7C
    if (ctx->r2 != 0) {
        // 0x80800E70: addiu       $a1, $zero, 0xCEB
        ctx->r5 = ADD32(0, 0XCEB);
            goto L_80800E7C;
    }
    // 0x80800E70: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800E74: b           L_80800F70
    // 0x80800E78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800E78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E7C:
    // 0x80800E7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E80: addiu       $t3, $zero, 0x3A
    ctx->r11 = ADD32(0, 0X3A);
    // 0x80800E84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800E88: addiu       $a2, $zero, 0x146
    ctx->r6 = ADD32(0, 0X146);
    // 0x80800E8C: jal         0x8008A208
    // 0x80800E90: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_36;
    // 0x80800E90: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_36:
    // 0x80800E94: b           L_80800F70
    // 0x80800E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E9C:
    // 0x80800E9C: jal         0x800FDC28
    // 0x80800EA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_37;
    // 0x80800EA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_37:
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA8: jal         0x80800F84
    // 0x80800EAC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_38;
    // 0x80800EAC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_38:
    // 0x80800EB0: b           L_80800F70
    // 0x80800EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EB8:
    // 0x80800EB8: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80800EBC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800EC0: jal         0x80801418
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801418_chinflatableboss(rdram, ctx);
        goto after_39;
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800EC8: b           L_80800F70
    // 0x80800ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F70;
    // 0x80800ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800ED0: lw          $t4, 0x7C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X7C);
L_80800ED4:
    // 0x80800ED4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800ED8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800EDC: sll         $t6, $t4, 19
    ctx->r14 = S32(ctx->r12 << 19);
    // 0x80800EE0: bltz        $t6, L_80800EF0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800EE4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800EF0;
    }
    // 0x80800EE4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800EE8: b           L_80800F70
    // 0x80800EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EF0:
    // 0x80800EF0: lbu         $t7, 0x487($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X487);
    // 0x80800EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: bne         $t7, $at, L_80800F3C
    if (ctx->r15 != ctx->r1) {
        // 0x80800F00: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_80800F3C;
    }
    // 0x80800F00: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80800F04: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x80800F08: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(832, 0X3020) << 16);
    // 0x80800F0C: addiu       $t9, $t9, 0x3020
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(832, 0X3020));
    // 0x80800F10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800F14: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80800F18: addiu       $a2, $v1, 0x3
    ctx->r6 = ADD32(ctx->r3, 0X3);
    // 0x80800F1C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80800F20: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800F24: jal         0x80802590
    // 0x80800F28: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_80802590_chinflatableboss(rdram, ctx);
        goto after_40;
    // 0x80800F28: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_40:
    // 0x80800F2C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800F30: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800F34: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800F38: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80800F3C:
    // 0x80800F3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800F40: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800F44: bne         $v1, $at, L_80800EF0
    if (ctx->r3 != ctx->r1) {
        // 0x80800F48: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80800EF0;
    }
    // 0x80800F48: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80800F4C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(832, 0X3020) << 16);
    // 0x80800F50: addiu       $a0, $a0, 0x3020
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(832, 0X3020));
    // 0x80800F54: jal         0x80101074
    // 0x80800F58: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_80101074(rdram, ctx);
        goto after_41;
    // 0x80800F58: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_41:
    // 0x80800F5C: b           L_80800F70
    // 0x80800F60: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
        goto L_80800F70;
    // 0x80800F60: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_80800F64:
    // 0x80800F64: b           L_80800F70
    // 0x80800F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F70;
    // 0x80800F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F70:
    // 0x80800F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800F7C: jr          $ra
    // 0x80800F80: nop

    return;
    // 0x80800F80: nop

;}
RECOMP_FUNC void chdiggerfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(864, 0X140) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(864, 0X140));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(864, 0X140));
;}
RECOMP_FUNC void func_800FED70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FED70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FED74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FED78: jal         0x800FED0C
    // 0x800FED7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FED0C(rdram, ctx);
        goto after_0;
    // 0x800FED7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800FED80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FED84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FED88: jr          $ra
    // 0x800FED8C: nop

    return;
    // 0x800FED8C: nop

;}
RECOMP_FUNC void _bskazeggass_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083328: syscall     55
    recomp_syscall_handler(rdram, ctx, 0x80083328);
    return;
    // 0x8008332C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void susplinet_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800264: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80800268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800270: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800274: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800278: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x8080027C: jal         0x800EE7F8
    // 0x80800280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800020: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    // 0x80800024: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x80800028: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080002C: jr          $ra
    // 0x80800030: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
    return;
    // 0x80800030: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800A5654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5654: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5658: addiu       $v1, $v1, -0x6AC0
    ctx->r3 = ADD32(ctx->r3, -0X6AC0);
    // 0x800A565C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800A5660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5668: beql        $a0, $zero, L_800A5698
    if (ctx->r4 == 0) {
        // 0x800A566C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5698;
    }
    goto skip_0;
    // 0x800A566C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A5670: jal         0x8001BAFC
    // 0x800A5674: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800A5674: nop

    after_0:
    // 0x800A5678: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A567C: addiu       $v1, $v1, -0x6AC0
    ctx->r3 = ADD32(ctx->r3, -0X6AC0);
    // 0x800A5680: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800A5684: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A5688: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x800A568C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800A5690: sw          $zero, 0x34($t8)
    MEM_W(0X34, ctx->r24) = 0;
    // 0x800A5694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5698:
    // 0x800A5698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A569C: jr          $ra
    // 0x800A56A0: nop

    return;
    // 0x800A56A0: nop

;}
RECOMP_FUNC void func_800FA9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA9F4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA9F8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA9FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FAA00: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FAA04: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800FAA08: lw          $a2, 0x3898($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3898);
    // 0x800FAA0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FAA10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FAA14: beql        $a2, $zero, L_800FAA28
    if (ctx->r6 == 0) {
        // 0x800FAA18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FAA28;
    }
    goto skip_0;
    // 0x800FAA18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FAA1C: jal         0x8008A5A0
    // 0x800FAA20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _scinfobar_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800FAA20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800FAA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FAA28:
    // 0x800FAA28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FAA2C: jr          $ra
    // 0x800FAA30: nop

    return;
    // 0x800FAA30: nop

;}
RECOMP_FUNC void func_808000BC_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: jal         0x80100094
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808000D8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x808000DC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000E4: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x808000E8: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808000EC: beq         $at, $zero, L_808001E4
    if (ctx->r1 == 0) {
        // 0x808000F0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001E4;
    }
    // 0x808000F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1204, 0X8D0) << 16);
    // 0x808000F8: addu        $at, $at, $t8
    gpr jr_addend_80800100 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000FC: lw          $t8, 0x8D0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1204, 0X8D0));
    // 0x80800100: jr          $t8
    // 0x80800104: nop

    switch (jr_addend_80800100 >> 2) {
        case 0: goto L_80800108; break;
        case 1: goto L_80800118; break;
        case 2: goto L_808001E4; break;
        case 3: goto L_80800154; break;
        case 4: goto L_8080018C; break;
        case 5: goto L_808001B0; break;
        default: switch_error(__func__, 0x80800100, 0x808008D0);
    }
    // 0x80800104: nop

L_80800108:
    // 0x80800108: jal         0x80800634
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800634_chmrsicecube(rdram, ctx);
        goto after_1;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800110: b           L_808001E4
    // 0x80800114: nop

        goto L_808001E4;
    // 0x80800114: nop

L_80800118:
    // 0x80800118: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800124: jal         0x80800898
    // 0x80800128: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80800898_chmrsicecube(rdram, ctx);
        goto after_2;
    // 0x80800128: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
    // 0x8080012C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800130: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80800134: jal         0x80101DDC
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080013C: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x80800140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E4;
    }
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x80102424
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080014C: b           L_808001E4
    // 0x80800150: nop

        goto L_808001E4;
    // 0x80800150: nop

L_80800154:
    // 0x80800154: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800158: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8080015C: jal         0x80101DDC
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800164: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x80800168: nop
    
            goto L_808001E4;
    }
    // 0x80800168: nop

    // 0x8080016C: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800178: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x8080017C: jal         0x80102424
    // 0x80800180: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800180: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_6:
    // 0x80800184: b           L_808001E4
    // 0x80800188: nop

        goto L_808001E4;
    // 0x80800188: nop

L_8080018C:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x8008A4C0
    // 0x80800194: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800194: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80800198: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x8080019C: nop
    
            goto L_808001E4;
    }
    // 0x8080019C: nop

    // 0x808001A0: jal         0x808006C4
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C4_chmrsicecube(rdram, ctx);
        goto after_8;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001A8: b           L_808001E4
    // 0x808001AC: nop

        goto L_808001E4;
    // 0x808001AC: nop

L_808001B0:
    // 0x808001B0: jal         0x80800898
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800898_chmrsicecube(rdram, ctx);
        goto after_9;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001BC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x808001C0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x808001CC: jal         0x80101DDC
    // 0x808001D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80101DDC(rdram, ctx);
        goto after_10;
    // 0x808001D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_10:
    // 0x808001D4: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E4;
    }
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x80102424
    // 0x808001E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808001E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
L_808001E4:
    // 0x808001E4: jal         0x8008A040
    // 0x808001E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x808001E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x808001EC: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x808001F0: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8080024C;
    }
    // 0x808001F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x8080066C
    // 0x808001FC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8080066C_chmrsicecube(rdram, ctx);
        goto after_13;
    // 0x808001FC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_13:
    // 0x80800200: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800204: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800208: jal         0x800EE7F8
    // 0x8080020C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x8080020C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_14:
    // 0x80800210: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080021C: beql        $t0, $zero, L_80800250
    if (ctx->r8 == 0) {
        // 0x80800220: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800250;
    }
    goto skip_0;
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800224: jal         0x8008A0D0
    // 0x80800228: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x80800228: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_15:
    // 0x8080022C: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800230: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8080024C;
    }
    // 0x80800230: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800234: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800238: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080023C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800240: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800244: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800248: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
L_8080024C:
    // 0x8080024C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800250:
    // 0x80800250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_808041C4_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808041C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808041C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808041CC: beq         $a1, $at, L_808041E8
    if (ctx->r5 == ctx->r1) {
        // 0x808041D0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808041E8;
    }
    // 0x808041D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808041D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808041D8: beql        $a1, $at, L_80804208
    if (ctx->r5 == ctx->r1) {
        // 0x808041DC: lhu         $t8, 0x72($a0)
        ctx->r24 = MEM_HU(ctx->r4, 0X72);
            goto L_80804208;
    }
    goto skip_0;
    // 0x808041DC: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    skip_0:
    // 0x808041E0: b           L_80804218
    // 0x808041E4: nop

        goto L_80804218;
    // 0x808041E4: nop

L_808041E8:
    // 0x808041E8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808041EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808041F0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808041F4: bne         $t7, $at, L_80804218
    if (ctx->r15 != ctx->r1) {
        // 0x808041F8: nop
    
            goto L_80804218;
    }
    // 0x808041F8: nop

    // 0x808041FC: b           L_80804224
    // 0x80804200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804224;
    // 0x80804200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804204: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
L_80804208:
    // 0x80804208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080420C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80804210: beql        $t9, $at, L_80804224
    if (ctx->r25 == ctx->r1) {
        // 0x80804214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804224;
    }
    goto skip_1;
    // 0x80804214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80804218:
    // 0x80804218: jal         0x80102424
    // 0x8080421C: nop

    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080421C: nop

    after_0:
    // 0x80804220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804224:
    // 0x80804224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804228: jr          $ra
    // 0x8080422C: nop

    return;
    // 0x8080422C: nop

;}
RECOMP_FUNC void func_800BCEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCEC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCEC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCEC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BCECC: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCED0: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    // 0x800BCED4: jal         0x800BCCC0
    // 0x800BCED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BCEDC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCEE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800BCEE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCEE8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BCEEC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BCEF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800BCEF4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BCEF8: addu        $t3, $a1, $v1
    ctx->r11 = ADD32(ctx->r5, ctx->r3);
    // 0x800BCEFC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800BCF00: beq         $t1, $zero, L_800BCF10
    if (ctx->r9 == 0) {
        // 0x800BCF04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BCF10;
    }
    // 0x800BCF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCF08: b           L_800BCF20
    // 0x800BCF0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BCF20;
    // 0x800BCF0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BCF10:
    // 0x800BCF10: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800BCF14: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800BCF18: srl         $t5, $t4, 1
    ctx->r13 = S32(U32(ctx->r12) >> 1);
    // 0x800BCF1C: subu        $v0, $t2, $t5
    ctx->r2 = SUB32(ctx->r10, ctx->r13);
L_800BCF20:
    // 0x800BCF20: jr          $ra
    // 0x800BCF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BCF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void cadbfunc_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003AC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x808003B0: jal         0x808002F8
    // 0x808003B4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_808002F8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808003B4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x808003B8: bne         $v0, $zero, L_808003C8
    if (ctx->r2 != 0) {
        // 0x808003BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808003C8;
    }
    // 0x808003BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003C0: b           L_808003DC
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003DC;
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C8:
    // 0x808003C8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808003CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003D0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x808003D4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
L_808003DC:
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_8009C150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C150: lw          $t6, 0xE4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C154: jr          $ra
    // 0x8009C158: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8009C158: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
