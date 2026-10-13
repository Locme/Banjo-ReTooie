#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800AEC_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800AFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800B04: jal         0x80100094
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800B10: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800B14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B18: bnel        $t6, $at, L_80800B2C
    if (ctx->r14 != ctx->r1) {
        // 0x80800B1C: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_80800B2C;
    }
    goto skip_0;
    // 0x80800B1C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80800B20: b           L_80800BD8
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BD8;
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B28: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_80800B2C:
    // 0x80800B2C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80800B30: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800B34: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800B38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800B3C: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
    // 0x80800B40: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800B44: jal         0x8002D6E0
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x800EE7F8
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC14) << 16);
    // 0x80800B5C: lwc1        $f12, 0xC14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC14));
    // 0x80800B60: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800B64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B68: jal         0x800DC178
    // 0x80800B6C: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800B6C: nop

    after_3:
    // 0x80800B70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B74: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800B78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC18) << 16);
    // 0x80800B7C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80800B80: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800B84: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80800B88: lwc1        $f12, 0xC18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC18));
    // 0x80800B8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC1C) << 16);
    // 0x80800B90: jal         0x800DC178
    // 0x80800B94: lwc1        $f14, 0xC1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC1C));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800B94: lwc1        $f14, 0xC1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC1C));
    after_4:
    // 0x80800B98: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800B9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800BA0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800BA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BA8: jal         0x800DC178
    // 0x80800BAC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800BAC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x80800BB0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800BB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800BB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC20) << 16);
    // 0x80800BBC: jal         0x800DC178
    // 0x80800BC0: lwc1        $f14, 0xC20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC20));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800BC0: lwc1        $f14, 0xC20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC20));
    after_6:
    // 0x80800BC4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800BC8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BD0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800BD4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80800BD8:
    // 0x80800BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BEC: nop

;}
RECOMP_FUNC void bstnt_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EDC: jal         0x8009E77C
    // 0x80800EE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800EE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800EE4: bne         $v0, $zero, L_80800F80
    if (ctx->r2 != 0) {
        // 0x80800EE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F80;
    }
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EEC: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800EF0: sb          $zero, 0x168($s0)
    MEM_B(0X168, ctx->r16) = 0;
    // 0x80800EF4: sb          $zero, 0x16A($s0)
    MEM_B(0X16A, ctx->r16) = 0;
    // 0x80800EF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800EFC: jal         0x80085338
    // 0x80800F00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80800F00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x80800F04: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800F08: ori         $a1, $a1, 0x6600
    ctx->r5 = ctx->r5 | 0X6600;
    // 0x80800F0C: jal         0x80092864
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_2;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800F1C: jal         0x8009BFE4
    // 0x80800F20: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_3;
    // 0x80800F20: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_3:
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F28: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800F2C: jal         0x8009C554
    // 0x80800F30: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_4;
    // 0x80800F30: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_4:
    // 0x80800F34: jal         0x8009EFA8
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_5;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F3C: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800F40: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F48: jal         0x8009F1C8
    // 0x80800F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_6;
    // 0x80800F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F58: jal         0x8009F1C8
    // 0x80800F5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_7;
    // 0x80800F5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F64: lui         $a1, 0x42AA
    ctx->r5 = S32(0X42AA << 16);
    // 0x80800F68: jal         0x800959C8
    // 0x80800F6C: lui         $a2, 0x4218
    ctx->r6 = S32(0X4218 << 16);
    func_800959C8(rdram, ctx);
        goto after_8;
    // 0x80800F6C: lui         $a2, 0x4218
    ctx->r6 = S32(0X4218 << 16);
    after_8:
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F78: jal         0x800947EC
    // 0x80800F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_9;
    // 0x80800F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
L_80800F80:
    // 0x80800F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F8C: jr          $ra
    // 0x80800F90: nop

    return;
    // 0x80800F90: nop

;}
RECOMP_FUNC void func_8008FA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FAA0: jal         0x800F54E4
    // 0x8008FAA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FAA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008FAA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FAAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FAB0: jal         0x800F4D18
    // 0x8008FAB4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4D18(rdram, ctx);
        goto after_1;
    // 0x8008FAB4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008FAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FAC0: jr          $ra
    // 0x8008FAC4: nop

    return;
    // 0x8008FAC4: nop

;}
RECOMP_FUNC void _chcanarymarycage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086960: syscall     400
    recomp_syscall_handler(rdram, ctx, 0x80086960);
    return;
    // 0x80086964: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000B0_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: jal         0x8009EF1C
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808000C4: jal         0x8009EF10
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000CC: bne         $v0, $zero, L_808000E8
    if (ctx->r2 != 0) {
        // 0x808000D0: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808000E8;
    }
    // 0x808000D0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: jal         0x8009B9B0
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808000E0: b           L_80800108
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800108;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F0: jal         0x800F1214
    // 0x808000F4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000F4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_3:
    // 0x808000F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: jal         0x8009B9B0
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80801744_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080174C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801750: jal         0x808015EC
    // 0x80801754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808015EC_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801758: jal         0x808000F0
    // 0x8080175C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x8080175C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801768: jr          $ra
    // 0x8080176C: nop

    return;
    // 0x8080176C: nop

;}
RECOMP_FUNC void func_80801CBC_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801CC8: jal         0x80100094
    // 0x80801CCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801CD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801CD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X448C) << 16);
    // 0x80801CDC: lwc1        $f6, 0x448C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X448C));
    // 0x80801CE0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80801CE4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801CE8: lwc1        $f14, 0x44($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80801CEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801CF0: jal         0x800F1DCC
    // 0x80801CF4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80801CF4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x80801CF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4490) << 16);
    // 0x80801CFC: lwc1        $f16, 0x4490($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4490));
    // 0x80801D00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D04: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801D08: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801D0C: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80801D10: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801D14: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x80801D18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D1C: jal         0x800F1DCC
    // 0x80801D20: lwc1        $f14, 0x93C($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X93C);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80801D20: lwc1        $f14, 0x93C($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X93C);
    after_2:
    // 0x80801D24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4494) << 16);
    // 0x80801D28: lwc1        $f8, 0x4494($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4494));
    // 0x80801D2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D30: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801D34: lwc1        $f6, 0x93C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X93C);
    // 0x80801D38: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80801D3C: swc1        $f10, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f10.u32l;
    // 0x80801D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D48: jr          $ra
    // 0x80801D4C: nop

    return;
    // 0x80801D4C: nop

;}
RECOMP_FUNC void func_800DA130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA138: jal         0x8001210C
    // 0x800DA13C: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x800DA13C: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    after_0:
    // 0x800DA140: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x800DA144: bne         $v0, $at, L_800DA15C
    if (ctx->r2 != ctx->r1) {
        // 0x800DA148: nop
    
            goto L_800DA15C;
    }
    // 0x800DA148: nop

    // 0x800DA14C: jal         0x800888B8
    // 0x800DA150: nop

    _gldbDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800DA150: nop

    after_1:
    // 0x800DA154: b           L_800DA17C
    // 0x800DA158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA17C;
    // 0x800DA158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA15C:
    // 0x800DA15C: jal         0x8001210C
    // 0x800DA160: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x800DA160: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    after_2:
    // 0x800DA164: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800DA168: bnel        $v0, $at, L_800DA17C
    if (ctx->r2 != ctx->r1) {
        // 0x800DA16C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DA17C;
    }
    goto skip_0;
    // 0x800DA16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DA170: jal         0x800888B0
    // 0x800DA174: nop

    _gldbDll_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x800DA174: nop

    after_3:
    // 0x800DA178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA17C:
    // 0x800DA17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA180: jr          $ra
    // 0x800DA184: nop

    return;
    // 0x800DA184: nop

;}
RECOMP_FUNC void _chboilerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086718: syscall     360
    recomp_syscall_handler(rdram, ctx, 0x80086718);
    return;
    // 0x8008671C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808002DC_gcfrontend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2650, 0XC9C) << 16);
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: addiu       $t8, $t8, 0xC9C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2650, 0XC9C));
    // 0x808002E8: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x808002EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x808002F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002F8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808002FC: addiu       $a1, $v0, -0x9FC
    ctx->r5 = ADD32(ctx->r2, -0X9FC);
    // 0x80800300: addiu       $a0, $v0, -0xA00
    ctx->r4 = ADD32(ctx->r2, -0XA00);
    // 0x80800304: jal         0x80800738
    // 0x80800308: lbu         $a2, -0x9F3($v0)
    ctx->r6 = MEM_BU(ctx->r2, -0X9F3);
    func_80800738_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x80800308: lbu         $a2, -0x9F3($v0)
    ctx->r6 = MEM_BU(ctx->r2, -0X9F3);
    after_0:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void func_8008B10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B10C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B118: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8008B11C: jal         0x8008C1C0
    // 0x8008B120: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C1C0(rdram, ctx);
        goto after_0;
    // 0x8008B120: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B12C: jr          $ra
    // 0x8008B130: nop

    return;
    // 0x8008B130: nop

;}
RECOMP_FUNC void func_80800A94_gcmapDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A94: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800A98: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800A9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AA4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800AA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800AB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AB4: addu        $s0, $a0, $t6
    ctx->r16 = ADD32(ctx->r4, ctx->r14);
    // 0x80800AB8: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80800ABC: beql        $a2, $zero, L_80800AD4
    if (ctx->r6 == 0) {
        // 0x80800AC0: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_80800AD4;
    }
    goto skip_0;
    // 0x80800AC0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x80800AC4: jal         0x80087A38
    // 0x80800AC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _dbtex_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800AC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800ACC: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80800AD0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_80800AD4:
    // 0x80800AD4: beql        $a0, $zero, L_80800AE8
    if (ctx->r4 == 0) {
        // 0x80800AD8: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80800AE8;
    }
    goto skip_1;
    // 0x80800AD8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80800ADC: jal         0x800B23E0
    // 0x80800AE0: nop

    func_800B23E0(rdram, ctx);
        goto after_1;
    // 0x80800AE0: nop

    after_1:
    // 0x80800AE4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80800AE8:
    // 0x80800AE8: beql        $a0, $zero, L_80800AFC
    if (ctx->r4 == 0) {
        // 0x80800AEC: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_80800AFC;
    }
    goto skip_2;
    // 0x80800AEC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x80800AF0: jal         0x80088898
    // 0x80800AF4: nop

    _glidmake_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800AF4: nop

    after_2:
    // 0x80800AF8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_80800AFC:
    // 0x80800AFC: beql        $a0, $zero, L_80800B14
    if (ctx->r4 == 0) {
        // 0x80800B00: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_80800B14;
    }
    goto skip_3;
    // 0x80800B00: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x80800B04: jal         0x80089098
    // 0x80800B08: nop

    _rtlight_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800B08: nop

    after_3:
    // 0x80800B0C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80800B10: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_80800B14:
    // 0x80800B14: beql        $a0, $zero, L_80800B2C
    if (ctx->r4 == 0) {
        // 0x80800B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B2C;
    }
    goto skip_4;
    // 0x80800B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800B1C: jal         0x800890B8
    // 0x80800B20: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    _vpmodule_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800B20: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x80800B24: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B2C:
    // 0x80800B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B34: jr          $ra
    // 0x80800B38: nop

    return;
    // 0x80800B38: nop

;}
RECOMP_FUNC void func_808007C4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808007C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808007D0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x808007D4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808007D8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808007DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808007E0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808007E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808007E8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808007EC: jal         0x80100094
    // 0x808007F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007F4: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x808007F8: jal         0x80800758
    // 0x808007FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80800758_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x808007FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800800: lbu         $t6, 0x26($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X26);
    // 0x80800804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080080C: bne         $t6, $at, L_8080081C
    if (ctx->r14 != ctx->r1) {
        // 0x80800810: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8080081C;
    }
    // 0x80800810: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800814: b           L_80800820
    // 0x80800818: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80800820;
    // 0x80800818: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8080081C:
    // 0x8080081C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80800820:
    // 0x80800820: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800824: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800828: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080082C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800830: jal         0x80089E18
    // 0x80800834: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    _suspline_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800834: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800838: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080083C: jal         0x80100094
    // 0x80800840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800844: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800848: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080084C: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
L_80800850:
    // 0x80800850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800854: jal         0x80089DC8
    // 0x80800858: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800858: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8080085C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80800860: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800864: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80800868: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8080086C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80800870: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80800874: bne         $at, $zero, L_80800850
    if (ctx->r1 != 0) {
        // 0x80800878: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_80800850;
    }
    // 0x80800878: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8080087C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800880: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
L_80800884:
    // 0x80800884: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800888: jal         0x80089DD0
    // 0x8080088C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x8080088C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800890: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80800894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800898: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x8080089C: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808008A0: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x808008A4: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x808008A8: bne         $at, $zero, L_80800884
    if (ctx->r1 != 0) {
        // 0x808008AC: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_80800884;
    }
    // 0x808008AC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x808008B0: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x808008B4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x808008B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008BC: beq         $a0, $s1, L_808009A0
    if (ctx->r4 == ctx->r17) {
        // 0x808008C0: lui         $at, 0x432F
        ctx->r1 = S32(0X432F << 16);
            goto L_808009A0;
    }
    // 0x808008C0: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x808008C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808008C8: nop

L_808008CC:
    // 0x808008CC: jal         0x800A5800
    // 0x808008D0: nop

    func_800A5800(rdram, ctx);
        goto after_6;
    // 0x808008D0: nop

    after_6:
    // 0x808008D4: bne         $s0, $zero, L_80800900
    if (ctx->r16 != 0) {
        // 0x808008D8: nop
    
            goto L_80800900;
    }
    // 0x808008D8: nop

    // 0x808008DC: beq         $s3, $zero, L_80800900
    if (ctx->r19 == 0) {
        // 0x808008E0: lw          $a0, 0x64($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X64);
            goto L_80800900;
    }
    // 0x808008E0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808008E4: jal         0x800EE7F8
    // 0x808008E8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808008E8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    after_7:
    // 0x808008EC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808008F0: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x808008F4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x808008F8: b           L_80800908
    // 0x808008FC: swc1        $f6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f6.u32l;
        goto L_80800908;
    // 0x808008FC: swc1        $f6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f6.u32l;
L_80800900:
    // 0x80800900: jal         0x80085580
    // 0x80800904: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800904: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_8:
L_80800908:
    // 0x80800908: jal         0x80085590
    // 0x8080090C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080090C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_9:
    // 0x80800910: jal         0x800855D0
    // 0x80800914: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    _cadbfunc_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x80800914: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x80800918: jal         0x800855E0
    // 0x8080091C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _cadbfunc_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x8080091C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_11:
    // 0x80800920: jal         0x800855F0
    // 0x80800924: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    _cadbfunc_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x80800924: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_12:
    // 0x80800928: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080092C: jal         0x80085668
    // 0x80800930: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_13;
    // 0x80800930: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_13:
    // 0x80800934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080093C: jal         0x80089D78
    // 0x80800940: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    _suspline_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800940: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_14:
    // 0x80800944: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80800948: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8080094C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80800950: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80800954: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80800958: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080095C: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80800960: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80800964: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80800968: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8080096C: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x80800970: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80800974: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80800978: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8080097C: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80800980: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x80800984: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80800988: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080098C: jal         0x80085600
    // 0x80800990: addiu       $a0, $sp, 0x76
    ctx->r4 = ADD32(ctx->r29, 0X76);
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_15;
    // 0x80800990: addiu       $a0, $sp, 0x76
    ctx->r4 = ADD32(ctx->r29, 0X76);
    after_15:
    // 0x80800994: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x80800998: bne         $a0, $s1, L_808008CC
    if (ctx->r4 != ctx->r17) {
        // 0x8080099C: nop
    
            goto L_808008CC;
    }
    // 0x8080099C: nop

L_808009A0:
    // 0x808009A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808009A4: jal         0x80089DC8
    // 0x808009A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suspline_entrypoint_10(rdram, ctx);
        goto after_16;
    // 0x808009A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808009AC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808009B0: jal         0x800F0EF0
    // 0x808009B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800F0EF0(rdram, ctx);
        goto after_17;
    // 0x808009B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x808009B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808009BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808009C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808009C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808009C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808009CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808009D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808009D4: jr          $ra
    // 0x808009D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808009D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _bababykaz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844A8: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844A8);
    return;
    // 0x800844AC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chweather_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859D0: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859D0);
    return;
    // 0x800859D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bamovethrust_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EF8: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084EF8);
    return;
    // 0x80084EFC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _gczoombox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AF0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087AF0);
    return;
    // 0x80087AF4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800070_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: jal         0x80800040
    // 0x8080007C: nop

    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x8080007C: nop

    after_0:
    // 0x80800080: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_8080405C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080405C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80804060: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80804064: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80804068: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8080406C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80804070: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80804074: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80804078: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8080407C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80804080: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80804084: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80804088: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8080408C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80804090: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80804094: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80804098: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080409C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808040A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808040A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808040A8: jal         0x80106790
    // 0x808040AC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808040AC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808040B0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808040B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808040B8: jal         0x80100094
    // 0x808040BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808040BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808040C0: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x808040C4: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x808040C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808040CC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808040D0: blez        $t6, L_808043D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808040D4: addiu       $fp, $sp, 0x90
        ctx->r30 = ADD32(ctx->r29, 0X90);
            goto L_808043D8;
    }
    // 0x808040D4: addiu       $fp, $sp, 0x90
    ctx->r30 = ADD32(ctx->r29, 0X90);
    // 0x808040D8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808040DC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808040E0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808040E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808040E8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808040EC: addiu       $s7, $sp, 0x9C
    ctx->r23 = ADD32(ctx->r29, 0X9C);
    // 0x808040F0: addiu       $s5, $sp, 0xBC
    ctx->r21 = ADD32(ctx->r29, 0XBC);
    // 0x808040F4: lw          $t7, 0x6C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6C);
L_808040F8:
    // 0x808040F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808040FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80804100: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80804104: beql        $s2, $t8, L_808043C4
    if (ctx->r18 == ctx->r24) {
        // 0x80804108: lw          $t3, 0xC8($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC8);
            goto L_808043C4;
    }
    goto skip_0;
    // 0x80804108: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    skip_0:
    // 0x8080410C: jal         0x80089AD0
    // 0x80804110: addiu       $s3, $s1, 0x4
    ctx->r19 = ADD32(ctx->r17, 0X4);
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80804110: addiu       $s3, $s1, 0x4
    ctx->r19 = ADD32(ctx->r17, 0X4);
    after_2:
    // 0x80804114: beq         $v0, $zero, L_80804150
    if (ctx->r2 == 0) {
        // 0x80804118: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804150;
    }
    // 0x80804118: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080411C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80804120: jal         0x80089AD8
    // 0x80804124: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80804124: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80804128: jal         0x80106790
    // 0x8080412C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x8080412C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80804130: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80804134: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80804138: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8080413C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80804140: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x80804144: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80804148: b           L_80804158
    // 0x8080414C: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
        goto L_80804158;
    // 0x8080414C: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
L_80804150:
    // 0x80804150: jal         0x800F5A00
    // 0x80804154: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80804154: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
L_80804158:
    // 0x80804158: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080415C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80804160: jal         0x800EFFB4
    // 0x80804164: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_6;
    // 0x80804164: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x80804168: beql        $v0, $zero, L_808043C4
    if (ctx->r2 == 0) {
        // 0x8080416C: lw          $t3, 0xC8($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC8);
            goto L_808043C4;
    }
    goto skip_1;
    // 0x8080416C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    skip_1:
    // 0x80804170: jal         0x800EEF94
    // 0x80804174: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_7;
    // 0x80804174: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    after_7:
    // 0x80804178: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8080417C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80804180: jal         0x80089AC8
    // 0x80804184: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80804184: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80804188: beq         $v0, $zero, L_808041B4
    if (ctx->r2 == 0) {
        // 0x8080418C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808041B4;
    }
    // 0x8080418C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804190: jal         0x800F5D70
    // 0x80804194: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    func_800F5D70(rdram, ctx);
        goto after_9;
    // 0x80804194: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_9:
    // 0x80804198: jal         0x800EEF94
    // 0x8080419C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800EEF94(rdram, ctx);
        goto after_10;
    // 0x8080419C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_10:
    // 0x808041A0: jal         0x800D8FF8
    // 0x808041A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_11;
    // 0x808041A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_11:
    // 0x808041A8: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808041AC: b           L_808041CC
    // 0x808041B0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
        goto L_808041CC;
    // 0x808041B0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_808041B4:
    // 0x808041B4: jal         0x800EEF94
    // 0x808041B8: addiu       $a0, $s4, 0x28
    ctx->r4 = ADD32(ctx->r20, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_12;
    // 0x808041B8: addiu       $a0, $s4, 0x28
    ctx->r4 = ADD32(ctx->r20, 0X28);
    after_12:
    // 0x808041BC: jal         0x800D8FF8
    // 0x808041C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x808041C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_13:
    // 0x808041C4: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808041C8: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_808041CC:
    // 0x808041CC: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x808041D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808041D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808041D8: bc1fl       L_80804300
    if (!c1cs) {
        // 0x808041DC: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_80804300;
    }
    goto skip_2;
    // 0x808041DC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_2:
    // 0x808041E0: jal         0x80089AC8
    // 0x808041E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808041E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_14:
    // 0x808041E8: beq         $v0, $zero, L_80804288
    if (ctx->r2 == 0) {
        // 0x808041EC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80804288;
    }
    // 0x808041EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808041F0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x808041F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808041F8: jal         0x80089B00
    // 0x808041FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x808041FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_15:
    // 0x80804200: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804204: jal         0x800F8294
    // 0x80804208: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F8294(rdram, ctx);
        goto after_16;
    // 0x80804208: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_16:
    // 0x8080420C: lhu         $t9, 0x72($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X72);
    // 0x80804210: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80804214: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1840, 0X50B4) << 16);
    // 0x80804218: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080421C: bne         $t0, $at, L_808043C0
    if (ctx->r8 != ctx->r1) {
        // 0x80804220: addiu       $t1, $t1, 0x50B4
        ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1840, 0X50B4));
            goto L_808043C0;
    }
    // 0x80804220: addiu       $t1, $t1, 0x50B4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1840, 0X50B4));
    // 0x80804224: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80804228: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080422C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80804230: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x80804234: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80804238: sw          $t3, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r11;
    // 0x8080423C: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80804240: jal         0x800F5A00
    // 0x80804244: sw          $at, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r1;
    func_800F5A00(rdram, ctx);
        goto after_17;
    // 0x80804244: sw          $at, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r1;
    after_17:
    // 0x80804248: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080424C: jal         0x80102D78
    // 0x80804250: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_80102D78(rdram, ctx);
        goto after_18;
    // 0x80804250: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_18:
    // 0x80804254: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80804258: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080425C: jal         0x800EEB9C
    // 0x80804260: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_19;
    // 0x80804260: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_19:
    // 0x80804264: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80804268: jal         0x800EF04C
    // 0x8080426C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x8080426C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_20:
    // 0x80804270: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80804278: jal         0x800F7700
    // 0x8080427C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F7700(rdram, ctx);
        goto after_21;
    // 0x8080427C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x80804280: b           L_808043C4
    // 0x80804284: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
        goto L_808043C4;
    // 0x80804284: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
L_80804288:
    // 0x80804288: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x8080428C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80804290: jal         0x80089B00
    // 0x80804294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_22;
    // 0x80804294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x80804298: lhu         $t4, 0x72($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X72);
    // 0x8080429C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808042A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808042A4: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808042A8: bnel        $t5, $at, L_808043C4
    if (ctx->r13 != ctx->r1) {
        // 0x808042AC: lw          $t3, 0xC8($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC8);
            goto L_808043C4;
    }
    goto skip_3;
    // 0x808042AC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    skip_3:
    // 0x808042B0: lbu         $t7, 0x65($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X65);
    // 0x808042B4: swc1        $f28, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f28.u32l;
    // 0x808042B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808042BC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808042C0: jal         0x8080324C
    // 0x808042C4: sb          $t8, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r24;
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_23;
    // 0x808042C4: sb          $t8, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r24;
    after_23:
    // 0x808042C8: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x808042CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808042D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808042D4: mul.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x808042D8: jal         0x80102D78
    // 0x808042DC: swc1        $f16, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f16.u32l;
    func_80102D78(rdram, ctx);
        goto after_24;
    // 0x808042DC: swc1        $f16, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f16.u32l;
    after_24:
    // 0x808042E0: swc1        $f0, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f0.u32l;
    // 0x808042E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808042E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808042EC: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x808042F0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808042F4: b           L_808043C0
    // 0x808042F8: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
        goto L_808043C0;
    // 0x808042F8: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x808042FC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_80804300:
    // 0x80804300: jal         0x80089B00
    // 0x80804304: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x80804304: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_25:
    // 0x80804308: jal         0x800DC0C0
    // 0x8080430C: nop

    func_800DC0C0(rdram, ctx);
        goto after_26;
    // 0x8080430C: nop

    after_26:
    // 0x80804310: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804318: nop

    // 0x8080431C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80804320: nop

    // 0x80804324: bc1fl       L_80804354
    if (!c1cs) {
        // 0x80804328: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80804354;
    }
    goto skip_4;
    // 0x80804328: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_4:
    // 0x8080432C: lw          $a1, 0x6C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X6C);
    // 0x80804330: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80804334: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x80804338: jal         0x80089AF8
    // 0x8080433C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_27;
    // 0x8080433C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_27:
    // 0x80804340: bne         $v0, $zero, L_80804350
    if (ctx->r2 != 0) {
        // 0x80804344: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80804350;
    }
    // 0x80804344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804348: jal         0x808032CC
    // 0x8080434C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_808032CC_chcollballcontrol(rdram, ctx);
        goto after_28;
    // 0x8080434C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_28:
L_80804350:
    // 0x80804350: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80804354:
    // 0x80804354: jal         0x80089AC8
    // 0x80804358: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x80804358: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x8080435C: beq         $v0, $zero, L_808043B0
    if (ctx->r2 == 0) {
        // 0x80804360: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808043B0;
    }
    // 0x80804360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804364: jal         0x800F52B8
    // 0x80804368: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_30;
    // 0x80804368: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_30:
    // 0x8080436C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804370: bne         $v0, $at, L_808043B0
    if (ctx->r2 != ctx->r1) {
        // 0x80804374: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808043B0;
    }
    // 0x80804374: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804378: jal         0x800F5A00
    // 0x8080437C: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800F5A00(rdram, ctx);
        goto after_31;
    // 0x8080437C: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_31:
    // 0x80804380: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80804384: jal         0x800F1DF4
    // 0x80804388: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_32;
    // 0x80804388: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x8080438C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80804390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804394: jal         0x8080324C
    // 0x80804398: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_33;
    // 0x80804398: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_33:
    // 0x8080439C: jal         0x800D8FF8
    // 0x808043A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x808043A0: nop

    after_34:
    // 0x808043A4: mul.s       $f10, $f24, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f30.fl);
    // 0x808043A8: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808043AC: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_808043B0:
    // 0x808043B0: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
    // 0x808043B4: swc1        $f28, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f28.u32l;
    // 0x808043B8: ori         $t1, $t2, 0x10
    ctx->r9 = ctx->r10 | 0X10;
    // 0x808043BC: sb          $t1, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r9;
L_808043C0:
    // 0x808043C0: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
L_808043C4:
    // 0x808043C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808043C8: lbu         $t4, 0x3A($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X3A);
    // 0x808043CC: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808043D0: bnel        $at, $zero, L_808040F8
    if (ctx->r1 != 0) {
        // 0x808043D4: lw          $t7, 0x6C($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X6C);
            goto L_808040F8;
    }
    goto skip_5;
    // 0x808043D4: lw          $t7, 0x6C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6C);
    skip_5:
L_808043D8:
    // 0x808043D8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808043DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808043E0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808043E4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808043E8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808043EC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808043F0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808043F4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808043F8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808043FC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80804400: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80804404: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80804408: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8080440C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80804410: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80804414: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80804418: jr          $ra
    // 0x8080441C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8080441C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_800D37C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D37C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D37C4: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
    // 0x800D37C8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800D37CC: jr          $ra
    // 0x800D37D0: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    return;
    // 0x800D37D0: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80800440_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800444: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080044C: addiu       $t6, $zero, 0x60
    ctx->r14 = ADD32(0, 0X60);
    // 0x80800450: addiu       $t7, $zero, 0x59C
    ctx->r15 = ADD32(0, 0X59C);
    // 0x80800454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800458: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080045C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800460: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800464: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800468: jal         0x80086898
    // 0x8080046C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080046C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x80800470: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x80800474: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B0;
    }
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: jal         0x800868B0
    // 0x8080047C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080047C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_1:
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x800868C0
    // 0x80800488: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800488: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800494: jal         0x800868E0
    // 0x80800498: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800498: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004A4: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x808004A8: jal         0x800868C8
    // 0x808004AC: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808004AC: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    after_4:
L_808004B0:
    // 0x808004B0: jal         0x800DA298
    // 0x808004B4: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808004B4: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_5:
    // 0x808004B8: beql        $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004BC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004DC;
    }
    goto skip_0;
    // 0x808004BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808004C0: jal         0x80088840
    // 0x808004C4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808004C4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_6:
    // 0x808004C8: bnel        $v0, $zero, L_808004DC
    if (ctx->r2 != 0) {
        // 0x808004CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004DC;
    }
    goto skip_1;
    // 0x808004CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808004D0: jal         0x800FFAB0
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004DC:
    // 0x808004DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

    // 0x808004EC: nop

;}
RECOMP_FUNC void func_80105390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105390: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80105394: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80105398: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8010539C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801053A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801053A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801053A8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801053AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801053B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801053B4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801053B8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801053BC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x801053C0: nop

    // 0x801053C4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x801053C8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x801053CC: jr          $ra
    // 0x801053D0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x801053D0: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80800000_anseq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800010: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x80800014: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800018: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8080001C: beql        $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800020: lbu         $t9, 0x4($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X4);
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800020: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
    skip_0:
    // 0x80800024: beq         $v0, $at, L_808000F8
    if (ctx->r2 == ctx->r1) {
        // 0x80800028: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_808000F8;
    }
    // 0x80800028: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8080002C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80800030: bne         $t7, $zero, L_808000F8
    if (ctx->r15 != 0) {
        // 0x80800034: sb          $t6, 0x6($a1)
        MEM_B(0X6, ctx->r5) = ctx->r14;
            goto L_808000F8;
    }
    // 0x80800034: sb          $t6, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r14;
    // 0x80800038: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8080003C: sb          $t8, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r24;
    // 0x80800040: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
L_80800044:
    // 0x80800044: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80800048: beq         $at, $zero, L_808000F8
    if (ctx->r1 == 0) {
        // 0x8080004C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808000F8;
    }
    // 0x8080004C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800050: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(26, 0X470) << 16);
    // 0x80800054: addu        $at, $at, $t9
    gpr jr_addend_8080005C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800058: lw          $t9, 0x470($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(26, 0X470));
    // 0x8080005C: jr          $t9
    // 0x80800060: nop

    switch (jr_addend_8080005C >> 2) {
        case 0: goto L_80800064; break;
        case 1: goto L_80800078; break;
        case 2: goto L_80800090; break;
        case 3: goto L_808000AC; break;
        case 4: goto L_808000C8; break;
        case 5: goto L_808000E8; break;
        default: switch_error(__func__, 0x8080005C, 0x80800470);
    }
    // 0x80800060: nop

L_80800064:
    // 0x80800064: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x80800068: jalr        $t9
    // 0x8080006C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8080006C: nop

    after_0:
    // 0x80800070: b           L_808000FC
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x8080007C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80800080: jalr        $t9
    // 0x80800084: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800084: nop

    after_1:
    // 0x80800088: b           L_808000FC
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800090:
    // 0x80800090: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x80800094: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80800098: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8080009C: jalr        $t9
    // 0x808000A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x808000A0: nop

    after_2:
    // 0x808000A4: b           L_808000FC
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x808000B0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x808000B4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x808000B8: jalr        $t9
    // 0x808000BC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x808000BC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    after_3:
    // 0x808000C0: b           L_808000FC
    // 0x808000C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x808000C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C8:
    // 0x808000C8: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x808000CC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x808000D0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x808000D4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x808000D8: jalr        $t9
    // 0x808000DC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x808000DC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x808000E0: b           L_808000FC
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000FC;
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E8:
    // 0x808000E8: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x808000EC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x808000F0: jalr        $t9
    // 0x808000F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x808000F4: nop

    after_5:
L_808000F8:
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_8080407C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080407C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804088: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080408C: jal         0x80087D20
    // 0x80804090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80804090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80804094: bne         $v0, $zero, L_808040CC
    if (ctx->r2 != 0) {
        // 0x80804098: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808040CC;
    }
    // 0x80804098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080409C: jal         0x80087D40
    // 0x808040A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x808040A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808040A4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X83D0) << 16);
    // 0x808040A8: addiu       $a2, $a2, -0x7C30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X83D0));
    // 0x808040AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808040B0: jal         0x80087D00
    // 0x808040B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808040B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808040B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808040BC: beql        $t6, $zero, L_808040D0
    if (ctx->r14 == 0) {
        // 0x808040C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808040D0;
    }
    goto skip_0;
    // 0x808040C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808040C4: jal         0x80803CC0
    // 0x808040C8: nop

    func_80803CC0_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808040C8: nop

    after_3:
L_808040CC:
    // 0x808040CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808040D0:
    // 0x808040D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808040D4: jr          $ra
    // 0x808040D8: nop

    return;
    // 0x808040D8: nop

;}
RECOMP_FUNC void func_808007CC_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007CC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x808007D0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x808007D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007D8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x808007E0: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x808007E4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x808007E8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x808007EC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x808007F0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x808007F4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x808007F8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808007FC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800800: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800804: jal         0x800B5BE4
    // 0x80800808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800808: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x8080080C: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x80800810: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800814: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800818: jal         0x8009C128
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800820: lw          $t6, 0x110($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X110);
    // 0x80800824: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80800828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080082C: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80800830: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800834: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X1004) << 16);
    // 0x80800838: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080083C: lwc1        $f18, 0x1004($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1004));
    // 0x80800840: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X1008) << 16);
    // 0x80800844: lwc1        $f6, 0x1008($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1008));
    // 0x80800848: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080084C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800850: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80800854: lw          $t7, 0x110($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X110);
    // 0x80800858: lwc1        $f16, 0x1C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8080085C: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x80800860: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800864: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800868: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080086C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800870: jal         0x800BA7C4
    // 0x80800874: nop

    func_800BA7C4(rdram, ctx);
        goto after_2;
    // 0x80800874: nop

    after_2:
    // 0x80800878: jal         0x8009C984
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800880: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800884: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800890: jal         0x800A1718
    // 0x80800894: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    func_800A1718(rdram, ctx);
        goto after_4;
    // 0x80800894: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800898: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8080089C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808008A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808008A4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(604, 0X10F0) << 16);
    // 0x808008A8: cvt.s.w     $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    ctx->f24.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808008AC: addiu       $s2, $s2, 0x10F0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(604, 0X10F0));
    // 0x808008B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008B8: c.lt.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
    // 0x808008BC: nop

    // 0x808008C0: bc1fl       L_80800968
    if (!c1cs) {
        // 0x808008C4: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80800968;
    }
    goto skip_0;
    // 0x808008C4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x808008C8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808008CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808008D0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808008D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808008D8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808008DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808008E0: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x808008E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808008E8:
    // 0x808008E8: jal         0x800EE7F8
    // 0x808008EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808008EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x808008F0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808008F4: jal         0x800DC178
    // 0x808008F8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808008F8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_6:
    // 0x808008FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800900: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800904: jal         0x800DC178
    // 0x80800908: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800908: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_7:
    // 0x8080090C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80800910: jal         0x800136E4
    // 0x80800914: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_8;
    // 0x80800914: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_8:
    // 0x80800918: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080091C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800924: jal         0x800EF214
    // 0x80800928: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    func_800EF214(rdram, ctx);
        goto after_9;
    // 0x80800928: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    after_9:
    // 0x8080092C: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80800930: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800934: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080093C: jal         0x800BABB8
    // 0x80800940: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80800940: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_10:
    // 0x80800944: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800948: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8080094C: nop

    // 0x80800950: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800954: c.lt.s      $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f8.fl < ctx->f24.fl;
    // 0x80800958: nop

    // 0x8080095C: bc1tl       L_808008E8
    if (c1cs) {
        // 0x80800960: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808008E8;
    }
    goto skip_1;
    // 0x80800960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80800964: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80800968:
    // 0x80800968: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080096C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800970: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800974: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800978: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8080097C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800980: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800984: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80800988: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8080098C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800990: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800994: jr          $ra
    // 0x80800998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void cadbfunc_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: jal         0x808006A8
    // 0x80800768: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_808006A8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800768: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8080076C: bne         $v0, $zero, L_8080077C
    if (ctx->r2 != 0) {
        // 0x80800770: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080077C;
    }
    // 0x80800770: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800774: b           L_80800788
    // 0x80800778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800788;
    // 0x80800778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080077C:
    // 0x8080077C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800784: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80800788:
    // 0x80800788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080078C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800790: jr          $ra
    // 0x80800794: nop

    return;
    // 0x80800794: nop

;}
RECOMP_FUNC void badialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080006C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800070: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800074: jr          $ra
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_808019D0_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808019D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808019D8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808019DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808019E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808019E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808019E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808019EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808019F0: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x808019F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808019F8: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x808019FC: bltzl       $t8, L_80801AEC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801A00: lw          $a0, 0x20($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X20);
            goto L_80801AEC;
    }
    goto skip_0;
    // 0x80801A00: lw          $a0, 0x20($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X20);
    skip_0:
    // 0x80801A04: jal         0x80800038
    // 0x80801A08: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80801A08: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
    after_0:
    // 0x80801A0C: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x80801A10: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80801A14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801A18: blez        $t9, L_80801AE0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80801A1C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801AE0;
    }
    // 0x80801A1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80801A20:
    // 0x80801A20: jal         0x80800000
    // 0x80801A24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80801A24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80801A28: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801A2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801A30: jal         0x80800070
    // 0x80801A34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800070_gcnewoption(rdram, ctx);
        goto after_2;
    // 0x80801A34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80801A38: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801A40: jal         0x808027DC
    // 0x80801A44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808027DC_gcnewoption(rdram, ctx);
        goto after_3;
    // 0x80801A44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80801A48: lw          $t0, 0x1C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C);
    // 0x80801A4C: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x80801A50: addu        $s0, $s3, $t4
    ctx->r16 = ADD32(ctx->r19, ctx->r12);
    // 0x80801A54: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80801A58: bgez        $t2, L_80801A88
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801A5C: addu        $t5, $s3, $s4
        ctx->r13 = ADD32(ctx->r19, ctx->r20);
            goto L_80801A88;
    }
    // 0x80801A5C: addu        $t5, $s3, $s4
    ctx->r13 = ADD32(ctx->r19, ctx->r20);
    // 0x80801A60: bne         $s5, $s1, L_80801A70
    if (ctx->r21 != ctx->r17) {
        // 0x80801A64: sll         $t3, $s2, 2
        ctx->r11 = S32(ctx->r18 << 2);
            goto L_80801A70;
    }
    // 0x80801A64: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x80801A68: b           L_80801A74
    // 0x80801A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801A74;
    // 0x80801A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801A70:
    // 0x80801A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801A74:
    // 0x80801A74: addu        $s0, $s3, $t3
    ctx->r16 = ADD32(ctx->r19, ctx->r11);
    // 0x80801A78: jal         0x80087C20
    // 0x80801A7C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_40(rdram, ctx);
        goto after_4;
    // 0x80801A7C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x80801A80: b           L_80801A94
    // 0x80801A84: nop

        goto L_80801A94;
    // 0x80801A84: nop

L_80801A88:
    // 0x80801A88: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801A8C: jal         0x80087C20
    // 0x80801A90: lbu         $a1, 0x218($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X218);
    _gczoombox_entrypoint_40(rdram, ctx);
        goto after_5;
    // 0x80801A90: lbu         $a1, 0x218($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X218);
    after_5:
L_80801A94:
    // 0x80801A94: bnel        $s5, $s1, L_80801AB8
    if (ctx->r21 != ctx->r17) {
        // 0x80801A98: xor         $a1, $s5, $s1
        ctx->r5 = ctx->r21 ^ ctx->r17;
            goto L_80801AB8;
    }
    goto skip_1;
    // 0x80801A98: xor         $a1, $s5, $s1
    ctx->r5 = ctx->r21 ^ ctx->r17;
    skip_1:
    // 0x80801A9C: jal         0x80087B90
    // 0x80801AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_22(rdram, ctx);
        goto after_6;
    // 0x80801AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80801AA4: bne         $v0, $zero, L_80801AB4
    if (ctx->r2 != 0) {
        // 0x80801AA8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801AB4;
    }
    // 0x80801AA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801AAC: jal         0x808010E0
    // 0x80801AB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_808010E0_gcnewoption(rdram, ctx);
        goto after_7;
    // 0x80801AB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_7:
L_80801AB4:
    // 0x80801AB4: xor         $a1, $s5, $s1
    ctx->r5 = ctx->r21 ^ ctx->r17;
L_80801AB8:
    // 0x80801AB8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80801ABC: jal         0x80087B88
    // 0x80801AC0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x80801AC0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_8:
    // 0x80801AC4: jal         0x80087B00
    // 0x80801AC8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80801AC8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_9:
    // 0x80801ACC: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x80801AD0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801AD4: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80801AD8: bnel        $at, $zero, L_80801A20
    if (ctx->r1 != 0) {
        // 0x80801ADC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801A20;
    }
    goto skip_2;
    // 0x80801ADC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_80801AE0:
    // 0x80801AE0: jal         0x80801B5C
    // 0x80801AE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80801B5C_gcnewoption(rdram, ctx);
        goto after_10;
    // 0x80801AE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80801AE8: lw          $a0, 0x20($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X20);
L_80801AEC:
    // 0x80801AEC: beq         $a0, $zero, L_80801B2C
    if (ctx->r4 == 0) {
        // 0x80801AF0: nop
    
            goto L_80801B2C;
    }
    // 0x80801AF0: nop

    // 0x80801AF4: jal         0x80087AF8
    // 0x80801AF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80801AF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_11:
    // 0x80801AFC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801B00: jal         0x80087B00
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801B08: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80801B0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801B10: beq         $v0, $at, L_80801B28
    if (ctx->r2 == ctx->r1) {
        // 0x80801B14: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801B28;
    }
    // 0x80801B14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801B18: beq         $v0, $at, L_80801B28
    if (ctx->r2 == ctx->r1) {
        // 0x80801B1C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80801B28;
    }
    // 0x80801B1C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801B20: bne         $v0, $at, L_80801B2C
    if (ctx->r2 != ctx->r1) {
        // 0x80801B24: nop
    
            goto L_80801B2C;
    }
    // 0x80801B24: nop

L_80801B28:
    // 0x80801B28: sb          $s1, 0x24($s3)
    MEM_B(0X24, ctx->r19) = ctx->r17;
L_80801B2C:
    // 0x80801B2C: jal         0x80088730
    // 0x80801B30: nop

    _gldialog_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80801B30: nop

    after_13:
    // 0x80801B34: sh          $v0, 0xC($s3)
    MEM_H(0XC, ctx->r19) = ctx->r2;
    // 0x80801B38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801B3C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801B40: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801B44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801B48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801B50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801B54: jr          $ra
    // 0x80801B58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801B58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _gcfrontend_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088158: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088158);
    return;
    // 0x8008815C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bapackctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808006C4_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808006D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808006DC: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x808006E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x808006E8: beq         $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x808006EC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800714;
    }
    // 0x808006EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006F4: beq         $v0, $at, L_8080071C
    if (ctx->r2 == ctx->r1) {
        // 0x808006F8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8080071C;
    }
    // 0x808006F8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x808006FC: beq         $v0, $v1, L_80800730
    if (ctx->r2 == ctx->r3) {
        // 0x80800700: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800730;
    }
    // 0x80800700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800704: beql        $v0, $at, L_8080072C
    if (ctx->r2 == ctx->r1) {
        // 0x80800708: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8080072C;
    }
    goto skip_0;
    // 0x80800708: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8080070C: b           L_80800744
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800744;
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800714:
    // 0x80800714: jal         0x800856B0
    // 0x80800718: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800718: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
L_8080071C:
    // 0x8080071C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800724: sw          $v1, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r3;
    // 0x80800728: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8080072C:
    // 0x8080072C: sw          $v1, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r3;
L_80800730:
    // 0x80800730: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800734: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800738: jal         0x800856D0
    // 0x8080073C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080073C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800744:
    // 0x80800744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800748: jr          $ra
    // 0x8080074C: nop

    return;
    // 0x8080074C: nop

;}
RECOMP_FUNC void gldialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80111AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111AE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80111AE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111AE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80111AEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80111AF0: jal         0x80110898
    // 0x80111AF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80110898(rdram, ctx);
        goto after_0;
    // 0x80111AF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80111AF8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80111AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B00: jal         0x801107F0
    // 0x80111B04: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80111B04: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80111B08: jal         0x8010FFD0
    // 0x80111B0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010FFD0(rdram, ctx);
        goto after_2;
    // 0x80111B0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80111B10: beq         $v0, $zero, L_80111B48
    if (ctx->r2 == 0) {
        // 0x80111B14: nop
    
            goto L_80111B48;
    }
    // 0x80111B14: nop

    // 0x80111B18: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80111B1C: jal         0x800EFD24
    // 0x80111B20: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80111B20: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_3:
    // 0x80111B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B28: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80111B2C: jal         0x80113640
    // 0x80111B30: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_80113640(rdram, ctx);
        goto after_4;
    // 0x80111B30: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80111B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B38: jal         0x80110770
    // 0x80111B3C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80110770(rdram, ctx);
        goto after_5;
    // 0x80111B3C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80111B40: b           L_80111B7C
    // 0x80111B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80111B7C;
    // 0x80111B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111B48:
    // 0x80111B48: jal         0x80111A98
    // 0x80111B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111A98(rdram, ctx);
        goto after_6;
    // 0x80111B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80111B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B54: jal         0x80111ABC
    // 0x80111B58: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80111ABC(rdram, ctx);
        goto after_7;
    // 0x80111B58: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80111B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B60: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80111B64: jal         0x80111A38
    // 0x80111B68: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80111A38(rdram, ctx);
        goto after_8;
    // 0x80111B68: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80111B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111B70: jal         0x80110770
    // 0x80111B74: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80110770(rdram, ctx);
        goto after_9;
    // 0x80111B74: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x80111B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111B7C:
    // 0x80111B7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80111B80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80111B84: jr          $ra
    // 0x80111B88: nop

    return;
    // 0x80111B88: nop

;}
RECOMP_FUNC void func_80800238_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080023C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800244: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800248: jal         0x8010C9B0
    // 0x8080024C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010C9B0(rdram, ctx);
        goto after_0;
    // 0x8080024C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_0:
    // 0x80800250: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800254: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800274;
    }
    // 0x80800254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: jal         0x80102424
    // 0x8080025C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080025C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800260: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80800268: lbu         $t8, 0x2A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A);
    // 0x8080026C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80800270: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
L_80800274:
    // 0x80800274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
RECOMP_FUNC void func_8008B518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B51C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008B524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B528: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008B52C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008B530: jal         0x8008C124
    // 0x8008B534: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C124(rdram, ctx);
        goto after_0;
    // 0x8008B534: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B538: lbu         $t7, 0x1B($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1B);
    // 0x8008B53C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008B540: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8008B544: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8008B548: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8008B54C: sb          $t8, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r24;
    // 0x8008B550: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008B554: jal         0x800E6A00
    // 0x8008B558: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    func_800E6A00(rdram, ctx);
        goto after_1;
    // 0x8008B558: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x8008B55C: beq         $v0, $zero, L_8008B578
    if (ctx->r2 == 0) {
        // 0x8008B560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008B578;
    }
    // 0x8008B560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B564: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
    // 0x8008B568: andi        $t0, $t9, 0xFFE7
    ctx->r8 = ctx->r25 & 0XFFE7;
    // 0x8008B56C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8008B570: b           L_8008B584
    // 0x8008B574: sb          $t1, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r9;
        goto L_8008B584;
    // 0x8008B574: sb          $t1, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r9;
L_8008B578:
    // 0x8008B578: lbu         $t2, 0x1B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1B);
    // 0x8008B57C: andi        $t3, $t2, 0xFFE7
    ctx->r11 = ctx->r10 & 0XFFE7;
    // 0x8008B580: sb          $t3, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r11;
L_8008B584:
    // 0x8008B584: lbu         $t5, 0x1B($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1B);
    // 0x8008B588: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008B58C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8008B590: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x8008B594: jal         0x8008B1D4
    // 0x8008B598: sb          $t6, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r14;
    anctrl_setSubrange(rdram, ctx);
        goto after_2;
    // 0x8008B598: sb          $t6, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r14;
    after_2:
    // 0x8008B59C: lui         $a1, 0x4007
    ctx->r5 = S32(0X4007 << 16);
    // 0x8008B5A0: ori         $a1, $a1, 0xE5C9
    ctx->r5 = ctx->r5 | 0XE5C9;
    // 0x8008B5A4: jal         0x8008B1BC
    // 0x8008B5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8008B5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008B5AC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8008B5B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8008B5B4: jal         0x8008B1C8
    // 0x8008B5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x8008B5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008B5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B5C0: jal         0x8008B1A0
    // 0x8008B5C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_5;
    // 0x8008B5C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8008B5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B5CC: jal         0x8008B188
    // 0x8008B5D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_6;
    // 0x8008B5D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8008B5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B5D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B5DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B5E0: jr          $ra
    // 0x8008B5E4: nop

    return;
    // 0x8008B5E4: nop

;}
RECOMP_FUNC void func_800A8710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A8718: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A871C: addiu       $s1, $s1, 0x7688
    ctx->r17 = ADD32(ctx->r17, 0X7688);
    // 0x800A8720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8724: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8728: jal         0x800CA364
    // 0x800A872C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_800CA364(rdram, ctx);
        goto after_0;
    // 0x800A872C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_0:
    // 0x800A8730: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x800A8734: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8738: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A873C: addiu       $s0, $s0, 0x7688
    ctx->r16 = ADD32(ctx->r16, 0X7688);
    // 0x800A8740: addiu       $s1, $s1, 0x76C4
    ctx->r17 = ADD32(ctx->r17, 0X76C4);
    // 0x800A8744: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800A8748:
    // 0x800A8748: beql        $a0, $zero, L_800A8760
    if (ctx->r4 == 0) {
        // 0x800A874C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800A8760;
    }
    goto skip_0;
    // 0x800A874C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800A8750: jal         0x800158E4
    // 0x800A8754: nop

    func_800158E4(rdram, ctx);
        goto after_1;
    // 0x800A8754: nop

    after_1:
    // 0x800A8758: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800A875C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800A8760:
    // 0x800A8760: bnel        $s0, $s1, L_800A8748
    if (ctx->r16 != ctx->r17) {
        // 0x800A8764: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800A8748;
    }
    goto skip_1;
    // 0x800A8764: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800A8768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A876C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A8770: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A8774: jr          $ra
    // 0x800A8778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A8778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_801101C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801101C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801101C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801101C8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801101CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801101D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801101D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801101D8: addiu       $s2, $s2, 0x7372
    ctx->r18 = ADD32(ctx->r18, 0X7372);
    // 0x801101DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801101E0: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x801101E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801101E8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x801101EC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801101F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801101F4: sh          $t6, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r14;
    // 0x801101F8: addiu       $s4, $s4, 0x7372
    ctx->r20 = ADD32(ctx->r20, 0X7372);
    // 0x801101FC: addiu       $s1, $s1, 0x4950
    ctx->r17 = ADD32(ctx->r17, 0X4950);
    // 0x80110200: addiu       $s0, $s0, 0x7340
    ctx->r16 = ADD32(ctx->r16, 0X7340);
    // 0x80110204: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80110208:
    // 0x80110208: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8011020C: jalr        $t9
    // 0x80110210: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80110210: nop

    after_0:
    // 0x80110214: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80110218: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8011021C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80110220: bgez        $v1, L_80110234
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80110224: andi        $a0, $v1, 0x3
        ctx->r4 = ctx->r3 & 0X3;
            goto L_80110234;
    }
    // 0x80110224: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x80110228: beq         $a0, $zero, L_80110234
    if (ctx->r4 == 0) {
        // 0x8011022C: nop
    
            goto L_80110234;
    }
    // 0x8011022C: nop

    // 0x80110230: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_80110234:
    // 0x80110234: beq         $a0, $zero, L_80110244
    if (ctx->r4 == 0) {
        // 0x80110238: nop
    
            goto L_80110244;
    }
    // 0x80110238: nop

    // 0x8011023C: b           L_80110244
    // 0x80110240: subu        $v0, $s3, $a0
    ctx->r2 = SUB32(ctx->r19, ctx->r4);
        goto L_80110244;
    // 0x80110240: subu        $v0, $s3, $a0
    ctx->r2 = SUB32(ctx->r19, ctx->r4);
L_80110244:
    // 0x80110244: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    // 0x80110248: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8011024C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80110250: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80110254: addu        $t0, $t8, $v0
    ctx->r8 = ADD32(ctx->r24, ctx->r2);
    // 0x80110258: bne         $s0, $s4, L_80110208
    if (ctx->r16 != ctx->r20) {
        // 0x8011025C: sh          $t0, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r8;
            goto L_80110208;
    }
    // 0x8011025C: sh          $t0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r8;
    // 0x80110260: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80110264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110268: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8011026C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80110270: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80110274: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80110278: jr          $ra
    // 0x8011027C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8011027C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80803988_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080398C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80803994: jal         0x80088328
    // 0x80803998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80803998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080399C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808039A0: jal         0x80088328
    // 0x808039A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808039A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808039A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808039AC: jal         0x80088328
    // 0x808039B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808039B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808039B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808039B8: jal         0x80088328
    // 0x808039BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808039BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808039C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808039C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808039C8: jr          $ra
    // 0x808039CC: nop

    return;
    // 0x808039CC: nop

;}
RECOMP_FUNC void func_80106668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106668: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010666C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80106674: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80106678: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010667C: jal         0x800B2974
    // 0x80106680: addiu       $a0, $a0, 0x6EE0
    ctx->r4 = ADD32(ctx->r4, 0X6EE0);
    vector_push_back(rdram, ctx);
        goto after_0;
    // 0x80106680: addiu       $a0, $a0, 0x6EE0
    ctx->r4 = ADD32(ctx->r4, 0X6EE0);
    after_0:
    // 0x80106684: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106688: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8010668C: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x80106690: jal         0x800B28E8
    // 0x80106694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    vector_index_of(rdram, ctx);
        goto after_1;
    // 0x80106694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80106698: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8010669C: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    // 0x801066A0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x801066A4: jal         0x8002D6E0
    // 0x801066A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _bzero(rdram, ctx);
        goto after_2;
    // 0x801066A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x801066AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801066B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801066B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801066B8: jr          $ra
    // 0x801066BC: nop

    return;
    // 0x801066BC: nop

;}
RECOMP_FUNC void func_80800754_bskazmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080075C: jal         0x80084FE0
    // 0x80800760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800764: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080076C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800770: beql        $v0, $t6, L_80800784
    if (ctx->r2 == ctx->r14) {
        // 0x80800774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800784;
    }
    goto skip_0;
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800778: jal         0x808005BC
    // 0x8080077C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    bskazmove_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080077C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    after_1:
    // 0x80800780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800784:
    // 0x80800784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void chlightfader_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080029C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x808002A0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808002A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002A8: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x808002AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808002B4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808002B8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808002BC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808002C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808002C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002C8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x808002CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002D0: jal         0x800C8800
    // 0x808002D4: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    func_800C8800(rdram, ctx);
        goto after_0;
    // 0x808002D4: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808002D8: addiu       $a0, $zero, 0x33C
    ctx->r4 = ADD32(0, 0X33C);
    // 0x808002DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80108474
    // 0x808002E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808002E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808002E8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808002EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808002F8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808002FC: jal         0x800C89A8
    // 0x80800300: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800C89A8(rdram, ctx);
        goto after_3;
    // 0x80800300: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800304: sw          $v0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r2;
    // 0x80800308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080030C: addiu       $s1, $s5, 0x1C
    ctx->r17 = ADD32(ctx->r21, 0X1C);
    // 0x80800310: addiu       $s2, $s5, 0x14
    ctx->r18 = ADD32(ctx->r21, 0X14);
    // 0x80800314: addiu       $s4, $zero, 0x28
    ctx->r20 = ADD32(0, 0X28);
L_80800318:
    // 0x80800318: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080031C: jal         0x800C8900
    // 0x80800320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C8900(rdram, ctx);
        goto after_4;
    // 0x80800320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800324: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800328: jal         0x800C883C
    // 0x8080032C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C883C(rdram, ctx);
        goto after_5;
    // 0x8080032C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800330: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800334: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80800338: bne         $s0, $s4, L_80800318
    if (ctx->r16 != ctx->r20) {
        // 0x8080033C: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_80800318;
    }
    // 0x8080033C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80800340: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800344: sw          $s3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r19;
    // 0x80800348: lwc1        $f6, 0x2C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x8080034C: swc1        $f0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f0.u32l;
    // 0x80800350: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800354: swc1        $f6, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->f6.u32l;
    // 0x80800358: sw          $t6, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r14;
    // 0x8080035C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80800360: swc1        $f0, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f0.u32l;
    // 0x80800364: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800368: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080036C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800370: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800380: jr          $ra
    // 0x80800384: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800384: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void func_8080018C_chminelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: bne         $a1, $at, L_808001CC
    if (ctx->r5 != ctx->r1) {
        // 0x8080019C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001CC;
    }
    // 0x8080019C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001A0: lh          $t6, 0x20($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X20);
    // 0x808001A4: addiu       $at, $zero, 0xFA1
    ctx->r1 = ADD32(0, 0XFA1);
    // 0x808001A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001AC: bne         $t6, $at, L_808001C4
    if (ctx->r14 != ctx->r1) {
        // 0x808001B0: nop
    
            goto L_808001C4;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x8010108C
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808001BC: b           L_808001D4
    // 0x808001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001D4;
    // 0x808001C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001C4:
    // 0x808001C4: b           L_808001D4
    // 0x808001C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001D4;
    // 0x808001C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001CC:
    // 0x808001CC: jal         0x80086248
    // 0x808001D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_808001D4:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

    // 0x808001E4: nop

    // 0x808001E8: nop

    // 0x808001EC: nop

;}
RECOMP_FUNC void ncbadive_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: jal         0x800EF410
    // 0x808001A0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    func_800EF410(rdram, ctx);
        goto after_0;
    // 0x808001A0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    after_0:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

    // 0x808001B4: nop

    // 0x808001B8: nop

    // 0x808001BC: nop

;}
RECOMP_FUNC void func_8080014C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800154: jal         0x80100094
    // 0x80800158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080015C: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x80800160: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800168: blez        $t6, L_808001A8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080016C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808001A8;
    }
    // 0x8080016C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800170: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800178: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
L_8080017C:
    // 0x8080017C: bnel        $a1, $t7, L_80800190
    if (ctx->r5 != ctx->r15) {
        // 0x80800180: sw          $zero, 0x20($v1)
        MEM_W(0X20, ctx->r3) = 0;
            goto L_80800190;
    }
    goto skip_0;
    // 0x80800180: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    skip_0:
    // 0x80800184: b           L_80800190
    // 0x80800188: sw          $a2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r6;
        goto L_80800190;
    // 0x80800188: sw          $a2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r6;
    // 0x8080018C: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_80800190:
    // 0x80800190: lbu         $t8, 0x3A($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X3A);
    // 0x80800194: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800198: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080019C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808001A0: bnel        $at, $zero, L_8080017C
    if (ctx->r1 != 0) {
        // 0x808001A4: lbu         $t7, 0x39($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X39);
            goto L_8080017C;
    }
    goto skip_1;
    // 0x808001A4: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    skip_1:
L_808001A8:
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void _bapackctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084760: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084760);
    return;
    // 0x80084764: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void aligned8_memset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E98: srl         $t0, $a2, 3
    ctx->r8 = S32(U32(ctx->r6) >> 3);
    // 0x80019E9C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80019EA0: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
L_80019EA4:
    // 0x80019EA4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80019EA8: sw          $a1, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r5;
    // 0x80019EAC: bne         $t0, $a0, L_80019EA4
    if (ctx->r8 != ctx->r4) {
        // 0x80019EB0: sw          $a1, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r5;
            goto L_80019EA4;
    }
    // 0x80019EB0: sw          $a1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r5;
    // 0x80019EB4: jr          $ra
    // 0x80019EB8: nop

    return;
    // 0x80019EB8: nop

;}
RECOMP_FUNC void func_808001A8_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: bne         $a1, $at, L_808001EC
    if (ctx->r5 != ctx->r1) {
        // 0x808001B8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808001EC;
    }
    // 0x808001B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001BC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808001C0: bne         $a2, $at, L_808001EC
    if (ctx->r6 != ctx->r1) {
        // 0x808001C4: nop
    
            goto L_808001EC;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x80085710
    // 0x808001CC: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808001CC: nop

    after_0:
    // 0x808001D0: addiu       $a0, $zero, 0x1A7
    ctx->r4 = ADD32(0, 0X1A7);
    // 0x808001D4: jal         0x800887D8
    // 0x808001D8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808001D8: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x808001DC: jal         0x800FFAB0
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808001E4: b           L_808001F4
    // 0x808001E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808001F4;
    // 0x808001E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808001EC:
    // 0x808001EC: jal         0x80086248
    // 0x808001F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_808001F4:
    // 0x808001F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_808004D0_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E4: lbu         $t0, 0x1E5($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1E5);
    // 0x808004E8: lbu         $t7, 0x1E7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E7);
    // 0x808004EC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808004F0: ori         $t2, $t0, 0x1
    ctx->r10 = ctx->r8 | 0X1;
    // 0x808004F4: sb          $t2, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r10;
    // 0x808004F8: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x808004FC: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x80800500: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800504: sb          $t6, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r14;
    // 0x80800508: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    // 0x8080050C: sb          $t3, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r11;
    // 0x80800510: jal         0x808001D4
    // 0x80800514: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80800514: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x80800518: addiu       $a0, $s2, 0x30
    ctx->r4 = ADD32(ctx->r18, 0X30);
    // 0x8080051C: jal         0x808001D4
    // 0x80800520: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_1;
    // 0x80800520: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_1:
    // 0x80800524: lbu         $t4, 0x1E4($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X1E4);
    // 0x80800528: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080052C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800530: lwc1        $f6, 0x14C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14C);
    // 0x80800534: andi        $t6, $t4, 0xFFBF
    ctx->r14 = ctx->r12 & 0XFFBF;
    // 0x80800538: andi        $t8, $t6, 0xDF
    ctx->r24 = ctx->r14 & 0XDF;
    // 0x8080053C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800540: sb          $t6, 0x1E4($s2)
    MEM_B(0X1E4, ctx->r18) = ctx->r14;
    // 0x80800544: andi        $t0, $t8, 0xF7
    ctx->r8 = ctx->r24 & 0XF7;
    // 0x80800548: sb          $t8, 0x1E4($s2)
    MEM_B(0X1E4, ctx->r18) = ctx->r24;
    // 0x8080054C: andi        $t2, $t0, 0xFB
    ctx->r10 = ctx->r8 & 0XFB;
    // 0x80800550: sb          $t0, 0x1E4($s2)
    MEM_B(0X1E4, ctx->r18) = ctx->r8;
    // 0x80800554: sb          $t2, 0x1E4($s2)
    MEM_B(0X1E4, ctx->r18) = ctx->r10;
    // 0x80800558: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x8080055C: bc1f        L_80800584
    if (!c1cs) {
        // 0x80800560: sb          $t3, 0x1E4($s2)
        MEM_B(0X1E4, ctx->r18) = ctx->r11;
            goto L_80800584;
    }
    // 0x80800560: sb          $t3, 0x1E4($s2)
    MEM_B(0X1E4, ctx->r18) = ctx->r11;
    // 0x80800564: jal         0x800FCCD4
    // 0x80800568: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x80800568: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    after_2:
    // 0x8080056C: beql        $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x80800570: sb          $zero, 0x170($s2)
        MEM_B(0X170, ctx->r18) = 0;
            goto L_808005D0;
    }
    goto skip_0;
    // 0x80800570: sb          $zero, 0x170($s2)
    MEM_B(0X170, ctx->r18) = 0;
    skip_0:
    // 0x80800574: jal         0x800FC74C
    // 0x80800578: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    func_800FC74C(rdram, ctx);
        goto after_3;
    // 0x80800578: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    after_3:
    // 0x8080057C: b           L_808005D0
    // 0x80800580: sb          $zero, 0x170($s2)
    MEM_B(0X170, ctx->r18) = 0;
        goto L_808005D0;
    // 0x80800580: sb          $zero, 0x170($s2)
    MEM_B(0X170, ctx->r18) = 0;
L_80800584:
    // 0x80800584: lbu         $v0, 0x178($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X178);
    // 0x80800588: beql        $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x8080058C: sb          $zero, 0x170($s2)
        MEM_B(0X170, ctx->r18) = 0;
            goto L_808005D0;
    }
    goto skip_1;
    // 0x8080058C: sb          $zero, 0x170($s2)
    MEM_B(0X170, ctx->r18) = 0;
    skip_1:
    // 0x80800590: blez        $v0, L_808005CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800594: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808005CC;
    }
    // 0x80800594: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800598: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8080059C:
    // 0x8080059C: jal         0x800C3D78
    // 0x808005A0: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    func_800C3D78(rdram, ctx);
        goto after_4;
    // 0x808005A0: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    after_4:
    // 0x808005A4: beql        $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x808005A8: lbu         $t4, 0x178($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0X178);
            goto L_808005B8;
    }
    goto skip_2;
    // 0x808005A8: lbu         $t4, 0x178($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X178);
    skip_2:
    // 0x808005AC: jal         0x800C3CE8
    // 0x808005B0: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    func_800C3CE8(rdram, ctx);
        goto after_5;
    // 0x808005B0: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    after_5:
    // 0x808005B4: lbu         $t4, 0x178($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X178);
L_808005B8:
    // 0x808005B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808005BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808005C0: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808005C4: bne         $at, $zero, L_8080059C
    if (ctx->r1 != 0) {
        // 0x808005C8: nop
    
            goto L_8080059C;
    }
    // 0x808005C8: nop

L_808005CC:
    // 0x808005CC: sb          $zero, 0x170($s2)
    MEM_B(0X170, ctx->r18) = 0;
L_808005D0:
    // 0x808005D0: jal         0x80803440
    // 0x808005D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gczoombox_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x808005D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005E8: jr          $ra
    // 0x808005EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800D2438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2438: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D243C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D2440: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D2444: addiu       $v0, $v0, -0x4C0C
    ctx->r2 = ADD32(ctx->r2, -0X4C0C);
    // 0x800D2448: addiu       $v1, $v1, -0x5050
    ctx->r3 = ADD32(ctx->r3, -0X5050);
    // 0x800D244C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800D2450:
    // 0x800D2450: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800D2454: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800D2458: sh          $a0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r4;
    // 0x800D245C: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x800D2460: bne         $at, $zero, L_800D2450
    if (ctx->r1 != 0) {
        // 0x800D2464: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800D2450;
    }
    // 0x800D2464: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800D2468: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D246C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2470: addiu       $v0, $v0, -0x4CE0
    ctx->r2 = ADD32(ctx->r2, -0X4CE0);
    // 0x800D2474: addiu       $v1, $v1, -0x4D40
    ctx->r3 = ADD32(ctx->r3, -0X4D40);
L_800D2478:
    // 0x800D2478: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800D247C: sh          $a0, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r4;
    // 0x800D2480: sh          $a0, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r4;
    // 0x800D2484: sh          $a0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r4;
    // 0x800D2488: bne         $v1, $v0, L_800D2478
    if (ctx->r3 != ctx->r2) {
        // 0x800D248C: sh          $a0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r4;
            goto L_800D2478;
    }
    // 0x800D248C: sh          $a0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r4;
    // 0x800D2490: jr          $ra
    // 0x800D2494: nop

    return;
    // 0x800D2494: nop

;}
RECOMP_FUNC void func_800DF8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF8B4: jr          $ra
    // 0x800DF8B8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    return;
    // 0x800DF8B8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
;}
