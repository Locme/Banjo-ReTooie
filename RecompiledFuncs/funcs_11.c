#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800088_bahold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800094: jal         0x80106790
    // 0x80800098: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800098: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080009C: lb          $t7, 0x65($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X65);
    // 0x808000A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: bgezl       $t7, L_808000D4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808000A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000AC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808000B0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808000B4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x808000B8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x808000BC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808000C0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x808000C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x808000CC: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
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
RECOMP_FUNC void sucoasterhit_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009B0: jal         0x80100094
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009B8: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x808009BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808009C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3302, 0XCA8) << 16);
    // 0x808009C4: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x808009C8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x808009CC: sltu        $a0, $zero, $t7
    ctx->r4 = 0 < ctx->r15 ? 1 : 0;
    // 0x808009D0: bne         $a0, $zero, L_808009F8
    if (ctx->r4 != 0) {
        // 0x808009D4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808009F8;
    }
    // 0x808009D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808009D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009DC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808009E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808009E8: nop

    // 0x808009EC: bc1f        L_808009F8
    if (!c1cs) {
        // 0x808009F0: nop
    
            goto L_808009F8;
    }
    // 0x808009F0: nop

    // 0x808009F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_808009F8:
    // 0x808009F8: beql        $a0, $zero, L_80800A0C
    if (ctx->r4 == 0) {
        // 0x808009FC: lbu         $t8, 0x18($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X18);
            goto L_80800A0C;
    }
    goto skip_0;
    // 0x808009FC: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    skip_0:
    // 0x80800A00: lwc1        $f8, 0xCA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3302, 0XCA8));
    // 0x80800A04: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800A08: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
L_80800A0C:
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800A14: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x80800A18: sb          $t9, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r25;
    // 0x80800A1C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800A20: jal         0x80800870
    // 0x80800A24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80800870_sucoasterhit(rdram, ctx);
        goto after_1;
    // 0x80800A24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800A28: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A30: bne         $a3, $zero, L_80800A58
    if (ctx->r7 != 0) {
        // 0x80800A34: nop
    
            goto L_80800A58;
    }
    // 0x80800A34: nop

    // 0x80800A38: jal         0x80102190
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102190(rdram, ctx);
        goto after_2;
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A48: jal         0x8008A140
    // 0x80800A4C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800A4C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x80800A50: b           L_80800AD8
    // 0x80800A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AD8;
    // 0x80800A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A58:
    // 0x80800A58: jal         0x8001210C
    // 0x80800A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x80800A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800A60: beq         $v0, $zero, L_80800A78
    if (ctx->r2 == 0) {
        // 0x80800A64: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800A78;
    }
    // 0x80800A64: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A68: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80800A6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A70: b           L_80800A84
    // 0x80800A74: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
        goto L_80800A84;
    // 0x80800A74: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
L_80800A78:
    // 0x80800A78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A7C: nop

    // 0x80800A80: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
L_80800A84:
    // 0x80800A84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800A88: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800A8C: jal         0x8001210C
    // 0x80800A90: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80800A90: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x80800A94: beq         $v0, $zero, L_80800AAC
    if (ctx->r2 == 0) {
        // 0x80800A98: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_80800AAC;
    }
    // 0x80800A98: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80800A9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800AA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800AA4: b           L_80800AB8
    // 0x80800AA8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
        goto L_80800AB8;
    // 0x80800AA8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_80800AAC:
    // 0x80800AAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800AB0: nop

    // 0x80800AB4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_80800AB8:
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800AC0: jal         0x8008A1A8
    // 0x80800AC4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    _sucoaster_entrypoint_22(rdram, ctx);
        goto after_6;
    // 0x80800AC4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x80800AEC
    // 0x80800AD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800AEC_sucoasterhit(rdram, ctx);
        goto after_7;
    // 0x80800AD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AD8:
    // 0x80800AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: nop

    return;
    // 0x80800AE8: nop

;}
RECOMP_FUNC void func_800C9EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9EFC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9F00: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9F08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9F0C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800C9F10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C9F14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9F18: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9F1C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9F20: jal         0x800C9750
    // 0x800C9F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C9F28: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800C9F2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C9F30: jal         0x8001BBA0
    // 0x800C9F34: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800C9F34: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x800C9F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9F3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9F40: jr          $ra
    // 0x800C9F44: nop

    return;
    // 0x800C9F44: nop

;}
RECOMP_FUNC void _chnutsnbolts_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864F0: syscall     332
    recomp_syscall_handler(rdram, ctx, 0x800864F0);
    return;
    // 0x800864F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gczoombox_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808035AC: beq         $a1, $zero, L_808035C4
    if (ctx->r5 == 0) {
        // 0x808035B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808035C4;
    }
    // 0x808035B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808035B4: lbu         $t7, 0x1E7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E7);
    // 0x808035B8: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808035BC: b           L_808035D0
    // 0x808035C0: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
        goto L_808035D0;
    // 0x808035C0: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
L_808035C4:
    // 0x808035C4: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
    // 0x808035C8: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x808035CC: sb          $t0, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r8;
L_808035D0:
    // 0x808035D0: jal         0x80802BF4
    // 0x808035D4: nop

    func_80802BF4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x808035D4: nop

    after_0:
    // 0x808035D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808035DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808035E0: jr          $ra
    // 0x808035E4: nop

    return;
    // 0x808035E4: nop

;}
RECOMP_FUNC void func_800E3C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3C94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3C98: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E3C9C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800E3CA0: jal         0x800CA6C0
    // 0x800E3CA4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6C0(rdram, ctx);
        goto after_0;
    // 0x800E3CA4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3CB0: jr          $ra
    // 0x800E3CB4: nop

    return;
    // 0x800E3CB4: nop

;}
RECOMP_FUNC void _bsbee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082830: syscall     15
    recomp_syscall_handler(rdram, ctx, 0x80082830);
    return;
    // 0x80082834: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800E9C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EA4: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x80800EA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EAC: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800EB0: beq         $t6, $at, L_80800EDC
    if (ctx->r14 == ctx->r1) {
        // 0x80800EB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800EDC;
    }
    // 0x80800EB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800EB8: beq         $t6, $at, L_80800F38
    if (ctx->r14 == ctx->r1) {
        // 0x80800EBC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800F38;
    }
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EC0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800EC4: beq         $t6, $at, L_80801044
    if (ctx->r14 == ctx->r1) {
        // 0x80800EC8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801044;
    }
    // 0x80800EC8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800ECC: beq         $t6, $at, L_80801044
    if (ctx->r14 == ctx->r1) {
        // 0x80800ED0: nop
    
            goto L_80801044;
    }
    // 0x80800ED0: nop

    // 0x80800ED4: b           L_80801050
    // 0x80800ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801050;
    // 0x80800ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EDC:
    // 0x80800EDC: jal         0x800C954C
    // 0x80800EE0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800C954C(rdram, ctx);
        goto after_0;
    // 0x80800EE0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EE4: bnel        $v0, $zero, L_80801050
    if (ctx->r2 != 0) {
        // 0x80800EE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801050;
    }
    goto skip_0;
    // 0x80800EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800EEC: jal         0x800DA298
    // 0x80800EF0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800EF0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_1:
    // 0x80800EF4: bnel        $v0, $zero, L_80801050
    if (ctx->r2 != 0) {
        // 0x80800EF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801050;
    }
    goto skip_1;
    // 0x80800EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800EFC: jal         0x80086B58
    // 0x80800F00: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800F00: nop

    after_2:
    // 0x80800F04: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800F08: addiu       $t8, $zero, 0xA3
    ctx->r24 = ADD32(0, 0XA3);
    // 0x80800F0C: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800F10: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800F14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800F18: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800F1C: jal         0x8008A208
    // 0x80800F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800F24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800F28: jal         0x80101FDC
    // 0x80800F2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800F2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800F30: b           L_80801050
    // 0x80800F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801050;
    // 0x80800F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F38:
    // 0x80800F38: jal         0x808013BC
    // 0x80800F3C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_808013BC_chfactorytwinklies(rdram, ctx);
        goto after_5;
    // 0x80800F3C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x80800F40: jal         0x80800D00
    // 0x80800F44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800D00_chfactorytwinklies(rdram, ctx);
        goto after_6;
    // 0x80800F44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80800F48: jal         0x800CEAD0
    // 0x80800F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_7;
    // 0x80800F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80800F50: beq         $v0, $zero, L_80800F68
    if (ctx->r2 == 0) {
        // 0x80800F54: nop
    
            goto L_80800F68;
    }
    // 0x80800F54: nop

    // 0x80800F58: jal         0x808011B0
    // 0x80800F5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808011B0_chfactorytwinklies(rdram, ctx);
        goto after_8;
    // 0x80800F5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80800F60: b           L_80801050
    // 0x80800F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801050;
    // 0x80800F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F68:
    // 0x80800F68: jal         0x80089C68
    // 0x80800F6C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800F6C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_9:
    // 0x80800F70: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800F74: jal         0x80089C68
    // 0x80800F78: addiu       $a0, $zero, 0x443
    ctx->r4 = ADD32(0, 0X443);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800F78: addiu       $a0, $zero, 0x443
    ctx->r4 = ADD32(0, 0X443);
    after_10:
    // 0x80800F7C: addiu       $a0, $zero, 0x445
    ctx->r4 = ADD32(0, 0X445);
    // 0x80800F80: jal         0x80089C68
    // 0x80800F84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x80800F84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_11:
    // 0x80800F88: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F8C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800F90: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x80800F94: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800F98: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80800F9C: beq         $at, $zero, L_8080104C
    if (ctx->r1 == 0) {
        // 0x80800FA0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080104C;
    }
    // 0x80800FA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800FA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2188) << 16);
    // 0x80800FAC: jal         0x800DC178
    // 0x80800FB0: lwc1        $f14, 0x2188($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2188));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800FB0: lwc1        $f14, 0x2188($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2188));
    after_12:
    // 0x80800FB4: jal         0x80088368
    // 0x80800FB8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800FB8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80800FBC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800FC0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800FC4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800FC8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800FCC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80800FD0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800FD4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800FD8: jal         0x800D9154
    // 0x80800FDC: nop

    func_800D9154(rdram, ctx);
        goto after_14;
    // 0x80800FDC: nop

    after_14:
    // 0x80800FE0: beql        $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x80800FE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801050;
    }
    goto skip_2;
    // 0x80800FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800FE8: jal         0x800DC0C0
    // 0x80800FEC: nop

    func_800DC0C0(rdram, ctx);
        goto after_15;
    // 0x80800FEC: nop

    after_15:
    // 0x80800FF0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800FF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X218C) << 16);
    // 0x80800FFC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801000: nop

    // 0x80801004: bc1f        L_80801014
    if (!c1cs) {
        // 0x80801008: nop
    
            goto L_80801014;
    }
    // 0x80801008: nop

    // 0x8080100C: b           L_80801034
    // 0x80801010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80801034;
    // 0x80801010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801014:
    // 0x80801014: lwc1        $f18, 0x218C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X218C));
    // 0x80801018: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080101C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801020: nop

    // 0x80801024: bc1f        L_80801034
    if (!c1cs) {
        // 0x80801028: nop
    
            goto L_80801034;
    }
    // 0x80801028: nop

    // 0x8080102C: b           L_80801034
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80801030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801034:
    // 0x80801034: jal         0x80108B04
    // 0x80801038: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80108B04(rdram, ctx);
        goto after_16;
    // 0x80801038: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_16:
    // 0x8080103C: b           L_80801050
    // 0x80801040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801050;
    // 0x80801040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801044:
    // 0x80801044: jal         0x808013BC
    // 0x80801048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808013BC_chfactorytwinklies(rdram, ctx);
        goto after_17;
    // 0x80801048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_8080104C:
    // 0x8080104C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801050:
    // 0x80801050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801054: jr          $ra
    // 0x80801058: nop

    return;
    // 0x80801058: nop

;}
RECOMP_FUNC void func_808015B0_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015B8: jal         0x80082FE8
    // 0x808015BC: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808015BC: nop

    after_0:
    // 0x808015C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015C8: jr          $ra
    // 0x808015CC: nop

    return;
    // 0x808015CC: nop

;}
RECOMP_FUNC void func_80115F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115F98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80115F9C: nop

    // 0x80115FA0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80115FA4: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80115FA8: jr          $ra
    // 0x80115FAC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80115FAC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80800294_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002A8: bne         $a1, $at, L_808002C8
    if (ctx->r5 != ctx->r1) {
        // 0x808002AC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808002C8;
    }
    // 0x808002AC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808002B0: addiu       $a0, $zero, 0x339
    ctx->r4 = ADD32(0, 0X339);
    // 0x808002B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808002B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002BC: jal         0x80101180
    // 0x808002C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808002C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808002C8:
    // 0x808002C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002D0: jal         0x80085820
    // 0x808002D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808002D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_80800A1C_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A20: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A28: beq         $a1, $at, L_80800A78
    if (ctx->r5 == ctx->r1) {
        // 0x80800A2C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800A78;
    }
    // 0x80800A2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800A30: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800A34: beq         $a1, $at, L_80800A68
    if (ctx->r5 == ctx->r1) {
        // 0x80800A38: lh          $a2, 0x22($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X22);
            goto L_80800A68;
    }
    // 0x80800A38: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x80800A3C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800A40: beq         $a1, $at, L_80800A58
    if (ctx->r5 == ctx->r1) {
        // 0x80800A44: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800A58;
    }
    // 0x80800A44: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A48: beql        $a1, $at, L_80800AA8
    if (ctx->r5 == ctx->r1) {
        // 0x80800A4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800AA8;
    }
    goto skip_0;
    // 0x80800A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800A50: b           L_80800AA8
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AA8;
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A58:
    // 0x80800A58: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800A5C: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800A60: b           L_80800AA4
    // 0x80800A64: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
        goto L_80800AA4;
    // 0x80800A64: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
L_80800A68:
    // 0x80800A68: jal         0x80800AB8
    // 0x80800A6C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80800AB8_chwarppad(rdram, ctx);
        goto after_0;
    // 0x80800A6C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_0:
    // 0x80800A70: b           L_80800AA8
    // 0x80800A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AA8;
    // 0x80800A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A78:
    // 0x80800A78: jal         0x80101080
    // 0x80800A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_1;
    // 0x80800A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A88: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80800A8C: jal         0x80800B34
    // 0x80800A90: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_80800B34_chwarppad(rdram, ctx);
        goto after_2;
    // 0x80800A90: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_2:
    // 0x80800A94: b           L_80800AA8
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AA8;
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A9C: b           L_80800AA8
    // 0x80800AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AA8;
    // 0x80800AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AA4:
    // 0x80800AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AA8:
    // 0x80800AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: nop

    return;
    // 0x80800AB4: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: jal         0x8080011C
    // 0x80800168: nop

    gccollectDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800168: nop

    after_0:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_808044F4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808044F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808044F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808044FC: jal         0x80100094
    // 0x80804500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804504: jal         0x800BD09C
    // 0x80804508: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800BD09C(rdram, ctx);
        goto after_1;
    // 0x80804508: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x8080450C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804514: jr          $ra
    // 0x80804518: nop

    return;
    // 0x80804518: nop

;}
RECOMP_FUNC void func_80800000_chhagstraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: bne         $a1, $at, L_80800028
    if (ctx->r5 != ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800028;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    // 0x80800014: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800018: jal         0x80101180
    // 0x8080001C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800020: b           L_80800030
    // 0x80800024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800030;
    // 0x80800024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800028:
    // 0x80800028: jal         0x80085820
    // 0x8080002C: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080002C: nop

    after_1:
L_80800030:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_8080000C_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80089B70
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sufreezy_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1044, 0X6F0) << 16);
    // 0x80800020: lwc1        $f4, 0x6F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1044, 0X6F0));
    // 0x80800024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void sutempleboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x800F54E4
    // 0x80800014: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: jal         0x800F4BE4
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4BE4(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800020: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800024: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80800038;
    }
    // 0x80800024: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800028: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8080002C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80800030: b           L_808001C4
    // 0x80800034: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_808001C4;
    // 0x80800034: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80800038:
    // 0x80800038: jal         0x800EA05C
    // 0x8080003C: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x8080003C: nop

    after_2:
    // 0x80800040: addiu       $at, $zero, 0x177
    ctx->r1 = ADD32(0, 0X177);
    // 0x80800044: beq         $v0, $at, L_8080006C
    if (ctx->r2 == ctx->r1) {
        // 0x80800048: addiu       $v1, $zero, 0x178
        ctx->r3 = ADD32(0, 0X178);
            goto L_8080006C;
    }
    // 0x80800048: addiu       $v1, $zero, 0x178
    ctx->r3 = ADD32(0, 0X178);
    // 0x8080004C: addiu       $v1, $zero, 0x178
    ctx->r3 = ADD32(0, 0X178);
    // 0x80800050: beq         $v0, $v1, L_808000D0
    if (ctx->r2 == ctx->r3) {
        // 0x80800054: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_808000D0;
    }
    // 0x80800054: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800058: addiu       $at, $zero, 0x17A
    ctx->r1 = ADD32(0, 0X17A);
    // 0x8080005C: beq         $v0, $at, L_808000A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800060: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_808000A0;
    }
    // 0x80800060: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80800064: b           L_808001C8
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001C8;
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080006C:
    // 0x8080006C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80800070: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    // 0x80800074: jal         0x800DA298
    // 0x80800078: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800078: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    after_3:
    // 0x8080007C: beq         $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80800094;
    }
    // 0x80800080: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80800084: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800088: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8080008C: b           L_808001C4
    // 0x80800090: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_808001C4;
    // 0x80800090: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80800094:
    // 0x80800094: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800098: b           L_808001C4
    // 0x8080009C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_808001C4;
    // 0x8080009C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_808000A0:
    // 0x808000A0: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x808000A4: jal         0x800DA298
    // 0x808000A8: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808000A8: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    after_4:
    // 0x808000AC: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000B0: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_808000C4;
    }
    // 0x808000B0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808000B4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x808000B8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808000BC: b           L_808001C4
    // 0x808000C0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
        goto L_808001C4;
    // 0x808000C0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_808000C4:
    // 0x808000C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808000C8: b           L_808001C4
    // 0x808000CC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_808001C4;
    // 0x808000CC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_808000D0:
    // 0x808000D0: jal         0x800EE88C
    // 0x808000D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x808000D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x808000D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E0: jal         0x800882F0
    // 0x808000E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x808000E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x808000E8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808000EC: jal         0x800EE88C
    // 0x808000F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_7;
    // 0x808000F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x808000F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808000F8: jal         0x800EEB40
    // 0x808000FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x808000FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80800100: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800104: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080010C: jal         0x800882F0
    // 0x80800110: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_9;
    // 0x80800110: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x80800114: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800118: jal         0x800EE88C
    // 0x8080011C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_10;
    // 0x8080011C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80800120: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800124: jal         0x800EEB40
    // 0x80800128: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EEB40(rdram, ctx);
        goto after_11;
    // 0x80800128: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_11:
    // 0x8080012C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800134: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800138: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800140: bc1f        L_80800150
    if (!c1cs) {
        // 0x80800144: nop
    
            goto L_80800150;
    }
    // 0x80800144: nop

    // 0x80800148: b           L_80800150
    // 0x8080014C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800150;
    // 0x8080014C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800150:
    // 0x80800150: jal         0x800D0B68
    // 0x80800154: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D0B68(rdram, ctx);
        goto after_12;
    // 0x80800154: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_12:
    // 0x80800158: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_80800184;
    }
    // 0x8080015C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800160: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    // 0x80800164: jal         0x800DA298
    // 0x80800168: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800168: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_13:
    // 0x8080016C: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800170: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_8080017C;
    }
    // 0x80800170: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800174: b           L_80800198
    // 0x80800178: xori        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 ^ 0X1;
        goto L_80800198;
    // 0x80800178: xori        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 ^ 0X1;
L_8080017C:
    // 0x8080017C: b           L_80800198
    // 0x80800180: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80800198;
    // 0x80800180: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80800184:
    // 0x80800184: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    // 0x80800188: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080018C: jal         0x800DA3B8
    // 0x80800190: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_800DA3B8(rdram, ctx);
        goto after_14;
    // 0x80800190: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_14:
    // 0x80800194: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80800198:
    // 0x80800198: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x8080019C: lw          $t1, 0x4C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4C);
            goto L_808001B0;
    }
    // 0x8080019C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x808001A0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x808001A4: addiu       $t8, $zero, 0x17A
    ctx->r24 = ADD32(0, 0X17A);
    // 0x808001A8: b           L_808001B8
    // 0x808001AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_808001B8;
    // 0x808001AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_808001B0:
    // 0x808001B0: addiu       $t0, $zero, 0x177
    ctx->r8 = ADD32(0, 0X177);
    // 0x808001B4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_808001B8:
    // 0x808001B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x808001BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808001C0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_808001C4:
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C8:
    // 0x808001C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

    // 0x808001D4: nop

    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void _badata_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084738: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084738);
    return;
    // 0x8008473C: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void func_80800160_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800168: jal         0x80091A58
    // 0x8080016C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080016C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
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
RECOMP_FUNC void ovl_relocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_800821FC:
    // 0x800821FC: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x80082200: xor         $t5, $t5, $s5
    ctx->r13 = ctx->r13 ^ ctx->r21;
    // 0x80082204: andi        $t4, $t5, 0x3
    ctx->r12 = ctx->r13 & 0X3;
    // 0x80082208: xor         $t5, $t5, $t4
    ctx->r13 = ctx->r13 ^ ctx->r12;
    // 0x8008220C: beq         $t4, $zero, L_80082240
    if (ctx->r12 == 0) {
        // 0x80082210: addu        $t5, $t5, $t0
        ctx->r13 = ADD32(ctx->r13, ctx->r8);
            goto L_80082240;
    }
    // 0x80082210: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x80082214: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80082218: beql        $t4, $zero, L_80082254
    if (ctx->r12 == 0) {
        // 0x8008221C: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_80082254;
    }
    goto skip_0;
    // 0x8008221C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    skip_0:
    // 0x80082220: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80082224: beq         $t4, $zero, L_80082274
    if (ctx->r12 == 0) {
        // 0x80082228: nop
    
            goto L_80082274;
    }
    // 0x80082228: nop

    // 0x8008222C: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80082230: beql        $t4, $zero, L_80082280
    if (ctx->r12 == 0) {
        // 0x80082234: lh          $t6, 0x2($t5)
        ctx->r14 = MEM_H(ctx->r13, 0X2);
            goto L_80082280;
    }
    goto skip_1;
    // 0x80082234: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    skip_1:
    // 0x80082238: j           L_800822AC
    // 0x8008223C: nop

        goto L_800822AC;
    // 0x8008223C: nop

L_80082240:
    // 0x80082240: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80082244: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80082248: j           L_800822AC
    // 0x8008224C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_800822AC;
    // 0x8008224C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80082250: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_80082254:
    // 0x80082254: sra         $t7, $t1, 2
    ctx->r15 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80082258: lui         $t8, 0xFC00
    ctx->r24 = S32(0XFC00 << 16);
    // 0x8008225C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80082260: xor         $t6, $t6, $t7
    ctx->r14 = ctx->r14 ^ ctx->r15;
    // 0x80082264: and         $t6, $t6, $t8
    ctx->r14 = ctx->r14 & ctx->r24;
    // 0x80082268: xor         $t6, $t6, $t7
    ctx->r14 = ctx->r14 ^ ctx->r15;
    // 0x8008226C: j           L_800822AC
    // 0x80082270: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_800822AC;
    // 0x80082270: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80082274:
    // 0x80082274: j           L_800822AC
    // 0x80082278: or          $t9, $t5, $zero
    ctx->r25 = ctx->r13 | 0;
        goto L_800822AC;
    // 0x80082278: or          $t9, $t5, $zero
    ctx->r25 = ctx->r13 | 0;
    // 0x8008227C: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
L_80082280:
    // 0x80082280: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80082284: beq         $t9, $zero, L_800822AC
    if (ctx->r25 == 0) {
        // 0x80082288: sh          $t6, 0x2($t5)
        MEM_H(0X2, ctx->r13) = ctx->r14;
            goto L_800822AC;
    }
    // 0x80082288: sh          $t6, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r14;
    // 0x8008228C: lh          $t7, 0x2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X2);
    // 0x80082290: srl         $t8, $t6, 15
    ctx->r24 = S32(U32(ctx->r14) >> 15);
    // 0x80082294: andi        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 & 0X1;
    // 0x80082298: srl         $t6, $t6, 16
    ctx->r14 = S32(U32(ctx->r14) >> 16);
    // 0x8008229C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800822A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800822A4: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800822A8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
L_800822AC:
    // 0x800822AC: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800822B0: bne         $t3, $zero, L_800821FC
    if (ctx->r11 != 0) {
        // 0x800822B4: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_800821FC;
    }
    // 0x800822B4: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800822B8: jr          $ra
    // 0x800822BC: nop

    return;
    // 0x800822BC: nop

;}
RECOMP_FUNC void func_800F23D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F23D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F23D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F23D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F23DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F23E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F23E4: jal         0x800EE7F8
    // 0x800F23E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800F23E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800F23EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800F23F0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F23F4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F23F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800F23FC:
    // 0x800F23FC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2400: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F2404: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2408: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F240C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800F2410: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F2414: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F2418: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F241C: lwc1        $f14, 0x30($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800F2420: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F2424: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800F2428: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F242C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800F2430: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800F2434: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800F2438: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800F243C: bne         $v1, $a1, L_800F23FC
    if (ctx->r3 != ctx->r5) {
        // 0x800F2440: swc1        $f10, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f10.u32l;
            goto L_800F23FC;
    }
    // 0x800F2440: swc1        $f10, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800F2444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2448: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F244C: jr          $ra
    // 0x800F2450: nop

    return;
    // 0x800F2450: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888F8: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x800888F8);
    return;
    // 0x800888FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsstonehead_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011AC: jal         0x800845D0
    // 0x808011B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808011B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011B4: jal         0x80800000
    // 0x808011B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808011B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011C4: jr          $ra
    // 0x808011C8: nop

    return;
    // 0x808011C8: nop

;}
RECOMP_FUNC void func_80802EF8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802EF8: jr          $ra
    // 0x80802EFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80802EFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void suspline_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x808008E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808008E4: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808008E8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808008EC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808008F0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808008F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808008F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808008FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800900: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800904: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800908: addiu       $a1, $s3, 0x3C
    ctx->r5 = ADD32(ctx->r19, 0X3C);
    // 0x8080090C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80800910: jal         0x800EE7F8
    // 0x80800914: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800914: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800918: lbu         $t6, 0x88($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X88);
    // 0x8080091C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800920: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x80800924: blez        $t6, L_80800958
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800928: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_80800958;
    }
    // 0x80800928: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8080092C: lh          $t7, 0x68($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X68);
L_80800930:
    // 0x80800930: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800934: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800938: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8080093C: sw          $t8, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r24;
    // 0x80800940: lbu         $t9, 0x88($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X88);
    // 0x80800944: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800948: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8080094C: bnel        $at, $zero, L_80800930
    if (ctx->r1 != 0) {
        // 0x80800950: lh          $t7, 0x68($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X68);
            goto L_80800930;
    }
    goto skip_0;
    // 0x80800950: lh          $t7, 0x68($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X68);
    skip_0:
    // 0x80800954: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800958:
    // 0x80800958: lbu         $v1, 0x89($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X89);
    // 0x8080095C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800960: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x80800964: blez        $v1, L_80800998
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800968: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_80800998;
    }
    // 0x80800968: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x8080096C: lh          $t0, 0x70($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X70);
L_80800970:
    // 0x80800970: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800974: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800978: addu        $t1, $t0, $s3
    ctx->r9 = ADD32(ctx->r8, ctx->r19);
    // 0x8080097C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80800980: lbu         $v1, 0x89($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X89);
    // 0x80800984: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800988: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8080098C: bnel        $at, $zero, L_80800970
    if (ctx->r1 != 0) {
        // 0x80800990: lh          $t0, 0x70($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X70);
            goto L_80800970;
    }
    goto skip_1;
    // 0x80800990: lh          $t0, 0x70($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X70);
    skip_1:
    // 0x80800994: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800998:
    // 0x80800998: lh          $a0, 0x78($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X78);
    // 0x8080099C: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x808009A0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x808009A4: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808009A8: bne         $at, $zero, L_80800B3C
    if (ctx->r1 != 0) {
        // 0x808009AC: nop
    
            goto L_80800B3C;
    }
    // 0x808009AC: nop

    // 0x808009B0: jal         0x80800224
    // 0x808009B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800224_suspline(rdram, ctx);
        goto after_1;
    // 0x808009B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x808009B8: lbu         $t2, 0x88($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X88);
    // 0x808009BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808009C0: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x808009C4: blez        $t2, L_80800AA0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x808009C8: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_80800AA0;
    }
    // 0x808009C8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x808009CC: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x808009D0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_808009D4:
    // 0x808009D4: lh          $t3, 0x84($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X84);
    // 0x808009D8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808009DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808009E0: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808009E4: mflo        $t4
    ctx->r12 = lo;
    // 0x808009E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x808009EC: jal         0x800EE7F8
    // 0x808009F0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808009F0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x808009F4: lh          $t7, 0x86($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X86);
    // 0x808009F8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808009FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800A00: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A04: mflo        $t8
    ctx->r24 = lo;
    // 0x80800A08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800A0C: jal         0x800EE7F8
    // 0x80800A10: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800A10: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80800A14: lh          $t1, 0x88($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X88);
    // 0x80800A18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800A1C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800A20: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A24: mflo        $t2
    ctx->r10 = lo;
    // 0x80800A28: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800A2C: jal         0x800EE7F8
    // 0x80800A30: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800A30: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x80800A34: lh          $t5, 0x8A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8A);
    // 0x80800A38: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800A3C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800A40: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A44: mflo        $t6
    ctx->r14 = lo;
    // 0x80800A48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800A4C: jal         0x800EE7F8
    // 0x80800A50: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800A50: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_5:
    // 0x80800A54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A58: jal         0x808000B4
    // 0x80800A5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808000B4_suspline(rdram, ctx);
        goto after_6;
    // 0x80800A5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80800A60: beq         $v0, $zero, L_80800A70
    if (ctx->r2 == 0) {
        // 0x80800A64: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800A70;
    }
    // 0x80800A64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800A68: jal         0x800F0EF0
    // 0x80800A6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F0EF0(rdram, ctx);
        goto after_7;
    // 0x80800A6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
L_80800A70:
    // 0x80800A70: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800A74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800A78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800A7C: jal         0x800890F8
    // 0x80800A80: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800A80: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80800A84: lbu         $t9, 0x88($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X88);
    // 0x80800A88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800A8C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800A90: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800A94: bne         $at, $zero, L_808009D4
    if (ctx->r1 != 0) {
        // 0x80800A98: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808009D4;
    }
    // 0x80800A98: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800A9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800AA0:
    // 0x80800AA0: lbu         $t0, 0x89($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X89);
    // 0x80800AA4: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x80800AA8: addiu       $s1, $s3, 0x30
    ctx->r17 = ADD32(ctx->r19, 0X30);
    // 0x80800AAC: blez        $t0, L_80800C3C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800AB0: addiu       $s4, $sp, 0x74
        ctx->r20 = ADD32(ctx->r29, 0X74);
            goto L_80800C3C;
    }
    // 0x80800AB0: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
L_80800AB4:
    // 0x80800AB4: lh          $t1, 0x84($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X84);
    // 0x80800AB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800ABC: lh          $t4, 0x86($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X86);
    // 0x80800AC0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800AC4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80800AC8: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80800ACC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800AD0: lh          $t7, 0x88($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88);
    // 0x80800AD4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80800AD8: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80800ADC: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800AE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800AE4: lh          $t0, 0x8A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X8A);
    // 0x80800AE8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800AEC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80800AF0: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800AF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800AF8: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80800AFC: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x80800B00: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80800B04: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800B08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800B0C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800B10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80800B14: jal         0x80089120
    // 0x80800B18: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    _mlspline_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800B18: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80800B1C: lbu         $t3, 0x89($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X89);
    // 0x80800B20: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800B24: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800B28: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800B2C: bne         $at, $zero, L_80800AB4
    if (ctx->r1 != 0) {
        // 0x80800B30: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800AB4;
    }
    // 0x80800B30: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800B34: b           L_80800C3C
    // 0x80800B38: nop

        goto L_80800C3C;
    // 0x80800B38: nop

L_80800B3C:
    // 0x80800B3C: bne         $s4, $a0, L_80800BC4
    if (ctx->r20 != ctx->r4) {
        // 0x80800B40: lbu         $v0, 0x88($s3)
        ctx->r2 = MEM_BU(ctx->r19, 0X88);
            goto L_80800BC4;
    }
    // 0x80800B40: lbu         $v0, 0x88($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X88);
    // 0x80800B44: blez        $v0, L_80800B84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800B48: addiu       $s0, $sp, 0xA4
        ctx->r16 = ADD32(ctx->r29, 0XA4);
            goto L_80800B84;
    }
    // 0x80800B48: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x80800B4C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_80800B50:
    // 0x80800B50: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800B54: lh          $a1, 0x78($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X78);
    // 0x80800B58: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800B5C: jal         0x800890E8
    // 0x80800B60: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _mlspline_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800B60: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80800B64: lbu         $t4, 0x88($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X88);
    // 0x80800B68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800B6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800B70: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800B74: bne         $at, $zero, L_80800B50
    if (ctx->r1 != 0) {
        // 0x80800B78: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800B50;
    }
    // 0x80800B78: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800B7C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800B80: lbu         $v1, 0x89($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X89);
L_80800B84:
    // 0x80800B84: blez        $v1, L_80800C3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800B88: addiu       $s0, $sp, 0x94
        ctx->r16 = ADD32(ctx->r29, 0X94);
            goto L_80800C3C;
    }
    // 0x80800B88: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x80800B8C: addiu       $s1, $s3, 0x30
    ctx->r17 = ADD32(ctx->r19, 0X30);
L_80800B90:
    // 0x80800B90: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800B94: lh          $a1, 0x78($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X78);
    // 0x80800B98: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800B9C: jal         0x800890F0
    // 0x80800BA0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _mlspline_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800BA0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_11:
    // 0x80800BA4: lbu         $t5, 0x89($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X89);
    // 0x80800BA8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800BAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800BB0: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80800BB4: bne         $at, $zero, L_80800B90
    if (ctx->r1 != 0) {
        // 0x80800BB8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800B90;
    }
    // 0x80800BB8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800BBC: b           L_80800C3C
    // 0x80800BC0: nop

        goto L_80800C3C;
    // 0x80800BC0: nop

L_80800BC4:
    // 0x80800BC4: blez        $v0, L_80800C04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800BC8: addiu       $s0, $sp, 0xA4
        ctx->r16 = ADD32(ctx->r29, 0XA4);
            goto L_80800C04;
    }
    // 0x80800BC8: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x80800BCC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_80800BD0:
    // 0x80800BD0: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800BD4: lh          $a1, 0x78($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X78);
    // 0x80800BD8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800BDC: jal         0x800890D8
    // 0x80800BE0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _mlspline_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800BE0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80800BE4: lbu         $t6, 0x88($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X88);
    // 0x80800BE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800BEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800BF0: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800BF4: bne         $at, $zero, L_80800BD0
    if (ctx->r1 != 0) {
        // 0x80800BF8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800BD0;
    }
    // 0x80800BF8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800BFC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800C00: lbu         $v1, 0x89($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X89);
L_80800C04:
    // 0x80800C04: blez        $v1, L_80800C3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800C08: addiu       $s0, $sp, 0x94
        ctx->r16 = ADD32(ctx->r29, 0X94);
            goto L_80800C3C;
    }
    // 0x80800C08: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x80800C0C: addiu       $s1, $s3, 0x30
    ctx->r17 = ADD32(ctx->r19, 0X30);
L_80800C10:
    // 0x80800C10: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800C14: lh          $a1, 0x78($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X78);
    // 0x80800C18: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800C1C: jal         0x800890E0
    // 0x80800C20: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _mlspline_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800C20: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_13:
    // 0x80800C24: lbu         $t7, 0x89($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X89);
    // 0x80800C28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800C2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800C30: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800C34: bne         $at, $zero, L_80800C10
    if (ctx->r1 != 0) {
        // 0x80800C38: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800C10;
    }
    // 0x80800C38: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800C3C:
    // 0x80800C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEB8) << 16);
    // 0x80800C40: lwc1        $f0, 0xEB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEB8));
    // 0x80800C44: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800C48: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800C4C: nop

    // 0x80800C50: bc1fl       L_80800C60
    if (!c1cs) {
        // 0x80800C54: lwc1        $f4, 0xB4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_80800C60;
    }
    goto skip_2;
    // 0x80800C54: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x80800C58: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
    // 0x80800C5C: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
L_80800C60:
    // 0x80800C60: swc1        $f4, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f4.u32l;
    // 0x80800C64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800C68: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800C6C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C70: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800C74: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800C78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800C7C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C80: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800C84: jr          $ra
    // 0x80800C88: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80800C88: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void bawasher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800048: jal         0x80092CDC
    // 0x8080004C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80092CDC(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x80800050: bne         $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x80800054: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800060;
    }
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: jal         0x8009C128
    // 0x8080005C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8080005C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void _chfriesstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DC0: syscall     240
    recomp_syscall_handler(rdram, ctx, 0x80085DC0);
    return;
    // 0x80085DC4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _ncba1p_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893E8: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893E8);
    return;
    // 0x800893EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chbaddiesetup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800608: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080060C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800610: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800614: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800618: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080061C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800624: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800628: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080062C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80800630: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80800634: jal         0x800858F8
    // 0x80800638: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    _chbounce_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800638: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8080063C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800640: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void func_80800380_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080038C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800390: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(904, 0X704) << 16);
    // 0x80800394: addiu       $t7, $t7, 0x704
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(904, 0X704));
    // 0x80800398: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x8080039C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808003A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003A8: jal         0x800BBCB8
    // 0x808003AC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808003AC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_808009F4_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A00: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x80800A04: jal         0x800DA980
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800A0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A10: bne         $v0, $at, L_80800A20
    if (ctx->r2 != ctx->r1) {
        // 0x80800A14: addiu       $a1, $zero, 0x1098
        ctx->r5 = ADD32(0, 0X1098);
            goto L_80800A20;
    }
    // 0x80800A14: addiu       $a1, $zero, 0x1098
    ctx->r5 = ADD32(0, 0X1098);
    // 0x80800A18: b           L_80800A20
    // 0x80800A1C: addiu       $a1, $zero, 0x1099
    ctx->r5 = ADD32(0, 0X1099);
        goto L_80800A20;
    // 0x80800A1C: addiu       $a1, $zero, 0x1099
    ctx->r5 = ADD32(0, 0X1099);
L_80800A20:
    // 0x80800A20: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800A24: addiu       $t6, $zero, 0x3B
    ctx->r14 = ADD32(0, 0X3B);
    // 0x80800A28: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800A2C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800A30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A34: jal         0x8008A208
    // 0x80800A38: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800A38: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80800A3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A40: jal         0x80100094
    // 0x80800A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A48: lbu         $t8, 0x16($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X16);
    // 0x80800A4C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80800A50: sb          $t9, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r25;
    // 0x80800A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A5C: jr          $ra
    // 0x80800A60: nop

    return;
    // 0x80800A60: nop

;}
RECOMP_FUNC void func_808058B0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808058B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808058B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808058B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808058BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808058C0: jal         0x80100094
    // 0x808058C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808058C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808058C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808058CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808058D0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808058D4: lhu         $a0, 0x1A($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X1A);
    // 0x808058D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808058DC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x808058E0: srl         $t7, $a0, 5
    ctx->r15 = S32(U32(ctx->r4) >> 5);
    // 0x808058E4: jal         0x800F79DC
    // 0x808058E8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F79DC(rdram, ctx);
        goto after_1;
    // 0x808058E8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x808058EC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808058F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808058F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808058F8: lwc1        $f6, 0x28($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X28);
    // 0x808058FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80805900: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80805904: nop

    // 0x80805908: bc1fl       L_80805954
    if (!c1cs) {
        // 0x8080590C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80805954;
    }
    goto skip_0;
    // 0x8080590C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80805910: jal         0x8008A010
    // 0x80805914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiecustomhits_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80805914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80805918: bne         $v0, $zero, L_80805934
    if (ctx->r2 != 0) {
        // 0x8080591C: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80805934;
    }
    // 0x8080591C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80805920: lhu         $a0, 0x1A($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X1A);
    // 0x80805924: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80805928: srl         $t1, $a0, 5
    ctx->r9 = S32(U32(ctx->r4) >> 5);
    // 0x8080592C: jal         0x800F5BF0
    // 0x80805930: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800F5BF0(rdram, ctx);
        goto after_3;
    // 0x80805930: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_80805934:
    // 0x80805934: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80805938: jal         0x800862B8
    // 0x8080593C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080593C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80805940: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BA0) << 16);
    // 0x80805944: lwc1        $f8, -0x6460($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BA0));
    // 0x80805948: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8080594C: swc1        $f8, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f8.u32l;
    // 0x80805950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805954:
    // 0x80805954: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80805958: jr          $ra
    // 0x8080595C: nop

    return;
    // 0x8080595C: nop

;}
RECOMP_FUNC void func_80800DAC_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800DB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DBC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800DC0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800DC4: jal         0x80100094
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800DCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800DD0: jal         0x80089DA8
    // 0x80800DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800DD8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: jal         0x80089DF0
    // 0x80800DE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _suspline_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80800DE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80800DE8: jal         0x80089E00
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suspline_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DF8: jal         0x80089D90
    // 0x80800DFC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800DFC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E08: jal         0x80089D90
    // 0x80800E0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800E0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800E10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800E14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E1C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800E28: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x80800E2C: jal         0x80089DB8
    // 0x80800E30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _suspline_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800E30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E40: jr          $ra
    // 0x80800E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _gczoombox_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BE0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BE0);
    return;
    // 0x80087BE4: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_80800038_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8080003C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800044: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800048: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080004C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800050: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800054: jal         0x80100094
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080005C: jal         0x800D8FF8
    // 0x80800060: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800060: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800064: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x80800068: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x8080006C: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x80800070: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800074: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80800078: jal         0x800EE7F8
    // 0x8080007C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080007C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80800080: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800084: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800088: lwc1        $f4, 0x38($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X38);
    // 0x8080008C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800090: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    // 0x80800094: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800098: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080009C: jal         0x800EF1B8
    // 0x808000A0: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x808000A0: nop

    after_3:
    // 0x808000A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB50) << 16);
    // 0x808000A8: lwc1        $f16, 0xB50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB50));
    // 0x808000AC: lwc1        $f10, 0x38($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X38);
    // 0x808000B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000B8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808000BC: jal         0x800E3E8C
    // 0x808000C0: nop

    func_800E3E8C(rdram, ctx);
        goto after_4;
    // 0x808000C0: nop

    after_4:
    // 0x808000C4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808000C8: lhu         $v1, 0x72($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X72);
    // 0x808000CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808000D4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000D8: beq         $t6, $at, L_808000F8
    if (ctx->r14 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F8;
    }
    // 0x808000DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E0: beq         $t6, $at, L_80800110
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800110;
    }
    // 0x808000E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E8: beq         $t6, $at, L_80800124
    if (ctx->r14 == ctx->r1) {
        // 0x808000EC: nop
    
            goto L_80800124;
    }
    // 0x808000EC: nop

    // 0x808000F0: b           L_8080018C
    // 0x808000F4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
        goto L_8080018C;
    // 0x808000F4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
L_808000F8:
    // 0x808000F8: jal         0x800F2E60
    // 0x808000FC: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    func_800F2E60(rdram, ctx);
        goto after_5;
    // 0x808000FC: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    after_5:
    // 0x80800100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: b           L_80800188
    // 0x8080010C: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
        goto L_80800188;
    // 0x8080010C: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
L_80800110:
    // 0x80800110: jal         0x800EFD3C
    // 0x80800114: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800EFD3C(rdram, ctx);
        goto after_6;
    // 0x80800114: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x80800118: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080011C: b           L_80800188
    // 0x80800120: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
        goto L_80800188;
    // 0x80800120: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
L_80800124:
    // 0x80800124: jal         0x800D90A4
    // 0x80800128: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80800128: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_7:
    // 0x8080012C: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800130: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080013C;
    }
    // 0x80800130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800134: jal         0x80101FDC
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_8080013C:
    // 0x8080013C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800140: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080014C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800150: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800154: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800158: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080015C: jal         0x800F10B4
    // 0x80800160: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80800160: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80800164: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800168: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x8080016C: jal         0x800EFD3C
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD3C(rdram, ctx);
        goto after_10;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800174: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080017C: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    // 0x80800180: jal         0x800F3214
    // 0x80800184: lw          $a3, 0x54($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X54);
    func_800F3214(rdram, ctx);
        goto after_11;
    // 0x80800184: lw          $a3, 0x54($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X54);
    after_11:
L_80800188:
    // 0x80800188: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
L_8080018C:
    // 0x8080018C: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80800190: lwc1        $f18, 0x54($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X54);
    // 0x80800194: lwc1        $f6, 0x4C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x80800198: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080019C: nop

    // 0x808001A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808001A4: jal         0x800136E4
    // 0x808001A8: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_12;
    // 0x808001A8: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_12:
    // 0x808001AC: lbu         $t7, 0x78($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X78);
    // 0x808001B0: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x808001B4: beql        $t7, $zero, L_808001D4
    if (ctx->r15 == 0) {
        // 0x808001B8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x808001B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_0:
    // 0x808001BC: jal         0x8008A7B0
    // 0x808001C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddiezone_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808001C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x808001C4: bnel        $v0, $zero, L_808001D4
    if (ctx->r2 != 0) {
        // 0x808001C8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808001D4;
    }
    goto skip_1;
    // 0x808001C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_1:
    // 0x808001CC: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x808001D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808001D4:
    // 0x808001D4: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
L_808001D8:
    // 0x808001D8: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808001DC: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x808001E0: lwc1        $f18, 0x54($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X54);
    // 0x808001E4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808001EC: nop

    // 0x808001F0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808001F4: jal         0x800136E4
    // 0x808001F8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_14;
    // 0x808001F8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_14:
    // 0x808001FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800204: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800208: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080020C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800210: lwc1        $f18, 0x38($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800214: lwc1        $f8, 0x48($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80800218: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080021C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800220: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800224: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800228: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080022C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800230: jal         0x800EEC30
    // 0x80800234: nop

    func_800EEC30(rdram, ctx);
        goto after_15;
    // 0x80800234: nop

    after_15:
    // 0x80800238: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080023C: jal         0x800EF04C
    // 0x80800240: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x80800240: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_16:
    // 0x80800244: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080024C: lwc1        $f8, 0x38($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800250: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800254: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    // 0x80800258: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080025C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800260: jal         0x800EF1B8
    // 0x80800264: nop

    func_800EF1B8(rdram, ctx);
        goto after_17;
    // 0x80800264: nop

    after_17:
    // 0x80800268: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8080026C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800270: beql        $t8, $zero, L_80800290
    if (ctx->r24 == 0) {
        // 0x80800274: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800290;
    }
    goto skip_2;
    // 0x80800274: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x80800278: jal         0x800C8CB8
    // 0x8080027C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C8CB8(rdram, ctx);
        goto after_18;
    // 0x8080027C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
    // 0x80800280: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800284: jal         0x800C8E84
    // 0x80800288: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800C8E84(rdram, ctx);
        goto after_19;
    // 0x80800288: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x8080028C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800290:
    // 0x80800290: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800294: bne         $s1, $at, L_808001D8
    if (ctx->r17 != ctx->r1) {
        // 0x80800298: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808001D8;
    }
    // 0x80800298: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080029C: lw          $t9, 0x7C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X7C);
    // 0x808002A0: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x808002A4: bgez        $t1, L_808002DC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808002A8: nop
    
            goto L_808002DC;
    }
    // 0x808002A8: nop

    // 0x808002AC: jal         0x801065A4
    // 0x808002B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801065A4(rdram, ctx);
        goto after_20;
    // 0x808002B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_20:
    // 0x808002B4: beq         $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x808002B8: nop
    
            goto L_808002DC;
    }
    // 0x808002B8: nop

    // 0x808002BC: jal         0x801065A4
    // 0x808002C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801065A4(rdram, ctx);
        goto after_21;
    // 0x808002C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_21:
    // 0x808002C4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808002C8: addiu       $a2, $a2, 0x6128
    ctx->r6 = ADD32(ctx->r6, 0X6128);
    // 0x808002CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002D4: jal         0x80088660
    // 0x808002D8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_22;
    // 0x808002D8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_22:
L_808002DC:
    // 0x808002DC: jal         0x800EA05C
    // 0x808002E0: nop

    func_800EA05C(rdram, ctx);
        goto after_23;
    // 0x808002E0: nop

    after_23:
    // 0x808002E4: addiu       $at, $zero, 0x10D
    ctx->r1 = ADD32(0, 0X10D);
    // 0x808002E8: bnel        $v0, $at, L_808003F0
    if (ctx->r2 != ctx->r1) {
        // 0x808002EC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003F0;
    }
    goto skip_3;
    // 0x808002EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808002F0: lhu         $v0, 0x72($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X72);
    // 0x808002F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002F8: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    // 0x808002FC: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800300: beq         $t2, $at, L_80800314
    if (ctx->r10 == ctx->r1) {
        // 0x80800304: lui         $a1, 0x3FA6
        ctx->r5 = S32(0X3FA6 << 16);
            goto L_80800314;
    }
    // 0x80800304: lui         $a1, 0x3FA6
    ctx->r5 = S32(0X3FA6 << 16);
    // 0x80800308: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080030C: bnel        $t2, $at, L_808003F0
    if (ctx->r10 != ctx->r1) {
        // 0x80800310: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003F0;
    }
    goto skip_4;
    // 0x80800310: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
L_80800314:
    // 0x80800314: jal         0x800D9154
    // 0x80800318: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_800D9154(rdram, ctx);
        goto after_24;
    // 0x80800318: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_24:
    // 0x8080031C: beq         $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x80800320: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1100, 0XB54) << 16);
            goto L_808003EC;
    }
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB54) << 16);
    // 0x80800324: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800328: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080032C: lwc1        $f12, 0x54($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X54);
    // 0x80800330: jal         0x800F1214
    // 0x80800334: lwc1        $f14, 0xB54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB54));
    func_800F1214(rdram, ctx);
        goto after_25;
    // 0x80800334: lwc1        $f14, 0xB54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB54));
    after_25:
    // 0x80800338: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB58) << 16);
    // 0x8080033C: lwc1        $f18, 0xB58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB58));
    // 0x80800340: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800344: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80800348: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080034C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800350: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800354: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800358: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8080035C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800360: nop

    // 0x80800364: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800368: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080036C: nop

    // 0x80800370: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800374: beql        $a0, $zero, L_808003C4
    if (ctx->r4 == 0) {
        // 0x80800378: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_808003C4;
    }
    goto skip_5;
    // 0x80800378: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x8080037C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800384: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800388: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080038C: nop

    // 0x80800390: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800394: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800398: nop

    // 0x8080039C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003A0: bne         $a0, $zero, L_808003B8
    if (ctx->r4 != 0) {
        // 0x808003A4: nop
    
            goto L_808003B8;
    }
    // 0x808003A4: nop

    // 0x808003A8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x808003AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003B0: b           L_808003D0
    // 0x808003B4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808003D0;
    // 0x808003B4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808003B8:
    // 0x808003B8: b           L_808003D0
    // 0x808003BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808003D0;
    // 0x808003BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808003C0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_808003C4:
    // 0x808003C4: nop

    // 0x808003C8: bltz        $a0, L_808003B8
    if (SIGNED(ctx->r4) < 0) {
        // 0x808003CC: nop
    
            goto L_808003B8;
    }
    // 0x808003CC: nop

L_808003D0:
    // 0x808003D0: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x808003D4: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x808003D8: ori         $at, $at, 0x4566
    ctx->r1 = ctx->r1 | 0X4566;
    // 0x808003DC: sll         $t5, $t4, 21
    ctx->r13 = S32(ctx->r12 << 21);
    // 0x808003E0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808003E4: jal         0x800C4140
    // 0x808003E8: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_26;
    // 0x808003E8: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    after_26:
L_808003EC:
    // 0x808003EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003F0:
    // 0x808003F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808003FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800400: jr          $ra
    // 0x80800404: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800404: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void _chlakemonster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CC0: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CC0);
    return;
    // 0x80086CC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chmonsterinterior_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086550: syscall     336
    recomp_syscall_handler(rdram, ctx, 0x80086550);
    return;
    // 0x80086554: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D52F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D52F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D52F8: jr          $ra
    // 0x800D52FC: lh          $v0, -0x4BCE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BCE);
    return;
    // 0x800D52FC: lh          $v0, -0x4BCE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BCE);
;}
RECOMP_FUNC void _bskazmove_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834C0: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834C0);
    return;
    // 0x800834C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800000_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008E35C
    // 0x8080000C: nop

    player_inWater(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_800C32C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C32C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C32C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C32CC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C32D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C32D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C32D8: beq         $t6, $zero, L_800C32FC
    if (ctx->r14 == 0) {
        // 0x800C32DC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C32FC;
    }
    // 0x800C32DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C32E0: jal         0x800C1414
    // 0x800C32E4: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C32E4: nop

    after_0:
    // 0x800C32E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C32EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C32F0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C32F4: jal         0x800C13A0
    // 0x800C32F8: sb          $t7, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r15;
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C32F8: sb          $t7, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r15;
    after_1:
L_800C32FC:
    // 0x800C32FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3304: jr          $ra
    // 0x800C3308: nop

    return;
    // 0x800C3308: nop

;}
RECOMP_FUNC void func_80802ED4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802EDC: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80802EE0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80802EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802EE8: jal         0x80803124
    // 0x80802EEC: sh          $t6, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = ctx->r14;
    func_80803124_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802EEC: sh          $t6, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80802EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802EF8: jr          $ra
    // 0x80802EFC: nop

    return;
    // 0x80802EFC: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E48: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E48);
    return;
    // 0x80087E4C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800DC48C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC48C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC494: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DC498: jal         0x80020C08
    // 0x800DC49C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_80020C08(rdram, ctx);
        goto after_0;
    // 0x800DC49C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_0:
    // 0x800DC4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC4A8: jr          $ra
    // 0x800DC4AC: nop

    return;
    // 0x800DC4AC: nop

;}
RECOMP_FUNC void gczoomboxdata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002A4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808002A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2686, 0XAB0) << 16);
    // 0x808002B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002B4: jr          $ra
    // 0x808002B8: lbu         $v0, 0xAB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2686, 0XAB0));
    return;
    // 0x808002B8: lbu         $v0, 0xAB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2686, 0XAB0));
;}
RECOMP_FUNC void basnowball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800560: lw          $t6, 0x110($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X110);
    // 0x80800564: jr          $ra
    // 0x80800568: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    return;
    // 0x80800568: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
;}
RECOMP_FUNC void func_80802718_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080271C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802728: jal         0x80088078
    // 0x8080272C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080272C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80802730: beq         $v0, $zero, L_80802764
    if (ctx->r2 == 0) {
        // 0x80802734: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802764;
    }
    // 0x80802734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802738: jal         0x80100094
    // 0x8080273C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080273C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802740: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80802744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080274C: beq         $t6, $at, L_8080275C
    if (ctx->r14 == ctx->r1) {
        // 0x80802750: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080275C;
    }
    // 0x80802750: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802754: jal         0x80802878
    // 0x80802758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_8080275C:
    // 0x8080275C: b           L_80802768
    // 0x80802760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802768;
    // 0x80802760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80802764:
    // 0x80802764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802768:
    // 0x80802768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080276C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802770: jr          $ra
    // 0x80802774: nop

    return;
    // 0x80802774: nop

;}
RECOMP_FUNC void bastick_func_8009F258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F260: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8009F264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009F268: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8009F26C: jal         0x8009F1C8
    // 0x8009F270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_0;
    // 0x8009F270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009F274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009F278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F27C: jal         0x8009F1C8
    // 0x8009F280: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_1;
    // 0x8009F280: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x8009F284: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009F288: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009F28C: jal         0x8009F1C8
    // 0x8009F290: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x8009F290: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x8009F294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009F29C: jr          $ra
    // 0x8009F2A0: nop

    return;
    // 0x8009F2A0: nop

;}
RECOMP_FUNC void func_800F9098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F909C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F90A0: bne         $a0, $at, L_800F90BC
    if (ctx->r4 != ctx->r1) {
        // 0x800F90A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800F90BC;
    }
    // 0x800F90A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F90A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F90AC: jal         0x800EE7F8
    // 0x800F90B0: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800F90B0: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    after_0:
    // 0x800F90B4: b           L_800F90D0
    // 0x800F90B8: nop

        goto L_800F90D0;
    // 0x800F90B8: nop

L_800F90BC:
    // 0x800F90BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800F90C0: bne         $a0, $at, L_800F90D0
    if (ctx->r4 != ctx->r1) {
        // 0x800F90C4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800F90D0;
    }
    // 0x800F90C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F90C8: jal         0x800EE7F8
    // 0x800F90CC: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800F90CC: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    after_1:
L_800F90D0:
    // 0x800F90D0: jal         0x800EA05C
    // 0x800F90D4: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x800F90D4: nop

    after_2:
    // 0x800F90D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F90DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F90E0: sw          $v0, 0x551C($at)
    MEM_W(0X551C, ctx->r1) = ctx->r2;
    // 0x800F90E4: jr          $ra
    // 0x800F90E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F90E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FB0: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FB0);
    return;
    // 0x80087FB4: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
