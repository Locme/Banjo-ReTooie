#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chklungoforcefield_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863C0: syscall     318
    recomp_syscall_handler(rdram, ctx, 0x800863C0);
    return;
    // 0x800863C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006B8_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808006BC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(868, 0XEFC) << 16);
    // 0x808006C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808006C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808006C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808006CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808006D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808006D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808006D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808006DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006E0: addiu       $t7, $t7, 0xEFC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(868, 0XEFC));
    // 0x808006E4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808006E8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808006EC: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x808006F0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(868, 0XF04) << 16);
    // 0x808006F4: addiu       $t1, $t1, 0xF04
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(868, 0XF04));
    // 0x808006F8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808006FC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800700: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800704: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x80800708: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(868, 0XF08) << 16);
    // 0x8080070C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800710: addiu       $s5, $s5, 0xF08
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(868, 0XF08));
    // 0x80800714: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800718: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x8080071C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80800720: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
L_80800724:
    // 0x80800724: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800728: jal         0x80101E14
    // 0x8080072C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x8080072C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x80800730: beq         $v0, $zero, L_80800758
    if (ctx->r2 == 0) {
        // 0x80800734: sll         $t5, $s0, 1
        ctx->r13 = S32(ctx->r16 << 1);
            goto L_80800758;
    }
    // 0x80800734: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x80800738: addu        $t9, $s4, $t5
    ctx->r25 = ADD32(ctx->r20, ctx->r13);
    // 0x8080073C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x80800740: jal         0x800C4B7C
    // 0x80800744: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    func_800C4B7C(rdram, ctx);
        goto after_1;
    // 0x80800744: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    after_1:
    // 0x80800748: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080074C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800750: jal         0x80089D18
    // 0x80800754: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800754: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
L_80800758:
    // 0x80800758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080075C: bne         $s0, $s6, L_80800724
    if (ctx->r16 != ctx->r22) {
        // 0x80800760: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800724;
    }
    // 0x80800760: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800764: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080076C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800770: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800774: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800778: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080077C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800780: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800784: jr          $ra
    // 0x80800788: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800788: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chlagoonbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1052, 0X96C) << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: addiu       $v0, $v0, 0x96C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X96C));
    return;
    // 0x80800044: addiu       $v0, $v0, 0x96C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X96C));
;}
RECOMP_FUNC void _bskazfly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833A8: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x800833A8);
    return;
    // 0x800833AC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsbabykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8009C128
    // 0x80800010: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800014: jal         0x8009C984
    // 0x80800018: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8080001C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800020: jal         0x80084490
    // 0x80800024: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _bababykaz_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800024: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80800028: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080002C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800030: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800038: jal         0x800871D8
    // 0x8080003C: lw          $a3, 0x160($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X160);
    _cheggclockwork_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080003C: lw          $a3, 0x160($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X160);
    after_3:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80803D98_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803DA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803DA4: jal         0x8010D290
    // 0x80803DA8: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_8010D290(rdram, ctx);
        goto after_0;
    // 0x80803DA8: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_0:
    // 0x80803DAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80803DB0: bne         $v0, $at, L_80803DC4
    if (ctx->r2 != ctx->r1) {
        // 0x80803DB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80803DC4;
    }
    // 0x80803DB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80803DB8: jal         0x800F54E4
    // 0x80803DBC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80803DBC: nop

    after_1:
    // 0x80803DC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80803DC4:
    // 0x80803DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803DCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80803DD0: jr          $ra
    // 0x80803DD4: nop

    return;
    // 0x80803DD4: nop

;}
RECOMP_FUNC void func_800D5318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5318: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D531C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D5320: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D5324: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D5328: jal         0x80088BB8
    // 0x800D532C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    _gspropctrl_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800D532C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D5330: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D5334: beq         $v0, $at, L_800D5354
    if (ctx->r2 == ctx->r1) {
        // 0x800D5338: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D5354;
    }
    // 0x800D5338: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D533C: beq         $v0, $at, L_800D53E8
    if (ctx->r2 == ctx->r1) {
        // 0x800D5340: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800D53E8;
    }
    // 0x800D5340: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D5344: beq         $v0, $at, L_800D53B4
    if (ctx->r2 == ctx->r1) {
        // 0x800D5348: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D53B4;
    }
    // 0x800D5348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D534C: b           L_800D5414
    // 0x800D5350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D5414;
    // 0x800D5350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D5354:
    // 0x800D5354: jal         0x8001211C
    // 0x800D5358: nop

    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x800D5358: nop

    after_1:
    // 0x800D535C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D5360: jal         0x80088BC0
    // 0x800D5364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropctrl_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x800D5364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800D5368: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800D536C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800D5370: beql        $t6, $t7, L_800D53A4
    if (ctx->r14 == ctx->r15) {
        // 0x800D5374: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D53A4;
    }
    goto skip_0;
    // 0x800D5374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800D5378: jal         0x80088BC8
    // 0x800D537C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropctrl_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x800D537C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800D5380: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800D5384: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800D5388: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D538C: lw          $t9, -0x4980($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4980);
    // 0x800D5390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D5394: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D5398: jalr        $t9
    // 0x800D539C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800D539C: nop

    after_4:
    // 0x800D53A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D53A4:
    // 0x800D53A4: jal         0x80088BD0
    // 0x800D53A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gspropctrl_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x800D53A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x800D53AC: b           L_800D5414
    // 0x800D53B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D5414;
    // 0x800D53B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D53B4:
    // 0x800D53B4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800D53B8: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x800D53BC: lhu         $a1, 0x8($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X8);
    // 0x800D53C0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800D53C4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D53C8: lbu         $a3, 0xB($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XB);
    // 0x800D53CC: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x800D53D0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800D53D4: addiu       $a1, $a1, 0xA0
    ctx->r5 = ADD32(ctx->r5, 0XA0);
    // 0x800D53D8: jal         0x80087AD8
    // 0x800D53DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _gcsectionskip_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x800D53DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_6:
    // 0x800D53E0: b           L_800D5414
    // 0x800D53E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D5414;
    // 0x800D53E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D53E8:
    // 0x800D53E8: jal         0x80088BC8
    // 0x800D53EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropctrl_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x800D53EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800D53F0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800D53F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800D53F8: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x800D53FC: lw          $t9, -0x4840($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4840);
    // 0x800D5400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D5404: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D5408: jalr        $t9
    // 0x800D540C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800D540C: nop

    after_8:
    // 0x800D5410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D5414:
    // 0x800D5414: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D5418: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D541C: jr          $ra
    // 0x800D5420: nop

    return;
    // 0x800D5420: nop

;}
RECOMP_FUNC void func_800EDF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDFA0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800EDFA4: jal         0x800EDF2C
    // 0x800EDFA8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EDF2C(rdram, ctx);
        goto after_0;
    // 0x800EDFA8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x800EDFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EDFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EDFB4: jr          $ra
    // 0x800EDFB8: nop

    return;
    // 0x800EDFB8: nop

;}
RECOMP_FUNC void func_80110C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110C34: jal         0x80089418
    // 0x80110C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80110C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80110C3C: beq         $v0, $zero, L_80110C78
    if (ctx->r2 == 0) {
        // 0x80110C40: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80110C78;
    }
    // 0x80110C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80110C44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80110C48: beql        $v0, $at, L_80110C7C
    if (ctx->r2 == ctx->r1) {
        // 0x80110C4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80110C7C;
    }
    goto skip_0;
    // 0x80110C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80110C50: lbu         $t6, 0x72($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X72);
    // 0x80110C54: addiu       $a1, $a0, 0x74
    ctx->r5 = ADD32(ctx->r4, 0X74);
    // 0x80110C58: addiu       $a2, $a0, 0x80
    ctx->r6 = ADD32(ctx->r4, 0X80);
    // 0x80110C5C: beq         $t6, $zero, L_80110C70
    if (ctx->r14 == 0) {
        // 0x80110C60: nop
    
            goto L_80110C70;
    }
    // 0x80110C60: nop

    // 0x80110C64: jal         0x80089430
    // 0x80110C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _ncba1p_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80110C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80110C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80110C70:
    // 0x80110C70: jal         0x800893F0
    // 0x80110C74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _ncba1p_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80110C74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_80110C78:
    // 0x80110C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110C7C:
    // 0x80110C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110C80: jr          $ra
    // 0x80110C84: nop

    return;
    // 0x80110C84: nop

;}
RECOMP_FUNC void baduo_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002B0: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808002B4: jr          $ra
    // 0x808002B8: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808002B8: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8001B754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B754: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8001B758: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001B75C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B760: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001B764: addiu       $t8, $t8, -0x40F0
    ctx->r24 = ADD32(ctx->r24, -0X40F0);
    // 0x8001B768: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8001B76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B770: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B774: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B778: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001B77C: jal         0x8001B084
    // 0x8001B780: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x8001B780: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001B784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B788: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B78C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B790: jr          $ra
    // 0x8001B794: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x8001B794: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void _bsmumswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083908: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x80083908);
    return;
    // 0x8008390C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80027090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027098: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002709C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800270A0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800270A4: beq         $t7, $zero, L_8002714C
    if (ctx->r15 == 0) {
        // 0x800270A8: nop
    
            goto L_8002714C;
    }
    // 0x800270A8: nop

    // 0x800270AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800270B0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800270B4: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x800270B8: beq         $t0, $zero, L_80027138
    if (ctx->r8 == 0) {
        // 0x800270BC: nop
    
            goto L_80027138;
    }
    // 0x800270BC: nop

    // 0x800270C0: jal         0x80021794
    // 0x800270C4: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x800270C4: nop

    after_0:
    // 0x800270C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800270CC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800270D0: bne         $t1, $zero, L_800270E0
    if (ctx->r9 != 0) {
        // 0x800270D4: nop
    
            goto L_800270E0;
    }
    // 0x800270D4: nop

    // 0x800270D8: b           L_80027154
    // 0x800270DC: nop

        goto L_80027154;
    // 0x800270DC: nop

L_800270E0:
    // 0x800270E0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800270E4: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800270E8: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x800270EC: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800270F0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800270F4: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x800270F8: lw          $t6, 0x88($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X88);
    // 0x800270FC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80027100: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80027104: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80027108: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
    // 0x8002710C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80027110: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80027114: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80027118: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x8002711C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80027120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80027124: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80027128: jal         0x8002B684
    // 0x8002712C: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x8002712C: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    after_1:
    // 0x80027130: b           L_80027144
    // 0x80027134: nop

        goto L_80027144;
    // 0x80027134: nop

L_80027138:
    // 0x80027138: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002713C: jal         0x80021884
    // 0x80027140: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    func_80021884(rdram, ctx);
        goto after_2;
    // 0x80027140: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    after_2:
L_80027144:
    // 0x80027144: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80027148: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
L_8002714C:
    // 0x8002714C: b           L_80027154
    // 0x80027150: nop

        goto L_80027154;
    // 0x80027150: nop

L_80027154:
    // 0x80027154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002715C: jr          $ra
    // 0x80027160: nop

    return;
    // 0x80027160: nop

    // 0x80027164: nop

    // 0x80027168: nop

    // 0x8002716C: nop

;}
RECOMP_FUNC void bakey_defrag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091AE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091AE8: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x80091AEC: jal         0x800BD0BC
    // 0x80091AF0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800BD0BC(rdram, ctx);
        goto after_0;
    // 0x80091AF0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80091AF4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80091AF8: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80091AFC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80091B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091B08: jr          $ra
    // 0x80091B0C: nop

    return;
    // 0x80091B0C: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801500: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080150C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801514: jal         0x800EE7F8
    // 0x80801518: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801518: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8080151C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80801520: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801524: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801528: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8080152C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801530: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801534: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801538: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8080153C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80801540: jal         0x800EFA4C
    // 0x80801544: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80801544: nop

    after_1:
    // 0x80801548: lui         $a3, 0x40
    ctx->r7 = S32(0X40 << 16);
    // 0x8080154C: ori         $a3, $a3, 0x5
    ctx->r7 = ctx->r7 | 0X5;
    // 0x80801550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801554: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80801558: jal         0x800C6A7C
    // 0x8080155C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x8080155C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80801560: beq         $v0, $zero, L_80801570
    if (ctx->r2 == 0) {
        // 0x80801564: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_80801570;
    }
    // 0x80801564: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80801568: b           L_808015E4
    // 0x8080156C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015E4;
    // 0x8080156C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801570:
    // 0x80801570: jal         0x800EE7F8
    // 0x80801574: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801574: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80801578: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801580: jal         0x800EE7F8
    // 0x80801584: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801584: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80801588: lui         $a3, 0x40
    ctx->r7 = S32(0X40 << 16);
    // 0x8080158C: ori         $a3, $a3, 0x5
    ctx->r7 = ctx->r7 | 0X5;
    // 0x80801590: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80801594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801598: jal         0x800C6A7C
    // 0x8080159C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800C6A7C(rdram, ctx);
        goto after_5;
    // 0x8080159C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x808015A0: beq         $v0, $zero, L_808015B0
    if (ctx->r2 == 0) {
        // 0x808015A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808015B0;
    }
    // 0x808015A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015A8: b           L_808015E4
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015E4;
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015B0:
    // 0x808015B0: jal         0x800EE7F8
    // 0x808015B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808015B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808015B8: lui         $a3, 0x40
    ctx->r7 = S32(0X40 << 16);
    // 0x808015BC: ori         $a3, $a3, 0x5
    ctx->r7 = ctx->r7 | 0X5;
    // 0x808015C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015C4: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x808015C8: jal         0x800C6C94
    // 0x808015CC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800C6C94(rdram, ctx);
        goto after_7;
    // 0x808015CC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x808015D0: beql        $v0, $zero, L_808015E4
    if (ctx->r2 == 0) {
        // 0x808015D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808015E4;
    }
    goto skip_0;
    // 0x808015D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808015D8: b           L_808015E4
    // 0x808015DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015E4;
    // 0x808015DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808015E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015E4:
    // 0x808015E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808015EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808015F0: jr          $ra
    // 0x808015F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808015F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808015F8: nop

    // 0x808015FC: nop

;}
RECOMP_FUNC void func_80800114_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800120: jal         0x80083F68
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x8009E6C4
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E6C4(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800134: bne         $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800160;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x8009BCB4
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_2;
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x80800144: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x80800148: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x8080014C: jal         0x8009BCC4
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x800961AC
    // 0x8080015C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x8080015C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_80800160:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void func_80800000_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080000C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800010: addiu       $at, $zero, 0x16A
    ctx->r1 = ADD32(0, 0X16A);
    // 0x80800014: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80800018: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x8080001C: beq         $t7, $at, L_80800070
    if (ctx->r15 == ctx->r1) {
        // 0x80800020: addiu       $a0, $a2, 0x18
        ctx->r4 = ADD32(ctx->r6, 0X18);
            goto L_80800070;
    }
    // 0x80800020: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    // 0x80800024: addiu       $at, $zero, 0x21A
    ctx->r1 = ADD32(0, 0X21A);
    // 0x80800028: beq         $t7, $at, L_80800058
    if (ctx->r15 == ctx->r1) {
        // 0x8080002C: addiu       $at, $zero, 0x22E
        ctx->r1 = ADD32(0, 0X22E);
            goto L_80800058;
    }
    // 0x8080002C: addiu       $at, $zero, 0x22E
    ctx->r1 = ADD32(0, 0X22E);
    // 0x80800030: beq         $t7, $at, L_80800060
    if (ctx->r15 == ctx->r1) {
        // 0x80800034: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800060;
    }
    // 0x80800034: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800038: addiu       $at, $zero, 0x3DB
    ctx->r1 = ADD32(0, 0X3DB);
    // 0x8080003C: beq         $t7, $at, L_80800068
    if (ctx->r15 == ctx->r1) {
        // 0x80800040: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80800068;
    }
    // 0x80800040: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800044: addiu       $at, $zero, 0x471
    ctx->r1 = ADD32(0, 0X471);
    // 0x80800048: beq         $t7, $at, L_8080007C
    if (ctx->r15 == ctx->r1) {
        // 0x8080004C: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_8080007C;
    }
    // 0x8080004C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80800050: b           L_80800084
    // 0x80800054: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
        goto L_80800084;
    // 0x80800054: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
L_80800058:
    // 0x80800058: b           L_80800080
    // 0x8080005C: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
        goto L_80800080;
    // 0x8080005C: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
L_80800060:
    // 0x80800060: b           L_80800080
    // 0x80800064: sw          $t8, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r24;
        goto L_80800080;
    // 0x80800064: sw          $t8, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r24;
L_80800068:
    // 0x80800068: b           L_80800080
    // 0x8080006C: sw          $t9, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r25;
        goto L_80800080;
    // 0x8080006C: sw          $t9, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r25;
L_80800070:
    // 0x80800070: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80800074: b           L_80800080
    // 0x80800078: sw          $t0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r8;
        goto L_80800080;
    // 0x80800078: sw          $t0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r8;
L_8080007C:
    // 0x8080007C: sw          $t1, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r9;
L_80800080:
    // 0x80800080: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
L_80800084:
    // 0x80800084: jal         0x800EE7F8
    // 0x80800088: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800088: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8080009C: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x808000A0: jal         0x80800424
    // 0x808000A4: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    func_80800424_chfootwear(rdram, ctx);
        goto after_1;
    // 0x808000A4: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void _subaddiemulti_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A088: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A088);
    return;
    // 0x8008A08C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chmayafarmer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1612, 0X1278) << 16);
    // 0x808008F0: jr          $ra
    // 0x808008F4: addiu       $v0, $v0, 0x1278
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1612, 0X1278));
    return;
    // 0x808008F4: addiu       $v0, $v0, 0x1278
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1612, 0X1278));
;}
RECOMP_FUNC void func_800CA510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA510: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA51C: swc1        $f12, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f12.u32l;
    // 0x800CA520: jal         0x800CA1B0
    // 0x800CA524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CA1B0(rdram, ctx);
        goto after_0;
    // 0x800CA524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CA528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CA52C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CA530: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CA534: lwc1        $f4, 0xE4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE4);
    // 0x800CA538: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CA53C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800CA540: jal         0x800CA2A8
    // 0x800CA544: nop

    func_800CA2A8(rdram, ctx);
        goto after_1;
    // 0x800CA544: nop

    after_1:
    // 0x800CA548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA54C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA550: jr          $ra
    // 0x800CA554: nop

    return;
    // 0x800CA554: nop

;}
RECOMP_FUNC void func_808015DC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015E4: jal         0x80106790
    // 0x808015E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808015E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808015EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015F8: beq         $v1, $at, L_80801614
    if (ctx->r3 == ctx->r1) {
        // 0x808015FC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80801614;
    }
    // 0x808015FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80801600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801604: beq         $v1, $at, L_80801628
    if (ctx->r3 == ctx->r1) {
        // 0x80801608: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801628;
    }
    // 0x80801608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080160C: b           L_8080163C
    // 0x80801610: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_8080163C;
    // 0x80801610: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80801614:
    // 0x80801614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801618: jal         0x80089CF0
    // 0x8080161C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080161C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80801620: b           L_8080164C
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080164C;
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801628:
    // 0x80801628: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8080162C: jal         0x80089CF0
    // 0x80801630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80801630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80801634: b           L_8080164C
    // 0x80801638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080164C;
    // 0x80801638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080163C:
    // 0x8080163C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80801640: jal         0x80089CF0
    // 0x80801644: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80801644: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80801648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080164C:
    // 0x8080164C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801650: jr          $ra
    // 0x80801654: nop

    return;
    // 0x80801654: nop

;}
RECOMP_FUNC void func_8008E39C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E39C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E3A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E3A4: jal         0x80084FE0
    // 0x8008E3A8: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8008E3A8: nop

    after_0:
    // 0x8008E3AC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8008E3B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008E3B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E3B8: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E3BC: beq         $v0, $zero, L_8008E3E0
    if (ctx->r2 == 0) {
        // 0x8008E3C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E3E0;
    }
    // 0x8008E3C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E3C4: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008E3C8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008E3CC: beq         $v0, $zero, L_8008E3E0
    if (ctx->r2 == 0) {
        // 0x8008E3D0: nop
    
            goto L_8008E3E0;
    }
    // 0x8008E3D0: nop

    // 0x8008E3D4: xori        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 ^ 0X2;
    // 0x8008E3D8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008E3DC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8008E3E0:
    // 0x8008E3E0: jr          $ra
    // 0x8008E3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _cheel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DB8: syscall     455
    recomp_syscall_handler(rdram, ctx, 0x80086DB8);
    return;
    // 0x80086DBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chbigtopticket_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1160, 0X120) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1160, 0X120));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1160, 0X120));
;}
RECOMP_FUNC void glzone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X0);
    // 0x80800010: jal         0x8001ACCC
    // 0x80800014: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_0:
    // 0x80800018: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80800028: jal         0x80800064
    // 0x8080002C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    glzone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080002C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    after_1:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void chboilerid_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AEC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800AF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800AF8: jal         0x80100094
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B00: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800B04: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B0C: lhu         $v1, 0x72($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X72);
    // 0x80800B10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B14: swc1        $f4, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f4.u32l;
    // 0x80800B18: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800B1C: beq         $t6, $at, L_80800C34
    if (ctx->r14 == ctx->r1) {
        // 0x80800B20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C34;
    }
    // 0x80800B20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B24: beql        $t6, $at, L_80800C38
    if (ctx->r14 == ctx->r1) {
        // 0x80800B28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C38;
    }
    goto skip_0;
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B2C: jal         0x80800CB0
    // 0x80800B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800CB0_chboilerid(rdram, ctx);
        goto after_1;
    // 0x80800B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800B34: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80800B38: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80800B3C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x80800B40: addiu       $t8, $t8, 0xD00
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x80800B44: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800B48: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80800B4C: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80800B50: lh          $t0, 0x6($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X6);
    // 0x80800B54: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800B58: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800B5C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B64: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800B68: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800B6C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800B70: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800B74: jal         0x80088FB8
    // 0x80800B78: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800B78: nop

    after_2:
    // 0x80800B7C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800B80: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x80800B84: addiu       $t3, $t3, 0xD00
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x80800B88: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800B8C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80800B90: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80800B94: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80800B98: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x80800B9C: lh          $t5, 0xE($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XE);
    // 0x80800BA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BA4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800BA8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80800BAC: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80800BB0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800BB4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800BB8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800BBC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800BC0: jal         0x80088FB8
    // 0x80800BC4: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800BC4: nop

    after_3:
    // 0x80800BC8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800BCC: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80800BD0: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x80800BD4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x80800BD8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80800BDC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800BE0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800BE4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800BE8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800BEC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800BF0: jal         0x80088FB8
    // 0x80800BF4: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800BF4: nop

    after_4:
    // 0x80800BF8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800BFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800C00: lh          $t8, 0x1A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1A);
    // 0x80800C04: sh          $t8, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r24;
    // 0x80800C08: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x80800C0C: sh          $t9, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r25;
    // 0x80800C10: lh          $t0, 0x1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X1C);
    // 0x80800C14: sh          $t0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r8;
    // 0x80800C18: jal         0x80101FDC
    // 0x80800C1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800C1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800C20: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    // 0x80800C24: jal         0x800DA3B8
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_6;
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800C2C: jal         0x800CF2D4
    // 0x80800C30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800CF2D4(rdram, ctx);
        goto after_7;
    // 0x80800C30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
L_80800C34:
    // 0x80800C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C38:
    // 0x80800C38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C40: jr          $ra
    // 0x80800C44: nop

    return;
    // 0x80800C44: nop

;}
RECOMP_FUNC void _sccustom_big_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A908: syscall     856
    recomp_syscall_handler(rdram, ctx, 0x8008A908);
    return;
    // 0x8008A90C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D40_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800D4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D50: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800D54: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800D58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D5C: jal         0x800B4374
    // 0x80800D60: lw          $a0, 0xE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE0);
    func_800B4374(rdram, ctx);
        goto after_0;
    // 0x80800D60: lw          $a0, 0xE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE0);
    after_0:
    // 0x80800D64: beq         $v0, $zero, L_80800DF0
    if (ctx->r2 == 0) {
        // 0x80800D68: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800DF0;
    }
    // 0x80800D68: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800D6C: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
    // 0x80800D70: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80800D74:
    // 0x80800D74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D78: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80800D7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800D80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800D84: jal         0x80800CA8
    // 0x80800D88: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800CA8_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x80800D88: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x80800D8C: beq         $v0, $zero, L_80800D98
    if (ctx->r2 == 0) {
        // 0x80800D90: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80800D98;
    }
    // 0x80800D90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800D94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800D98:
    // 0x80800D98: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80800D9C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80800DA0: jal         0x80800CA8
    // 0x80800DA4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800CA8_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x80800DA4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x80800DA8: beq         $v0, $zero, L_80800DB4
    if (ctx->r2 == 0) {
        // 0x80800DAC: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80800DB4;
    }
    // 0x80800DAC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800DB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800DB4:
    // 0x80800DB4: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80800DB8: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80800DBC: jal         0x80800CA8
    // 0x80800DC0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800CA8_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x80800DC0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x80800DC4: beq         $v0, $zero, L_80800DD0
    if (ctx->r2 == 0) {
        // 0x80800DC8: addiu       $a0, $s1, 0xE0
        ctx->r4 = ADD32(ctx->r17, 0XE0);
            goto L_80800DD0;
    }
    // 0x80800DC8: addiu       $a0, $s1, 0xE0
    ctx->r4 = ADD32(ctx->r17, 0XE0);
    // 0x80800DCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800DD0:
    // 0x80800DD0: beq         $s0, $zero, L_80800DE8
    if (ctx->r16 == 0) {
        // 0x80800DD4: nop
    
            goto L_80800DE8;
    }
    // 0x80800DD4: nop

    // 0x80800DD8: jal         0x800B4134
    // 0x80800DDC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800B4134(rdram, ctx);
        goto after_4;
    // 0x80800DDC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x80800DE0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800DE8:
    // 0x80800DE8: bnel        $s0, $zero, L_80800D74
    if (ctx->r16 != 0) {
        // 0x80800DEC: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_80800D74;
    }
    goto skip_0;
    // 0x80800DEC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    skip_0:
L_80800DF0:
    // 0x80800DF0: jal         0x800B4354
    // 0x80800DF4: addiu       $a0, $s1, 0xE0
    ctx->r4 = ADD32(ctx->r17, 0XE0);
    func_800B4354(rdram, ctx);
        goto after_5;
    // 0x80800DF4: addiu       $a0, $s1, 0xE0
    ctx->r4 = ADD32(ctx->r17, 0XE0);
    after_5:
    // 0x80800DF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800DFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800E00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800E04: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E08: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800E0C: jr          $ra
    // 0x80800E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808007A4_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808007A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808007B0: jal         0x80100094
    // 0x808007B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007B8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x808007BC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x808007C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007C4: jal         0x800D0A9C
    // 0x808007C8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x808007C8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_1:
    // 0x808007CC: jal         0x800D395C
    // 0x808007D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x808007D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x808007D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007D8: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x808007DC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808007E0: jal         0x800D2054
    // 0x808007E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x808007E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x808007E8: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x808007EC: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808007F0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808007F4: beq         $a1, $zero, L_80800810
    if (ctx->r5 == 0) {
        // 0x808007F8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80800810;
    }
    // 0x808007F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808007FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800800: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800804: bnel        $a1, $zero, L_80800814
    if (ctx->r5 != 0) {
        // 0x80800808: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80800814;
    }
    goto skip_0;
    // 0x80800808: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x8080080C: sltu        $a1, $zero, $a3
    ctx->r5 = 0 < ctx->r7 ? 1 : 0;
L_80800810:
    // 0x80800810: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800814:
    // 0x80800814: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080081C: slti        $t8, $v0, 0x1E
    ctx->r24 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80800820: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80800824: sltu        $a1, $zero, $t8
    ctx->r5 = 0 < ctx->r24 ? 1 : 0;
    // 0x80800828: beq         $a1, $zero, L_80800840
    if (ctx->r5 == 0) {
        // 0x8080082C: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800840;
    }
    // 0x8080082C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800830: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800834: beql        $a1, $zero, L_80800844
    if (ctx->r5 == 0) {
        // 0x80800838: sw          $a1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r5;
            goto L_80800844;
    }
    goto skip_1;
    // 0x80800838: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    skip_1:
    // 0x8080083C: sltiu       $a1, $a3, 0x1
    ctx->r5 = ctx->r7 < 0X1 ? 1 : 0;
L_80800840:
    // 0x80800840: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800844:
    // 0x80800844: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80800848: jal         0x800FDC28
    // 0x8080084C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FDC28(rdram, ctx);
        goto after_4;
    // 0x8080084C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800850: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800854: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800858: bne         $a1, $zero, L_80800868
    if (ctx->r5 != 0) {
        // 0x8080085C: nop
    
            goto L_80800868;
    }
    // 0x8080085C: nop

    // 0x80800860: beq         $v1, $zero, L_80800870
    if (ctx->r3 == 0) {
        // 0x80800864: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800870;
    }
    // 0x80800864: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_80800868:
    // 0x80800868: b           L_80800870
    // 0x8080086C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_80800870;
    // 0x8080086C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80800870:
    // 0x80800870: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800874: jal         0x800FC6B0
    // 0x80800878: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800FC6B0(rdram, ctx);
        goto after_5;
    // 0x80800878: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x8080087C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800880: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800884: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800888: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8080088C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800890: beq         $t3, $zero, L_808008A0
    if (ctx->r11 == 0) {
        // 0x80800894: nop
    
            goto L_808008A0;
    }
    // 0x80800894: nop

    // 0x80800898: b           L_808008FC
    // 0x8080089C: addiu       $v1, $zero, 0x10D1
    ctx->r3 = ADD32(0, 0X10D1);
        goto L_808008FC;
    // 0x8080089C: addiu       $v1, $zero, 0x10D1
    ctx->r3 = ADD32(0, 0X10D1);
L_808008A0:
    // 0x808008A0: beq         $v1, $zero, L_808008B0
    if (ctx->r3 == 0) {
        // 0x808008A4: nop
    
            goto L_808008B0;
    }
    // 0x808008A4: nop

    // 0x808008A8: b           L_808008FC
    // 0x808008AC: addiu       $v1, $zero, 0x10C3
    ctx->r3 = ADD32(0, 0X10C3);
        goto L_808008FC;
    // 0x808008AC: addiu       $v1, $zero, 0x10C3
    ctx->r3 = ADD32(0, 0X10C3);
L_808008B0:
    // 0x808008B0: jal         0x800D395C
    // 0x808008B4: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x808008B4: nop

    after_6:
    // 0x808008B8: bne         $v0, $zero, L_808008F0
    if (ctx->r2 != 0) {
        // 0x808008BC: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_808008F0;
    }
    // 0x808008BC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x808008C0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808008C4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C8: beq         $t4, $zero, L_808008E8
    if (ctx->r12 == 0) {
        // 0x808008CC: nop
    
            goto L_808008E8;
    }
    // 0x808008CC: nop

    // 0x808008D0: bne         $t5, $zero, L_808008E0
    if (ctx->r13 != 0) {
        // 0x808008D4: nop
    
            goto L_808008E0;
    }
    // 0x808008D4: nop

    // 0x808008D8: b           L_808008FC
    // 0x808008DC: addiu       $v1, $zero, 0x10F7
    ctx->r3 = ADD32(0, 0X10F7);
        goto L_808008FC;
    // 0x808008DC: addiu       $v1, $zero, 0x10F7
    ctx->r3 = ADD32(0, 0X10F7);
L_808008E0:
    // 0x808008E0: b           L_808008FC
    // 0x808008E4: addiu       $v1, $zero, 0x10F6
    ctx->r3 = ADD32(0, 0X10F6);
        goto L_808008FC;
    // 0x808008E4: addiu       $v1, $zero, 0x10F6
    ctx->r3 = ADD32(0, 0X10F6);
L_808008E8:
    // 0x808008E8: b           L_808008FC
    // 0x808008EC: addiu       $v1, $zero, 0x10F5
    ctx->r3 = ADD32(0, 0X10F5);
        goto L_808008FC;
    // 0x808008EC: addiu       $v1, $zero, 0x10F5
    ctx->r3 = ADD32(0, 0X10F5);
L_808008F0:
    // 0x808008F0: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x808008F4: addiu       $v1, $zero, 0xCEB
    ctx->r3 = ADD32(0, 0XCEB);
    // 0x808008F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_808008FC:
    // 0x808008FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800904: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874C0: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x800874C0);
    return;
    // 0x800874C4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800D7948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7948: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800D794C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D7950: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D7954: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D7958: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800D795C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800D7960: jal         0x80105494
    // 0x800D7964: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x800D7964: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D7968: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800D796C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7970: andi        $t6, $t0, 0x300
    ctx->r14 = ctx->r8 & 0X300;
    // 0x800D7974: beql        $t6, $zero, L_800D7A38
    if (ctx->r14 == 0) {
        // 0x800D7978: lw          $v0, 0x24($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X24);
            goto L_800D7A38;
    }
    goto skip_0;
    // 0x800D7978: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    skip_0:
    // 0x800D797C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800D7980: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800D7984: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x800D7988: jal         0x800D7520
    // 0x800D798C: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    func_800D7520(rdram, ctx);
        goto after_1;
    // 0x800D798C: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    after_1:
    // 0x800D7990: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7998: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800D799C: addiu       $a3, $sp, 0x64
    ctx->r7 = ADD32(ctx->r29, 0X64);
    // 0x800D79A0: jal         0x800C810C
    // 0x800D79A4: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    func_800C810C(rdram, ctx);
        goto after_2;
    // 0x800D79A4: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_2:
    // 0x800D79A8: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800D79AC: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D79B0: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x800D79B4: beq         $t9, $zero, L_800D79E0
    if (ctx->r25 == 0) {
        // 0x800D79B8: andi        $t3, $t0, 0x100
        ctx->r11 = ctx->r8 & 0X100;
            goto L_800D79E0;
    }
    // 0x800D79B8: andi        $t3, $t0, 0x100
    ctx->r11 = ctx->r8 & 0X100;
    // 0x800D79BC: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x800D79C0: beq         $t1, $zero, L_800D79D0
    if (ctx->r9 == 0) {
        // 0x800D79C4: andi        $t2, $t0, 0x200
        ctx->r10 = ctx->r8 & 0X200;
            goto L_800D79D0;
    }
    // 0x800D79C4: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x800D79C8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D79CC: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_800D79D0:
    // 0x800D79D0: beq         $t2, $zero, L_800D7A34
    if (ctx->r10 == 0) {
        // 0x800D79D4: lwc1        $f6, 0x64($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800D7A34;
    }
    // 0x800D79D4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D79D8: b           L_800D7A34
    // 0x800D79DC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_800D7A34;
    // 0x800D79DC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_800D79E0:
    // 0x800D79E0: beq         $t3, $zero, L_800D7A1C
    if (ctx->r11 == 0) {
        // 0x800D79E4: andi        $t4, $t0, 0x200
        ctx->r12 = ctx->r8 & 0X200;
            goto L_800D7A1C;
    }
    // 0x800D79E4: andi        $t4, $t0, 0x200
    ctx->r12 = ctx->r8 & 0X200;
    // 0x800D79E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800D79EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D79F0: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D79F4: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D79F8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800D79FC: nop

    // 0x800D7A00: bc1fl       L_800D7A18
    if (!c1cs) {
        // 0x800D7A04: add.s       $f18, $f16, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
            goto L_800D7A18;
    }
    goto skip_1;
    // 0x800D7A04: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    skip_1:
    // 0x800D7A08: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800D7A0C: b           L_800D7A1C
    // 0x800D7A10: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
        goto L_800D7A1C;
    // 0x800D7A10: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x800D7A14: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
L_800D7A18:
    // 0x800D7A18: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
L_800D7A1C:
    // 0x800D7A1C: beq         $t4, $zero, L_800D7A34
    if (ctx->r12 == 0) {
        // 0x800D7A20: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800D7A34;
    }
    // 0x800D7A20: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800D7A24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7A28: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D7A2C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D7A30: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_800D7A34:
    // 0x800D7A34: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
L_800D7A38:
    // 0x800D7A38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D7A3C: sll         $a0, $v0, 23
    ctx->r4 = S32(ctx->r2 << 23);
    // 0x800D7A40: srl         $t5, $a0, 29
    ctx->r13 = S32(U32(ctx->r4) >> 29);
    // 0x800D7A44: beq         $t5, $zero, L_800D7B34
    if (ctx->r13 == 0) {
        // 0x800D7A48: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_800D7B34;
    }
    // 0x800D7A48: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800D7A4C: lw          $t6, -0x3FEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3FEC);
    // 0x800D7A50: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800D7A54: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D7A58: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800D7A5C: lw          $t8, -0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, -0XC);
    // 0x800D7A60: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    // 0x800D7A64: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800D7A68: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x800D7A6C: bgez        $t1, L_800D7AC0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800D7A70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D7AC0;
    }
    // 0x800D7A70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D7A74: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800D7A78: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800D7A7C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800D7A80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D7A84: beq         $v0, $a0, L_800D7AA8
    if (ctx->r2 == ctx->r4) {
        // 0x800D7A88: lh          $t2, 0x2($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X2);
            goto L_800D7AA8;
    }
    // 0x800D7A88: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
L_800D7A8C:
    // 0x800D7A8C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800D7A90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D7A94: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800D7A98: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D7A9C: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x800D7AA0: bne         $v0, $a0, L_800D7A8C
    if (ctx->r2 != ctx->r4) {
        // 0x800D7AA4: lh          $t2, 0x2($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X2);
            goto L_800D7A8C;
    }
    // 0x800D7AA4: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
L_800D7AA8:
    // 0x800D7AA8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800D7AAC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800D7AB0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D7AB4: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800D7AB8: b           L_800D7B24
    // 0x800D7ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800D7B24;
    // 0x800D7ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D7AC0:
    // 0x800D7AC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800D7AC4: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800D7AC8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800D7ACC: beq         $v1, $a0, L_800D7B00
    if (ctx->r3 == ctx->r4) {
        // 0x800D7AD0: lw          $t4, 0x0($t3)
        ctx->r12 = MEM_W(ctx->r11, 0X0);
            goto L_800D7B00;
    }
    // 0x800D7AD0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
L_800D7AD4:
    // 0x800D7AD4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800D7AD8: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800D7ADC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800D7AE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D7AE4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800D7AE8: nop

    // 0x800D7AEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D7AF0: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800D7AF4: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800D7AF8: bne         $v1, $a0, L_800D7AD4
    if (ctx->r3 != ctx->r4) {
        // 0x800D7AFC: lw          $t4, 0x0($t3)
        ctx->r12 = MEM_W(ctx->r11, 0X0);
            goto L_800D7AD4;
    }
    // 0x800D7AFC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
L_800D7B00:
    // 0x800D7B00: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800D7B04: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800D7B08: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D7B0C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800D7B10: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800D7B14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D7B18: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D7B1C: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800D7B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D7B24:
    // 0x800D7B24: jal         0x800D7908
    // 0x800D7B28: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800D7908(rdram, ctx);
        goto after_3;
    // 0x800D7B28: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x800D7B2C: b           L_800D7DBC
    // 0x800D7B30: nop

        goto L_800D7DBC;
    // 0x800D7B30: nop

L_800D7B34:
    // 0x800D7B34: lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X28);
    // 0x800D7B38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7B3C: sll         $t1, $v0, 18
    ctx->r9 = S32(ctx->r2 << 18);
    // 0x800D7B40: andi        $t7, $a1, 0x3F
    ctx->r15 = ctx->r5 & 0X3F;
    // 0x800D7B44: beq         $t7, $zero, L_800D7B6C
    if (ctx->r15 == 0) {
        // 0x800D7B48: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_800D7B6C;
    }
    // 0x800D7B48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D7B4C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800D7B50: jal         0x80106790
    // 0x800D7B54: lw          $a0, -0x4090($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4090);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x800D7B54: lw          $a0, -0x4090($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4090);
    after_4:
    // 0x800D7B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7B5C: jal         0x800D7908
    // 0x800D7B60: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800D7908(rdram, ctx);
        goto after_5;
    // 0x800D7B60: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x800D7B64: b           L_800D7DBC
    // 0x800D7B68: nop

        goto L_800D7DBC;
    // 0x800D7B68: nop

L_800D7B6C:
    // 0x800D7B6C: bgezl       $t1, L_800D7B94
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800D7B70: lw          $v0, 0x44($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X44);
            goto L_800D7B94;
    }
    goto skip_2;
    // 0x800D7B70: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    skip_2:
    // 0x800D7B74: jal         0x8008FE68
    // 0x800D7B78: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_8008FE68(rdram, ctx);
        goto after_6;
    // 0x800D7B78: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x800D7B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7B80: jal         0x800D7908
    // 0x800D7B84: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800D7908(rdram, ctx);
        goto after_7;
    // 0x800D7B84: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x800D7B88: b           L_800D7DBC
    // 0x800D7B8C: nop

        goto L_800D7DBC;
    // 0x800D7B8C: nop

    // 0x800D7B90: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
L_800D7B94:
    // 0x800D7B94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7B98: srl         $t2, $v0, 31
    ctx->r10 = S32(U32(ctx->r2) >> 31);
    // 0x800D7B9C: beql        $t2, $zero, L_800D7BB0
    if (ctx->r10 == 0) {
        // 0x800D7BA0: lwc1        $f0, 0xC($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800D7BB0;
    }
    goto skip_3;
    // 0x800D7BA0: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    skip_3:
    // 0x800D7BA4: b           L_800D7BB0
    // 0x800D7BA8: lwc1        $f0, -0x4000($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4000);
        goto L_800D7BB0;
    // 0x800D7BA8: lwc1        $f0, -0x4000($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4000);
    // 0x800D7BAC: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
L_800D7BB0:
    // 0x800D7BB0: lwc1        $f2, 0x38($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800D7BB4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800D7BB8: nop

    // 0x800D7BBC: bc1fl       L_800D7D7C
    if (!c1cs) {
        // 0x800D7BC0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800D7D7C;
    }
    goto skip_4;
    // 0x800D7BC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x800D7BC4: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800D7BC8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800D7BCC: nop

    // 0x800D7BD0: bc1fl       L_800D7D7C
    if (!c1cs) {
        // 0x800D7BD4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800D7D7C;
    }
    goto skip_5;
    // 0x800D7BD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x800D7BD8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800D7BDC: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800D7BE0: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x800D7BE4: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800D7BE8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800D7BEC: andi        $t6, $t0, 0x800
    ctx->r14 = ctx->r8 & 0X800;
    // 0x800D7BF0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D7BF4: beq         $t5, $zero, L_800D7D44
    if (ctx->r13 == 0) {
        // 0x800D7BF8: swc1        $f10, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
            goto L_800D7D44;
    }
    // 0x800D7BF8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800D7BFC: beql        $t6, $zero, L_800D7CA4
    if (ctx->r14 == 0) {
        // 0x800D7C00: andi        $t4, $t0, 0x1000
        ctx->r12 = ctx->r8 & 0X1000;
            goto L_800D7CA4;
    }
    goto skip_6;
    // 0x800D7C00: andi        $t4, $t0, 0x1000
    ctx->r12 = ctx->r8 & 0X1000;
    skip_6:
    // 0x800D7C04: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x800D7C08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7C0C: srl         $t7, $v0, 23
    ctx->r15 = S32(U32(ctx->r2) >> 23);
    // 0x800D7C10: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800D7C14: sll         $t8, $v0, 9
    ctx->r24 = S32(ctx->r2 << 9);
    // 0x800D7C18: bgez        $t7, L_800D7C2C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D7C1C: cvt.s.w     $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800D7C2C;
    }
    // 0x800D7C1C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D7C20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D7C24: nop

    // 0x800D7C28: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
L_800D7C2C:
    // 0x800D7C2C: srl         $t9, $t8, 23
    ctx->r25 = S32(U32(ctx->r24) >> 23);
    // 0x800D7C30: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800D7C34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7C38: bgez        $t9, L_800D7C4C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800D7C3C: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D7C4C;
    }
    // 0x800D7C3C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D7C40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D7C44: nop

    // 0x800D7C48: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_800D7C4C:
    // 0x800D7C4C: jal         0x800F1DCC
    // 0x800D7C50: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x800D7C50: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    after_8:
    // 0x800D7C54: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7C58: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D7C5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7C60: lw          $t1, 0x40($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X40);
    // 0x800D7C64: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D7C68: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x800D7C6C: srl         $t3, $t2, 23
    ctx->r11 = S32(U32(ctx->r10) >> 23);
    // 0x800D7C70: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800D7C74: bgez        $t3, L_800D7C88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800D7C78: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800D7C88;
    }
    // 0x800D7C78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D7C7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7C80: nop

    // 0x800D7C84: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800D7C88:
    // 0x800D7C88: jal         0x800136E4
    // 0x800D7C8C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_9;
    // 0x800D7C8C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_9:
    // 0x800D7C90: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7C94: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800D7C98: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x800D7C9C: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x800D7CA0: andi        $t4, $t0, 0x1000
    ctx->r12 = ctx->r8 & 0X1000;
L_800D7CA4:
    // 0x800D7CA4: beq         $t4, $zero, L_800D7D44
    if (ctx->r12 == 0) {
        // 0x800D7CA8: sll         $t5, $v0, 3
        ctx->r13 = S32(ctx->r2 << 3);
            goto L_800D7D44;
    }
    // 0x800D7CA8: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800D7CAC: srl         $t6, $t5, 23
    ctx->r14 = S32(U32(ctx->r13) >> 23);
    // 0x800D7CB0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D7CB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7CB8: bgez        $t6, L_800D7CCC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D7CBC: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D7CCC;
    }
    // 0x800D7CBC: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D7CC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7CC4: nop

    // 0x800D7CC8: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_800D7CCC:
    // 0x800D7CCC: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x800D7CD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7CD4: sll         $t8, $t7, 18
    ctx->r24 = S32(ctx->r15 << 18);
    // 0x800D7CD8: srl         $t9, $t8, 23
    ctx->r25 = S32(U32(ctx->r24) >> 23);
    // 0x800D7CDC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800D7CE0: bgez        $t9, L_800D7CF4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800D7CE4: cvt.s.w     $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800D7CF4;
    }
    // 0x800D7CE4: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D7CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7CEC: nop

    // 0x800D7CF0: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_800D7CF4:
    // 0x800D7CF4: jal         0x800F1DCC
    // 0x800D7CF8: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    func_800F1DCC(rdram, ctx);
        goto after_10;
    // 0x800D7CF8: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    after_10:
    // 0x800D7CFC: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7D00: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D7D04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D7D08: lw          $t1, 0x40($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X40);
    // 0x800D7D0C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D7D10: sll         $t2, $t1, 18
    ctx->r10 = S32(ctx->r9 << 18);
    // 0x800D7D14: srl         $t3, $t2, 23
    ctx->r11 = S32(U32(ctx->r10) >> 23);
    // 0x800D7D18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800D7D1C: bgez        $t3, L_800D7D30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800D7D20: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D7D30;
    }
    // 0x800D7D20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D7D24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D7D28: nop

    // 0x800D7D2C: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_800D7D30:
    // 0x800D7D30: jal         0x800136E4
    // 0x800D7D34: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x800D7D34: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_11:
    // 0x800D7D38: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7D3C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x800D7D40: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
L_800D7D44:
    // 0x800D7D44: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800D7D48: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x800D7D4C: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800D7D50: beq         $t6, $zero, L_800D7DBC
    if (ctx->r14 == 0) {
        // 0x800D7D54: nop
    
            goto L_800D7DBC;
    }
    // 0x800D7D54: nop

    // 0x800D7D58: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800D7D5C: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x800D7D60: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D7D64: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800D7D68: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800D7D6C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800D7D70: b           L_800D7DBC
    // 0x800D7D74: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
        goto L_800D7DBC;
    // 0x800D7D74: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x800D7D78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800D7D7C:
    // 0x800D7D7C: nop

    // 0x800D7D80: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800D7D84: nop

    // 0x800D7D88: bc1fl       L_800D7DA8
    if (!c1cs) {
        // 0x800D7D8C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800D7DA8;
    }
    goto skip_7;
    // 0x800D7D8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_7:
    // 0x800D7D90: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800D7D94: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800D7D98: nop

    // 0x800D7D9C: bc1t        L_800D7DBC
    if (c1cs) {
        // 0x800D7DA0: nop
    
            goto L_800D7DBC;
    }
    // 0x800D7DA0: nop

    // 0x800D7DA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800D7DA8:
    // 0x800D7DA8: lbu         $t7, 0x44($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X44);
    // 0x800D7DAC: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x800D7DB0: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x800D7DB4: sb          $t8, 0x44($v1)
    MEM_B(0X44, ctx->r3) = ctx->r24;
    // 0x800D7DB8: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
L_800D7DBC:
    // 0x800D7DBC: jal         0x800D7900
    // 0x800D7DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D7900(rdram, ctx);
        goto after_12;
    // 0x800D7DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800D7DC4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D7DC8: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D7DCC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x800D7DD0: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x800D7DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7DD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D7DDC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800D7DE0: jr          $ra
    // 0x800D7DE4: nop

    return;
    // 0x800D7DE4: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CFC: jr          $ra
    // 0x80800D00: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    return;
    // 0x80800D00: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800F8B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8B14: jal         0x800F88A0
    // 0x800F8B18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8B18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F8B1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8B20: jal         0x800EE7F8
    // 0x800F8B24: addiu       $a1, $v0, 0x24
    ctx->r5 = ADD32(ctx->r2, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800F8B24: addiu       $a1, $v0, 0x24
    ctx->r5 = ADD32(ctx->r2, 0X24);
    after_1:
    // 0x800F8B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8B30: jr          $ra
    // 0x800F8B34: nop

    return;
    // 0x800F8B34: nop

;}
RECOMP_FUNC void func_80104460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104460: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80104464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010446C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80104470: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104474: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80104478: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010447C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80104480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80104484: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80104488: addiu       $a0, $a0, 0x6E80
    ctx->r4 = ADD32(ctx->r4, 0X6E80);
    // 0x8010448C: jal         0x800B3044
    // 0x80104490: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x80104490: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80104494: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80104498: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8010449C: addiu       $s3, $v0, 0x4
    ctx->r19 = ADD32(ctx->r2, 0X4);
    // 0x801044A0: sh          $t6, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r14;
    // 0x801044A4: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x801044A8: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x801044AC: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801044B0: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x801044B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801044B8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_801044BC:
    // 0x801044BC: jal         0x800EFD4C
    // 0x801044C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFD4C(rdram, ctx);
        goto after_1;
    // 0x801044C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x801044C4: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x801044C8: addiu       $s3, $s3, 0x6
    ctx->r19 = ADD32(ctx->r19, 0X6);
    // 0x801044CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801044D0: sb          $s0, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r16;
    // 0x801044D4: sb          $s0, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r16;
    // 0x801044D8: sb          $s0, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r16;
    // 0x801044DC: bne         $s2, $s4, L_801044BC
    if (ctx->r18 != ctx->r20) {
        // 0x801044E0: sb          $s0, 0x14($s1)
        MEM_B(0X14, ctx->r17) = ctx->r16;
            goto L_801044BC;
    }
    // 0x801044E0: sb          $s0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r16;
    // 0x801044E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801044E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801044EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801044F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801044F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801044F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801044FC: jr          $ra
    // 0x80104500: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80104500: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void boot_osMapTLBRdb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80019EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019EC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80019EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80019EC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80019ECC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80019ED0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80019ED4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80019ED8: jal         0x8002D780
    // 0x80019EDC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80019EDC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80019EE0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80019EE4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80019EE8: jal         0x8002E6E0
    // 0x80019EEC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80019EEC: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_1:
    // 0x80019EF0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80019EF4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80019EF8: jal         0x80030AB0
    // 0x80019EFC: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    osInvalICache_recomp(rdram, ctx);
        goto after_2;
    // 0x80019EFC: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    after_2:
    // 0x80019F00: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x80019F04: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80019F08: beq         $s0, $zero, L_80019F18
    if (ctx->r16 == 0) {
        // 0x80019F0C: subu        $a1, $t8, $s0
        ctx->r5 = SUB32(ctx->r24, ctx->r16);
            goto L_80019F18;
    }
    // 0x80019F0C: subu        $a1, $t8, $s0
    ctx->r5 = SUB32(ctx->r24, ctx->r16);
    // 0x80019F10: jal         0x8002E6E0
    // 0x80019F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x80019F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80019F18:
    // 0x80019F18: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80019F1C: lui         $t0, 0x8001
    ctx->r8 = S32(0X8001 << 16);
    // 0x80019F20: addiu       $t0, $t0, 0x2010
    ctx->r8 = ADD32(ctx->r8, 0X2010);
    // 0x80019F24: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80019F28: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80019F2C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80019F30: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80019F34: beq         $v1, $zero, L_80019F58
    if (ctx->r3 == 0) {
        // 0x80019F38: sw          $t1, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r9;
            goto L_80019F58;
    }
    // 0x80019F38: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80019F3C: jal         0x8001A2B0
    // 0x80019F40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_8001A2B0(rdram, ctx);
        goto after_4;
    // 0x80019F40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_4:
    // 0x80019F44: jal         0x8001A0A8
    // 0x80019F48: nop

    func_8001A0A8(rdram, ctx);
        goto after_5;
    // 0x80019F48: nop

    after_5:
    // 0x80019F4C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80019F50: b           L_80019F60
    // 0x80019F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80019F60;
    // 0x80019F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80019F58:
    // 0x80019F58: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80019F5C: lw          $a0, -0x166C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X166C);
L_80019F60:
    // 0x80019F60: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80019F64: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80019F68: jal         0x80012F78
    // 0x80019F6C: subu        $a2, $t2, $a1
    ctx->r6 = SUB32(ctx->r10, ctx->r5);
    rom_dma_read(rdram, ctx);
        goto after_6;
    // 0x80019F6C: subu        $a2, $t2, $a1
    ctx->r6 = SUB32(ctx->r10, ctx->r5);
    after_6:
    // 0x80019F70: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80019F74: jal         0x8001C1E0
    // 0x80019F78: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8001C1E0(rdram, ctx);
        goto after_7;
    // 0x80019F78: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80019F7C: jal         0x8001C26C
    // 0x80019F80: nop

    func_8001C26C(rdram, ctx);
        goto after_8;
    // 0x80019F80: nop

    after_8:
    // 0x80019F84: jal         0x8001C28C
    // 0x80019F88: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8001C28C(rdram, ctx);
        goto after_9;
    // 0x80019F88: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_9:
    // 0x80019F8C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80019F90: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80019F94: jal         0x8001C1E0
    // 0x80019F98: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8001C1E0(rdram, ctx);
        goto after_10;
    // 0x80019F98: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x80019F9C: beq         $s0, $zero, L_80019FF0
    if (ctx->r16 == 0) {
        // 0x80019FA0: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_80019FF0;
    }
    // 0x80019FA0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80019FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80019FA8: jal         0x8002D6E0
    // 0x80019FAC: subu        $a1, $t3, $s0
    ctx->r5 = SUB32(ctx->r11, ctx->r16);
    _bzero(rdram, ctx);
        goto after_11;
    // 0x80019FAC: subu        $a1, $t3, $s0
    ctx->r5 = SUB32(ctx->r11, ctx->r16);
    after_11:
    // 0x80019FB0: jal         0x8002D780
    // 0x80019FB4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_12;
    // 0x80019FB4: nop

    after_12:
    // 0x80019FB8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80019FBC: addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // 0x80019FC0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80019FC4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80019FC8: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80019FCC: jal         0x8001C26C
    // 0x80019FD0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8001C26C(rdram, ctx);
        goto after_13;
    // 0x80019FD0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_13:
    // 0x80019FD4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80019FD8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80019FDC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019FE0: jal         0x8001C28C
    // 0x80019FE4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8001C28C(rdram, ctx);
        goto after_14;
    // 0x80019FE4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_14:
    // 0x80019FE8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80019FEC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80019FF0:
    // 0x80019FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019FF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019FF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80019FFC: jr          $ra
    // 0x8001A000: nop

    return;
    // 0x8001A000: nop

;}
RECOMP_FUNC void func_80800164_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x8009BC34
    // 0x80800170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BC34(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: jal         0x800961AC
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_800F9400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9404: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F9408: beq         $a0, $at, L_800F941C
    if (ctx->r4 == ctx->r1) {
        // 0x800F940C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800F941C;
    }
    // 0x800F940C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F9414: bne         $a0, $at, L_800F942C
    if (ctx->r4 != ctx->r1) {
        // 0x800F9418: nop
    
            goto L_800F942C;
    }
    // 0x800F9418: nop

L_800F941C:
    // 0x800F941C: jal         0x800C964C
    // 0x800F9420: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800C964C(rdram, ctx);
        goto after_0;
    // 0x800F9420: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x800F9424: b           L_800F9438
    // 0x800F9428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9438;
    // 0x800F9428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F942C:
    // 0x800F942C: jal         0x800C964C
    // 0x800F9430: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800C964C(rdram, ctx);
        goto after_1;
    // 0x800F9430: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x800F9434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9438:
    // 0x800F9438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F943C: jr          $ra
    // 0x800F9440: nop

    return;
    // 0x800F9440: nop

;}
RECOMP_FUNC void func_800BABA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BABA0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BABA4: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x800BABA8: jr          $ra
    // 0x800BABAC: swc1        $f12, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800BABAC: swc1        $f12, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void bskazshoesspringjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800248: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(276, 0X270) << 16);
    // 0x8080024C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800250: jr          $ra
    // 0x80800254: lw          $v0, 0x270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(276, 0X270));
    return;
    // 0x80800254: lw          $v0, 0x270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(276, 0X270));
;}
RECOMP_FUNC void func_80802DF4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802DF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802DFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802E00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802E04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802E08: jal         0x80100094
    // 0x80802E0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802E0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802E10: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80802E14: addiu       $a0, $zero, 0x315
    ctx->r4 = ADD32(0, 0X315);
    // 0x80802E18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802E1C: jal         0x800DA564
    // 0x80802E20: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x80802E20: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80802E24: bne         $v0, $zero, L_80802EF8
    if (ctx->r2 != 0) {
        // 0x80802E28: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80802EF8;
    }
    // 0x80802E28: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80802E2C: jal         0x800D395C
    // 0x80802E30: nop

    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x80802E30: nop

    after_2:
    // 0x80802E34: beq         $v0, $zero, L_80802EDC
    if (ctx->r2 == 0) {
        // 0x80802E38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802EDC;
    }
    // 0x80802E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802E3C: addiu       $a0, $zero, 0xC08
    ctx->r4 = ADD32(0, 0XC08);
    // 0x80802E40: jal         0x800DA980
    // 0x80802E44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_3;
    // 0x80802E44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80802E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802E4C: jal         0x800DC128
    // 0x80802E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80802E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80802E54: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80802E58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802E5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80802E60:
    // 0x80802E60: jal         0x800DA298
    // 0x80802E64: addiu       $a0, $s0, 0xC08
    ctx->r4 = ADD32(ctx->r16, 0XC08);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80802E64: addiu       $a0, $s0, 0xC08
    ctx->r4 = ADD32(ctx->r16, 0XC08);
    after_5:
    // 0x80802E68: beql        $v0, $zero, L_80802E7C
    if (ctx->r2 == 0) {
        // 0x80802E6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80802E7C;
    }
    goto skip_0;
    // 0x80802E6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80802E70: beq         $s1, $s2, L_80802E88
    if (ctx->r17 == ctx->r18) {
        // 0x80802E74: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80802E88;
    }
    // 0x80802E74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80802E78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80802E7C:
    // 0x80802E7C: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80802E80: bne         $at, $zero, L_80802E60
    if (ctx->r1 != 0) {
        // 0x80802E84: nop
    
            goto L_80802E60;
    }
    // 0x80802E84: nop

L_80802E88:
    // 0x80802E88: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80802E8C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1240, 0X3D04) << 16);
    // 0x80802E90: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x80802E94: addiu       $t8, $t8, 0x3D04
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1240, 0X3D04));
    // 0x80802E98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802E9C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80802EA0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80802EA4:
    // 0x80802EA4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80802EA8: bne         $v1, $t9, L_80802EB8
    if (ctx->r3 != ctx->r25) {
        // 0x80802EAC: addiu       $t0, $s0, 0x1
        ctx->r8 = ADD32(ctx->r16, 0X1);
            goto L_80802EB8;
    }
    // 0x80802EAC: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x80802EB0: b           L_80802EC4
    // 0x80802EB4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
        goto L_80802EC4;
    // 0x80802EB4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_80802EB8:
    // 0x80802EB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802EBC: bne         $s0, $a0, L_80802EA4
    if (ctx->r16 != ctx->r4) {
        // 0x80802EC0: addiu       $v0, $v0, 0x3
        ctx->r2 = ADD32(ctx->r2, 0X3);
            goto L_80802EA4;
    }
    // 0x80802EC0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80802EC4:
    // 0x80802EC4: addiu       $a0, $zero, 0x315
    ctx->r4 = ADD32(0, 0X315);
    // 0x80802EC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80802ECC: jal         0x800DA7A8
    // 0x80802ED0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_6;
    // 0x80802ED0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x80802ED4: b           L_80802EFC
    // 0x80802ED8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
        goto L_80802EFC;
    // 0x80802ED8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
L_80802EDC:
    // 0x80802EDC: jal         0x800DC128
    // 0x80802EE0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x80802EE0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x80802EE4: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80802EE8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80802EEC: addiu       $a0, $zero, 0x315
    ctx->r4 = ADD32(0, 0X315);
    // 0x80802EF0: jal         0x800DA7A8
    // 0x80802EF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_8;
    // 0x80802EF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
L_80802EF8:
    // 0x80802EF8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
L_80802EFC:
    // 0x80802EFC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80802F00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802F04: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80802F08: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80802F0C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1240, 0X3D01) << 16);
    // 0x80802F10: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80802F14: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80802F18: lbu         $v0, 0x3D01($v1)
    ctx->r2 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(1240, 0X3D01));
    // 0x80802F1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802F20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802F28: jr          $ra
    // 0x80802F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80802F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsclaw_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EB8: syscall     33
    recomp_syscall_handler(rdram, ctx, 0x80082EB8);
    return;
    // 0x80082EBC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bskazjump_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083478: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083478);
    return;
    // 0x8008347C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void chspotlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1004, 0X9B0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x9B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1004, 0X9B0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x9B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1004, 0X9B0));
;}
RECOMP_FUNC void func_80800084_chlavaexplodbuild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800090: jal         0x800DA524
    // 0x80800094: addiu       $a0, $zero, 0xA24
    ctx->r4 = ADD32(0, 0XA24);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800094: addiu       $a0, $zero, 0xA24
    ctx->r4 = ADD32(0, 0XA24);
    after_0:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_808029D8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808029DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808029E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808029E4: jal         0x80100094
    // 0x808029E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029EC: beq         $v0, $zero, L_808029FC
    if (ctx->r2 == 0) {
        // 0x808029F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808029FC;
    }
    // 0x808029F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808029F4: jal         0x80087CC8
    // 0x808029F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808029F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_808029FC:
    // 0x808029FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802A04: jr          $ra
    // 0x80802A08: nop

    return;
    // 0x80802A08: nop

;}
RECOMP_FUNC void badata_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA4: jal         0x80800000
    // 0x80800EA8: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800EA8: nop

    after_0:
    // 0x80800EAC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X2378) << 16);
    // 0x80800EB8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EBC: lh          $v0, 0x2378($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X2378));
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800E146C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E146C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1470: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1474: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E1478: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E147C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1480: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800E1484: jr          $ra
    // 0x800E1488: swc1        $f12, -0x305C($at)
    MEM_W(-0X305C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800E1488: swc1        $f12, -0x305C($at)
    MEM_W(-0X305C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80804210_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804218: jal         0x808090D8
    // 0x8080421C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808090D8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080421C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804220: jal         0x80807C8C
    // 0x80804224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80804228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080422C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void chpumproomgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(992, 0XE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(992, 0XE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(992, 0XE0));
;}
