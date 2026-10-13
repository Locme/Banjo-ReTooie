#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F1418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1418: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F141C: beq         $at, $zero, L_800F142C
    if (ctx->r1 == 0) {
        // 0x800F1420: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800F142C;
    }
    // 0x800F1420: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800F1424: jr          $ra
    // 0x800F1428: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800F1428: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800F142C:
    // 0x800F142C: jr          $ra
    // 0x800F1430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F1430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800714_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800718: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080071C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800724: beq         $a1, $at, L_80800818
    if (ctx->r5 == ctx->r1) {
        // 0x80800728: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800818;
    }
    // 0x80800728: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080072C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800730: beq         $a1, $at, L_80800748
    if (ctx->r5 == ctx->r1) {
        // 0x80800734: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800748;
    }
    // 0x80800734: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800738: beq         $a1, $at, L_808007F4
    if (ctx->r5 == ctx->r1) {
        // 0x8080073C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808007F4;
    }
    // 0x8080073C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800740: b           L_80800854
    // 0x80800744: nop

        goto L_80800854;
    // 0x80800744: nop

L_80800748:
    // 0x80800748: jal         0x800F54E4
    // 0x8080074C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080074C: nop

    after_0:
    // 0x80800750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800754: jal         0x800F64A4
    // 0x80800758: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800758: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8080075C: beql        $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x80800760: lw          $t1, 0x74($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X74);
            goto L_808007C0;
    }
    goto skip_0;
    // 0x80800760: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x80800764: jal         0x800DA298
    // 0x80800768: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800768: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_2:
    // 0x8080076C: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800770: nop
    
            goto L_808007EC;
    }
    // 0x80800770: nop

    // 0x80800774: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080077C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800780: bne         $t7, $at, L_808007EC
    if (ctx->r15 != ctx->r1) {
        // 0x80800784: nop
    
            goto L_808007EC;
    }
    // 0x80800784: nop

    // 0x80800788: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800794: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800798: jal         0x80103110
    // 0x8080079C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x8080079C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_3:
    // 0x808007A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007A8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x808007AC: jal         0x80085708
    // 0x808007B0: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808007B0: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    after_4:
    // 0x808007B4: b           L_80800854
    // 0x808007B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800854;
    // 0x808007B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808007BC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
L_808007C0:
    // 0x808007C0: addiu       $a1, $zero, 0x1354
    ctx->r5 = ADD32(0, 0X1354);
    // 0x808007C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808007C8: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x808007CC: bltz        $t3, L_808007EC
    if (SIGNED(ctx->r11) < 0) {
        // 0x808007D0: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_808007EC;
    }
    // 0x808007D0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808007D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007D8: jal         0x8008A208
    // 0x808007DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808007DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x808007E0: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x808007E4: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x808007E8: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
L_808007EC:
    // 0x808007EC: b           L_80800854
    // 0x808007F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800854;
    // 0x808007F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007F4:
    // 0x808007F4: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x80800800: jal         0x80102424
    // 0x80800804: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800804: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_6:
    // 0x80800808: jal         0x80102204
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102204(rdram, ctx);
        goto after_7;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800810: b           L_80800854
    // 0x80800814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800854;
    // 0x80800814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800818:
    // 0x80800818: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8080081C: bne         $a2, $at, L_8080084C
    if (ctx->r6 != ctx->r1) {
        // 0x80800820: nop
    
            goto L_8080084C;
    }
    // 0x80800820: nop

    // 0x80800824: jal         0x80085710
    // 0x80800828: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_8;
    // 0x80800828: nop

    after_8:
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800830: jal         0x80102424
    // 0x80800834: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800834: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800838: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    // 0x8080083C: jal         0x800887D8
    // 0x80800840: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800840: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x80800844: b           L_80800854
    // 0x80800848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800854;
    // 0x80800848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080084C:
    // 0x8080084C: b           L_80800854
    // 0x80800850: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800854;
    // 0x80800850: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800854:
    // 0x80800854: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800858: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080085C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800860: jr          $ra
    // 0x80800864: nop

    return;
    // 0x80800864: nop

;}
RECOMP_FUNC void func_80110A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80110A70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80110A74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80110A78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80110A7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80110A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110A84: jal         0x800A516C
    // 0x80110A88: addiu       $a2, $a2, 0x74
    ctx->r6 = ADD32(ctx->r6, 0X74);
    func_800A516C(rdram, ctx);
        goto after_0;
    // 0x80110A88: addiu       $a2, $a2, 0x74
    ctx->r6 = ADD32(ctx->r6, 0X74);
    after_0:
    // 0x80110A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110A94: jr          $ra
    // 0x80110A98: nop

    return;
    // 0x80110A98: nop

;}
RECOMP_FUNC void chlavaarchgrill3switches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2036, 0X238) << 16);
    // 0x80800180: jr          $ra
    // 0x80800184: addiu       $v0, $v0, 0x238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X238));
    return;
    // 0x80800184: addiu       $v0, $v0, 0x238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X238));
;}
RECOMP_FUNC void func_800B270C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B270C: jr          $ra
    // 0x800B2710: lh          $v0, 0xA($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XA);
    return;
    // 0x800B2710: lh          $v0, 0xA($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XA);
;}
RECOMP_FUNC void func_800D8FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D8FF0: jr          $ra
    // 0x800D8FF4: lw          $v0, -0x389C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X389C);
    return;
    // 0x800D8FF4: lw          $v0, -0x389C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X389C);
;}
RECOMP_FUNC void func_800CEAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEAD8: jal         0x800CEA60
    // 0x800CEADC: nop

    func_800CEA60(rdram, ctx);
        goto after_0;
    // 0x800CEADC: nop

    after_0:
    // 0x800CEAE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CEAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CEAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEAEC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800CEAF0: nop

    // 0x800CEAF4: bc1f        L_800CEB00
    if (!c1cs) {
        // 0x800CEAF8: nop
    
            goto L_800CEB00;
    }
    // 0x800CEAF8: nop

    // 0x800CEAFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CEB00:
    // 0x800CEB00: jr          $ra
    // 0x800CEB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CEB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009D7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D7A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D7A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D7AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009D7B0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009D7B4: jal         0x800DC178
    // 0x8009D7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8009D7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009D7BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009D7C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D7C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009D7C8: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009D7CC: addiu       $a3, $zero, 0x61A8
    ctx->r7 = ADD32(0, 0X61A8);
    // 0x8009D7D0: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8009D7D4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009D7D8: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8009D7DC: jal         0x8009DF18
    // 0x8009D7E0: lh          $a1, -0x6DF8($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6DF8);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x8009D7E0: lh          $a1, -0x6DF8($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6DF8);
    after_1:
    // 0x8009D7E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009D7E8: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8009D7EC: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x8009D7F0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009D7F4: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x8009D7F8: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8009D7FC: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x8009D800: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8009D804: bnel        $at, $zero, L_8009D814
    if (ctx->r1 != 0) {
        // 0x8009D808: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009D814;
    }
    goto skip_0;
    // 0x8009D808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8009D80C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8009D810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009D814:
    // 0x8009D814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D818: jr          $ra
    // 0x8009D81C: nop

    return;
    // 0x8009D81C: nop

;}
RECOMP_FUNC void func_800AA3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA3B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AA3BC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AA3C0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AA3C4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AA3C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AA3CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AA3D0: beq         $a0, $zero, L_800AA4B0
    if (ctx->r4 == 0) {
        // 0x800AA3D4: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800AA4B0;
    }
    // 0x800AA3D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AA3D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA3DC: addiu       $s0, $t6, 0x7938
    ctx->r16 = ADD32(ctx->r14, 0X7938);
    // 0x800AA3E0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800AA3E4: addiu       $s4, $s4, 0x7968
    ctx->r20 = ADD32(ctx->r20, 0X7968);
    // 0x800AA3E8: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x800AA3EC: addiu       $s5, $a1, 0x18
    ctx->r21 = ADD32(ctx->r5, 0X18);
    // 0x800AA3F0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
L_800AA3F4:
    // 0x800AA3F4: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x800AA3F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800AA3FC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800AA400: addu        $s1, $t8, $s5
    ctx->r17 = ADD32(ctx->r24, ctx->r21);
    // 0x800AA404: jal         0x800EE88C
    // 0x800AA408: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800AA408: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800AA40C: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x800AA410: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800AA414: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x800AA418: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800AA41C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800AA420: bgez        $t9, L_800AA438
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AA424: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AA438;
    }
    // 0x800AA424: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA428: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA42C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA430: nop

    // 0x800AA434: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800AA438:
    // 0x800AA438: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800AA43C: lbu         $t0, 0xD($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XD);
    // 0x800AA440: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA444: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800AA448: bgez        $t0, L_800AA45C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA44C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800AA45C;
    }
    // 0x800AA44C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA450: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA454: nop

    // 0x800AA458: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800AA45C:
    // 0x800AA45C: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x800AA460: lbu         $t1, 0xE($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XE);
    // 0x800AA464: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA468: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800AA46C: bgez        $t1, L_800AA480
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800AA470: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AA480;
    }
    // 0x800AA470: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA478: nop

    // 0x800AA47C: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800AA480:
    // 0x800AA480: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x800AA484: lbu         $t2, 0xF($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XF);
    // 0x800AA488: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA48C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800AA490: bgez        $t2, L_800AA4A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800AA494: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800AA4A4;
    }
    // 0x800AA494: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA498: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA49C: nop

    // 0x800AA4A0: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_800AA4A4:
    // 0x800AA4A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AA4A8: bne         $s0, $s4, L_800AA3F4
    if (ctx->r16 != ctx->r20) {
        // 0x800AA4AC: swc1        $f18, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
            goto L_800AA3F4;
    }
    // 0x800AA4AC: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_800AA4B0:
    // 0x800AA4B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA4B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AA4B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AA4BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA4C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AA4C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800AA4C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800AA4CC: jr          $ra
    // 0x800AA4D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AA4D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801030_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801034: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801038: beq         $a1, $at, L_80801098
    if (ctx->r5 == ctx->r1) {
        // 0x8080103C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801098;
    }
    // 0x8080103C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801040: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801044: beq         $a1, $at, L_80801088
    if (ctx->r5 == ctx->r1) {
        // 0x80801048: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80801088;
    }
    // 0x80801048: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080104C: bne         $a1, $at, L_808010C8
    if (ctx->r5 != ctx->r1) {
        // 0x80801050: nop
    
            goto L_808010C8;
    }
    // 0x80801050: nop

    // 0x80801054: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080105C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801060: bne         $t7, $at, L_80801078
    if (ctx->r15 != ctx->r1) {
        // 0x80801064: nop
    
            goto L_80801078;
    }
    // 0x80801064: nop

    // 0x80801068: jal         0x80800E58
    // 0x8080106C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_0;
    // 0x8080106C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80801070: b           L_808010D4
    // 0x80801074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010D4;
    // 0x80801074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801078:
    // 0x80801078: jal         0x80800E58
    // 0x8080107C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_1;
    // 0x8080107C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80801080: b           L_808010D4
    // 0x80801084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010D4;
    // 0x80801084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801088:
    // 0x80801088: jal         0x80800E58
    // 0x8080108C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_2;
    // 0x8080108C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80801090: b           L_808010D4
    // 0x80801094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010D4;
    // 0x80801094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801098:
    // 0x80801098: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8080109C: bne         $a2, $at, L_808010C0
    if (ctx->r6 != ctx->r1) {
        // 0x808010A0: nop
    
            goto L_808010C0;
    }
    // 0x808010A0: nop

    // 0x808010A4: jal         0x80085710
    // 0x808010A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x808010A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x808010AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808010B0: jal         0x80800E58
    // 0x808010B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x808010B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x808010B8: b           L_808010D4
    // 0x808010BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808010D4;
    // 0x808010BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808010C0:
    // 0x808010C0: b           L_808010D4
    // 0x808010C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808010D4;
    // 0x808010C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808010C8:
    // 0x808010C8: b           L_808010D4
    // 0x808010CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808010D4;
    // 0x808010CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808010D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010D4:
    // 0x808010D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010DC: jr          $ra
    // 0x808010E0: nop

    return;
    // 0x808010E0: nop

;}
RECOMP_FUNC void func_80800754_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080075C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800760: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XE14) << 16);
    // 0x80800764: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(936, 0XBC0) << 16);
    // 0x80800768: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8080076C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800770: addiu       $a3, $a3, 0xBC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(936, 0XBC0));
    // 0x80800774: addiu       $a2, $a2, 0xE14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XE14));
    // 0x80800778: jal         0x8008A1F0
    // 0x8080077C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x8080077C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800780: beq         $v0, $zero, L_80800790
    if (ctx->r2 == 0) {
        // 0x80800784: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800790;
    }
    // 0x80800784: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800788: jal         0x80090734
    // 0x8080078C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_1;
    // 0x8080078C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80800790:
    // 0x80800790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800798: jr          $ra
    // 0x8080079C: nop

    return;
    // 0x8080079C: nop

;}
RECOMP_FUNC void func_80801448_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080144C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801450: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801454: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801458: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080145C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801460: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801464: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801468: jal         0x80100094
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801470: lh          $v1, 0x84($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X84);
    // 0x80801474: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x80801478: addiu       $t7, $t7, 0x25C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x8080147C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80801480: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80801484: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801488: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8080148C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80801490: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80801494: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801498: beq         $s5, $t9, L_808014F4
    if (ctx->r21 == ctx->r25) {
        // 0x8080149C: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_808014F4;
    }
    // 0x8080149C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x808014A0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x808014A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808014A8: addu        $s1, $t0, $t7
    ctx->r17 = ADD32(ctx->r8, ctx->r15);
    // 0x808014AC: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x808014B0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x808014B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x808014B8: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
L_808014BC:
    // 0x808014BC: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x808014C0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x808014C4: addu        $a0, $s2, $t2
    ctx->r4 = ADD32(ctx->r18, ctx->r10);
    // 0x808014C8: bnel        $s3, $t1, L_808014E8
    if (ctx->r19 != ctx->r9) {
        // 0x808014CC: lh          $v0, 0x2($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X2);
            goto L_808014E8;
    }
    goto skip_0;
    // 0x808014CC: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    skip_0:
    // 0x808014D0: jal         0x800D9078
    // 0x808014D4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808014D4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x808014D8: beql        $v0, $zero, L_808014E8
    if (ctx->r2 == 0) {
        // 0x808014DC: lh          $v0, 0x2($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X2);
            goto L_808014E8;
    }
    goto skip_1;
    // 0x808014DC: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    skip_1:
    // 0x808014E0: sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // 0x808014E4: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
L_808014E8:
    // 0x808014E8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808014EC: bnel        $s5, $v0, L_808014BC
    if (ctx->r21 != ctx->r2) {
        // 0x808014F0: addu        $s0, $s2, $v0
        ctx->r16 = ADD32(ctx->r18, ctx->r2);
            goto L_808014BC;
    }
    goto skip_2;
    // 0x808014F0: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
    skip_2:
L_808014F4:
    // 0x808014F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808014F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808014FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801500: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801504: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801508: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080150C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801510: jr          $ra
    // 0x80801514: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801514: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800098_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: jal         0x80800000
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chnests(rdram, ctx);
        goto after_0;
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000A8: jal         0x800D3948
    // 0x808000AC: nop

    func_800D3948(rdram, ctx);
        goto after_1;
    // 0x808000AC: nop

    after_1:
    // 0x808000B0: bnel        $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000DC;
    }
    goto skip_0;
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000B8: jal         0x800F54E4
    // 0x808000BC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000BC: nop

    after_2:
    // 0x808000C0: jal         0x800F7150
    // 0x808000C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F7150(rdram, ctx);
        goto after_3;
    // 0x808000C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808000C8: beql        $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000DC;
    }
    goto skip_1;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000D0: jal         0x808002E0
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E0_chnests(rdram, ctx);
        goto after_4;
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000DC:
    // 0x808000DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_800DA048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA048: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DA04C: jr          $ra
    // 0x800DA050: sw          $zero, -0x4670($at)
    MEM_W(-0X4670, ctx->r1) = 0;
    return;
    // 0x800DA050: sw          $zero, -0x4670($at)
    MEM_W(-0X4670, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800720_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080072C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800734: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80800738: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8080073C: bne         $t7, $zero, L_808007A4
    if (ctx->r15 != 0) {
        // 0x80800740: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_808007A4;
    }
    // 0x80800740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800744: jal         0x800856B0
    // 0x80800748: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800748: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8080074C: jal         0x800856E0
    // 0x80800750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800754: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1708, 0X880) << 16);
    // 0x80800758: addiu       $a1, $a1, 0x880
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1708, 0X880));
    // 0x8080075C: jal         0x800856E8
    // 0x80800760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800764: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1708, 0X890) << 16);
    // 0x80800768: addiu       $a1, $a1, 0x890
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1708, 0X890));
    // 0x8080076C: jal         0x800856F0
    // 0x80800770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800778: jal         0x800856F8
    // 0x8080077C: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    _capod_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080077C: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800780: jal         0x800880B8
    // 0x80800784: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800784: nop

    after_5:
    // 0x80800788: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080078C: jal         0x800856D8
    // 0x80800790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800794: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800798: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x8080079C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808007A0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_808007A4:
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007B0: jr          $ra
    // 0x808007B4: nop

    return;
    // 0x808007B4: nop

;}
RECOMP_FUNC void func_800DF818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF818: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF81C: jr          $ra
    // 0x800DF820: sw          $a0, -0x369C($at)
    MEM_W(-0X369C, ctx->r1) = ctx->r4;
    return;
    // 0x800DF820: sw          $a0, -0x369C($at)
    MEM_W(-0X369C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80801E90_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801E9C: jal         0x800F54E4
    // 0x80801EA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801EA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801EA4: jal         0x800F5EF8
    // 0x80801EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x80801EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801EB0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801EB4: jal         0x8010FFB0
    // 0x80801EB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8010FFB0(rdram, ctx);
        goto after_2;
    // 0x80801EB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80801EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801EC4: jr          $ra
    // 0x80801EC8: nop

    return;
    // 0x80801EC8: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DE0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DE0);
    return;
    // 0x80087DE4: addi        $t0, $zero, 0xA4
    ctx->r8 = ADD32(0, 0XA4);
;}
RECOMP_FUNC void func_80800468_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800470: jal         0x80100094
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800478: jal         0x80088FA8
    // 0x8080047C: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080047C: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    after_1:
    // 0x80800480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800488: jr          $ra
    // 0x8080048C: nop

    return;
    // 0x8080048C: nop

;}
RECOMP_FUNC void func_808002CC_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D4: jal         0x800C8A98
    // 0x808002D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x808002D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E4: jal         0x800C8CB8
    // 0x808002E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x808002E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002EC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1492, 0X600) << 16);
    // 0x808002F0: addiu       $a1, $a1, 0x600
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1492, 0X600));
    // 0x808002F4: jal         0x800C8E84
    // 0x808002F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x808002F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808002FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800300: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80800304: jal         0x800C8E54
    // 0x80800308: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800C8E54(rdram, ctx);
        goto after_3;
    // 0x80800308: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_3:
    // 0x8080030C: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800310: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800314: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: jal         0x800863E8
    // 0x8080031C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080031C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800520: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(144, 0X8FC) << 16);
    // 0x80800524: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800528: jr          $ra
    // 0x8080052C: lw          $v0, 0x8FC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X8FC));
    return;
    // 0x8080052C: lw          $v0, 0x8FC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X8FC));
;}
RECOMP_FUNC void func_80800234_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800244: jal         0x8009E74C
    // 0x80800248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8080024C: bnel        $v0, $zero, L_808002E0
    if (ctx->r2 != 0) {
        // 0x80800250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002E0;
    }
    goto skip_0;
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800254: jal         0x80084420
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baalarm_free(rdram, ctx);
        goto after_1;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080025C: jal         0x8009E474
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_2;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800264: jal         0x8009EF60
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_3;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x800A0CF4
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x800A0CE8
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_5;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: jal         0x800A0DD0
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DD0(rdram, ctx);
        goto after_6;
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x8009BF5C
    // 0x80800298: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x80800298: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x8009C4CC
    // 0x808002A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_8;
    // 0x808002A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80091788
    // 0x808002B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_9;
    // 0x808002B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808002B4: jal         0x800C77DC
    // 0x808002B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_10;
    // 0x808002B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002C4: jal         0x800852E8
    // 0x808002C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_incrementBy(rdram, ctx);
        goto after_11;
    // 0x808002C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_11:
    // 0x808002CC: jal         0x808000C8
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_12;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002D4: jal         0x800832E8
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E0:
    // 0x808002E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_800D8FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8FA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D8FAC: jal         0x800F0D90
    // 0x800D8FB0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800F0D90(rdram, ctx);
        goto after_0;
    // 0x800D8FB0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_0:
    // 0x800D8FB4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D8FB8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D8FBC: addiu       $v1, $v1, -0x389C
    ctx->r3 = ADD32(ctx->r3, -0X389C);
    // 0x800D8FC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D8FC4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800D8FC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8FCC: lwc1        $f8, 0x5D18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D18);
    // 0x800D8FD0: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D8FD4: jal         0x800D8F50
    // 0x800D8FD8: nop

    func_800D8F50(rdram, ctx);
        goto after_1;
    // 0x800D8FD8: nop

    after_1:
    // 0x800D8FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8FE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8FE4: jr          $ra
    // 0x800D8FE8: nop

    return;
    // 0x800D8FE8: nop

;}
RECOMP_FUNC void _chfootwear_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087768: syscall     620
    recomp_syscall_handler(rdram, ctx, 0x80087768);
    return;
    // 0x8008776C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080141C_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080141C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801424: jal         0x800F54E4
    // 0x80801428: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801428: nop

    after_0:
    // 0x8080142C: jal         0x800F5FE0
    // 0x80801430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5FE0(rdram, ctx);
        goto after_1;
    // 0x80801430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080143C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801440: jr          $ra
    // 0x80801444: nop

    return;
    // 0x80801444: nop

;}
RECOMP_FUNC void func_80802730_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802738: jal         0x80106790
    // 0x8080273C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080273C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802740: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802744: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802748: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x8080274C: jal         0x80087BE0
    // 0x80802750: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x80802750: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    after_1:
    // 0x80802754: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080275C: jal         0x80087B20
    // 0x80802760: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80802760: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_2:
    // 0x80802764: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80802768: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080276C: sw          $t8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r24;
    // 0x80802770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802778: jr          $ra
    // 0x8080277C: nop

    return;
    // 0x8080277C: nop

;}
RECOMP_FUNC void func_808030D0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808030D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808030D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808030DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808030E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808030E4: jal         0x80100094
    // 0x808030E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808030E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808030EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808030F0: jal         0x80106790
    // 0x808030F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808030F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808030F8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808030FC: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    // 0x80803100: jal         0x80089AC8
    // 0x80803104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80803104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80803108: beq         $v0, $zero, L_80803160
    if (ctx->r2 == 0) {
        // 0x8080310C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80803160;
    }
    // 0x8080310C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80803110: jal         0x800F5F24
    // 0x80803114: lbu         $a0, 0x20($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X20);
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x80803114: lbu         $a0, 0x20($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X20);
    after_3:
    // 0x80803118: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8080311C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803120: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80803124: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80803128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080312C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803130: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80803134: jal         0x800F10B4
    // 0x80803138: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80803138: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8080313C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803140: lbu         $a0, 0x20($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X20);
    // 0x80803144: jal         0x800F4F98
    // 0x80803148: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_5;
    // 0x80803148: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8080314C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80803150: jal         0x80089AF0
    // 0x80803154: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80803154: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    after_6:
    // 0x80803158: b           L_808031C4
    // 0x8080315C: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
        goto L_808031C4;
    // 0x8080315C: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
L_80803160:
    // 0x80803160: jal         0x80089AD8
    // 0x80803164: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80803164: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    after_7:
    // 0x80803168: jal         0x80106790
    // 0x8080316C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x8080316C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80803170: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80803174: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80803178: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080317C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803180: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80803184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803188: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x8080318C: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80803190: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x80803194: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80803198: jal         0x800F10B4
    // 0x8080319C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x8080319C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x808031A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808031A4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808031A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808031AC: nop

    // 0x808031B0: swc1        $f10, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f10.u32l;
    // 0x808031B4: lbu         $a1, 0x20($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X20);
    // 0x808031B8: jal         0x80089AF0
    // 0x808031BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808031BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x808031C0: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
L_808031C4:
    // 0x808031C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808031C8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x808031CC: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x808031D0: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x808031D4: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
    // 0x808031D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4C98) << 16);
    // 0x808031DC: sb          $t0, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r8;
    // 0x808031E0: addiu       $a2, $a2, 0x4C98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4C98));
    // 0x808031E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808031EC: jal         0x80089D18
    // 0x808031F0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808031F0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    after_11:
    // 0x808031F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808031F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808031FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803200: jr          $ra
    // 0x80803204: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80803204: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800424_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800430: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800434: jal         0x8008D04C
    // 0x80800438: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x80800438: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080043C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800440: jal         0x8008AF24
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x8008AED4
    // 0x80800450: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800450: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: jal         0x8008B1BC
    // 0x8080045C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080045C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x8008B134
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080046C: jal         0x8008B064
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800478: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080047C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800480: jr          $ra
    // 0x80800484: nop

    return;
    // 0x80800484: nop

;}
RECOMP_FUNC void func_80800A84_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A90: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800A94: addiu       $at, $zero, 0x43B
    ctx->r1 = ADD32(0, 0X43B);
    // 0x80800A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A9C: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80800AA0: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800AA4: beq         $t7, $at, L_80800B1C
    if (ctx->r15 == ctx->r1) {
        // 0x80800AA8: addiu       $at, $zero, 0x43C
        ctx->r1 = ADD32(0, 0X43C);
            goto L_80800B1C;
    }
    // 0x80800AA8: addiu       $at, $zero, 0x43C
    ctx->r1 = ADD32(0, 0X43C);
    // 0x80800AAC: beq         $t7, $at, L_80800AD8
    if (ctx->r15 == ctx->r1) {
        // 0x80800AB0: addiu       $at, $zero, 0x43D
        ctx->r1 = ADD32(0, 0X43D);
            goto L_80800AD8;
    }
    // 0x80800AB0: addiu       $at, $zero, 0x43D
    ctx->r1 = ADD32(0, 0X43D);
    // 0x80800AB4: bne         $t7, $at, L_80800B48
    if (ctx->r15 != ctx->r1) {
        // 0x80800AB8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1300, 0XF88) << 16);
            goto L_80800B48;
    }
    // 0x80800AB8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1300, 0XF88) << 16);
    // 0x80800ABC: addiu       $a0, $a0, 0xF88
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1300, 0XF88));
    // 0x80800AC0: jal         0x80088090
    // 0x80800AC4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800AC4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80800AC8: jal         0x800880A0
    // 0x80800ACC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800ACC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_1:
    // 0x80800AD0: b           L_80800B48
    // 0x80800AD4: nop

        goto L_80800B48;
    // 0x80800AD4: nop

L_80800AD8:
    // 0x80800AD8: jal         0x8010CD28
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_2;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800AE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800AE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AE8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800AEC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800AF0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800AF4: jal         0x800EFA4C
    // 0x80800AF8: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800AF8: nop

    after_3:
    // 0x80800AFC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1300, 0XF98) << 16);
    // 0x80800B00: addiu       $a0, $a0, 0xF98
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1300, 0XF98));
    // 0x80800B04: jal         0x80088090
    // 0x80800B08: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800B08: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80800B0C: jal         0x800880A0
    // 0x80800B10: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800B10: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800B14: b           L_80800B48
    // 0x80800B18: nop

        goto L_80800B48;
    // 0x80800B18: nop

L_80800B1C:
    // 0x80800B1C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800B20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B24: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800B28: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1300, 0XFA8) << 16);
    // 0x80800B2C: addiu       $a0, $a0, 0xFA8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1300, 0XFA8));
    // 0x80800B30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800B34: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800B38: jal         0x80088090
    // 0x80800B3C: nop

    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800B3C: nop

    after_6:
    // 0x80800B40: jal         0x800880A0
    // 0x80800B44: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800B44: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_7:
L_80800B48:
    // 0x80800B48: jal         0x80088098
    // 0x80800B4C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800B4C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800B5C: jr          $ra
    // 0x80800B60: nop

    return;
    // 0x80800B60: nop

;}
RECOMP_FUNC void func_800F739C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F739C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F73A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F73A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F73A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F73AC: jal         0x800C7074
    // 0x800F73B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7074(rdram, ctx);
        goto after_0;
    // 0x800F73B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800F73B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F73B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F73BC: jr          $ra
    // 0x800F73C0: nop

    return;
    // 0x800F73C0: nop

;}
RECOMP_FUNC void func_80800480_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800484: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080048C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800490: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800494: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800498: jal         0x800EE7F8
    // 0x8080049C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080049C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x808004A0: jal         0x800E3980
    // 0x808004A4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x808004A4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x808004A8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808004AC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808004B0: jal         0x800F18FC
    // 0x808004B4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x808004B4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x808004B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808004BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808004C0: jal         0x800EEBF0
    // 0x808004C4: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_800EEBF0(rdram, ctx);
        goto after_3;
    // 0x808004C4: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_3:
    // 0x808004C8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808004CC: jal         0x800EF04C
    // 0x808004D0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x808004D0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x808004D4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004D8: jal         0x800F13C4
    // 0x808004DC: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    func_800F13C4(rdram, ctx);
        goto after_5;
    // 0x808004DC: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x808004E0: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808004E4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004EC: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808004F0: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808004F4: jal         0x80013970
    // 0x808004F8: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x808004F8: nop

    after_6:
    // 0x808004FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5C0) << 16);
    // 0x80800500: lwc1        $f10, 0x5C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5C0));
    // 0x80800504: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800508: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080050C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800510: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800514: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80800518: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080051C: jal         0x800F13C4
    // 0x80800520: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    func_800F13C4(rdram, ctx);
        goto after_7;
    // 0x80800520: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    after_7:
    // 0x80800524: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800528: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080052C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800530: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800534: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800538: jal         0x800138D0
    // 0x8080053C: nop

    func_800138D0(rdram, ctx);
        goto after_8;
    // 0x8080053C: nop

    after_8:
    // 0x80800540: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5C4) << 16);
    // 0x80800544: lwc1        $f16, 0x5C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5C4));
    // 0x80800548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080054C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800550: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800554: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800558: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080055C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800560: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80800564: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800568: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8080056C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800570: jal         0x80087748
    // 0x80800574: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _chbubble_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800574: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80800578: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
    // 0x8080057C: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80800580: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80800584: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800588: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080058C: sb          $t1, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r9;
    // 0x80800590: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800594: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

    // 0x808005A4: nop

    // 0x808005A8: nop

    // 0x808005AC: nop

;}
RECOMP_FUNC void sufade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800004: lw          $t6, 0x7EF4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EF4);
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: bne         $t6, $zero, L_80800038
    if (ctx->r14 != 0) {
        // 0x80800018: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80800038;
    }
    // 0x80800018: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080001C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800024: jal         0x800B2D70
    // 0x80800028: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    vector_new(rdram, ctx);
        goto after_0;
    // 0x80800028: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080002C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800030: sw          $v0, 0x7EF4($at)
    MEM_W(0X7EF4, ctx->r1) = ctx->r2;
    // 0x80800034: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80800038:
    // 0x80800038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080003C: addiu       $a0, $a0, 0x7EF4
    ctx->r4 = ADD32(ctx->r4, 0X7EF4);
    // 0x80800040: jal         0x800B2974
    // 0x80800044: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    vector_push_back(rdram, ctx);
        goto after_1;
    // 0x80800044: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800048: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080004C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800050: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80800054: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80800058: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8080005C: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80800060: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x80800064: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_8008B850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B850: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B854: addiu       $v1, $v1, 0x6CC0
    ctx->r3 = ADD32(ctx->r3, 0X6CC0);
    // 0x8008B858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B85C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B860: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8008B864: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8008B868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B86C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B870: beql        $at, $zero, L_8008B8D0
    if (ctx->r1 == 0) {
        // 0x8008B874: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008B8D0;
    }
    goto skip_0;
    // 0x8008B874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008B878: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_8008B87C:
    // 0x8008B87C: beql        $t6, $zero, L_8008B8C0
    if (ctx->r14 == 0) {
        // 0x8008B880: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B8C0;
    }
    goto skip_1;
    // 0x8008B880: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_1:
    // 0x8008B884: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8008B888: beq         $t7, $zero, L_8008B8B4
    if (ctx->r15 == 0) {
        // 0x8008B88C: nop
    
            goto L_8008B8B4;
    }
    // 0x8008B88C: nop

    // 0x8008B890: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8008B894: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8008B898: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8008B89C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008B8A0: bgtz        $t0, L_8008B8B4
    if (SIGNED(ctx->r8) > 0) {
        // 0x8008B8A4: nop
    
            goto L_8008B8B4;
    }
    // 0x8008B8A4: nop

    // 0x8008B8A8: jal         0x800DFCC0
    // 0x8008B8AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800DFCC0(rdram, ctx);
        goto after_0;
    // 0x8008B8AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_0:
    // 0x8008B8B0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8008B8B4:
    // 0x8008B8B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B8B8: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8008B8BC: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_8008B8C0:
    // 0x8008B8C0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B8C4: bnel        $at, $zero, L_8008B87C
    if (ctx->r1 != 0) {
        // 0x8008B8C8: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_8008B87C;
    }
    goto skip_2;
    // 0x8008B8C8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_2:
    // 0x8008B8CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B8D0:
    // 0x8008B8D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B8D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B8D8: jr          $ra
    // 0x8008B8DC: nop

    return;
    // 0x8008B8DC: nop

;}
RECOMP_FUNC void func_808001E4_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: jal         0x8008E124
    // 0x808001F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E124(rdram, ctx);
        goto after_0;
    // 0x808001F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001F4: beql        $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001F8: addiu       $v0, $zero, 0xBB
        ctx->r2 = ADD32(0, 0XBB);
            goto L_80800210;
    }
    goto skip_0;
    // 0x808001F8: addiu       $v0, $zero, 0xBB
    ctx->r2 = ADD32(0, 0XBB);
    skip_0:
    // 0x808001FC: jal         0x80084740
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badata_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800204: b           L_80800214
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800214;
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080020C: addiu       $v0, $zero, 0xBB
    ctx->r2 = ADD32(0, 0XBB);
L_80800210:
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800214:
    // 0x80800214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_80800058_chjiggybeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080005C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800060: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800064: jr          $ra
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _bsstonehead_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CE8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CE8);
    return;
    // 0x80083CEC: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_80801DB4_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801DB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801DBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801DC0: lw          $v0, 0x178($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X178);
    // 0x80801DC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DC8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80801DCC: beq         $v0, $zero, L_80801EF8
    if (ctx->r2 == 0) {
        // 0x80801DD0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80801EF8;
    }
    // 0x80801DD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801DD4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80801DD8: lw          $a0, 0x168($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X168);
    // 0x80801DDC: bnel        $a0, $zero, L_80801E08
    if (ctx->r4 != 0) {
        // 0x80801DE0: lw          $a1, 0x16C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X16C);
            goto L_80801E08;
    }
    goto skip_0;
    // 0x80801DE0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    skip_0:
    // 0x80801DE4: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801DE8: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x80801DEC: srl         $t8, $t7, 15
    ctx->r24 = S32(U32(ctx->r15) >> 15);
    // 0x80801DF0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80801DF4: jalr        $v0
    // 0x80801DF8: lbu         $a2, 0x116($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X116);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80801DF8: lbu         $a2, 0x116($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X116);
    after_0:
    // 0x80801DFC: b           L_80801E3C
    // 0x80801E00: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_80801E3C;
    // 0x80801E00: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80801E04: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
L_80801E08:
    // 0x80801E08: jal         0x80800000
    // 0x80801E0C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80801E0C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_1:
    // 0x80801E10: beq         $v0, $zero, L_80801E3C
    if (ctx->r2 == 0) {
        // 0x80801E14: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80801E3C;
    }
    // 0x80801E14: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80801E18: lhu         $t3, 0x15E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801E1C: lw          $t9, 0x178($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X178);
    // 0x80801E20: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80801E24: srl         $t4, $t3, 15
    ctx->r12 = S32(U32(ctx->r11) >> 15);
    // 0x80801E28: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80801E2C: lbu         $a2, 0x116($t5)
    ctx->r6 = MEM_BU(ctx->r13, 0X116);
    // 0x80801E30: jalr        $t9
    // 0x80801E34: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80801E34: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    after_2:
    // 0x80801E38: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_80801E3C:
    // 0x80801E3C: bgez        $t2, L_80801E4C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801E40: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_80801E4C;
    }
    // 0x80801E40: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801E44: subu        $t2, $t6, $t2
    ctx->r10 = SUB32(ctx->r14, ctx->r10);
    // 0x80801E48: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80801E4C:
    // 0x80801E4C: bltzl       $t2, L_80801EF8
    if (SIGNED(ctx->r10) < 0) {
        // 0x80801E50: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_80801EF8;
    }
    goto skip_1;
    // 0x80801E50: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_1:
    // 0x80801E54: lhu         $v1, 0x15E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801E58: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
    // 0x80801E5C: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x80801E60: srl         $t7, $v1, 15
    ctx->r15 = S32(U32(ctx->r3) >> 15);
    // 0x80801E64: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80801E68: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80801E6C: lbu         $t3, 0x116($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X116);
    // 0x80801E70: addu        $t9, $s0, $t5
    ctx->r25 = ADD32(ctx->r16, ctx->r13);
    // 0x80801E74: lw          $t6, 0x104($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X104);
    // 0x80801E78: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80801E7C: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x80801E80: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x80801E84: lh          $t8, 0x8($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X8);
    // 0x80801E88: bnel        $t8, $at, L_80801EF8
    if (ctx->r24 != ctx->r1) {
        // 0x80801E8C: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_80801EF8;
    }
    goto skip_2;
    // 0x80801E8C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_2:
    // 0x80801E90: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80801E94: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80801E98: jal         0x80088738
    // 0x80801E9C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801E9C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x80801EA0: lhu         $v1, 0x15E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801EA4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80801EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EAC: srl         $t3, $v1, 15
    ctx->r11 = S32(U32(ctx->r3) >> 15);
    // 0x80801EB0: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x80801EB4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80801EB8: lbu         $t9, 0x116($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X116);
    // 0x80801EBC: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80801EC0: lw          $t8, 0x104($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X104);
    // 0x80801EC4: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x80801EC8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80801ECC: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x80801ED0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80801ED4: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80801ED8: lw          $a2, 0xC($t3)
    ctx->r6 = MEM_W(ctx->r11, 0XC);
    // 0x80801EDC: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80801EE0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801EE4: jal         0x80800350
    // 0x80801EE8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80800350_gcdialogexec(rdram, ctx);
        goto after_4;
    // 0x80801EE8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_4:
    // 0x80801EEC: b           L_80801EF8
    // 0x80801EF0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
        goto L_80801EF8;
    // 0x80801EF0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80801EF4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80801EF8:
    // 0x80801EF8: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80801EFC: beql        $a0, $zero, L_80802010
    if (ctx->r4 == 0) {
        // 0x80801F00: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802010;
    }
    goto skip_3;
    // 0x80801F00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80801F04: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    // 0x80801F08: jal         0x80800000
    // 0x80801F0C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_5;
    // 0x80801F0C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_5:
    // 0x80801F10: beq         $v0, $zero, L_8080200C
    if (ctx->r2 == 0) {
        // 0x80801F14: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_8080200C;
    }
    // 0x80801F14: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80801F18: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80801F1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801F20: lhu         $t9, 0x18($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X18);
    // 0x80801F24: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x80801F28: beql        $t6, $zero, L_80802010
    if (ctx->r14 == 0) {
        // 0x80801F2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802010;
    }
    goto skip_4;
    // 0x80801F2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80801F30: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80801F34: lhu         $t4, 0x15E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801F38: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x80801F3C: srl         $t8, $t4, 15
    ctx->r24 = S32(U32(ctx->r12) >> 15);
    // 0x80801F40: addu        $t3, $s0, $t8
    ctx->r11 = ADD32(ctx->r16, ctx->r24);
    // 0x80801F44: jal         0x8008A220
    // 0x80801F48: lbu         $a2, 0x116($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X116);
    _subaddiedialog_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x80801F48: lbu         $a2, 0x116($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X116);
    after_6:
    // 0x80801F4C: bgez        $v0, L_80801F60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80801F50: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80801F60;
    }
    // 0x80801F50: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80801F54: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801F58: subu        $t2, $t5, $v0
    ctx->r10 = SUB32(ctx->r13, ctx->r2);
    // 0x80801F5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80801F60:
    // 0x80801F60: bltzl       $t2, L_8080200C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80801F64: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_8080200C;
    }
    goto skip_5;
    // 0x80801F64: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_5:
    // 0x80801F68: lhu         $v1, 0x15E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801F6C: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
    // 0x80801F70: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x80801F74: srl         $t9, $v1, 15
    ctx->r25 = S32(U32(ctx->r3) >> 15);
    // 0x80801F78: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x80801F7C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80801F80: lbu         $t7, 0x116($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X116);
    // 0x80801F84: addu        $t3, $s0, $t8
    ctx->r11 = ADD32(ctx->r16, ctx->r24);
    // 0x80801F88: lw          $t5, 0x104($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X104);
    // 0x80801F8C: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x80801F90: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x80801F94: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x80801F98: lh          $t6, 0x8($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X8);
    // 0x80801F9C: bnel        $t6, $at, L_8080200C
    if (ctx->r14 != ctx->r1) {
        // 0x80801FA0: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_8080200C;
    }
    goto skip_6;
    // 0x80801FA0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    skip_6:
    // 0x80801FA4: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80801FA8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80801FAC: jal         0x80088738
    // 0x80801FB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801FB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_7:
    // 0x80801FB4: lhu         $v1, 0x15E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X15E);
    // 0x80801FB8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80801FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FC0: srl         $t7, $v1, 15
    ctx->r15 = S32(U32(ctx->r3) >> 15);
    // 0x80801FC4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80801FC8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80801FCC: lbu         $t3, 0x116($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X116);
    // 0x80801FD0: addu        $t9, $s0, $t5
    ctx->r25 = ADD32(ctx->r16, ctx->r13);
    // 0x80801FD4: lw          $t6, 0x104($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X104);
    // 0x80801FD8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80801FDC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80801FE0: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x80801FE4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80801FE8: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x80801FEC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    // 0x80801FF0: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80801FF4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801FF8: jal         0x80800350
    // 0x80801FFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80800350_gcdialogexec(rdram, ctx);
        goto after_8;
    // 0x80801FFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_8:
    // 0x80802000: b           L_8080200C
    // 0x80802004: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
        goto L_8080200C;
    // 0x80802004: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80802008: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8080200C:
    // 0x8080200C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802010:
    // 0x80802010: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802014: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802018: jr          $ra
    // 0x8080201C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x8080201C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void func_80803B48_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B50: jal         0x800F6478
    // 0x80803B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F6478(rdram, ctx);
        goto after_0;
    // 0x80803B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803B58: beq         $v0, $zero, L_80803B70
    if (ctx->r2 == 0) {
        // 0x80803B5C: nop
    
            goto L_80803B70;
    }
    // 0x80803B5C: nop

    // 0x80803B60: jal         0x800F6C5C
    // 0x80803B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6C5C(rdram, ctx);
        goto after_1;
    // 0x80803B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80803B68: bne         $v0, $zero, L_80803B78
    if (ctx->r2 != 0) {
        // 0x80803B6C: nop
    
            goto L_80803B78;
    }
    // 0x80803B6C: nop

L_80803B70:
    // 0x80803B70: b           L_80803BA0
    // 0x80803B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803BA0;
    // 0x80803B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803B78:
    // 0x80803B78: jal         0x800F5628
    // 0x80803B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F5628(rdram, ctx);
        goto after_2;
    // 0x80803B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80803B80: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803B84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803B8C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803B90: nop

    // 0x80803B94: bc1fl       L_80803BA4
    if (!c1cs) {
        // 0x80803B98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803BA4;
    }
    goto skip_0;
    // 0x80803B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803BA0:
    // 0x80803BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803BA4:
    // 0x80803BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803BA8: jr          $ra
    // 0x80803BAC: nop

    return;
    // 0x80803BAC: nop

;}
RECOMP_FUNC void func_80106920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106920: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80106924: lw          $a1, 0x6EE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6EE0);
    // 0x80106928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010692C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106930: bne         $a1, $zero, L_80106940
    if (ctx->r5 != 0) {
        // 0x80106934: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80106940;
    }
    // 0x80106934: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80106938: b           L_80106994
    // 0x8010693C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106994;
    // 0x8010693C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106940:
    // 0x80106940: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80106944: jal         0x800B2928
    // 0x80106948: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x80106948: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010694C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80106950: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106954: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80106958: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010695C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80106960: bltz        $t7, L_80106974
    if (SIGNED(ctx->r15) < 0) {
        // 0x80106964: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_80106974;
    }
    // 0x80106964: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80106968: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010696C: bne         $at, $zero, L_8010697C
    if (ctx->r1 != 0) {
        // 0x80106970: nop
    
            goto L_8010697C;
    }
    // 0x80106970: nop

L_80106974:
    // 0x80106974: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80106978: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
L_8010697C:
    // 0x8010697C: bltz        $a1, L_80106994
    if (SIGNED(ctx->r5) < 0) {
        // 0x80106980: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80106994;
    }
    // 0x80106980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80106984: jal         0x800B28CC
    // 0x80106988: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_at(rdram, ctx);
        goto after_1;
    // 0x80106988: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_1:
    // 0x8010698C: b           L_80106998
    // 0x80106990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106998;
    // 0x80106990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106994:
    // 0x80106994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106998:
    // 0x80106998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010699C: jr          $ra
    // 0x801069A0: nop

    return;
    // 0x801069A0: nop

;}
RECOMP_FUNC void func_80800164_chegggrenade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080016C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800174: jal         0x80100094
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080017C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800180: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800188: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080018C: beq         $t6, $at, L_808001A4
    if (ctx->r14 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001A4;
    }
    // 0x80800190: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800194: beq         $t6, $at, L_80800204
    if (ctx->r14 == ctx->r1) {
        // 0x80800198: nop
    
            goto L_80800204;
    }
    // 0x80800198: nop

    // 0x8080019C: b           L_808002AC
    // 0x808001A0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_808002AC;
    // 0x808001A0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808001A4:
    // 0x808001A4: jal         0x8008A3B8
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001AC: bnel        $v0, $zero, L_808002AC
    if (ctx->r2 != 0) {
        // 0x808001B0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_808002AC;
    }
    goto skip_0;
    // 0x808001B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808001B4: jal         0x800EEEA8
    // 0x808001B8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_2;
    // 0x808001B8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x808001BC: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_808001D4;
    }
    // 0x808001C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C4: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x808001C8: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808001CC: b           L_808002A8
    // 0x808001D0: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_808002A8;
    // 0x808001D0: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_808001D4:
    // 0x808001D4: jal         0x80800000
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chegggrenade(rdram, ctx);
        goto after_3;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001DC: jal         0x8008A3F8
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001E4: jal         0x8008A3E8
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001EC: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_808002A8;
    }
    // 0x808001F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: lbu         $t3, 0x39($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X39);
    // 0x808001F8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x808001FC: b           L_808002A8
    // 0x80800200: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
        goto L_808002A8;
    // 0x80800200: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
L_80800204:
    // 0x80800204: jal         0x8008A3B8
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080020C: bne         $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x80800210: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_808002A8;
    }
    // 0x80800210: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800214: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080021C: lwc1        $f12, 0x30($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80800220: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800224: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x80800228: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8080022C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800230: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x80800234: jal         0x800F10B4
    // 0x80800238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8080023C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800240: jal         0x8008A450
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800248: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x8080024C: nop
    
            goto L_80800258;
    }
    // 0x8080024C: nop

    // 0x80800250: jal         0x8008A430
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_9;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800258:
    // 0x80800258: jal         0x8008A3E0
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800260: beq         $v0, $zero, L_80800278
    if (ctx->r2 == 0) {
        // 0x80800264: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80800278;
    }
    // 0x80800264: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800268: lbu         $t9, 0x39($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X39);
    // 0x8080026C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800270: b           L_808002A8
    // 0x80800274: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
        goto L_808002A8;
    // 0x80800274: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
L_80800278:
    // 0x80800278: jal         0x8008A3D8
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800280: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x80800284: nop
    
            goto L_80800298;
    }
    // 0x80800284: nop

    // 0x80800288: jal         0x8008A348
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800290: b           L_808002AC
    // 0x80800294: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_808002AC;
    // 0x80800294: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800298:
    // 0x80800298: jal         0x80800000
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chegggrenade(rdram, ctx);
        goto after_13;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002A0: jal         0x8008A3F8
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_14;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808002A8:
    // 0x808002A8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808002AC:
    // 0x808002AC: lb          $t3, 0x39($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X39);
    // 0x808002B0: bgezl       $t3, L_808002DC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808002B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002DC;
    }
    goto skip_1;
    // 0x808002B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002B8: lw          $t4, 0x38($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X38);
    // 0x808002BC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808002C0: addiu       $a0, $a0, 0x7210
    ctx->r4 = ADD32(ctx->r4, 0X7210);
    // 0x808002C4: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x808002C8: bltzl       $t5, L_808002DC
    if (SIGNED(ctx->r13) < 0) {
        // 0x808002CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002DC;
    }
    goto skip_2;
    // 0x808002CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808002D0: jal         0x80086D30
    // 0x808002D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808002D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x808002D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002DC:
    // 0x808002DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002E4: jr          $ra
    // 0x808002E8: nop

    return;
    // 0x808002E8: nop

;}
RECOMP_FUNC void func_800D2770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2778: jal         0x800D21D0
    // 0x800D277C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D277C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D2780: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2784: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D2788: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x800D278C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D2790: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800D2794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D279C: jr          $ra
    // 0x800D27A0: nop

    return;
    // 0x800D27A0: nop

;}
RECOMP_FUNC void func_808015F8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801600: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801604: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    // 0x80801608: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
    // 0x8080160C: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x80801610: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801614: jal         0x800880D8
    // 0x80801618: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801618: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_0:
    // 0x8080161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801624: jr          $ra
    // 0x80801628: nop

    return;
    // 0x80801628: nop

;}
RECOMP_FUNC void chquizexitdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2488, 0X190) << 16);
    // 0x80800184: jr          $ra
    // 0x80800188: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2488, 0X190));
    return;
    // 0x80800188: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2488, 0X190));
    // 0x8080018C: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1894) << 16);
    // 0x80800C24: jr          $ra
    // 0x80800C28: addiu       $v0, $v0, 0x1894
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1894));
    return;
    // 0x80800C28: addiu       $v0, $v0, 0x1894
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1894));
;}
RECOMP_FUNC void _chanim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085998: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x80085998);
    return;
    // 0x8008599C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800E38_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E38: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x80800E3C: jr          $ra
    // 0x80800E40: lb          $v0, 0x60($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X60);
    return;
    // 0x80800E40: lb          $v0, 0x60($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X60);
;}
RECOMP_FUNC void chmusicmenu_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1824, 0X15C4) << 16);
    // 0x808010BC: jr          $ra
    // 0x808010C0: addiu       $v0, $v0, 0x15C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X15C4));
    return;
    // 0x808010C0: addiu       $v0, $v0, 0x15C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X15C4));
;}
RECOMP_FUNC void func_80800F6C_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800F78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800F7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F80: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800F84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800F88: jal         0x800DC128
    // 0x80800F8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800F8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800F90: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800F94: jal         0x800B53A4
    // 0x80800F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800F9C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1776, 0X18B8) << 16);
    // 0x80800FA0: addiu       $t6, $t6, 0x18B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1776, 0X18B8));
    // 0x80800FA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800FA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800FAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FB0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FB8: jal         0x800BABB8
    // 0x80800FBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800FBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800FC0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800FC4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FCC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80800FD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800FD4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800FD8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800FDC: nop

    // 0x80800FE0: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80800FE4: jal         0x800BA568
    // 0x80800FE8: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA568(rdram, ctx);
        goto after_3;
    // 0x80800FE8: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_3:
    // 0x80800FEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1710) << 16);
    // 0x80800FF0: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800FF4: lwc1        $f16, 0x1710($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1710));
    // 0x80800FF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1714) << 16);
    // 0x80800FFC: lwc1        $f4, 0x1714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1714));
    // 0x80801000: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801008: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080100C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801010: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801014: jal         0x800BA7C4
    // 0x80801018: nop

    func_800BA7C4(rdram, ctx);
        goto after_4;
    // 0x80801018: nop

    after_4:
    // 0x8080101C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1718) << 16);
    // 0x80801020: lwc1        $f8, 0x1718($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1718));
    // 0x80801024: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X171C) << 16);
    // 0x8080102C: lwc1        $f18, 0x171C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X171C));
    // 0x80801030: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801038: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8080103C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801040: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80801044: jal         0x800BA7FC
    // 0x80801048: nop

    func_800BA7FC(rdram, ctx);
        goto after_5;
    // 0x80801048: nop

    after_5:
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801050: jal         0x800BA22C
    // 0x80801054: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x80801054: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80801058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080105C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801060: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801064: jr          $ra
    // 0x80801068: nop

    return;
    // 0x80801068: nop

;}
RECOMP_FUNC void gccubeDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080072C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800730: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800734: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080073C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800744: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80800748: jal         0x800825F8
    // 0x8080074C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x8080074C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800758: jal         0x800825A8
    // 0x8080075C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _gsmaker_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080075C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800760: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800764: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800768: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080076C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800770: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800774: bne         $at, $zero, L_808007F8
    if (ctx->r1 != 0) {
        // 0x80800778: sw          $t6, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r14;
            goto L_808007F8;
    }
    // 0x80800778: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_8080077C:
    // 0x8080077C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800780: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800784: bne         $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x80800788: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_808007E0;
    }
    // 0x80800788: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080078C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800790:
    // 0x80800790: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800794: bne         $at, $zero, L_808007CC
    if (ctx->r1 != 0) {
        // 0x80800798: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_808007CC;
    }
    // 0x80800798: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080079C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
L_808007A0:
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: jal         0x808003A0
    // 0x808007A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003A0_gccubeDll(rdram, ctx);
        goto after_2;
    // 0x808007A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808007AC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808007B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808007B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808007B8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808007BC: beq         $at, $zero, L_808007A0
    if (ctx->r1 == 0) {
        // 0x808007C0: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_808007A0;
    }
    // 0x808007C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808007C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808007C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_808007CC:
    // 0x808007CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808007D0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808007D4: beql        $at, $zero, L_80800790
    if (ctx->r1 == 0) {
        // 0x808007D8: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80800790;
    }
    goto skip_0;
    // 0x808007D8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x808007DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
L_808007E0:
    // 0x808007E0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808007E4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808007E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808007EC: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808007F0: beq         $at, $zero, L_8080077C
    if (ctx->r1 == 0) {
        // 0x808007F4: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_8080077C;
    }
    // 0x808007F4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_808007F8:
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: jal         0x800825C8
    // 0x80800800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800804: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800808: jal         0x80800868
    // 0x8080080C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800868_gccubeDll(rdram, ctx);
        goto after_4;
    // 0x8080080C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800814: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800818: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void func_800F4B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4B4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4B54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4B5C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4B60: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4B64: jal         0x8009E674
    // 0x800F4B68: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F4B68: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    after_0:
    // 0x800F4B6C: beq         $v0, $zero, L_800F4B7C
    if (ctx->r2 == 0) {
        // 0x800F4B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F4B7C;
    }
    // 0x800F4B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4B74: b           L_800F4B80
    // 0x800F4B78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800F4B80;
    // 0x800F4B78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F4B7C:
    // 0x800F4B7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F4B80:
    // 0x800F4B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F4B84: jr          $ra
    // 0x800F4B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F4B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
