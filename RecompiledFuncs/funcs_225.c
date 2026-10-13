#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080032C_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800330: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2136, 0X910) << 16);
    // 0x80800334: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080033C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800340: addiu       $t7, $t7, 0x910
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2136, 0X910));
    // 0x80800344: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800348: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x8080034C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800350: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800354: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800358: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2136, 0X91C) << 16);
    // 0x8080035C: addiu       $t2, $t2, 0x91C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2136, 0X91C));
    // 0x80800360: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800364: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800368: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080036C: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x80800370: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800374: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800378: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8080037C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2136, 0X928) << 16);
    // 0x80800380: addiu       $t8, $t8, 0x928
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2136, 0X928));
    // 0x80800384: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800388: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8080038C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800390: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x80800394: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800398: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8080039C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x808003A0: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2136, 0X934) << 16);
    // 0x808003A4: addiu       $t3, $t3, 0x934
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2136, 0X934));
    // 0x808003A8: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x808003AC: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x808003B0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x808003B4: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x808003B8: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x808003BC: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x808003C0: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x808003C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003CC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x808003D0: jal         0x80100094
    // 0x808003D4: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    after_0:
    // 0x808003D8: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x808003DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003E4: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x808003E8: bgez        $t9, L_80800514
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808003EC: addiu       $a2, $sp, 0x58
        ctx->r6 = ADD32(ctx->r29, 0X58);
            goto L_80800514;
    }
    // 0x808003EC: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x808003F0: jal         0x8008A0E0
    // 0x808003F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808003F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x808003F8: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x808003FC: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80800400: addiu       $t2, $sp, 0x64
    ctx->r10 = ADD32(ctx->r29, 0X64);
    // 0x80800404: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800408: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080040C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: lui         $a1, 0x432F
    ctx->r5 = S32(0X432F << 16);
    // 0x80800418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080041C: jal         0x80089878
    // 0x80800420: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800420: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_2:
    // 0x80800424: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080042C: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80800430: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x80800434: addiu       $t3, $sp, 0x58
    ctx->r11 = ADD32(ctx->r29, 0X58);
    // 0x80800438: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8080043C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800440: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800444: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80800448: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8080044C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800450: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: jal         0x80089870
    // 0x8080045C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080045C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_3:
    // 0x80800460: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80800464: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80800468: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x8080046C: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x80800470: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80800474: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80800478: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8080047C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800488: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8080048C: jal         0x80089870
    // 0x80800490: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800490: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    after_4:
    // 0x80800494: jal         0x800898B0
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080049C: lhu         $t0, 0x72($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X72);
    // 0x808004A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004A4: srl         $t2, $t0, 10
    ctx->r10 = S32(U32(ctx->r8) >> 10);
    // 0x808004A8: bnel        $t2, $at, L_80800518
    if (ctx->r10 != ctx->r1) {
        // 0x808004AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800518;
    }
    goto skip_0;
    // 0x808004AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808004B0: jal         0x800898E8
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808004C4: nop

    // 0x808004C8: bc1fl       L_80800518
    if (!c1cs) {
        // 0x808004CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800518;
    }
    goto skip_1;
    // 0x808004CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x808004D0: jal         0x80089868
    // 0x808004D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808004D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_7:
    // 0x808004D8: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800514;
    }
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x800898C8
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808004E8: jal         0x800DA298
    // 0x808004EC: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808004EC: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    after_9:
    // 0x808004F0: bne         $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x808004F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080050C;
    }
    // 0x808004F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004FC: jal         0x80800150
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_10;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800504: b           L_80800518
    // 0x80800508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800518;
    // 0x80800508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080050C:
    // 0x8080050C: jal         0x80800150
    // 0x80800510: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_11;
    // 0x80800510: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
L_80800514:
    // 0x80800514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800518:
    // 0x80800518: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080051C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800520: jr          $ra
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800F9178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9178: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F917C: jr          $ra
    // 0x800F9180: sb          $zero, 0x54FA($at)
    MEM_B(0X54FA, ctx->r1) = 0;
    return;
    // 0x800F9180: sb          $zero, 0x54FA($at)
    MEM_B(0X54FA, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800FB774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FB778: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FB77C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800FB780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB784: jal         0x80017764
    // 0x800FB788: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    func_80017764(rdram, ctx);
        goto after_0;
    // 0x800FB788: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    after_0:
    // 0x800FB78C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FB790: jal         0x800FB6C0
    // 0x800FB794: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800FB6C0(rdram, ctx);
        goto after_1;
    // 0x800FB794: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800FB798: jal         0x800FB5BC
    // 0x800FB79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB5BC(rdram, ctx);
        goto after_2;
    // 0x800FB79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FB7A0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FB7A4: addiu       $t9, $t9, 0x57D0
    ctx->r25 = ADD32(ctx->r25, 0X57D0);
    // 0x800FB7A8: subu        $a0, $s0, $t9
    ctx->r4 = SUB32(ctx->r16, ctx->r25);
    // 0x800FB7AC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FB7B0: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FB7B4: lbu         $t7, 0x30($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X30);
    // 0x800FB7B8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800FB7BC: mflo        $t0
    ctx->r8 = lo;
    // 0x800FB7C0: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x800FB7C4: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    // 0x800FB7C8: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x800FB7CC: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // 0x800FB7D0: lh          $a1, 0x22($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X22);
    // 0x800FB7D4: jal         0x80017404
    // 0x800FB7D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80017404(rdram, ctx);
        goto after_3;
    // 0x800FB7D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x800FB7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FB7E0: jal         0x800FB6E0
    // 0x800FB7E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FB6E0(rdram, ctx);
        goto after_4;
    // 0x800FB7E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FB7E8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800FB7EC: jal         0x800172D4
    // 0x800FB7F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800172D4(rdram, ctx);
        goto after_5;
    // 0x800FB7F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
    // 0x800FB7F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB7F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FB7FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FB800: jr          $ra
    // 0x800FB804: nop

    return;
    // 0x800FB804: nop

;}
RECOMP_FUNC void func_800CE8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE8D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CE8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE8E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CE8E8: jal         0x800CE3E0
    // 0x800CE8EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE8EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CE8F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800CE8F4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CE8F8: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x800CE8FC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800CE900: sh          $a2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r6;
    // 0x800CE904: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x800CE908: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
    // 0x800CE90C: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800CE910: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800CE914: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x800CE918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE91C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE920: jr          $ra
    // 0x800CE924: nop

    return;
    // 0x800CE924: nop

;}
RECOMP_FUNC void func_8080022C_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800230: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800234: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080023C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800240: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800244: jal         0x800EE7F8
    // 0x80800248: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800248: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080024C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800254: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800258: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080025C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800260: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800264: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800268: jal         0x80086670
    // 0x8080026C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080026C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800270: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1056, 0X458) << 16);
    // 0x80800274: addiu       $a2, $a2, 0x458
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1056, 0X458));
    // 0x80800278: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080027C: jal         0x80089D18
    // 0x80800280: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800280: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800284: jal         0x800DA544
    // 0x80800288: addiu       $a0, $zero, 0x173
    ctx->r4 = ADD32(0, 0X173);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800288: addiu       $a0, $zero, 0x173
    ctx->r4 = ADD32(0, 0X173);
    after_3:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_808004F0_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x808004FC: jal         0x800D0A9C
    // 0x80800500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800504: bnel        $v0, $zero, L_80800530
    if (ctx->r2 != 0) {
        // 0x80800508: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80800530;
    }
    goto skip_0;
    // 0x80800508: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_0:
    // 0x8080050C: jal         0x80088840
    // 0x80800510: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800510: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_1:
    // 0x80800514: bne         $v0, $zero, L_8080052C
    if (ctx->r2 != 0) {
        // 0x80800518: addiu       $a0, $zero, 0x6DF
        ctx->r4 = ADD32(0, 0X6DF);
            goto L_8080052C;
    }
    // 0x80800518: addiu       $a0, $zero, 0x6DF
    ctx->r4 = ADD32(0, 0X6DF);
    // 0x8080051C: jal         0x800DA564
    // 0x80800520: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_2;
    // 0x80800520: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800524: b           L_80800534
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800534;
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080052C:
    // 0x8080052C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80800530:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800534:
    // 0x80800534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_80800444_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800450: jal         0x800DA298
    // 0x80800454: addiu       $a0, $zero, 0xA17
    ctx->r4 = ADD32(0, 0XA17);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800454: addiu       $a0, $zero, 0xA17
    ctx->r4 = ADD32(0, 0XA17);
    after_0:
    // 0x80800458: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080045C: beq         $v1, $zero, L_80800470
    if (ctx->r3 == 0) {
        // 0x80800460: nop
    
            goto L_80800470;
    }
    // 0x80800460: nop

    // 0x80800464: jal         0x800DA298
    // 0x80800468: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800468: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    after_1:
    // 0x8080046C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800470:
    // 0x80800470: beq         $v1, $zero, L_80800498
    if (ctx->r3 == 0) {
        // 0x80800474: addiu       $a0, $zero, 0x44
        ctx->r4 = ADD32(0, 0X44);
            goto L_80800498;
    }
    // 0x80800474: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80800478: jal         0x800D0A9C
    // 0x8080047C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x8080047C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800480: bne         $v0, $zero, L_80800498
    if (ctx->r2 != 0) {
        // 0x80800484: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800498;
    }
    // 0x80800484: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800488: jal         0x80800830
    // 0x8080048C: addiu       $a1, $zero, 0x127E
    ctx->r5 = ADD32(0, 0X127E);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_3;
    // 0x8080048C: addiu       $a1, $zero, 0x127E
    ctx->r5 = ADD32(0, 0X127E);
    after_3:
    // 0x80800490: b           L_80800534
    // 0x80800494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800534;
    // 0x80800494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800498:
    // 0x80800498: addiu       $a0, $zero, 0xA16
    ctx->r4 = ADD32(0, 0XA16);
    // 0x8080049C: jal         0x800DA9E4
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_4;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004A4: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A8: addiu       $a0, $zero, 0xA17
        ctx->r4 = ADD32(0, 0XA17);
            goto L_808004C0;
    }
    // 0x808004A8: addiu       $a0, $zero, 0xA17
    ctx->r4 = ADD32(0, 0XA17);
    // 0x808004AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004B0: jal         0x80800830
    // 0x808004B4: addiu       $a1, $zero, 0x1280
    ctx->r5 = ADD32(0, 0X1280);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_5;
    // 0x808004B4: addiu       $a1, $zero, 0x1280
    ctx->r5 = ADD32(0, 0X1280);
    after_5:
    // 0x808004B8: b           L_80800534
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800534;
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004C0:
    // 0x808004C0: jal         0x800DA9E4
    // 0x808004C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x808004C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808004C8: beq         $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x808004CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800510;
    }
    // 0x808004CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: jal         0x800DA298
    // 0x808004D4: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808004D4: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    after_7:
    // 0x808004D8: bne         $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x808004DC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808004F0;
    }
    // 0x808004DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004E0: jal         0x80800830
    // 0x808004E4: addiu       $a1, $zero, 0x127C
    ctx->r5 = ADD32(0, 0X127C);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_8;
    // 0x808004E4: addiu       $a1, $zero, 0x127C
    ctx->r5 = ADD32(0, 0X127C);
    after_8:
    // 0x808004E8: b           L_80800534
    // 0x808004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800534;
    // 0x808004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004F0:
    // 0x808004F0: jal         0x800DA298
    // 0x808004F4: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808004F4: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    after_9:
    // 0x808004F8: bne         $v0, $zero, L_80800530
    if (ctx->r2 != 0) {
        // 0x808004FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800530;
    }
    // 0x808004FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800500: jal         0x80800830
    // 0x80800504: addiu       $a1, $zero, 0x127D
    ctx->r5 = ADD32(0, 0X127D);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_10;
    // 0x80800504: addiu       $a1, $zero, 0x127D
    ctx->r5 = ADD32(0, 0X127D);
    after_10:
    // 0x80800508: b           L_80800534
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800534;
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800510:
    // 0x80800510: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1876, 0X988) << 16);
    // 0x80800514: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1876, 0X8E0) << 16);
    // 0x80800518: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8080051C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800520: addiu       $a3, $a3, 0x8E0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1876, 0X8E0));
    // 0x80800524: addiu       $a2, $a2, 0x988
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1876, 0X988));
    // 0x80800528: jal         0x8008A1F0
    // 0x8080052C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x8080052C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_11:
L_80800530:
    // 0x80800530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800534:
    // 0x80800534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_801049B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801049B4: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x801049B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801049BC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801049C0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801049C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801049C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801049CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801049D0: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x801049D4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801049D8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x801049DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801049E0: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x801049E4: bgez        $t8, L_80104A00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801049E8: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80104A00;
    }
    // 0x801049E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801049EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801049F0: jal         0x800EFA88
    // 0x801049F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800EFA88(rdram, ctx);
        goto after_0;
    // 0x801049F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x801049F8: b           L_80104D64
    // 0x801049FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80104D64;
    // 0x801049FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80104A00:
    // 0x80104A00: jal         0x800EE7F8
    // 0x80104A04: addiu       $a0, $sp, 0x114
    ctx->r4 = ADD32(ctx->r29, 0X114);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80104A04: addiu       $a0, $sp, 0x114
    ctx->r4 = ADD32(ctx->r29, 0X114);
    after_1:
    // 0x80104A08: lw          $a3, 0x120($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X120);
    // 0x80104A0C: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x80104A10: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    // 0x80104A14: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80104A18: addiu       $s2, $a3, 0x4
    ctx->r18 = ADD32(ctx->r7, 0X4);
L_80104A1C:
    // 0x80104A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80104A20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80104A24: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x80104A28: jal         0x800EE88C
    // 0x80104A2C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80104A2C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x80104A30: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80104A34: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80104A38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104A3C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80104A40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80104A44:
    // 0x80104A44: lbu         $t9, 0x18($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X18);
    // 0x80104A48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104A4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104A50: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80104A54: bne         $v0, $s0, L_80104A44
    if (ctx->r2 != ctx->r16) {
        // 0x80104A58: sw          $t9, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r25;
            goto L_80104A44;
    }
    // 0x80104A58: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x80104A5C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80104A60: addiu       $t0, $sp, 0xC8
    ctx->r8 = ADD32(ctx->r29, 0XC8);
    // 0x80104A64: sltu        $at, $a2, $t0
    ctx->r1 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x80104A68: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80104A6C: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x80104A70: bne         $at, $zero, L_80104A1C
    if (ctx->r1 != 0) {
        // 0x80104A74: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80104A1C;
    }
    // 0x80104A74: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80104A78: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x80104A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104A80: jal         0x800F36D4
    // 0x80104A84: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    func_800F36D4(rdram, ctx);
        goto after_3;
    // 0x80104A84: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_3:
    // 0x80104A88: beq         $v0, $zero, L_80104AB0
    if (ctx->r2 == 0) {
        // 0x80104A8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80104AB0;
    }
    // 0x80104A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104A90: jal         0x800F36D4
    // 0x80104A94: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    func_800F36D4(rdram, ctx);
        goto after_4;
    // 0x80104A94: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_4:
    // 0x80104A98: beq         $v0, $zero, L_80104AB0
    if (ctx->r2 == 0) {
        // 0x80104A9C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80104AB0;
    }
    // 0x80104A9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80104AA0: jal         0x800EE830
    // 0x80104AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE830(rdram, ctx);
        goto after_5;
    // 0x80104AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80104AA8: b           L_80104D64
    // 0x80104AAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80104D64;
    // 0x80104AAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80104AB0:
    // 0x80104AB0: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
    // 0x80104AB4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80104AB8: addiu       $a0, $sp, 0x108
    ctx->r4 = ADD32(ctx->r29, 0X108);
    // 0x80104ABC: jal         0x800EFB24
    // 0x80104AC0: addiu       $a1, $sp, 0x114
    ctx->r5 = ADD32(ctx->r29, 0X114);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80104AC0: addiu       $a1, $sp, 0x114
    ctx->r5 = ADD32(ctx->r29, 0X114);
    after_6:
    // 0x80104AC4: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x80104AC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80104ACC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x80104AD0: jal         0x800EFB24
    // 0x80104AD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80104AD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80104AD8: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x80104ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104AE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80104AE4: jal         0x800EFB24
    // 0x80104AE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80104AE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80104AEC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80104AF0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80104AF4: jal         0x800EFB24
    // 0x80104AF8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x80104AF8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x80104AFC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80104B00: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80104B04: jal         0x800EFB24
    // 0x80104B08: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x80104B08: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x80104B0C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80104B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80104B14: jal         0x800EE97C
    // 0x80104B18: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EE97C(rdram, ctx);
        goto after_11;
    // 0x80104B18: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_11:
    // 0x80104B1C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x80104B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104B24: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80104B28: jal         0x800EE97C
    // 0x80104B2C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800EE97C(rdram, ctx);
        goto after_12;
    // 0x80104B2C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_12:
    // 0x80104B30: addiu       $a0, $sp, 0x108
    ctx->r4 = ADD32(ctx->r29, 0X108);
    // 0x80104B34: jal         0x800EEAA4
    // 0x80104B38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_13;
    // 0x80104B38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x80104B3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80104B40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80104B44: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x80104B48: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80104B4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80104B50: bc1f        L_80104B5C
    if (!c1cs) {
        // 0x80104B54: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80104B5C;
    }
    // 0x80104B54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80104B58: lwc1        $f12, 0x6444($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6444);
L_80104B5C:
    // 0x80104B5C: jal         0x800EEAA4
    // 0x80104B60: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_14;
    // 0x80104B60: swc1        $f12, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f12.u32l;
    after_14:
    // 0x80104B64: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80104B68: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80104B6C: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80104B70: div.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80104B74: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80104B78: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80104B7C: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x80104B80: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80104B84: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80104B88: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80104B8C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80104B90: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80104B94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80104B98: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80104B9C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80104BA0: jal         0x800EFA4C
    // 0x80104BA4: nop

    func_800EFA4C(rdram, ctx);
        goto after_15;
    // 0x80104BA4: nop

    after_15:
    // 0x80104BA8: addiu       $a0, $sp, 0xFC
    ctx->r4 = ADD32(ctx->r29, 0XFC);
    // 0x80104BAC: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x80104BB0: jal         0x800EFB24
    // 0x80104BB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_16;
    // 0x80104BB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_16:
    // 0x80104BB8: addiu       $s1, $sp, 0xFC
    ctx->r17 = ADD32(ctx->r29, 0XFC);
    // 0x80104BBC: jal         0x800EEF94
    // 0x80104BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_17;
    // 0x80104BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80104BC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80104BC8: jal         0x800EEF94
    // 0x80104BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_18;
    // 0x80104BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80104BD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80104BD4: lwc1        $f16, 0x6448($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6448);
    // 0x80104BD8: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80104BDC: addiu       $v0, $sp, 0xA4
    ctx->r2 = ADD32(ctx->r29, 0XA4);
    // 0x80104BE0: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80104BE4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80104BE8: div.s       $f2, $f20, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80104BEC: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80104BF0: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x80104BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80104BF8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80104BFC: beq         $at, $zero, L_80104C48
    if (ctx->r1 == 0) {
        // 0x80104C00: subu        $t2, $t1, $a0
        ctx->r10 = SUB32(ctx->r9, ctx->r4);
            goto L_80104C48;
    }
    // 0x80104C00: subu        $t2, $t1, $a0
    ctx->r10 = SUB32(ctx->r9, ctx->r4);
L_80104C04:
    // 0x80104C04: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x80104C08: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80104C0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80104C10: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80104C14: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80104C18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104C1C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80104C20: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80104C24: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80104C28: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80104C2C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80104C30: nop

    // 0x80104C34: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x80104C38: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80104C3C: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x80104C40: bne         $at, $zero, L_80104C04
    if (ctx->r1 != 0) {
        // 0x80104C44: subu        $t2, $t1, $a0
        ctx->r10 = SUB32(ctx->r9, ctx->r4);
            goto L_80104C04;
    }
    // 0x80104C44: subu        $t2, $t1, $a0
    ctx->r10 = SUB32(ctx->r9, ctx->r4);
L_80104C48:
    // 0x80104C48: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x80104C4C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80104C50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104C54: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80104C58: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80104C5C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80104C60: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80104C64: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80104C68: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80104C6C: nop

    // 0x80104C70: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x80104C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80104C78: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x80104C7C: jal         0x800EFB24
    // 0x80104C80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_19;
    // 0x80104C80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_19:
    // 0x80104C84: jal         0x800EEF94
    // 0x80104C88: addiu       $a0, $sp, 0x108
    ctx->r4 = ADD32(ctx->r29, 0X108);
    func_800EEF94(rdram, ctx);
        goto after_20;
    // 0x80104C88: addiu       $a0, $sp, 0x108
    ctx->r4 = ADD32(ctx->r29, 0X108);
    after_20:
    // 0x80104C8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80104C90: jal         0x800EEF94
    // 0x80104C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_21;
    // 0x80104C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80104C98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80104C9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80104CA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80104CA4: lwc1        $f10, 0x644C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X644C);
    // 0x80104CA8: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80104CAC: addiu       $v0, $sp, 0xA4
    ctx->r2 = ADD32(ctx->r29, 0XA4);
    // 0x80104CB0: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80104CB4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80104CB8: div.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80104CBC: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80104CC0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80104CC4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80104CC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80104CCC: beq         $v0, $a1, L_80104D14
    if (ctx->r2 == ctx->r5) {
        // 0x80104CD0: subu        $t6, $t5, $a0
        ctx->r14 = SUB32(ctx->r13, ctx->r4);
            goto L_80104D14;
    }
    // 0x80104CD0: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
L_80104CD4:
    // 0x80104CD4: mtc1        $t6, $f20
    ctx->f20.u32l = ctx->r14;
    // 0x80104CD8: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80104CDC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80104CE0: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80104CE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80104CE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104CEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80104CF0: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80104CF4: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80104CF8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80104CFC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80104D00: nop

    // 0x80104D04: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80104D08: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x80104D0C: bne         $v0, $a1, L_80104CD4
    if (ctx->r2 != ctx->r5) {
        // 0x80104D10: subu        $t6, $t5, $a0
        ctx->r14 = SUB32(ctx->r13, ctx->r4);
            goto L_80104CD4;
    }
    // 0x80104D10: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
L_80104D14:
    // 0x80104D14: mtc1        $t6, $f20
    ctx->f20.u32l = ctx->r14;
    // 0x80104D18: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80104D1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104D20: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80104D24: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80104D28: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80104D2C: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80104D30: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80104D34: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80104D38: nop

    // 0x80104D3C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80104D40: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x80104D44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80104D48: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80104D4C: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80104D50: bgezl       $t1, L_80104D64
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80104D54: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80104D64;
    }
    goto skip_0;
    // 0x80104D54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80104D58: jal         0x80105390
    // 0x80104D5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80105390(rdram, ctx);
        goto after_22;
    // 0x80104D5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_22:
    // 0x80104D60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80104D64:
    // 0x80104D64: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80104D68: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80104D6C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80104D70: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80104D74: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80104D78: jr          $ra
    // 0x80104D7C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x80104D7C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_8080184C_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080184C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801850: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801854: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080185C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801860: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X226C) << 16);
    // 0x80801864: addiu       $a2, $a2, 0x226C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X226C));
    // 0x80801868: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080186C: jal         0x8008A1F0
    // 0x80801870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080187C: jr          $ra
    // 0x80801880: nop

    return;
    // 0x80801880: nop

;}
RECOMP_FUNC void func_800EFA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFA20: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EFA24: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFA28: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800EFA2C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EFA30: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EFA34: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EFA38: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800EFA3C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFA40: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800EFA44: jr          $ra
    // 0x800EFA48: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EFA48: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80800298_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080029C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: jal         0x80100094
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808002B4: jal         0x80101F24
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002BC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1760, 0XB90) << 16);
    // 0x808002C0: addiu       $a1, $a1, 0xB90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1760, 0XB90));
    // 0x808002C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808002C8: jal         0x800F3780
    // 0x808002CC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_800F3780(rdram, ctx);
        goto after_2;
    // 0x808002CC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_2:
    // 0x808002D0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808002D4: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x808002D8: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808002DC: bltzl       $t8, L_808006FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808002E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006FC;
    }
    goto skip_0;
    // 0x808002E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002E4: jal         0x800D9078
    // 0x808002E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x808002E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x808002EC: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x808002F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002F4: srl         $t9, $a0, 10
    ctx->r25 = S32(U32(ctx->r4) >> 10);
    // 0x808002F8: beq         $t9, $at, L_80800320
    if (ctx->r25 == ctx->r1) {
        // 0x808002FC: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_80800320;
    }
    // 0x808002FC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800304: beq         $t9, $at, L_80800394
    if (ctx->r25 == ctx->r1) {
        // 0x80800308: lui         $t4, 0x8080
        ctx->r12 = S32(RELOC_HI16(1760, 0XBD8) << 16);
            goto L_80800394;
    }
    // 0x80800308: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1760, 0XBD8) << 16);
    // 0x8080030C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800310: beq         $t9, $at, L_80800588
    if (ctx->r25 == ctx->r1) {
        // 0x80800314: lui         $t3, 0x8080
        ctx->r11 = S32(RELOC_HI16(1760, 0XBD8) << 16);
            goto L_80800588;
    }
    // 0x80800314: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1760, 0XBD8) << 16);
    // 0x80800318: b           L_808006E0
    // 0x8080031C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
        goto L_808006E0;
    // 0x8080031C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
L_80800320:
    // 0x80800320: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080032C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80800330: bgez        $t2, L_8080036C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800334: nop
    
            goto L_8080036C;
    }
    // 0x80800334: nop

    // 0x80800338: jal         0x80089BF0
    // 0x8080033C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080033C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA5C) << 16);
    // 0x80800344: lwc1        $f4, 0xA5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA5C));
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800350: nop

    // 0x80800354: bc1fl       L_80800388
    if (!c1cs) {
        // 0x80800358: lhu         $a0, 0x72($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X72);
            goto L_80800388;
    }
    goto skip_1;
    // 0x80800358: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x8080035C: jal         0x808008F8
    // 0x80800360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_5;
    // 0x80800360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800364: b           L_80800388
    // 0x80800368: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
        goto L_80800388;
    // 0x80800368: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
L_8080036C:
    // 0x8080036C: jal         0x80800990
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800990_chbadbeehive(rdram, ctx);
        goto after_6;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800374: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800378: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x808008F8
    // 0x80800380: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_7;
    // 0x80800380: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_80800384:
    // 0x80800384: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
L_80800388:
    // 0x80800388: srl         $t3, $a0, 10
    ctx->r11 = S32(U32(ctx->r4) >> 10);
    // 0x8080038C: b           L_808006DC
    // 0x80800390: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_808006DC;
    // 0x80800390: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_80800394:
    // 0x80800394: addiu       $t4, $t4, 0xBD8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1760, 0XBD8));
    // 0x80800398: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x808003A4: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x808003A8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x808003AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808003B0: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x808003B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808003B8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003BC: jal         0x801026CC
    // 0x808003C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_801026CC(rdram, ctx);
        goto after_8;
    // 0x808003C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x808003C4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808003C8: jal         0x8010D254
    // 0x808003CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_9;
    // 0x808003CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_9:
    // 0x808003D0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x808003DC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808003E0: bgez        $t9, L_80800470
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808003E4: nop
    
            goto L_80800470;
    }
    // 0x808003E4: nop

    // 0x808003E8: jal         0x80089BF0
    // 0x808003EC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x808003EC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x808003F0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808003F4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003F8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808003FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800408: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8080040C: jal         0x80102BF8
    // 0x80800410: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80102BF8(rdram, ctx);
        goto after_11;
    // 0x80800410: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x80800414: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800418: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080041C: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800420: ori         $a1, $a1, 0x5015
    ctx->r5 = ctx->r5 | 0X5015;
    // 0x80800424: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800430: jal         0x8010C3A8
    // 0x80800434: nop

    func_8010C3A8(rdram, ctx);
        goto after_12;
    // 0x80800434: nop

    after_12:
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800440: jal         0x80089BF0
    // 0x80800444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800454: nop

    // 0x80800458: bc1fl       L_8080057C
    if (!c1cs) {
        // 0x8080045C: lhu         $a0, 0x72($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X72);
            goto L_8080057C;
    }
    goto skip_2;
    // 0x8080045C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x80800460: jal         0x808008F8
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_14;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800468: b           L_8080057C
    // 0x8080046C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
        goto L_8080057C;
    // 0x8080046C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
L_80800470:
    // 0x80800470: jal         0x80089F78
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800478: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x8080047C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C0;
    }
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x80102D78
    // 0x80800484: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80102D78(rdram, ctx);
        goto after_16;
    // 0x80800484: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x80800488: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080048C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800490: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800494: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800498: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080049C: addiu       $t0, $zero, 0x5800
    ctx->r8 = ADD32(0, 0X5800);
    // 0x808004A0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808004A4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: jal         0x80089F90
    // 0x808004B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_17;
    // 0x808004B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x808004B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808004B8: lhu         $t1, 0x6($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6);
    // 0x808004BC: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
L_808004C0:
    // 0x808004C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808004C4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808004C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004CC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808004D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004D4: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x808004D8: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x808004DC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808004E8: jal         0x80089F80
    // 0x808004EC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x808004EC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x808004F0: jal         0x800D8FF8
    // 0x808004F4: nop

    func_800D8FF8(rdram, ctx);
        goto after_19;
    // 0x808004F4: nop

    after_19:
    // 0x808004F8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808004FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800500: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800504: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800508: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080050C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800510: jal         0x800F15F8
    // 0x80800514: nop

    func_800F15F8(rdram, ctx);
        goto after_20;
    // 0x80800514: nop

    after_20:
    // 0x80800518: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080051C: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800520: ori         $a1, $a1, 0x5115
    ctx->r5 = ctx->r5 | 0X5115;
    // 0x80800524: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800528: jal         0x8010C3A8
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_21;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800530: jal         0x80089F78
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800538: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x8080053C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1760, 0XA60) << 16);
            goto L_80800578;
    }
    // 0x8080053C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA60) << 16);
    // 0x80800540: jal         0x800DC298
    // 0x80800544: lwc1        $f12, 0xA60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA60));
    func_800DC298(rdram, ctx);
        goto after_23;
    // 0x80800544: lwc1        $f12, 0xA60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA60));
    after_23:
    // 0x80800548: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x8080054C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800578;
    }
    // 0x8080054C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800550: jal         0x8010C9B0
    // 0x80800554: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010C9B0(rdram, ctx);
        goto after_24;
    // 0x80800554: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_24:
    // 0x80800558: beql        $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x8080055C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    goto skip_3;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800560: jal         0x8010C500
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_25;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800568: bne         $v0, $zero, L_80800578
    if (ctx->r2 != 0) {
        // 0x8080056C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800578;
    }
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800570:
    // 0x80800570: jal         0x808008F8
    // 0x80800574: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_26;
    // 0x80800574: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
L_80800578:
    // 0x80800578: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
L_8080057C:
    // 0x8080057C: srl         $t2, $a0, 10
    ctx->r10 = S32(U32(ctx->r4) >> 10);
    // 0x80800580: b           L_808006DC
    // 0x80800584: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
        goto L_808006DC;
    // 0x80800584: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_80800588:
    // 0x80800588: addiu       $t3, $t3, 0xBD8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1760, 0XBD8));
    // 0x8080058C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x80800598: lw          $a2, 0x4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X4);
    // 0x8080059C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x808005A0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808005A4: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    // 0x808005A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808005AC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005B0: jal         0x801026CC
    // 0x808005B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_801026CC(rdram, ctx);
        goto after_27;
    // 0x808005B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x808005B8: jal         0x80800990
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800990_chbadbeehive(rdram, ctx);
        goto after_28;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808005C0: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D0;
    }
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: jal         0x808008F8
    // 0x808005CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_29;
    // 0x808005CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
L_808005D0:
    // 0x808005D0: jal         0x80089F78
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808005D8: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x808005DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800620;
    }
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x80102D78
    // 0x808005E4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_31;
    // 0x808005E4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_31:
    // 0x808005E8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808005EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005F0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808005F4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808005F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005FC: addiu       $t6, $zero, 0x5800
    ctx->r14 = ADD32(0, 0X5800);
    // 0x80800600: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800604: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: jal         0x80089F90
    // 0x80800610: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_32;
    // 0x80800610: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_32:
    // 0x80800614: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800618: lhu         $t7, 0x6($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X6);
    // 0x8080061C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
L_80800620:
    // 0x80800620: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800624: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800628: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080062C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800630: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800634: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800638: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x8080063C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800648: jal         0x80089F80
    // 0x8080064C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_33;
    // 0x8080064C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_33:
    // 0x80800650: jal         0x800D8FF8
    // 0x80800654: nop

    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x80800654: nop

    after_34:
    // 0x80800658: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080065C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800660: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800664: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800668: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080066C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800670: jal         0x800F15F8
    // 0x80800674: nop

    func_800F15F8(rdram, ctx);
        goto after_35;
    // 0x80800674: nop

    after_35:
    // 0x80800678: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080067C: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800680: ori         $a1, $a1, 0x5115
    ctx->r5 = ctx->r5 | 0X5115;
    // 0x80800684: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800688: jal         0x8010C3A8
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_36;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800690: jal         0x80089F78
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_37;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800698: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x8080069C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1760, 0XA64) << 16);
            goto L_808006D0;
    }
    // 0x8080069C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA64) << 16);
    // 0x808006A0: jal         0x800DC298
    // 0x808006A4: lwc1        $f12, 0xA64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA64));
    func_800DC298(rdram, ctx);
        goto after_38;
    // 0x808006A4: lwc1        $f12, 0xA64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA64));
    after_38:
    // 0x808006A8: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x808006AC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808006D0;
    }
    // 0x808006AC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808006B0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808006B4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808006B8: jal         0x800EFFB4
    // 0x808006BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_800EFFB4(rdram, ctx);
        goto after_39;
    // 0x808006BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_39:
    // 0x808006C0: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x808006C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D0;
    }
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x808008F8
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_40;
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
L_808006D0:
    // 0x808006D0: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x808006D4: srl         $t8, $a0, 10
    ctx->r24 = S32(U32(ctx->r4) >> 10);
    // 0x808006D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_808006DC:
    // 0x808006DC: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
L_808006E0:
    // 0x808006E0: beq         $at, $zero, L_808006F0
    if (ctx->r1 == 0) {
        // 0x808006E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F0;
    }
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: jal         0x8010C908
    // 0x808006EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8010C908(rdram, ctx);
        goto after_41;
    // 0x808006EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_41:
L_808006F0:
    // 0x808006F0: jal         0x80800158
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800158_chbadbeehive(rdram, ctx);
        goto after_42;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006FC:
    // 0x808006FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800700: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void mlwave_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000D0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808000D4: jal         0x800DC178
    // 0x808000D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808000D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808000E4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808000E8: jal         0x808001A8
    // 0x808000EC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    mlwave_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808000EC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086090: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x80086090);
    return;
    // 0x80086094: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080012C_sueggmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080013C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800140: jal         0x80100094
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800148: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x8080014C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800150: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800154: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80800000
    // 0x80800160: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80800000_sueggmove(rdram, ctx);
        goto after_1;
    // 0x80800160: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800164: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800168: addiu       $a0, $a0, -0x5BC8
    ctx->r4 = ADD32(ctx->r4, -0X5BC8);
    // 0x8080016C: jal         0x800EA600
    // 0x80800170: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EA600(rdram, ctx);
        goto after_2;
    // 0x80800170: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800174: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080017C: lui         $a3, 0x242
    ctx->r7 = S32(0X242 << 16);
    // 0x80800180: ori         $a3, $a3, 0xA0
    ctx->r7 = ctx->r7 | 0XA0;
    // 0x80800184: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080018C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800190: jal         0x800FAB50
    // 0x80800194: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_3;
    // 0x80800194: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800198: jal         0x800EA614
    // 0x8080019C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800EA614(rdram, ctx);
        goto after_4;
    // 0x8080019C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
    // 0x808001A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808001A4: beql        $t6, $zero, L_80800228
    if (ctx->r14 == 0) {
        // 0x808001A8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800228;
    }
    goto skip_0;
    // 0x808001A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808001AC: lbu         $t7, 0xE($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XE);
    // 0x808001B0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808001B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808001B8: bne         $t7, $zero, L_808001F4
    if (ctx->r15 != 0) {
        // 0x808001BC: nop
    
            goto L_808001F4;
    }
    // 0x808001BC: nop

    // 0x808001C0: jal         0x800EFD24
    // 0x808001C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_5;
    // 0x808001C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x808001C8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808001CC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808001D0: jal         0x800F1988
    // 0x808001D4: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    func_800F1988(rdram, ctx);
        goto after_6;
    // 0x808001D4: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    after_6:
    // 0x808001D8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001E0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808001E4: jal         0x800136E4
    // 0x808001E8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x808001E8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_7:
    // 0x808001EC: b           L_80800218
    // 0x808001F0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_80800218;
    // 0x808001F0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_808001F4:
    // 0x808001F4: jal         0x800F059C
    // 0x808001F8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800F059C(rdram, ctx);
        goto after_8;
    // 0x808001F8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x808001FC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800200: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800204: jal         0x800F0E00
    // 0x80800208: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    func_800F0E00(rdram, ctx);
        goto after_9;
    // 0x80800208: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    after_9:
    // 0x8080020C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800210: jal         0x80800108
    // 0x80800214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800108_sueggmove(rdram, ctx);
        goto after_10;
    // 0x80800214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
L_80800218:
    // 0x80800218: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8080021C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80800220: sw          $t9, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r25;
    // 0x80800224: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80800228:
    // 0x80800228: jal         0x800EE7F8
    // 0x8080022C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x8080022C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x80800230: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3326, 0X420) << 16);
    // 0x80800234: lwc1        $f10, 0x420($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3326, 0X420));
    // 0x80800238: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x8080023C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800240: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800244: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080024C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_808002A0_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B0: beq         $a1, $at, L_808002D4
    if (ctx->r5 == ctx->r1) {
        // 0x808002B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808002D4;
    }
    // 0x808002B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808002BC: beq         $a1, $at, L_808002EC
    if (ctx->r5 == ctx->r1) {
        // 0x808002C0: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_808002EC;
    }
    // 0x808002C0: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808002C4: beq         $a1, $at, L_808002FC
    if (ctx->r5 == ctx->r1) {
        // 0x808002C8: addiu       $a0, $zero, 0xD5
        ctx->r4 = ADD32(0, 0XD5);
            goto L_808002FC;
    }
    // 0x808002C8: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    // 0x808002CC: b           L_80800320
    // 0x808002D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_80800320;
    // 0x808002D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808002D4:
    // 0x808002D4: addiu       $a0, $zero, 0x11F
    ctx->r4 = ADD32(0, 0X11F);
    // 0x808002D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808002DC: jal         0x80101180
    // 0x808002E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808002E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808002E4: b           L_80800334
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800334;
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: jal         0x80800344
    // 0x808002F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800344_chprisonbits(rdram, ctx);
        goto after_1;
    // 0x808002F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808002F4: b           L_80800334
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800334;
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002FC:
    // 0x808002FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800300: jal         0x800DA298
    // 0x80800304: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800304: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800308: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800310: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8080031C;
    }
    // 0x80800310: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800314: b           L_80800334
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800334;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80800320:
    // 0x80800320: jal         0x80085820
    // 0x80800324: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800324: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800328: b           L_80800338
    // 0x8080032C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800338;
    // 0x8080032C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800334:
    // 0x80800334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800338:
    // 0x80800338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void func_800B7CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7CC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7CC8: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7CD4: beq         $a0, $zero, L_800B7CE4
    if (ctx->r4 == 0) {
        // 0x800B7CD8: nop
    
            goto L_800B7CE4;
    }
    // 0x800B7CD8: nop

    // 0x800B7CDC: jal         0x80088948
    // 0x800B7CE0: nop

    _fxleaves_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800B7CE0: nop

    after_0:
L_800B7CE4:
    // 0x800B7CE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7CE8: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7CEC: beq         $a0, $zero, L_800B7CFC
    if (ctx->r4 == 0) {
        // 0x800B7CF0: nop
    
            goto L_800B7CFC;
    }
    // 0x800B7CF0: nop

    // 0x800B7CF4: jal         0x80088900
    // 0x800B7CF8: nop

    _fxrain_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x800B7CF8: nop

    after_1:
L_800B7CFC:
    // 0x800B7CFC: jal         0x800B8FEC
    // 0x800B7D00: nop

    func_800B8FEC(rdram, ctx);
        goto after_2;
    // 0x800B7D00: nop

    after_2:
    // 0x800B7D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7D0C: jr          $ra
    // 0x800B7D10: nop

    return;
    // 0x800B7D10: nop

;}
RECOMP_FUNC void func_80800C88_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C88: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C98: jal         0x80100094
    // 0x80800C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CA0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80800CA4: beq         $v0, $zero, L_80800E50
    if (ctx->r2 == 0) {
        // 0x80800CA8: sw          $zero, 0x90($sp)
        MEM_W(0X90, ctx->r29) = 0;
            goto L_80800E50;
    }
    // 0x80800CA8: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x80800CAC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800CB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800CB4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800CB8: bgezl       $t8, L_80800E40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800CBC: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_80800E40;
    }
    goto skip_0;
    // 0x80800CBC: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_0:
    // 0x80800CC0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800CC4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x80800CC8: jal         0x800DBEFC
    // 0x80800CCC: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_1;
    // 0x80800CCC: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x80800CD0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800CD4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800CD8: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x80800CDC: jal         0x800DBEFC
    // 0x80800CE0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800CE0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_2:
    // 0x80800CE4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800CE8: jal         0x800EEB40
    // 0x80800CEC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80800CEC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_3:
    // 0x80800CF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F6C) << 16);
    // 0x80800CF4: lwc1        $f4, 0x1F6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F6C));
    // 0x80800CF8: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80800CFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800D00: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800D04: nop

    // 0x80800D08: bc1fl       L_80800D2C
    if (!c1cs) {
        // 0x80800D0C: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_80800D2C;
    }
    goto skip_1;
    // 0x80800D0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800D10: lbu         $t2, 0x3E($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3E);
    // 0x80800D14: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80800D18: bnel        $t2, $zero, L_80800D28
    if (ctx->r10 != 0) {
        // 0x80800D1C: sw          $t4, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r12;
            goto L_80800D28;
    }
    goto skip_2;
    // 0x80800D1C: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    skip_2:
    // 0x80800D20: sb          $t3, 0x3E($t1)
    MEM_B(0X3E, ctx->r9) = ctx->r11;
    // 0x80800D24: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
L_80800D28:
    // 0x80800D28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_80800D2C:
    // 0x80800D2C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80800D30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800D34: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    // 0x80800D38: jal         0x800DBEFC
    // 0x80800D3C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800DBEFC(rdram, ctx);
        goto after_4;
    // 0x80800D3C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x80800D40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800D44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D48: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80800D4C: jal         0x800DBEFC
    // 0x80800D50: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_5;
    // 0x80800D50: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x80800D54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800D58: jal         0x800EF04C
    // 0x80800D5C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800D5C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x80800D60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800D64: jal         0x800EF334
    // 0x80800D68: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x80800D68: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x80800D6C: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x80800D70: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800D74: lbu         $t7, 0x3F($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X3F);
    // 0x80800D78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800D7C: beq         $t7, $zero, L_80800DBC
    if (ctx->r15 == 0) {
        // 0x80800D80: nop
    
            goto L_80800DBC;
    }
    // 0x80800D80: nop

    // 0x80800D84: addiu       $a0, $a2, 0xC
    ctx->r4 = ADD32(ctx->r6, 0XC);
    // 0x80800D88: jal         0x800EFB24
    // 0x80800D8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800D8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_8:
    // 0x80800D90: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80800D94: jal         0x800EE7F8
    // 0x80800D98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800D98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800D9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA0: jal         0x800EF334
    // 0x80800DA4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_800EF334(rdram, ctx);
        goto after_10;
    // 0x80800DA4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_10:
    // 0x80800DA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800DAC: jal         0x800EF04C
    // 0x80800DB0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800DB0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80800DB4: b           L_80800DD4
    // 0x80800DB8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
        goto L_80800DD4;
    // 0x80800DB8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80800DBC:
    // 0x80800DBC: jal         0x800EE7F8
    // 0x80800DC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80800DC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800DC4: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80800DC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800DCC: sb          $t8, 0x3F($t9)
    MEM_B(0X3F, ctx->r25) = ctx->r24;
    // 0x80800DD0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80800DD4:
    // 0x80800DD4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800DD8: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80800DDC: jal         0x800DBEFC
    // 0x80800DE0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_13;
    // 0x80800DE0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_13:
    // 0x80800DE4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800DE8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800DEC: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x80800DF0: jal         0x800DBEFC
    // 0x80800DF4: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_14;
    // 0x80800DF4: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_14:
    // 0x80800DF8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800DFC: jal         0x800EF04C
    // 0x80800E00: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x80800E00: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_15:
    // 0x80800E04: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800E08: jal         0x800EF334
    // 0x80800E0C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_16;
    // 0x80800E0C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_16:
    // 0x80800E10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800E14: jal         0x800F1DF4
    // 0x80800E18: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800F1DF4(rdram, ctx);
        goto after_17;
    // 0x80800E18: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_17:
    // 0x80800E1C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80800E20: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80800E24: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x80800E28: jal         0x800F1828
    // 0x80800E2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F1828(rdram, ctx);
        goto after_18;
    // 0x80800E2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x80800E30: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80800E34: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80800E38: swc1        $f6, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f6.u32l;
    // 0x80800E3C: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_80800E40:
    // 0x80800E40: lbu         $v0, 0x3E($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X3E);
    // 0x80800E44: blez        $v0, L_80800E50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800E48: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80800E50;
    }
    // 0x80800E48: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80800E4C: sb          $t5, 0x3E($t4)
    MEM_B(0X3E, ctx->r12) = ctx->r13;
L_80800E50:
    // 0x80800E50: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800E54: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800E58: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800E5C: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800E60: beq         $at, $zero, L_808011DC
    if (ctx->r1 == 0) {
        // 0x80800E64: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808011DC;
    }
    // 0x80800E64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800E68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F70) << 16);
    // 0x80800E6C: addu        $at, $at, $t8
    gpr jr_addend_80800E74 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800E70: lw          $t8, 0x1F70($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F70));
    // 0x80800E74: jr          $t8
    // 0x80800E78: nop

    switch (jr_addend_80800E74 >> 2) {
        case 0: goto L_80800E7C; break;
        case 1: goto L_80800F1C; break;
        case 2: goto L_80800F74; break;
        case 3: goto L_808010A0; break;
        case 4: goto L_808011A4; break;
        case 5: goto L_808011DC; break;
        case 6: goto L_808011CC; break;
        default: switch_error(__func__, 0x80800E74, 0x80801F70);
    }
    // 0x80800E78: nop

L_80800E7C:
    // 0x80800E7C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1748, 0X20D4) << 16);
    // 0x80800E80: addiu       $a0, $a0, 0x20D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1748, 0X20D4));
    // 0x80800E84: jal         0x8010CAC0
    // 0x80800E88: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    func_8010CAC0(rdram, ctx);
        goto after_19;
    // 0x80800E88: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_19:
    // 0x80800E8C: beql        $v0, $zero, L_808011E0
    if (ctx->r2 == 0) {
        // 0x80800E90: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_3;
    // 0x80800E90: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_3:
    // 0x80800E94: jal         0x80090248
    // 0x80800E98: nop

    func_80090248(rdram, ctx);
        goto after_20;
    // 0x80800E98: nop

    after_20:
    // 0x80800E9C: beq         $v0, $zero, L_808011DC
    if (ctx->r2 == 0) {
        // 0x80800EA0: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_808011DC;
    }
    // 0x80800EA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800EA4: jal         0x8008FD70
    // 0x80800EA8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_8008FD70(rdram, ctx);
        goto after_21;
    // 0x80800EA8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_21:
    // 0x80800EAC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80800EB0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800EB4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80800EB8: jal         0x800C6E38
    // 0x80800EBC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_22;
    // 0x80800EBC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_22:
    // 0x80800EC0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80800EC4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80800EC8: beq         $t0, $zero, L_80800F0C
    if (ctx->r8 == 0) {
        // 0x80800ECC: nop
    
            goto L_80800F0C;
    }
    // 0x80800ECC: nop

    // 0x80800ED0: beq         $v0, $zero, L_80800F0C
    if (ctx->r2 == 0) {
        // 0x80800ED4: nop
    
            goto L_80800F0C;
    }
    // 0x80800ED4: nop

    // 0x80800ED8: jal         0x800DA298
    // 0x80800EDC: addiu       $a0, $zero, 0x1B9
    ctx->r4 = ADD32(0, 0X1B9);
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x80800EDC: addiu       $a0, $zero, 0x1B9
    ctx->r4 = ADD32(0, 0X1B9);
    after_23:
    // 0x80800EE0: bne         $v0, $zero, L_80800F0C
    if (ctx->r2 != 0) {
        // 0x80800EE4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800F0C;
    }
    // 0x80800EE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800EE8: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80800EEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800EF4: jal         0x800861A0
    // 0x80800EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x80800EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x80800EFC: jal         0x800DA544
    // 0x80800F00: addiu       $a0, $zero, 0x1B9
    ctx->r4 = ADD32(0, 0X1B9);
    func_800DA544(rdram, ctx);
        goto after_25;
    // 0x80800F00: addiu       $a0, $zero, 0x1B9
    ctx->r4 = ADD32(0, 0X1B9);
    after_25:
    // 0x80800F04: b           L_80800F0C
    // 0x80800F08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800F0C;
    // 0x80800F08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800F0C:
    // 0x80800F0C: jal         0x80801494
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801494_chlakemonster(rdram, ctx);
        goto after_26;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800F14: b           L_808011E0
    // 0x80800F18: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
        goto L_808011E0;
    // 0x80800F18: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_80800F1C:
    // 0x80800F1C: jal         0x80090298
    // 0x80800F20: nop

    func_80090298(rdram, ctx);
        goto after_27;
    // 0x80800F20: nop

    after_27:
    // 0x80800F24: beql        $v0, $zero, L_80800F38
    if (ctx->r2 == 0) {
        // 0x80800F28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F38;
    }
    goto skip_4;
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800F2C: jal         0x80090840
    // 0x80800F30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_80090840(rdram, ctx);
        goto after_28;
    // 0x80800F30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_28:
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F38:
    // 0x80800F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F3C: jal         0x80800A14
    // 0x80800F40: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    func_80800A14_chlakemonster(rdram, ctx);
        goto after_29;
    // 0x80800F40: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    after_29:
    // 0x80800F44: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80800F48: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80800F4C: sll         $t1, $t2, 19
    ctx->r9 = S32(ctx->r10 << 19);
    // 0x80800F50: bgezl       $t1, L_808011E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800F54: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_5;
    // 0x80800F54: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_5:
    // 0x80800F58: lbu         $t4, 0x3D($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X3D);
    // 0x80800F5C: beql        $t4, $zero, L_808011E0
    if (ctx->r12 == 0) {
        // 0x80800F60: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_6;
    // 0x80800F60: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x80800F64: jal         0x800907C0
    // 0x80800F68: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800907C0(rdram, ctx);
        goto after_30;
    // 0x80800F68: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_30:
    // 0x80800F6C: b           L_808011E0
    // 0x80800F70: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
        goto L_808011E0;
    // 0x80800F70: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_80800F74:
    // 0x80800F74: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1748, 0X21EC) << 16);
    // 0x80800F78: addiu       $t7, $t7, 0x21EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1748, 0X21EC));
    // 0x80800F7C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800F80: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80800F84: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800F88: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800F8C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800F90: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80800F94: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800F98: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80800F9C: beql        $t0, $zero, L_80800FB0
    if (ctx->r8 == 0) {
        // 0x80800FA0: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_80800FB0;
    }
    goto skip_7;
    // 0x80800FA0: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    skip_7:
    // 0x80800FA4: jal         0x8080064C
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlakemonster(rdram, ctx);
        goto after_31;
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800FAC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
L_80800FB0:
    // 0x80800FB0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FB4: jal         0x80101E14
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800FBC: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800FC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FDC;
    }
    // 0x80800FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC4: jal         0x808008E8
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E8_chlakemonster(rdram, ctx);
        goto after_33;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800FCC: jal         0x808001C0
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001C0_chlakemonster(rdram, ctx);
        goto after_34;
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800FD4: b           L_80800FFC
    // 0x80800FD8: nop

        goto L_80800FFC;
    // 0x80800FD8: nop

L_80800FDC:
    // 0x80800FDC: jal         0x80101E4C
    // 0x80800FE0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80101E4C(rdram, ctx);
        goto after_35;
    // 0x80800FE0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_35:
    // 0x80800FE4: beq         $v0, $zero, L_80800FFC
    if (ctx->r2 == 0) {
        // 0x80800FE8: nop
    
            goto L_80800FFC;
    }
    // 0x80800FE8: nop

    // 0x80800FEC: jal         0x80800968
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800968_chlakemonster(rdram, ctx);
        goto after_36;
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800FF4: jal         0x808001C0
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001C0_chlakemonster(rdram, ctx);
        goto after_37;
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
L_80800FFC:
    // 0x80800FFC: jal         0x80101DDC
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_38;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80801004: beq         $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80801008: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801014;
    }
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080100C: jal         0x80801494
    // 0x80801010: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_39;
    // 0x80801010: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_39:
L_80801014:
    // 0x80801014: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80801018: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8080101C: sll         $t1, $t2, 19
    ctx->r9 = S32(ctx->r10 << 19);
    // 0x80801020: bgezl       $t1, L_808011E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801024: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_8;
    // 0x80801024: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_8:
    // 0x80801028: lbu         $t4, 0x3D($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X3D);
    // 0x8080102C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801030: beql        $t4, $zero, L_808011E0
    if (ctx->r12 == 0) {
        // 0x80801034: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_9;
    // 0x80801034: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_9:
    // 0x80801038: jal         0x800EE7F8
    // 0x8080103C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_40;
    // 0x8080103C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_40:
    // 0x80801040: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F8C) << 16);
    // 0x80801044: lwc1        $f10, 0x1F8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F8C));
    // 0x80801048: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080104C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801050: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80801054: jal         0x800906B0
    // 0x80801058: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    func_800906B0(rdram, ctx);
        goto after_41;
    // 0x80801058: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_41:
    // 0x8080105C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80801060: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801064: jal         0x80101E14
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_42;
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080106C: beql        $v0, $zero, L_808011E0
    if (ctx->r2 == 0) {
        // 0x80801070: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_10;
    // 0x80801070: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_10:
    // 0x80801074: jal         0x80090708
    // 0x80801078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_43;
    // 0x80801078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x8080107C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1748, 0X21F8) << 16);
    // 0x80801080: addiu       $a1, $a1, 0x21F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1748, 0X21F8));
    // 0x80801084: jal         0x80090590
    // 0x80801088: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_80090590(rdram, ctx);
        goto after_44;
    // 0x80801088: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_44:
    // 0x8080108C: jal         0x8009086C
    // 0x80801090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8009086C(rdram, ctx);
        goto after_45;
    // 0x80801090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_45:
    // 0x80801094: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80801098: b           L_808011DC
    // 0x8080109C: sb          $zero, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = 0;
        goto L_808011DC;
    // 0x8080109C: sb          $zero, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = 0;
L_808010A0:
    // 0x808010A0: jal         0x80090298
    // 0x808010A4: nop

    func_80090298(rdram, ctx);
        goto after_46;
    // 0x808010A4: nop

    after_46:
    // 0x808010A8: beql        $v0, $zero, L_808010BC
    if (ctx->r2 == 0) {
        // 0x808010AC: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_808010BC;
    }
    goto skip_11;
    // 0x808010AC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_11:
    // 0x808010B0: jal         0x80090840
    // 0x808010B4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_80090840(rdram, ctx);
        goto after_47;
    // 0x808010B4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_47:
    // 0x808010B8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_808010BC:
    // 0x808010BC: beql        $t6, $zero, L_808010D0
    if (ctx->r14 == 0) {
        // 0x808010C0: lui         $a1, 0x3D8F
        ctx->r5 = S32(0X3D8F << 16);
            goto L_808010D0;
    }
    goto skip_12;
    // 0x808010C0: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    skip_12:
    // 0x808010C4: jal         0x8080064C
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlakemonster(rdram, ctx);
        goto after_48;
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808010CC: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
L_808010D0:
    // 0x808010D0: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x808010D4: jal         0x80101E14
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_49;
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x808010DC: beq         $v0, $zero, L_808010F4
    if (ctx->r2 == 0) {
        // 0x808010E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010F4;
    }
    // 0x808010E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E4: jal         0x80800968
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800968_chlakemonster(rdram, ctx);
        goto after_50;
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808010EC: b           L_80801178
    // 0x808010F0: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
        goto L_80801178;
    // 0x808010F0: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
L_808010F4:
    // 0x808010F4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808010F8: jal         0x80101E14
    // 0x808010FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_51;
    // 0x808010FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_51:
    // 0x80801100: beq         $v0, $zero, L_80801138
    if (ctx->r2 == 0) {
        // 0x80801104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801138;
    }
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801108: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X207C) << 16);
    // 0x8080110C: addiu       $a2, $a2, 0x207C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X207C));
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801114: jal         0x80089D18
    // 0x80801118: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x80801118: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_52:
    // 0x8080111C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80801120: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801128: jal         0x8009086C
    // 0x8080112C: sb          $t7, 0x3D($t9)
    MEM_B(0X3D, ctx->r25) = ctx->r15;
    func_8009086C(rdram, ctx);
        goto after_53;
    // 0x8080112C: sb          $t7, 0x3D($t9)
    MEM_B(0X3D, ctx->r25) = ctx->r15;
    after_53:
    // 0x80801130: b           L_80801178
    // 0x80801134: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
        goto L_80801178;
    // 0x80801134: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
L_80801138:
    // 0x80801138: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080113C: jal         0x80101E14
    // 0x80801140: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_54;
    // 0x80801140: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_54:
    // 0x80801144: beq         $v0, $zero, L_8080115C
    if (ctx->r2 == 0) {
        // 0x80801148: nop
    
            goto L_8080115C;
    }
    // 0x80801148: nop

    // 0x8080114C: jal         0x808008E8
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E8_chlakemonster(rdram, ctx);
        goto after_55;
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80801154: b           L_80801178
    // 0x80801158: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
        goto L_80801178;
    // 0x80801158: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
L_8080115C:
    // 0x8080115C: jal         0x80101DDC
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_56;
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80801164: beql        $v0, $zero, L_80801178
    if (ctx->r2 == 0) {
        // 0x80801168: lw          $t0, 0x7C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X7C);
            goto L_80801178;
    }
    goto skip_13;
    // 0x80801168: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    skip_13:
    // 0x8080116C: jal         0x808009CC
    // 0x80801170: nop

    func_808009CC_chlakemonster(rdram, ctx);
        goto after_57;
    // 0x80801170: nop

    after_57:
    // 0x80801174: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
L_80801178:
    // 0x80801178: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8080117C: sll         $t3, $t0, 19
    ctx->r11 = S32(ctx->r8 << 19);
    // 0x80801180: bgezl       $t3, L_808011E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80801184: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_14;
    // 0x80801184: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_14:
    // 0x80801188: lbu         $t5, 0x3D($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X3D);
    // 0x8080118C: beql        $t5, $zero, L_808011E0
    if (ctx->r13 == 0) {
        // 0x80801190: lw          $t4, 0x94($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X94);
            goto L_808011E0;
    }
    goto skip_15;
    // 0x80801190: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    skip_15:
    // 0x80801194: jal         0x800907C0
    // 0x80801198: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800907C0(rdram, ctx);
        goto after_58;
    // 0x80801198: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_58:
    // 0x8080119C: b           L_808011E0
    // 0x808011A0: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
        goto L_808011E0;
    // 0x808011A0: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_808011A4:
    // 0x808011A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1748, 0X20D4) << 16);
    // 0x808011A8: addiu       $a0, $a0, 0x20D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1748, 0X20D4));
    // 0x808011AC: jal         0x8010CB84
    // 0x808011B0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8010CB84(rdram, ctx);
        goto after_59;
    // 0x808011B0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_59:
    // 0x808011B4: bne         $v0, $zero, L_808011DC
    if (ctx->r2 != 0) {
        // 0x808011B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011DC;
    }
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011BC: jal         0x80801494
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_60;
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
    // 0x808011C4: b           L_808011E0
    // 0x808011C8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
        goto L_808011E0;
    // 0x808011C8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_808011CC:
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808011D4: jal         0x80800A14
    // 0x808011D8: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    func_80800A14_chlakemonster(rdram, ctx);
        goto after_61;
    // 0x808011D8: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    after_61:
L_808011DC:
    // 0x808011DC: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
L_808011E0:
    // 0x808011E0: beql        $t4, $zero, L_808013D8
    if (ctx->r12 == 0) {
        // 0x808011E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808013D8;
    }
    goto skip_16;
    // 0x808011E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x808011E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808011EC: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x808011F0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808011F4: nop

    // 0x808011F8: bc1fl       L_8080121C
    if (!c1cs) {
        // 0x808011FC: lw          $t8, 0x94($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X94);
            goto L_8080121C;
    }
    goto skip_17;
    // 0x808011FC: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    skip_17:
    // 0x80801200: jal         0x800D8FF8
    // 0x80801204: nop

    func_800D8FF8(rdram, ctx);
        goto after_62;
    // 0x80801204: nop

    after_62:
    // 0x80801208: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x8080120C: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80801210: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80801214: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80801218: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8080121C:
    // 0x8080121C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801220: lwc1        $f16, 0x28($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X28);
    // 0x80801224: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80801228: nop

    // 0x8080122C: bc1fl       L_80801250
    if (!c1cs) {
        // 0x80801230: lw          $t7, 0x7C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X7C);
            goto L_80801250;
    }
    goto skip_18;
    // 0x80801230: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    skip_18:
    // 0x80801234: jal         0x800D8FF8
    // 0x80801238: nop

    func_800D8FF8(rdram, ctx);
        goto after_63;
    // 0x80801238: nop

    after_63:
    // 0x8080123C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80801240: lwc1        $f18, 0x28($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80801244: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80801248: swc1        $f4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f4.u32l;
    // 0x8080124C: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
L_80801250:
    // 0x80801250: sll         $t0, $t7, 19
    ctx->r8 = S32(ctx->r15 << 19);
    // 0x80801254: bgezl       $t0, L_808013D8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801258: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808013D8;
    }
    goto skip_19;
    // 0x80801258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x8080125C: jal         0x800D8FF8
    // 0x80801260: nop

    func_800D8FF8(rdram, ctx);
        goto after_64;
    // 0x80801260: nop

    after_64:
    // 0x80801264: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801268: jal         0x80101F24
    // 0x8080126C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_65;
    // 0x8080126C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80801270: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80801274: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801278: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080127C: lwc1        $f8, 0x24($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X24);
    // 0x80801280: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80801284: nop

    // 0x80801288: bc1fl       L_808013D8
    if (!c1cs) {
        // 0x8080128C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808013D8;
    }
    goto skip_20;
    // 0x8080128C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_20:
    // 0x80801290: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801294: lwc1        $f16, 0x28($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080129C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x808012A0: nop

    // 0x808012A4: bc1fl       L_808013D8
    if (!c1cs) {
        // 0x808012A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808013D8;
    }
    goto skip_21;
    // 0x808012A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_21:
    // 0x808012AC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x808012B0: jal         0x801022E4
    // 0x808012B4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_801022E4(rdram, ctx);
        goto after_66;
    // 0x808012B4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_66:
    // 0x808012B8: addiu       $at, $zero, 0x169
    ctx->r1 = ADD32(0, 0X169);
    // 0x808012BC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808012C0: beq         $v0, $at, L_808012E4
    if (ctx->r2 == ctx->r1) {
        // 0x808012C4: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_808012E4;
    }
    // 0x808012C4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808012C8: addiu       $at, $zero, 0x1FD
    ctx->r1 = ADD32(0, 0X1FD);
    // 0x808012CC: beq         $v0, $at, L_8080131C
    if (ctx->r2 == ctx->r1) {
        // 0x808012D0: addiu       $at, $zero, 0x1FE
        ctx->r1 = ADD32(0, 0X1FE);
            goto L_8080131C;
    }
    // 0x808012D0: addiu       $at, $zero, 0x1FE
    ctx->r1 = ADD32(0, 0X1FE);
    // 0x808012D4: beql        $v0, $at, L_80801320
    if (ctx->r2 == ctx->r1) {
        // 0x808012D8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80801320;
    }
    goto skip_22;
    // 0x808012D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_22:
    // 0x808012DC: b           L_80801320
    // 0x808012E0: nop

        goto L_80801320;
    // 0x808012E0: nop

L_808012E4:
    // 0x808012E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F90) << 16);
    // 0x808012E8: lwc1        $f18, 0x1F90($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F90));
    // 0x808012EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F94) << 16);
    // 0x808012F0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x808012F4: nop

    // 0x808012F8: bc1t        L_80801314
    if (c1cs) {
        // 0x808012FC: nop
    
            goto L_80801314;
    }
    // 0x808012FC: nop

    // 0x80801300: lwc1        $f4, 0x1F94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F94));
    // 0x80801304: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80801308: nop

    // 0x8080130C: bc1f        L_80801320
    if (!c1cs) {
        // 0x80801310: nop
    
            goto L_80801320;
    }
    // 0x80801310: nop

L_80801314:
    // 0x80801314: b           L_80801320
    // 0x80801318: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x80801318: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080131C:
    // 0x8080131C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801320:
    // 0x80801320: beq         $v1, $zero, L_808013D4
    if (ctx->r3 == 0) {
        // 0x80801324: lw          $t3, 0x94($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X94);
            goto L_808013D4;
    }
    // 0x80801324: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80801328: lwc1        $f0, 0x18($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8080132C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801330: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801334: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801338: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080133C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80801340: bc1fl       L_80801358
    if (!c1cs) {
        // 0x80801344: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80801358;
    }
    goto skip_23;
    // 0x80801344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_23:
    // 0x80801348: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8080134C: b           L_808013D4
    // 0x80801350: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
        goto L_808013D4;
    // 0x80801350: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
    // 0x80801354: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80801358:
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801360: swc1        $f16, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f16.u32l;
    // 0x80801364: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80801368: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X20A4) << 16);
    // 0x8080136C: sll         $t8, $t5, 12
    ctx->r24 = S32(ctx->r13 << 12);
    // 0x80801370: bgez        $t8, L_808013C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801374: nop
    
            goto L_808013C0;
    }
    // 0x80801374: nop

    // 0x80801378: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X208C) << 16);
    // 0x8080137C: addiu       $a2, $a2, 0x208C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X208C));
    // 0x80801380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801384: jal         0x80089D18
    // 0x80801388: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_67;
    // 0x80801388: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_67:
    // 0x8080138C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80801390: beq         $t6, $zero, L_808013A8
    if (ctx->r14 == 0) {
        // 0x80801394: nop
    
            goto L_808013A8;
    }
    // 0x80801394: nop

    // 0x80801398: jal         0x808002FC
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002FC_chlakemonster(rdram, ctx);
        goto after_68;
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x808013A0: b           L_808013B4
    // 0x808013A4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
        goto L_808013B4;
    // 0x808013A4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_808013A8:
    // 0x808013A8: jal         0x80800404
    // 0x808013AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800404_chlakemonster(rdram, ctx);
        goto after_69;
    // 0x808013AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x808013B0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_808013B4:
    // 0x808013B4: andi        $t9, $t7, 0xFFF7
    ctx->r25 = ctx->r15 & 0XFFF7;
    // 0x808013B8: b           L_808013D4
    // 0x808013BC: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_808013D4;
    // 0x808013BC: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_808013C0:
    // 0x808013C0: jal         0x80089D18
    // 0x808013C4: addiu       $a2, $a2, 0x20A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X20A4));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_70;
    // 0x808013C4: addiu       $a2, $a2, 0x20A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X20A4));
    after_70:
    // 0x808013C8: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808013CC: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x808013D0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808013D4:
    // 0x808013D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013D8:
    // 0x808013D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808013DC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x808013E0: jr          $ra
    // 0x808013E4: nop

    return;
    // 0x808013E4: nop

;}
RECOMP_FUNC void func_80800294_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x808002A0: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x808002A4: beq         $t6, $zero, L_808002CC
    if (ctx->r14 == 0) {
        // 0x808002A8: sll         $t8, $v0, 5
        ctx->r24 = S32(ctx->r2 << 5);
            goto L_808002CC;
    }
    // 0x808002A8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x808002AC: bltz        $t8, L_808002CC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808002B0: nop
    
            goto L_808002CC;
    }
    // 0x808002B0: nop

    // 0x808002B4: lh          $t9, 0x1B0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1B0);
    // 0x808002B8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808002BC: nop

    // 0x808002C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002C4: b           L_808002D4
    // 0x808002C8: swc1        $f6, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f6.u32l;
        goto L_808002D4;
    // 0x808002C8: swc1        $f6, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f6.u32l;
L_808002CC:
    // 0x808002CC: jal         0x80800228
    // 0x808002D0: nop

    func_80800228_gczoombox(rdram, ctx);
        goto after_0;
    // 0x808002D0: nop

    after_0:
L_808002D4:
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void bavan_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800140: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800144: jal         0x800F0DC0
    // 0x80800148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F0DC0(rdram, ctx);
        goto after_0;
    // 0x80800148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080014C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80800154: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080003C: jal         0x8001B668
    // 0x80800040: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_0:
    // 0x80800044: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80800048: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080004C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80800050: jal         0x808000F0
    // 0x80800054: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    ncpodfixpos_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800058: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080005C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80800060: jal         0x800EFD24
    // 0x80800064: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    after_2:
    // 0x80800068: jal         0x800EFD24
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800070: jal         0x800EFD24
    // 0x80800074: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800074: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_4:
    // 0x80800078: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080007C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800080: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800084: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800088: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8080008C: sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // 0x80800090: sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    // 0x80800094: sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // 0x80800098: sb          $zero, 0x41($s0)
    MEM_B(0X41, ctx->r16) = 0;
    // 0x8080009C: sb          $zero, 0x42($s0)
    MEM_B(0X42, ctx->r16) = 0;
    // 0x808000A0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x808000A4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x808000A8: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x808000AC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x808000B0: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bstimeout_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: jal         0x800951B4
    // 0x80800194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800951B4(rdram, ctx);
        goto after_0;
    // 0x80800194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800198: jal         0x800A4E30
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void chlavatraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1864, 0XF0) << 16);
    // 0x808000D4: jr          $ra
    // 0x808000D8: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1864, 0XF0));
    return;
    // 0x808000D8: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1864, 0XF0));
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_80015828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015828: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001582C: addiu       $a0, $a0, -0x6888
    ctx->r4 = ADD32(ctx->r4, -0X6888);
    // 0x80015830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80015834: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80015838:
    // 0x80015838: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8001583C: beql        $t6, $zero, L_80015854
    if (ctx->r14 == 0) {
        // 0x80015840: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80015854;
    }
    goto skip_0;
    // 0x80015840: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x80015844: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80015848: bne         $v1, $v0, L_80015838
    if (ctx->r3 != ctx->r2) {
        // 0x8001584C: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80015838;
    }
    // 0x8001584C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80015850: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80015854:
    // 0x80015854: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80015858: jr          $ra
    // 0x8001585C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001585C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void chlinkpipefan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2248, 0X9C8) << 16);
    // 0x808008DC: jr          $ra
    // 0x808008E0: addiu       $v0, $v0, 0x9C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2248, 0X9C8));
    return;
    // 0x808008E0: addiu       $v0, $v0, 0x9C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2248, 0X9C8));
    // 0x808008E4: nop

    // 0x808008E8: nop

    // 0x808008EC: nop

;}
RECOMP_FUNC void _gcnewpause_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088208: syscall     675
    recomp_syscall_handler(rdram, ctx, 0x80088208);
    return;
    // 0x8008820C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bashoessuck_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080020C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800210: jal         0x800961AC
    // 0x80800214: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800961AC(rdram, ctx);
        goto after_0;
    // 0x80800214: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_8080037C_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800380: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080038C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800390: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800394: jal         0x80098140
    // 0x80800398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080039C: lui         $a1, 0x3E9E
    ctx->r5 = S32(0X3E9E << 16);
    // 0x808003A0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    // 0x808003A4: jal         0x8008CB10
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003AC: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808003B8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808003BC: jal         0x8009DBF0
    // 0x808003C0: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DBF0(rdram, ctx);
        goto after_2;
    // 0x808003C0: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_2:
L_808003C4:
    // 0x808003C4: lui         $a1, 0x3E4A
    ctx->r5 = S32(0X3E4A << 16);
    // 0x808003C8: ori         $a1, $a1, 0x57A8
    ctx->r5 = ctx->r5 | 0X57A8;
    // 0x808003CC: jal         0x8008CB10
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003D4: beq         $v0, $zero, L_808003E8
    if (ctx->r2 == 0) {
        // 0x808003D8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808003E8;
    }
    // 0x808003D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003DC: sb          $t6, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r14;
    // 0x808003E0: jal         0x8080021C
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_4;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808003E8:
    // 0x808003E8: jal         0x8008CAEC
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003F0: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x808003F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800400;
    }
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: addiu       $t7, $zero, 0x16C
    ctx->r15 = ADD32(0, 0X16C);
    // 0x808003FC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800400:
    // 0x80800400: jal         0x8009E5C8
    // 0x80800404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080040C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800410: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void func_8080042C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800430: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800438: jal         0x80800114
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800114_bstntswim(rdram, ctx);
        goto after_0;
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80800448: jal         0x8008CB3C
    // 0x8080044C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080044C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_1:
    // 0x80800450: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800454: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800460: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800464: jal         0x8009FFD8
    // 0x80800468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800468: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800474: jal         0x8009C99C
    // 0x80800478: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800478: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x8009B9B0
    // 0x80800484: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800484: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800494: jr          $ra
    // 0x80800498: nop

    return;
    // 0x80800498: nop

;}
RECOMP_FUNC void _bsdronexform_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831B0: syscall     50
    recomp_syscall_handler(rdram, ctx, 0x800831B0);
    return;
    // 0x800831B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void anseq_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002FC: jal         0x8001B798
    // 0x80800300: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800300: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x80800304: jal         0x800B2D48
    // 0x80800308: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_800B2D48(rdram, ctx);
        goto after_1;
    // 0x80800308: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x8080030C: jal         0x8001B754
    // 0x80800310: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x80800310: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_2:
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void func_800E93AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E93AC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800E93B0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800E93B4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800E93B8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E93BC: addiu       $t8, $t8, -0x2970
    ctx->r24 = ADD32(ctx->r24, -0X2970);
    // 0x800E93C0: addiu       $t7, $t6, 0x4658
    ctx->r15 = ADD32(ctx->r14, 0X4658);
    // 0x800E93C4: jr          $ra
    // 0x800E93C8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800E93C8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_8080000C_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80100094
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: jal         0x8008A020
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void _bamum_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F20: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F20);
    return;
    // 0x80084F24: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800810_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800810: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080081C: jal         0x8008CABC
    // 0x80800820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800824: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800828: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080082C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80800830: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800834: jal         0x8008B348
    // 0x80800838: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800838: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080083C: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x80800840: lui         $a2, 0x3F8C
        ctx->r6 = S32(0X3F8C << 16);
            goto L_80800854;
    }
    // 0x80800840: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800844: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: jal         0x8009DE38
    // 0x80800850: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    func_8009DE38(rdram, ctx);
        goto after_2;
    // 0x80800850: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    after_2:
L_80800854:
    // 0x80800854: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800858: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080085C: jal         0x8008B348
    // 0x80800860: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800860: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800864: beq         $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800868: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_8080087C;
    }
    // 0x80800868: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080086C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x8009DBF0
    // 0x80800878: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DBF0(rdram, ctx);
        goto after_4;
    // 0x80800878: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_4:
L_8080087C:
    // 0x8080087C: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x80800880: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800884: jal         0x8008B348
    // 0x80800888: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800888: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8080088C: beql        $v0, $zero, L_808008A0
    if (ctx->r2 == 0) {
        // 0x80800890: lui         $a1, 0x3F45
        ctx->r5 = S32(0X3F45 << 16);
            goto L_808008A0;
    }
    goto skip_0;
    // 0x80800890: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    skip_0:
    // 0x80800894: jal         0x8009FE58
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_6;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080089C: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
L_808008A0:
    // 0x808008A0: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x808008A4: jal         0x8008B348
    // 0x808008A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808008A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808008AC: beq         $v0, $zero, L_808008C4
    if (ctx->r2 == 0) {
        // 0x808008B0: lui         $a2, 0x3F8C
        ctx->r6 = S32(0X3F8C << 16);
            goto L_808008C4;
    }
    // 0x808008B0: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x808008B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: jal         0x8009DE38
    // 0x808008C0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DE38(rdram, ctx);
        goto after_8;
    // 0x808008C0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_8:
L_808008C4:
    // 0x808008C4: jal         0x8008B2B4
    // 0x808008C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_9;
    // 0x808008C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x808008CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DB4) << 16);
    // 0x808008D0: lwc1        $f4, 0x1DB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DB4));
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808008DC: nop

    // 0x808008E0: bc1f        L_808008F8
    if (!c1cs) {
        // 0x808008E4: nop
    
            goto L_808008F8;
    }
    // 0x808008E4: nop

    // 0x808008E8: jal         0x808001D4
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_10;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808008F0: b           L_80800904
    // 0x808008F4: lui         $a1, 0x3F3B
    ctx->r5 = S32(0X3F3B << 16);
        goto L_80800904;
    // 0x808008F4: lui         $a1, 0x3F3B
    ctx->r5 = S32(0X3F3B << 16);
L_808008F8:
    // 0x808008F8: jal         0x8009B9B0
    // 0x808008FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808008FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800900: lui         $a1, 0x3F3B
    ctx->r5 = S32(0X3F3B << 16);
L_80800904:
    // 0x80800904: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x80800908: jal         0x8008B348
    // 0x8080090C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x8080090C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800910: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080092C;
    }
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x80084538
    // 0x8080091C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_13;
    // 0x8080091C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800924: jal         0x800A0CD0
    // 0x80800928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_14;
    // 0x80800928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_8080092C:
    // 0x8080092C: jal         0x8008CAEC
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_15;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800934: beq         $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800938: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800940;
    }
    // 0x80800938: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080093C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80800940:
    // 0x80800940: jal         0x8008B2B4
    // 0x80800944: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_16;
    // 0x80800944: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80800948: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DB8) << 16);
    // 0x8080094C: lwc1        $f6, 0x1DB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DB8));
    // 0x80800950: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800954: nop

    // 0x80800958: bc1f        L_80800974
    if (!c1cs) {
        // 0x8080095C: nop
    
            goto L_80800974;
    }
    // 0x8080095C: nop

    // 0x80800960: jal         0x8009EF10
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_17;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800968: blez        $v0, L_80800974
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080096C: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_80800974;
    }
    // 0x8080096C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80800970: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80800974:
    // 0x80800974: jal         0x8008B2B4
    // 0x80800978: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_18;
    // 0x80800978: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x8080097C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DBC) << 16);
    // 0x80800980: lwc1        $f8, 0x1DBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DBC));
    // 0x80800984: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800988: nop

    // 0x8080098C: bc1fl       L_808009E4
    if (!c1cs) {
        // 0x80800990: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    goto skip_1;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800994: jal         0x8008E35C
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_19;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080099C: beql        $v0, $zero, L_808009E4
    if (ctx->r2 == 0) {
        // 0x808009A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    goto skip_2;
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808009A4: jal         0x800964DC
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_20;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808009AC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808009B0: jal         0x80096364
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_21;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808009B8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808009BC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808009C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009C4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x808009C8: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x808009CC: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x808009D0: nop

    // 0x808009D4: bc1fl       L_808009E4
    if (!c1cs) {
        // 0x808009D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    goto skip_3;
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808009DC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E4:
    // 0x808009E4: jal         0x8009E5C8
    // 0x808009E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x808009E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_22:
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009F8: jr          $ra
    // 0x808009FC: nop

    return;
    // 0x808009FC: nop

;}
RECOMP_FUNC void _bawobble_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085480: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085480);
    return;
    // 0x80085484: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80096728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009672C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096730: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096734: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80096738: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8009673C: beq         $a1, $zero, L_80096758
    if (ctx->r5 == 0) {
        // 0x80096740: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80096758;
    }
    // 0x80096740: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80096744: jal         0x800C5BC4
    // 0x80096748: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C5BC4(rdram, ctx);
        goto after_0;
    // 0x80096748: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009674C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80096750: lw          $t7, 0x94($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X94);
    // 0x80096754: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_80096758:
    // 0x80096758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009675C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096760: jr          $ra
    // 0x80096764: nop

    return;
    // 0x80096764: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14A0) << 16);
    // 0x80800C24: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C28: jr          $ra
    // 0x80800C2C: lw          $v0, 0x14A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14A0));
    return;
    // 0x80800C2C: lw          $v0, 0x14A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14A0));
;}
RECOMP_FUNC void func_800E6A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6A90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E6A94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E6A98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E6A9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E6AA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E6AA4: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x800E6AA8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800E6AAC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E6AB0: beq         $a2, $zero, L_800E6AE4
    if (ctx->r6 == 0) {
        // 0x800E6AB4: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800E6AE4;
    }
    // 0x800E6AB4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800E6AB8: addiu       $s2, $s2, 0x5DC0
    ctx->r18 = ADD32(ctx->r18, 0X5DC0);
    // 0x800E6ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E6AC0:
    // 0x800E6AC0: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x800E6AC4: jal         0x800E6AFC
    // 0x800E6AC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800E6AFC(rdram, ctx);
        goto after_0;
    // 0x800E6AC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x800E6ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6AD0: jal         0x800E6A10
    // 0x800E6AD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E6A10(rdram, ctx);
        goto after_1;
    // 0x800E6AD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800E6AD8: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x800E6ADC: bnel        $a2, $zero, L_800E6AC0
    if (ctx->r6 != 0) {
        // 0x800E6AE0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E6AC0;
    }
    goto skip_0;
    // 0x800E6AE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_800E6AE4:
    // 0x800E6AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E6AE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E6AEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E6AF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E6AF4: jr          $ra
    // 0x800E6AF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E6AF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void boot_osSetIntMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8080015C_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800160: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080016C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80800170: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80800174: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80800178: jal         0x801022E4
    // 0x8080017C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x8080017C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    after_0:
    // 0x80800180: addiu       $at, $zero, 0x4A5
    ctx->r1 = ADD32(0, 0X4A5);
    // 0x80800184: beq         $v0, $at, L_808001AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800188: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001AC;
    }
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $at, $zero, 0x4A6
    ctx->r1 = ADD32(0, 0X4A6);
    // 0x80800190: beq         $v0, $at, L_808002B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B4;
    }
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $at, $zero, 0x4A7
    ctx->r1 = ADD32(0, 0X4A7);
    // 0x8080019C: beq         $v0, $at, L_80800230
    if (ctx->r2 == ctx->r1) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800230;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: b           L_80800378
    // 0x808001A8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
        goto L_80800378;
    // 0x808001A8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
L_808001AC:
    // 0x808001AC: jal         0x80101E14
    // 0x808001B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x808001B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808001B4: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001B8: bne         $a2, $zero, L_808001D0
    if (ctx->r6 != 0) {
        // 0x808001BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D0;
    }
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808001C4: jal         0x80101E14
    // 0x808001C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808001C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_2:
    // 0x808001CC: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
L_808001D0:
    // 0x808001D0: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808001D4: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x808001D8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808001DC: jal         0x80101E14
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001E4: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808001E8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x808001EC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808001F0: jal         0x80101E14
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001F8: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001FC: bne         $v1, $zero, L_80800228
    if (ctx->r3 != 0) {
        // 0x80800200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800228;
    }
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80101E14
    // 0x80800208: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800208: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x8080020C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800210: bne         $v1, $zero, L_80800228
    if (ctx->r3 != 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800228;
    }
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: lui         $a1, 0x3F0F
    ctx->r5 = S32(0X3F0F << 16);
    // 0x8080021C: jal         0x80101E14
    // 0x80800220: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_6;
    // 0x80800220: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_6:
    // 0x80800224: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800228:
    // 0x80800228: b           L_80800374
    // 0x8080022C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
        goto L_80800374;
    // 0x8080022C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
L_80800230:
    // 0x80800230: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800234: jal         0x80101E14
    // 0x80800238: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80800238: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_7:
    // 0x8080023C: sltu        $a3, $zero, $v0
    ctx->r7 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800240: bne         $a3, $zero, L_80800258
    if (ctx->r7 != 0) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x8080024C: jal         0x80101E14
    // 0x80800250: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800250: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_8:
    // 0x80800254: sltu        $a3, $zero, $v0
    ctx->r7 = 0 < ctx->r2 ? 1 : 0;
L_80800258:
    // 0x80800258: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x80101E14
    // 0x80800264: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x80800264: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x80800268: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x8080026C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080028C;
    }
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800278: jal         0x8008A0D0
    // 0x8080027C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x8080027C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_10:
    // 0x80800280: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800284: b           L_80800374
    // 0x80800288: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
        goto L_80800374;
    // 0x80800288: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
L_8080028C:
    // 0x8080028C: jal         0x80101E14
    // 0x80800290: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800290: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_11:
    // 0x80800294: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x80800298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800374;
    }
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x808002A0: jal         0x8008A0D0
    // 0x808002A4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808002A4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_12:
    // 0x808002A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808002AC: b           L_80800374
    // 0x808002B0: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
        goto L_80800374;
    // 0x808002B0: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_808002B4:
    // 0x808002B4: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x808002B8: jal         0x80101E14
    // 0x808002BC: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x808002BC: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_13:
    // 0x808002C0: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x808002C4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808002C8: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x808002CC: jal         0x80101E14
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002D4: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x808002D8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x808002DC: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x808002E0: jal         0x80101E14
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808002E8: sltu        $a3, $zero, $v0
    ctx->r7 = 0 < ctx->r2 ? 1 : 0;
    // 0x808002EC: bne         $a3, $zero, L_8080031C
    if (ctx->r7 != 0) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: lui         $a1, 0x3F0A
    ctx->r5 = S32(0X3F0A << 16);
    // 0x808002F8: jal         0x80101E14
    // 0x808002FC: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x808002FC: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    after_16:
    // 0x80800300: sltu        $a3, $zero, $v0
    ctx->r7 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800304: bne         $a3, $zero, L_8080031C
    if (ctx->r7 != 0) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800310: jal         0x80101E14
    // 0x80800314: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80800314: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_17:
    // 0x80800318: sltu        $a3, $zero, $v0
    ctx->r7 = 0 < ctx->r2 ? 1 : 0;
L_8080031C:
    // 0x8080031C: lui         $a1, 0x3D0F
    ctx->r5 = S32(0X3D0F << 16);
    // 0x80800320: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80800324: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x80800328: jal         0x80101E14
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_18;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800330: beq         $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8080033C: jal         0x800EE7F8
    // 0x80800340: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x80800340: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_19:
    // 0x80800344: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800348: b           L_80800374
    // 0x8080034C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
        goto L_80800374;
    // 0x8080034C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
L_80800350:
    // 0x80800350: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80800354: jal         0x80101E14
    // 0x80800358: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80800358: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_20:
    // 0x8080035C: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x80800360: addiu       $a0, $sp, 0x6C
        ctx->r4 = ADD32(ctx->r29, 0X6C);
            goto L_80800374;
    }
    // 0x80800360: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800364: jal         0x800EE7F8
    // 0x80800368: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80800368: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x8080036C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800370: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
L_80800374:
    // 0x80800374: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
L_80800378:
    // 0x80800378: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080037C: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800380: beq         $t0, $zero, L_80800618
    if (ctx->r8 == 0) {
        // 0x80800384: nop
    
            goto L_80800618;
    }
    // 0x80800384: nop

    // 0x80800388: jal         0x800B53A4
    // 0x8080038C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_800B53A4(rdram, ctx);
        goto after_22;
    // 0x8080038C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_22:
    // 0x80800390: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80800394: jal         0x800B53A4
    // 0x80800398: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B53A4(rdram, ctx);
        goto after_23;
    // 0x80800398: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_23:
    // 0x8080039C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808003A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003A8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808003AC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808003B0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x808003B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808003B8: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x808003BC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808003C0: jal         0x800EEC30
    // 0x808003C4: nop

    func_800EEC30(rdram, ctx);
        goto after_24;
    // 0x808003C4: nop

    after_24:
    // 0x808003C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003D0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808003D4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003D8: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x808003DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808003E0: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x808003E4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808003E8: jal         0x800EEC30
    // 0x808003EC: nop

    func_800EEC30(rdram, ctx);
        goto after_25;
    // 0x808003EC: nop

    after_25:
    // 0x808003F0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808003F4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808003F8: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808003FC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800400: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800404: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800408: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080040C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800410: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800414: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800418: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080041C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800420: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800424: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800428: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8080042C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800430: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800434: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80800438: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080043C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80800440: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80800444: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80800448: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8080044C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800450: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800454: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800458: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080045C: jal         0x800BA930
    // 0x80800460: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800BA930(rdram, ctx);
        goto after_26;
    // 0x80800460: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_26:
    // 0x80800464: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800468: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080046C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800470: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800474: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800478: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080047C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800480: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800484: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800488: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080048C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800490: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800494: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800498: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080049C: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x808004A0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808004A4: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808004A8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x808004AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004B0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808004B4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x808004B8: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x808004BC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x808004C0: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x808004C4: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808004C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808004CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808004D0: jal         0x800BA930
    // 0x808004D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800BA930(rdram, ctx);
        goto after_27;
    // 0x808004D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_27:
    // 0x808004D8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808004DC: jal         0x800EF334
    // 0x808004E0: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_800EF334(rdram, ctx);
        goto after_28;
    // 0x808004E0: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_28:
    // 0x808004E4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808004E8: jal         0x800EF334
    // 0x808004EC: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_800EF334(rdram, ctx);
        goto after_29;
    // 0x808004EC: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_29:
    // 0x808004F0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808004F4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808004F8: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800500: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800504: addiu       $t0, $zero, -0x190
    ctx->r8 = ADD32(0, -0X190);
    // 0x80800508: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080050C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800510: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800514: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800518: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080051C: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80800520: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800524: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80800528: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8080052C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800530: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80800534: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800538: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080053C: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x80800540: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800544: jal         0x800BA450
    // 0x80800548: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_800BA450(rdram, ctx);
        goto after_30;
    // 0x80800548: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_30:
    // 0x8080054C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800550: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800554: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800558: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080055C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800560: addiu       $t1, $zero, -0x190
    ctx->r9 = ADD32(0, -0X190);
    // 0x80800564: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800568: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080056C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800570: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800574: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800578: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x8080057C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800580: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80800584: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80800588: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080058C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800590: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800594: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800598: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x8080059C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808005A0: jal         0x800BA450
    // 0x808005A4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_800BA450(rdram, ctx);
        goto after_31;
    // 0x808005A4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_31:
    // 0x808005A8: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2456, 0X1E38) << 16);
    // 0x808005AC: addiu       $t4, $t4, 0x1E38
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2456, 0X1E38));
    // 0x808005B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808005B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005B8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808005BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005C0: jal         0x800BABB8
    // 0x808005C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_32;
    // 0x808005C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_32:
    // 0x808005C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005CC: jal         0x800BA22C
    // 0x808005D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_33;
    // 0x808005D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x808005D4: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2456, 0X1E60) << 16);
    // 0x808005D8: addiu       $t5, $t5, 0x1E60
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2456, 0X1E60));
    // 0x808005DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808005E0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808005E4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808005E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005EC: jal         0x800BABB8
    // 0x808005F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_34;
    // 0x808005F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_34:
    // 0x808005F4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808005F8: jal         0x800BA22C
    // 0x808005FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_35;
    // 0x808005FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_35:
    // 0x80800600: lui         $a0, 0xA62F
    ctx->r4 = S32(0XA62F << 16);
    // 0x80800604: lui         $a2, 0xFA0
    ctx->r6 = S32(0XFA0 << 16);
    // 0x80800608: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    // 0x8080060C: ori         $a0, $a0, 0xA404
    ctx->r4 = ctx->r4 | 0XA404;
    // 0x80800610: jal         0x800C4140
    // 0x80800614: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C4140(rdram, ctx);
        goto after_36;
    // 0x80800614: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_36:
L_80800618:
    // 0x80800618: jal         0x800C0638
    // 0x8080061C: nop

    func_800C0638(rdram, ctx);
        goto after_37;
    // 0x8080061C: nop

    after_37:
    // 0x80800620: bne         $v0, $zero, L_808006B0
    if (ctx->r2 != 0) {
        // 0x80800624: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_808006B0;
    }
    // 0x80800624: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80800628: beq         $t6, $zero, L_80800670
    if (ctx->r14 == 0) {
        // 0x8080062C: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_80800670;
    }
    // 0x8080062C: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800630: jal         0x800DC0C0
    // 0x80800634: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_800DC0C0(rdram, ctx);
        goto after_38;
    // 0x80800634: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_38:
    // 0x80800638: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080063C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800640: lui         $at, 0x7FEB
    ctx->r1 = S32(0X7FEB << 16);
    // 0x80800644: lui         $a2, 0xFA0
    ctx->r6 = S32(0XFA0 << 16);
    // 0x80800648: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080064C: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    // 0x80800650: ori         $at, $at, 0xB800
    ctx->r1 = ctx->r1 | 0XB800;
    // 0x80800654: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800658: bc1f        L_80800668
    if (!c1cs) {
        // 0x8080065C: addiu       $a3, $zero, 0x675
        ctx->r7 = ADD32(0, 0X675);
            goto L_80800668;
    }
    // 0x8080065C: addiu       $a3, $zero, 0x675
    ctx->r7 = ADD32(0, 0X675);
    // 0x80800660: b           L_80800668
    // 0x80800664: addiu       $a3, $zero, 0x674
    ctx->r7 = ADD32(0, 0X674);
        goto L_80800668;
    // 0x80800664: addiu       $a3, $zero, 0x674
    ctx->r7 = ADD32(0, 0X674);
L_80800668:
    // 0x80800668: jal         0x800C4140
    // 0x8080066C: addu        $a0, $a3, $at
    ctx->r4 = ADD32(ctx->r7, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_39;
    // 0x8080066C: addu        $a0, $a3, $at
    ctx->r4 = ADD32(ctx->r7, ctx->r1);
    after_39:
L_80800670:
    // 0x80800670: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80800674: lui         $a0, 0x7FEB
    ctx->r4 = S32(0X7FEB << 16);
    // 0x80800678: ori         $a0, $a0, 0xBE76
    ctx->r4 = ctx->r4 | 0XBE76;
    // 0x8080067C: beq         $t8, $zero, L_80800690
    if (ctx->r24 == 0) {
        // 0x80800680: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800690;
    }
    // 0x80800680: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800684: lui         $a2, 0xFA0
    ctx->r6 = S32(0XFA0 << 16);
    // 0x80800688: jal         0x800C4140
    // 0x8080068C: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    func_800C4140(rdram, ctx);
        goto after_40;
    // 0x8080068C: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    after_40:
L_80800690:
    // 0x80800690: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80800694: lui         $a0, 0x7FEB
    ctx->r4 = S32(0X7FEB << 16);
    // 0x80800698: ori         $a0, $a0, 0xBE77
    ctx->r4 = ctx->r4 | 0XBE77;
    // 0x8080069C: beq         $t9, $zero, L_808006B0
    if (ctx->r25 == 0) {
        // 0x808006A0: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808006B0;
    }
    // 0x808006A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808006A4: lui         $a2, 0xFA0
    ctx->r6 = S32(0XFA0 << 16);
    // 0x808006A8: jal         0x800C4140
    // 0x808006AC: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    func_800C4140(rdram, ctx);
        goto after_41;
    // 0x808006AC: ori         $a2, $a2, 0x64
    ctx->r6 = ctx->r6 | 0X64;
    after_41:
L_808006B0:
    // 0x808006B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808006B8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_8080026C_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800270: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080027C: beq         $a1, $at, L_808002A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800280: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808002A4;
    }
    // 0x80800280: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800284: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800288: beq         $a1, $at, L_808002C8
    if (ctx->r5 == ctx->r1) {
        // 0x8080028C: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_808002C8;
    }
    // 0x8080028C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800294: beq         $a1, $at, L_80800308
    if (ctx->r5 == ctx->r1) {
        // 0x80800298: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_80800308;
    }
    // 0x80800298: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: b           L_80800344
    // 0x808002A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x808002A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A4:
    // 0x808002A4: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    // 0x808002A8: jal         0x801084B0
    // 0x808002AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808002AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808002B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B8: jal         0x80102FDC
    // 0x808002BC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x808002BC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_1:
    // 0x808002C0: b           L_80800344
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C8:
    // 0x808002C8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808002CC: jal         0x8010A570
    // 0x808002D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808002D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808002D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002DC: jal         0x80800748
    // 0x808002E0: addiu       $a2, $zero, 0x95D
    ctx->r6 = ADD32(0, 0X95D);
    func_80800748_chphlegm(rdram, ctx);
        goto after_3;
    // 0x808002E0: addiu       $a2, $zero, 0x95D
    ctx->r6 = ADD32(0, 0X95D);
    after_3:
    // 0x808002E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808002E8: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x808002EC: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x808002F0: beql        $t0, $zero, L_80800344
    if (ctx->r8 == 0) {
        // 0x808002F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800344;
    }
    goto skip_0;
    // 0x808002F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808002F8: jal         0x800FFAB0
    // 0x808002FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808002FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800300: b           L_80800344
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800308:
    // 0x80800308: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x8080030C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800314: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800318: bgez        $t4, L_80800328
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080031C: addiu       $v0, $zero, 0x876
        ctx->r2 = ADD32(0, 0X876);
            goto L_80800328;
    }
    // 0x8080031C: addiu       $v0, $zero, 0x876
    ctx->r2 = ADD32(0, 0X876);
    // 0x80800320: b           L_80800328
    // 0x80800324: addiu       $v0, $zero, 0x6DC
    ctx->r2 = ADD32(0, 0X6DC);
        goto L_80800328;
    // 0x80800324: addiu       $v0, $zero, 0x6DC
    ctx->r2 = ADD32(0, 0X6DC);
L_80800328:
    // 0x80800328: jal         0x80103140
    // 0x8080032C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    func_80103140(rdram, ctx);
        goto after_5;
    // 0x8080032C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_5:
    // 0x80800330: b           L_80800344
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800338: b           L_80800344
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800344:
    // 0x80800344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_808042FC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808042FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80804300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804304: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80804308: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080430C: jal         0x80100094
    // 0x80804310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804314: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80804318: beql        $t6, $zero, L_808043CC
    if (ctx->r14 == 0) {
        // 0x8080431C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808043CC;
    }
    goto skip_0;
    // 0x8080431C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804320: jal         0x800E8C58
    // 0x80804324: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    func_800E8C58(rdram, ctx);
        goto after_1;
    // 0x80804324: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    after_1:
    // 0x80804328: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8080432C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80804330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80804334: jal         0x800B27E0
    // 0x80804338: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_800B27E0(rdram, ctx);
        goto after_2;
    // 0x80804338: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8080433C: jal         0x80087A10
    // 0x80804340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80804340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80804344: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804348: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080434C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80804350: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80804354: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80804358: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8080435C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80804360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80804364: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80804368: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8080436C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80804370: jal         0x800E0C20
    // 0x80804374: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800E0C20(rdram, ctx);
        goto after_4;
    // 0x80804374: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80804378: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080437C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80804380: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80804384: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80804388: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8080438C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80804390: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80804394: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80804398: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080439C: jal         0x800E0C20
    // 0x808043A0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    func_800E0C20(rdram, ctx);
        goto after_5;
    // 0x808043A0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x808043A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808043A8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808043AC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808043B0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x808043B4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x808043B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808043BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808043C0: jal         0x800E0C20
    // 0x808043C4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    func_800E0C20(rdram, ctx);
        goto after_6;
    // 0x808043C4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x808043C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808043CC:
    // 0x808043CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808043D0: jr          $ra
    // 0x808043D4: nop

    return;
    // 0x808043D4: nop

;}
RECOMP_FUNC void func_800F5B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5B38: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5B40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5B48: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5B4C: jal         0x800F3E84
    // 0x800F5B50: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3E84(rdram, ctx);
        goto after_0;
    // 0x800F5B50: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5B5C: jr          $ra
    // 0x800F5B60: nop

    return;
    // 0x800F5B60: nop

;}
RECOMP_FUNC void _glsplinenode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884F0: syscall     690
    recomp_syscall_handler(rdram, ctx, 0x800884F0);
    return;
    // 0x800884F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801A80_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A88: jal         0x800F54E4
    // 0x80801A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A90: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A98: jal         0x800F5BF0
    // 0x80801A9C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800F5BF0(rdram, ctx);
        goto after_1;
    // 0x80801A9C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_1:
    // 0x80801AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AA8: jr          $ra
    // 0x80801AAC: nop

    return;
    // 0x80801AAC: nop

;}
RECOMP_FUNC void func_80800124_chfactorylinkgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800130: jal         0x80085808
    // 0x80800134: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800134: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    after_0:
    // 0x80800138: jal         0x80085818
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_8009DF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DF18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DF1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DF20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009DF24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009DF28: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DF2C: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DF30: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DF34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009DF38: lbu         $a1, 0x2($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2);
    // 0x8009DF3C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8009DF40: jal         0x8009DCCC
    // 0x8009DF44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8009DCCC(rdram, ctx);
        goto after_0;
    // 0x8009DF44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8009DF48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DF4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DF50: jr          $ra
    // 0x8009DF54: nop

    return;
    // 0x8009DF54: nop

;}
RECOMP_FUNC void func_800149BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800149BC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800149C0: lw          $t6, -0x70A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X70A4);
    // 0x800149C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800149C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800149CC: bne         $t6, $zero, L_80014A4C
    if (ctx->r14 != 0) {
        // 0x800149D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80014A4C;
    }
    // 0x800149D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800149D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800149D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800149DC: jal         0x800155BC
    // 0x800149E0: sw          $t7, -0x70A4($at)
    MEM_W(-0X70A4, ctx->r1) = ctx->r15;
    func_800155BC(rdram, ctx);
        goto after_0;
    // 0x800149E0: sw          $t7, -0x70A4($at)
    MEM_W(-0X70A4, ctx->r1) = ctx->r15;
    after_0:
    // 0x800149E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800149E8: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x800149EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800149F0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800149F4: beq         $v0, $zero, L_80014A14
    if (ctx->r2 == 0) {
        // 0x800149F8: nop
    
            goto L_80014A14;
    }
    // 0x800149F8: nop

    // 0x800149FC: beq         $v0, $at, L_80014A14
    if (ctx->r2 == ctx->r1) {
        // 0x80014A00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80014A14;
    }
    // 0x80014A00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014A04: beq         $v0, $at, L_80014A24
    if (ctx->r2 == ctx->r1) {
        // 0x80014A08: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80014A24;
    }
    // 0x80014A08: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80014A0C: b           L_80014A2C
    // 0x80014A10: nop

        goto L_80014A2C;
    // 0x80014A10: nop

L_80014A14:
    // 0x80014A14: jal         0x8002F780
    // 0x80014A18: addiu       $a0, $a0, -0xB78
    ctx->r4 = ADD32(ctx->r4, -0XB78);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x80014A18: addiu       $a0, $a0, -0xB78
    ctx->r4 = ADD32(ctx->r4, -0XB78);
    after_1:
    // 0x80014A1C: b           L_80014A2C
    // 0x80014A20: nop

        goto L_80014A2C;
    // 0x80014A20: nop

L_80014A24:
    // 0x80014A24: jal         0x8002F780
    // 0x80014A28: addiu       $a0, $a0, -0xBC8
    ctx->r4 = ADD32(ctx->r4, -0XBC8);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x80014A28: addiu       $a0, $a0, -0xBC8
    ctx->r4 = ADD32(ctx->r4, -0XBC8);
    after_2:
L_80014A2C:
    // 0x80014A2C: jal         0x80015430
    // 0x80014A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015430(rdram, ctx);
        goto after_3;
    // 0x80014A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80014A34: jal         0x80018634
    // 0x80014A38: nop

    func_80018634(rdram, ctx);
        goto after_4;
    // 0x80014A38: nop

    after_4:
L_80014A3C:
    // 0x80014A3C: jal         0x8002EF70
    // 0x80014A40: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_5;
    // 0x80014A40: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x80014A44: b           L_80014A3C
    // 0x80014A48: nop

        goto L_80014A3C;
    // 0x80014A48: nop

L_80014A4C:
    // 0x80014A4C: jr          $ra
    // 0x80014A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801F4C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801F50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F54: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80801F58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801F5C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80801F60: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801F64: jal         0x800EE7F8
    // 0x80801F68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801F68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801F6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D68) << 16);
    // 0x80801F70: lwc1        $f4, 0x2D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D68));
    // 0x80801F74: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80801F78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801F7C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801F84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801F88: jal         0x800D10D4
    // 0x80801F8C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_800D10D4(rdram, ctx);
        goto after_1;
    // 0x80801F8C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80801F90: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801F94: jal         0x80106790
    // 0x80801F98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80801F98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801F9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801FA0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801FA4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80801FA8: jal         0x80802A2C
    // 0x80801FAC: addiu       $a3, $zero, 0x438
    ctx->r7 = ADD32(0, 0X438);
    func_80802A2C_chinflatableboss(rdram, ctx);
        goto after_3;
    // 0x80801FAC: addiu       $a3, $zero, 0x438
    ctx->r7 = ADD32(0, 0X438);
    after_3:
    // 0x80801FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801FB8: jr          $ra
    // 0x80801FBC: nop

    return;
    // 0x80801FBC: nop

;}
RECOMP_FUNC void func_80800434_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800438: addiu       $t6, $a1, -0x1142
    ctx->r14 = ADD32(ctx->r5, -0X1142);
    // 0x8080043C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800440: sltiu       $at, $t6, 0x1D
    ctx->r1 = ctx->r14 < 0X1D ? 1 : 0;
    // 0x80800444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080044C: beq         $at, $zero, L_80800690
    if (ctx->r1 == 0) {
        // 0x80800450: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800690;
    }
    // 0x80800450: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800454: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(868, 0XDD8) << 16);
    // 0x8080045C: addu        $at, $at, $t6
    gpr jr_addend_80800464 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800460: lw          $t6, 0xDD8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(868, 0XDD8));
    // 0x80800464: jr          $t6
    // 0x80800468: nop

    switch (jr_addend_80800464 >> 2) {
        case 0: goto L_808004C0; break;
        case 1: goto L_80800664; break;
        case 2: goto L_8080046C; break;
        case 3: goto L_80800530; break;
        case 4: goto L_80800690; break;
        case 5: goto L_8080056C; break;
        case 6: goto L_80800580; break;
        case 7: goto L_80800690; break;
        case 8: goto L_80800690; break;
        case 9: goto L_808005C4; break;
        case 10: goto L_808005C4; break;
        case 11: goto L_808005C4; break;
        case 12: goto L_808005C4; break;
        case 13: goto L_808005C4; break;
        case 14: goto L_80800690; break;
        case 15: goto L_80800690; break;
        case 16: goto L_80800690; break;
        case 17: goto L_80800690; break;
        case 18: goto L_80800690; break;
        case 19: goto L_80800690; break;
        case 20: goto L_80800690; break;
        case 21: goto L_80800690; break;
        case 22: goto L_80800690; break;
        case 23: goto L_80800690; break;
        case 24: goto L_80800690; break;
        case 25: goto L_80800690; break;
        case 26: goto L_80800690; break;
        case 27: goto L_80800494; break;
        case 28: goto L_8080067C; break;
        default: switch_error(__func__, 0x80800464, 0x80800DD8);
    }
    // 0x80800468: nop

L_8080046C:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80100094
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800478: jal         0x80089FE0
    // 0x8080047C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080047C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x80102424
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080048C: b           L_808006A8
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800494:
    // 0x80800494: jal         0x80800888
    // 0x80800498: nop

    func_80800888_chcheato(rdram, ctx);
        goto after_3;
    // 0x80800498: nop

    after_3:
    // 0x8080049C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004A0: addiu       $t7, $zero, 0x37
    ctx->r15 = ADD32(0, 0X37);
    // 0x808004A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808004A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004AC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808004B0: jal         0x8008A208
    // 0x808004B4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808004B4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808004B8: b           L_808006A8
    // 0x808004BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x808004BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004C0:
    // 0x808004C0: jal         0x800D1A04
    // 0x808004C4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800D1A04(rdram, ctx);
        goto after_5;
    // 0x808004C4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_5:
    // 0x808004C8: beq         $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004CC: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80800504;
    }
    // 0x808004CC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x808004D0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x808004D4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x808004D8: jal         0x80800824
    // 0x808004DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80800824_chcheato(rdram, ctx);
        goto after_6;
    // 0x808004DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x808004E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004E4: addiu       $t9, $zero, 0x37
    ctx->r25 = ADD32(0, 0X37);
    // 0x808004E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808004EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F4: jal         0x8008A208
    // 0x808004F8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808004F8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808004FC: b           L_808006A8
    // 0x80800500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800504:
    // 0x80800504: jal         0x800C01A8
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_8;
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8080050C: jal         0x800C0850
    // 0x80800510: nop

    func_800C0850(rdram, ctx);
        goto after_9;
    // 0x80800510: nop

    after_9:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x80102424
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800520: jal         0x80800CC0
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chcheato(rdram, ctx);
        goto after_11;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800528: b           L_808006A8
    // 0x8080052C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x8080052C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800530:
    // 0x80800530: jal         0x80800C0C
    // 0x80800534: nop

    func_80800C0C_chcheato(rdram, ctx);
        goto after_12;
    // 0x80800534: nop

    after_12:
    // 0x80800538: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x8080053C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800554;
    }
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x80102424
    // 0x80800548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x8080054C: b           L_808006A8
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800554:
    // 0x80800554: jal         0x80102424
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080055C: jal         0x80800CC0
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chcheato(rdram, ctx);
        goto after_15;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800564: b           L_808006A8
    // 0x80800568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080056C:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x80102424
    // 0x80800574: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800574: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800578: b           L_808006A8
    // 0x8080057C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x8080057C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800580:
    // 0x80800580: jal         0x800DA544
    // 0x80800584: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    func_800DA544(rdram, ctx);
        goto after_17;
    // 0x80800584: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    after_17:
    // 0x80800588: jal         0x80800C0C
    // 0x8080058C: nop

    func_80800C0C_chcheato(rdram, ctx);
        goto after_18;
    // 0x8080058C: nop

    after_18:
    // 0x80800590: beq         $v0, $zero, L_808005AC
    if (ctx->r2 == 0) {
        // 0x80800594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005AC;
    }
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x80102424
    // 0x808005A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x808005A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x808005A4: b           L_808006A8
    // 0x808005A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x808005A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005AC:
    // 0x808005AC: jal         0x80102424
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808005B4: jal         0x80800CC0
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chcheato(rdram, ctx);
        goto after_21;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808005BC: b           L_808006A8
    // 0x808005C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x808005C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005C4:
    // 0x808005C4: jal         0x800D1A04
    // 0x808005C8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800D1A04(rdram, ctx);
        goto after_22;
    // 0x808005C8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_22:
    // 0x808005CC: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x808005D0: bne         $at, $zero, L_80800610
    if (ctx->r1 != 0) {
        // 0x808005D4: nop
    
            goto L_80800610;
    }
    // 0x808005D4: nop

    // 0x808005D8: jal         0x80800BB8
    // 0x808005DC: nop

    func_80800BB8_chcheato(rdram, ctx);
        goto after_23;
    // 0x808005DC: nop

    after_23:
    // 0x808005E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808005E4: beq         $v0, $at, L_80800610
    if (ctx->r2 == ctx->r1) {
        // 0x808005E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800610;
    }
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x80100094
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808005F4: jal         0x80089FE0
    // 0x808005F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x808005F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: jal         0x80102424
    // 0x80800604: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80800604: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
    // 0x80800608: b           L_808006A8
    // 0x8080060C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x8080060C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800610:
    // 0x80800610: jal         0x800DA298
    // 0x80800614: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800614: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    after_27:
    // 0x80800618: bne         $v0, $zero, L_80800644
    if (ctx->r2 != 0) {
        // 0x8080061C: addiu       $a1, $zero, 0x115E
        ctx->r5 = ADD32(0, 0X115E);
            goto L_80800644;
    }
    // 0x8080061C: addiu       $a1, $zero, 0x115E
    ctx->r5 = ADD32(0, 0X115E);
    // 0x80800620: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800624: addiu       $t0, $zero, 0x37
    ctx->r8 = ADD32(0, 0X37);
    // 0x80800628: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080062C: addiu       $a1, $zero, 0x1148
    ctx->r5 = ADD32(0, 0X1148);
    // 0x80800630: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800634: jal         0x8008A208
    // 0x80800638: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x80800638: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_28:
    // 0x8080063C: b           L_808006A8
    // 0x80800640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800644:
    // 0x80800644: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800648: addiu       $t1, $zero, 0x37
    ctx->r9 = ADD32(0, 0X37);
    // 0x8080064C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800650: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800654: jal         0x8008A208
    // 0x80800658: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800658: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_29:
    // 0x8080065C: b           L_808006A8
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800664:
    // 0x80800664: jal         0x80085710
    // 0x80800668: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_30;
    // 0x80800668: nop

    after_30:
    // 0x8080066C: jal         0x80088830
    // 0x80800670: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_31;
    // 0x80800670: nop

    after_31:
    // 0x80800674: b           L_808006A8
    // 0x80800678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x80800678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080067C:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x80102424
    // 0x80800684: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_32;
    // 0x80800684: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_32:
    // 0x80800688: b           L_808006A8
    // 0x8080068C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006A8;
    // 0x8080068C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800690:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x80102424
    // 0x80800698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_33;
    // 0x80800698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x8080069C: jal         0x80800CC0
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chcheato(rdram, ctx);
        goto after_34;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808006A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006A8:
    // 0x808006A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006B0: jr          $ra
    // 0x808006B4: nop

    return;
    // 0x808006B4: nop

;}
