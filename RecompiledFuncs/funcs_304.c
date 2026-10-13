#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bssnowball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CF0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X10B4) << 16);
    // 0x80800CF4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: lw          $v0, 0x10B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10B4));
    return;
    // 0x80800CFC: lw          $v0, 0x10B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10B4));
;}
RECOMP_FUNC void func_80801FE4_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801FE8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801FEC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801FF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801FF8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80801FFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802000: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80802004: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80802008: jal         0x800EE7F8
    // 0x8080200C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080200C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80802010: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802014: jal         0x800EE7F8
    // 0x80802018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80802018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8080201C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80802020: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80802024: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80802028: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080202C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802030: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80802034: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802038: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080203C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80802040: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80802044: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80802048: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8080204C: jal         0x800BEF00
    // 0x80802050: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80802050: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80802054: beq         $v0, $zero, L_8080206C
    if (ctx->r2 == 0) {
        // 0x80802058: lwc1        $f4, 0x2C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8080206C;
    }
    // 0x80802058: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080205C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80802060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802064: b           L_80802070
    // 0x80802068: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_80802070;
    // 0x80802068: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_8080206C:
    // 0x8080206C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802070:
    // 0x80802070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802074: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802078: jr          $ra
    // 0x8080207C: nop

    return;
    // 0x8080207C: nop

;}
RECOMP_FUNC void func_808000DC_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E8: jal         0x8009E474
    // 0x808000EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x808000EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80095774
    // 0x808000F8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x808000F8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_1:
    // 0x808000FC: jal         0x8009BC6C
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800104: jal         0x8009BC90
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080010C: jal         0x80092BE8
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_4;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800114: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800118: jal         0x8009C944
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_set(rdram, ctx);
        goto after_5;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x800931AC
    // 0x80800128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_6;
    // 0x80800128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080012C: jal         0x800832E8
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void chhellterskelter_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(964, 0X810) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X810));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X810));
;}
RECOMP_FUNC void func_8002ACE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002ACE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ACE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002ACEC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002ACF0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002ACF4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002ACF8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8002ACFC: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x8002AD00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8002AD04: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8002AD08: sb          $t7, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r15;
    // 0x8002AD0C: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x8002AD10: sb          $t8, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r24;
    // 0x8002AD14: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8002AD18: sb          $t9, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r25;
    // 0x8002AD1C: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x8002AD20: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    // 0x8002AD24: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8002AD28: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002AD2C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8002AD30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002AD34: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8002AD38: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AD3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002AD40: jal         0x80026500
    // 0x8002AD44: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x8002AD44: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x8002AD48: b           L_8002AD50
    // 0x8002AD4C: nop

        goto L_8002AD50;
    // 0x8002AD4C: nop

L_8002AD50:
    // 0x8002AD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AD54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002AD58: jr          $ra
    // 0x8002AD5C: nop

    return;
    // 0x8002AD5C: nop

;}
RECOMP_FUNC void func_80800000_idworldmake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800008: lw          $t6, 0x7EF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EF8);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080001C: bne         $t6, $zero, L_80800038
    if (ctx->r14 != 0) {
        // 0x80800020: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80800038;
    }
    // 0x80800020: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800024: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x80800028: jal         0x800B2D70
    // 0x8080002C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800034: sw          $v0, 0x7EF8($at)
    MEM_W(0X7EF8, ctx->r1) = ctx->r2;
L_80800038:
    // 0x80800038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080003C: jal         0x800B2974
    // 0x80800040: addiu       $a0, $a0, 0x7EF8
    ctx->r4 = ADD32(ctx->r4, 0X7EF8);
    vector_push_back(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $a0, 0x7EF8
    ctx->r4 = ADD32(ctx->r4, 0X7EF8);
    after_1:
    // 0x80800044: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080004C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80800050: sb          $t7, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r15;
    // 0x80800054: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800058: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8080005C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800060: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x80800064: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x80800068: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8080006C: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80800070: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2954, 0XAB0) << 16);
    // 0x80800074: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800078: lbu         $t2, 0x6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X6);
    // 0x8080007C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800080: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800084: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80800088: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8080008C: lw          $t9, 0xAB0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(2954, 0XAB0));
    // 0x80800090: jalr        $t9
    // 0x80800094: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800094: nop

    after_2:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void _chwaspstatue_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087640: syscall     599
    recomp_syscall_handler(rdram, ctx, 0x80087640);
    return;
    // 0x80087644: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chcanarymarycage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1572, 0X674) << 16);
    // 0x80800604: jr          $ra
    // 0x80800608: addiu       $v0, $v0, 0x674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1572, 0X674));
    return;
    // 0x80800608: addiu       $v0, $v0, 0x674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1572, 0X674));
    // 0x8080060C: nop

;}
RECOMP_FUNC void func_800D4400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4400: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D4404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D4408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D440C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D4410: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D4414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D4418: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800D441C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4420: jal         0x800D4D5C
    // 0x800D4424: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800D4D5C(rdram, ctx);
        goto after_0;
    // 0x800D4424: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D4428: jal         0x800C6784
    // 0x800D442C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C6784(rdram, ctx);
        goto after_1;
    // 0x800D442C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800D4430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D4434: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800D4438: jal         0x800C675C
    // 0x800D443C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C675C(rdram, ctx);
        goto after_2;
    // 0x800D443C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x800D4440: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800D4444: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D4448: lbu         $v0, 0x56($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X56);
    // 0x800D444C: sb          $zero, 0x56($s0)
    MEM_B(0X56, ctx->r16) = 0;
    // 0x800D4450: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D4454: lwc1        $f6, 0x5B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B20);
    // 0x800D4458: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D445C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D4460: nop

    // 0x800D4464: bc1tl       L_800D4524
    if (c1cs) {
        // 0x800D4468: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D4524;
    }
    goto skip_0;
    // 0x800D4468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D446C: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800D4470: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D4474: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800D4478: nop

    // 0x800D447C: bc1f        L_800D4490
    if (!c1cs) {
        // 0x800D4480: nop
    
            goto L_800D4490;
    }
    // 0x800D4480: nop

    // 0x800D4484: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x800D4488: b           L_800D4520
    // 0x800D448C: sb          $t6, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r14;
        goto L_800D4520;
    // 0x800D448C: sb          $t6, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r14;
L_800D4490:
    // 0x800D4490: beq         $v0, $zero, L_800D4520
    if (ctx->r2 == 0) {
        // 0x800D4494: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_800D4520;
    }
    // 0x800D4494: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800D4498: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800D449C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D44A0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D44A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D44A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800D44AC: nop

    // 0x800D44B0: bc1fl       L_800D4524
    if (!c1cs) {
        // 0x800D44B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D4524;
    }
    goto skip_1;
    // 0x800D44B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800D44B8: lwc1        $f18, 0x5B24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5B24);
    // 0x800D44BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800D44C0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800D44C4: nop

    // 0x800D44C8: bc1fl       L_800D4500
    if (!c1cs) {
        // 0x800D44CC: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800D4500;
    }
    goto skip_2;
    // 0x800D44CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x800D44D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D44D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D44D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D44DC: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800D44E0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800D44E4: nop

    // 0x800D44E8: bc1fl       L_800D4524
    if (!c1cs) {
        // 0x800D44EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D4524;
    }
    goto skip_3;
    // 0x800D44EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800D44F0: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x800D44F4: b           L_800D4520
    // 0x800D44F8: sb          $t8, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r24;
        goto L_800D4520;
    // 0x800D44F8: sb          $t8, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r24;
    // 0x800D44FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800D4500:
    // 0x800D4500: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D4504: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800D4508: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800D450C: nop

    // 0x800D4510: bc1fl       L_800D4524
    if (!c1cs) {
        // 0x800D4514: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D4524;
    }
    goto skip_4;
    // 0x800D4514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800D4518: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x800D451C: sb          $t9, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r25;
L_800D4520:
    // 0x800D4520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D4524:
    // 0x800D4524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D452C: jr          $ra
    // 0x800D4530: nop

    return;
    // 0x800D4530: nop

;}
RECOMP_FUNC void func_80800D88_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D88: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800D8C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800D90: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800D94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800D98: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800D9C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800DA0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800DA4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800DA8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800DAC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800DB0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800DB4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800DB8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80800DBC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80800DC0: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80800DC4: jal         0x800EC708
    // 0x80800DC8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800EC708(rdram, ctx);
        goto after_0;
    // 0x80800DC8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800DCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3230, 0X18C4) << 16);
    // 0x80800DD0: lwc1        $f4, 0x18C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3230, 0X18C4));
    // 0x80800DD4: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80800DD8: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x80800DDC: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800DE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800DE4: jal         0x800EE7F8
    // 0x80800DE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800DE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80800DEC: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x80800DF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800DF4: jal         0x800EF11C
    // 0x80800DF8: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    func_800EF11C(rdram, ctx);
        goto after_2;
    // 0x80800DF8: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    after_2:
    // 0x80800DFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3230, 0X18C8) << 16);
    // 0x80800E00: lwc1        $f6, 0x18C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3230, 0X18C8));
    // 0x80800E04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800E08: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80800E0C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800E10: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800E14: jal         0x800EF1B8
    // 0x80800E18: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80800E18: nop

    after_3:
    // 0x80800E1C: lw          $s7, 0x80($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X80);
    // 0x80800E20: bnel        $s7, $zero, L_80800E38
    if (ctx->r23 != 0) {
        // 0x80800E24: lw          $a0, 0x0($s7)
        ctx->r4 = MEM_W(ctx->r23, 0X0);
            goto L_80800E38;
    }
    goto skip_0;
    // 0x80800E24: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    skip_0:
    // 0x80800E28: jal         0x800BE444
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BE444(rdram, ctx);
        goto after_4;
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E30: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800E34: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
L_80800E38:
    // 0x80800E38: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
    // 0x80800E3C: beql        $a0, $zero, L_80800F04
    if (ctx->r4 == 0) {
        // 0x80800E40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800F04;
    }
    goto skip_1;
    // 0x80800E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80800E44:
    // 0x80800E44: jal         0x800E9E88
    // 0x80800E48: nop

    func_800E9E88(rdram, ctx);
        goto after_5;
    // 0x80800E48: nop

    after_5:
    // 0x80800E4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E50: jal         0x800E9EB4
    // 0x80800E54: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_6;
    // 0x80800E54: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_6:
    // 0x80800E58: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80800E5C: beq         $at, $zero, L_80800EF0
    if (ctx->r1 == 0) {
        // 0x80800E60: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800EF0;
    }
    // 0x80800E60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800E64: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80800E68:
    // 0x80800E68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800E6C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800E70: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800E74: beql        $t7, $zero, L_80800EE4
    if (ctx->r15 == 0) {
        // 0x80800E78: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80800EE4;
    }
    goto skip_2;
    // 0x80800E78: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x80800E7C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80800E80: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80800E84: jal         0x80801784
    // 0x80800E88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80801784_subaddierouteDll(rdram, ctx);
        goto after_7;
    // 0x80800E88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800E8C: beq         $v0, $zero, L_80800EE0
    if (ctx->r2 == 0) {
        // 0x80800E90: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800EE0;
    }
    // 0x80800E90: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800E94: jal         0x800EEB40
    // 0x80800E98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x80800E98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80800E9C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800EA0: add.s       $f2, $f20, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x80800EA4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800EA8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800EAC: nop

    // 0x80800EB0: bc1fl       L_80800EE4
    if (!c1cs) {
        // 0x80800EB4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80800EE4;
    }
    goto skip_3;
    // 0x80800EB4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_3:
    // 0x80800EB8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800EBC: jal         0x800EE940
    // 0x80800EC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE940(rdram, ctx);
        goto after_9;
    // 0x80800EC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80800EC4: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80800EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800ECC: lhu         $t8, 0x6($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6);
    // 0x80800ED0: sw          $s1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r17;
    // 0x80800ED4: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80800ED8: b           L_80800F04
    // 0x80800EDC: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
        goto L_80800F04;
    // 0x80800EDC: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
L_80800EE0:
    // 0x80800EE0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80800EE4:
    // 0x80800EE4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800EE8: bnel        $at, $zero, L_80800E68
    if (ctx->r1 != 0) {
        // 0x80800EEC: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_80800E68;
    }
    goto skip_4;
    // 0x80800EEC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_80800EF0:
    // 0x80800EF0: lw          $a0, 0x4($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X4);
    // 0x80800EF4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80800EF8: bne         $a0, $zero, L_80800E44
    if (ctx->r4 != 0) {
        // 0x80800EFC: nop
    
            goto L_80800E44;
    }
    // 0x80800EFC: nop

    // 0x80800F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F04:
    // 0x80800F04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F08: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800F0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800F14: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800F18: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800F1C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F20: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800F24: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800F28: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800F2C: jr          $ra
    // 0x80800F30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800F30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _babee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084548: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084548);
    return;
    // 0x8008454C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BD0: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BD0);
    return;
    // 0x80089BD4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C064C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C064C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C0650: jr          $ra
    // 0x800C0654: lh          $v0, -0x75EE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X75EE);
    return;
    // 0x800C0654: lh          $v0, -0x75EE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X75EE);
;}
RECOMP_FUNC void func_80090178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090180: jal         0x800F54E4
    // 0x80090184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009018C: jal         0x800F64A4
    // 0x80090190: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80090190: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009019C: jr          $ra
    // 0x800901A0: nop

    return;
    // 0x800901A0: nop

;}
RECOMP_FUNC void func_808094A4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808094A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808094A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808094AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808094B0: jal         0x80802D50
    // 0x808094B4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80802D50_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808094B4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808094B8: beq         $v0, $zero, L_808094C8
    if (ctx->r2 == 0) {
        // 0x808094BC: nop
    
            goto L_808094C8;
    }
    // 0x808094BC: nop

    // 0x808094C0: b           L_808094E4
    // 0x808094C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_808094E4;
    // 0x808094C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_808094C8:
    // 0x808094C8: jal         0x80808630
    // 0x808094CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80808630_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808094CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808094D0: beql        $v0, $zero, L_808094E4
    if (ctx->r2 == 0) {
        // 0x808094D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808094E4;
    }
    goto skip_0;
    // 0x808094D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808094D8: b           L_808094E4
    // 0x808094DC: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
        goto L_808094E4;
    // 0x808094DC: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
    // 0x808094E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808094E4:
    // 0x808094E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808094E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808094EC: jr          $ra
    // 0x808094F0: nop

    return;
    // 0x808094F0: nop

;}
RECOMP_FUNC void func_801027F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801027F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801027F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801027FC: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80102800: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80102804: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80102808: beql        $t7, $zero, L_80102834
    if (ctx->r15 == 0) {
        // 0x8010280C: addiu       $v0, $a0, 0x44
        ctx->r2 = ADD32(ctx->r4, 0X44);
            goto L_80102834;
    }
    goto skip_0;
    // 0x8010280C: addiu       $v0, $a0, 0x44
    ctx->r2 = ADD32(ctx->r4, 0X44);
    skip_0:
    // 0x80102810: jal         0x80102780
    // 0x80102814: addiu       $a1, $a1, 0x5AA0
    ctx->r5 = ADD32(ctx->r5, 0X5AA0);
    func_80102780(rdram, ctx);
        goto after_0;
    // 0x80102814: addiu       $a1, $a1, 0x5AA0
    ctx->r5 = ADD32(ctx->r5, 0X5AA0);
    after_0:
    // 0x80102818: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010281C: addiu       $v0, $a1, 0x5AA0
    ctx->r2 = ADD32(ctx->r5, 0X5AA0);
    // 0x80102820: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80102824: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80102828: b           L_80102834
    // 0x8010282C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80102834;
    // 0x8010282C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80102830: addiu       $v0, $a0, 0x44
    ctx->r2 = ADD32(ctx->r4, 0X44);
L_80102834:
    // 0x80102834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010283C: jr          $ra
    // 0x80102840: nop

    return;
    // 0x80102840: nop

;}
RECOMP_FUNC void func_800A1294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1294: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A1298: lbu         $t6, 0x7094($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7094);
    // 0x800A129C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A12A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A12A4: bne         $t6, $zero, L_800A1354
    if (ctx->r14 != 0) {
        // 0x800A12A8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800A1354;
    }
    // 0x800A12A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A12AC: jal         0x800D3948
    // 0x800A12B0: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x800A12B0: nop

    after_0:
    // 0x800A12B4: bnel        $v0, $zero, L_800A1358
    if (ctx->r2 != 0) {
        // 0x800A12B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1358;
    }
    goto skip_0;
    // 0x800A12B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A12BC: jal         0x800DA298
    // 0x800A12C0: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800A12C0: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_1:
    // 0x800A12C4: bnel        $v0, $zero, L_800A1358
    if (ctx->r2 != 0) {
        // 0x800A12C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1358;
    }
    goto skip_1;
    // 0x800A12C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A12CC: jal         0x800D3E40
    // 0x800A12D0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800D3E40(rdram, ctx);
        goto after_2;
    // 0x800A12D0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_2:
    // 0x800A12D4: bne         $v0, $zero, L_800A1354
    if (ctx->r2 != 0) {
        // 0x800A12D8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A1354;
    }
    // 0x800A12D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A12DC: lbu         $t7, 0x7097($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7097);
    // 0x800A12E0: bnel        $t7, $zero, L_800A1358
    if (ctx->r15 != 0) {
        // 0x800A12E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1358;
    }
    goto skip_2;
    // 0x800A12E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800A12E8: jal         0x8008FD48
    // 0x800A12EC: nop

    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x800A12EC: nop

    after_3:
    // 0x800A12F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A12F4: jal         0x800D4EB8
    // 0x800A12F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D4EB8(rdram, ctx);
        goto after_4;
    // 0x800A12F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800A12FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1300: beq         $v0, $zero, L_800A1354
    if (ctx->r2 == 0) {
        // 0x800A1304: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800A1354;
    }
    // 0x800A1304: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A1308: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A130C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A1310: beq         $t8, $zero, L_800A133C
    if (ctx->r24 == 0) {
        // 0x800A1314: nop
    
            goto L_800A133C;
    }
    // 0x800A1314: nop

    // 0x800A1318: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A131C: jal         0x800D4E7C
    // 0x800A1320: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D4E7C(rdram, ctx);
        goto after_5;
    // 0x800A1320: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x800A1324: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A1328: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x800A132C: jal         0x800D2498
    // 0x800A1330: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D2498(rdram, ctx);
        goto after_6;
    // 0x800A1330: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800A1334: b           L_800A1358
    // 0x800A1338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A1358;
    // 0x800A1338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A133C:
    // 0x800A133C: jal         0x800D4E7C
    // 0x800A1340: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D4E7C(rdram, ctx);
        goto after_7;
    // 0x800A1340: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_7:
    // 0x800A1344: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A1348: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x800A134C: jal         0x800D24E8
    // 0x800A1350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D24E8(rdram, ctx);
        goto after_8;
    // 0x800A1350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_800A1354:
    // 0x800A1354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1358:
    // 0x800A1358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A135C: jr          $ra
    // 0x800A1360: nop

    return;
    // 0x800A1360: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086098: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x80086098);
    return;
    // 0x8008609C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DFC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFC80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DFC84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFC88: jal         0x8001ACCC
    // 0x800DFC8C: addiu       $a0, $zero, 0x1110
    ctx->r4 = ADD32(0, 0X1110);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800DFC8C: addiu       $a0, $zero, 0x1110
    ctx->r4 = ADD32(0, 0X1110);
    after_0:
    // 0x800DFC90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800DFC94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800DFC98: addiu       $t7, $zero, 0x6D
    ctx->r15 = ADD32(0, 0X6D);
    // 0x800DFC9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800DFCA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800DFCA4: jal         0x800DFAD0
    // 0x800DFCA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DFAD0(rdram, ctx);
        goto after_1;
    // 0x800DFCA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800DFCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFCB0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DFCB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DFCB8: jr          $ra
    // 0x800DFCBC: nop

    return;
    // 0x800DFCBC: nop

;}
RECOMP_FUNC void chtoxicroomprops_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2492, 0XA30) << 16);
    // 0x808006F8: jr          $ra
    // 0x808006FC: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0XA30));
    return;
    // 0x808006FC: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0XA30));
;}
RECOMP_FUNC void bavan_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800124: lw          $t6, 0x144($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X144);
    // 0x80800128: jr          $ra
    // 0x8080012C: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8080012C: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80025678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025678: jr          $ra
    // 0x8002567C: nop

    return;
    // 0x8002567C: nop

;}
RECOMP_FUNC void func_808061AC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808061AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808061B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808061B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808061B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808061BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808061C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808061C4: jal         0x80802458
    // 0x808061C8: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808061C8: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x808061CC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x808061D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808061D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808061D8: beq         $a2, $zero, L_80806208
    if (ctx->r6 == 0) {
        // 0x808061DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806208;
    }
    // 0x808061DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061E0: beq         $a2, $at, L_8080622C
    if (ctx->r6 == ctx->r1) {
        // 0x808061E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080622C;
    }
    // 0x808061E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808061EC: beq         $a2, $at, L_80806254
    if (ctx->r6 == ctx->r1) {
        // 0x808061F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806254;
    }
    // 0x808061F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808061F8: beq         $a2, $at, L_8080627C
    if (ctx->r6 == ctx->r1) {
        // 0x808061FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080627C;
    }
    // 0x808061FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806200: b           L_80806328
    // 0x80806204: sw          $a2, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->r6;
        goto L_80806328;
    // 0x80806204: sw          $a2, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->r6;
L_80806208:
    // 0x80806208: jal         0x8009BCB4
    // 0x8080620C: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x8080620C: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    after_1:
    // 0x80806210: jal         0x80806774
    // 0x80806214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806774_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80806218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080621C: jal         0x8009B800
    // 0x80806220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    baphysics_set_type(rdram, ctx);
        goto after_3;
    // 0x80806220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80806224: b           L_80806324
    // 0x80806228: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
        goto L_80806324;
    // 0x80806228: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_8080622C:
    // 0x8080622C: jal         0x8009BCB4
    // 0x80806230: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x80806230: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    after_4:
    // 0x80806234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806238: jal         0x8009B800
    // 0x8080623C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baphysics_set_type(rdram, ctx);
        goto after_5;
    // 0x8080623C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
    // 0x80806240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806244: jal         0x8009B9B0
    // 0x80806248: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80806248: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x8080624C: b           L_80806324
    // 0x80806250: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
        goto L_80806324;
    // 0x80806250: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_80806254:
    // 0x80806254: jal         0x8009BCB4
    // 0x80806258: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    baphysics_set_gravity(rdram, ctx);
        goto after_7;
    // 0x80806258: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    after_7:
    // 0x8080625C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80806260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806264: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80806268: swc1        $f0, 0x1D8($s1)
    MEM_W(0X1D8, ctx->r17) = ctx->f0.u32l;
    // 0x8080626C: jal         0x8009B800
    // 0x80806270: swc1        $f0, 0x1D4($s1)
    MEM_W(0X1D4, ctx->r17) = ctx->f0.u32l;
    baphysics_set_type(rdram, ctx);
        goto after_8;
    // 0x80806270: swc1        $f0, 0x1D4($s1)
    MEM_W(0X1D4, ctx->r17) = ctx->f0.u32l;
    after_8:
    // 0x80806274: b           L_80806324
    // 0x80806278: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
        goto L_80806324;
    // 0x80806278: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_8080627C:
    // 0x8080627C: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    // 0x80806280: jal         0x8009BCB4
    // 0x80806284: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x80806284: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_9:
    // 0x80806288: lw          $t6, 0x19C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X19C);
    // 0x8080628C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80806290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806294: beq         $t6, $at, L_80806314
    if (ctx->r14 == ctx->r1) {
        // 0x80806298: addiu       $a1, $s1, 0x1A0
        ctx->r5 = ADD32(ctx->r17, 0X1A0);
            goto L_80806314;
    }
    // 0x80806298: addiu       $a1, $s1, 0x1A0
    ctx->r5 = ADD32(ctx->r17, 0X1A0);
    // 0x8080629C: jal         0x800F3BB0
    // 0x808062A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800F3BB0(rdram, ctx);
        goto after_10;
    // 0x808062A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_10:
    // 0x808062A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808062A8: jal         0x800EE7F8
    // 0x808062AC: addiu       $a0, $s1, 0x1AC
    ctx->r4 = ADD32(ctx->r17, 0X1AC);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808062AC: addiu       $a0, $s1, 0x1AC
    ctx->r4 = ADD32(ctx->r17, 0X1AC);
    after_11:
    // 0x808062B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808062B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808062B8: jal         0x8009BB5C
    // 0x808062BC: swc1        $f0, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->f0.u32l;
    func_8009BB5C(rdram, ctx);
        goto after_12;
    // 0x808062BC: swc1        $f0, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->f0.u32l;
    after_12:
    // 0x808062C0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808062C4: jal         0x8009C984
    // 0x808062C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_13;
    // 0x808062C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808062CC: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x808062D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808062D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808062D8: lwc1        $f4, 0x40($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X40);
    // 0x808062DC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808062E0: jal         0x80013728
    // 0x808062E4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_80013728(rdram, ctx);
        goto after_14;
    // 0x808062E4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_14:
    // 0x808062E8: jal         0x800138D0
    // 0x808062EC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_15;
    // 0x808062EC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_15:
    // 0x808062F0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808062F4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x808062F8: lwc1        $f4, 0x12C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x808062FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80806300: swc1        $f18, 0x1E4($s1)
    MEM_W(0X1E4, ctx->r17) = ctx->f18.u32l;
    // 0x80806304: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80806308: lwc1        $f6, 0x44($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8080630C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80806310: swc1        $f8, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->f8.u32l;
L_80806314:
    // 0x80806314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806318: jal         0x8009B800
    // 0x8080631C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    baphysics_set_type(rdram, ctx);
        goto after_16;
    // 0x8080631C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_16:
    // 0x80806320: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_80806324:
    // 0x80806324: sw          $a2, 0x19C($s1)
    MEM_W(0X19C, ctx->r17) = ctx->r6;
L_80806328:
    // 0x80806328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080632C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80806330: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80806334: jr          $ra
    // 0x80806338: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80806338: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8080130C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080130C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801314: jal         0x800839B8
    // 0x80801318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080131C: jal         0x808000F0
    // 0x80801320: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801320: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080132C: jr          $ra
    // 0x80801330: nop

    return;
    // 0x80801330: nop

;}
RECOMP_FUNC void _gcnewpause_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088200: syscall     675
    recomp_syscall_handler(rdram, ctx, 0x80088200);
    return;
    // 0x80088204: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802B74_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802B80: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80802B84: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80802B88: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80802B8C: bnel        $t8, $at, L_80802BA0
    if (ctx->r24 != ctx->r1) {
        // 0x80802B90: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802BA0;
    }
    goto skip_0;
    // 0x80802B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80802B94: jal         0x800904C8
    // 0x80802B98: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_0;
    // 0x80802B98: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80802B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80802BA0:
    // 0x80802BA0: jal         0x80100094
    // 0x80802BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80802BA8: beq         $v0, $zero, L_80802BB8
    if (ctx->r2 == 0) {
        // 0x80802BAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802BB8;
    }
    // 0x80802BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802BB0: jal         0x800897C8
    // 0x80802BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80802BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80802BB8:
    // 0x80802BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802BC0: jr          $ra
    // 0x80802BC4: nop

    return;
    // 0x80802BC4: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803430: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803434: andi        $t7, $t6, 0xFD
    ctx->r15 = ctx->r14 & 0XFD;
    // 0x80803438: jr          $ra
    // 0x8080343C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080343C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800A8F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8F68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8F6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A8F70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8F78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A8F7C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_800A8F80:
    // 0x800A8F80: jal         0x800A91F4
    // 0x800A8F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A91F4(rdram, ctx);
        goto after_0;
    // 0x800A8F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A8F88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A8F8C: bne         $s0, $s1, L_800A8F80
    if (ctx->r16 != ctx->r17) {
        // 0x800A8F90: nop
    
            goto L_800A8F80;
    }
    // 0x800A8F90: nop

    // 0x800A8F94: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8F98: addiu       $s1, $s1, 0x76D0
    ctx->r17 = ADD32(ctx->r17, 0X76D0);
    // 0x800A8F9C: lh          $s0, 0x2($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X2);
    // 0x800A8FA0: beql        $s0, $zero, L_800A8FCC
    if (ctx->r16 == 0) {
        // 0x800A8FA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A8FCC;
    }
    goto skip_0;
    // 0x800A8FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800A8FA8:
    // 0x800A8FA8: jal         0x800A87FC
    // 0x800A8FAC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    func_800A87FC(rdram, ctx);
        goto after_1;
    // 0x800A8FAC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    after_1:
    // 0x800A8FB0: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x800A8FB4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800A8FB8: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x800A8FBC: lh          $s0, 0x2($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X2);
    // 0x800A8FC0: bne         $s0, $zero, L_800A8FA8
    if (ctx->r16 != 0) {
        // 0x800A8FC4: nop
    
            goto L_800A8FA8;
    }
    // 0x800A8FC4: nop

    // 0x800A8FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A8FCC:
    // 0x800A8FCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A8FD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A8FD4: jr          $ra
    // 0x800A8FD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A8FD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800088_baflamethrower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: lw          $v0, 0x88($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X88);
    // 0x80800094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800098: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080009C: lbu         $v1, 0xC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC);
    // 0x808000A0: beql        $v1, $a2, L_808000B4
    if (ctx->r3 == ctx->r6) {
        // 0x808000A4: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_808000B4;
    }
    goto skip_0;
    // 0x808000A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_0:
    // 0x808000A8: bne         $v1, $a3, L_808000BC
    if (ctx->r3 != ctx->r7) {
        // 0x808000AC: nop
    
            goto L_808000BC;
    }
    // 0x808000AC: nop

    // 0x808000B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_808000B4:
    // 0x808000B4: beql        $a1, $a3, L_80800148
    if (ctx->r5 == ctx->r7) {
        // 0x808000B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800148;
    }
    goto skip_1;
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808000BC:
    // 0x808000BC: beq         $a1, $zero, L_80800144
    if (ctx->r5 == 0) {
        // 0x808000C0: sb          $a1, 0xC($v0)
        MEM_B(0XC, ctx->r2) = ctx->r5;
            goto L_80800144;
    }
    // 0x808000C0: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x808000C4: beq         $a1, $a2, L_808000E4
    if (ctx->r5 == ctx->r6) {
        // 0x808000C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000E4;
    }
    // 0x808000C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000CC: beql        $a1, $at, L_8080010C
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8080010C;
    }
    goto skip_2;
    // 0x808000D0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_2:
    // 0x808000D4: beq         $a1, $a3, L_80800134
    if (ctx->r5 == ctx->r7) {
        // 0x808000D8: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80800134;
    }
    // 0x808000D8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000DC: b           L_80800148
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800148;
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E4:
    // 0x808000E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000E8: lw          $t6, 0x88($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X88);
    // 0x808000EC: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x808000F0: lw          $v0, 0x88($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X88);
    // 0x808000F4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808000F8: jal         0x80800008
    // 0x808000FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    func_80800008_baflamethrower(rdram, ctx);
        goto after_0;
    // 0x808000FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x80800100: b           L_80800148
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800148;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_8080010C:
    // 0x8080010C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800110: lw          $t7, 0x88($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X88);
    // 0x80800114: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080011C: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x80800120: lw          $t8, 0x88($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X88);
    // 0x80800124: jal         0x80800008
    // 0x80800128: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    func_80800008_baflamethrower(rdram, ctx);
        goto after_1;
    // 0x80800128: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    after_1:
    // 0x8080012C: b           L_80800148
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800148;
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800138: lw          $t9, 0x88($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X88);
    // 0x8080013C: jal         0x80084B60
    // 0x80800140: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    _baflameline_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800140: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    after_2:
L_80800144:
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800148:
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_808017D0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017E0: jal         0x80100094
    // 0x808017E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808017E8: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808017F4: jal         0x80801568
    // 0x808017F8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80801568_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x808017F8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_1:
    // 0x808017FC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801800: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1692, 0X45E8) << 16);
    // 0x80801804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801808: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080180C: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x80801810: lh          $a2, 0x45E8($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(1692, 0X45E8));
    // 0x80801814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801818: addiu       $a3, $zero, 0x2C21
    ctx->r7 = ADD32(0, 0X2C21);
    // 0x8080181C: beq         $a2, $at, L_80801834
    if (ctx->r6 == ctx->r1) {
        // 0x80801820: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801834;
    }
    // 0x80801820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801824: jal         0x80085708
    // 0x80801828: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80801828: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8080182C: b           L_8080184C
    // 0x80801830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080184C;
    // 0x80801830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801834:
    // 0x80801834: jal         0x808012A4
    // 0x80801838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80801838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080183C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801840: jal         0x808009DC
    // 0x80801844: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x80801844: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80801848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080184C:
    // 0x8080184C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801854: jr          $ra
    // 0x80801858: nop

    return;
    // 0x80801858: nop

;}
RECOMP_FUNC void func_80800228_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080022C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800234: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080023C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800240: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800244: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800248: beq         $at, $zero, L_80800530
    if (ctx->r1 == 0) {
        // 0x8080024C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800530;
    }
    // 0x8080024C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800250: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2392, 0XC80) << 16);
    // 0x80800254: addu        $at, $at, $t8
    gpr jr_addend_8080025C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800258: lw          $t8, 0xC80($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2392, 0XC80));
    // 0x8080025C: jr          $t8
    // 0x80800260: nop

    switch (jr_addend_8080025C >> 2) {
        case 0: goto L_80800264; break;
        case 1: goto L_808002C0; break;
        case 2: goto L_808002E0; break;
        case 3: goto L_80800410; break;
        case 4: goto L_808004BC; break;
        case 5: goto L_80800508; break;
        default: switch_error(__func__, 0x8080025C, 0x80800C80);
    }
    // 0x80800260: nop

L_80800264:
    // 0x80800264: jal         0x80800050
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800050_chfantasycannon(rdram, ctx);
        goto after_0;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080026C: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800270: lui         $at, 0x4362
        ctx->r1 = S32(0X4362 << 16);
            goto L_80800288;
    }
    // 0x80800270: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80800544
    // 0x8080027C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_1;
    // 0x8080027C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800280: b           L_80800534
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800288:
    // 0x80800288: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080028C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800290: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800294: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800298: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080029C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002A0: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x808002A4: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002B0: jal         0x80089F18
    // 0x808002B4: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808002B4: nop

    after_2:
    // 0x808002B8: b           L_80800534
    // 0x808002BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x808002BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002C0:
    // 0x808002C0: jal         0x800D90A4
    // 0x808002C4: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808002C4: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    after_3:
    // 0x808002C8: beq         $v0, $zero, L_80800530
    if (ctx->r2 == 0) {
        // 0x808002CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800530;
    }
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x80800544
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_4;
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808002D8: b           L_80800534
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002E0:
    // 0x808002E0: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x808002E4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x808002E8: jal         0x80101E14
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002F0: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002F4: lui         $a0, 0x7FFB
        ctx->r4 = S32(0X7FFB << 16);
            goto L_8080030C;
    }
    // 0x808002F4: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x808002F8: jal         0x800C3F48
    // 0x808002FC: ori         $a0, $a0, 0x5E0D
    ctx->r4 = ctx->r4 | 0X5E0D;
    func_800C3F48(rdram, ctx);
        goto after_6;
    // 0x808002FC: ori         $a0, $a0, 0x5E0D
    ctx->r4 = ctx->r4 | 0X5E0D;
    after_6:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80800544
    // 0x80800308: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_7;
    // 0x80800308: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_8080030C:
    // 0x8080030C: lui         $a1, 0x3E23
    ctx->r5 = S32(0X3E23 << 16);
    // 0x80800310: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800314: jal         0x80101E14
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080031C: beql        $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800320: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800348;
    }
    goto skip_0;
    // 0x80800320: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x80800324: jal         0x800F54E4
    // 0x80800328: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800328: nop

    after_9:
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: jal         0x800F4CEC
    // 0x80800334: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_800F4CEC(rdram, ctx);
        goto after_10;
    // 0x80800334: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_10:
    // 0x80800338: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080033C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800340: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800344: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800348:
    // 0x80800348: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8080034C: jal         0x80101E14
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800354: beq         $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800358: lui         $a0, 0x665B
        ctx->r4 = S32(0X665B << 16);
            goto L_80800364;
    }
    // 0x80800358: lui         $a0, 0x665B
    ctx->r4 = S32(0X665B << 16);
    // 0x8080035C: jal         0x800C3F48
    // 0x80800360: ori         $a0, $a0, 0x5E0C
    ctx->r4 = ctx->r4 | 0X5E0C;
    func_800C3F48(rdram, ctx);
        goto after_12;
    // 0x80800360: ori         $a0, $a0, 0x5E0C
    ctx->r4 = ctx->r4 | 0X5E0C;
    after_12:
L_80800364:
    // 0x80800364: jal         0x80101F24
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_13;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2392, 0XC98) << 16);
    // 0x80800370: lwc1        $f16, 0xC98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2392, 0XC98));
    // 0x80800374: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80800378: nop

    // 0x8080037C: bc1fl       L_80800534
    if (!c1cs) {
        // 0x80800380: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800534;
    }
    goto skip_1;
    // 0x80800380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800384: jal         0x80101F24
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_14;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080038C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800394: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800398: lui         $a2, 0x3E23
    ctx->r6 = S32(0X3E23 << 16);
    // 0x8080039C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808003A0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808003A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003A8: jal         0x800F10B4
    // 0x808003AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x808003AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x808003B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808003B8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808003BC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808003C0: jal         0x800EFE50
    // 0x808003C4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800EFE50(rdram, ctx);
        goto after_16;
    // 0x808003C4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x808003C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003D0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003D4: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003D8: jal         0x80013970
    // 0x808003DC: nop

    func_80013970(rdram, ctx);
        goto after_17;
    // 0x808003DC: nop

    after_17:
    // 0x808003E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808003E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808003EC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808003F0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808003F4: jal         0x800F54E4
    // 0x808003F8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808003F8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800400: jal         0x800F8294
    // 0x80800404: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F8294(rdram, ctx);
        goto after_19;
    // 0x80800404: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_19:
    // 0x80800408: b           L_80800534
    // 0x8080040C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x8080040C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800410:
    // 0x80800410: jal         0x80101DDC
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800418: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x8080041C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80800544
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_21;
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_21:
    // 0x80800428: b           L_80800498
    // 0x8080042C: nop

        goto L_80800498;
    // 0x8080042C: nop

L_80800430:
    // 0x80800430: jal         0x80101F24
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_22;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800438: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080043C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800440: nop

    // 0x80800444: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800448: nop

    // 0x8080044C: bc1f        L_80800498
    if (!c1cs) {
        // 0x80800450: nop
    
            goto L_80800498;
    }
    // 0x80800450: nop

    // 0x80800454: jal         0x808000A4
    // 0x80800458: nop

    func_808000A4_chfantasycannon(rdram, ctx);
        goto after_23;
    // 0x80800458: nop

    after_23:
    // 0x8080045C: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80800468: bltz        $t3, L_80800498
    if (SIGNED(ctx->r11) < 0) {
        // 0x8080046C: nop
    
            goto L_80800498;
    }
    // 0x8080046C: nop

    // 0x80800470: jal         0x80101E14
    // 0x80800474: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x80800474: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_24:
    // 0x80800478: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x8080047C: nop
    
            goto L_80800498;
    }
    // 0x8080047C: nop

    // 0x80800480: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800484: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80800488: jal         0x800F54E4
    // 0x8080048C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x8080048C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    after_25:
    // 0x80800490: jal         0x800F4CC0
    // 0x80800494: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_26;
    // 0x80800494: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
L_80800498:
    // 0x80800498: jal         0x800F54E4
    // 0x8080049C: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x8080049C: nop

    after_27:
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A4: jal         0x800F7B9C
    // 0x808004A8: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_800F7B9C(rdram, ctx);
        goto after_28;
    // 0x808004A8: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_28:
    // 0x808004AC: jal         0x808008B0
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chfantasycannon(rdram, ctx);
        goto after_29;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808004B4: b           L_80800534
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004BC:
    // 0x808004BC: jal         0x808000A4
    // 0x808004C0: nop

    func_808000A4_chfantasycannon(rdram, ctx);
        goto after_30;
    // 0x808004C0: nop

    after_30:
    // 0x808004C4: jal         0x800F54E4
    // 0x808004C8: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x808004C8: nop

    after_31:
    // 0x808004CC: jal         0x800F6C5C
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_32;
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_32:
    // 0x808004D4: beq         $v0, $zero, L_808004E4
    if (ctx->r2 == 0) {
        // 0x808004D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E4;
    }
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x80800544
    // 0x808004E0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_33;
    // 0x808004E0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_33:
L_808004E4:
    // 0x808004E4: jal         0x800F54E4
    // 0x808004E8: nop

    func_800F54E4(rdram, ctx);
        goto after_34;
    // 0x808004E8: nop

    after_34:
    // 0x808004EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F0: jal         0x800F7B9C
    // 0x808004F4: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_800F7B9C(rdram, ctx);
        goto after_35;
    // 0x808004F4: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_35:
    // 0x808004F8: jal         0x808008B0
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chfantasycannon(rdram, ctx);
        goto after_36;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800500: b           L_80800534
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800508:
    // 0x80800508: jal         0x800D90A4
    // 0x8080050C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    func_800D90A4(rdram, ctx);
        goto after_37;
    // 0x8080050C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    after_37:
    // 0x80800510: beq         $v0, $zero, L_80800528
    if (ctx->r2 == 0) {
        // 0x80800514: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800528;
    }
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x80800544
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800544_chfantasycannon(rdram, ctx);
        goto after_38;
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x80800520: b           L_80800534
    // 0x80800524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800534;
    // 0x80800524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800528:
    // 0x80800528: jal         0x808008B0
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chfantasycannon(rdram, ctx);
        goto after_39;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
L_80800530:
    // 0x80800530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800534:
    // 0x80800534: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800538: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void func_80800598_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: jal         0x80100094
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005A8: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x808005AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B4: jr          $ra
    // 0x808005B8: nop

    return;
    // 0x808005B8: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800C3C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800C40: jal         0x8008CABC
    // 0x80800C44: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C44: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800C48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(104, 0X1464) << 16);
    // 0x80800C4C: lwc1        $f4, 0x1464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0X1464));
    // 0x80800C50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C58: jal         0x8008AF24
    // 0x80800C5C: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800C5C: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C64: jal         0x8008AED4
    // 0x80800C68: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800C68: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_2:
    // 0x80800C6C: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800C70: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800C74: jal         0x8008B1C8
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C80: jal         0x8008B1BC
    // 0x80800C84: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800C84: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: jal         0x8008B24C
    // 0x80800C90: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800C90: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    after_5:
    // 0x80800C94: lui         $a2, 0x3ED7
    ctx->r6 = S32(0X3ED7 << 16);
    // 0x80800C98: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x8008B1D4
    // 0x80800CA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800CA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CAC: jal         0x8008B134
    // 0x80800CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800CB4: jal         0x8008B064
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800CBC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800CC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800CD0: jal         0x8009FFD8
    // 0x80800CD4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800CD4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800CD8: jal         0x8009EF04
    // 0x80800CDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x80800CDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800CE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800CE4: nop

    // 0x80800CE8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800CEC: nop

    // 0x80800CF0: bc1t        L_80800D0C
    if (c1cs) {
        // 0x80800CF4: nop
    
            goto L_80800D0C;
    }
    // 0x80800CF4: nop

    // 0x80800CF8: jal         0x8009EEB8
    // 0x80800CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x80800CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800D00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D04: jal         0x8009C914
    // 0x80800D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x80800D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_80800D0C:
    // 0x80800D0C: jal         0x8009C990
    // 0x80800D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x80800D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800D14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D18: jal         0x8009B9C0
    // 0x80800D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x80800D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800D20: jal         0x80800064
    // 0x80800D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800064_bsblongleg(rdram, ctx);
        goto after_15;
    // 0x80800D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800D28: jal         0x8009C990
    // 0x80800D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x80800D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800D30: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800D34: jal         0x8009BB00
    // 0x80800D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800D3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D44: jal         0x8009BA68
    // 0x80800D48: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800D48: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D50: jal         0x8009BA58
    // 0x80800D54: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80800D54: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_19:
    // 0x80800D58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D5C: jal         0x8009BCB4
    // 0x80800D60: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x80800D60: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    after_20:
    // 0x80800D64: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800D68: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D70: jal         0x8009DE38
    // 0x80800D74: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    func_8009DE38(rdram, ctx);
        goto after_21;
    // 0x80800D74: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    after_21:
    // 0x80800D78: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800D7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D80: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800D84: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800D8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801680_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801680: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080168C: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80801690: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801694: beq         $at, $zero, L_808019F0
    if (ctx->r1 == 0) {
        // 0x80801698: sb          $a1, 0x15C($a0)
        MEM_B(0X15C, ctx->r4) = ctx->r5;
            goto L_808019F0;
    }
    // 0x80801698: sb          $a1, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = ctx->r5;
    // 0x8080169C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808016A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DDC) << 16);
    // 0x808016A4: addu        $at, $at, $t6
    gpr jr_addend_808016AC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808016A8: lw          $t6, 0x1DDC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DDC));
    // 0x808016AC: jr          $t6
    // 0x808016B0: nop

    switch (jr_addend_808016AC >> 2) {
        case 0: goto L_808019D0; break;
        case 1: goto L_808016B4; break;
        case 2: goto L_808018E0; break;
        case 3: goto L_808018FC; break;
        case 4: goto L_80801934; break;
        default: switch_error(__func__, 0x808016AC, 0x80801DDC);
    }
    // 0x808016B0: nop

L_808016B4:
    // 0x808016B4: jal         0x8008CABC
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808016BC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808016C0: jal         0x8008E35C
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016CC: jal         0x8008E078
    // 0x808016D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x808016D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x808016D4: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x808016D8: bne         $a2, $zero, L_808016E4
    if (ctx->r6 != 0) {
        // 0x808016DC: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_808016E4;
    }
    // 0x808016DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808016E0: sltu        $a2, $zero, $a1
    ctx->r6 = 0 < ctx->r5 ? 1 : 0;
L_808016E4:
    // 0x808016E4: sltu        $t7, $zero, $a1
    ctx->r15 = 0 < ctx->r5 ? 1 : 0;
    // 0x808016E8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F0: jal         0x80800A78
    // 0x808016F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80800A78_bsbansack(rdram, ctx);
        goto after_3;
    // 0x808016F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x808016F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DF0) << 16);
    // 0x808016FC: lwc1        $f12, 0x1DF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DF0));
    // 0x80801700: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DF4) << 16);
    // 0x80801704: jal         0x800DC178
    // 0x80801708: lwc1        $f14, 0x1DF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DF4));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801708: lwc1        $f14, 0x1DF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DF4));
    after_4:
    // 0x8080170C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801714: addiu       $a1, $zero, 0x3F0
    ctx->r5 = ADD32(0, 0X3F0);
    // 0x80801718: jal         0x8009DB04
    // 0x8080171C: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x8080171C: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_5:
    // 0x80801720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801724: jal         0x800A2EEC
    // 0x80801728: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A2EEC(rdram, ctx);
        goto after_6;
    // 0x80801728: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8080172C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80801730: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080173C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801740: jal         0x8009FFD8
    // 0x80801744: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x80801744: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80801748: jal         0x8009EF04
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_8;
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801750: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801754: nop

    // 0x80801758: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080175C: nop

    // 0x80801760: bc1t        L_8080177C
    if (c1cs) {
        // 0x80801764: nop
    
            goto L_8080177C;
    }
    // 0x80801764: nop

    // 0x80801768: jal         0x8009EEB8
    // 0x8080176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_9;
    // 0x8080176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801770: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801774: jal         0x8009C914
    // 0x80801778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_10;
    // 0x80801778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_8080177C:
    // 0x8080177C: jal         0x808001D4
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_11;
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801784: jal         0x8009BB00
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080178C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801790: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801794: beq         $t9, $zero, L_808017F4
    if (ctx->r25 == 0) {
        // 0x80801798: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_808017F4;
    }
    // 0x80801798: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080179C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DF8) << 16);
    // 0x808017A4: lwc1        $f6, 0x1DF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DF8));
    // 0x808017A8: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x808017AC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808017B0: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808017B4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x808017B8: jal         0x800F10B4
    // 0x808017BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x808017BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x808017C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808017C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DFC) << 16);
    // 0x808017CC: lwc1        $f8, 0x1DFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DFC));
    // 0x808017D0: lui         $a3, 0x43AD
    ctx->r7 = S32(0X43AD << 16);
    // 0x808017D4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808017D8: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x808017DC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808017E0: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808017E4: jal         0x800F10B4
    // 0x808017E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x808017E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x808017EC: b           L_8080184C
    // 0x808017F0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
        goto L_8080184C;
    // 0x808017F0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_808017F4:
    // 0x808017F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808017F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1E00) << 16);
    // 0x80801800: lwc1        $f10, 0x1E00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E00));
    // 0x80801804: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x80801808: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080180C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80801810: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80801814: jal         0x800F10B4
    // 0x80801818: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80801818: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x8080181C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801820: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1E04) << 16);
    // 0x80801828: lwc1        $f16, 0x1E04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E04));
    // 0x8080182C: lui         $a3, 0x43AD
    ctx->r7 = S32(0X43AD << 16);
    // 0x80801830: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80801834: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x80801838: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080183C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80801840: jal         0x800F10B4
    // 0x80801844: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80801844: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80801848: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8080184C:
    // 0x8080184C: jal         0x8009C990
    // 0x80801850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80801850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801854: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801858: jal         0x8009B9C0
    // 0x8080185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_18;
    // 0x8080185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801860: jal         0x8009C990
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_19;
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801868: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801870: jal         0x8009BA68
    // 0x80801874: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x80801874: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_20:
    // 0x80801878: jal         0x8008AF24
    // 0x8080187C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    anctrl_reset(rdram, ctx);
        goto after_21;
    // 0x8080187C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_21:
    // 0x80801880: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801884: jal         0x8008AED4
    // 0x80801888: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    anctrl_setIndex(rdram, ctx);
        goto after_22;
    // 0x80801888: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_22:
    // 0x8080188C: lui         $a2, 0x3F25
    ctx->r6 = S32(0X3F25 << 16);
    // 0x80801890: ori         $a2, $a2, 0x8794
    ctx->r6 = ctx->r6 | 0X8794;
    // 0x80801894: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801898: jal         0x8008B1D4
    // 0x8080189C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_23;
    // 0x8080189C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_23:
    // 0x808018A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808018A4: jal         0x8008B1BC
    // 0x808018A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    anctrl_setDuration(rdram, ctx);
        goto after_24;
    // 0x808018A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_24:
    // 0x808018AC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808018B0: jal         0x8008B134
    // 0x808018B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_25;
    // 0x808018B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808018B8: jal         0x8008B064
    // 0x808018BC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    anctrl_start(rdram, ctx);
        goto after_26;
    // 0x808018BC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_26:
    // 0x808018C0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808018C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018C8: beql        $t0, $zero, L_808019F4
    if (ctx->r8 == 0) {
        // 0x808018CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808019F4;
    }
    goto skip_0;
    // 0x808018CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808018D0: jal         0x8009BA58
    // 0x808018D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_27;
    // 0x808018D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_27:
    // 0x808018D8: b           L_808019F4
    // 0x808018DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808019F4;
    // 0x808018DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808018E0:
    // 0x808018E0: lui         $a1, 0x3F4B
    ctx->r5 = S32(0X3F4B << 16);
    // 0x808018E4: ori         $a1, $a1, 0xE76D
    ctx->r5 = ctx->r5 | 0XE76D;
    // 0x808018E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018EC: jal         0x8008CF1C
    // 0x808018F0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_28;
    // 0x808018F0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_28:
    // 0x808018F4: b           L_808019F4
    // 0x808018F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808019F4;
    // 0x808018F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808018FC:
    // 0x808018FC: jal         0x8008E35C
    // 0x80801900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_29;
    // 0x80801900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801904: beql        $v0, $zero, L_80801918
    if (ctx->r2 == 0) {
        // 0x80801908: lui         $a1, 0x3F7A
        ctx->r5 = S32(0X3F7A << 16);
            goto L_80801918;
    }
    goto skip_1;
    // 0x80801908: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    skip_1:
    // 0x8080190C: jal         0x80800A14
    // 0x80801910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_bsbansack(rdram, ctx);
        goto after_30;
    // 0x80801910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80801914: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
L_80801918:
    // 0x80801918: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x8080191C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801920: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80801924: jal         0x8008CF1C
    // 0x80801928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_31;
    // 0x80801928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080192C: b           L_808019F4
    // 0x80801930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808019F4;
    // 0x80801930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801934:
    // 0x80801934: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801938: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801940: jal         0x8009BB5C
    // 0x80801944: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    func_8009BB5C(rdram, ctx);
        goto after_32;
    // 0x80801944: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x80801948: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080194C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801958: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080195C: jal         0x8009D2D8
    // 0x80801960: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    func_8009D2D8(rdram, ctx);
        goto after_33;
    // 0x80801960: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    after_33:
    // 0x80801964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801968: jal         0x8009B9B0
    // 0x8080196C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_34;
    // 0x8080196C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_34:
    // 0x80801970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801974: jal         0x800A2FCC
    // 0x80801978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2FCC(rdram, ctx);
        goto after_35;
    // 0x80801978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x8080197C: jal         0x8008E35C
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_36;
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80801984: beq         $v0, $zero, L_808019A0
    if (ctx->r2 == 0) {
        // 0x80801988: nop
    
            goto L_808019A0;
    }
    // 0x80801988: nop

    // 0x8080198C: jal         0x80800A14
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_bsbansack(rdram, ctx);
        goto after_37;
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80801994: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1E08) << 16);
    // 0x80801998: lwc1        $f8, 0x1E08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E08));
    // 0x8080199C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_808019A0:
    // 0x808019A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1E0C) << 16);
    // 0x808019A4: lwc1        $f10, 0x1E0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E0C));
    // 0x808019A8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808019AC: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x808019B0: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x808019B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808019B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019BC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808019C0: jal         0x8008CF1C
    // 0x808019C4: nop

    baanim_setEndAndDuration(rdram, ctx);
        goto after_38;
    // 0x808019C4: nop

    after_38:
    // 0x808019C8: b           L_808019F4
    // 0x808019CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808019F4;
    // 0x808019CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808019D0:
    // 0x808019D0: jal         0x80800A78
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A78_bsbansack(rdram, ctx);
        goto after_39;
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019DC: jal         0x8009BF5C
    // 0x808019E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_40;
    // 0x808019E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_40:
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E8: jal         0x8009C4CC
    // 0x808019EC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_41;
    // 0x808019EC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_41:
L_808019F0:
    // 0x808019F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808019F4:
    // 0x808019F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808019F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808019FC: jr          $ra
    // 0x80801A00: nop

    return;
    // 0x80801A00: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085128: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085128);
    return;
    // 0x8008512C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _suexpression_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089790: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089790);
    return;
    // 0x80089794: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D6408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D640C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6410: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D6414: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D6418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D641C: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x800D6420: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800D6424: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D6428: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x800D642C: beq         $at, $zero, L_800D6534
    if (ctx->r1 == 0) {
        // 0x800D6430: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D6534;
    }
    // 0x800D6430: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D6434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6438: addu        $at, $at, $t9
    gpr jr_addend_800D6440 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D643C: lw          $t9, 0x5C54($at)
    ctx->r25 = ADD32(ctx->r1, 0X5C54);
    // 0x800D6440: jr          $t9
    // 0x800D6444: nop

    switch (jr_addend_800D6440 >> 2) {
        case 0: goto L_800D6534; break;
        case 1: goto L_800D648C; break;
        case 2: goto L_800D6528; break;
        case 3: goto L_800D6528; break;
        case 4: goto L_800D6528; break;
        case 5: goto L_800D6448; break;
        case 6: goto L_800D6448; break;
        case 7: goto L_800D6528; break;
        case 8: goto L_800D6528; break;
        default: switch_error(__func__, 0x800D6440, 0x80125C54);
    }
    // 0x800D6444: nop

L_800D6448:
    // 0x800D6448: jal         0x8001211C
    // 0x800D644C: nop

    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x800D644C: nop

    after_0:
    // 0x800D6450: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800D6454: srl         $t1, $t0, 5
    ctx->r9 = S32(U32(ctx->r8) >> 5);
    // 0x800D6458: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D645C: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6460: beq         $at, $zero, L_800D6478
    if (ctx->r1 == 0) {
        // 0x800D6464: nop
    
            goto L_800D6478;
    }
    // 0x800D6464: nop

    // 0x800D6468: jal         0x800D56C4
    // 0x800D646C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_1;
    // 0x800D646C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x800D6470: b           L_800D6484
    // 0x800D6474: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D6484;
    // 0x800D6474: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D6478:
    // 0x800D6478: jal         0x800D5E54
    // 0x800D647C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5E54(rdram, ctx);
        goto after_2;
    // 0x800D647C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x800D6480: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800D6484:
    // 0x800D6484: b           L_800D6534
    // 0x800D6488: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
        goto L_800D6534;
    // 0x800D6488: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_800D648C:
    // 0x800D648C: jal         0x8001211C
    // 0x800D6490: nop

    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x800D6490: nop

    after_3:
    // 0x800D6494: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800D6498: srl         $t3, $v1, 5
    ctx->r11 = S32(U32(ctx->r3) >> 5);
    // 0x800D649C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D64A0: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D64A4: beql        $at, $zero, L_800D64C0
    if (ctx->r1 == 0) {
        // 0x800D64A8: lw          $t5, 0x8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X8);
            goto L_800D64C0;
    }
    goto skip_0;
    // 0x800D64A8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x800D64AC: jal         0x800D56C4
    // 0x800D64B0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_4;
    // 0x800D64B0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x800D64B4: b           L_800D6504
    // 0x800D64B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D6504;
    // 0x800D64B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D64BC: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
L_800D64C0:
    // 0x800D64C0: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800D64C4: bltz        $t7, L_800D64F8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D64C8: nop
    
            goto L_800D64F8;
    }
    // 0x800D64C8: nop

    // 0x800D64CC: lhu         $t8, 0x8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X8);
    // 0x800D64D0: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x800D64D4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800D64D8: bne         $t9, $zero, L_800D64F8
    if (ctx->r25 != 0) {
        // 0x800D64DC: nop
    
            goto L_800D64F8;
    }
    // 0x800D64DC: nop

    // 0x800D64E0: bne         $t0, $zero, L_800D64F8
    if (ctx->r8 != 0) {
        // 0x800D64E4: nop
    
            goto L_800D64F8;
    }
    // 0x800D64E4: nop

    // 0x800D64E8: jal         0x800D56C4
    // 0x800D64EC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_5;
    // 0x800D64EC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x800D64F0: b           L_800D6504
    // 0x800D64F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D6504;
    // 0x800D64F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D64F8:
    // 0x800D64F8: jal         0x800D5E54
    // 0x800D64FC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5E54(rdram, ctx);
        goto after_6;
    // 0x800D64FC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800D6500: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800D6504:
    // 0x800D6504: lbu         $v0, 0xB($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB);
    // 0x800D6508: beq         $v0, $zero, L_800D6520
    if (ctx->r2 == 0) {
        // 0x800D650C: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800D6520;
    }
    // 0x800D650C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800D6510: jal         0x800DBB9C
    // 0x800D6514: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DBB9C(rdram, ctx);
        goto after_7;
    // 0x800D6514: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x800D6518: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800D651C: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
L_800D6520:
    // 0x800D6520: b           L_800D6534
    // 0x800D6524: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
        goto L_800D6534;
    // 0x800D6524: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_800D6528:
    // 0x800D6528: jal         0x800D56C4
    // 0x800D652C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_8;
    // 0x800D652C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x800D6530: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800D6534:
    // 0x800D6534: jal         0x800D61B4
    // 0x800D6538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D61B4(rdram, ctx);
        goto after_9;
    // 0x800D6538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800D653C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6540: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800D6544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D6548: jr          $ra
    // 0x800D654C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D654C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808004E8_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F0: jal         0x800EA05C
    // 0x808004F4: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808004F4: nop

    after_0:
    // 0x808004F8: xori        $t6, $v0, 0x101
    ctx->r14 = ctx->r2 ^ 0X101;
    // 0x808004FC: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800500: bnel        $v0, $zero, L_8080054C
    if (ctx->r2 != 0) {
        // 0x80800504: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080054C;
    }
    goto skip_0;
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800508: jal         0x800EA05C
    // 0x8080050C: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x8080050C: nop

    after_1:
    // 0x80800510: xori        $t7, $v0, 0x106
    ctx->r15 = ctx->r2 ^ 0X106;
    // 0x80800514: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800518: bnel        $v0, $zero, L_8080054C
    if (ctx->r2 != 0) {
        // 0x8080051C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080054C;
    }
    goto skip_1;
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800520: jal         0x800EA05C
    // 0x80800524: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800524: nop

    after_2:
    // 0x80800528: xori        $t8, $v0, 0x109
    ctx->r24 = ctx->r2 ^ 0X109;
    // 0x8080052C: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80800530: bnel        $v0, $zero, L_8080054C
    if (ctx->r2 != 0) {
        // 0x80800534: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080054C;
    }
    goto skip_2;
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800538: jal         0x800EA05C
    // 0x8080053C: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x8080053C: nop

    after_3:
    // 0x80800540: xori        $t9, $v0, 0x10B
    ctx->r25 = ctx->r2 ^ 0X10B;
    // 0x80800544: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080054C:
    // 0x8080054C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800550: jr          $ra
    // 0x80800554: nop

    return;
    // 0x80800554: nop

;}
RECOMP_FUNC void func_808007F0_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007FC: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800808: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080080C: nop

    // 0x80800810: bc1fl       L_80800824
    if (!c1cs) {
        // 0x80800814: lw          $t6, 0x64($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X64);
            goto L_80800824;
    }
    goto skip_0;
    // 0x80800814: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800818: b           L_808008C0
    // 0x8080081C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x8080081C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800820: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80800824:
    // 0x80800824: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800828: bgez        $t8, L_80800838
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080082C: nop
    
            goto L_80800838;
    }
    // 0x8080082C: nop

    // 0x80800830: b           L_808008C0
    // 0x80800834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C0;
    // 0x80800834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800838:
    // 0x80800838: jal         0x801072A8
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_0;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800840: beq         $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x80800844: nop
    
            goto L_80800850;
    }
    // 0x80800844: nop

    // 0x80800848: b           L_808008C0
    // 0x8080084C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x8080084C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800850:
    // 0x80800850: jal         0x80089F78
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800858: bne         $v0, $zero, L_80800868
    if (ctx->r2 != 0) {
        // 0x8080085C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800868;
    }
    // 0x8080085C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800860: b           L_808008C0
    // 0x80800864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x80800864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800868:
    // 0x80800868: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x8080086C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800870: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x80800874: jal         0x8010C9FC
    // 0x80800878: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010C9FC(rdram, ctx);
        goto after_2;
    // 0x80800878: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080087C: bne         $v0, $zero, L_8080088C
    if (ctx->r2 != 0) {
        // 0x80800880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080088C;
    }
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: b           L_808008C0
    // 0x80800888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x80800888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080088C:
    // 0x8080088C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800890: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800894: jal         0x8010C668
    // 0x80800898: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_8010C668(rdram, ctx);
        goto after_3;
    // 0x80800898: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_3:
    // 0x8080089C: bne         $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x808008A0: nop
    
            goto L_808008AC;
    }
    // 0x808008A0: nop

    // 0x808008A4: b           L_808008C0
    // 0x808008A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x808008A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008AC:
    // 0x808008AC: jal         0x80089EF8
    // 0x808008B0: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808008B0: nop

    after_4:
    // 0x808008B4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808008B8: xor         $v0, $v0, $t9
    ctx->r2 = ctx->r2 ^ ctx->r25;
    // 0x808008BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_808008C0:
    // 0x808008C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void _seqdat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A688: syscall     847
    recomp_syscall_handler(rdram, ctx, 0x8008A688);
    return;
    // 0x8008A68C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80092B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092B94: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80092B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092B9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80092BA0: lw          $a1, 0x50($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X50);
    // 0x80092BA4: jal         0x800EE7F8
    // 0x80092BA8: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80092BA8: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    after_0:
    // 0x80092BAC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80092BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092BB4: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x80092BB8: lwc1        $f0, 0x70($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X70);
    // 0x80092BBC: jr          $ra
    // 0x80092BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80092BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808002CC_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002DC: jal         0x800DA298
    // 0x808002E0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002E0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x808002E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808002EC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808002F0: jal         0x800EE7F8
    // 0x808002F4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808002F4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x808002F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808002FC: jal         0x800EE7F8
    // 0x80800300: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800300: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800304: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800308: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080030C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800310: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080031C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80800320: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800324: beql        $t6, $zero, L_80800348
    if (ctx->r14 == 0) {
        // 0x80800328: lwc1        $f10, 0x2C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_80800348;
    }
    goto skip_0;
    // 0x80800328: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    skip_0:
    // 0x8080032C: jal         0x80101FDC
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800334: jal         0x8010A590
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080033C: b           L_80800350
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800350;
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800344: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_80800348:
    // 0x80800348: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800350:
    // 0x80800350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BD0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BD0);
    return;
    // 0x80082BD4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chjinjo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BA8: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086BA8);
    return;
    // 0x80086BAC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _badata_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084708: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084708);
    return;
    // 0x8008470C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void bsbeemain_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080106C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801070: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X12C0) << 16);
    // 0x80801074: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801078: jr          $ra
    // 0x8080107C: lw          $v0, 0x12C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12C0));
    return;
    // 0x8080107C: lw          $v0, 0x12C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12C0));
;}
RECOMP_FUNC void func_800BC410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC410: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BC414: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC418: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800BC41C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BC420: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800BC424: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800BC428: jal         0x800E7FCC
    // 0x800BC42C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E7FCC(rdram, ctx);
        goto after_0;
    // 0x800BC42C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800BC430: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BC434: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800BC438: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800BC43C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800BC440: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800BC444: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BC448: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC44C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800BC450: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BC454: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800BC458: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800BC45C: jal         0x800BC474
    // 0x800BC460: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_800BC474(rdram, ctx);
        goto after_1;
    // 0x800BC460: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_1:
    // 0x800BC464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC468: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BC46C: jr          $ra
    // 0x800BC470: nop

    return;
    // 0x800BC470: nop

;}
RECOMP_FUNC void func_80802210_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802218: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080221C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802220: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802224: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80802228: jal         0x80100094
    // 0x8080222C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080222C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802230: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802234: lbu         $t6, 0x12B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12B);
    // 0x80802238: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080223C: beql        $t6, $zero, L_8080225C
    if (ctx->r14 == 0) {
        // 0x80802240: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_8080225C;
    }
    goto skip_0;
    // 0x80802240: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80802244: jal         0x80085710
    // 0x80802248: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80802248: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080224C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80802250: ori         $t7, $a3, 0x2000
    ctx->r15 = ctx->r7 | 0X2000;
    // 0x80802254: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80802258: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_8080225C:
    // 0x8080225C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802260: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802264: jal         0x80085708
    // 0x80802268: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80802268: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8080226C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80802270: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802274: sb          $t9, 0x12B($t0)
    MEM_B(0X12B, ctx->r8) = ctx->r25;
    // 0x80802278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080227C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802280: jr          $ra
    // 0x80802284: nop

    return;
    // 0x80802284: nop

;}
RECOMP_FUNC void func_800C9510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9518: jal         0x800C91C8
    // 0x800C951C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C951C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C9520: beq         $v0, $zero, L_800C9538
    if (ctx->r2 == 0) {
        // 0x800C9524: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C9538;
    }
    // 0x800C9524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9528: jal         0x800881C8
    // 0x800C952C: nop

    _gctransitionDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x800C952C: nop

    after_1:
    // 0x800C9530: b           L_800C9540
    // 0x800C9534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9540;
    // 0x800C9534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9538:
    // 0x800C9538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C953C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9540:
    // 0x800C9540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9544: jr          $ra
    // 0x800C9548: nop

    return;
    // 0x800C9548: nop

;}
RECOMP_FUNC void func_800D1804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D180C: jal         0x800D175C
    // 0x800D1810: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800D175C(rdram, ctx);
        goto after_0;
    // 0x800D1810: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800D1814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D181C: jr          $ra
    // 0x800D1820: nop

    return;
    // 0x800D1820: nop

;}
