#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8008C124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C12C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C130: sb          $a1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r5;
    // 0x8008C134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C138: jal         0x8008C1B8
    // 0x8008C13C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C1B8(rdram, ctx);
        goto after_0;
    // 0x8008C13C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008C140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C144: jal         0x8008C1C0
    // 0x8008C148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008C1C0(rdram, ctx);
        goto after_1;
    // 0x8008C148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8008C14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C150: jal         0x8008C1E4
    // 0x8008C154: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008C1E4(rdram, ctx);
        goto after_2;
    // 0x8008C154: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8008C158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C15C: jal         0x8008C1D4
    // 0x8008C160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C1D4(rdram, ctx);
        goto after_3;
    // 0x8008C160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008C164: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C168: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8008C16C: sb          $t6, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r14;
    // 0x8008C170: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8008C174: jal         0x8008B8E0
    // 0x8008C178: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    func_8008B8E0(rdram, ctx);
        goto after_4;
    // 0x8008C178: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    after_4:
    // 0x8008C17C: jal         0x8008B8E0
    // 0x8008C180: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    func_8008B8E0(rdram, ctx);
        goto after_5;
    // 0x8008C180: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    after_5:
    // 0x8008C184: lbu         $t7, 0x1C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1C);
    // 0x8008C188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C18C: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8008C190: bnel        $t7, $at, L_8008C1A8
    if (ctx->r15 != ctx->r1) {
        // 0x8008C194: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C1A8;
    }
    goto skip_0;
    // 0x8008C194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008C198: jal         0x8008B8E0
    // 0x8008C19C: nop

    func_8008B8E0(rdram, ctx);
        goto after_6;
    // 0x8008C19C: nop

    after_6:
    // 0x8008C1A0: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8008C1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C1A8:
    // 0x8008C1A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C1B0: jr          $ra
    // 0x8008C1B4: nop

    return;
    // 0x8008C1B4: nop

;}
RECOMP_FUNC void chnests_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1278) << 16);
    // 0x80800F54: jr          $ra
    // 0x80800F58: addiu       $v0, $v0, 0x1278
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1278));
    return;
    // 0x80800F58: addiu       $v0, $v0, 0x1278
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1278));
;}
RECOMP_FUNC void badrone_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B4: jal         0x80800348
    // 0x808004B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x808004B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808004BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void func_80800000_chmole_prehist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1836, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1836, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1836, 0XC0));
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void func_800CB518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB518: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB51C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB520: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB524: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CB528: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800CB52C: jr          $ra
    // 0x800CB530: lh          $v0, -0x548E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X548E);
    return;
    // 0x800CB530: lh          $v0, -0x548E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X548E);
;}
RECOMP_FUNC void func_800D73AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D73AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D73B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D73B4: jal         0x800D59C0
    // 0x800D73B8: nop

    func_800D59C0(rdram, ctx);
        goto after_0;
    // 0x800D73B8: nop

    after_0:
    // 0x800D73BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D73C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D73C4: jr          $ra
    // 0x800D73C8: nop

    return;
    // 0x800D73C8: nop

;}
RECOMP_FUNC void func_80800AD8_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800AE4: jal         0x800F54E4
    // 0x80800AE8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800AEC: jal         0x800F5410
    // 0x80800AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800AF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AF8: beq         $v0, $at, L_80800B10
    if (ctx->r2 == ctx->r1) {
        // 0x80800AFC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80800B10;
    }
    // 0x80800AFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800B00: beq         $v0, $at, L_80800B10
    if (ctx->r2 == ctx->r1) {
        // 0x80800B04: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800B10;
    }
    // 0x80800B04: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800B08: bne         $v0, $at, L_80800B9C
    if (ctx->r2 != ctx->r1) {
        // 0x80800B0C: nop
    
            goto L_80800B9C;
    }
    // 0x80800B0C: nop

L_80800B10:
    // 0x80800B10: jal         0x800F54E4
    // 0x80800B14: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800B14: nop

    after_2:
    // 0x80800B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800B20: jal         0x800F5A2C
    // 0x80800B24: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F5A2C(rdram, ctx);
        goto after_3;
    // 0x80800B24: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800B28: jal         0x800F54E4
    // 0x80800B2C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800B2C: nop

    after_4:
    // 0x80800B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B38: jal         0x800F5A2C
    // 0x80800B3C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F5A2C(rdram, ctx);
        goto after_5;
    // 0x80800B3C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x80800B40: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800B44: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800B48: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80800B4C: jal         0x800EFE50
    // 0x80800B50: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x80800B50: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_6:
    // 0x80800B54: jal         0x800F54E4
    // 0x80800B58: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800B58: nop

    after_7:
    // 0x80800B5C: jal         0x800F5F24
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_8;
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800B64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B68: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B6C: jal         0x800EEB9C
    // 0x80800B70: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x80800B70: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_9:
    // 0x80800B74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800B78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B7C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800B80: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800B84: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800B88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B8C: jal         0x800EF04C
    // 0x80800B90: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80800B90: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80800B94: b           L_80800BEC
    // 0x80800B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BEC;
    // 0x80800B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B9C:
    // 0x80800B9C: jal         0x800F54E4
    // 0x80800BA0: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800BA0: nop

    after_11:
    // 0x80800BA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BA8: jal         0x800F5A00
    // 0x80800BAC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800F5A00(rdram, ctx);
        goto after_12;
    // 0x80800BAC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x80800BB0: jal         0x800F54E4
    // 0x80800BB4: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800BB4: nop

    after_13:
    // 0x80800BB8: jal         0x800F5F24
    // 0x80800BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_14;
    // 0x80800BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80800BC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BC4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800BC8: jal         0x800EF1B8
    // 0x80800BCC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_15;
    // 0x80800BCC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_15:
    // 0x80800BD0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800BD4: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800BD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BDC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800BE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800BE4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80800BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BEC:
    // 0x80800BEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800BF0: jr          $ra
    // 0x80800BF4: nop

    return;
    // 0x80800BF4: nop

;}
RECOMP_FUNC void func_8080116C_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080116C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801174: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080117C: jal         0x80100094
    // 0x80801180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801184: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80801188: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080118C: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80801190: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80801194: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80801198: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8080119C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x808011A0: jal         0x8008A028
    // 0x808011A4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808011A4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x808011A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011AC: jal         0x80103110
    // 0x808011B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x808011B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808011B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011BC: jr          $ra
    // 0x808011C0: nop

    return;
    // 0x808011C0: nop

    // 0x808011C4: nop

    // 0x808011C8: nop

    // 0x808011CC: nop

;}
RECOMP_FUNC void func_800CBBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBBC0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CBBC4: lw          $t7, -0x5174($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5174);
    // 0x800CBBC8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CBBCC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CBBD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CBBD4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800CBBD8: jr          $ra
    // 0x800CBBDC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    return;
    // 0x800CBBDC: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
;}
RECOMP_FUNC void func_808011A8_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808011AC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1812, 0X195C) << 16);
    // 0x808011B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011B8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x808011BC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x808011C0: addiu       $t6, $t6, 0x195C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1812, 0X195C));
    // 0x808011C4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808011C8: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x808011CC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1812, 0X196C) << 16);
    // 0x808011D0: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x808011D4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x808011D8: addiu       $t1, $t1, 0x196C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1812, 0X196C));
    // 0x808011DC: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x808011E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x808011E4: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x808011E8: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x808011EC: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x808011F0: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x808011F4: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808011F8: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x808011FC: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80801200: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80801204: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80801208: jal         0x800DF324
    // 0x8080120C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_800DF324(rdram, ctx);
        goto after_0;
    // 0x8080120C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_0:
    // 0x80801210: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801218: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8080121C: jal         0x800DFB40
    // 0x80801220: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800DFB40(rdram, ctx);
        goto after_1;
    // 0x80801220: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80801224: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801228: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080122C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801230: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1944) << 16);
    // 0x80801238: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080123C: lwc1        $f10, 0x1944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1944));
    // 0x80801240: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801248: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080124C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80801250: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80801254: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80801258: jal         0x800D93A0
    // 0x8080125C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    func_800D93A0(rdram, ctx);
        goto after_2;
    // 0x8080125C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801268: jal         0x800D9470
    // 0x8080126C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800D9470(rdram, ctx);
        goto after_3;
    // 0x8080126C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80801270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801274: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80801278: jal         0x800DFF2C
    // 0x8080127C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800DFF2C(rdram, ctx);
        goto after_4;
    // 0x8080127C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80801280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801288: jal         0x800DFB40
    // 0x8080128C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFB40(rdram, ctx);
        goto after_5;
    // 0x8080128C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80801290: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801298: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080129C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1948) << 16);
    // 0x808012A0: lwc1        $f10, 0x1948($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1948));
    // 0x808012A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808012A8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808012AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808012B4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808012B8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x808012BC: jal         0x800D93A0
    // 0x808012C0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    func_800D93A0(rdram, ctx);
        goto after_6;
    // 0x808012C0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808012CC: jal         0x800D9470
    // 0x808012D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800D9470(rdram, ctx);
        goto after_7;
    // 0x808012D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x808012D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808012DC: jal         0x800DFF2C
    // 0x808012E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800DFF2C(rdram, ctx);
        goto after_8;
    // 0x808012E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x808012E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808012E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808012F0: jr          $ra
    // 0x808012F4: nop

    return;
    // 0x808012F4: nop

;}
RECOMP_FUNC void func_8008C1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1B8: jr          $ra
    // 0x8008C1BC: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
    return;
    // 0x8008C1BC: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800474_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080047C: jal         0x800848E0
    // 0x80800480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _badrone_entrypoint_31(rdram, ctx);
        goto after_0;
    // 0x80800480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800484: beq         $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x80800488: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800494;
    }
    // 0x80800488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080048C: jal         0x80800000
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsstatue(rdram, ctx);
        goto after_1;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800494:
    // 0x80800494: jal         0x80082FF0
    // 0x80800498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080049C: jal         0x80800130
    // 0x808004A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800130_bsstatue(rdram, ctx);
        goto after_3;
    // 0x808004A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void func_8080130C_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080130C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801310: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80801314: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801318: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x8080131C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801324: beq         $at, $zero, L_808014A0
    if (ctx->r1 == 0) {
        // 0x80801328: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_808014A0;
    }
    // 0x80801328: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080132C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801330: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X1A74) << 16);
    // 0x80801334: addu        $at, $at, $t7
    gpr jr_addend_8080133C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801338: lw          $t7, 0x1A74($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2276, 0X1A74));
    // 0x8080133C: jr          $t7
    // 0x80801340: nop

    switch (jr_addend_8080133C >> 2) {
        case 0: goto L_80801344; break;
        case 1: goto L_808014A0; break;
        case 2: goto L_808014A0; break;
        case 3: goto L_808014A0; break;
        case 4: goto L_80801470; break;
        case 5: goto L_80801360; break;
        case 6: goto L_808013F8; break;
        case 7: goto L_80801420; break;
        case 8: goto L_80801344; break;
        case 9: goto L_808013F8; break;
        case 10: goto L_808014A0; break;
        case 11: goto L_808014A0; break;
        case 12: goto L_80801498; break;
        default: switch_error(__func__, 0x8080133C, 0x80801A74);
    }
    // 0x80801340: nop

L_80801344:
    // 0x80801344: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80801348: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8080134C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801350: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x80801354: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x80801358: b           L_808014A0
    // 0x8080135C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808014A0;
    // 0x8080135C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80801360:
    // 0x80801360: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80801364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080136C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801370: jal         0x80100094
    // 0x80801374: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801374: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_0:
    // 0x80801378: bne         $v0, $zero, L_8080138C
    if (ctx->r2 != 0) {
        // 0x8080137C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080138C;
    }
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801384: jal         0x80100074
    // 0x80801388: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80801388: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
L_8080138C:
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801390: jal         0x80100094
    // 0x80801394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801398: bne         $v0, $zero, L_808013C8
    if (ctx->r2 != 0) {
        // 0x8080139C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013C8;
    }
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808013A4: jal         0x80100074
    // 0x808013A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80100074(rdram, ctx);
        goto after_3;
    // 0x808013A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
    // 0x808013AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B0: jal         0x80100094
    // 0x808013B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808013B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808013B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808013C0: jal         0x80089F70
    // 0x808013C4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808013C4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_5:
L_808013C8:
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013CC: jal         0x80100094
    // 0x808013D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808013D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808013D4: beq         $v0, $zero, L_808014A0
    if (ctx->r2 == 0) {
        // 0x808013D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014A0;
    }
    // 0x808013D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013DC: jal         0x80100094
    // 0x808013E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808013E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E8: jal         0x8008A058
    // 0x808013EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808013EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x808013F0: b           L_808014A4
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A4;
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808013F8:
    // 0x808013F8: jal         0x800F54E4
    // 0x808013FC: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808013FC: nop

    after_9:
    // 0x80801400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801404: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801408: jal         0x800F7A2C
    // 0x8080140C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F7A2C(rdram, ctx);
        goto after_10;
    // 0x8080140C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80801410: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801414: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801418: b           L_808014A0
    // 0x8080141C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808014A0;
    // 0x8080141C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80801420:
    // 0x80801420: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801424: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80801428: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080142C: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80801430: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801434: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80801438: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
    // 0x8080143C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801444: jal         0x80100094
    // 0x80801448: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80801448: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x8080144C: beq         $v0, $zero, L_808014A0
    if (ctx->r2 == 0) {
        // 0x80801450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014A0;
    }
    // 0x80801450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801454: jal         0x80100094
    // 0x80801458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80801458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801460: jal         0x8008A058
    // 0x80801464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80801464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x80801468: b           L_808014A4
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A4;
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801470:
    // 0x80801470: jal         0x80800480
    // 0x80801474: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_14;
    // 0x80801474: nop

    after_14:
    // 0x80801478: beq         $v0, $zero, L_80801498
    if (ctx->r2 == 0) {
        // 0x8080147C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801498;
    }
    // 0x8080147C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801480: jal         0x800DA544
    // 0x80801484: nop

    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80801484: nop

    after_15:
    // 0x80801488: jal         0x80800678
    // 0x8080148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_16;
    // 0x8080148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801490: jal         0x800DA544
    // 0x80801494: addiu       $a0, $v0, 0x1B1
    ctx->r4 = ADD32(ctx->r2, 0X1B1);
    func_800DA544(rdram, ctx);
        goto after_17;
    // 0x80801494: addiu       $a0, $v0, 0x1B1
    ctx->r4 = ADD32(ctx->r2, 0X1B1);
    after_17:
L_80801498:
    // 0x80801498: jal         0x8010A570
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_18;
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_808014A0:
    // 0x808014A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808014A4:
    // 0x808014A4: jal         0x80102424
    // 0x808014A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x808014A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x808014AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014B8: jr          $ra
    // 0x808014BC: nop

    return;
    // 0x808014BC: nop

;}
RECOMP_FUNC void _chnests_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A88: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A88);
    return;
    // 0x80085A8C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _sumole_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899F8: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899F8);
    return;
    // 0x800899FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x80800000
    // 0x808000D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x808000D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000D8: bne         $v0, $zero, L_808000E8
    if (ctx->r2 != 0) {
        // 0x808000DC: nop
    
            goto L_808000E8;
    }
    // 0x808000DC: nop

    // 0x808000E0: b           L_80800114
    // 0x808000E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800114;
    // 0x808000E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E8:
    // 0x808000E8: jal         0x800F54E4
    // 0x808000EC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808000EC: nop

    after_1:
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808000F8: jal         0x800F4B8C
    // 0x808000FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800F4B8C(rdram, ctx);
        goto after_2;
    // 0x808000FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800100: bnel        $v0, $zero, L_80800114
    if (ctx->r2 != 0) {
        // 0x80800104: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800114;
    }
    goto skip_0;
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800108: b           L_80800114
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800114;
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_800ED144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ED148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ED14C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800ED150: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x800ED154: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800ED158: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x800ED15C: lwc1        $f6, 0x9C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x800ED160: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800ED164: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800ED168: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED16C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ED170: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED174: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800ED178: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x800ED17C: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800ED180: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800ED184: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED188: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ED18C: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800ED190: lwc1        $f18, 0x80($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800ED194: lwc1        $f16, 0x90($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X90);
    // 0x800ED198: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800ED19C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ED1A0: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800ED1A4: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800ED1A8: lwc1        $f8, 0x94($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X94);
    // 0x800ED1AC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED1B0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800ED1B4: beq         $at, $zero, L_800ED41C
    if (ctx->r1 == 0) {
        // 0x800ED1B8: swc1        $f18, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
            goto L_800ED41C;
    }
    // 0x800ED1B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
L_800ED1BC:
    // 0x800ED1BC: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ED1C0: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800ED1C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ED1C8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED1CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ED1D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED1D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800ED1D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ED1DC: nop

    // 0x800ED1E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ED1E4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ED1E8: nop

    // 0x800ED1EC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ED1F0: beql        $t8, $zero, L_800ED240
    if (ctx->r24 == 0) {
        // 0x800ED1F4: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_800ED240;
    }
    goto skip_0;
    // 0x800ED1F4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x800ED1F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ED1FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ED200: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED204: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ED208: nop

    // 0x800ED20C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ED210: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ED214: nop

    // 0x800ED218: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ED21C: bne         $t8, $zero, L_800ED234
    if (ctx->r24 != 0) {
        // 0x800ED220: nop
    
            goto L_800ED234;
    }
    // 0x800ED220: nop

    // 0x800ED224: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800ED228: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED22C: b           L_800ED24C
    // 0x800ED230: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800ED24C;
    // 0x800ED230: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800ED234:
    // 0x800ED234: b           L_800ED24C
    // 0x800ED238: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800ED24C;
    // 0x800ED238: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800ED23C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_800ED240:
    // 0x800ED240: nop

    // 0x800ED244: bltz        $t8, L_800ED234
    if (SIGNED(ctx->r24) < 0) {
        // 0x800ED248: nop
    
            goto L_800ED234;
    }
    // 0x800ED248: nop

L_800ED24C:
    // 0x800ED24C: sb          $t8, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r24;
    // 0x800ED250: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800ED254: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800ED258: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ED25C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ED260: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED264: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ED268: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ED26C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800ED270: nop

    // 0x800ED274: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800ED278: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800ED27C: nop

    // 0x800ED280: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800ED284: beql        $t0, $zero, L_800ED2D4
    if (ctx->r8 == 0) {
        // 0x800ED288: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_800ED2D4;
    }
    goto skip_1;
    // 0x800ED288: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800ED28C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED290: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ED294: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED298: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800ED29C: nop

    // 0x800ED2A0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ED2A4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800ED2A8: nop

    // 0x800ED2AC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800ED2B0: bne         $t0, $zero, L_800ED2C8
    if (ctx->r8 != 0) {
        // 0x800ED2B4: nop
    
            goto L_800ED2C8;
    }
    // 0x800ED2B4: nop

    // 0x800ED2B8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800ED2BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED2C0: b           L_800ED2E0
    // 0x800ED2C4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800ED2E0;
    // 0x800ED2C4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800ED2C8:
    // 0x800ED2C8: b           L_800ED2E0
    // 0x800ED2CC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800ED2E0;
    // 0x800ED2CC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800ED2D0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_800ED2D4:
    // 0x800ED2D4: nop

    // 0x800ED2D8: bltz        $t0, L_800ED2C8
    if (SIGNED(ctx->r8) < 0) {
        // 0x800ED2DC: nop
    
            goto L_800ED2C8;
    }
    // 0x800ED2DC: nop

L_800ED2E0:
    // 0x800ED2E0: sb          $t0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r8;
    // 0x800ED2E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ED2E8: lwc1        $f10, 0x80($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800ED2EC: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ED2F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ED2F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED2F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ED2FC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800ED300: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ED304: nop

    // 0x800ED308: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800ED30C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ED310: nop

    // 0x800ED314: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ED318: beql        $t2, $zero, L_800ED368
    if (ctx->r10 == 0) {
        // 0x800ED31C: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_800ED368;
    }
    goto skip_2;
    // 0x800ED31C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800ED320: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ED324: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ED328: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800ED32C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ED330: nop

    // 0x800ED334: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800ED338: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ED33C: nop

    // 0x800ED340: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ED344: bne         $t2, $zero, L_800ED35C
    if (ctx->r10 != 0) {
        // 0x800ED348: nop
    
            goto L_800ED35C;
    }
    // 0x800ED348: nop

    // 0x800ED34C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800ED350: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED354: b           L_800ED374
    // 0x800ED358: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800ED374;
    // 0x800ED358: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800ED35C:
    // 0x800ED35C: b           L_800ED374
    // 0x800ED360: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800ED374;
    // 0x800ED360: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800ED364: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_800ED368:
    // 0x800ED368: nop

    // 0x800ED36C: bltz        $t2, L_800ED35C
    if (SIGNED(ctx->r10) < 0) {
        // 0x800ED370: nop
    
            goto L_800ED35C;
    }
    // 0x800ED370: nop

L_800ED374:
    // 0x800ED374: sb          $t2, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r10;
    // 0x800ED378: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800ED37C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800ED380: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ED384: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800ED388: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED38C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ED390: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800ED394: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800ED398: nop

    // 0x800ED39C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ED3A0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800ED3A4: nop

    // 0x800ED3A8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800ED3AC: beql        $t4, $zero, L_800ED3FC
    if (ctx->r12 == 0) {
        // 0x800ED3B0: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_800ED3FC;
    }
    goto skip_3;
    // 0x800ED3B0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x800ED3B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ED3B8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800ED3BC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED3C0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800ED3C4: nop

    // 0x800ED3C8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ED3CC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800ED3D0: nop

    // 0x800ED3D4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800ED3D8: bne         $t4, $zero, L_800ED3F0
    if (ctx->r12 != 0) {
        // 0x800ED3DC: nop
    
            goto L_800ED3F0;
    }
    // 0x800ED3DC: nop

    // 0x800ED3E0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800ED3E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED3E8: b           L_800ED408
    // 0x800ED3EC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800ED408;
    // 0x800ED3EC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800ED3F0:
    // 0x800ED3F0: b           L_800ED408
    // 0x800ED3F4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800ED408;
    // 0x800ED3F4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800ED3F8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_800ED3FC:
    // 0x800ED3FC: nop

    // 0x800ED400: bltz        $t4, L_800ED3F0
    if (SIGNED(ctx->r12) < 0) {
        // 0x800ED404: nop
    
            goto L_800ED3F0;
    }
    // 0x800ED404: nop

L_800ED408:
    // 0x800ED408: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ED40C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800ED410: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED414: bne         $at, $zero, L_800ED1BC
    if (ctx->r1 != 0) {
        // 0x800ED418: sb          $t4, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r12;
            goto L_800ED1BC;
    }
    // 0x800ED418: sb          $t4, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r12;
L_800ED41C:
    // 0x800ED41C: jr          $ra
    // 0x800ED420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800ED420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808033D8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808033DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808033E0: jal         0x80100094
    // 0x808033E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808033E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808033E8: lbu         $t6, 0x62($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X62);
    // 0x808033EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808033F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808033F4: bne         $t6, $zero, L_80803404
    if (ctx->r14 != 0) {
        // 0x808033F8: addiu       $v1, $zero, 0x8
        ctx->r3 = ADD32(0, 0X8);
            goto L_80803404;
    }
    // 0x808033F8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x808033FC: b           L_80803404
    // 0x80803400: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80803404;
    // 0x80803400: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80803404:
    // 0x80803404: jr          $ra
    // 0x80803408: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80803408: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _sukickball_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AF8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AF8);
    return;
    // 0x80089AFC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80016E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016E80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016E84: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80016E88: addiu       $s1, $s1, -0x5188
    ctx->r17 = ADD32(ctx->r17, -0X5188);
    // 0x80016E8C: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x80016E90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80016E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016E98: blez        $t6, L_80016EBC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80016E9C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80016EBC;
    }
    // 0x80016E9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80016EA0:
    // 0x80016EA0: jal         0x80016DF8
    // 0x80016EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80016DF8(rdram, ctx);
        goto after_0;
    // 0x80016EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80016EA8: lhu         $t7, 0x0($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X0);
    // 0x80016EAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80016EB0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80016EB4: bne         $at, $zero, L_80016EA0
    if (ctx->r1 != 0) {
        // 0x80016EB8: nop
    
            goto L_80016EA0;
    }
    // 0x80016EB8: nop

L_80016EBC:
    // 0x80016EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016EC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80016EC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80016EC8: jr          $ra
    // 0x80016ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80016ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fxrain_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F8: jal         0x800B28B8
    // 0x808001FC: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    vector_clear(rdram, ctx);
        goto after_0;
    // 0x808001FC: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800264_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080026C: jal         0x80800240
    // 0x80800270: nop

    func_80800240_chlagoonfish(rdram, ctx);
        goto after_0;
    // 0x80800270: nop

    after_0:
    // 0x80800274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
RECOMP_FUNC void chglowbo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080123C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80801240: jal         0x80086D28
    // 0x80801244: addiu       $a0, $a0, 0x6AE8
    ctx->r4 = ADD32(ctx->r4, 0X6AE8);
    _chbaddiesetup_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801244: addiu       $a0, $a0, 0x6AE8
    ctx->r4 = ADD32(ctx->r4, 0X6AE8);
    after_0:
    // 0x80801248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080124C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801250: jr          $ra
    // 0x80801254: nop

    return;
    // 0x80801254: nop

;}
RECOMP_FUNC void _chstinger_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872C0: syscall     546
    recomp_syscall_handler(rdram, ctx, 0x800872C0);
    return;
    // 0x800872C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncpoddialog_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802834: sb          $a1, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r5;
    // 0x80802838: jr          $ra
    // 0x8080283C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x8080283C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
;}
RECOMP_FUNC void _susplinet_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E78: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E78);
    return;
    // 0x80089E7C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_801032B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801032B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801032B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801032B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801032BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801032C0: lh          $t8, 0x8C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8C);
    // 0x801032C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x801032C8: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x801032CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801032D0: sh          $zero, 0x8C($a0)
    MEM_H(0X8C, ctx->r4) = 0;
    // 0x801032D4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x801032D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x801032DC: jal         0x80103140
    // 0x801032E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x801032E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801032E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801032E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801032EC: lh          $t9, 0x8C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8C);
    // 0x801032F0: beql        $t9, $zero, L_80103310
    if (ctx->r25 == 0) {
        // 0x801032F4: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_80103310;
    }
    goto skip_0;
    // 0x801032F4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x801032F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801032FC: jal         0x80104328
    // 0x80103300: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80104328(rdram, ctx);
        goto after_1;
    // 0x80103300: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80103304: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80103308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010330C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_80103310:
    // 0x80103310: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80103314: sh          $t0, 0x8C($a0)
    MEM_H(0X8C, ctx->r4) = ctx->r8;
    // 0x80103318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010331C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103320: jr          $ra
    // 0x80103324: nop

    return;
    // 0x80103324: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857D8: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857D8);
    return;
    // 0x800857DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chboggyfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087188: syscall     527
    recomp_syscall_handler(rdram, ctx, 0x80087188);
    return;
    // 0x8008718C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfloorbubbles_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C60: syscall     436
    recomp_syscall_handler(rdram, ctx, 0x80086C60);
    return;
    // 0x80086C64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80805448_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805448: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080544C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80805450: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80805454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805458: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080545C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80805460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80805464: jal         0x80100094
    // 0x80805468: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805468: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080546C: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x80805470: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80805474: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80805478: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080547C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80805480: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80805484: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80805488: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080548C: beq         $a2, $zero, L_808054B4
    if (ctx->r6 == 0) {
        // 0x80805490: sh          $a2, 0x34($t8)
        MEM_H(0X34, ctx->r24) = ctx->r6;
            goto L_808054B4;
    }
    // 0x80805490: sh          $a2, 0x34($t8)
    MEM_H(0X34, ctx->r24) = ctx->r6;
    // 0x80805494: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80805498: beq         $a2, $t0, L_80805520
    if (ctx->r6 == ctx->r8) {
        // 0x8080549C: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80805520;
    }
    // 0x8080549C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x808054A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808054A4: beq         $a2, $at, L_80805584
    if (ctx->r6 == ctx->r1) {
        // 0x808054A8: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80805584;
    }
    // 0x808054A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x808054AC: b           L_80805608
    // 0x808054B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80805608;
    // 0x808054B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808054B4:
    // 0x808054B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808054B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808054BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808054C0: jal         0x80805960
    // 0x808054C4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80805960_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808054C4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x808054C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808054CC: lui         $t3, 0x8081
    ctx->r11 = S32(RELOC_HI16(1480, 0XA068) << 16);
    // 0x808054D0: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x808054D4: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x808054D8: lbu         $t3, -0x5F98($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(1480, 0XA068));
    // 0x808054DC: lbu         $t8, 0x1B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1B);
    // 0x808054E0: sll         $t1, $t9, 27
    ctx->r9 = S32(ctx->r25 << 27);
    // 0x808054E4: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x808054E8: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x808054EC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x808054F0: andi        $t7, $t6, 0x1E
    ctx->r15 = ctx->r14 & 0X1E;
    // 0x808054F4: andi        $t9, $t8, 0xFFE1
    ctx->r25 = ctx->r24 & 0XFFE1;
    // 0x808054F8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808054FC: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80805500: sb          $t1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r9;
    // 0x80805504: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80805508: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8080550C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80805510: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80805514: sb          $zero, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = 0;
    // 0x80805518: b           L_80805604
    // 0x8080551C: sb          $zero, 0x49($v1)
    MEM_B(0X49, ctx->r3) = 0;
        goto L_80805604;
    // 0x8080551C: sb          $zero, 0x49($v1)
    MEM_B(0X49, ctx->r3) = 0;
L_80805520:
    // 0x80805520: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80805524: jal         0x800DC128
    // 0x80805528: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80805528: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8080552C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805534: jal         0x80805960
    // 0x80805538: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80805960_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80805538: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8080553C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80805540: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(1480, 0XA068) << 16);
    // 0x80805544: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80805548: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x8080554C: lbu         $t8, -0x5F98($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(1480, 0XA068));
    // 0x80805550: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80805554: sll         $t5, $t4, 27
    ctx->r13 = S32(ctx->r12 << 27);
    // 0x80805558: lbu         $t4, 0x1B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1B);
    // 0x8080555C: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80805560: nor         $t7, $t8, $zero
    ctx->r15 = ~(ctx->r24 | 0);
    // 0x80805564: and         $t1, $t6, $t7
    ctx->r9 = ctx->r14 & ctx->r15;
    // 0x80805568: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8080556C: andi        $t3, $t2, 0x1E
    ctx->r11 = ctx->r10 & 0X1E;
    // 0x80805570: andi        $t5, $t4, 0xFFE1
    ctx->r13 = ctx->r12 & 0XFFE1;
    // 0x80805574: or          $t8, $t3, $t5
    ctx->r24 = ctx->r11 | ctx->r13;
    // 0x80805578: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080557C: b           L_80805604
    // 0x80805580: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
        goto L_80805604;
    // 0x80805580: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
L_80805584:
    // 0x80805584: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80805588: jal         0x800DC128
    // 0x8080558C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x8080558C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80805590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805598: jal         0x80805960
    // 0x8080559C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80805960_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080559C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x808055A0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808055A4: lui         $t1, 0x8081
    ctx->r9 = S32(RELOC_HI16(1480, 0XA068) << 16);
    // 0x808055A8: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x808055AC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x808055B0: lbu         $t1, -0x5F98($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(1480, 0XA068));
    // 0x808055B4: lbu         $t8, 0x1B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1B);
    // 0x808055B8: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x808055BC: srl         $t9, $t7, 28
    ctx->r25 = S32(U32(ctx->r15) >> 28);
    // 0x808055C0: or          $t4, $t9, $t1
    ctx->r12 = ctx->r25 | ctx->r9;
    // 0x808055C4: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x808055C8: andi        $t5, $t3, 0x1E
    ctx->r13 = ctx->r11 & 0X1E;
    // 0x808055CC: andi        $t6, $t8, 0xFFE1
    ctx->r14 = ctx->r24 & 0XFFE1;
    // 0x808055D0: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x808055D4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B98) << 16);
    // 0x808055D8: sb          $t7, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r15;
    // 0x808055DC: lwc1        $f12, -0x6468($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B98));
    // 0x808055E0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B9C) << 16);
    // 0x808055E4: jal         0x800DC178
    // 0x808055E8: lwc1        $f14, -0x6464($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B9C));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808055E8: lwc1        $f14, -0x6464($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B9C));
    after_6:
    // 0x808055EC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x808055F0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808055F4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808055F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808055FC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80805600: swc1        $f0, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f0.u32l;
L_80805604:
    // 0x80805604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805608:
    // 0x80805608: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080560C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
L_80805610:
    // 0x80805610: lh          $t4, 0x34($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X34);
    // 0x80805614: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80805618: bne         $t0, $t4, L_80805624
    if (ctx->r8 != ctx->r12) {
        // 0x8080561C: nop
    
            goto L_80805624;
    }
    // 0x8080561C: nop

    // 0x80805620: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80805624:
    // 0x80805624: bne         $v0, $a0, L_80805610
    if (ctx->r2 != ctx->r4) {
        // 0x80805628: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_80805610;
    }
    // 0x80805628: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8080562C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80805630: slt         $s0, $zero, $a3
    ctx->r16 = SIGNED(0) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80805634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805638: jal         0x808056F8
    // 0x8080563C: sb          $s0, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r16;
    func_808056F8_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x8080563C: sb          $s0, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r16;
    after_7:
    // 0x80805640: beql        $s0, $zero, L_8080567C
    if (ctx->r16 == 0) {
        // 0x80805644: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8080567C;
    }
    goto skip_0;
    // 0x80805644: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80805648: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8080564C: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x80805650: lhu         $t4, 0x2A($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2A);
    // 0x80805654: sll         $t5, $t8, 23
    ctx->r13 = S32(ctx->r24 << 23);
    // 0x80805658: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
    // 0x8080565C: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80805660: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80805664: andi        $t2, $t1, 0x1FE
    ctx->r10 = ctx->r9 & 0X1FE;
    // 0x80805668: andi        $t3, $t4, 0xFE01
    ctx->r11 = ctx->r12 & 0XFE01;
    // 0x8080566C: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x80805670: b           L_808056A4
    // 0x80805674: sh          $t8, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r24;
        goto L_808056A4;
    // 0x80805674: sh          $t8, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r24;
    // 0x80805678: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8080567C:
    // 0x8080567C: lw          $t5, 0x28($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X28);
    // 0x80805680: lhu         $t3, 0x2A($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2A);
    // 0x80805684: sll         $t6, $t5, 23
    ctx->r14 = S32(ctx->r13 << 23);
    // 0x80805688: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x8080568C: andi        $t1, $t7, 0xFFFB
    ctx->r9 = ctx->r15 & 0XFFFB;
    // 0x80805690: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80805694: andi        $t2, $t4, 0x1FE
    ctx->r10 = ctx->r12 & 0X1FE;
    // 0x80805698: andi        $t8, $t3, 0xFE01
    ctx->r24 = ctx->r11 & 0XFE01;
    // 0x8080569C: or          $t5, $t2, $t8
    ctx->r13 = ctx->r10 | ctx->r24;
    // 0x808056A0: sh          $t5, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r13;
L_808056A4:
    // 0x808056A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808056A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808056AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808056B0: jr          $ra
    // 0x808056B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808056B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void subaddieaudioquick_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000A8: jal         0x80800050
    // 0x808000AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000B0: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x808000B4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808000B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000BC: jal         0x800C4350
    // 0x808000C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x808000C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808000C4: jal         0x800C3BDC
    // 0x808000C8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    func_800C3BDC(rdram, ctx);
        goto after_2;
    // 0x808000C8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    after_2:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void fxsparkle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: jal         0x80088AC8
    // 0x808000B8: nop

    _fxspgold_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000B8: nop

    after_0:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

    // 0x808000CC: nop

;}
RECOMP_FUNC void func_800927C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800927C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800927C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800927CC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800927D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800927D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800927D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800927DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800927E0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800927E4: jal         0x800F6BE4
    // 0x800927E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_0;
    // 0x800927E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800927EC: beql        $v0, $zero, L_80092854
    if (ctx->r2 == 0) {
        // 0x800927F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80092854;
    }
    goto skip_0;
    // 0x800927F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800927F4: jal         0x800F53D0
    // 0x800927F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x800927F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800927FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80092800: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80092804: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80092808: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8009280C: jal         0x800EFA4C
    // 0x80092810: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80092810: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80092814: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80092818: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8009281C: jal         0x80108474
    // 0x80092820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_3;
    // 0x80092820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80092824: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80092828: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x8009282C: sw          $t6, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r14;
    // 0x80092830: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80092834: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    // 0x80092838: jal         0x800A70D0
    // 0x8009283C: lw          $a0, 0x84($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X84);
    func_800A70D0(rdram, ctx);
        goto after_4;
    // 0x8009283C: lw          $a0, 0x84($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X84);
    after_4:
    // 0x80092840: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80092844: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80092848: jal         0x800A7108
    // 0x8009284C: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    func_800A7108(rdram, ctx);
        goto after_5;
    // 0x8009284C: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    after_5:
    // 0x80092850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80092854:
    // 0x80092854: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80092858: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009285C: jr          $ra
    // 0x80092860: nop

    return;
    // 0x80092860: nop

;}
RECOMP_FUNC void func_80102128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010212C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102134: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80102138: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010213C: jal         0x8001210C
    // 0x80102140: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80102140: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80102144: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80102148: bnel        $v0, $t6, L_80102180
    if (ctx->r2 != ctx->r14) {
        // 0x8010214C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80102180;
    }
    goto skip_0;
    // 0x8010214C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80102150: jal         0x800DC298
    // 0x80102154: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80102154: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80102158: beq         $v0, $zero, L_8010217C
    if (ctx->r2 == 0) {
        // 0x8010215C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8010217C;
    }
    // 0x8010215C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80102160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80102164: beq         $a1, $at, L_80102174
    if (ctx->r5 == ctx->r1) {
        // 0x80102168: nop
    
            goto L_80102174;
    }
    // 0x80102168: nop

    // 0x8010216C: jal         0x80102424
    // 0x80102170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80102170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80102174:
    // 0x80102174: b           L_80102180
    // 0x80102178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80102180;
    // 0x80102178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010217C:
    // 0x8010217C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102180:
    // 0x80102180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102188: jr          $ra
    // 0x8010218C: nop

    return;
    // 0x8010218C: nop

;}
RECOMP_FUNC void func_80800070_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: jal         0x80100094
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800088: jal         0x80088848
    // 0x8080008C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080008C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800090: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800094: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800098: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080009C: sw          $t6, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r14;
    // 0x808000A0: lhu         $v1, 0x76($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X76);
    // 0x808000A4: srl         $t7, $v1, 7
    ctx->r15 = S32(U32(ctx->r3) >> 7);
    // 0x808000A8: addiu       $t9, $t7, -0x32
    ctx->r25 = ADD32(ctx->r15, -0X32);
    // 0x808000AC: sll         $t2, $t9, 7
    ctx->r10 = S32(ctx->r25 << 7);
    // 0x808000B0: andi        $t3, $v1, 0x7F
    ctx->r11 = ctx->r3 & 0X7F;
    // 0x808000B4: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x808000B8: jal         0x800EA05C
    // 0x808000BC: sh          $t4, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r12;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808000BC: sh          $t4, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r12;
    after_2:
    // 0x808000C0: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x808000C4: bne         $v0, $at, L_808000DC
    if (ctx->r2 != ctx->r1) {
        // 0x808000C8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808000DC;
    }
    // 0x808000C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808000CC: lbu         $t5, 0x7A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7A);
    // 0x808000D0: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x808000D4: b           L_808000E8
    // 0x808000D8: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
        goto L_808000E8;
    // 0x808000D8: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
L_808000DC:
    // 0x808000DC: lbu         $t8, 0x7A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7A);
    // 0x808000E0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x808000E4: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
L_808000E8:
    // 0x808000E8: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x808000EC: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x808000F0: beql        $t2, $zero, L_80800118
    if (ctx->r10 == 0) {
        // 0x808000F4: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_80800118;
    }
    goto skip_0;
    // 0x808000F4: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    skip_0:
    // 0x808000F8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: addiu       $a1, $zero, 0x7FD
    ctx->r5 = ADD32(0, 0X7FD);
    // 0x80800104: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    // 0x80800108: jal         0x801032B0
    // 0x8080010C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_801032B0(rdram, ctx);
        goto after_3;
    // 0x8080010C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x80800110: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800114: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
L_80800118:
    // 0x80800118: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8080011C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80800120: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x80800124: sb          $zero, 0x9($t0)
    MEM_B(0X9, ctx->r8) = 0;
    // 0x80800128: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8080012C: sb          $zero, 0x6($t0)
    MEM_B(0X6, ctx->r8) = 0;
    // 0x80800130: sb          $zero, 0xA($t0)
    MEM_B(0XA, ctx->r8) = 0;
    // 0x80800134: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x80800138: sb          $zero, 0x7($t0)
    MEM_B(0X7, ctx->r8) = 0;
    // 0x8080013C: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
    // 0x80800140: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80800144: sb          $zero, 0x4($t0)
    MEM_B(0X4, ctx->r8) = 0;
    // 0x80800148: sb          $zero, 0x8($t0)
    MEM_B(0X8, ctx->r8) = 0;
    // 0x8080014C: sb          $t4, 0x5C($t0)
    MEM_B(0X5C, ctx->r8) = ctx->r12;
    // 0x80800150: sw          $t5, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r13;
    // 0x80800154: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800158: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    // 0x8080015C: bnel        $t6, $zero, L_808002E0
    if (ctx->r14 != 0) {
        // 0x80800160: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808002E0;
    }
    goto skip_1;
    // 0x80800160: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x80800164: jal         0x800DA298
    // 0x80800168: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800168: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8080016C: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x80800170: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808001F8;
    }
    // 0x80800170: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800174: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    // 0x80800178: jal         0x800DA298
    // 0x8080017C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080017C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_5:
    // 0x80800180: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x80800184: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808001F8;
    }
    // 0x80800184: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080018C: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    // 0x80800190: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80800194: beq         $t7, $zero, L_808001B8
    if (ctx->r15 == 0) {
        // 0x80800198: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_808001B8;
    }
    // 0x80800198: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8080019C: jal         0x800DA298
    // 0x808001A0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808001A0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_6:
    // 0x808001A4: bne         $v0, $zero, L_808001D0
    if (ctx->r2 != 0) {
        // 0x808001A8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808001D0;
    }
    // 0x808001A8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808001AC: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x808001B0: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x808001B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808001B8:
    // 0x808001B8: bne         $v0, $zero, L_808001F8
    if (ctx->r2 != 0) {
        // 0x808001BC: addiu       $a0, $zero, 0x1D2
        ctx->r4 = ADD32(0, 0X1D2);
            goto L_808001F8;
    }
    // 0x808001BC: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    // 0x808001C0: jal         0x800DA298
    // 0x808001C4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808001C4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_7:
    // 0x808001C8: bne         $v0, $zero, L_808001F8
    if (ctx->r2 != 0) {
        // 0x808001CC: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808001F8;
    }
    // 0x808001CC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808001D0:
    // 0x808001D0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808001D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5570) << 16);
    // 0x808001D8: addiu       $a2, $a2, 0x5570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5570));
    // 0x808001DC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x808001E0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001EC: jal         0x800D1000
    // 0x808001F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800D1000(rdram, ctx);
        goto after_8;
    // 0x808001F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x808001F4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808001F8:
    // 0x808001F8: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x808001FC: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    // 0x80800200: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80800204: beq         $t1, $zero, L_80800228
    if (ctx->r9 == 0) {
        // 0x80800208: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80800228;
    }
    // 0x80800208: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8080020C: jal         0x800DA298
    // 0x80800210: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800210: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_9:
    // 0x80800214: bne         $v0, $zero, L_80800240
    if (ctx->r2 != 0) {
        // 0x80800218: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800240;
    }
    // 0x80800218: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080021C: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800220: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80800224: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80800228:
    // 0x80800228: bne         $v0, $zero, L_80800258
    if (ctx->r2 != 0) {
        // 0x8080022C: addiu       $a0, $zero, 0x1D6
        ctx->r4 = ADD32(0, 0X1D6);
            goto L_80800258;
    }
    // 0x8080022C: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    // 0x80800230: jal         0x800DA298
    // 0x80800234: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800234: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_10:
    // 0x80800238: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x8080023C: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800258;
    }
    // 0x8080023C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80800240:
    // 0x80800240: jal         0x800861A8
    // 0x80800244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80800248: jal         0x800FFAB0
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800250: b           L_808003C8
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C8;
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800258:
    // 0x80800258: jal         0x800D395C
    // 0x8080025C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800D395C(rdram, ctx);
        goto after_13;
    // 0x8080025C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_13:
    // 0x80800260: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800264: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800288;
    }
    // 0x80800264: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800268: lbu         $t3, 0x7A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080026C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80800270: beql        $t4, $zero, L_808002E0
    if (ctx->r12 == 0) {
        // 0x80800274: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808002E0;
    }
    goto skip_2;
    // 0x80800274: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x80800278: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x8080027C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80800280: b           L_808002DC
    // 0x80800284: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_808002DC;
    // 0x80800284: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800288:
    // 0x80800288: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080028C: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    // 0x80800290: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80800294: beq         $t8, $zero, L_808002B8
    if (ctx->r24 == 0) {
        // 0x80800298: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_808002B8;
    }
    // 0x80800298: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8080029C: jal         0x800DA298
    // 0x808002A0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808002A0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_14:
    // 0x808002A4: bne         $v0, $zero, L_808002D0
    if (ctx->r2 != 0) {
        // 0x808002A8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808002D0;
    }
    // 0x808002A8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808002AC: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x808002B0: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x808002B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_808002B8:
    // 0x808002B8: bne         $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808002BC: addiu       $a0, $zero, 0x1D5
        ctx->r4 = ADD32(0, 0X1D5);
            goto L_808002DC;
    }
    // 0x808002BC: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    // 0x808002C0: jal         0x800DA298
    // 0x808002C4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808002C4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_15:
    // 0x808002C8: beq         $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x808002CC: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808002DC;
    }
    // 0x808002CC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808002D0:
    // 0x808002D0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808002D4: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x808002D8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808002DC:
    // 0x808002DC: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_808002E0:
    // 0x808002E0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x808002EC: bgez        $t6, L_80800300
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808002F0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800300;
    }
    // 0x808002F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002F4: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x808002F8: b           L_80800304
    // 0x808002FC: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
        goto L_80800304;
    // 0x808002FC: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_80800300:
    // 0x80800300: sw          $t8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r24;
L_80800304:
    // 0x80800304: sb          $zero, 0x58($t0)
    MEM_B(0X58, ctx->r8) = 0;
    // 0x80800308: sb          $zero, 0x59($t0)
    MEM_B(0X59, ctx->r8) = 0;
    // 0x8080030C: sb          $zero, 0x5D($t0)
    MEM_B(0X5D, ctx->r8) = 0;
    // 0x80800310: sb          $zero, 0x5E($t0)
    MEM_B(0X5E, ctx->r8) = 0;
    // 0x80800314: sb          $zero, 0x60($t0)
    MEM_B(0X60, ctx->r8) = 0;
    // 0x80800318: sb          $zero, 0x5F($t0)
    MEM_B(0X5F, ctx->r8) = 0;
    // 0x8080031C: sb          $zero, 0x55($t0)
    MEM_B(0X55, ctx->r8) = 0;
    // 0x80800320: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800324: addiu       $v0, $zero, 0x76
    ctx->r2 = ADD32(0, 0X76);
    // 0x80800328: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8080032C: beq         $t1, $zero, L_8080033C
    if (ctx->r9 == 0) {
        // 0x80800330: nop
    
            goto L_8080033C;
    }
    // 0x80800330: nop

    // 0x80800334: b           L_8080033C
    // 0x80800338: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
        goto L_8080033C;
    // 0x80800338: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
L_8080033C:
    // 0x8080033C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800340: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800344: jal         0x800897C0
    // 0x80800348: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x80800348: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_16:
    // 0x8080034C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: beql        $t3, $zero, L_80800370
    if (ctx->r11 == 0) {
        // 0x80800358: lbu         $t4, 0x65($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X65);
            goto L_80800370;
    }
    goto skip_3;
    // 0x80800358: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    skip_3:
    // 0x8080035C: jal         0x808012B4
    // 0x80800360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_17;
    // 0x80800360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800364: b           L_808003C8
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C8;
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080036C: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
L_80800370:
    // 0x80800370: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800374: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80800378: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8080037C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800380: beq         $t6, $zero, L_808003A4
    if (ctx->r14 == 0) {
        // 0x80800384: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808003A4;
    }
    // 0x80800384: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800388: jal         0x800DA298
    // 0x8080038C: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x8080038C: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    after_18:
    // 0x80800390: bnel        $v0, $zero, L_808003BC
    if (ctx->r2 != 0) {
        // 0x80800394: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_4;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800398: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080039C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x808003A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_808003A4:
    // 0x808003A4: bnel        $v0, $zero, L_808003C8
    if (ctx->r2 != 0) {
        // 0x808003A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003C8;
    }
    goto skip_5;
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808003AC: jal         0x800DA298
    // 0x808003B0: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x808003B0: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    after_19:
    // 0x808003B4: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003BC:
    // 0x808003BC: jal         0x808012B4
    // 0x808003C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_20;
    // 0x808003C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
L_808003C4:
    // 0x808003C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C8:
    // 0x808003C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void _bskazegghead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083428: syscall     61
    recomp_syscall_handler(rdram, ctx, 0x80083428);
    return;
    // 0x8008342C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80803730_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080373C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803740: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80803744: jal         0x80100094
    // 0x80803748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080374C: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x80803750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803754: ori         $a1, $a1, 0xA300
    ctx->r5 = ctx->r5 | 0XA300;
    // 0x80803758: jal         0x80105998
    // 0x8080375C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x8080375C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803760: beq         $v0, $zero, L_80803784
    if (ctx->r2 == 0) {
        // 0x80803764: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80803784;
    }
    // 0x80803764: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803768: sb          $zero, 0x8F8($v1)
    MEM_B(0X8F8, ctx->r3) = 0;
    // 0x8080376C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80803770: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803778: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080377C: jal         0x80800998
    // 0x80803780: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80803780: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_2:
L_80803784:
    // 0x80803784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080378C: jr          $ra
    // 0x80803790: nop

    return;
    // 0x80803790: nop

;}
RECOMP_FUNC void chtrashcangame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X31B4) << 16);
    // 0x80801CE8: jr          $ra
    // 0x80801CEC: addiu       $v0, $v0, 0x31B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X31B4));
    return;
    // 0x80801CEC: addiu       $v0, $v0, 0x31B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X31B4));
;}
RECOMP_FUNC void func_80800C58_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C60: jal         0x8010C964
    // 0x80800C64: nop

    func_8010C964(rdram, ctx);
        goto after_0;
    // 0x80800C64: nop

    after_0:
    // 0x80800C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C70: jr          $ra
    // 0x80800C74: nop

    return;
    // 0x80800C74: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5F0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5F0);
    return;
    // 0x8008A5F4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80802014_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080201C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802020: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802024: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80802028: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080202C: jal         0x8008FB10
    // 0x80802030: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x80802030: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    after_0:
    // 0x80802034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080203C: jr          $ra
    // 0x80802040: nop

    return;
    // 0x80802040: nop

;}
RECOMP_FUNC void func_8080071C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800724: jal         0x800EA05C
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080072C: slti        $at, $v0, 0xD6
    ctx->r1 = SIGNED(ctx->r2) < 0XD6 ? 1 : 0;
    // 0x80800730: bne         $at, $zero, L_80800774
    if (ctx->r1 != 0) {
        // 0x80800734: slti        $at, $v0, 0xEA
        ctx->r1 = SIGNED(ctx->r2) < 0XEA ? 1 : 0;
            goto L_80800774;
    }
    // 0x80800734: slti        $at, $v0, 0xEA
    ctx->r1 = SIGNED(ctx->r2) < 0XEA ? 1 : 0;
    // 0x80800738: bne         $at, $zero, L_80800760
    if (ctx->r1 != 0) {
        // 0x8080073C: addiu       $t6, $v0, -0x11E
        ctx->r14 = ADD32(ctx->r2, -0X11E);
            goto L_80800760;
    }
    // 0x8080073C: addiu       $t6, $v0, -0x11E
    ctx->r14 = ADD32(ctx->r2, -0X11E);
    // 0x80800740: sltiu       $at, $t6, 0x3A
    ctx->r1 = ctx->r14 < 0X3A ? 1 : 0;
    // 0x80800744: beq         $at, $zero, L_808007D8
    if (ctx->r1 == 0) {
        // 0x80800748: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808007D8;
    }
    // 0x80800748: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080074C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2374) << 16);
    // 0x80800750: addu        $at, $at, $t6
    gpr jr_addend_80800758 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800754: lw          $t6, 0x2374($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2374));
    // 0x80800758: jr          $t6
    // 0x8080075C: nop

    switch (jr_addend_80800758 >> 2) {
        case 0: goto L_808007A8; break;
        case 1: goto L_808007B8; break;
        case 2: goto L_808007B0; break;
        case 3: goto L_808007D8; break;
        case 4: goto L_808007A8; break;
        case 5: goto L_808007D8; break;
        case 6: goto L_808007D8; break;
        case 7: goto L_808007D8; break;
        case 8: goto L_808007D8; break;
        case 9: goto L_808007D8; break;
        case 10: goto L_808007D8; break;
        case 11: goto L_808007D8; break;
        case 12: goto L_808007D8; break;
        case 13: goto L_808007D8; break;
        case 14: goto L_808007D8; break;
        case 15: goto L_808007D8; break;
        case 16: goto L_808007D8; break;
        case 17: goto L_808007D8; break;
        case 18: goto L_808007D8; break;
        case 19: goto L_808007D8; break;
        case 20: goto L_808007D8; break;
        case 21: goto L_808007D8; break;
        case 22: goto L_808007D8; break;
        case 23: goto L_808007C0; break;
        case 24: goto L_808007D8; break;
        case 25: goto L_808007D8; break;
        case 26: goto L_808007D8; break;
        case 27: goto L_808007D8; break;
        case 28: goto L_808007D8; break;
        case 29: goto L_808007D8; break;
        case 30: goto L_808007D8; break;
        case 31: goto L_808007D8; break;
        case 32: goto L_808007D8; break;
        case 33: goto L_808007D8; break;
        case 34: goto L_808007C8; break;
        case 35: goto L_808007D8; break;
        case 36: goto L_808007D8; break;
        case 37: goto L_808007D8; break;
        case 38: goto L_808007D8; break;
        case 39: goto L_808007D8; break;
        case 40: goto L_808007D8; break;
        case 41: goto L_808007D8; break;
        case 42: goto L_808007D8; break;
        case 43: goto L_808007D8; break;
        case 44: goto L_808007D8; break;
        case 45: goto L_808007D8; break;
        case 46: goto L_808007D8; break;
        case 47: goto L_808007D8; break;
        case 48: goto L_808007D8; break;
        case 49: goto L_808007D8; break;
        case 50: goto L_808007D8; break;
        case 51: goto L_808007D8; break;
        case 52: goto L_808007D8; break;
        case 53: goto L_808007D8; break;
        case 54: goto L_808007D8; break;
        case 55: goto L_808007D8; break;
        case 56: goto L_808007D8; break;
        case 57: goto L_808007D0; break;
        default: switch_error(__func__, 0x80800758, 0x80802374);
    }
    // 0x8080075C: nop

L_80800760:
    // 0x80800760: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80800764: beq         $v0, $at, L_808007A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800768: nop
    
            goto L_808007A0;
    }
    // 0x80800768: nop

    // 0x8080076C: b           L_808007DC
    // 0x80800770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007DC;
    // 0x80800770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800774:
    // 0x80800774: addiu       $at, $zero, 0xB6
    ctx->r1 = ADD32(0, 0XB6);
    // 0x80800778: beq         $v0, $at, L_80800790
    if (ctx->r2 == ctx->r1) {
        // 0x8080077C: addiu       $at, $zero, 0xD5
        ctx->r1 = ADD32(0, 0XD5);
            goto L_80800790;
    }
    // 0x8080077C: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x80800780: beq         $v0, $at, L_80800798
    if (ctx->r2 == ctx->r1) {
        // 0x80800784: nop
    
            goto L_80800798;
    }
    // 0x80800784: nop

    // 0x80800788: b           L_808007DC
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007DC;
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800790:
    // 0x80800790: b           L_808007DC
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007DC;
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800798:
    // 0x80800798: b           L_808007DC
    // 0x8080079C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808007DC;
    // 0x8080079C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007A0:
    // 0x808007A0: b           L_808007DC
    // 0x808007A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808007DC;
    // 0x808007A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808007A8:
    // 0x808007A8: b           L_808007DC
    // 0x808007AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_808007DC;
    // 0x808007AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_808007B0:
    // 0x808007B0: b           L_808007DC
    // 0x808007B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808007DC;
    // 0x808007B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808007B8:
    // 0x808007B8: b           L_808007DC
    // 0x808007BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_808007DC;
    // 0x808007BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_808007C0:
    // 0x808007C0: b           L_808007DC
    // 0x808007C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_808007DC;
    // 0x808007C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_808007C8:
    // 0x808007C8: b           L_808007DC
    // 0x808007CC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_808007DC;
    // 0x808007CC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_808007D0:
    // 0x808007D0: b           L_808007DC
    // 0x808007D4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_808007DC;
    // 0x808007D4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_808007D8:
    // 0x808007D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007DC:
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E4: jr          $ra
    // 0x808007E8: nop

    return;
    // 0x808007E8: nop

;}
RECOMP_FUNC void susplinet_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800218: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8080021C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800220: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80800224: nop

    // 0x80800228: bc1f        L_8080024C
    if (!c1cs) {
        // 0x8080022C: nop
    
            goto L_8080024C;
    }
    // 0x8080022C: nop

    // 0x80800230: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80800234: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80800238: nop

    // 0x8080023C: bc1f        L_8080024C
    if (!c1cs) {
        // 0x80800240: nop
    
            goto L_8080024C;
    }
    // 0x80800240: nop

    // 0x80800244: jr          $ra
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void func_80800F10_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F14: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800F18: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800F1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800F20: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800F24: jal         0x800D8FF8
    // 0x80800F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F34: jal         0x80016B30
    // 0x80800F38: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x80800F38: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F40: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800F44: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800F48: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800F4C: nop

    // 0x80800F50: bc1f        L_80800FB4
    if (!c1cs) {
        // 0x80800F54: nop
    
            goto L_80800FB4;
    }
    // 0x80800F54: nop

    // 0x80800F58: beq         $v0, $zero, L_80800F98
    if (ctx->r2 == 0) {
        // 0x80800F5C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800F98;
    }
    // 0x80800F5C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800F60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800F68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F6C: lui         $a2, 0xBC23
    ctx->r6 = S32(0XBC23 << 16);
    // 0x80800F70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800F74: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800F78: jal         0x800F10B4
    // 0x80800F7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800F7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800F80: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80800F84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3708) << 16);
    // 0x80800F88: lwc1        $f6, 0x3708($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3708));
    // 0x80800F8C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80800F90: b           L_80801030
    // 0x80800F94: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_80801030;
    // 0x80800F94: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_80800F98:
    // 0x80800F98: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80800F9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X370C) << 16);
    // 0x80800FA0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80800FA4: lwc1        $f10, 0x370C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X370C));
    // 0x80800FA8: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80800FAC: b           L_80801010
    // 0x80800FB0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
        goto L_80801010;
    // 0x80800FB0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800FB4:
    // 0x80800FB4: bne         $v0, $zero, L_80800FF4
    if (ctx->r2 != 0) {
        // 0x80800FB8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800FF4;
    }
    // 0x80800FB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FC0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800FC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FC8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800FCC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800FD0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800FD4: jal         0x800F10B4
    // 0x80800FD8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800FD8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80800FDC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80800FE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3710) << 16);
    // 0x80800FE4: lwc1        $f18, 0x3710($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3710));
    // 0x80800FE8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80800FEC: b           L_80801030
    // 0x80800FF0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
        goto L_80801030;
    // 0x80800FF0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80800FF4:
    // 0x80800FF4: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80800FF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3714) << 16);
    // 0x80800FFC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80801000: lwc1        $f6, 0x3714($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3714));
    // 0x80801004: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80801008: nop

    // 0x8080100C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80801010:
    // 0x80801010: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801014: nop

    // 0x80801018: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8080101C: nop

    // 0x80801020: bc1fl       L_80801030
    if (!c1cs) {
        // 0x80801024: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_80801030;
    }
    goto skip_0;
    // 0x80801024: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_0:
    // 0x80801028: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080102C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_80801030:
    // 0x80801030: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801034: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801038: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080103C: jr          $ra
    // 0x80801040: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801040: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chbottlesparty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1508, 0X410) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1508, 0X410));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1508, 0X410));
;}
RECOMP_FUNC void boot___osSetSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void bsbtrot_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808017F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808017F8: jal         0x8008CABC
    // 0x808017FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808017FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801800: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801804: jal         0x8008AF24
    // 0x80801808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80801808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080180C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801810: jal         0x8008AED4
    // 0x80801814: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80801814: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_2:
    // 0x80801818: lui         $a1, 0x3D8D
    ctx->r5 = S32(0X3D8D << 16);
    // 0x8080181C: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    // 0x80801820: jal         0x8008B24C
    // 0x80801824: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_3;
    // 0x80801824: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80801828: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080182C: jal         0x8008B134
    // 0x80801830: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80801830: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80801834: jal         0x8008B064
    // 0x80801838: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x80801838: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8080183C: jal         0x80800538
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_6;
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801844: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801848: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080184C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801854: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801858: jal         0x8009FFD8
    // 0x8080185C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x8080185C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80801860: jal         0x8009C990
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x80801864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801868: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080186C: jal         0x8009B9C0
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801874: jal         0x8009C990
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080187C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801880: jal         0x8009BB00
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801888: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801890: jal         0x8009BA68
    // 0x80801894: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80801894: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80801898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080189C: jal         0x800A0CF4
    // 0x808018A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_13;
    // 0x808018A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808018A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018A8: jal         0x800A0CE8
    // 0x808018AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_14;
    // 0x808018AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808018B8: jal         0x8009BFE4
    // 0x808018BC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_15;
    // 0x808018BC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_15:
    // 0x808018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018C4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808018C8: jal         0x8009C554
    // 0x808018CC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_16;
    // 0x808018CC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_16:
    // 0x808018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018D4: jal         0x8009B9B0
    // 0x808018D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x808018D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_17:
    // 0x808018DC: jal         0x8009D658
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_18;
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808018E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808018EC: nop

    // 0x808018F0: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x808018F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808018F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808018FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801900: jr          $ra
    // 0x80801904: nop

    return;
    // 0x80801904: nop

;}
RECOMP_FUNC void func_800B5028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B502C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5030: jal         0x8001ACCC
    // 0x800B5034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800B5034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B5038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B503C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5040: sw          $v0, 0x7F10($at)
    MEM_W(0X7F10, ctx->r1) = ctx->r2;
    // 0x800B5044: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5048: sh          $zero, 0x7F18($at)
    MEM_H(0X7F18, ctx->r1) = 0;
    // 0x800B504C: jr          $ra
    // 0x800B5050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B5050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bstntswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FE0: syscall     100
    recomp_syscall_handler(rdram, ctx, 0x80083FE0);
    return;
    // 0x80083FE4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
