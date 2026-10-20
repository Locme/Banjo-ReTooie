#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80802F00_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80802F00_chdiggerboss");
    // 0x80802F00: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802F04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802F08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802F10: jal         0x80803BE8
    // 0x80802F14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802F14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80802F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802F20: jal         0x80802878
    // 0x80802F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80802F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80802F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802F30: jal         0x80800618
    // 0x80802F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800618_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80802F38: jal         0x80802228
    // 0x80802F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80802F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802F40: jal         0x808056B8
    // 0x80802F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80802F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80802F48: jal         0x800F54E4
    // 0x80802F4C: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80802F4C: nop

    after_5:
    // 0x80802F50: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802F58: jal         0x800F5A00
    // 0x80802F5C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x80802F5C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80802F60: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802F64: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80802F68: jal         0x800EFB8C
    // 0x80802F6C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EFB8C(rdram, ctx);
        goto after_7;
    // 0x80802F6C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x80802F70: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A54) << 16);
    // 0x80802F74: lwc1        $f4, -0x65AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A54));
    // 0x80802F78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802F7C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802F80: nop

    // 0x80802F84: bc1fl       L_80802FD0
    if (!c1cs) {
        // 0x80802F88: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80802FD0;
    }
    goto skip_0;
    // 0x80802F88: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80802F8C: jal         0x800F1DF4
    // 0x80802F90: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F1DF4(rdram, ctx);
        goto after_8;
    // 0x80802F90: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x80802F94: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80802F98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802F9C: lui         $a2, 0x4409
    ctx->r6 = S32(0X4409 << 16);
    // 0x80802FA0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80802FA4: jal         0x800EEB9C
    // 0x80802FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x80802FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802FB0: jal         0x800EF04C
    // 0x80802FB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80802FB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80802FB8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802FBC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80802FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802FC4: jal         0x800F8418
    // 0x80802FC8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_800F8418(rdram, ctx);
        goto after_11;
    // 0x80802FC8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80802FCC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_80802FD0:
    // 0x80802FD0: jal         0x800F7F98
    // 0x80802FD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_12;
    // 0x80802FD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80802FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802FDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802FE4: jr          $ra
    // 0x80802FE8: nop

    return;
    // 0x80802FE8: nop

;}
RECOMP_FUNC void func_8080000C_chcamerawibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800014: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800018: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8080001C: bgez        $t7, L_80800030
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800020: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800030;
    }
    // 0x80800020: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800028: nop

    // 0x8080002C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800030:
    // 0x80800030: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800038: lwc1        $f18, 0x38($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080003C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800040: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    // 0x80800044: jr          $ra
    // 0x80800048: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x80800048: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void badata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080072C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800730: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800734: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080073C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1A78) << 16);
    // 0x80800740: jal         0x808006AC
    // 0x80800744: addiu       $a1, $a1, 0x1A78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1A78));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800744: addiu       $a1, $a1, 0x1A78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1A78));
    after_0:
    // 0x80800748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080074C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800750: jr          $ra
    // 0x80800754: nop

    return;
    // 0x80800754: nop

;}
RECOMP_FUNC void chnewfreezy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080190C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1812, 0X1978) << 16);
    // 0x80801910: jr          $ra
    // 0x80801914: addiu       $v0, $v0, 0x1978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1812, 0X1978));
    return;
    // 0x80801914: addiu       $v0, $v0, 0x1978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1812, 0X1978));
    // 0x80801918: nop

    // 0x8080191C: nop

;}
RECOMP_FUNC void func_800B90E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B90E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B90EC: lw          $v0, 0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7128);
    // 0x800B90F0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800B90F4: beq         $v0, $zero, L_800B9100
    if (ctx->r2 == 0) {
        // 0x800B90F8: nop
    
            goto L_800B9100;
    }
    // 0x800B90F8: nop

    // 0x800B90FC: sb          $t6, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r14;
L_800B9100:
    // 0x800B9100: jr          $ra
    // 0x800B9104: nop

    return;
    // 0x800B9104: nop

;}
RECOMP_FUNC void func_808000AC_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: jal         0x80093360
    // 0x808000C0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_0;
    // 0x808000C0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_0:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x8009C908
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_1;
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000D8: jal         0x8009C99C
    // 0x808000DC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x808000DC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_2:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000E8: jal         0x8009C554
    // 0x808000EC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_3;
    // 0x808000EC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x808000F0: jal         0x80084C68
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800100: jal         0x800959C8
    // 0x80800104: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800959C8(rdram, ctx);
        goto after_5;
    // 0x80800104: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_5:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800961AC
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80800608_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080060C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800610: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800614: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800618: bltz        $a1, L_808006DC
    if (SIGNED(ctx->r5) < 0) {
        // 0x8080061C: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_808006DC;
    }
    // 0x8080061C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800620: slti        $at, $a1, 0x64
    ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    // 0x80800624: beql        $at, $zero, L_808006E0
    if (ctx->r1 == 0) {
        // 0x80800628: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006E0;
    }
    goto skip_0;
    // 0x80800628: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080062C: beq         $a1, $zero, L_808006DC
    if (ctx->r5 == 0) {
        // 0x80800630: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_808006DC;
    }
    // 0x80800630: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800634: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800638: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3338, 0X8B0) << 16);
    // 0x8080063C: addiu       $t7, $t7, 0x8B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3338, 0X8B0));
    // 0x80800640: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800644: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800648: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8080064C: beql        $v0, $zero, L_8080067C
    if (ctx->r2 == 0) {
        // 0x80800650: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_8080067C;
    }
    goto skip_1;
    // 0x80800650: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80800654: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800658: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8080065C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800660: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800664: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80800668: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080066C: jal         0x80088B40
    // 0x80800670: nop

    _fxdialog_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800670: nop

    after_0:
    // 0x80800674: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800678: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8080067C:
    // 0x8080067C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800680: beq         $v0, $zero, L_8080069C
    if (ctx->r2 == 0) {
        // 0x80800684: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_8080069C;
    }
    // 0x80800684: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800688: jal         0x800E8C58
    // 0x8080068C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800E8C58(rdram, ctx);
        goto after_1;
    // 0x8080068C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800690: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800694: b           L_8080069C
    // 0x80800698: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8080069C;
    // 0x80800698: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8080069C:
    // 0x8080069C: lb          $t8, 0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2);
    // 0x808006A0: lb          $t9, 0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X3);
    // 0x808006A4: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    // 0x808006A8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x808006AC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x808006B0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x808006B4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808006B8: srl         $t2, $t1, 15
    ctx->r10 = S32(U32(ctx->r9) >> 15);
    // 0x808006BC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x808006C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808006C4: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x808006C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808006CC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808006D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808006D4: jal         0x80088B50
    // 0x808006D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _fxdialog_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808006D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
L_808006DC:
    // 0x808006DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006E0:
    // 0x808006E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006E4: jr          $ra
    // 0x808006E8: nop

    return;
    // 0x808006E8: nop

;}
RECOMP_FUNC void idwibble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: jr          $ra
    // 0x80800320: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800320: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808001E4_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: jal         0x800D8FF8
    // 0x808001F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808001FC: lwc1        $f4, 0x16C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X16C);
    // 0x80800200: jal         0x800F0E00
    // 0x80800204: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x80800204: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x80800208: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: swc1        $f0, 0x16C($t7)
    MEM_W(0X16C, ctx->r15) = ctx->f0.u32l;
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void bstnt_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E64: jal         0x8009E74C
    // 0x80800E68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800E68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800E6C: bne         $v0, $zero, L_80800EB8
    if (ctx->r2 != 0) {
        // 0x80800E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EB8;
    }
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E78: jal         0x800947EC
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E84: jal         0x80092864
    // 0x80800E88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_2;
    // 0x80800E88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800E8C: jal         0x8009C000
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_3;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E94: jal         0x8009C570
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_4;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E9C: jal         0x8009EF60
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_5;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800EA4: jal         0x80095A40
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_6;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB0: jal         0x80092744
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092744(rdram, ctx);
        goto after_7;
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80800EB8:
    // 0x80800EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EC4: jr          $ra
    // 0x80800EC8: nop

    return;
    // 0x80800EC8: nop

;}
RECOMP_FUNC void func_800F8EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8EC4: jal         0x800F5410
    // 0x800F8EC8: nop

    func_800F5410(rdram, ctx);
        goto after_0;
    // 0x800F8EC8: nop

    after_0:
    // 0x800F8ECC: jal         0x800F8E78
    // 0x800F8ED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8E78(rdram, ctx);
        goto after_1;
    // 0x800F8ED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800F8ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8EDC: jr          $ra
    // 0x800F8EE0: nop

    return;
    // 0x800F8EE0: nop

;}
RECOMP_FUNC void func_80806EC4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806EC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806EC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806ECC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806ED0: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80806ED4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80806ED8: jal         0x800827E0
    // 0x80806EDC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    _bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80806EDC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80806EE0: jal         0x8080800C
    // 0x80806EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080800C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80806EE8: jal         0x800D3948
    // 0x80806EEC: nop

    func_800D3948(rdram, ctx);
        goto after_2;
    // 0x80806EEC: nop

    after_2:
    // 0x80806EF0: beq         $v0, $zero, L_80806F24
    if (ctx->r2 == 0) {
        // 0x80806EF4: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80806F24;
    }
    // 0x80806EF4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80806EF8: lw          $t8, 0x68($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X68);
    // 0x80806EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806F00: jal         0x800844D0
    // 0x80806F04: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    _bababykaz_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80806F04: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_3:
    // 0x80806F08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80806F0C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80806F10: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80806F14: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80806F18: or          $a2, $t9, $t1
    ctx->r6 = ctx->r25 | ctx->r9;
    // 0x80806F1C: jal         0x80101180
    // 0x80806F20: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x80806F20: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    after_4:
L_80806F24:
    // 0x80806F24: jal         0x80084488
    // 0x80806F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80806F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80806F2C: beq         $v0, $zero, L_80806F48
    if (ctx->r2 == 0) {
        // 0x80806F30: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80806F48;
    }
    // 0x80806F30: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806F38: jal         0x8009E5C8
    // 0x80806F3C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80806F3C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    after_6:
    // 0x80806F40: b           L_80807014
    // 0x80806F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807014;
    // 0x80806F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806F48:
    // 0x80806F48: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80806F4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80806F50: beq         $v0, $zero, L_80806F68
    if (ctx->r2 == 0) {
        // 0x80806F54: nop
    
            goto L_80806F68;
    }
    // 0x80806F54: nop

    // 0x80806F58: beq         $v0, $at, L_80806FA8
    if (ctx->r2 == ctx->r1) {
        // 0x80806F5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806FA8;
    }
    // 0x80806F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806F60: b           L_80807000
    // 0x80806F64: nop

        goto L_80807000;
    // 0x80806F64: nop

L_80806F68:
    // 0x80806F68: jal         0x80801A98
    // 0x80806F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A98_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80806F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80806F70: beq         $v0, $zero, L_80807000
    if (ctx->r2 == 0) {
        // 0x80806F74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807000;
    }
    // 0x80806F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806F78: jal         0x800936E8
    // 0x80806F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_8;
    // 0x80806F7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80806F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806F84: jal         0x8009337C
    // 0x80806F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_9;
    // 0x80806F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80806F8C: jal         0x80808DB0
    // 0x80806F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x80806F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80806F94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80806F98: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80806F9C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80806FA0: b           L_80807000
    // 0x80806FA4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
        goto L_80807000;
    // 0x80806FA4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
L_80806FA8:
    // 0x80806FA8: jal         0x80804848
    // 0x80806FAC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    func_80804848_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80806FAC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_11:
    // 0x80806FB0: jal         0x80801DC0
    // 0x80806FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DC0_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80806FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80806FB8: jal         0x80809D24
    // 0x80806FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80806FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80806FC0: jal         0x8080682C
    // 0x80806FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080682C_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x80806FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80806FC8: jal         0x808099B4
    // 0x80806FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808099B4_bsfirstp(rdram, ctx);
        goto after_15;
    // 0x80806FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80806FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806FD4: jal         0x8080633C
    // 0x80806FD8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x80806FD8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80806FDC: jal         0x80808EF0
    // 0x80806FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808EF0_bsfirstp(rdram, ctx);
        goto after_17;
    // 0x80806FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80806FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806FE8: jal         0x80091A58
    // 0x80806FEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_18;
    // 0x80806FEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
    // 0x80806FF0: beq         $v0, $zero, L_80807000
    if (ctx->r2 == 0) {
        // 0x80806FF4: nop
    
            goto L_80807000;
    }
    // 0x80806FF4: nop

    // 0x80806FF8: jal         0x80082820
    // 0x80806FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_13(rdram, ctx);
        goto after_19;
    // 0x80806FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80807000:
    // 0x80807000: jal         0x80801928
    // 0x80807004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_20;
    // 0x80807004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80807008: jal         0x80806BA0
    // 0x8080700C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806BA0_bsfirstp(rdram, ctx);
        goto after_21;
    // 0x8080700C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80807010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807014:
    // 0x80807014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080701C: jr          $ra
    // 0x80807020: nop

    return;
    // 0x80807020: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F70: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F70);
    return;
    // 0x80083F74: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009328C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009328C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093294: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80093298: jal         0x800136E4
    // 0x8009329C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009329C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800932A0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800932A4: lw          $t7, 0x50($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X50);
    // 0x800932A8: swc1        $f0, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f0.u32l;
    // 0x800932AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800932B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800932B4: jr          $ra
    // 0x800932B8: nop

    return;
    // 0x800932B8: nop

;}
RECOMP_FUNC void func_800F8150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8150: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8158: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F815C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8160: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8164: jal         0x80093370
    // 0x800F8168: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80093370(rdram, ctx);
        goto after_0;
    // 0x800F8168: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F816C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8174: jr          $ra
    // 0x800F8178: nop

    return;
    // 0x800F8178: nop

;}
RECOMP_FUNC void chjamjarsdummy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1568, 0X338) << 16);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $v0, $v0, 0x338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1568, 0X338));
    return;
    // 0x808002F8: addiu       $v0, $v0, 0x338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1568, 0X338));
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_80801C78_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801C84: jal         0x80100094
    // 0x80801C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C8C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80801C90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801C94: beql        $t6, $zero, L_80801CB4
    if (ctx->r14 == 0) {
        // 0x80801C98: lbu         $a0, 0x1($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X1);
            goto L_80801CB4;
    }
    goto skip_0;
    // 0x80801C98: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x80801C9C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80801CA0: jal         0x800C2FDC
    // 0x80801CA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80801CA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801CA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CAC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80801CB0: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
L_80801CB4:
    // 0x80801CB4: beql        $a0, $zero, L_80801CD0
    if (ctx->r4 == 0) {
        // 0x80801CB8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801CD0;
    }
    goto skip_1;
    // 0x80801CB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80801CBC: jal         0x800C2FDC
    // 0x80801CC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800C2FDC(rdram, ctx);
        goto after_2;
    // 0x80801CC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801CC4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CC8: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80801CCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801CD0:
    // 0x80801CD0: jal         0x80100094
    // 0x80801CD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801CD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801CD8: beq         $v0, $zero, L_80801CE8
    if (ctx->r2 == 0) {
        // 0x80801CDC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801CE8;
    }
    // 0x80801CDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801CE0: jal         0x80089848
    // 0x80801CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80801CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80801CE8:
    // 0x80801CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801CF0: jr          $ra
    // 0x80801CF4: nop

    return;
    // 0x80801CF4: nop

;}
RECOMP_FUNC void func_80804230_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804238: jal         0x80100094
    // 0x8080423C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080423C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804240: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80804244: jal         0x8008A038
    // 0x80804248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80804248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080424C: jal         0x800C8A98
    // 0x80804250: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80804250: nop

    after_2:
    // 0x80804254: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80804258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080425C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804260: jal         0x800C8FE0
    // 0x80804264: sw          $v0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r2;
    func_800C8FE0(rdram, ctx);
        goto after_3;
    // 0x80804264: sw          $v0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r2;
    after_3:
    // 0x80804268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080426C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804270: jr          $ra
    // 0x80804274: nop

    return;
    // 0x80804274: nop

    // 0x80804278: nop

    // 0x8080427C: nop

;}
RECOMP_FUNC void func_800C1950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1958: beq         $a0, $zero, L_800C1974
    if (ctx->r4 == 0) {
        // 0x800C195C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C1974;
    }
    // 0x800C195C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1960: jal         0x800C1448
    // 0x800C1964: nop

    func_800C1448(rdram, ctx);
        goto after_0;
    // 0x800C1964: nop

    after_0:
    // 0x800C1968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C196C: jal         0x800DC42C
    // 0x800C1970: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800DC42C(rdram, ctx);
        goto after_1;
    // 0x800C1970: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800C1974:
    // 0x800C1974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C197C: jr          $ra
    // 0x800C1980: nop

    return;
    // 0x800C1980: nop

;}
RECOMP_FUNC void bastatemem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: jr          $ra
    // 0x80800064: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
    return;
    // 0x80800064: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
    // 0x80800068: nop

    // 0x8080006C: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F00: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084F00);
    return;
    // 0x80084F04: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800D3770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3770: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D3774: lbu         $v0, 0x762C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X762C);
    // 0x800D3778: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800D377C: slti        $a0, $v0, 0xF
    ctx->r4 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800D3780: xori        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 ^ 0X1;
    // 0x800D3784: beq         $v1, $zero, L_800D3790
    if (ctx->r3 == 0) {
        // 0x800D3788: nop
    
            goto L_800D3790;
    }
    // 0x800D3788: nop

    // 0x800D378C: slti        $v1, $v0, 0x1C
    ctx->r3 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
L_800D3790:
    // 0x800D3790: bne         $v0, $at, L_800D379C
    if (ctx->r2 != ctx->r1) {
        // 0x800D3794: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800D379C;
    }
    // 0x800D3794: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800D3798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D379C:
    // 0x800D379C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D37A0: lb          $v0, -0x4C0F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C0F);
    // 0x800D37A4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800D37A8: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x800D37AC: beq         $v0, $zero, L_800D37B8
    if (ctx->r2 == 0) {
        // 0x800D37B0: nop
    
            goto L_800D37B8;
    }
    // 0x800D37B0: nop

    // 0x800D37B4: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
L_800D37B8:
    // 0x800D37B8: jr          $ra
    // 0x800D37BC: nop

    return;
    // 0x800D37BC: nop

;}
RECOMP_FUNC void func_8080001C_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800028: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2132, 0X2E4) << 16);
    // 0x8080002C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800030: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800034: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80800038: jal         0x800DA544
    // 0x8080003C: lw          $a0, 0x2E4($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(2132, 0X2E4));
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x8080003C: lw          $a0, 0x2E4($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(2132, 0X2E4));
    after_0:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_8010A848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A848: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A84C: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x8010A850: sll         $t7, $v0, 23
    ctx->r15 = S32(ctx->r2 << 23);
    // 0x8010A854: jr          $ra
    // 0x8010A858: srl         $v0, $t7, 24
    ctx->r2 = S32(U32(ctx->r15) >> 24);
    return;
    // 0x8010A858: srl         $v0, $t7, 24
    ctx->r2 = S32(U32(ctx->r15) >> 24);
;}
RECOMP_FUNC void gcmapsects_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F7C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800F80: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800F84: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800F88: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800F8C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800F90: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800F94: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800F98: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800F9C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800FA0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800FA4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800FA8: lh          $v1, 0x74($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X74);
    // 0x80800FAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800FB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800FB4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800FB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800FBC: beq         $v1, $at, L_80801040
    if (ctx->r3 == ctx->r1) {
        // 0x80800FC0: mov.s       $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
            goto L_80801040;
    }
    // 0x80800FC0: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80800FC4: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x80800FC8: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x80800FCC: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800FD0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80800FD4: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x80800FD8: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80800FDC: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x80800FE0: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x80800FE4: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x80800FE8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800FEC: jal         0x800EFED0
    // 0x80800FF0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFED0(rdram, ctx);
        goto after_0;
    // 0x80800FF0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80800FF4: beq         $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80800FF8: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80801040;
    }
    // 0x80800FF8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FFC: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x80801000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801004: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80801008: lwc1        $f0, 0x34($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8080100C: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x80801010: nop

    // 0x80801014: bc1t        L_80801040
    if (c1cs) {
        // 0x80801018: nop
    
            goto L_80801040;
    }
    // 0x80801018: nop

    // 0x8080101C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80801020: nop

    // 0x80801024: bc1tl       L_80801040
    if (c1cs) {
        // 0x80801028: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80801040;
    }
    goto skip_0;
    // 0x80801028: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
    // 0x8080102C: c.eq.s      $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f22.fl == ctx->f22.fl;
    // 0x80801030: nop

    // 0x80801034: bc1f        L_80801040
    if (!c1cs) {
        // 0x80801038: nop
    
            goto L_80801040;
    }
    // 0x80801038: nop

    // 0x8080103C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80801040:
    // 0x80801040: beql        $a3, $zero, L_808010F8
    if (ctx->r7 == 0) {
        // 0x80801044: c.eq.s      $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
            goto L_808010F8;
    }
    goto skip_1;
    // 0x80801044: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    skip_1:
    // 0x80801048: lbu         $t9, 0x77($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X77);
    // 0x8080104C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801050: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801054: blezl       $t9, L_808010F8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80801058: c.eq.s      $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
            goto L_808010F8;
    }
    goto skip_2;
    // 0x80801058: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    skip_2:
    // 0x8080105C: lw          $t0, 0x68($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X68);
L_80801060:
    // 0x80801060: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801064: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x80801068: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    // 0x8080106C: jal         0x800EFFB4
    // 0x80801070: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    func_800EFFB4(rdram, ctx);
        goto after_1;
    // 0x80801070: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    after_1:
    // 0x80801074: beql        $v0, $zero, L_808010E0
    if (ctx->r2 == 0) {
        // 0x80801078: lbu         $t4, 0x77($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0X77);
            goto L_808010E0;
    }
    goto skip_3;
    // 0x80801078: lbu         $t4, 0x77($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X77);
    skip_3:
    // 0x8080107C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x80801080: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801084: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x80801088: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x8080108C: jal         0x800EFED0
    // 0x80801090: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EFED0(rdram, ctx);
        goto after_2;
    // 0x80801090: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_2:
    // 0x80801094: beql        $v0, $zero, L_808010E0
    if (ctx->r2 == 0) {
        // 0x80801098: lbu         $t4, 0x77($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0X77);
            goto L_808010E0;
    }
    goto skip_4;
    // 0x80801098: lbu         $t4, 0x77($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X77);
    skip_4:
    // 0x8080109C: lw          $t2, 0x68($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X68);
    // 0x808010A0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x808010A4: lwc1        $f0, 0x34($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X34);
    // 0x808010A8: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x808010AC: nop

    // 0x808010B0: bc1tl       L_808010E0
    if (c1cs) {
        // 0x808010B4: lbu         $t4, 0x77($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0X77);
            goto L_808010E0;
    }
    goto skip_5;
    // 0x808010B4: lbu         $t4, 0x77($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X77);
    skip_5:
    // 0x808010B8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x808010BC: nop

    // 0x808010C0: bc1tl       L_808010DC
    if (c1cs) {
        // 0x808010C4: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_808010DC;
    }
    goto skip_6;
    // 0x808010C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_6:
    // 0x808010C8: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x808010CC: nop

    // 0x808010D0: bc1fl       L_808010E0
    if (!c1cs) {
        // 0x808010D4: lbu         $t4, 0x77($s2)
        ctx->r12 = MEM_BU(ctx->r18, 0X77);
            goto L_808010E0;
    }
    goto skip_7;
    // 0x808010D4: lbu         $t4, 0x77($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X77);
    skip_7:
    // 0x808010D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_808010DC:
    // 0x808010DC: lbu         $t4, 0x77($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X77);
L_808010E0:
    // 0x808010E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808010E4: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x808010E8: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808010EC: bnel        $at, $zero, L_80801060
    if (ctx->r1 != 0) {
        // 0x808010F0: lw          $t0, 0x68($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X68);
            goto L_80801060;
    }
    goto skip_8;
    // 0x808010F0: lw          $t0, 0x68($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X68);
    skip_8:
    // 0x808010F4: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
L_808010F8:
    // 0x808010F8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808010FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801100: bc1t        L_80801150
    if (c1cs) {
        // 0x80801104: nop
    
            goto L_80801150;
    }
    // 0x80801104: nop

    // 0x80801108: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080110C: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80801110: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80801114: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x80801118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080111C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801120: nop

    // 0x80801124: bc1f        L_80801148
    if (!c1cs) {
        // 0x80801128: nop
    
            goto L_80801148;
    }
    // 0x80801128: nop

    // 0x8080112C: add.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x80801130: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801134: nop

    // 0x80801138: bc1f        L_80801148
    if (!c1cs) {
        // 0x8080113C: nop
    
            goto L_80801148;
    }
    // 0x8080113C: nop

    // 0x80801140: b           L_80801150
    // 0x80801144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801150;
    // 0x80801144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801148:
    // 0x80801148: b           L_80801150
    // 0x8080114C: swc1        $f20, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f20.u32l;
        goto L_80801150;
    // 0x8080114C: swc1        $f20, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f20.u32l;
L_80801150:
    // 0x80801150: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801154: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801158: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080115C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801160: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80801164: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80801168: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8080116C: jr          $ra
    // 0x80801170: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80801170: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800000_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80102424
    // 0x8080000C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
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
RECOMP_FUNC void func_80800BA0_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80800BA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800BA8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800BAC: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80800BB0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800BB4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x80800BB8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800BBC: lh          $t8, 0x1118($t7)
    ctx->r24 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x80800BC0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80800BC4: sll         $t0, $t8, 6
    ctx->r8 = S32(ctx->r24 << 6);
    // 0x80800BC8: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x80800BCC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800BD0: jr          $ra
    // 0x80800BD4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    return;
    // 0x80800BD4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void glsplinefuncs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800014: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800018: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080001C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800020: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800024: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800028: jal         0x800D7400
    // 0x8080002C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_800D7400(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800030: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800034: jal         0x8001B798
    // 0x80800038: lh          $a0, 0x186($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X186);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800038: lh          $a0, 0x186($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X186);
    after_1:
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2702, 0X400) << 16);
    // 0x80800040: lwc1        $f0, 0x400($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2702, 0X400));
    // 0x80800044: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800048: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8080004C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800050: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80800054: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800058: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080005C: beq         $s4, $at, L_80800198
    if (ctx->r20 == ctx->r1) {
        // 0x80800060: swc1        $f0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
            goto L_80800198;
    }
    // 0x80800060: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80800064: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x80800068: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8080006C: jal         0x8001B798
    // 0x80800070: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x80800070: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    after_2:
    // 0x80800074: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80800078: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8080007C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800080: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800084: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80800088: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080008C: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x80800090: srl         $t3, $t2, 21
    ctx->r11 = S32(U32(ctx->r10) >> 21);
    // 0x80800094: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800098: beq         $s0, $t3, L_808000CC
    if (ctx->r16 == ctx->r11) {
        // 0x8080009C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_808000CC;
    }
    // 0x8080009C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000A0: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x808000A4: beql        $at, $zero, L_808000D0
    if (ctx->r1 == 0) {
        // 0x808000A8: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000A8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    skip_0:
    // 0x808000AC: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
L_808000B0:
    // 0x808000B0: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x808000B4: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x808000B8: srl         $t5, $t4, 21
    ctx->r13 = S32(U32(ctx->r12) >> 21);
    // 0x808000BC: beql        $s0, $t5, L_808000D0
    if (ctx->r16 == ctx->r13) {
        // 0x808000C0: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_808000D0;
    }
    goto skip_1;
    // 0x808000C0: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    skip_1:
    // 0x808000C4: bnel        $at, $zero, L_808000B0
    if (ctx->r1 != 0) {
        // 0x808000C8: lw          $t4, 0x24($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X24);
            goto L_808000B0;
    }
    goto skip_2;
    // 0x808000C8: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    skip_2:
L_808000CC:
    // 0x808000CC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
L_808000D0:
    // 0x808000D0: beql        $at, $zero, L_8080019C
    if (ctx->r1 == 0) {
        // 0x808000D4: lw          $t7, 0x188($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X188);
            goto L_8080019C;
    }
    goto skip_3;
    // 0x808000D4: lw          $t7, 0x188($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X188);
    skip_3:
    // 0x808000D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x808000DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000E0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x808000E4: bnel        $t6, $at, L_80800160
    if (ctx->r14 != ctx->r1) {
        // 0x808000E8: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_80800160;
    }
    goto skip_4;
    // 0x808000E8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x808000EC: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x808000F0: sll         $t8, $v0, 25
    ctx->r24 = S32(ctx->r2 << 25);
    // 0x808000F4: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x808000F8: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x808000FC: bne         $t7, $zero, L_8080015C
    if (ctx->r15 != 0) {
        // 0x80800100: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080015C;
    }
    // 0x80800100: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800104: bne         $t9, $at, L_8080015C
    if (ctx->r25 != ctx->r1) {
        // 0x80800108: srl         $t0, $a0, 23
        ctx->r8 = S32(U32(ctx->r4) >> 23);
            goto L_8080015C;
    }
    // 0x80800108: srl         $t0, $a0, 23
    ctx->r8 = S32(U32(ctx->r4) >> 23);
    // 0x8080010C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800110: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800114: bgez        $t0, L_8080012C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800118: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080012C;
    }
    // 0x80800118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080011C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800120: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800124: nop

    // 0x80800128: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080012C:
    // 0x8080012C: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80800130: lhu         $t2, 0x6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X6);
    // 0x80800134: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80800138: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080013C: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800140: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80800144: bgez        $t3, L_80800158
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800148: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800158;
    }
    // 0x80800148: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080014C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800150: nop

    // 0x80800154: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800158:
    // 0x80800158: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
L_8080015C:
    // 0x8080015C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
L_80800160:
    // 0x80800160: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800164: sw          $s4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r20;
    // 0x80800168: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080016C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800170: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80800174: jal         0x800D7520
    // 0x80800178: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800D7520(rdram, ctx);
        goto after_3;
    // 0x80800178: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8080017C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800184: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800188: jal         0x800C7A68
    // 0x8080018C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800C7A68(rdram, ctx);
        goto after_4;
    // 0x8080018C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_4:
    // 0x80800190: b           L_808002F8
    // 0x80800194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002F8;
    // 0x80800194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800198:
    // 0x80800198: lw          $t7, 0x188($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X188);
L_8080019C:
    // 0x8080019C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808001A0: blezl       $t7, L_808002F8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808001A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808002F8;
    }
    goto skip_5;
    // 0x808001A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
L_808001A8:
    // 0x808001A8: beq         $s1, $s4, L_808002E0
    if (ctx->r17 == ctx->r20) {
        // 0x808001AC: sll         $t8, $s1, 1
        ctx->r24 = S32(ctx->r17 << 1);
            goto L_808002E0;
    }
    // 0x808001AC: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x808001B0: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x808001B4: jal         0x8001B798
    // 0x808001B8: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    func_8001B798(rdram, ctx);
        goto after_5;
    // 0x808001B8: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    after_5:
    // 0x808001BC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x808001C0: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x808001C4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808001C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808001CC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x808001D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808001D4: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x808001D8: srl         $t3, $t2, 21
    ctx->r11 = S32(U32(ctx->r10) >> 21);
    // 0x808001DC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808001E0: beq         $s0, $t3, L_80800214
    if (ctx->r16 == ctx->r11) {
        // 0x808001E4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800214;
    }
    // 0x808001E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808001E8: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x808001EC: beql        $at, $zero, L_80800218
    if (ctx->r1 == 0) {
        // 0x808001F0: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_80800218;
    }
    goto skip_6;
    // 0x808001F0: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    skip_6:
    // 0x808001F4: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
L_808001F8:
    // 0x808001F8: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x808001FC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800200: srl         $t5, $t4, 21
    ctx->r13 = S32(U32(ctx->r12) >> 21);
    // 0x80800204: beql        $s0, $t5, L_80800218
    if (ctx->r16 == ctx->r13) {
        // 0x80800208: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_80800218;
    }
    goto skip_7;
    // 0x80800208: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    skip_7:
    // 0x8080020C: bnel        $at, $zero, L_808001F8
    if (ctx->r1 != 0) {
        // 0x80800210: lw          $t4, 0x24($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X24);
            goto L_808001F8;
    }
    goto skip_8;
    // 0x80800210: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    skip_8:
L_80800214:
    // 0x80800214: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
L_80800218:
    // 0x80800218: beql        $at, $zero, L_808002E4
    if (ctx->r1 == 0) {
        // 0x8080021C: lw          $t7, 0x188($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X188);
            goto L_808002E4;
    }
    goto skip_9;
    // 0x8080021C: lw          $t7, 0x188($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X188);
    skip_9:
    // 0x80800220: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80800224: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800228: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8080022C: bnel        $t6, $at, L_808002A8
    if (ctx->r14 != ctx->r1) {
        // 0x80800230: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_808002A8;
    }
    goto skip_10;
    // 0x80800230: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    skip_10:
    // 0x80800234: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x80800238: sll         $t8, $v0, 25
    ctx->r24 = S32(ctx->r2 << 25);
    // 0x8080023C: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x80800240: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x80800244: bne         $t7, $zero, L_808002A4
    if (ctx->r15 != 0) {
        // 0x80800248: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808002A4;
    }
    // 0x80800248: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080024C: bne         $t9, $at, L_808002A4
    if (ctx->r25 != ctx->r1) {
        // 0x80800250: srl         $t0, $a0, 23
        ctx->r8 = S32(U32(ctx->r4) >> 23);
            goto L_808002A4;
    }
    // 0x80800250: srl         $t0, $a0, 23
    ctx->r8 = S32(U32(ctx->r4) >> 23);
    // 0x80800254: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80800258: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8080025C: bgez        $t0, L_80800274
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800260: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800274;
    }
    // 0x80800260: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800264: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800268: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080026C: nop

    // 0x80800270: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80800274:
    // 0x80800274: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80800278: lhu         $t2, 0x6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X6);
    // 0x8080027C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80800280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800284: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800288: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8080028C: bgez        $t3, L_808002A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800290: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808002A0;
    }
    // 0x80800290: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800298: nop

    // 0x8080029C: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_808002A0:
    // 0x808002A0: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
L_808002A4:
    // 0x808002A4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
L_808002A8:
    // 0x808002A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002AC: sw          $s1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r17;
    // 0x808002B0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808002B4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808002B8: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x808002BC: jal         0x800D7520
    // 0x808002C0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800D7520(rdram, ctx);
        goto after_6;
    // 0x808002C0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x808002C4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808002C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002CC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808002D0: jal         0x800C7A68
    // 0x808002D4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800C7A68(rdram, ctx);
        goto after_7;
    // 0x808002D4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_7:
    // 0x808002D8: b           L_808002F8
    // 0x808002DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002F8;
    // 0x808002DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E0:
    // 0x808002E0: lw          $t7, 0x188($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X188);
L_808002E4:
    // 0x808002E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808002E8: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808002EC: bne         $at, $zero, L_808001A8
    if (ctx->r1 != 0) {
        // 0x808002F0: nop
    
            goto L_808001A8;
    }
    // 0x808002F0: nop

    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800308: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080030C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800310: jr          $ra
    // 0x80800314: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800314: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void chdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080108C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801090: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801094: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801098: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080109C: jal         0x80100094
    // 0x808010A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808010A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808010A4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808010A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808010AC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808010B0: beq         $a3, $at, L_808010E4
    if (ctx->r7 == ctx->r1) {
        // 0x808010B4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_808010E4;
    }
    // 0x808010B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808010B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808010BC: beq         $a3, $at, L_80801178
    if (ctx->r7 == ctx->r1) {
        // 0x808010C0: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80801178;
    }
    // 0x808010C0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808010C4: beq         $a3, $at, L_8080126C
    if (ctx->r7 == ctx->r1) {
        // 0x808010C8: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_8080126C;
    }
    // 0x808010C8: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808010CC: beq         $a3, $at, L_808011D8
    if (ctx->r7 == ctx->r1) {
        // 0x808010D0: addiu       $at, $zero, 0x6F
        ctx->r1 = ADD32(0, 0X6F);
            goto L_808011D8;
    }
    // 0x808010D0: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x808010D4: beql        $a3, $at, L_80801244
    if (ctx->r7 == ctx->r1) {
        // 0x808010D8: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_80801244;
    }
    goto skip_0;
    // 0x808010D8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x808010DC: b           L_80801320
    // 0x808010E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801320;
    // 0x808010E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808010E4:
    // 0x808010E4: beql        $v1, $zero, L_8080113C
    if (ctx->r3 == 0) {
        // 0x808010E8: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_8080113C;
    }
    goto skip_1;
    // 0x808010E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x808010EC: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x808010F0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808010F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808010F8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808010FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801100: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801104: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801108: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8080110C: nop

    // 0x80801110: bc1fl       L_8080113C
    if (!c1cs) {
        // 0x80801114: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_8080113C;
    }
    goto skip_2;
    // 0x80801114: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80801118: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x8080111C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801120: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80801124: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801128: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080112C: jal         0x800868A8
    // 0x80801130: nop

    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801130: nop

    after_1:
    // 0x80801134: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801138: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_8080113C:
    // 0x8080113C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801140: lhu         $v1, 0x72($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X72);
    // 0x80801144: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x80801148: beq         $t8, $at, L_80801168
    if (ctx->r24 == ctx->r1) {
        // 0x8080114C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801168;
    }
    // 0x8080114C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801150: bnel        $t8, $at, L_80801320
    if (ctx->r24 != ctx->r1) {
        // 0x80801154: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801320;
    }
    goto skip_3;
    // 0x80801154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80801158: lbu         $t0, 0x8($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X8);
    // 0x8080115C: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80801160: b           L_8080131C
    // 0x80801164: sb          $t1, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r9;
        goto L_8080131C;
    // 0x80801164: sb          $t1, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r9;
L_80801168:
    // 0x80801168: jal         0x80800754
    // 0x8080116C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800754_chdoor(rdram, ctx);
        goto after_2;
    // 0x8080116C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80801170: b           L_80801320
    // 0x80801174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x80801174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801178:
    // 0x80801178: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8080117C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801180: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80801184: bnel        $t3, $zero, L_80801198
    if (ctx->r11 != 0) {
        // 0x80801188: lhu         $v1, 0x72($a0)
        ctx->r3 = MEM_HU(ctx->r4, 0X72);
            goto L_80801198;
    }
    goto skip_4;
    // 0x80801188: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    skip_4:
    // 0x8080118C: b           L_80801320
    // 0x80801190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801320;
    // 0x80801190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801194: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
L_80801198:
    // 0x80801198: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080119C: srl         $t4, $v1, 10
    ctx->r12 = S32(U32(ctx->r3) >> 10);
    // 0x808011A0: beq         $t4, $at, L_808011B8
    if (ctx->r12 == ctx->r1) {
        // 0x808011A4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808011B8;
    }
    // 0x808011A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808011A8: beq         $t4, $at, L_808011C8
    if (ctx->r12 == ctx->r1) {
        // 0x808011AC: nop
    
            goto L_808011C8;
    }
    // 0x808011AC: nop

    // 0x808011B0: b           L_80801320
    // 0x808011B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x808011B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011B8:
    // 0x808011B8: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x808011BC: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x808011C0: b           L_8080131C
    // 0x808011C4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
        goto L_8080131C;
    // 0x808011C4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
L_808011C8:
    // 0x808011C8: jal         0x808008A0
    // 0x808011CC: nop

    func_808008A0_chdoor(rdram, ctx);
        goto after_3;
    // 0x808011CC: nop

    after_3:
    // 0x808011D0: b           L_80801320
    // 0x808011D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x808011D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011D8:
    // 0x808011D8: lbu         $a0, 0x20($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X20);
    // 0x808011DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808011E0: lbu         $a1, 0x28($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X28);
    // 0x808011E4: beql        $a0, $at, L_80801210
    if (ctx->r4 == ctx->r1) {
        // 0x808011E8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80801210;
    }
    goto skip_5;
    // 0x808011E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_5:
    // 0x808011EC: jal         0x80088840
    // 0x808011F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808011F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_4:
    // 0x808011F4: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x808011F8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080120C;
    }
    // 0x808011F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808011FC: jal         0x80800754
    // 0x80801200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800754_chdoor(rdram, ctx);
        goto after_5;
    // 0x80801200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80801204: b           L_80801320
    // 0x80801208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x80801208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080120C:
    // 0x8080120C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80801210:
    // 0x80801210: beq         $a1, $at, L_80801238
    if (ctx->r5 == ctx->r1) {
        // 0x80801214: nop
    
            goto L_80801238;
    }
    // 0x80801214: nop

    // 0x80801218: jal         0x80088840
    // 0x8080121C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x8080121C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x80801220: beq         $v0, $zero, L_80801238
    if (ctx->r2 == 0) {
        // 0x80801224: nop
    
            goto L_80801238;
    }
    // 0x80801224: nop

    // 0x80801228: jal         0x808008A0
    // 0x8080122C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808008A0_chdoor(rdram, ctx);
        goto after_7;
    // 0x8080122C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80801230: b           L_80801320
    // 0x80801234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801320;
    // 0x80801234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801238:
    // 0x80801238: b           L_80801320
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801320;
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801240: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_80801244:
    // 0x80801244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801248: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8080124C: bne         $t9, $zero, L_8080125C
    if (ctx->r25 != 0) {
        // 0x80801250: nop
    
            goto L_8080125C;
    }
    // 0x80801250: nop

    // 0x80801254: b           L_80801320
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801320;
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080125C:
    // 0x8080125C: jal         0x808013C0
    // 0x80801260: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808013C0_chdoor(rdram, ctx);
        goto after_8;
    // 0x80801260: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80801264: b           L_80801324
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801324;
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080126C:
    // 0x8080126C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80801270: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x80801274: bnel        $t1, $zero, L_80801288
    if (ctx->r9 != 0) {
        // 0x80801278: lbu         $t2, 0x21($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X21);
            goto L_80801288;
    }
    goto skip_6;
    // 0x80801278: lbu         $t2, 0x21($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X21);
    skip_6:
    // 0x8080127C: b           L_80801320
    // 0x80801280: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80801320;
    // 0x80801280: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80801284: lbu         $t2, 0x21($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X21);
L_80801288:
    // 0x80801288: bnel        $v1, $t2, L_808012D0
    if (ctx->r3 != ctx->r10) {
        // 0x8080128C: lbu         $t4, 0x29($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X29);
            goto L_808012D0;
    }
    goto skip_7;
    // 0x8080128C: lbu         $t4, 0x29($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X29);
    skip_7:
    // 0x80801290: lh          $t3, 0x24($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X24);
    // 0x80801294: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801298: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080129C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x808012A0: nop

    // 0x808012A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808012A8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808012AC: jal         0x80085728
    // 0x808012B0: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_9;
    // 0x808012B0: nop

    after_9:
    // 0x808012B4: beq         $v0, $zero, L_8080130C
    if (ctx->r2 == 0) {
        // 0x808012B8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080130C;
    }
    // 0x808012B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012BC: jal         0x80800B14
    // 0x808012C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B14_chdoor(rdram, ctx);
        goto after_10;
    // 0x808012C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808012C4: b           L_80801320
    // 0x808012C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801320;
    // 0x808012C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808012CC: lbu         $t4, 0x29($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X29);
L_808012D0:
    // 0x808012D0: bne         $v1, $t4, L_8080130C
    if (ctx->r3 != ctx->r12) {
        // 0x808012D4: nop
    
            goto L_8080130C;
    }
    // 0x808012D4: nop

    // 0x808012D8: lh          $t5, 0x2C($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2C);
    // 0x808012DC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808012E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808012E4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x808012E8: nop

    // 0x808012EC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808012F0: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808012F4: jal         0x80085728
    // 0x808012F8: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_11;
    // 0x808012F8: nop

    after_11:
    // 0x808012FC: beq         $v0, $zero, L_8080130C
    if (ctx->r2 == 0) {
        // 0x80801300: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080130C;
    }
    // 0x80801300: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801304: jal         0x80800B14
    // 0x80801308: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800B14_chdoor(rdram, ctx);
        goto after_12;
    // 0x80801308: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_12:
L_8080130C:
    // 0x8080130C: b           L_80801320
    // 0x80801310: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801320;
    // 0x80801310: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80801314: b           L_80801320
    // 0x80801318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801320;
    // 0x80801318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080131C:
    // 0x8080131C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801320:
    // 0x80801320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801324:
    // 0x80801324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801328: jr          $ra
    // 0x8080132C: nop

    return;
    // 0x8080132C: nop

;}
RECOMP_FUNC void func_80803EA4_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803EA4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80803EA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803EAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803EB4: jal         0x80100094
    // 0x80803EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803EBC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80803EC0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80803EC4: jal         0x800D8FF8
    // 0x80803EC8: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80803EC8: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    after_1:
    // 0x80803ECC: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80803ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803ED4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80803ED8: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x80803EDC: beq         $t7, $at, L_80803F04
    if (ctx->r15 == ctx->r1) {
        // 0x80803EE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803F04;
    }
    // 0x80803EE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803EE4: beq         $t7, $at, L_80803F14
    if (ctx->r15 == ctx->r1) {
        // 0x80803EE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80803F14;
    }
    // 0x80803EE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803EEC: beq         $t7, $at, L_80803F78
    if (ctx->r15 == ctx->r1) {
        // 0x80803EF0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803F78;
    }
    // 0x80803EF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803EF4: beql        $t7, $at, L_80803F8C
    if (ctx->r15 == ctx->r1) {
        // 0x80803EF8: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_80803F8C;
    }
    goto skip_0;
    // 0x80803EF8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80803EFC: b           L_80803FE0
    // 0x80803F00: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
        goto L_80803FE0;
    // 0x80803F00: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_80803F04:
    // 0x80803F04: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80803F08: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80803F0C: b           L_80803FDC
    // 0x80803F10: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80803FDC;
    // 0x80803F10: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80803F14:
    // 0x80803F14: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80803F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803F1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803F20: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80803F24: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80803F28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X45D4) << 16);
    // 0x80803F2C: lwc1        $f4, 0x45D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X45D4));
    // 0x80803F30: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80803F34: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80803F38: lwc1        $f12, 0x8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80803F3C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80803F40: jal         0x800F15F8
    // 0x80803F44: nop

    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80803F44: nop

    after_2:
    // 0x80803F48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803F4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803F50: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80803F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F58: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80803F5C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    // 0x80803F60: bc1fl       L_80803FE0
    if (!c1cs) {
        // 0x80803F64: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_80803FE0;
    }
    goto skip_1;
    // 0x80803F64: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80803F68: jal         0x808041C4
    // 0x80803F6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808041C4_chweldarboss(rdram, ctx);
        goto after_3;
    // 0x80803F6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80803F70: b           L_80803FE0
    // 0x80803F74: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
        goto L_80803FE0;
    // 0x80803F74: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_80803F78:
    // 0x80803F78: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80803F7C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80803F80: b           L_80803FDC
    // 0x80803F84: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80803FDC;
    // 0x80803F84: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80803F88: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_80803F8C:
    // 0x80803F8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X45D8) << 16);
    // 0x80803F90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803F94: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80803F98: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80803F9C: lwc1        $f10, 0x45D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X45D8));
    // 0x80803FA0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80803FA4: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80803FA8: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80803FAC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80803FB0: jal         0x800F15F8
    // 0x80803FB4: nop

    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x80803FB4: nop

    after_4:
    // 0x80803FB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80803FBC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80803FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FC4: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80803FC8: swc1        $f0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f0.u32l;
    // 0x80803FCC: bc1fl       L_80803FE0
    if (!c1cs) {
        // 0x80803FD0: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_80803FE0;
    }
    goto skip_2;
    // 0x80803FD0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x80803FD4: jal         0x808041C4
    // 0x80803FD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808041C4_chweldarboss(rdram, ctx);
        goto after_5;
    // 0x80803FD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80803FDC:
    // 0x80803FDC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_80803FE0:
    // 0x80803FE0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80803FE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803FE8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803FEC: lwc1        $f12, 0x8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80803FF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803FF4: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x80803FF8: jal         0x800F12D4
    // 0x80803FFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_6;
    // 0x80803FFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80804000: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80804004: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80804008: jal         0x800EE7F8
    // 0x8080400C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080400C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80804010: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80804014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80804018: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080401C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80804020: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80804024: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80804028: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080402C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80804030: jal         0x800EF214
    // 0x80804034: nop

    func_800EF214(rdram, ctx);
        goto after_8;
    // 0x80804034: nop

    after_8:
    // 0x80804038: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8080403C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80804040: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80804044: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804048: lwc1        $f12, 0x8($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8080404C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804050: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x80804054: jal         0x800F12D4
    // 0x80804058: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_9;
    // 0x80804058: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8080405C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80804060: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80804064: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804068: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8080406C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804070: lwc1        $f12, 0x8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80804074: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804078: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x8080407C: jal         0x800F12D4
    // 0x80804080: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_10;
    // 0x80804080: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80804084: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80804088: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
    // 0x8080408C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804090: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80804094: jal         0x800C8FE0
    // 0x80804098: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_11;
    // 0x80804098: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_11:
    // 0x8080409C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808040A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808040A4: jal         0x800C8E54
    // 0x808040A8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800C8E54(rdram, ctx);
        goto after_12;
    // 0x808040A8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x808040AC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808040B0: jal         0x800C8CB8
    // 0x808040B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_13;
    // 0x808040B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x808040B8: jal         0x8001210C
    // 0x808040BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_14;
    // 0x808040BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
    // 0x808040C0: beq         $v0, $zero, L_808040D4
    if (ctx->r2 == 0) {
        // 0x808040C4: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1360, 0X4ABC) << 16);
            goto L_808040D4;
    }
    // 0x808040C4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4ABC) << 16);
    // 0x808040C8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4AC8) << 16);
    // 0x808040CC: b           L_808040D8
    // 0x808040D0: addiu       $a1, $a1, 0x4AC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AC8));
        goto L_808040D8;
    // 0x808040D0: addiu       $a1, $a1, 0x4AC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AC8));
L_808040D4:
    // 0x808040D4: addiu       $a1, $a1, 0x4ABC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4ABC));
L_808040D8:
    // 0x808040D8: jal         0x800C8E84
    // 0x808040DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800C8E84(rdram, ctx);
        goto after_15;
    // 0x808040DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_15:
    // 0x808040E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808040E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808040E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808040EC: jr          $ra
    // 0x808040F0: nop

    return;
    // 0x808040F0: nop

;}
RECOMP_FUNC void func_800F1A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1A90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F1A94: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1A98: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1A9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F1AA0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1AA4: nop

    // 0x800F1AA8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1AAC: jal         0x8002DCA0
    // 0x800F1AB0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1AB0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F1AB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F1AB8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F1ABC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F1AC0: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1AC4: jal         0x80013B70
    // 0x800F1AC8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_80013B70(rdram, ctx);
        goto after_1;
    // 0x800F1AC8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_1:
    // 0x800F1ACC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800F1AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F1AD4: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x800F1AD8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1ADC: jal         0x80013B7C
    // 0x800F1AE0: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x800F1AE0: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    after_2:
    // 0x800F1AE4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800F1AE8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800F1AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1AF4: jr          $ra
    // 0x800F1AF8: nop

    return;
    // 0x800F1AF8: nop

;}
RECOMP_FUNC void func_80802730_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802738: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080273C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802740: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802744: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80802748: jal         0x80100094
    // 0x8080274C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080274C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802750: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802754: lbu         $v1, 0x59($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X59);
    // 0x80802758: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080275C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80802760: beq         $v1, $zero, L_80802780
    if (ctx->r3 == 0) {
        // 0x80802764: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80802780;
    }
    // 0x80802764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802768: beq         $v1, $at, L_80802788
    if (ctx->r3 == ctx->r1) {
        // 0x8080276C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802788;
    }
    // 0x8080276C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802770: beql        $v1, $at, L_808027C8
    if (ctx->r3 == ctx->r1) {
        // 0x80802774: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808027C8;
    }
    goto skip_0;
    // 0x80802774: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80802778: b           L_808027D4
    // 0x8080277C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808027D4;
    // 0x8080277C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802780:
    // 0x80802780: jal         0x800856B0
    // 0x80802784: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802784: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
L_80802788:
    // 0x80802788: jal         0x800856E0
    // 0x8080278C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080278C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80802790: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80802794: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80802798: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(932, 0X2AA0) << 16);
    // 0x8080279C: sb          $t6, 0x59($t7)
    MEM_B(0X59, ctx->r15) = ctx->r14;
    // 0x808027A0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x808027A4: jal         0x80088090
    // 0x808027A8: addiu       $a0, $a0, 0x2AA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(932, 0X2AA0));
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808027A8: addiu       $a0, $a0, 0x2AA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(932, 0X2AA0));
    after_3:
    // 0x808027AC: jal         0x80088098
    // 0x808027B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808027B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808027B4: jal         0x800880A0
    // 0x808027B8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808027B8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x808027BC: jal         0x800880B8
    // 0x808027C0: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808027C0: nop

    after_6:
    // 0x808027C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808027C8:
    // 0x808027C8: jal         0x800856D8
    // 0x808027CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _capod_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x808027CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808027D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808027D4:
    // 0x808027D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808027D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808027DC: jr          $ra
    // 0x808027E0: nop

    return;
    // 0x808027E0: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800724: jal         0x808006A8
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808006A8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080072C: bne         $v0, $zero, L_8080073C
    if (ctx->r2 != 0) {
        // 0x80800730: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080073C;
    }
    // 0x80800730: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800734: b           L_8080074C
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080074C;
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080073C:
    // 0x8080073C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800740: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800748: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8080074C:
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void idflasha_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: jr          $ra
    // 0x8080011C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    return;
    // 0x8080011C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
;}
RECOMP_FUNC void _gcfrontend_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088150: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088150);
    return;
    // 0x80088154: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80801158_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080115C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801160: jal         0x8080101C
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080101C_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080116C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801170: jr          $ra
    // 0x80801174: nop

    return;
    // 0x80801174: nop

;}
RECOMP_FUNC void func_80802614_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802614: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802618: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1608, 0X5178) << 16);
    // 0x8080261C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802620: addiu       $t6, $t6, 0x5178
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1608, 0X5178));
    // 0x80802624: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080262C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802630: jal         0x800BBCB8
    // 0x80802634: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80802634: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80802638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080263C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802640: jr          $ra
    // 0x80802644: nop

    return;
    // 0x80802644: nop

;}
RECOMP_FUNC void func_8080414C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080414C: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x80804150: xori        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 ^ 0XF;
    // 0x80804154: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80804158: bne         $v0, $zero, L_80804168
    if (ctx->r2 != 0) {
        // 0x8080415C: nop
    
            goto L_80804168;
    }
    // 0x8080415C: nop

    // 0x80804160: xori        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 ^ 0X10;
    // 0x80804164: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80804168:
    // 0x80804168: jr          $ra
    // 0x8080416C: nop

    return;
    // 0x8080416C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084278: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084278);
    return;
    // 0x8008427C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_80111A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111AA0: lw          $a1, 0x34($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X34);
    // 0x80111AA4: jal         0x801107F0
    // 0x80111AA8: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80111AA8: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    after_0:
    // 0x80111AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111AB4: jr          $ra
    // 0x80111AB8: nop

    return;
    // 0x80111AB8: nop

;}
RECOMP_FUNC void func_800D3CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3CF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D3CFC: jr          $ra
    // 0x800D3D00: sb          $a0, -0x4C0C($at)
    MEM_B(-0X4C0C, ctx->r1) = ctx->r4;
    return;
    // 0x800D3D00: sb          $a0, -0x4C0C($at)
    MEM_B(-0X4C0C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _sueggmove_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A468: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A468);
    return;
    // 0x8008A46C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800AC100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC100: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x800AC104: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800AC108: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x800AC10C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800AC110: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800AC114: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x800AC118: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800AC11C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800AC120: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800AC124: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800AC128: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800AC12C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800AC130: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800AC134: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800AC138: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800AC13C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800AC140: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800AC144: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800AC148: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800AC14C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800AC150: sw          $a3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r7;
    // 0x800AC154: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800AC158: jal         0x800EFD24
    // 0x800AC15C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800AC15C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800AC160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AC164: lw          $v0, 0x798C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X798C);
    // 0x800AC168: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x800AC16C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AC170: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800AC174: beq         $v1, $t6, L_800AC5EC
    if (ctx->r3 == ctx->r14) {
        // 0x800AC178: sw          $v0, 0x128($sp)
        MEM_W(0X128, ctx->r29) = ctx->r2;
            goto L_800AC5EC;
    }
    // 0x800AC178: sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // 0x800AC17C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AC184: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800AC188: sub.s       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f4.fl;
    // 0x800AC18C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800AC190: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800AC194: addiu       $fp, $sp, 0x100
    ctx->r30 = ADD32(ctx->r29, 0X100);
    // 0x800AC198: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800AC19C: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x800AC1A0: addiu       $s6, $sp, 0x94
    ctx->r22 = ADD32(ctx->r29, 0X94);
    // 0x800AC1A4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800AC1A8: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
L_800AC1AC:
    // 0x800AC1AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC1B0: addiu       $a2, $v1, 0x28
    ctx->r6 = ADD32(ctx->r3, 0X28);
    // 0x800AC1B4: jal         0x800EFB24
    // 0x800AC1B8: sw          $v1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r3;
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800AC1B8: sw          $v1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r3;
    after_1:
    // 0x800AC1BC: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC1C0: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x800AC1C4: jal         0x800EEAA4
    // 0x800AC1C8: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    func_800EEAA4(rdram, ctx);
        goto after_2;
    // 0x800AC1C8: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_2:
    // 0x800AC1CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AC1D0: jal         0x800F2100
    // 0x800AC1D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x800AC1D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800AC1D8: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800AC1DC: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800AC1E0: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800AC1E4: nop

    // 0x800AC1E8: bc1tl       L_800AC5D4
    if (c1cs) {
        // 0x800AC1EC: addiu       $a0, $sp, 0x124
        ctx->r4 = ADD32(ctx->r29, 0X124);
            goto L_800AC5D4;
    }
    goto skip_0;
    // 0x800AC1EC: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
    skip_0:
    // 0x800AC1F0: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x800AC1F4: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AC1F8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC1FC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AC200: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800AC204: lwc1        $f10, 0x1C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800AC208: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800AC20C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800AC210: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AC214: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800AC218: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800AC21C: lwc1        $f10, 0x8($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800AC220: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC224: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AC228: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x800AC22C: jal         0x800F2100
    // 0x800AC230: lwc1        $f12, 0x18($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X18);
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x800AC230: lwc1        $f12, 0x18($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X18);
    after_4:
    // 0x800AC234: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800AC238: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AC23C: jal         0x800F2100
    // 0x800AC240: lwc1        $f12, 0x1C($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X1C);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x800AC240: lwc1        $f12, 0x1C($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X1C);
    after_5:
    // 0x800AC244: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AC248: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800AC24C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800AC250: bc1f        L_800AC260
    if (!c1cs) {
        // 0x800AC254: nop
    
            goto L_800AC260;
    }
    // 0x800AC254: nop

    // 0x800AC258: b           L_800AC260
    // 0x800AC25C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800AC260;
    // 0x800AC25C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AC260:
    // 0x800AC260: jal         0x800F2100
    // 0x800AC264: lwc1        $f12, 0x20($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X20);
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x800AC264: lwc1        $f12, 0x20($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X20);
    after_6:
    // 0x800AC268: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800AC26C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800AC270: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AC274: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AC278: jal         0x800F2100
    // 0x800AC27C: lwc1        $f12, 0x18($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X18);
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x800AC27C: lwc1        $f12, 0x18($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X18);
    after_7:
    // 0x800AC280: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AC284: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x800AC288: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800AC28C: bc1fl       L_800AC29C
    if (!c1cs) {
        // 0x800AC290: addiu       $t3, $s0, 0x1
        ctx->r11 = ADD32(ctx->r16, 0X1);
            goto L_800AC29C;
    }
    goto skip_1;
    // 0x800AC290: addiu       $t3, $s0, 0x1
    ctx->r11 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800AC294: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800AC298: addiu       $t3, $s0, 0x1
    ctx->r11 = ADD32(ctx->r16, 0X1);
L_800AC29C:
    // 0x800AC29C: div         $zero, $t3, $s4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r20)));
    // 0x800AC2A0: mfhi        $v1
    ctx->r3 = hi;
    // 0x800AC2A4: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800AC2A8: addu        $v0, $t5, $t4
    ctx->r2 = ADD32(ctx->r13, ctx->r12);
    // 0x800AC2AC: addu        $t6, $s6, $t4
    ctx->r14 = ADD32(ctx->r22, ctx->r12);
    // 0x800AC2B0: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800AC2B4: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AC2B8: bne         $s4, $zero, L_800AC2C4
    if (ctx->r20 != 0) {
        // 0x800AC2BC: nop
    
            goto L_800AC2C4;
    }
    // 0x800AC2BC: nop

    // 0x800AC2C0: break       7
    do_break(2148188864);
L_800AC2C4:
    // 0x800AC2C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC2C8: bne         $s4, $at, L_800AC2DC
    if (ctx->r20 != ctx->r1) {
        // 0x800AC2CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC2DC;
    }
    // 0x800AC2CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC2D0: bne         $t3, $at, L_800AC2DC
    if (ctx->r11 != ctx->r1) {
        // 0x800AC2D4: nop
    
            goto L_800AC2DC;
    }
    // 0x800AC2D4: nop

    // 0x800AC2D8: break       6
    do_break(2148188888);
L_800AC2DC:
    // 0x800AC2DC: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AC2E0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AC2E4: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800AC2E8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800AC2EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC2F0: jal         0x800EFA4C
    // 0x800AC2F4: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x800AC2F4: nop

    after_8:
    // 0x800AC2F8: addiu       $t7, $s0, 0x2
    ctx->r15 = ADD32(ctx->r16, 0X2);
    // 0x800AC2FC: div         $zero, $t7, $s4
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r20)));
    // 0x800AC300: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800AC304: mfhi        $v1
    ctx->r3 = hi;
    // 0x800AC308: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800AC30C: addu        $t0, $s6, $t8
    ctx->r8 = ADD32(ctx->r22, ctx->r24);
    // 0x800AC310: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800AC314: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AC318: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AC31C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AC320: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800AC324: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800AC328: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AC32C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800AC330: bne         $s4, $zero, L_800AC33C
    if (ctx->r20 != 0) {
        // 0x800AC334: nop
    
            goto L_800AC33C;
    }
    // 0x800AC334: nop

    // 0x800AC338: break       7
    do_break(2148188984);
L_800AC33C:
    // 0x800AC33C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC340: bne         $s4, $at, L_800AC354
    if (ctx->r20 != ctx->r1) {
        // 0x800AC344: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC354;
    }
    // 0x800AC344: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC348: bne         $t7, $at, L_800AC354
    if (ctx->r15 != ctx->r1) {
        // 0x800AC34C: nop
    
            goto L_800AC354;
    }
    // 0x800AC34C: nop

    // 0x800AC350: break       6
    do_break(2148189008);
L_800AC354:
    // 0x800AC354: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AC358: jal         0x800EFA4C
    // 0x800AC35C: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x800AC35C: nop

    after_9:
    // 0x800AC360: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800AC364: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800AC368: lwc1        $f20, 0xC0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800AC36C: lwc1        $f22, 0xB0($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800AC370: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AC374: nop

    // 0x800AC378: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800AC37C: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AC380: c.eq.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl == ctx->f28.fl;
    // 0x800AC384: nop

    // 0x800AC388: bc1t        L_800AC5D0
    if (c1cs) {
        // 0x800AC38C: nop
    
            goto L_800AC5D0;
    }
    // 0x800AC38C: nop

    // 0x800AC390: div.s       $f0, $f26, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f26.fl, ctx->f14.fl);
    // 0x800AC394: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800AC398: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800AC39C: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800AC3A0: nop

    // 0x800AC3A4: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800AC3A8: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800AC3AC: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800AC3B0: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x800AC3B4: nop

    // 0x800AC3B8: bc1f        L_800AC430
    if (!c1cs) {
        // 0x800AC3BC: nop
    
            goto L_800AC430;
    }
    // 0x800AC3BC: nop

    // 0x800AC3C0: c.le.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl <= ctx->f26.fl;
    // 0x800AC3C4: nop

    // 0x800AC3C8: bc1f        L_800AC430
    if (!c1cs) {
        // 0x800AC3CC: nop
    
            goto L_800AC430;
    }
    // 0x800AC3CC: nop

    // 0x800AC3D0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AC3D4: nop

    // 0x800AC3D8: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800AC3DC: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AC3E0: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AC3E4: c.le.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl <= ctx->f2.fl;
    // 0x800AC3E8: nop

    // 0x800AC3EC: bc1f        L_800AC430
    if (!c1cs) {
        // 0x800AC3F0: nop
    
            goto L_800AC430;
    }
    // 0x800AC3F0: nop

    // 0x800AC3F4: c.le.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl <= ctx->f26.fl;
    // 0x800AC3F8: nop

    // 0x800AC3FC: bc1f        L_800AC430
    if (!c1cs) {
        // 0x800AC400: nop
    
            goto L_800AC430;
    }
    // 0x800AC400: nop

    // 0x800AC404: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x800AC408: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC40C: c.le.s      $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f4.fl <= ctx->f26.fl;
    // 0x800AC410: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x800AC414: bc1f        L_800AC430
    if (!c1cs) {
        // 0x800AC418: nop
    
            goto L_800AC430;
    }
    // 0x800AC418: nop

    // 0x800AC41C: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x800AC420: jal         0x800EF04C
    // 0x800AC424: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x800AC424: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    after_10:
    // 0x800AC428: b           L_800AC5D4
    // 0x800AC42C: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
        goto L_800AC5D4;
    // 0x800AC42C: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
L_800AC430:
    // 0x800AC430: mul.s       $f22, $f30, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800AC434: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC438: addiu       $s1, $sp, 0xDC
    ctx->r17 = ADD32(ctx->r29, 0XDC);
L_800AC43C:
    // 0x800AC43C: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AC444: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC448: addu        $a2, $v1, $s2
    ctx->r6 = ADD32(ctx->r3, ctx->r18);
    // 0x800AC44C: jal         0x800EFB24
    // 0x800AC450: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x800AC450: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_11:
    // 0x800AC454: jal         0x800EEFD4
    // 0x800AC458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_12;
    // 0x800AC458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800AC45C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800AC460: nop

    // 0x800AC464: bc1fl       L_800AC48C
    if (!c1cs) {
        // 0x800AC468: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800AC48C;
    }
    goto skip_2;
    // 0x800AC468: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x800AC46C: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC470: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x800AC474: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x800AC478: jal         0x800EF04C
    // 0x800AC47C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x800AC47C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_13:
    // 0x800AC480: b           L_800AC49C
    // 0x800AC484: addiu       $t1, $sp, 0x100
    ctx->r9 = ADD32(ctx->r29, 0X100);
        goto L_800AC49C;
    // 0x800AC484: addiu       $t1, $sp, 0x100
    ctx->r9 = ADD32(ctx->r29, 0X100);
    // 0x800AC488: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_800AC48C:
    // 0x800AC48C: sltu        $at, $s1, $fp
    ctx->r1 = ctx->r17 < ctx->r30 ? 1 : 0;
    // 0x800AC490: bne         $at, $zero, L_800AC43C
    if (ctx->r1 != 0) {
        // 0x800AC494: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_800AC43C;
    }
    // 0x800AC494: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800AC498: addiu       $t1, $sp, 0x100
    ctx->r9 = ADD32(ctx->r29, 0X100);
L_800AC49C:
    // 0x800AC49C: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x800AC4A0: bne         $at, $zero, L_800AC5D0
    if (ctx->r1 != 0) {
        // 0x800AC4A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AC5D0;
    }
    // 0x800AC4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AC4A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC4AC: addiu       $s1, $sp, 0xDC
    ctx->r17 = ADD32(ctx->r29, 0XDC);
    // 0x800AC4B0: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
L_800AC4B4:
    // 0x800AC4B4: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
    // 0x800AC4B8: div         $zero, $s3, $s4
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r20)));
    // 0x800AC4BC: mfhi        $t2
    ctx->r10 = hi;
    // 0x800AC4C0: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC4C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC4C8: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4CC: addu        $a2, $v1, $s2
    ctx->r6 = ADD32(ctx->r3, ctx->r18);
    // 0x800AC4D0: bne         $s4, $zero, L_800AC4DC
    if (ctx->r20 != 0) {
        // 0x800AC4D4: nop
    
            goto L_800AC4DC;
    }
    // 0x800AC4D4: nop

    // 0x800AC4D8: break       7
    do_break(2148189400);
L_800AC4DC:
    // 0x800AC4DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC4E0: bne         $s4, $at, L_800AC4F4
    if (ctx->r20 != ctx->r1) {
        // 0x800AC4E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AC4F4;
    }
    // 0x800AC4E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AC4E8: bne         $s3, $at, L_800AC4F4
    if (ctx->r19 != ctx->r1) {
        // 0x800AC4EC: nop
    
            goto L_800AC4F4;
    }
    // 0x800AC4EC: nop

    // 0x800AC4F0: break       6
    do_break(2148189424);
L_800AC4F4:
    // 0x800AC4F4: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC4F8: addu        $a1, $v1, $t3
    ctx->r5 = ADD32(ctx->r3, ctx->r11);
    // 0x800AC4FC: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x800AC500: jal         0x800EFB24
    // 0x800AC504: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x800AC504: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_14:
    // 0x800AC508: jal         0x800EEFD4
    // 0x800AC50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_15;
    // 0x800AC50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800AC510: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AC514: jal         0x800EF2A0
    // 0x800AC518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_16;
    // 0x800AC518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800AC51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC520: jal         0x800EEAA4
    // 0x800AC524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_17;
    // 0x800AC524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x800AC528: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800AC52C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800AC530: bc1fl       L_800AC5C0
    if (!c1cs) {
        // 0x800AC534: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800AC5C0;
    }
    goto skip_3;
    // 0x800AC534: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    skip_3:
    // 0x800AC538: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800AC53C: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800AC540: nop

    // 0x800AC544: bc1fl       L_800AC5C0
    if (!c1cs) {
        // 0x800AC548: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800AC5C0;
    }
    goto skip_4;
    // 0x800AC548: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    skip_4:
    // 0x800AC54C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AC550: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800AC554: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800AC558: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800AC55C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800AC560: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800AC564: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AC568: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AC56C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800AC570: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AC574: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800AC578: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AC57C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800AC580: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800AC584: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800AC588: jal         0x800EEFD4
    // 0x800AC58C: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    func_800EEFD4(rdram, ctx);
        goto after_18;
    // 0x800AC58C: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x800AC590: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800AC594: nop

    // 0x800AC598: bc1fl       L_800AC5C0
    if (!c1cs) {
        // 0x800AC59C: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800AC5C0;
    }
    goto skip_5;
    // 0x800AC59C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    skip_5:
    // 0x800AC5A0: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC5A4: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x800AC5A8: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x800AC5AC: jal         0x800EF04C
    // 0x800AC5B0: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x800AC5B0: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_19:
    // 0x800AC5B4: b           L_800AC5D4
    // 0x800AC5B8: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
        goto L_800AC5D4;
    // 0x800AC5B8: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
    // 0x800AC5BC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800AC5C0:
    // 0x800AC5C0: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800AC5C4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800AC5C8: bne         $s3, $s4, L_800AC4B4
    if (ctx->r19 != ctx->r20) {
        // 0x800AC5CC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800AC4B4;
    }
    // 0x800AC5CC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800AC5D0:
    // 0x800AC5D0: addiu       $a0, $sp, 0x124
    ctx->r4 = ADD32(ctx->r29, 0X124);
L_800AC5D4:
    // 0x800AC5D4: jal         0x800ABC0C
    // 0x800AC5D8: addiu       $a1, $sp, 0x128
    ctx->r5 = ADD32(ctx->r29, 0X128);
    func_800ABC0C(rdram, ctx);
        goto after_20;
    // 0x800AC5D8: addiu       $a1, $sp, 0x128
    ctx->r5 = ADD32(ctx->r29, 0X128);
    after_20:
    // 0x800AC5DC: lw          $v1, 0x124($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X124);
    // 0x800AC5E0: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x800AC5E4: bnel        $v1, $t4, L_800AC1AC
    if (ctx->r3 != ctx->r12) {
        // 0x800AC5E8: addiu       $a0, $sp, 0xDC
        ctx->r4 = ADD32(ctx->r29, 0XDC);
            goto L_800AC1AC;
    }
    goto skip_6;
    // 0x800AC5E8: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    skip_6:
L_800AC5EC:
    // 0x800AC5EC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800AC5F0: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x800AC5F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800AC5F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800AC5FC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800AC600: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800AC604: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800AC608: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800AC60C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800AC610: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800AC614: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800AC618: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800AC61C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800AC620: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800AC624: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800AC628: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800AC62C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800AC630: jr          $ra
    // 0x800AC634: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x800AC634: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void plsu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "plsu_entrypoint_0");
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800014: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800018: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2515, 0X210) << 16);
    // 0x8080001C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800020: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800028: lwc1        $f20, 0x210($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2515, 0X210));
    // 0x8080002C: jal         0x800F5898
    // 0x80800030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80800034: blez        $v0, L_80800094
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800038: addiu       $s1, $sp, 0x44
        ctx->r17 = ADD32(ctx->r29, 0X44);
            goto L_80800094;
    }
    // 0x80800038: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
L_8080003C:
    // 0x8080003C: jal         0x800F6BE4
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800044: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800080;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x800F5A00
    // 0x80800050: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800058: jal         0x800EEB40
    // 0x8080005C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x8080005C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80800060: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800064: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800068: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080006C: bc1f        L_80800080
    if (!c1cs) {
        // 0x80800070: nop
    
            goto L_80800080;
    }
    // 0x80800070: nop

    // 0x80800074: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800078: jal         0x800EE7F8
    // 0x8080007C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080007C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_4:
L_80800080:
    // 0x80800080: jal         0x800F5898
    // 0x80800084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_5;
    // 0x80800084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_5:
    // 0x80800088: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080008C: bne         $at, $zero, L_8080003C
    if (ctx->r1 != 0) {
        // 0x80800090: nop
    
            goto L_8080003C;
    }
    // 0x80800090: nop

L_80800094:
    // 0x80800094: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800098: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080009C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808000A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808000B0: jr          $ra
    // 0x808000B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808000B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800104_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: jal         0x80100094
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080011C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800120: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800124: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800128: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080012C: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x80800130: beq         $at, $zero, L_80800590
    if (ctx->r1 == 0) {
        // 0x80800134: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800590;
    }
    // 0x80800134: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X2160) << 16);
    // 0x8080013C: addu        $at, $at, $t8
    gpr jr_addend_80800144 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800140: lw          $t8, 0x2160($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(924, 0X2160));
    // 0x80800144: jr          $t8
    // 0x80800148: nop

    switch (jr_addend_80800144 >> 2) {
        case 0: goto L_8080014C; break;
        case 1: goto L_80800164; break;
        case 2: goto L_808001B4; break;
        case 3: goto L_80800228; break;
        case 4: goto L_8080023C; break;
        case 5: goto L_8080029C; break;
        case 6: goto L_80800398; break;
        case 7: goto L_80800408; break;
        case 8: goto L_80800590; break;
        case 9: goto L_80800420; break;
        case 10: goto L_80800478; break;
        case 11: goto L_80800590; break;
        case 12: goto L_808004C4; break;
        case 13: goto L_8080055C; break;
        default: switch_error(__func__, 0x80800144, 0x80802160);
    }
    // 0x80800148: nop

L_8080014C:
    // 0x8080014C: jal         0x80801344
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801344_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800154: jal         0x808012CC
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012CC_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080015C: b           L_80800590
    // 0x80800160: nop

        goto L_80800590;
    // 0x80800160: nop

L_80800164:
    // 0x80800164: jal         0x80801344
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801344_chevilspirit(rdram, ctx);
        goto after_3;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080016C: jal         0x800DB9B0
    // 0x80800170: nop

    func_800DB9B0(rdram, ctx);
        goto after_4;
    // 0x80800170: nop

    after_4:
    // 0x80800174: beq         $v0, $zero, L_80800590
    if (ctx->r2 == 0) {
        // 0x80800178: nop
    
            goto L_80800590;
    }
    // 0x80800178: nop

    // 0x8080017C: jal         0x800DA544
    // 0x80800180: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800180: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_5:
    // 0x80800184: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800188: addiu       $t9, $zero, 0xBB
    ctx->r25 = ADD32(0, 0XBB);
    // 0x8080018C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800190: addiu       $a1, $zero, 0x15CA
    ctx->r5 = ADD32(0, 0X15CA);
    // 0x80800194: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800198: jal         0x8008A208
    // 0x8080019C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080019C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80102424
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808001AC: b           L_80800590
    // 0x808001B0: nop

        goto L_80800590;
    // 0x808001B0: nop

L_808001B4:
    // 0x808001B4: jal         0x80801344
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801344_chevilspirit(rdram, ctx);
        goto after_8;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001BC: jal         0x800D9078
    // 0x808001C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x808001C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_9:
    // 0x808001C4: beq         $v0, $zero, L_80800590
    if (ctx->r2 == 0) {
        // 0x808001C8: nop
    
            goto L_80800590;
    }
    // 0x808001C8: nop

    // 0x808001CC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808001D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808001D4: beq         $a0, $zero, L_808001E8
    if (ctx->r4 == 0) {
        // 0x808001D8: nop
    
            goto L_808001E8;
    }
    // 0x808001D8: nop

    // 0x808001DC: jal         0x800863E8
    // 0x808001E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808001E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x808001E4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_808001E8:
    // 0x808001E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X22B8) << 16);
    // 0x808001EC: addiu       $a1, $a1, 0x22B8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X22B8));
    // 0x808001F0: jal         0x80802090
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802090_chevilspirit(rdram, ctx);
        goto after_11;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001F8: jal         0x80089CA8
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8010A828
    // 0x80800208: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8010A828(rdram, ctx);
        goto after_13;
    // 0x80800208: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_13:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80102424
    // 0x80800214: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800214: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800218: jal         0x800DA524
    // 0x8080021C: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    func_800DA524(rdram, ctx);
        goto after_15;
    // 0x8080021C: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    after_15:
    // 0x80800220: b           L_80800590
    // 0x80800224: nop

        goto L_80800590;
    // 0x80800224: nop

L_80800228:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x801078DC
    // 0x80800230: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    func_801078DC(rdram, ctx);
        goto after_16;
    // 0x80800230: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    after_16:
    // 0x80800234: b           L_80800590
    // 0x80800238: nop

        goto L_80800590;
    // 0x80800238: nop

L_8080023C:
    // 0x8080023C: jal         0x800C9510
    // 0x80800240: nop

    func_800C9510(rdram, ctx);
        goto after_17;
    // 0x80800240: nop

    after_17:
    // 0x80800244: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x80801A6C
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801A6C_chevilspirit(rdram, ctx);
        goto after_18;
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800254: b           L_80800590
    // 0x80800258: nop

        goto L_80800590;
    // 0x80800258: nop

L_8080025C:
    // 0x8080025C: jal         0x80801840
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801840_chevilspirit(rdram, ctx);
        goto after_19;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800264: beql        $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080027C;
    }
    goto skip_0;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080026C: jal         0x80801EC4
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EC4_chevilspirit(rdram, ctx);
        goto after_20;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800274: bne         $v0, $zero, L_8080028C
    if (ctx->r2 != 0) {
        // 0x80800278: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080028C;
    }
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080027C:
    // 0x8080027C: jal         0x80102424
    // 0x80800280: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x80800280: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x80800284: b           L_80800590
    // 0x80800288: nop

        goto L_80800590;
    // 0x80800288: nop

L_8080028C:
    // 0x8080028C: jal         0x808015A4
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808015A4_chevilspirit(rdram, ctx);
        goto after_22;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800294: b           L_80800590
    // 0x80800298: nop

        goto L_80800590;
    // 0x80800298: nop

L_8080029C:
    // 0x8080029C: jal         0x8008FFE8
    // 0x808002A0: nop

    func_8008FFE8(rdram, ctx);
        goto after_23;
    // 0x808002A0: nop

    after_23:
    // 0x808002A4: jal         0x80110014
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_24;
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x808002AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B0: jal         0x80116088
    // 0x808002B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80116088(rdram, ctx);
        goto after_25;
    // 0x808002B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x808002B8: jal         0x800C9510
    // 0x808002BC: nop

    func_800C9510(rdram, ctx);
        goto after_26;
    // 0x808002BC: nop

    after_26:
    // 0x808002C0: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D8;
    }
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: jal         0x80801A6C
    // 0x808002CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801A6C_chevilspirit(rdram, ctx);
        goto after_27;
    // 0x808002CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x808002D0: b           L_80800590
    // 0x808002D4: nop

        goto L_80800590;
    // 0x808002D4: nop

L_808002D8:
    // 0x808002D8: jal         0x80801840
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801840_chevilspirit(rdram, ctx);
        goto after_28;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808002E0: bne         $v0, $zero, L_80800300
    if (ctx->r2 != 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800300;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x80102424
    // 0x808002EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x808002EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_29:
    // 0x808002F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808002F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002F8: b           L_80800590
    // 0x808002FC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_80800590;
    // 0x808002FC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_80800300:
    // 0x80800300: jal         0x80801EC4
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EC4_chevilspirit(rdram, ctx);
        goto after_30;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800308: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x8080030C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80801A6C
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801A6C_chevilspirit(rdram, ctx);
        goto after_31;
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_31:
    // 0x80800318: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x8080031C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X21EC) << 16);
    // 0x80800324: jal         0x80802090
    // 0x80800328: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_32;
    // 0x80800328: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    after_32:
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: jal         0x80102424
    // 0x80800334: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_33;
    // 0x80800334: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_33:
    // 0x80800338: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080033C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800340: b           L_80800590
    // 0x80800344: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_80800590;
    // 0x80800344: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_80800348:
    // 0x80800348: jal         0x808018DC
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018DC_chevilspirit(rdram, ctx);
        goto after_34;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800350: bne         $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X21EC) << 16);
    // 0x8080035C: jal         0x80802090
    // 0x80800360: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_35;
    // 0x80800360: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    after_35:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x80102424
    // 0x8080036C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_36;
    // 0x8080036C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_36:
    // 0x80800370: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800374: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800378: b           L_80800590
    // 0x8080037C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
        goto L_80800590;
    // 0x8080037C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_80800380:
    // 0x80800380: jal         0x80801684
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801684_chevilspirit(rdram, ctx);
        goto after_37;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800388: jal         0x80801398
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801398_chevilspirit(rdram, ctx);
        goto after_38;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800390: b           L_80800590
    // 0x80800394: nop

        goto L_80800590;
    // 0x80800394: nop

L_80800398:
    // 0x80800398: jal         0x8001210C
    // 0x8080039C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_39;
    // 0x8080039C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_39:
    // 0x808003A0: bne         $v0, $zero, L_808003B8
    if (ctx->r2 != 0) {
        // 0x808003A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003B8;
    }
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x808003AC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x808003B0: jal         0x8010297C
    // 0x808003B4: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    func_8010297C(rdram, ctx);
        goto after_40;
    // 0x808003B4: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    after_40:
L_808003B8:
    // 0x808003B8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808003BC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x808003C8: jal         0x80102BF8
    // 0x808003CC: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    func_80102BF8(rdram, ctx);
        goto after_41;
    // 0x808003CC: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    after_41:
    // 0x808003D0: jal         0x800D9078
    // 0x808003D4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_42;
    // 0x808003D4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_42:
    // 0x808003D8: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F8;
    }
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X21EC) << 16);
    // 0x808003E4: jal         0x80802090
    // 0x808003E8: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_43;
    // 0x808003E8: addiu       $a1, $a1, 0x21EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21EC));
    after_43:
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: jal         0x80102424
    // 0x808003F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_44;
    // 0x808003F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_44:
L_808003F8:
    // 0x808003F8: jal         0x808012CC
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012CC_chevilspirit(rdram, ctx);
        goto after_45;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800400: b           L_80800590
    // 0x80800404: nop

        goto L_80800590;
    // 0x80800404: nop

L_80800408:
    // 0x80800408: jal         0x80801534
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801534_chevilspirit(rdram, ctx);
        goto after_46;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80800410: jal         0x808012CC
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012CC_chevilspirit(rdram, ctx);
        goto after_47;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800418: b           L_80800590
    // 0x8080041C: nop

        goto L_80800590;
    // 0x8080041C: nop

L_80800420:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: jal         0x801078DC
    // 0x80800428: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    func_801078DC(rdram, ctx);
        goto after_48;
    // 0x80800428: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    after_48:
    // 0x8080042C: jal         0x80089C90
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_49;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800434: bne         $v0, $zero, L_80800590
    if (ctx->r2 != 0) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800590;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X22C8) << 16);
    // 0x80800440: jal         0x80802090
    // 0x80800444: addiu       $a1, $a1, 0x22C8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X22C8));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_50;
    // 0x80800444: addiu       $a1, $a1, 0x22C8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X22C8));
    after_50:
    // 0x80800448: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: addiu       $a1, $zero, 0x90F
    ctx->r5 = ADD32(0, 0X90F);
    // 0x80800454: jal         0x80103140
    // 0x80800458: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    func_80103140(rdram, ctx);
        goto after_51;
    // 0x80800458: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    after_51:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x80102424
    // 0x80800464: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_52;
    // 0x80800464: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_52:
    // 0x80800468: jal         0x80089CA0
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_53;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80800470: b           L_80800590
    // 0x80800474: nop

        goto L_80800590;
    // 0x80800474: nop

L_80800478:
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x801078DC
    // 0x80800480: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    func_801078DC(rdram, ctx);
        goto after_54;
    // 0x80800480: addiu       $a1, $v1, 0x3C
    ctx->r5 = ADD32(ctx->r3, 0X3C);
    after_54:
    // 0x80800484: jal         0x80089C90
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_55;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x8080048C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800490: bne         $v0, $at, L_80800590
    if (ctx->r2 != ctx->r1) {
        // 0x80800494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800590;
    }
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x80102424
    // 0x8080049C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_56;
    // 0x8080049C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_56:
    // 0x808004A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004A4: addiu       $t1, $zero, 0xBB
    ctx->r9 = ADD32(0, 0XBB);
    // 0x808004A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808004AC: addiu       $a1, $zero, 0x15CB
    ctx->r5 = ADD32(0, 0X15CB);
    // 0x808004B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808004B4: jal         0x8008A208
    // 0x808004B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_57;
    // 0x808004B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_57:
    // 0x808004BC: b           L_80800590
    // 0x808004C0: nop

        goto L_80800590;
    // 0x808004C0: nop

L_808004C4:
    // 0x808004C4: jal         0x800D90A4
    // 0x808004C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_58;
    // 0x808004C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_58:
    // 0x808004CC: jal         0x8010D23C
    // 0x808004D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_8010D23C(rdram, ctx);
        goto after_59;
    // 0x808004D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_59:
    // 0x808004D4: beql        $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004D8: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80800504;
    }
    goto skip_1;
    // 0x808004D8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x808004DC: jal         0x8010CD28
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_60;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x808004E4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808004E8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808004EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x808004F8: jal         0x80102BF8
    // 0x808004FC: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    func_80102BF8(rdram, ctx);
        goto after_61;
    // 0x808004FC: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    after_61:
    // 0x80800500: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_80800504:
    // 0x80800504: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800508: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x8080050C: beq         $t2, $zero, L_80800590
    if (ctx->r10 == 0) {
        // 0x80800510: nop
    
            goto L_80800590;
    }
    // 0x80800510: nop

    // 0x80800514: jal         0x8010CAC0
    // 0x80800518: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_62;
    // 0x80800518: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_62:
    // 0x8080051C: beq         $v0, $zero, L_80800590
    if (ctx->r2 == 0) {
        // 0x80800520: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800590;
    }
    // 0x80800520: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800524: jal         0x800DC128
    // 0x80800528: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_63;
    // 0x80800528: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_63:
    // 0x8080052C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800530: addiu       $t3, $zero, 0xBB
    ctx->r11 = ADD32(0, 0XBB);
    // 0x80800534: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800538: addiu       $a1, $v0, 0x15C6
    ctx->r5 = ADD32(ctx->r2, 0X15C6);
    // 0x8080053C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800540: jal         0x8008A208
    // 0x80800544: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_64;
    // 0x80800544: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_64:
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: jal         0x80102424
    // 0x80800550: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_65;
    // 0x80800550: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_65:
    // 0x80800554: b           L_80800590
    // 0x80800558: nop

        goto L_80800590;
    // 0x80800558: nop

L_8080055C:
    // 0x8080055C: jal         0x8010D23C
    // 0x80800560: nop

    func_8010D23C(rdram, ctx);
        goto after_66;
    // 0x80800560: nop

    after_66:
    // 0x80800564: beq         $v0, $zero, L_80800590
    if (ctx->r2 == 0) {
        // 0x80800568: nop
    
            goto L_80800590;
    }
    // 0x80800568: nop

    // 0x8080056C: jal         0x8010CD28
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_67;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80800574: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800578: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080057C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80800588: jal         0x80102BF8
    // 0x8080058C: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    func_80102BF8(rdram, ctx);
        goto after_68;
    // 0x8080058C: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    after_68:
L_80800590:
    // 0x80800590: jal         0x80801E18
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801E18_chevilspirit(rdram, ctx);
        goto after_69;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80800598: jal         0x80802118
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802118_chevilspirit(rdram, ctx);
        goto after_70;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x808005A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005AC: jr          $ra
    // 0x808005B0: nop

    return;
    // 0x808005B0: nop

;}
RECOMP_FUNC void func_80117248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117248: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8011724C: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80117250: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80117254: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80117258: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8011725C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80117260: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80117264: lw          $fp, 0x4A8C($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X4A8C);
    // 0x80117268: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8011726C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80117270: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80117274: slti        $at, $a2, 0x800
    ctx->r1 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // 0x80117278: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8011727C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80117280: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80117284: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80117288: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8011728C: bne         $at, $zero, L_80117298
    if (ctx->r1 != 0) {
        // 0x80117290: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80117298;
    }
    // 0x80117290: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80117294: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80117298:
    // 0x80117298: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8011729C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x801172A0: addu        $s3, $s3, $a2
    ctx->r19 = ADD32(ctx->r19, ctx->r6);
    // 0x801172A4: subu        $s2, $s2, $a2
    ctx->r18 = SUB32(ctx->r18, ctx->r6);
    // 0x801172A8: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x801172AC: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x801172B0: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x801172B4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x801172B8: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x801172BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801172C0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801172C4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801172C8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801172CC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801172D0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801172D4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801172D8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801172DC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801172E0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801172E4: jal         0x80013324
    // 0x801172E8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80013324(rdram, ctx);
        goto after_0;
    // 0x801172E8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_0:
    // 0x801172EC: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x801172F0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x801172F4: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x801172F8: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x801172FC: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x80117300: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80117304: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80117308: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8011730C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80117310: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80117314: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80117318: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8011731C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80117320: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80117324: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80117328: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8011732C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80117330: beq         $s2, $zero, L_801173F0
    if (ctx->r18 == 0) {
        // 0x80117334: addiu       $sp, $sp, 0x48
        ctx->r29 = ADD32(ctx->r29, 0X48);
            goto L_801173F0;
    }
    // 0x80117334: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80117338: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8011733C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80117340: slti        $at, $a2, 0x800
    ctx->r1 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // 0x80117344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80117348: bne         $at, $zero, L_80117354
    if (ctx->r1 != 0) {
        // 0x8011734C: addiu       $a1, $a1, 0x800
        ctx->r5 = ADD32(ctx->r5, 0X800);
            goto L_80117354;
    }
    // 0x8011734C: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // 0x80117350: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80117354:
    // 0x80117354: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80117358: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x8011735C: addu        $s3, $s3, $a2
    ctx->r19 = ADD32(ctx->r19, ctx->r6);
    // 0x80117360: subu        $s2, $s2, $a2
    ctx->r18 = SUB32(ctx->r18, ctx->r6);
    // 0x80117364: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80117368: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x8011736C: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x80117370: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80117374: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80117378: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8011737C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80117380: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80117384: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80117388: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8011738C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80117390: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80117394: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80117398: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8011739C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801173A0: jal         0x80013224
    // 0x801173A4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80013224(rdram, ctx);
        goto after_1;
    // 0x801173A4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_1:
    // 0x801173A8: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x801173AC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x801173B0: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x801173B4: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x801173B8: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x801173BC: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x801173C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801173C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801173C8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801173CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801173D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x801173D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x801173D8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801173DC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801173E0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801173E4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x801173E8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x801173EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
L_801173F0:
    // 0x801173F0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801173F4: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // 0x801173F8: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x801173FC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80117400: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_80117404:
    // 0x80117404: jal         0x80117448
    // 0x80117408: nop

    func_80117448(rdram, ctx);
        goto after_2;
    // 0x80117408: nop

    after_2:
    // 0x8011740C: bne         $v0, $zero, L_80117404
    if (ctx->r2 != 0) {
        // 0x80117410: nop
    
            goto L_80117404;
    }
    // 0x80117410: nop

    // 0x80117414: jal         0x8001334C
    // 0x80117418: nop

    func_8001334C(rdram, ctx);
        goto after_3;
    // 0x80117418: nop

    after_3:
    // 0x8011741C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80117420: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80117424: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80117428: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8011742C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80117430: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80117434: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80117438: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8011743C: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80117440: jr          $ra
    // 0x80117444: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80117444: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808004FC_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800500: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800504: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800508: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080050C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800510: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800514: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800518: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080051C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800520: jal         0x80800260
    // 0x80800524: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_80800260_subaddiestore(rdram, ctx);
        goto after_0;
    // 0x80800524: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080052C: beq         $v0, $at, L_8080053C
    if (ctx->r2 == ctx->r1) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080053C;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: b           L_80800AB4
    // 0x80800538: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800AB4;
    // 0x80800538: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8080053C:
    // 0x8080053C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800540: jal         0x8001BBA0
    // 0x80800544: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800544: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_1:
    // 0x80800548: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x8080054C: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x80800550: lbu         $t0, 0x73($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X73);
    // 0x80800554: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80800558: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8080055C: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x80800560: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800564: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80800568: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x8080056C: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    // 0x80800570: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
    // 0x80800574: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
    // 0x80800578: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8080057C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80800580: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x80800584: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
    // 0x80800588: sh          $zero, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = 0;
    // 0x8080058C: sb          $t1, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r9;
    // 0x80800590: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x80800594: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80800598: lhu         $t9, 0x9C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X9C);
    // 0x8080059C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808005A0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x808005A4: andi        $t0, $t9, 0xE007
    ctx->r8 = ctx->r25 & 0XE007;
    // 0x808005A8: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x808005AC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808005B0: andi        $t8, $t7, 0x1FF8
    ctx->r24 = ctx->r15 & 0X1FF8;
    // 0x808005B4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808005B8: sh          $t1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r9;
    // 0x808005BC: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x808005C0: lhu         $t6, 0xAC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XAC);
    // 0x808005C4: lhu         $t3, 0x12($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X12);
    // 0x808005C8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x808005CC: srl         $t4, $t3, 1
    ctx->r12 = S32(U32(ctx->r11) >> 1);
    // 0x808005D0: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x808005D4: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x808005D8: sh          $t9, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r25;
    // 0x808005DC: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x808005E0: lbu         $t5, 0x9C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9C);
    // 0x808005E4: lw          $t0, 0x28($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X28);
    // 0x808005E8: andi        $t7, $t5, 0xFFBF
    ctx->r15 = ctx->r13 & 0XFFBF;
    // 0x808005EC: sll         $t1, $t0, 21
    ctx->r9 = S32(ctx->r8 << 21);
    // 0x808005F0: srl         $t3, $t1, 31
    ctx->r11 = S32(U32(ctx->r9) >> 31);
    // 0x808005F4: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x808005F8: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x808005FC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80800600: sb          $t9, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r25;
    // 0x80800604: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80800608: or          $t6, $t9, $zero
    ctx->r14 = ctx->r25 | 0;
    // 0x8080060C: andi        $t7, $t6, 0xDF
    ctx->r15 = ctx->r14 & 0XDF;
    // 0x80800610: lw          $t0, 0x28($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X28);
    // 0x80800614: sll         $t1, $t0, 22
    ctx->r9 = S32(ctx->r8 << 22);
    // 0x80800618: srl         $t3, $t1, 31
    ctx->r11 = S32(U32(ctx->r9) >> 31);
    // 0x8080061C: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80800620: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x80800624: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80800628: jal         0x8010A698
    // 0x8080062C: sb          $t9, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r25;
    func_8010A698(rdram, ctx);
        goto after_2;
    // 0x8080062C: sb          $t9, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r25;
    after_2:
    // 0x80800630: lbu         $t2, 0x9F($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X9F);
    // 0x80800634: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x80800638: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8080063C: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x80800640: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800644: sb          $t4, 0x9F($s0)
    MEM_B(0X9F, ctx->r16) = ctx->r12;
    // 0x80800648: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8080064C: lbu         $t1, 0xAE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XAE);
    // 0x80800650: lw          $t5, 0x28($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X28);
    // 0x80800654: andi        $t3, $t1, 0xFF81
    ctx->r11 = ctx->r9 & 0XFF81;
    // 0x80800658: sll         $t7, $t5, 23
    ctx->r15 = S32(ctx->r13 << 23);
    // 0x8080065C: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x80800660: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80800664: andi        $t2, $t0, 0x7E
    ctx->r10 = ctx->r8 & 0X7E;
    // 0x80800668: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x8080066C: sb          $t8, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r24;
    // 0x80800670: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80800674: andi        $t0, $t8, 0xFE
    ctx->r8 = ctx->r24 & 0XFE;
    // 0x80800678: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8080067C: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80800680: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80800684: sb          $t1, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r9;
    // 0x80800688: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8080068C: lbu         $t7, 0xAF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XAF);
    // 0x80800690: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80800694: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80800698: sll         $t5, $t4, 7
    ctx->r13 = S32(ctx->r12 << 7);
    // 0x8080069C: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x808006A0: sb          $t9, 0xAF($s0)
    MEM_B(0XAF, ctx->r16) = ctx->r25;
    // 0x808006A4: lh          $v1, 0x8C($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X8C);
    // 0x808006A8: beq         $v1, $zero, L_808009AC
    if (ctx->r3 == 0) {
        // 0x808006AC: nop
    
            goto L_808009AC;
    }
    // 0x808006AC: nop

    // 0x808006B0: jal         0x80104248
    // 0x808006B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80104248(rdram, ctx);
        goto after_3;
    // 0x808006B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x808006B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006BC: jal         0x8008B264
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_4;
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808006C4: lhu         $t3, 0x9E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X9E);
    // 0x808006C8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x808006CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006D0: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x808006D4: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x808006D8: jal         0x8008B284
    // 0x808006DC: sh          $t6, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r14;
    anctrl_getPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808006DC: sh          $t6, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r14;
    after_5:
    // 0x808006E0: lbu         $t8, 0x9D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9D);
    // 0x808006E4: andi        $t5, $v0, 0x7
    ctx->r13 = ctx->r2 & 0X7;
    // 0x808006E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006EC: andi        $t9, $t8, 0xFFF8
    ctx->r25 = ctx->r24 & 0XFFF8;
    // 0x808006F0: or          $t0, $t5, $t9
    ctx->r8 = ctx->r13 | ctx->r25;
    // 0x808006F4: jal         0x8008B28C
    // 0x808006F8: sb          $t0, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r8;
    func_8008B28C(rdram, ctx);
        goto after_6;
    // 0x808006F8: sb          $t0, 0x9D($s0)
    MEM_B(0X9D, ctx->r16) = ctx->r8;
    after_6:
    // 0x808006FC: lbu         $t4, 0xAC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XAC);
    // 0x80800700: sll         $t2, $v0, 7
    ctx->r10 = S32(ctx->r2 << 7);
    // 0x80800704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800708: andi        $t6, $t4, 0xFF7F
    ctx->r14 = ctx->r12 & 0XFF7F;
    // 0x8080070C: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x80800710: jal         0x8008B29C
    // 0x80800714: sb          $t7, 0xAC($s0)
    MEM_B(0XAC, ctx->r16) = ctx->r15;
    func_8008B29C(rdram, ctx);
        goto after_7;
    // 0x80800714: sb          $t7, 0xAC($s0)
    MEM_B(0XAC, ctx->r16) = ctx->r15;
    after_7:
    // 0x80800718: lbu         $t0, 0x9C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9C);
    // 0x8080071C: sll         $t9, $v0, 7
    ctx->r25 = S32(ctx->r2 << 7);
    // 0x80800720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800724: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x80800728: or          $t3, $t9, $t1
    ctx->r11 = ctx->r25 | ctx->r9;
    // 0x8080072C: jal         0x8008B2AC
    // 0x80800730: sb          $t3, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r11;
    func_8008B2AC(rdram, ctx);
        goto after_8;
    // 0x80800730: sb          $t3, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r11;
    after_8:
    // 0x80800734: swc1        $f0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f0.u32l;
    // 0x80800738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080073C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800740: jal         0x8008B238
    // 0x80800744: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_8008B238(rdram, ctx);
        goto after_9;
    // 0x80800744: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_9:
    // 0x80800748: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8080074C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800750: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800754: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800758: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080075C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800764: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800768: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8080076C: nop

    // 0x80800770: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800774: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800778: nop

    // 0x8080077C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800780: beql        $t2, $zero, L_808007D0
    if (ctx->r10 == 0) {
        // 0x80800784: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_808007D0;
    }
    goto skip_0;
    // 0x80800784: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80800788: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080078C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800790: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800794: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800798: nop

    // 0x8080079C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808007A0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808007A4: nop

    // 0x808007A8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x808007AC: bne         $t2, $zero, L_808007C4
    if (ctx->r10 != 0) {
        // 0x808007B0: nop
    
            goto L_808007C4;
    }
    // 0x808007B0: nop

    // 0x808007B4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x808007B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808007BC: b           L_808007DC
    // 0x808007C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_808007DC;
    // 0x808007C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_808007C4:
    // 0x808007C4: b           L_808007DC
    // 0x808007C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_808007DC;
    // 0x808007C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x808007CC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_808007D0:
    // 0x808007D0: nop

    // 0x808007D4: bltz        $t2, L_808007C4
    if (SIGNED(ctx->r10) < 0) {
        // 0x808007D8: nop
    
            goto L_808007C4;
    }
    // 0x808007D8: nop

L_808007DC:
    // 0x808007DC: sh          $t2, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r10;
    // 0x808007E0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808007E4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808007E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808007EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808007F0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808007F4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808007F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808007FC: nop

    // 0x80800800: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800804: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800808: nop

    // 0x8080080C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800810: beql        $t7, $zero, L_80800860
    if (ctx->r15 == 0) {
        // 0x80800814: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_80800860;
    }
    goto skip_1;
    // 0x80800814: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80800818: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080081C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800820: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800824: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800828: nop

    // 0x8080082C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800830: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800834: nop

    // 0x80800838: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080083C: bne         $t7, $zero, L_80800854
    if (ctx->r15 != 0) {
        // 0x80800840: nop
    
            goto L_80800854;
    }
    // 0x80800840: nop

    // 0x80800844: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80800848: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080084C: b           L_8080086C
    // 0x80800850: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8080086C;
    // 0x80800850: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800854:
    // 0x80800854: b           L_8080086C
    // 0x80800858: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8080086C;
    // 0x80800858: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080085C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_80800860:
    // 0x80800860: nop

    // 0x80800864: bltz        $t7, L_80800854
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800868: nop
    
            goto L_80800854;
    }
    // 0x80800868: nop

L_8080086C:
    // 0x8080086C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800870: jal         0x8008B2B4
    // 0x80800874: sh          $t7, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = ctx->r15;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_10;
    // 0x80800874: sh          $t7, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = ctx->r15;
    after_10:
    // 0x80800878: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8080087C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800880: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800884: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800888: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080088C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800890: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800894: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800898: nop

    // 0x8080089C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808008A0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808008A4: nop

    // 0x808008A8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808008AC: beql        $t5, $zero, L_808008FC
    if (ctx->r13 == 0) {
        // 0x808008B0: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_808008FC;
    }
    goto skip_2;
    // 0x808008B0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x808008B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808008BC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808008C0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808008C4: nop

    // 0x808008C8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808008CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808008D0: nop

    // 0x808008D4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808008D8: bne         $t5, $zero, L_808008F0
    if (ctx->r13 != 0) {
        // 0x808008DC: nop
    
            goto L_808008F0;
    }
    // 0x808008DC: nop

    // 0x808008E0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x808008E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808008E8: b           L_80800908
    // 0x808008EC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80800908;
    // 0x808008EC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_808008F0:
    // 0x808008F0: b           L_80800908
    // 0x808008F4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80800908;
    // 0x808008F4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808008F8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_808008FC:
    // 0x808008FC: nop

    // 0x80800900: bltz        $t5, L_808008F0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800904: nop
    
            goto L_808008F0;
    }
    // 0x80800904: nop

L_80800908:
    // 0x80800908: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080090C: jal         0x8008B2D4
    // 0x80800910: sh          $t5, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = ctx->r13;
    func_8008B2D4(rdram, ctx);
        goto after_11;
    // 0x80800910: sh          $t5, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = ctx->r13;
    after_11:
    // 0x80800914: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80800918: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080091C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800920: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800924: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800928: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080092C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800930: nop

    // 0x80800934: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800938: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080093C: nop

    // 0x80800940: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800944: beql        $t9, $zero, L_80800994
    if (ctx->r25 == 0) {
        // 0x80800948: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_80800994;
    }
    goto skip_3;
    // 0x80800948: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x8080094C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800950: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800954: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800958: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080095C: nop

    // 0x80800960: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800964: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800968: nop

    // 0x8080096C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800970: bne         $t9, $zero, L_80800988
    if (ctx->r25 != 0) {
        // 0x80800974: nop
    
            goto L_80800988;
    }
    // 0x80800974: nop

    // 0x80800978: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8080097C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800980: b           L_808009A0
    // 0x80800984: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_808009A0;
    // 0x80800984: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800988:
    // 0x80800988: b           L_808009A0
    // 0x8080098C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_808009A0;
    // 0x8080098C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800990: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_80800994:
    // 0x80800994: nop

    // 0x80800998: bltz        $t9, L_80800988
    if (SIGNED(ctx->r25) < 0) {
        // 0x8080099C: nop
    
            goto L_80800988;
    }
    // 0x8080099C: nop

L_808009A0:
    // 0x808009A0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808009A4: sh          $t9, 0xA6($s0)
    MEM_H(0XA6, ctx->r16) = ctx->r25;
    // 0x808009A8: lh          $v1, 0x8C($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X8C);
L_808009AC:
    // 0x808009AC: beq         $v1, $zero, L_808009C4
    if (ctx->r3 == 0) {
        // 0x808009B0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808009C4;
    }
    // 0x808009B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808009B4: lbu         $t3, 0xAE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XAE);
    // 0x808009B8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x808009BC: b           L_808009D0
    // 0x808009C0: sb          $t4, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r12;
        goto L_808009D0;
    // 0x808009C0: sb          $t4, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r12;
L_808009C4:
    // 0x808009C4: lbu         $t2, 0xAE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XAE);
    // 0x808009C8: andi        $t6, $t2, 0xFF7F
    ctx->r14 = ctx->r10 & 0XFF7F;
    // 0x808009CC: sb          $t6, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r14;
L_808009D0:
    // 0x808009D0: sh          $zero, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = 0;
    // 0x808009D4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x808009D8: lw          $t7, 0x7C($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X7C);
    // 0x808009DC: addiu       $s1, $s0, 0xB0
    ctx->r17 = ADD32(ctx->r16, 0XB0);
    // 0x808009E0: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x808009E4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x808009E8: beql        $t8, $zero, L_80800A10
    if (ctx->r24 == 0) {
        // 0x808009EC: lw          $t5, 0x94($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X94);
            goto L_80800A10;
    }
    goto skip_4;
    // 0x808009EC: lw          $t5, 0x94($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X94);
    skip_4:
    // 0x808009F0: jal         0x80105494
    // 0x808009F4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    func_80105494(rdram, ctx);
        goto after_12;
    // 0x808009F4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    after_12:
    // 0x808009F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A00: jal         0x8001BBA0
    // 0x80800A04: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    rare_memcpy(rdram, ctx);
        goto after_13;
    // 0x80800A04: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_13:
    // 0x80800A08: addiu       $s4, $s0, 0x48
    ctx->r20 = ADD32(ctx->r16, 0X48);
    // 0x80800A0C: lw          $t5, 0x94($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X94);
L_80800A10:
    // 0x80800A10: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80800A14: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80800A18: srl         $t9, $t0, 22
    ctx->r25 = S32(U32(ctx->r8) >> 22);
    // 0x80800A1C: beq         $t9, $zero, L_80800A40
    if (ctx->r25 == 0) {
        // 0x80800A20: nop
    
            goto L_80800A40;
    }
    // 0x80800A20: nop

    // 0x80800A24: jal         0x80106F30
    // 0x80800A28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80106F30(rdram, ctx);
        goto after_14;
    // 0x80800A28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_14:
    // 0x80800A2C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800A30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A34: jal         0x8001BBA0
    // 0x80800A38: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_15;
    // 0x80800A38: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_15:
    // 0x80800A3C: addiu       $s4, $s0, 0x18
    ctx->r20 = ADD32(ctx->r16, 0X18);
L_80800A40:
    // 0x80800A40: jal         0x80800F98
    // 0x80800A44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80800F98_subaddiestore(rdram, ctx);
        goto after_16;
    // 0x80800A44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_16:
    // 0x80800A48: beq         $v0, $zero, L_80800AB0
    if (ctx->r2 == 0) {
        // 0x80800A4C: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80800AB0;
    }
    // 0x80800A4C: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x80800A50: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80800A54: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80800A58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80800A5C:
    // 0x80800A5C: lh          $a0, 0x82($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X82);
    // 0x80800A60: beql        $a0, $zero, L_80800A9C
    if (ctx->r4 == 0) {
        // 0x80800A64: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_80800A9C;
    }
    goto skip_5;
    // 0x80800A64: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_5:
    // 0x80800A68: jal         0x8001B7B8
    // 0x80800A6C: nop

    func_8001B7B8(rdram, ctx);
        goto after_17;
    // 0x80800A6C: nop

    after_17:
    // 0x80800A70: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80800A74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A78: jal         0x8001B798
    // 0x80800A7C: lh          $a0, 0x82($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X82);
    func_8001B798(rdram, ctx);
        goto after_18;
    // 0x80800A7C: lh          $a0, 0x82($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X82);
    after_18:
    // 0x80800A80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800A84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A88: jal         0x8001BBA0
    // 0x80800A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    rare_memcpy(rdram, ctx);
        goto after_19;
    // 0x80800A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_19:
    // 0x80800A90: b           L_80800A9C
    // 0x80800A94: addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
        goto L_80800A9C;
    // 0x80800A94: addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // 0x80800A98: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_80800A9C:
    // 0x80800A9C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80800AA0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800AA4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80800AA8: bne         $s3, $at, L_80800A5C
    if (ctx->r19 != ctx->r1) {
        // 0x80800AAC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80800A5C;
    }
    // 0x80800AAC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80800AB0:
    // 0x80800AB0: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80800AB4:
    // 0x80800AB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800ABC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800AC0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800AC8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800ACC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD0: jr          $ra
    // 0x80800AD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800AD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800C78_baduo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C88: jal         0x8008A7A0
    // 0x80800C8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _surestart_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800C8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800C90: jal         0x800A1658
    // 0x80800C94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A1658(rdram, ctx);
        goto after_1;
    // 0x80800C94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA0: jr          $ra
    // 0x80800CA4: nop

    return;
    // 0x80800CA4: nop

;}
RECOMP_FUNC void func_808021BC_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808021BC_chtrashcangame");
    // 0x808021BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808021C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808021D0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808021D4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808021D8: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x808021DC: jal         0x800C6920
    // 0x808021E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_0;
    // 0x808021E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x808021E4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808021E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808021EC: jal         0x800EE7F8
    // 0x808021F0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808021F0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x808021F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021F8: jal         0x80102424
    // 0x808021FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808021FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80802200: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802204: jal         0x800F54E4
    // 0x80802208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80802208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8080220C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802210: jal         0x800F5A00
    // 0x80802214: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x80802214: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80802218: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080221C: jal         0x800F1DF4
    // 0x80802220: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x80802220: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80802224: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80802228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080222C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802234: jr          $ra
    // 0x80802238: nop

    return;
    // 0x80802238: nop

;}
RECOMP_FUNC void func_80102950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102958: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010295C: jal         0x800136E4
    // 0x80102960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x80102960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80102964: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102968: swc1        $f0, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f0.u32l;
    // 0x8010296C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102974: jr          $ra
    // 0x80102978: nop

    return;
    // 0x80102978: nop

;}
