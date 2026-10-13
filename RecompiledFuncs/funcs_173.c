#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800298E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800298E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800298E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800298EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800298F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800298F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800298F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800298FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80029900: sb          $t6, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r14;
    // 0x80029904: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80029908: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x8002990C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80029910: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80029914: beq         $t9, $zero, L_800299E4
    if (ctx->r25 == 0) {
        // 0x80029918: nop
    
            goto L_800299E4;
    }
    // 0x80029918: nop

L_8002991C:
    // 0x8002991C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80029920: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80029924: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80029928: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8002992C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80029930: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80029934: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029938: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8002993C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80029940: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80029944: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029948: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002994C: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x80029950: bne         $t8, $at, L_800299D0
    if (ctx->r24 != ctx->r1) {
        // 0x80029954: nop
    
            goto L_800299D0;
    }
    // 0x80029954: nop

    // 0x80029958: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002995C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80029960: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80029964: bne         $t0, $t1, L_800299D0
    if (ctx->r8 != ctx->r9) {
        // 0x80029968: nop
    
            goto L_800299D0;
    }
    // 0x80029968: nop

    // 0x8002996C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80029970: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80029974: slt         $at, $t4, $t2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029978: beq         $at, $zero, L_800299C4
    if (ctx->r1 == 0) {
        // 0x8002997C: nop
    
            goto L_800299C4;
    }
    // 0x8002997C: nop

    // 0x80029980: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80029984: beq         $t3, $zero, L_800299A4
    if (ctx->r11 == 0) {
        // 0x80029988: nop
    
            goto L_800299A4;
    }
    // 0x80029988: nop

    // 0x8002998C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029990: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029994: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80029998: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8002999C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800299A0: sw          $t9, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r25;
L_800299A4:
    // 0x800299A4: jal         0x80020E74
    // 0x800299A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80020E74(rdram, ctx);
        goto after_0;
    // 0x800299A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x800299AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800299B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800299B4: jal         0x80020E40
    // 0x800299B8: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x800299B8: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_1:
    // 0x800299BC: b           L_800299C8
    // 0x800299C0: nop

        goto L_800299C8;
    // 0x800299C0: nop

L_800299C4:
    // 0x800299C4: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
L_800299C8:
    // 0x800299C8: b           L_800299E4
    // 0x800299CC: nop

        goto L_800299E4;
    // 0x800299CC: nop

L_800299D0:
    // 0x800299D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800299D4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800299D8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800299DC: bne         $t1, $zero, L_8002991C
    if (ctx->r9 != 0) {
        // 0x800299E0: nop
    
            goto L_8002991C;
    }
    // 0x800299E0: nop

L_800299E4:
    // 0x800299E4: b           L_800299F4
    // 0x800299E8: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
        goto L_800299F4;
    // 0x800299E8: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x800299EC: b           L_800299F4
    // 0x800299F0: nop

        goto L_800299F4;
    // 0x800299F0: nop

L_800299F4:
    // 0x800299F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800299F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800299FC: jr          $ra
    // 0x80029A00: nop

    return;
    // 0x80029A00: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800430: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080043C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800440: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800444: jal         0x80094C0C
    // 0x80800448: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80094C0C(rdram, ctx);
        goto after_0;
    // 0x80800448: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x8009C128
    // 0x80800454: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800454: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800458: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080045C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800460: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800464: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800468: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080046C: jal         0x800EE7F8
    // 0x80800470: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800470: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: jal         0x800F3E84
    // 0x8080047C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F3E84(rdram, ctx);
        goto after_3;
    // 0x8080047C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80800480: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800484: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800488: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8080048C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800490: jal         0x800EEB9C
    // 0x80800494: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x80800494: nop

    after_4:
    // 0x80800498: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8080049C: jal         0x800EF04C
    // 0x808004A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808004A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x808004A4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808004AC: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x808004B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004B4: jal         0x800EEB9C
    // 0x808004B8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_6;
    // 0x808004B8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808004BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808004C0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808004C4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x808004C8: jal         0x800EE7F8
    // 0x808004CC: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808004CC: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    after_7:
    // 0x808004D0: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x808004D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808004D8: jal         0x800EE7F8
    // 0x808004DC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808004DC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_8:
    // 0x808004E0: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x808004E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808004E8: jal         0x800EE7F8
    // 0x808004EC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808004EC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_9:
    // 0x808004F0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x808004F4: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x808004F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808004FC: addiu       $a0, $a0, 0x4A58
    ctx->r4 = ADD32(ctx->r4, 0X4A58);
    // 0x80800500: sb          $t6, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r14;
    // 0x80800504: jal         0x80086D30
    // 0x80800508: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800508: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_10:
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800514: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_808003D8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: jal         0x800897C8
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void func_80800F14_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800F20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800F24: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80800F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F2C: jal         0x8009370C
    // 0x80800F30: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8009370C(rdram, ctx);
        goto after_0;
    // 0x80800F30: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800F34: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800F38: jal         0x800E0ACC
    // 0x80800F3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E0ACC(rdram, ctx);
        goto after_1;
    // 0x80800F3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800F40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F44: jal         0x800E0AF0
    // 0x80800F48: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_2;
    // 0x80800F48: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800F4C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800F50: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3D4) << 16);
    // 0x80800F54: lwc1        $f6, -0x5C2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3D4));
    // 0x80800F58: lwc1        $f4, 0x58($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80800F5C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3D8) << 16);
    // 0x80800F60: lwc1        $f10, 0x60($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80800F64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F6C: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x80800F70: lwc1        $f16, -0x5C28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3D8));
    // 0x80800F74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800F78: jal         0x800A3280
    // 0x80800F7C: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    func_800A3280(rdram, ctx);
        goto after_3;
    // 0x80800F7C: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    after_3:
    // 0x80800F80: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800F84: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80800F88: beq         $at, $zero, L_80800FEC
    if (ctx->r1 == 0) {
        // 0x80800F8C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800FEC;
    }
    // 0x80800F8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800F90: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3DC) << 16);
    // 0x80800F94: addu        $at, $at, $t6
    gpr jr_addend_80800F9C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800F98: lw          $t6, -0x5C24($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3DC));
    // 0x80800F9C: jr          $t6
    // 0x80800FA0: nop

    switch (jr_addend_80800F9C >> 2) {
        case 0: goto L_80800FA4; break;
        case 1: goto L_80800FE0; break;
        case 2: goto L_80800FE0; break;
        case 3: goto L_80800FB8; break;
        case 4: goto L_80800FCC; break;
        case 5: goto L_80800FA4; break;
        default: switch_error(__func__, 0x80800F9C, 0x8080A3DC);
    }
    // 0x80800FA0: nop

L_80800FA4:
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA8: jal         0x80800A18
    // 0x80800FAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800A18_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80800FAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800FB0: b           L_80800FF0
    // 0x80800FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FF0;
    // 0x80800FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FB8:
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: jal         0x80800B44
    // 0x80800FC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800B44_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80800FC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80800FC4: b           L_80800FF0
    // 0x80800FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FF0;
    // 0x80800FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FCC:
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: jal         0x80800C88
    // 0x80800FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800C88_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80800FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800FD8: b           L_80800FF0
    // 0x80800FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FF0;
    // 0x80800FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FE0:
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: jal         0x80800D18
    // 0x80800FE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800D18_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80800FE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
L_80800FEC:
    // 0x80800FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FF0:
    // 0x80800FF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800FF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800FF8: jr          $ra
    // 0x80800FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void glrecord_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800068: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x8080006C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800070: addiu       $v0, $v0, -0x2A50
    ctx->r2 = ADD32(ctx->r2, -0X2A50);
    // 0x80800074: mflo        $t6
    ctx->r14 = lo;
    // 0x80800078: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080007C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80800080: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80800084: jr          $ra
    // 0x80800088: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    return;
    // 0x80800088: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
;}
RECOMP_FUNC void chfootwear_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2448, 0X7D0) << 16);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X7D0));
    return;
    // 0x80800698: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X7D0));
;}
RECOMP_FUNC void func_808002E0_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808002E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F0: jal         0x80106790
    // 0x808002F4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002F4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808002F8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80103DFC
    // 0x80800304: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x80800304: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80800308: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080030C: jal         0x800EE7F8
    // 0x80800310: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800310: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80800314: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800318: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1376, 0X4E0) << 16);
    // 0x8080031C: addiu       $a1, $a1, 0x4E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1376, 0X4E0));
    // 0x80800320: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800324: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800330;
    }
    // 0x80800324: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800328: b           L_80800330
    // 0x8080032C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
        goto L_80800330;
    // 0x8080032C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
L_80800330:
    // 0x80800330: jal         0x800F1DF4
    // 0x80800334: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80800334: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800338: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080033C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800340: jal         0x800EF1B8
    // 0x80800344: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80800344: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_4:
    // 0x80800348: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080034C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800350: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800354: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1376, 0X480) << 16);
    // 0x80800358: addiu       $t6, $t6, 0x480
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1376, 0X480));
    // 0x8080035C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800360: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800364: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800368: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080036C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80800370: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800374: jal         0x800BBCB8
    // 0x80800378: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800378: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_5:
    // 0x8080037C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1376, 0X4C4) << 16);
    // 0x80800380: addiu       $a2, $a2, 0x4C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1376, 0X4C4));
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800388: jal         0x80089D18
    // 0x8080038C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8080038C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800390: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80800394: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800398: beq         $t7, $zero, L_808003E0
    if (ctx->r15 == 0) {
        // 0x8080039C: nop
    
            goto L_808003E0;
    }
    // 0x8080039C: nop

    // 0x808003A0: jal         0x800EE7F8
    // 0x808003A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808003A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808003A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808003AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003B0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808003B4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808003B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808003BC: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x808003C0: jal         0x800C8CB8
    // 0x808003C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x808003C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_8:
    // 0x808003C8: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x808003CC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808003D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x808003D4: jal         0x800863E8
    // 0x808003D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808003D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808003DC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_808003E0:
    // 0x808003E0: jal         0x8010A570
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003E8: jal         0x800FFAB0
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void _sumole_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A38: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A38);
    return;
    // 0x80089A3C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void suquiz_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB4: jal         0x800D3948
    // 0x80800CB8: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800CB8: nop

    after_0:
    // 0x80800CBC: beq         $v0, $zero, L_80800CF4
    if (ctx->r2 == 0) {
        // 0x80800CC0: nop
    
            goto L_80800CF4;
    }
    // 0x80800CC0: nop

    // 0x80800CC4: jal         0x80088398
    // 0x80800CC8: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800CC8: nop

    after_1:
    // 0x80800CCC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800CD0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800CD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800CDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800CE0: addiu       $v1, $v1, 0x7614
    ctx->r3 = ADD32(ctx->r3, 0X7614);
    // 0x80800CE4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800CE8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800CEC: b           L_80800D1C
    // 0x80800CF0: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
        goto L_80800D1C;
    // 0x80800CF0: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
L_80800CF4:
    // 0x80800CF4: jal         0x80800584
    // 0x80800CF8: nop

    suquiz_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800CF8: nop

    after_2:
    // 0x80800CFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800D00: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80800D04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF70) << 16);
    // 0x80800D08: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800D0C: addiu       $v1, $v1, 0x7614
    ctx->r3 = ADD32(ctx->r3, 0X7614);
    // 0x80800D10: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80800D14: lwc1        $f16, 0xF70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF70));
    // 0x80800D18: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
L_80800D1C:
    // 0x80800D1C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80800D20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800D24: sb          $t9, 0x24($t0)
    MEM_B(0X24, ctx->r8) = ctx->r25;
    // 0x80800D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D30: jr          $ra
    // 0x80800D34: nop

    return;
    // 0x80800D34: nop

;}
RECOMP_FUNC void func_8080009C_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000A4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808000A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: beq         $a1, $at, L_808000D8
    if (ctx->r5 == ctx->r1) {
        // 0x808000B4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808000D8;
    }
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B8: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808000BC: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000C0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1508, 0X4A0) << 16);
            goto L_808000F8;
    }
    // 0x808000C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1508, 0X4A0) << 16);
    // 0x808000C4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000C8: beq         $a1, $at, L_8080010C
    if (ctx->r5 == ctx->r1) {
        // 0x808000CC: nop
    
            goto L_8080010C;
    }
    // 0x808000CC: nop

    // 0x808000D0: b           L_80800128
    // 0x808000D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800128;
    // 0x808000D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D8:
    // 0x808000D8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808000DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E8: jal         0x80101FDC
    // 0x808000EC: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808000EC: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    after_0:
    // 0x808000F0: b           L_80800128
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800128;
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F8:
    // 0x808000F8: addiu       $a0, $a0, 0x4A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1508, 0X4A0));
    // 0x808000FC: jal         0x80088090
    // 0x80800100: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800100: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x80800104: b           L_80800128
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800128;
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080010C:
    // 0x8080010C: jal         0x80800138
    // 0x80800110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800138_chbottlesparty(rdram, ctx);
        goto after_2;
    // 0x80800110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800114: b           L_80800128
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800128;
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080011C: b           L_80800128
    // 0x80800120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800128;
    // 0x80800120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800128:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void _glgamestore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884A8: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884A8);
    return;
    // 0x800884AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chstatueboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1312, 0X2748) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2748
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1312, 0X2748));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2748
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1312, 0X2748));
;}
RECOMP_FUNC void func_80800D74_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D84: jal         0x80100094
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D8C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D90: jal         0x800EFD24
    // 0x80800D94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800D94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800D98: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800D9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800DA0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800DA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DB0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800DB4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800DB8: jal         0x808015DC
    // 0x80800DBC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_808015DC_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80800DBC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800DC0: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800DCC: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800DD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800DD4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800DD8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800DDC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800DE0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800DE4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800DE8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800DEC: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
    // 0x80800DF0: jal         0x800EFA4C
    // 0x80800DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800DF8: jal         0x800EF2A0
    // 0x80800DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EF2A0(rdram, ctx);
        goto after_4;
    // 0x80800DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800E00: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800E04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E08: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800E0C: swc1        $f6, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->f6.u32l;
    // 0x80800E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E1C: jr          $ra
    // 0x80800E20: nop

    return;
    // 0x80800E20: nop

;}
RECOMP_FUNC void babuzz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000FC: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80800100: jal         0x800C2FDC
    // 0x80800104: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800104: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_0:
    // 0x80800108: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x80800110: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_80800E40_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E48: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E50: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80800E54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800E58: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800E5C: jal         0x80086C68
    // 0x80800E60: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800E60: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800E64: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800E68: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800E6C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80800E70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E78: jal         0x80089840
    // 0x80800E7C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800E7C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x80800E80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E84: jal         0x80100094
    // 0x80800E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800E8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E90: jal         0x80089850
    // 0x80800E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800EA0: jal         0x80089908
    // 0x80800EA4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_4;
    // 0x80800EA4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800EA8: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800EAC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800EB0: jal         0x80089900
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800EB8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800EBC: jal         0x8010A800
    // 0x80800EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x80800EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800EC4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ECC: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x80800ED0: lui         $a3, 0x457A
    ctx->r7 = S32(0X457A << 16);
    // 0x80800ED4: jal         0x80089920
    // 0x80800ED8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sumumbofx_entrypoint_28(rdram, ctx);
        goto after_7;
    // 0x80800ED8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EE0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: jr          $ra
    // 0x80800EEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800EEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800F5F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5F50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5F58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5F60: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5F64: jal         0x8009C990
    // 0x800F5F68: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    yaw_getIdeal(rdram, ctx);
        goto after_0;
    // 0x800F5F68: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5F74: jr          $ra
    // 0x800F5F78: nop

    return;
    // 0x800F5F78: nop

;}
RECOMP_FUNC void _dbtex_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A38: syscall     650
    recomp_syscall_handler(rdram, ctx, 0x80087A38);
    return;
    // 0x80087A3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800110_bskazshoessuckspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080011C: jal         0x8009E704
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080012C: jal         0x8009CA70
    // 0x80800130: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_1:
    // 0x80800134: bnel        $v0, $zero, L_80800174
    if (ctx->r2 != 0) {
        // 0x80800138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080013C: jal         0x80085090
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80095774
    // 0x8080014C: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x8080014C: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_3:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80092880
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092880(rdram, ctx);
        goto after_4;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x800A2018
    // 0x80800164: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A2018(rdram, ctx);
        goto after_5;
    // 0x80800164: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
    // 0x80800168: jal         0x800A4E30
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_6;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800174:
    // 0x80800174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AA8: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AA8);
    return;
    // 0x80087AAC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void glsavegame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x808003C8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x808003CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D0: addiu       $s1, $s1, 0x7624
    ctx->r17 = ADD32(ctx->r17, 0X7624);
    // 0x808003D4: addiu       $s0, $s0, 0x7618
    ctx->r16 = ADD32(ctx->r16, 0X7618);
    // 0x808003D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808003DC:
    // 0x808003DC: beql        $a0, $zero, L_808003F4
    if (ctx->r4 == 0) {
        // 0x808003E0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808003F4;
    }
    goto skip_0;
    // 0x808003E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808003E4: jal         0x8001B084
    // 0x808003E8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808003E8: nop

    after_0:
    // 0x808003EC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x808003F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808003F4:
    // 0x808003F4: bnel        $s0, $s1, L_808003DC
    if (ctx->r16 != ctx->r17) {
        // 0x808003F8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808003DC;
    }
    goto skip_1;
    // 0x808003F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808003FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800404: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800408: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080040C: sb          $zero, 0x7628($at)
    MEM_B(0X7628, ctx->r1) = 0;
    // 0x80800410: jr          $ra
    // 0x80800414: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800414: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chpickups_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X940) << 16);
    // 0x8080004C: jr          $ra
    // 0x80800050: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X940));
    return;
    // 0x80800050: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X940));
;}
RECOMP_FUNC void func_808000FC_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800104: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800108: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080010C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800110: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1732, 0X4790) << 16);
    // 0x80800114: addiu       $a2, $a2, 0x4790
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1732, 0X4790));
    // 0x80800118: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080011C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80800120: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80800124: lw          $t9, -0x638($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X638);
    // 0x80800128: lw          $t0, -0x634($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X634);
    // 0x8080012C: lui         $v1, 0x3FFF
    ctx->r3 = S32(0X3FFF << 16);
    // 0x80800130: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80800134: and         $s1, $t9, $v1
    ctx->r17 = ctx->r25 & ctx->r3;
    // 0x80800138: andi        $t2, $s1, 0x400
    ctx->r10 = ctx->r17 & 0X400;
    // 0x8080013C: and         $t1, $t0, $v1
    ctx->r9 = ctx->r8 & ctx->r3;
    // 0x80800140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800144: beq         $t2, $zero, L_8080015C
    if (ctx->r10 == 0) {
        // 0x80800148: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_8080015C;
    }
    // 0x80800148: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8080014C: jal         0x8008A490
    // 0x80800150: nop

    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800150: nop

    after_0:
    // 0x80800154: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1732, 0X4790) << 16);
    // 0x80800158: addiu       $a2, $a2, 0x4790
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1732, 0X4790));
L_8080015C:
    // 0x8080015C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(0X8080 << 16);
    // 0x80800164: sll         $t8, $s1, 8
    ctx->r24 = S32(ctx->r17 << 8);
    // 0x80800168: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8080016C: beq         $t4, $zero, L_80800180
    if (ctx->r12 == 0) {
        // 0x80800170: andi        $t2, $s1, 0x8
        ctx->r10 = ctx->r17 & 0X8;
            goto L_80800180;
    }
    // 0x80800170: andi        $t2, $s1, 0x8
    ctx->r10 = ctx->r17 & 0X8;
    // 0x80800174: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x80800178: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8080017C: sb          $t7, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r15;
L_80800180:
    // 0x80800180: bgez        $t8, L_80800194
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800184: nop
    
            goto L_80800194;
    }
    // 0x80800184: nop

    // 0x80800188: lbu         $t0, 0x71($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X71);
    // 0x8080018C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80800190: sb          $t1, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r9;
L_80800194:
    // 0x80800194: beql        $t2, $zero, L_808001AC
    if (ctx->r10 == 0) {
        // 0x80800198: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800198: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x8080019C: lbu         $t4, 0x70($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X70);
    // 0x808001A0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x808001A4: sb          $t5, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r13;
    // 0x808001A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_808001AC:
    // 0x808001AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808001B0: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x808001B4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x808001B8: beql        $t7, $zero, L_80800224
    if (ctx->r15 == 0) {
        // 0x808001BC: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_80800224;
    }
    goto skip_1;
    // 0x808001BC: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    skip_1:
    // 0x808001C0: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x808001C4: lbu         $t9, 0x7B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7B);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x808001D0: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x808001D4: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x808001D8: sb          $t0, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r8;
    // 0x808001DC: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x808001E0: lbu         $t5, -0x62C($t4)
    ctx->r13 = MEM_BU(ctx->r12, -0X62C);
    // 0x808001E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808001E8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x808001EC: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808001F0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808001F4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x808001F8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x808001FC: lbu         $t0, -0x62B($t9)
    ctx->r8 = MEM_BU(ctx->r25, -0X62B);
    // 0x80800200: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80800204: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80800208: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x8080020C: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800210: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80800214: lbu         $t5, -0x62A($t4)
    ctx->r13 = MEM_BU(ctx->r12, -0X62A);
    // 0x80800218: jal         0x80089CE8
    // 0x8080021C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080021C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    after_1:
    // 0x80800220: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
L_80800224:
    // 0x80800224: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x80800228: beq         $t6, $zero, L_8080023C
    if (ctx->r14 == 0) {
        // 0x8080022C: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_8080023C;
    }
    // 0x8080022C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x8010A800
    // 0x80800238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_2;
    // 0x80800238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_8080023C:
    // 0x8080023C: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x80800240: and         $v0, $s1, $at
    ctx->r2 = ctx->r17 & ctx->r1;
    // 0x80800244: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800250: jal         0x8010A800
    // 0x80800254: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x80800254: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800258: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8080025C:
    // 0x8080025C: andi        $t8, $s1, 0x100
    ctx->r24 = ctx->r17 & 0X100;
    // 0x80800260: beq         $t8, $zero, L_80800278
    if (ctx->r24 == 0) {
        // 0x80800264: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800278;
    }
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    // 0x8080026C: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80800270: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800274: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
L_80800278:
    // 0x80800278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080027C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800284: jal         0x80108658
    // 0x80800288: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80108658(rdram, ctx);
        goto after_4;
    // 0x80800288: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x8080028C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: beq         $t2, $zero, L_808002B0
    if (ctx->r10 == 0) {
        // 0x8080029C: nop
    
            goto L_808002B0;
    }
    // 0x8080029C: nop

    // 0x808002A0: jal         0x8010A800
    // 0x808002A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_5;
    // 0x808002A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808002A8: b           L_808002D8
    // 0x808002AC: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
        goto L_808002D8;
    // 0x808002AC: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
L_808002B0:
    // 0x808002B0: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x8010A800
    // 0x808002C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x808002C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808002C4: b           L_808002D8
    // 0x808002C8: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
        goto L_808002D8;
    // 0x808002C8: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
L_808002CC:
    // 0x808002CC: jal         0x8010A800
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_7;
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808002D4: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
L_808002D8:
    // 0x808002D8: beql        $t3, $zero, L_808002EC
    if (ctx->r11 == 0) {
        // 0x808002DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002EC;
    }
    goto skip_2;
    // 0x808002DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808002E0: jal         0x8010A63C
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_8;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808002E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002EC:
    // 0x808002EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808002F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80803694_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803694: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803698: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080369C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808036A0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808036A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808036A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808036AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808036B0: jal         0x80100094
    // 0x808036B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808036B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808036B8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808036BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808036C0: slti        $at, $a3, 0x14D9
    ctx->r1 = SIGNED(ctx->r7) < 0X14D9 ? 1 : 0;
    // 0x808036C4: bne         $at, $zero, L_808036EC
    if (ctx->r1 != 0) {
        // 0x808036C8: addiu       $t6, $a3, -0x171D
        ctx->r14 = ADD32(ctx->r7, -0X171D);
            goto L_808036EC;
    }
    // 0x808036C8: addiu       $t6, $a3, -0x171D
    ctx->r14 = ADD32(ctx->r7, -0X171D);
    // 0x808036CC: sltiu       $at, $t6, 0x19
    ctx->r1 = ctx->r14 < 0X19 ? 1 : 0;
    // 0x808036D0: beq         $at, $zero, L_808039AC
    if (ctx->r1 == 0) {
        // 0x808036D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808039AC;
    }
    // 0x808036D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808036D8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A88) << 16);
    // 0x808036DC: addu        $at, $at, $t6
    gpr jr_addend_808036E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808036E0: lw          $t6, -0x6578($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A88));
    // 0x808036E4: jr          $t6
    // 0x808036E8: nop

    switch (jr_addend_808036E4 >> 2) {
        case 0: goto L_808039AC; break;
        case 1: goto L_8080370C; break;
        case 2: goto L_8080370C; break;
        case 3: goto L_80803724; break;
        case 4: goto L_808037AC; break;
        case 5: goto L_808037A4; break;
        case 6: goto L_808037C0; break;
        case 7: goto L_808037DC; break;
        case 8: goto L_808037F8; break;
        case 9: goto L_808039AC; break;
        case 10: goto L_808039AC; break;
        case 11: goto L_808039AC; break;
        case 12: goto L_80803890; break;
        case 13: goto L_808038C0; break;
        case 14: goto L_808038E8; break;
        case 15: goto L_80803930; break;
        case 16: goto L_80803944; break;
        case 17: goto L_80803740; break;
        case 18: goto L_80803758; break;
        case 19: goto L_80803758; break;
        case 20: goto L_80803820; break;
        case 21: goto L_80803838; break;
        case 22: goto L_80803850; break;
        case 23: goto L_80803868; break;
        case 24: goto L_80803960; break;
        default: switch_error(__func__, 0x808036E4, 0x80809A88);
    }
    // 0x808036E8: nop

L_808036EC:
    // 0x808036EC: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808036F0: beq         $a3, $at, L_8080398C
    if (ctx->r7 == ctx->r1) {
        // 0x808036F4: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_8080398C;
    }
    // 0x808036F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808036F8: addiu       $at, $zero, 0x14D8
    ctx->r1 = ADD32(0, 0X14D8);
    // 0x808036FC: beq         $a3, $at, L_80803970
    if (ctx->r7 == ctx->r1) {
        // 0x80803700: nop
    
            goto L_80803970;
    }
    // 0x80803700: nop

    // 0x80803704: b           L_808039B0
    // 0x80803708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080370C:
    // 0x8080370C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803710: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80803714: jal         0x80803BE8
    // 0x80803718: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80803718: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8080371C: b           L_808039B0
    // 0x80803720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803724:
    // 0x80803724: jal         0x800FDC28
    // 0x80803728: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800FDC28(rdram, ctx);
        goto after_2;
    // 0x80803728: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x8080372C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803730: jal         0x80805A00
    // 0x80803734: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80803734: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80803738: b           L_808039B0
    // 0x8080373C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080373C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803740:
    // 0x80803740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803744: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80803748: jal         0x80802FEC
    // 0x8080374C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x8080374C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80803750: b           L_808039B0
    // 0x80803754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803758:
    // 0x80803758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080375C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80803760: jal         0x80802878
    // 0x80803764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80803764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80803768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080376C: jal         0x80802170
    // 0x80803770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80803770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80803774: bne         $v0, $zero, L_80803790
    if (ctx->r2 != 0) {
        // 0x80803778: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803790;
    }
    // 0x80803778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080377C: addiu       $a1, $zero, 0x1722
    ctx->r5 = ADD32(0, 0X1722);
    // 0x80803780: jal         0x80803660
    // 0x80803784: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80803784: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    after_7:
    // 0x80803788: b           L_808039B0
    // 0x8080378C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080378C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803790:
    // 0x80803790: jal         0x800C0850
    // 0x80803794: nop

    func_800C0850(rdram, ctx);
        goto after_8;
    // 0x80803794: nop

    after_8:
    // 0x80803798: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8080379C: b           L_808039AC
    // 0x808037A0: sh          $zero, 0x46($t7)
    MEM_H(0X46, ctx->r15) = 0;
        goto L_808039AC;
    // 0x808037A0: sh          $zero, 0x46($t7)
    MEM_H(0X46, ctx->r15) = 0;
L_808037A4:
    // 0x808037A4: b           L_808039AC
    // 0x808037A8: sh          $zero, 0x46($v0)
    MEM_H(0X46, ctx->r2) = 0;
        goto L_808039AC;
    // 0x808037A8: sh          $zero, 0x46($v0)
    MEM_H(0X46, ctx->r2) = 0;
L_808037AC:
    // 0x808037AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037B0: jal         0x80805A00
    // 0x808037B4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x808037B4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_9:
    // 0x808037B8: b           L_808039B0
    // 0x808037BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x808037BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808037C0:
    // 0x808037C0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CF0) << 16);
    // 0x808037C4: addiu       $a2, $a2, -0x6310
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CF0));
    // 0x808037C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037CC: jal         0x80807280
    // 0x808037D0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x808037D0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_10:
    // 0x808037D4: b           L_808039B0
    // 0x808037D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x808037D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808037DC:
    // 0x808037DC: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9D00) << 16);
    // 0x808037E0: addiu       $a2, $a2, -0x6300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9D00));
    // 0x808037E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037E8: jal         0x80807280
    // 0x808037EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x808037EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_11:
    // 0x808037F0: b           L_808039B0
    // 0x808037F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x808037F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808037F8:
    // 0x808037F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037FC: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80803800: jal         0x8080290C
    // 0x80803804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80803804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80803808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080380C: addiu       $a1, $zero, 0x1726
    ctx->r5 = ADD32(0, 0X1726);
    // 0x80803810: jal         0x80803660
    // 0x80803814: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80803814: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_13:
    // 0x80803818: b           L_808039B0
    // 0x8080381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803820:
    // 0x80803820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803824: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80803828: jal         0x80803BE8
    // 0x8080382C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x8080382C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_14:
    // 0x80803830: b           L_808039B0
    // 0x80803834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803838:
    // 0x80803838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080383C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80803840: jal         0x80803BE8
    // 0x80803844: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80803844: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_15:
    // 0x80803848: b           L_808039B0
    // 0x8080384C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080384C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803850:
    // 0x80803850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803854: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80803858: jal         0x80803BE8
    // 0x8080385C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x8080385C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_16:
    // 0x80803860: b           L_808039B0
    // 0x80803864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803868:
    // 0x80803868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080386C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80803870: jal         0x80802878
    // 0x80803874: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x80803874: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80803878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080387C: addiu       $a1, $zero, 0x1729
    ctx->r5 = ADD32(0, 0X1729);
    // 0x80803880: jal         0x80803660
    // 0x80803884: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x80803884: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_18:
    // 0x80803888: b           L_808039B0
    // 0x8080388C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080388C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803890:
    // 0x80803890: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CC0) << 16);
    // 0x80803894: addiu       $a2, $a2, -0x6340
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CC0));
    // 0x80803898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080389C: jal         0x80806A78
    // 0x808038A0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x808038A0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_19:
    // 0x808038A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038A8: jal         0x80806EE4
    // 0x808038AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x808038AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808038B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808038B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808038B8: b           L_808039AC
    // 0x808038BC: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
        goto L_808039AC;
    // 0x808038BC: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
L_808038C0:
    // 0x808038C0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CD0) << 16);
    // 0x808038C4: addiu       $a2, $a2, -0x6330
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CD0));
    // 0x808038C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038CC: jal         0x80806A78
    // 0x808038D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x808038D0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_21:
    // 0x808038D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038D8: jal         0x80806EE4
    // 0x808038DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_22;
    // 0x808038DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808038E0: b           L_808039B0
    // 0x808038E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x808038E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808038E8:
    // 0x808038E8: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CE0) << 16);
    // 0x808038EC: addiu       $a2, $a2, -0x6320
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CE0));
    // 0x808038F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038F4: jal         0x80806A78
    // 0x808038F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_23;
    // 0x808038F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_23:
    // 0x808038FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803900: jal         0x80806EE4
    // 0x80803904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_24;
    // 0x80803904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80803908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080390C: jal         0x80807DC0
    // 0x80803910: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80807DC0_chdiggerboss(rdram, ctx);
        goto after_25;
    // 0x80803910: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x80803914: jal         0x80802228
    // 0x80803918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x80803918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8080391C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803920: jal         0x808080C0
    // 0x80803924: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808080C0_chdiggerboss(rdram, ctx);
        goto after_27;
    // 0x80803924: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x80803928: b           L_808039B0
    // 0x8080392C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080392C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803930:
    // 0x80803930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803934: jal         0x80808470
    // 0x80803938: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80808470_chdiggerboss(rdram, ctx);
        goto after_28;
    // 0x80803938: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_28:
    // 0x8080393C: b           L_808039B0
    // 0x80803940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803944:
    // 0x80803944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803948: jal         0x80802BE0
    // 0x8080394C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80802BE0_chdiggerboss(rdram, ctx);
        goto after_29;
    // 0x8080394C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_29:
    // 0x80803950: jal         0x80808560
    // 0x80803954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808560_chdiggerboss(rdram, ctx);
        goto after_30;
    // 0x80803954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80803958: b           L_808039B0
    // 0x8080395C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080395C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803960:
    // 0x80803960: jal         0x80809150
    // 0x80803964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809150_chdiggerboss(rdram, ctx);
        goto after_31;
    // 0x80803964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80803968: b           L_808039B0
    // 0x8080396C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x8080396C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803970:
    // 0x80803970: jal         0x800FDC28
    // 0x80803974: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_32;
    // 0x80803974: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x80803978: addiu       $a0, $zero, 0x191
    ctx->r4 = ADD32(0, 0X191);
    // 0x8080397C: jal         0x80087A58
    // 0x80803980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_33;
    // 0x80803980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80803984: b           L_808039B0
    // 0x80803988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x80803988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080398C:
    // 0x8080398C: blez        $t0, L_808039A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80803990: nop
    
            goto L_808039A4;
    }
    // 0x80803990: nop

    // 0x80803994: jal         0x80088188
    // 0x80803998: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_34;
    // 0x80803998: nop

    after_34:
    // 0x8080399C: b           L_808039B0
    // 0x808039A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808039B0;
    // 0x808039A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808039A4:
    // 0x808039A4: jal         0x80088180
    // 0x808039A8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_35;
    // 0x808039A8: nop

    after_35:
L_808039AC:
    // 0x808039AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808039B0:
    // 0x808039B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808039B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808039B8: jr          $ra
    // 0x808039BC: nop

    return;
    // 0x808039BC: nop

;}
RECOMP_FUNC void func_800951B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800951B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800951B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800951BC: lui         $a2, 0x3D0B
    ctx->r6 = S32(0X3D0B << 16);
    // 0x800951C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800951C4: ori         $a2, $a2, 0x4396
    ctx->r6 = ctx->r6 | 0X4396;
    // 0x800951C8: jal         0x8009518C
    // 0x800951CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009518C(rdram, ctx);
        goto after_0;
    // 0x800951CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800951D0: lui         $a2, 0x3D0B
    ctx->r6 = S32(0X3D0B << 16);
    // 0x800951D4: ori         $a2, $a2, 0x4396
    ctx->r6 = ctx->r6 | 0X4396;
    // 0x800951D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800951DC: jal         0x8009518C
    // 0x800951E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009518C(rdram, ctx);
        goto after_1;
    // 0x800951E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800951E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800951E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800951EC: jr          $ra
    // 0x800951F0: nop

    return;
    // 0x800951F0: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A670: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A670);
    return;
    // 0x8008A674: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800194_chweldarbossdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001A0: jal         0x800DA298
    // 0x808001A4: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001A4: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_0:
    // 0x808001A8: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001AC: beq         $a0, $zero, L_808001E0
    if (ctx->r4 == 0) {
        // 0x808001B0: nop
    
            goto L_808001E0;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x800DA298
    // 0x808001B8: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808001B8: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_1:
    // 0x808001BC: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808001C0: beq         $a0, $zero, L_808001E0
    if (ctx->r4 == 0) {
        // 0x808001C4: nop
    
            goto L_808001E0;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x800F54E4
    // 0x808001CC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808001CC: nop

    after_2:
    // 0x808001D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D4: jal         0x800F64A4
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001DC: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_808001E0:
    // 0x808001E0: bnel        $a0, $zero, L_808001FC
    if (ctx->r4 != 0) {
        // 0x808001E4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808001E8: jal         0x80088848
    // 0x808001EC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x808001EC: nop

    after_4:
    // 0x808001F0: beql        $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808001F4: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80800208;
    }
    goto skip_1;
    // 0x808001F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    skip_1:
    // 0x808001F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808001FC:
    // 0x808001FC: jal         0x80101FDC
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800204: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800208:
    // 0x80800208: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080020C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800210: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800214: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080021C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800220: jal         0x80086898
    // 0x80800224: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800224: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    after_6:
    // 0x80800228: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x8080022C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800254;
    }
    // 0x8080022C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: jal         0x800868A8
    // 0x80800234: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800234: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x80800238: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x8080023C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800240: jal         0x800868B0
    // 0x80800244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80800248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080024C: jal         0x800868C0
    // 0x80800250: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x80800250: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
L_80800254:
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

    // 0x80800264: nop

    // 0x80800268: nop

    // 0x8080026C: nop

;}
RECOMP_FUNC void func_8080073C_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080073C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800740: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800744: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800748: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080074C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800750: beq         $a1, $at, L_8080088C
    if (ctx->r5 == ctx->r1) {
        // 0x80800754: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_8080088C;
    }
    // 0x80800754: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800758: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080075C: beq         $a1, $at, L_80800864
    if (ctx->r5 == ctx->r1) {
        // 0x80800760: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800864;
    }
    // 0x80800760: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800764: bne         $a1, $at, L_808008DC
    if (ctx->r5 != ctx->r1) {
        // 0x80800768: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808008DC;
    }
    // 0x80800768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080076C: jal         0x8008FCC8
    // 0x80800770: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_0;
    // 0x80800770: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800774: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800778: bne         $v0, $at, L_8080085C
    if (ctx->r2 != ctx->r1) {
        // 0x8080077C: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_8080085C;
    }
    // 0x8080077C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800780: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800784: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800788: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080078C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800790: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800794: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800798: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8080079C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808007A0: jal         0x800889D0
    // 0x808007A4: nop

    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808007A4: nop

    after_1:
    // 0x808007A8: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x808007AC: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x808007B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808007B4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808007B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C0: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x808007C4: addiu       $a2, $zero, -0xFA
    ctx->r6 = ADD32(0, -0XFA);
    // 0x808007C8: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    // 0x808007CC: jal         0x800BA930
    // 0x808007D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x808007D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x808007D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808007D8: jal         0x800BA22C
    // 0x808007DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x808007DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x808007E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808007E4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2376, 0XA78) << 16);
    // 0x808007E8: addiu       $t8, $t8, 0xA78
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2376, 0XA78));
    // 0x808007EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808007F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808007F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808007F8: jal         0x800BBCB8
    // 0x808007FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808007FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x80800800: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800804: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2376, 0XAB4) << 16);
    // 0x80800808: addiu       $t9, $t9, 0xAB4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2376, 0XAB4));
    // 0x8080080C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800810: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800814: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800818: jal         0x800BBCB8
    // 0x8080081C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x8080081C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_5:
    // 0x80800820: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2376, 0XADC) << 16);
    // 0x80800824: addiu       $a1, $a1, 0xADC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2376, 0XADC));
    // 0x80800828: jal         0x800C4AF0
    // 0x8080082C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800C4AF0(rdram, ctx);
        goto after_6;
    // 0x8080082C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800830: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    // 0x80800834: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x80800838: jal         0x80101180
    // 0x8080083C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x8080083C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800844: jal         0x80086E20
    // 0x80800848: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800848: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x8080084C: jal         0x800DA544
    // 0x80800850: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800850: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    after_9:
    // 0x80800854: b           L_808008DC
    // 0x80800858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x80800858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080085C:
    // 0x8080085C: b           L_808008DC
    // 0x80800860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x80800860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800864:
    // 0x80800864: jal         0x801015D0
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_10;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080086C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800870: jal         0x800DF744
    // 0x80800874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x80800874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800878: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080087C: jal         0x800DF744
    // 0x80800880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x80800880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800884: b           L_808008DC
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080088C:
    // 0x8080088C: jal         0x80101080
    // 0x80800890: nop

    func_80101080(rdram, ctx);
        goto after_13;
    // 0x80800890: nop

    after_13:
    // 0x80800894: jal         0x80106790
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_14;
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8080089C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808008A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008A8: jal         0x80086E00
    // 0x808008AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x808008AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x808008B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808008B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808008B8: jal         0x80086E00
    // 0x808008BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808008BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x808008C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808008C4: jal         0x80086E08
    // 0x808008C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chskeletonexplode_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x808008C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808008CC: jal         0x800FFA88
    // 0x808008D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_18;
    // 0x808008D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
    // 0x808008D4: b           L_808008DC
    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008DC:
    // 0x808008DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808008E0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808008E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void func_800E30E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E30E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E30E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E30E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E30EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E30F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E30F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E30F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800E30FC: jal         0x800AF5FC
    // 0x800E3100: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800AF5FC(rdram, ctx);
        goto after_0;
    // 0x800E3100: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E3104: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800E3108: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800E310C: bnel        $t6, $zero, L_800E31F0
    if (ctx->r14 != 0) {
        // 0x800E3110: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_800E31F0;
    }
    goto skip_0;
    // 0x800E3110: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800E3114: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800E3118: bnel        $t7, $zero, L_800E31F0
    if (ctx->r15 != 0) {
        // 0x800E311C: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_800E31F0;
    }
    goto skip_1;
    // 0x800E311C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800E3120: jal         0x800E2DF0
    // 0x800E3124: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800E2DF0(rdram, ctx);
        goto after_1;
    // 0x800E3124: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_1:
    // 0x800E3128: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E312C: addiu       $a1, $a1, -0x2B90
    ctx->r5 = ADD32(ctx->r5, -0X2B90);
    // 0x800E3130: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x800E3134: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800E3138: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800E313C: beq         $v0, $zero, L_800E314C
    if (ctx->r2 == 0) {
        // 0x800E3140: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800E314C;
    }
    // 0x800E3140: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800E3144: b           L_800E3158
    // 0x800E3148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800E3158;
    // 0x800E3148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800E314C:
    // 0x800E314C: lh          $a0, 0x8($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X8);
    // 0x800E3150: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800E3154: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_800E3158:
    // 0x800E3158: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800E315C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3160: beql        $v0, $zero, L_800E3174
    if (ctx->r2 == 0) {
        // 0x800E3164: lh          $v1, 0xA($t0)
        ctx->r3 = MEM_H(ctx->r8, 0XA);
            goto L_800E3174;
    }
    goto skip_2;
    // 0x800E3164: lh          $v1, 0xA($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XA);
    skip_2:
    // 0x800E3168: b           L_800E317C
    // 0x800E316C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800E317C;
    // 0x800E316C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E3170: lh          $v1, 0xA($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XA);
L_800E3174:
    // 0x800E3174: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800E3178: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_800E317C:
    // 0x800E317C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800E3180: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E3184: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800E3188: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E318C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800E3190: nop

    // 0x800E3194: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E3198: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800E319C: lwc1        $f10, 0x30($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800E31A0: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800E31A4: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800E31A8: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800E31AC: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E31B0: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800E31B4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800E31B8: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800E31BC: nop

    // 0x800E31C0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800E31C4: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800E31C8: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x800E31CC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800E31D0: nop

    // 0x800E31D4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E31D8: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800E31DC: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800E31E0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800E31E4: b           L_800E31FC
    // 0x800E31E8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_800E31FC;
    // 0x800E31E8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800E31EC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_800E31F0:
    // 0x800E31F0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800E31F4: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800E31F8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_800E31FC:
    // 0x800E31FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800E3200: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3204: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800E3208: jal         0x800E2E48
    // 0x800E320C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_800E2E48(rdram, ctx);
        goto after_2;
    // 0x800E320C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x800E3210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3214: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E3218: jr          $ra
    // 0x800E321C: nop

    return;
    // 0x800E321C: nop

;}
RECOMP_FUNC void func_808006EC_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006F8: jal         0x800832E0
    // 0x808006FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800700: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800704: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x8008CB3C
    // 0x80800710: addiu       $a1, $zero, 0x13E
    ctx->r5 = ADD32(0, 0X13E);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800710: addiu       $a1, $zero, 0x13E
    ctx->r5 = ADD32(0, 0X13E);
    after_1:
    // 0x80800714: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800718: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800728: jal         0x8009FFD8
    // 0x8080072C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080072C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800730: lui         $a1, 0xC489
    ctx->r5 = S32(0XC489 << 16);
    // 0x80800734: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800738: jal         0x8009BCB4
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: jal         0x8009BA58
    // 0x80800748: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x80800748: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080074C: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x80800750: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80085338
    // 0x8080075C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x8080075C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80095760
    // 0x80800768: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_set(rdram, ctx);
        goto after_6;
    // 0x80800768: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_6:
    // 0x8080076C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800778: jr          $ra
    // 0x8080077C: nop

    return;
    // 0x8080077C: nop

;}
RECOMP_FUNC void func_800F6EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6EAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6EB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6EB4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6EB8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6EBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6EC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F6EC8: jal         0x8009E674
    // 0x800F6ECC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F6ECC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6ED0: beq         $v0, $zero, L_800F6EEC
    if (ctx->r2 == 0) {
        // 0x800F6ED4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6EEC;
    }
    // 0x800F6ED4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6ED8: jal         0x80084800
    // 0x800F6EDC: nop

    _badrone_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800F6EDC: nop

    after_1:
    // 0x800F6EE0: xori        $t7, $v0, 0x9
    ctx->r15 = ctx->r2 ^ 0X9;
    // 0x800F6EE4: b           L_800F6EF0
    // 0x800F6EE8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
        goto L_800F6EF0;
    // 0x800F6EE8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_800F6EEC:
    // 0x800F6EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6EF0:
    // 0x800F6EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6EF8: jr          $ra
    // 0x800F6EFC: nop

    return;
    // 0x800F6EFC: nop

;}
RECOMP_FUNC void func_80801C64_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C70: jal         0x80800030
    // 0x80801C74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80801C74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801C78: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801C7C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C84: jal         0x8008CDB8
    // 0x80801C88: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x80801C88: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    after_1:
    // 0x80801C8C: jal         0x80800000
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_2;
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C98: jal         0x8009B94C
    // 0x80801C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_3;
    // 0x80801C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CA4: jal         0x8009BA9C
    // 0x80801CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80801CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CB0: jal         0x8009BF5C
    // 0x80801CB4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_5;
    // 0x80801CB4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80801CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CBC: jal         0x8009C4CC
    // 0x80801CC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80801CC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80801CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CC8: jal         0x800A0CF4
    // 0x80801CCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_7;
    // 0x80801CCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80801CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801CDC: jr          $ra
    // 0x80801CE0: nop

    return;
    // 0x80801CE0: nop

;}
RECOMP_FUNC void func_800D1844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D184C: jal         0x800D175C
    // 0x800D1850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D175C(rdram, ctx);
        goto after_0;
    // 0x800D1850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800D1854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D185C: jr          $ra
    // 0x800D1860: nop

    return;
    // 0x800D1860: nop

;}
RECOMP_FUNC void func_80800848_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: jr          $ra
    // 0x8080084C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080084C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80098658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098658: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009865C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098664: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80098668: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009866C: lw          $a3, 0xE0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XE0);
    // 0x80098670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80098674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098678: lwc1        $f6, 0x28($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X28);
    // 0x8009867C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80098680: nop

    // 0x80098684: bc1f        L_800986D4
    if (!c1cs) {
        // 0x80098688: nop
    
            goto L_800986D4;
    }
    // 0x80098688: nop

    // 0x8009868C: lwc1        $f8, 0x1C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80098690: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80098694: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80098698: nop

    // 0x8009869C: bc1f        L_800986D4
    if (!c1cs) {
        // 0x800986A0: nop
    
            goto L_800986D4;
    }
    // 0x800986A0: nop

    // 0x800986A4: lwc1        $f16, 0x20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X20);
    // 0x800986A8: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800986AC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800986B0: nop

    // 0x800986B4: bc1f        L_800986D4
    if (!c1cs) {
        // 0x800986B8: nop
    
            goto L_800986D4;
    }
    // 0x800986B8: nop

    // 0x800986BC: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800986C0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800986C4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800986C8: nop

    // 0x800986CC: bc1tl       L_80098720
    if (c1cs) {
        // 0x800986D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80098720;
    }
    goto skip_0;
    // 0x800986D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800986D4:
    // 0x800986D4: jal         0x800EE7F8
    // 0x800986D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800986D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800986DC: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    // 0x800986E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800986E4: jal         0x800EE7F8
    // 0x800986E8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800986E8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x800986EC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800986F0: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x800986F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800986F8: swc1        $f8, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f8.u32l;
    // 0x800986FC: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x80098700: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80098704: sb          $t7, 0x2D($t8)
    MEM_B(0X2D, ctx->r24) = ctx->r15;
    // 0x80098708: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x8009870C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80098710: sb          $t9, 0x2F($t0)
    MEM_B(0X2F, ctx->r8) = ctx->r25;
    // 0x80098714: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x80098718: sb          $t1, 0x2C($t2)
    MEM_B(0X2C, ctx->r10) = ctx->r9;
    // 0x8009871C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80098720:
    // 0x80098720: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098728: jr          $ra
    // 0x8009872C: nop

    return;
    // 0x8009872C: nop

;}
RECOMP_FUNC void func_80800CBC_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CC8: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800CCC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800CD0: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80800CD4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80800CD8: sh          $t7, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r15;
    // 0x80800CDC: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80800CE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800CE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CE8: jal         0x8010A828
    // 0x80800CEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8010A828(rdram, ctx);
        goto after_0;
    // 0x80800CEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800CF0: jal         0x800D3E40
    // 0x80800CF4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D3E40(rdram, ctx);
        goto after_1;
    // 0x80800CF4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80800CF8: beq         $v0, $zero, L_80800D14
    if (ctx->r2 == 0) {
        // 0x80800CFC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800D14;
    }
    // 0x80800CFC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800D00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800D04: jal         0x80800930
    // 0x80800D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_2;
    // 0x80800D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800D0C: b           L_80800D48
    // 0x80800D10: nop

        goto L_80800D48;
    // 0x80800D10: nop

L_80800D14:
    // 0x80800D14: addiu       $a0, $zero, 0x344
    ctx->r4 = ADD32(0, 0X344);
    // 0x80800D18: jal         0x800DA298
    // 0x80800D1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800D1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800D20: beq         $v0, $zero, L_80800D3C
    if (ctx->r2 == 0) {
        // 0x80800D24: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800D3C;
    }
    // 0x80800D24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800D28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800D2C: jal         0x80800930
    // 0x80800D30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_4;
    // 0x80800D30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800D34: b           L_80800D48
    // 0x80800D38: nop

        goto L_80800D48;
    // 0x80800D38: nop

L_80800D3C:
    // 0x80800D3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800D40: jal         0x80800930
    // 0x80800D44: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_5;
    // 0x80800D44: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
L_80800D48:
    // 0x80800D48: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1824, 0X12A0) << 16);
    // 0x80800D4C: lh          $t8, 0x12A0($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(1824, 0X12A0));
    // 0x80800D50: addiu       $v1, $zero, 0x9A
    ctx->r3 = ADD32(0, 0X9A);
    // 0x80800D54: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80800D58: beq         $v1, $t8, L_80800D7C
    if (ctx->r3 == ctx->r24) {
        // 0x80800D5C: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(1824, 0X12A0) << 16);
            goto L_80800D7C;
    }
    // 0x80800D5C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1824, 0X12A0) << 16);
    // 0x80800D60: addiu       $t0, $t0, 0x12A0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1824, 0X12A0));
    // 0x80800D64: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80800D68: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
L_80800D6C:
    // 0x80800D6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D70: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800D74: bnel        $v1, $t1, L_80800D6C
    if (ctx->r3 != ctx->r9) {
        // 0x80800D78: lh          $t1, 0x2($v0)
        ctx->r9 = MEM_H(ctx->r2, 0X2);
            goto L_80800D6C;
    }
    goto skip_0;
    // 0x80800D78: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    skip_0:
L_80800D7C:
    // 0x80800D7C: jal         0x800DA298
    // 0x80800D80: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800D80: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_6:
    // 0x80800D84: addiu       $a0, $s0, 0x53E
    ctx->r4 = ADD32(ctx->r16, 0X53E);
    // 0x80800D88: jal         0x800DA3B8
    // 0x80800D8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_7;
    // 0x80800D8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FC0: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FC0);
    return;
    // 0x80082FC4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800170_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800178: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080017C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800180: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800184: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800188: beq         $t6, $at, L_808001AC
    if (ctx->r14 == ctx->r1) {
        // 0x8080018C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001AC;
    }
    // 0x8080018C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800190: beq         $t6, $at, L_808001BC
    if (ctx->r14 == ctx->r1) {
        // 0x80800194: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808001BC;
    }
    // 0x80800194: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800198: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080019C: beql        $t6, $at, L_808001D0
    if (ctx->r14 == ctx->r1) {
        // 0x808001A0: lbu         $a0, 0x79($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X79);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x808001A0: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
    skip_0:
    // 0x808001A4: b           L_8080021C
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080021C;
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001AC:
    // 0x808001AC: jal         0x80800044
    // 0x808001B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800044_chpodiumbankaz(rdram, ctx);
        goto after_0;
    // 0x808001B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808001B4: b           L_8080021C
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080021C;
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: jal         0x80101FDC
    // 0x808001C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808001C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808001C4: b           L_8080021C
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080021C;
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001CC: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
L_808001D0:
    // 0x808001D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808001D4: srl         $t7, $a0, 4
    ctx->r15 = S32(U32(ctx->r4) >> 4);
    // 0x808001D8: jal         0x800F6BE4
    // 0x808001DC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_2;
    // 0x808001DC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x808001E0: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001E4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080020C;
    }
    // 0x808001E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808001E8: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
    // 0x808001EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808001F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001F4: srl         $t8, $a0, 4
    ctx->r24 = S32(U32(ctx->r4) >> 4);
    // 0x808001F8: jal         0x800F7B9C
    // 0x808001FC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_3;
    // 0x808001FC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x80800200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800204: bne         $v0, $at, L_80800218
    if (ctx->r2 != ctx->r1) {
        // 0x80800208: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800218;
    }
    // 0x80800208: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8080020C:
    // 0x8080020C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800210: jal         0x80101FDC
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080021C:
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_80800080_chperspexboxswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080008C: jal         0x80085808
    // 0x80800090: addiu       $a1, $zero, 0x43A
    ctx->r5 = ADD32(0, 0X43A);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800090: addiu       $a1, $zero, 0x43A
    ctx->r5 = ADD32(0, 0X43A);
    after_0:
    // 0x80800094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: jal         0x80085810
    // 0x8080009C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080009C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x808000A0: jal         0x80085818
    // 0x808000A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808000A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808000A8: jal         0x80104E78
    // 0x808000AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80104E78(rdram, ctx);
        goto after_3;
    // 0x808000AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void chminegrilldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2096, 0X190) << 16);
    // 0x8080017C: jr          $ra
    // 0x80800180: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2096, 0X190));
    return;
    // 0x80800180: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2096, 0X190));
;}
RECOMP_FUNC void _bsbshock_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B38: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B38);
    return;
    // 0x80082B3C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chicestationbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1220, 0X2C8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1220, 0X2C8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1220, 0X2C8));
;}
RECOMP_FUNC void func_800C99F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C99F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C99F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C99F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C99FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9A00: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800C9A04: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800C9A08: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800C9A0C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800C9A10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C9A14: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800C9A18: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    // 0x800C9A1C: jal         0x800C4244
    // 0x800C9A20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4244(rdram, ctx);
        goto after_0;
    // 0x800C9A20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800C9A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9A28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9A2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9A30: jr          $ra
    // 0x800C9A34: nop

    return;
    // 0x800C9A34: nop

;}
RECOMP_FUNC void func_80800000_fxfontstring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80800004: beq         $t6, $zero, L_8080001C
    if (ctx->r14 == 0) {
        // 0x80800008: nop
    
            goto L_8080001C;
    }
    // 0x80800008: nop

    // 0x8080000C: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_80800010:
    // 0x80800010: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800014: bnel        $t7, $zero, L_80800010
    if (ctx->r15 != 0) {
        // 0x80800018: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_80800010;
    }
    goto skip_0;
    // 0x80800018: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_8080001C:
    // 0x8080001C: jr          $ra
    // 0x80800020: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80800020: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void bskaztorpedo_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801688: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080168C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X18A4) << 16);
    // 0x80801690: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801694: jr          $ra
    // 0x80801698: lw          $v0, 0x18A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X18A4));
    return;
    // 0x80801698: lw          $v0, 0x18A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X18A4));
;}
RECOMP_FUNC void func_80800E6C_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800E7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800E80: lw          $a3, 0x28($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X28);
    // 0x80800E84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E8C: beq         $a3, $zero, L_80800EB8
    if (ctx->r7 == 0) {
        // 0x80800E90: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_80800EB8;
    }
    // 0x80800E90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800E94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E98: beq         $a3, $at, L_80800EC0
    if (ctx->r7 == ctx->r1) {
        // 0x80800E9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800EC0;
    }
    // 0x80800E9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800EA0: beq         $a3, $at, L_80800F1C
    if (ctx->r7 == ctx->r1) {
        // 0x80800EA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F1C;
    }
    // 0x80800EA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800EA8: beq         $a3, $at, L_80800EC0
    if (ctx->r7 == ctx->r1) {
        // 0x80800EAC: nop
    
            goto L_80800EC0;
    }
    // 0x80800EAC: nop

    // 0x80800EB0: b           L_80800F2C
    // 0x80800EB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F2C;
    // 0x80800EB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EB8:
    // 0x80800EB8: jal         0x800856B0
    // 0x80800EBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800EBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800EC0:
    // 0x80800EC0: jal         0x800856E0
    // 0x80800EC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800EC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800EC8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800ECC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800ED0: addiu       $at, $zero, 0x360
    ctx->r1 = ADD32(0, 0X360);
    // 0x80800ED4: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80800ED8: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x80800EDC: bne         $t9, $at, L_80800EF0
    if (ctx->r25 != ctx->r1) {
        // 0x80800EE0: sw          $t6, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r14;
            goto L_80800EF0;
    }
    // 0x80800EE0: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80800EE4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1036, 0X12A8) << 16);
    // 0x80800EE8: b           L_80800EF8
    // 0x80800EEC: addiu       $a3, $a3, 0x12A8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1036, 0X12A8));
        goto L_80800EF8;
    // 0x80800EEC: addiu       $a3, $a3, 0x12A8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1036, 0X12A8));
L_80800EF0:
    // 0x80800EF0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1036, 0X12B8) << 16);
    // 0x80800EF4: addiu       $a3, $a3, 0x12B8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1036, 0X12B8));
L_80800EF8:
    // 0x80800EF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800EFC: jal         0x80088090
    // 0x80800F00: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800F00: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800F04: jal         0x80088098
    // 0x80800F08: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800F08: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800F0C: jal         0x800880A0
    // 0x80800F10: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800F10: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800F14: jal         0x800880B8
    // 0x80800F18: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800F18: nop

    after_5:
L_80800F1C:
    // 0x80800F1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800F20: jal         0x800856D8
    // 0x80800F24: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800F24: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F2C:
    // 0x80800F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F34: jr          $ra
    // 0x80800F38: nop

    return;
    // 0x80800F38: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860C0: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x800860C0);
    return;
    // 0x800860C4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void mlwave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80800004: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800008: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080000C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800010: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x80800014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080001C: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    // 0x80800020: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x80800024: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x80800028: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8080002C: bc1t        L_80800048
    if (c1cs) {
        // 0x80800030: swc1        $f4, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
            goto L_80800048;
    }
    // 0x80800030: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x80800034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2974, 0X410) << 16);
    // 0x80800038: lwc1        $f8, 0x410($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2974, 0X410));
    // 0x8080003C: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800040: b           L_8080004C
    // 0x80800044: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
        goto L_8080004C;
    // 0x80800044: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_80800048:
    // 0x80800048: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
L_8080004C:
    // 0x8080004C: jr          $ra
    // 0x80800050: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80800050: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BA8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BA8);
    return;
    // 0x80089BAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chtiptup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F20: syscall     260
    recomp_syscall_handler(rdram, ctx, 0x80085F20);
    return;
    // 0x80085F24: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800000_chgate1doors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800010: bne         $a1, $at, L_8080008C
    if (ctx->r5 != ctx->r1) {
        // 0x80800014: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080008C;
    }
    // 0x80800014: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800018: jal         0x80106790
    // 0x8080001C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080001C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800020: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800028: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x8080002C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80800030: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800034: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80800038: beql        $at, $zero, L_8080004C
    if (ctx->r1 == 0) {
        // 0x8080003C: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x8080003C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800040: jal         0x80103110
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800048: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8080004C:
    // 0x8080004C: lhu         $t1, 0x72($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X72);
    // 0x80800050: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80800054: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800058: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8080005C: beq         $at, $zero, L_8080006C
    if (ctx->r1 == 0) {
        // 0x80800060: nop
    
            goto L_8080006C;
    }
    // 0x80800060: nop

    // 0x80800064: jal         0x80103110
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080006C:
    // 0x8080006C: jal         0x8010A570
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800074: jal         0x8010A570
    // 0x80800078: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800078: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080007C: jal         0x800DA544
    // 0x80800080: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800080: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_5:
    // 0x80800084: b           L_80800094
    // 0x80800088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800094;
    // 0x80800088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080008C:
    // 0x8080008C: b           L_80800094
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
