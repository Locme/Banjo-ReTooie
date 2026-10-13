#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chfantasysafe_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087680: syscall     603
    recomp_syscall_handler(rdram, ctx, 0x80087680);
    return;
    // 0x80087684: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C3C: jal         0x8008CABC
    // 0x80800C40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C48: jal         0x8008AF24
    // 0x80800C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C54: jal         0x8008B1A0
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C60: jal         0x8008B188
    // 0x80800C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_3;
    // 0x80800C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: jal         0x8008AED4
    // 0x80800C70: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800C70: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_4:
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x8008B1BC
    // 0x80800C7C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800C7C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: jal         0x8008B134
    // 0x80800C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800C8C: jal         0x8008B064
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C98: jal         0x8008CA4C
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_8;
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800CA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CA4: jal         0x8009D2D8
    // 0x80800CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_9;
    // 0x80800CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800CAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB0: jal         0x8009B9B0
    // 0x80800CB4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800CB4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800CB8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80800CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CC0: jal         0x800FCAE0
    // 0x80800CC4: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    func_800FCAE0(rdram, ctx);
        goto after_11;
    // 0x80800CC4: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_11:
    // 0x80800CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CD4: jr          $ra
    // 0x80800CD8: nop

    return;
    // 0x80800CD8: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080396C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803974: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803978: lh          $t7, 0x172($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X172);
    // 0x8080397C: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80803980: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80803984: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80803988: beq         $t6, $t7, L_808039EC
    if (ctx->r14 == ctx->r15) {
        // 0x8080398C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_808039EC;
    }
    // 0x8080398C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803990: jal         0x808000C4
    // 0x80803994: sh          $zero, 0x140($a0)
    MEM_H(0X140, ctx->r4) = 0;
    func_808000C4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803994: sh          $zero, 0x140($a0)
    MEM_H(0X140, ctx->r4) = 0;
    after_0:
    // 0x80803998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080399C: jal         0x80802B94
    // 0x808039A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80802B94_gczoombox(rdram, ctx);
        goto after_1;
    // 0x808039A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808039A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808039A8: addiu       $a1, $s0, 0x1B7
    ctx->r5 = ADD32(ctx->r16, 0X1B7);
    // 0x808039AC: jal         0x80088420
    // 0x808039B0: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    _gczoomboxdata_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808039B0: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    after_2:
    // 0x808039B4: jal         0x80800000
    // 0x808039B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_gczoombox(rdram, ctx);
        goto after_3;
    // 0x808039B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808039BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039C0: jal         0x80802C80
    // 0x808039C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80802C80_gczoombox(rdram, ctx);
        goto after_4;
    // 0x808039C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808039C8: lbu         $t8, 0x1E6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E6);
    // 0x808039CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808039D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808039D4: andi        $t0, $t8, 0xFFBF
    ctx->r8 = ctx->r24 & 0XFFBF;
    // 0x808039D8: sb          $t0, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r8;
    // 0x808039DC: andi        $t1, $t0, 0xDF
    ctx->r9 = ctx->r8 & 0XDF;
    // 0x808039E0: sh          $s1, 0x172($s0)
    MEM_H(0X172, ctx->r16) = ctx->r17;
    // 0x808039E4: sb          $t1, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r9;
    // 0x808039E8: swc1        $f4, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->f4.u32l;
L_808039EC:
    // 0x808039EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808039F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808039F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808039F8: jr          $ra
    // 0x808039FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808039FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bafpctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800BB8: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800BBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BC8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800BCC: lwc1        $f12, 0x18($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80800BD0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800BD4: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80800BD8: jal         0x800F10B4
    // 0x80800BDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800BDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BE8: jr          $ra
    // 0x80800BEC: nop

    return;
    // 0x80800BEC: nop

;}
RECOMP_FUNC void bamovethrust_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E0: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x808000E4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808000E8: jal         0x80800000
    // 0x808000EC: lw          $a2, 0x8C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8C);
    func_80800000_bamovethrust(rdram, ctx);
        goto after_0;
    // 0x808000EC: lw          $a2, 0x8C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8C);
    after_0:
    // 0x808000F0: lw          $a1, 0xC8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC8);
    // 0x808000F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808000F8: jal         0x800EE7F8
    // 0x808000FC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_1:
    // 0x80800100: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x80800104: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800108: jal         0x800EF334
    // 0x8080010C: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x8080010C: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    after_2:
    // 0x80800110: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x80800114: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800118: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8080011C: jal         0x800EE780
    // 0x80800120: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x80800120: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x80800124: jal         0x800D8FF8
    // 0x80800128: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800128: nop

    after_4:
    // 0x8080012C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x80800130: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800134: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800138: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8080013C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800140: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800144: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800148: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8080014C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x80800150: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800154: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800158: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1fl       L_80800174
    if (!c1cs) {
        // 0x80800164: addiu       $a0, $v0, 0x28
        ctx->r4 = ADD32(ctx->r2, 0X28);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800164: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    skip_0:
    // 0x80800168: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8080016C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x80800170: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
L_80800174:
    // 0x80800174: jal         0x800EFA20
    // 0x80800178: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    func_800EFA20(rdram, ctx);
        goto after_5;
    // 0x80800178: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_5:
    // 0x8080017C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x80800180: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800184: jal         0x800EF04C
    // 0x80800188: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800188: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_6:
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800190: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_808003AC_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808003B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003BC: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808003C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808003C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808003CC: beq         $t6, $zero, L_808003F0
    if (ctx->r14 == 0) {
        // 0x808003D0: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_808003F0;
    }
    // 0x808003D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808003D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D8: beq         $t6, $at, L_80800410
    if (ctx->r14 == ctx->r1) {
        // 0x808003DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800410;
    }
    // 0x808003DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003E0: beql        $t6, $at, L_80800404
    if (ctx->r14 == ctx->r1) {
        // 0x808003E4: lhu         $t7, 0x6E($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X6E);
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003E4: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
    skip_0:
    // 0x808003E8: b           L_80800424
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003F0:
    // 0x808003F0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x808003F4: jal         0x800856B0
    // 0x808003F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808003F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808003FC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800400: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
L_80800404:
    // 0x80800404: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800408: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8080040C: sh          $t9, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r25;
L_80800410:
    // 0x80800410: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800414: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800418: jal         0x800856D0
    // 0x8080041C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080041C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800424:
    // 0x80800424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
RECOMP_FUNC void func_80800730_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800738: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080073C: addiu       $at, $zero, 0x369
    ctx->r1 = ADD32(0, 0X369);
    // 0x80800740: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800744: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800748: bne         $t8, $at, L_80800790
    if (ctx->r24 != ctx->r1) {
        // 0x8080074C: nop
    
            goto L_80800790;
    }
    // 0x8080074C: nop

    // 0x80800750: jal         0x8008A4B8
    // 0x80800754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800758: beq         $v0, $zero, L_80800780
    if (ctx->r2 == 0) {
        // 0x8080075C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800780;
    }
    // 0x8080075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800764: jal         0x80103110
    // 0x80800768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800770: jal         0x80101FDC
    // 0x80800774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800778: b           L_8080079C
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080079C;
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800780:
    // 0x80800780: jal         0x8080023C
    // 0x80800784: nop

    func_8080023C_chlagoonbits(rdram, ctx);
        goto after_3;
    // 0x80800784: nop

    after_3:
    // 0x80800788: b           L_8080079C
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080079C;
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800790:
    // 0x80800790: jal         0x8080023C
    // 0x80800794: nop

    func_8080023C_chlagoonbits(rdram, ctx);
        goto after_4;
    // 0x80800794: nop

    after_4:
    // 0x80800798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080079C:
    // 0x8080079C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A0: jr          $ra
    // 0x808007A4: nop

    return;
    // 0x808007A4: nop

    // 0x808007A8: nop

    // 0x808007AC: nop

;}
RECOMP_FUNC void chbanjoctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1236, 0X1270) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1236, 0X1270));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1236, 0X1270));
;}
RECOMP_FUNC void func_80800000_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800010: jal         0x800CEAA8
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x8080001C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800028;
    }
    // 0x8080001C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800020: beq         $a1, $zero, L_80800038
    if (ctx->r5 == 0) {
        // 0x80800024: nop
    
            goto L_80800038;
    }
    // 0x80800024: nop

L_80800028:
    // 0x80800028: bnel        $v0, $zero, L_80800044
    if (ctx->r2 != 0) {
        // 0x8080002C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800044;
    }
    goto skip_0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800030: beql        $a1, $zero, L_80800044
    if (ctx->r5 == 0) {
        // 0x80800034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800044;
    }
    goto skip_1;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80800038:
    // 0x80800038: jal         0x800CE88C
    // 0x8080003C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CE88C(rdram, ctx);
        goto after_1;
    // 0x8080003C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089908: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089908);
    return;
    // 0x8008990C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_8010E070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010E074: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010E078: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010E07C: addiu       $s1, $s1, 0x7060
    ctx->r17 = ADD32(ctx->r17, 0X7060);
    // 0x8010E080: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010E084: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010E088: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010E08C: jal         0x800B3784
    // 0x8010E090: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800B3784(rdram, ctx);
        goto after_0;
    // 0x8010E090: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_0:
    // 0x8010E094: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010E098: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010E09C: sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // 0x8010E0A0: addiu       $a2, $a2, 0x707C
    ctx->r6 = ADD32(ctx->r6, 0X707C);
    // 0x8010E0A4: addiu       $a1, $a1, 0x7078
    ctx->r5 = ADD32(ctx->r5, 0X7078);
    // 0x8010E0A8: jal         0x800B37A4
    // 0x8010E0AC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800B37A4(rdram, ctx);
        goto after_1;
    // 0x8010E0AC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_1:
    // 0x8010E0B0: lbu         $t6, 0x10($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X10);
    // 0x8010E0B4: bnel        $t6, $zero, L_8010E108
    if (ctx->r14 != 0) {
        // 0x8010E0B8: lbu         $t9, 0x11($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X11);
            goto L_8010E108;
    }
    goto skip_0;
    // 0x8010E0B8: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    skip_0:
    // 0x8010E0BC: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
    // 0x8010E0C0: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x8010E0C4: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8010E0C8: beq         $at, $zero, L_8010E104
    if (ctx->r1 == 0) {
        // 0x8010E0CC: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_8010E104;
    }
    // 0x8010E0CC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010E0D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010E0D4: nop

    // 0x8010E0D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8010E0DC:
    // 0x8010E0DC: jal         0x800192FC
    // 0x8010E0E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800192FC(rdram, ctx);
        goto after_2;
    // 0x8010E0E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8010E0E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010E0E8: jal         0x800EF368
    // 0x8010E0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x8010E0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010E0F0: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x8010E0F4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8010E0F8: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x8010E0FC: bnel        $at, $zero, L_8010E0DC
    if (ctx->r1 != 0) {
        // 0x8010E100: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010E0DC;
    }
    goto skip_1;
    // 0x8010E100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_8010E104:
    // 0x8010E104: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
L_8010E108:
    // 0x8010E108: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010E10C: addiu       $a1, $a1, 0x7064
    ctx->r5 = ADD32(ctx->r5, 0X7064);
    // 0x8010E110: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8010E114: bne         $at, $zero, L_8010E1E4
    if (ctx->r1 != 0) {
        // 0x8010E118: nop
    
            goto L_8010E1E4;
    }
    // 0x8010E118: nop

    // 0x8010E11C: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x8010E120: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8010E124: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010E128: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8010E12C: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8010E130: beql        $at, $zero, L_8010E154
    if (ctx->r1 == 0) {
        // 0x8010E134: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8010E154;
    }
    goto skip_2;
    // 0x8010E134: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
L_8010E138:
    // 0x8010E138: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8010E13C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8010E140: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8010E144: bne         $at, $zero, L_8010E138
    if (ctx->r1 != 0) {
        // 0x8010E148: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8010E138;
    }
    // 0x8010E148: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8010E14C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8010E150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8010E154:
    // 0x8010E154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010E158: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8010E15C: beq         $at, $zero, L_8010E1E4
    if (ctx->r1 == 0) {
        // 0x8010E160: div.s       $f2, $f12, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
            goto L_8010E1E4;
    }
    // 0x8010E160: div.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8010E164: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
L_8010E168:
    // 0x8010E168: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8010E16C: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x8010E170: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8010E174: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8010E178: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8010E17C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8010E180: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8010E184: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010E188: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8010E18C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E190: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010E194: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010E198: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8010E19C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010E1A0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8010E1A4: nop

    // 0x8010E1A8: sw          $t2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->r10;
    // 0x8010E1AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010E1B0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8010E1B4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010E1B8: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8010E1BC: nop

    // 0x8010E1C0: sw          $t5, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r13;
    // 0x8010E1C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010E1C8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8010E1CC: nop

    // 0x8010E1D0: sw          $t8, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r24;
    // 0x8010E1D4: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x8010E1D8: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x8010E1DC: bnel        $at, $zero, L_8010E168
    if (ctx->r1 != 0) {
        // 0x8010E1E0: lwc1        $f6, 0x18($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8010E168;
    }
    goto skip_3;
    // 0x8010E1E0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    skip_3:
L_8010E1E4:
    // 0x8010E1E4: jal         0x800B37B8
    // 0x8010E1E8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800B37B8(rdram, ctx);
        goto after_4;
    // 0x8010E1E8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_4:
    // 0x8010E1EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010E1F0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010E1F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E1F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010E1FC: jr          $ra
    // 0x8010E200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010E200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80096704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009670C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096710: jal         0x800C5B84
    // 0x80096714: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C5B84(rdram, ctx);
        goto after_0;
    // 0x80096714: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009671C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096720: jr          $ra
    // 0x80096724: nop

    return;
    // 0x80096724: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2C8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2C8);
    return;
    // 0x8008A2CC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chloggo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1292, 0X690) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1292, 0X690));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1292, 0X690));
;}
RECOMP_FUNC void func_8080005C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x80099B94
    // 0x80800068: nop

    func_80099B94(rdram, ctx);
        goto after_0;
    // 0x80800068: nop

    after_0:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8080017C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80800180: jr          $ra
    // 0x80800184: lbu         $v0, -0x4BF6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BF6);
    return;
    // 0x80800184: lbu         $v0, -0x4BF6($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BF6);
;}
RECOMP_FUNC void func_80801B3C_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801B48: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80801B4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801B50: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80801B54: bgez        $t9, L_80801B6C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801B58: nop
    
            goto L_80801B6C;
    }
    // 0x80801B58: nop

    // 0x80801B5C: jal         0x80089BD8
    // 0x80801B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80801B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B64: b           L_80801B6C
    // 0x80801B68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80801B6C;
    // 0x80801B68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80801B6C:
    // 0x80801B6C: bne         $v1, $zero, L_80801B88
    if (ctx->r3 != 0) {
        // 0x80801B70: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801B88;
    }
    // 0x80801B70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801B74: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80801B78: jal         0x800D9078
    // 0x80801B7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80801B7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80801B80: beq         $v0, $zero, L_80801B9C
    if (ctx->r2 == 0) {
        // 0x80801B84: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80801B9C;
    }
    // 0x80801B84: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80801B88:
    // 0x80801B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801B90: jal         0x80801160
    // 0x80801B94: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_2;
    // 0x80801B94: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801B98: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80801B9C:
    // 0x80801B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801BA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801BA8: jr          $ra
    // 0x80801BAC: nop

    return;
    // 0x80801BAC: nop

;}
RECOMP_FUNC void func_800A1F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1F10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A1F14: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A1F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1F20: lw          $v0, 0x108($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X108);
    // 0x800A1F24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A1F28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A1F2C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A1F30: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A1F34: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A1F38: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A1F3C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A1F40: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A1F44: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A1F48: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A1F4C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A1F50: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800A1F54: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A1F58: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A1F5C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800A1F60: jal         0x800EFA88
    // 0x800A1F64: nop

    func_800EFA88(rdram, ctx);
        goto after_0;
    // 0x800A1F64: nop

    after_0:
    // 0x800A1F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1F70: jr          $ra
    // 0x800A1F74: nop

    return;
    // 0x800A1F74: nop

;}
RECOMP_FUNC void chexploder_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801A88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A8C: jal         0x80100094
    // 0x80801A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A98: lhu         $a2, 0x16($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X16);
    // 0x80801A9C: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
    // 0x80801AA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801AA4: jal         0x80103140
    // 0x80801AA8: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80801AA8: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    after_1:
    // 0x80801AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AB4: jr          $ra
    // 0x80801AB8: nop

    return;
    // 0x80801AB8: nop

    // 0x80801ABC: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866A8: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866A8);
    return;
    // 0x800866AC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_8001E7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001E7A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E7A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001E7AC: jr          $ra
    // 0x8001E7B0: lw          $v0, -0x16A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16A4);
    return;
    // 0x8001E7B0: lw          $v0, -0x16A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16A4);
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089208: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089208);
    return;
    // 0x8008920C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800B5E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B5E40: lw          $a0, -0x7E80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7E80);
    // 0x800B5E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5E4C: beql        $a0, $zero, L_800B5E68
    if (ctx->r4 == 0) {
        // 0x800B5E50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B5E68;
    }
    goto skip_0;
    // 0x800B5E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B5E54: jal         0x800B2F58
    // 0x800B5E58: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800B5E58: nop

    after_0:
    // 0x800B5E5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B5E60: sw          $v0, -0x7E80($at)
    MEM_W(-0X7E80, ctx->r1) = ctx->r2;
    // 0x800B5E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B5E68:
    // 0x800B5E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5E6C: jr          $ra
    // 0x800B5E70: nop

    return;
    // 0x800B5E70: nop

;}
RECOMP_FUNC void func_800B5A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5A6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B5A70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B5A74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B5A78: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B5A7C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B5A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5A84: addiu       $s1, $s1, -0x7EBC
    ctx->r17 = ADD32(ctx->r17, -0X7EBC);
    // 0x800B5A88: addiu       $s0, $s0, 0x7F34
    ctx->r16 = ADD32(ctx->r16, 0X7F34);
    // 0x800B5A8C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800B5A90:
    // 0x800B5A90: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800B5A94: beql        $t7, $zero, L_800B5AB8
    if (ctx->r15 == 0) {
        // 0x800B5A98: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B5AB8;
    }
    goto skip_0;
    // 0x800B5A98: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800B5A9C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800B5AA0: beql        $a0, $zero, L_800B5AB8
    if (ctx->r4 == 0) {
        // 0x800B5AA4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B5AB8;
    }
    goto skip_1;
    // 0x800B5AA4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x800B5AA8: jal         0x800B5548
    // 0x800B5AAC: nop

    func_800B5548(rdram, ctx);
        goto after_0;
    // 0x800B5AAC: nop

    after_0:
    // 0x800B5AB0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800B5AB4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800B5AB8:
    // 0x800B5AB8: bnel        $s0, $s1, L_800B5A90
    if (ctx->r16 != ctx->r17) {
        // 0x800B5ABC: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800B5A90;
    }
    goto skip_2;
    // 0x800B5ABC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x800B5AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5AC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B5AC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B5ACC: jr          $ra
    // 0x800B5AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B5AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800CA6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA6C4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CA6C8: swc1        $f12, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f12.u32l;
    // 0x800CA6CC: jr          $ra
    // 0x800CA6D0: swc1        $f14, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800CA6D0: swc1        $f14, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void _gcmapsects_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F50: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F50);
    return;
    // 0x80087F54: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800C10_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C14: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800C18: slti        $at, $a1, 0x7F
    ctx->r1 = SIGNED(ctx->r5) < 0X7F ? 1 : 0;
    // 0x80800C1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C20: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800C24: bne         $at, $zero, L_80800C40
    if (ctx->r1 != 0) {
        // 0x80800C28: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80800C40;
    }
    // 0x80800C28: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800C2C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800C30: beql        $a1, $at, L_80800E74
    if (ctx->r5 == ctx->r1) {
        // 0x80800C34: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_80800E74;
    }
    goto skip_0;
    // 0x80800C34: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800C38: b           L_80800ED0
    // 0x80800C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800ED0;
    // 0x80800C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C40:
    // 0x80800C40: slti        $at, $a1, 0x3F
    ctx->r1 = SIGNED(ctx->r5) < 0X3F ? 1 : 0;
    // 0x80800C44: bne         $at, $zero, L_80800C60
    if (ctx->r1 != 0) {
        // 0x80800C48: addiu       $t6, $a1, -0x13
        ctx->r14 = ADD32(ctx->r5, -0X13);
            goto L_80800C60;
    }
    // 0x80800C48: addiu       $t6, $a1, -0x13
    ctx->r14 = ADD32(ctx->r5, -0X13);
    // 0x80800C4C: addiu       $at, $zero, 0x7E
    ctx->r1 = ADD32(0, 0X7E);
    // 0x80800C50: beql        $a1, $at, L_80800E34
    if (ctx->r5 == ctx->r1) {
        // 0x80800C54: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800E34;
    }
    goto skip_1;
    // 0x80800C54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x80800C58: b           L_80800ED0
    // 0x80800C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800ED0;
    // 0x80800C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C60:
    // 0x80800C60: sltiu       $at, $t6, 0x2C
    ctx->r1 = ctx->r14 < 0X2C ? 1 : 0;
    // 0x80800C64: beq         $at, $zero, L_80800EC4
    if (ctx->r1 == 0) {
        // 0x80800C68: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800EC4;
    }
    // 0x80800C68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800C6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11FC) << 16);
    // 0x80800C70: addu        $at, $at, $t6
    gpr jr_addend_80800C78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800C74: lw          $t6, 0x11FC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11FC));
    // 0x80800C78: jr          $t6
    // 0x80800C7C: nop

    switch (jr_addend_80800C78 >> 2) {
        case 0: goto L_80800DF4; break;
        case 1: goto L_80800E60; break;
        case 2: goto L_80800EC4; break;
        case 3: goto L_80800EC4; break;
        case 4: goto L_80800EC4; break;
        case 5: goto L_80800EC4; break;
        case 6: goto L_80800EC4; break;
        case 7: goto L_80800EC4; break;
        case 8: goto L_80800EC4; break;
        case 9: goto L_80800EC4; break;
        case 10: goto L_80800EC4; break;
        case 11: goto L_80800EC4; break;
        case 12: goto L_80800EC4; break;
        case 13: goto L_80800EC4; break;
        case 14: goto L_80800EC4; break;
        case 15: goto L_80800EC4; break;
        case 16: goto L_80800EC4; break;
        case 17: goto L_80800EC4; break;
        case 18: goto L_80800EC4; break;
        case 19: goto L_80800EC4; break;
        case 20: goto L_80800EC4; break;
        case 21: goto L_80800EC4; break;
        case 22: goto L_80800C80; break;
        case 23: goto L_80800CC0; break;
        case 24: goto L_80800EC4; break;
        case 25: goto L_80800EC4; break;
        case 26: goto L_80800EC4; break;
        case 27: goto L_80800EC4; break;
        case 28: goto L_80800EC4; break;
        case 29: goto L_80800EC4; break;
        case 30: goto L_80800EC4; break;
        case 31: goto L_80800EC4; break;
        case 32: goto L_80800EC4; break;
        case 33: goto L_80800EC4; break;
        case 34: goto L_80800EC4; break;
        case 35: goto L_80800EC4; break;
        case 36: goto L_80800EC4; break;
        case 37: goto L_80800EC4; break;
        case 38: goto L_80800EC4; break;
        case 39: goto L_80800EC4; break;
        case 40: goto L_80800EC4; break;
        case 41: goto L_80800EC4; break;
        case 42: goto L_80800EC4; break;
        case 43: goto L_80800CD4; break;
        default: switch_error(__func__, 0x80800C78, 0x808011FC);
    }
    // 0x80800C7C: nop

L_80800C80:
    // 0x80800C80: jal         0x808000DC
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000DC_chjinjo(rdram, ctx);
        goto after_0;
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800C88: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800C8C: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800C90: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: jal         0x800897C0
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800CA0: jal         0x80089828
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800CA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CAC: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800CB0: jal         0x800897E8
    // 0x80800CB4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800CB4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_3:
    // 0x80800CB8: b           L_80800ED0
    // 0x80800CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800ED0;
    // 0x80800CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CC0:
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC4: jal         0x800897C8
    // 0x80800CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800CCC: b           L_80800ED0
    // 0x80800CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800ED0;
    // 0x80800CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CD4:
    // 0x80800CD4: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800CD8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80800CDC: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800CE0: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80800CE4: beql        $at, $zero, L_80800ED0
    if (ctx->r1 == 0) {
        // 0x80800CE8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800ED0;
    }
    goto skip_2;
    // 0x80800CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800CEC: lhu         $a1, 0x1A($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X1A);
    // 0x80800CF0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF8: srl         $t0, $a1, 5
    ctx->r8 = S32(U32(ctx->r5) >> 5);
    // 0x80800CFC: jal         0x8010A6B0
    // 0x80800D00: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8010A6B0(rdram, ctx);
        goto after_5;
    // 0x80800D00: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_5:
    // 0x80800D04: beql        $v0, $zero, L_80800ED0
    if (ctx->r2 == 0) {
        // 0x80800D08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800ED0;
    }
    goto skip_3;
    // 0x80800D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800D0C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800D10: andi        $t1, $a0, 0x1FF
    ctx->r9 = ctx->r4 & 0X1FF;
    // 0x80800D14: jal         0x800D0CC8
    // 0x80800D18: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_6;
    // 0x80800D18: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_6:
    // 0x80800D1C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1672, 0X1324) << 16);
    // 0x80800D20: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800D24: addiu       $a2, $a2, 0x1324
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X1324));
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: jal         0x80089D18
    // 0x80800D30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800D30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D38: jal         0x80102424
    // 0x80800D3C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800D3C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D44: jal         0x8008A4B0
    // 0x80800D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800D4C: jal         0x8010A570
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800D54: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80800D58: jal         0x800DA9E4
    // 0x80800D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_11;
    // 0x80800D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800D60: bnel        $v0, $zero, L_80800D9C
    if (ctx->r2 != 0) {
        // 0x80800D64: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_80800D9C;
    }
    goto skip_4;
    // 0x80800D64: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_4:
    // 0x80800D68: jal         0x808000DC
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000DC_chjinjo(rdram, ctx);
        goto after_12;
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D70: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80800D74: addiu       $t2, $t2, 0x6BA0
    ctx->r10 = ADD32(ctx->r10, 0X6BA0);
    // 0x80800D78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800D7C: addiu       $a0, $zero, 0xCDA
    ctx->r4 = ADD32(0, 0XCDA);
    // 0x80800D80: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800D8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800D90: jal         0x800C05B8
    // 0x80800D94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800C05B8(rdram, ctx);
        goto after_13;
    // 0x80800D94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_13:
    // 0x80800D98: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_80800D9C:
    // 0x80800D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DA0: andi        $t3, $a0, 0x1FF
    ctx->r11 = ctx->r4 & 0X1FF;
    // 0x80800DA4: jal         0x800D0BD4
    // 0x80800DA8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800D0BD4(rdram, ctx);
        goto after_14;
    // 0x80800DA8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_14:
    // 0x80800DAC: jal         0x800D1338
    // 0x80800DB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800D1338(rdram, ctx);
        goto after_15;
    // 0x80800DB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x80800DB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800DB8: jal         0x800D129C
    // 0x80800DBC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800D129C(rdram, ctx);
        goto after_16;
    // 0x80800DBC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x80800DC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800DC4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800DC8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800DCC: jal         0x800D24E8
    // 0x80800DD0: addiu       $a0, $a0, 0xE1
    ctx->r4 = ADD32(ctx->r4, 0XE1);
    func_800D24E8(rdram, ctx);
        goto after_17;
    // 0x80800DD0: addiu       $a0, $a0, 0xE1
    ctx->r4 = ADD32(ctx->r4, 0XE1);
    after_17:
    // 0x80800DD4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: lhu         $a1, 0x1A($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X1A);
    // 0x80800DE0: srl         $t5, $a1, 5
    ctx->r13 = S32(U32(ctx->r5) >> 5);
    // 0x80800DE4: jal         0x80801098
    // 0x80800DE8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_80801098_chjinjo(rdram, ctx);
        goto after_18;
    // 0x80800DE8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_18:
    // 0x80800DEC: b           L_80800ED0
    // 0x80800DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800ED0;
    // 0x80800DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DF4:
    // 0x80800DF4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800DF8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800DFC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800E00: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800E04: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800E08: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800E0C: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800E10: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x80800E14: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80800E18: bnel        $t3, $at, L_80800ED0
    if (ctx->r11 != ctx->r1) {
        // 0x80800E1C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800ED0;
    }
    goto skip_5;
    // 0x80800E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80800E20: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x80800E24: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80800E28: b           L_80800ECC
    // 0x80800E2C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
        goto L_80800ECC;
    // 0x80800E2C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    // 0x80800E30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800E34:
    // 0x80800E34: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800E38: addiu       $a0, $zero, 0x4D6
    ctx->r4 = ADD32(0, 0X4D6);
    // 0x80800E3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800E40: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800E44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800E48: bc1fl       L_80800ED0
    if (!c1cs) {
        // 0x80800E4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800ED0;
    }
    goto skip_6;
    // 0x80800E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_6:
    // 0x80800E50: jal         0x80108A30
    // 0x80800E54: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_80108A30(rdram, ctx);
        goto after_19;
    // 0x80800E54: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_19:
    // 0x80800E58: b           L_80800ED0
    // 0x80800E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800ED0;
    // 0x80800E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E60:
    // 0x80800E60: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E64: ori         $t8, $t9, 0x10
    ctx->r24 = ctx->r25 | 0X10;
    // 0x80800E68: b           L_80800ECC
    // 0x80800E6C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800ECC;
    // 0x80800E6C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800E70: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_80800E74:
    // 0x80800E74: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800E78: sll         $t0, $v0, 11
    ctx->r8 = S32(ctx->r2 << 11);
    // 0x80800E7C: srl         $t1, $t0, 20
    ctx->r9 = S32(U32(ctx->r8) >> 20);
    // 0x80800E80: bne         $t1, $at, L_80800E98
    if (ctx->r9 != ctx->r1) {
        // 0x80800E84: nop
    
            goto L_80800E98;
    }
    // 0x80800E84: nop

    // 0x80800E88: jal         0x808001A0
    // 0x80800E8C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    chjinjo_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x80800E8C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_20:
    // 0x80800E90: b           L_80800EA4
    // 0x80800E94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800EA4;
    // 0x80800E94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800E98:
    // 0x80800E98: jal         0x800D0CC8
    // 0x80800E9C: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    func_800D0CC8(rdram, ctx);
        goto after_21;
    // 0x80800E9C: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    after_21:
    // 0x80800EA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800EA4:
    // 0x80800EA4: addiu       $a2, $v1, 0xC31
    ctx->r6 = ADD32(ctx->r3, 0XC31);
    // 0x80800EA8: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x80800EAC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB4: jal         0x80103140
    // 0x80800EB8: addiu       $a1, $zero, 0x643
    ctx->r5 = ADD32(0, 0X643);
    func_80103140(rdram, ctx);
        goto after_22;
    // 0x80800EB8: addiu       $a1, $zero, 0x643
    ctx->r5 = ADD32(0, 0X643);
    after_22:
    // 0x80800EBC: b           L_80800ED0
    // 0x80800EC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800ED0;
    // 0x80800EC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EC4:
    // 0x80800EC4: b           L_80800ED0
    // 0x80800EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800ED0;
    // 0x80800EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800ECC:
    // 0x80800ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ED0:
    // 0x80800ED0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ED4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800ED8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800EDC: jr          $ra
    // 0x80800EE0: nop

    return;
    // 0x80800EE0: nop

;}
RECOMP_FUNC void chfireimp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1348, 0X1F8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1348, 0X1F8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1348, 0X1F8));
;}
RECOMP_FUNC void _chexploder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086668: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086668);
    return;
    // 0x8008666C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80020E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E74: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80020E78: beq         $t6, $zero, L_80020E8C
    if (ctx->r14 == 0) {
        // 0x80020E7C: nop
    
            goto L_80020E8C;
    }
    // 0x80020E7C: nop

    // 0x80020E80: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80020E84: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80020E88: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80020E8C:
    // 0x80020E8C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80020E90: beq         $t9, $zero, L_80020EA4
    if (ctx->r25 == 0) {
        // 0x80020E94: nop
    
            goto L_80020EA4;
    }
    // 0x80020E94: nop

    // 0x80020E98: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80020E9C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80020EA0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_80020EA4:
    // 0x80020EA4: jr          $ra
    // 0x80020EA8: nop

    return;
    // 0x80020EA8: nop

;}
RECOMP_FUNC void _capod_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085740: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085740);
    return;
    // 0x80085744: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800BCF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCF90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCF94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCF98: jal         0x800BCCD8
    // 0x800BCF9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    static_16_800BCCD8(rdram, ctx);
        goto after_0;
    // 0x800BCF9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800BCFA0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCFA4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BCFA8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800BCFAC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800BCFB0: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800BCFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCFB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCFBC: jr          $ra
    // 0x800BCFC0: nop

    return;
    // 0x800BCFC0: nop

;}
RECOMP_FUNC void _capod_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856C8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856C8);
    return;
    // 0x800856CC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080000C_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80102424
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800024: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800028: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x8080002C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800030: beq         $at, $zero, L_808000D0
    if (ctx->r1 == 0) {
        // 0x80800034: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808000D0;
    }
    // 0x80800034: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC20) << 16);
    // 0x8080003C: addu        $at, $at, $t8
    gpr jr_addend_80800044 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800040: lw          $t8, 0xC20($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC20));
    // 0x80800044: jr          $t8
    // 0x80800048: nop

    switch (jr_addend_80800044 >> 2) {
        case 0: goto L_80800060; break;
        case 1: goto L_8080004C; break;
        case 2: goto L_80800070; break;
        case 3: goto L_808000D0; break;
        case 4: goto L_80800094; break;
        case 5: goto L_808000A8; break;
        default: switch_error(__func__, 0x80800044, 0x80800C20);
    }
    // 0x80800048: nop

L_8080004C:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x8008A4B0
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800058: b           L_808000D4
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000D4;
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: jal         0x800DA544
    // 0x80800064: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    after_2:
    // 0x80800068: b           L_808000D4
    // 0x8080006C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000D4;
    // 0x8080006C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800070:
    // 0x80800070: jal         0x800DA544
    // 0x80800074: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_3:
    // 0x80800078: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800080: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800084: jal         0x80085708
    // 0x80800088: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    after_4:
    // 0x8080008C: b           L_808000D4
    // 0x80800090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000D4;
    // 0x80800090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800094:
    // 0x80800094: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800098: nop

    // 0x8080009C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808000A0: b           L_808000D0
    // 0x808000A4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
        goto L_808000D0;
    // 0x808000A4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_808000A8:
    // 0x808000A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1696, 0XCF0) << 16);
    // 0x808000AC: addiu       $a2, $a2, 0xCF0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1696, 0XCF0));
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80089D18
    // 0x808000B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808000B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808000BC: jal         0x800DA544
    // 0x808000C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808000C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_6:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80108B04
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_808000D0:
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D4:
    // 0x808000D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_800A819C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A819C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A81A0: lh          $v1, 0x7632($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X7632);
    // 0x800A81A4: xori        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 ^ 0X3;
    // 0x800A81A8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A81AC: bne         $v0, $zero, L_800A81BC
    if (ctx->r2 != 0) {
        // 0x800A81B0: nop
    
            goto L_800A81BC;
    }
    // 0x800A81B0: nop

    // 0x800A81B4: xori        $v0, $v1, 0x5
    ctx->r2 = ctx->r3 ^ 0X5;
    // 0x800A81B8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800A81BC:
    // 0x800A81BC: jr          $ra
    // 0x800A81C0: nop

    return;
    // 0x800A81C0: nop

;}
RECOMP_FUNC void func_80110CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110CC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110CC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80110CCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80110CD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80110CD4: jal         0x8011539C
    // 0x80110CD8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8011539C(rdram, ctx);
        goto after_0;
    // 0x80110CD8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80110CDC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80110CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80110CE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80110CE8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80110CEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80110CF0: jal         0x80115D08
    // 0x80110CF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80115D08(rdram, ctx);
        goto after_1;
    // 0x80110CF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80110CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80110CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80110D00: jr          $ra
    // 0x80110D04: nop

    return;
    // 0x80110D04: nop

;}
RECOMP_FUNC void func_800B2540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B2548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B254C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B2550: lhu         $t6, 0x16($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X16);
    // 0x800B2554: addiu       $s1, $a0, 0x18
    ctx->r17 = ADD32(ctx->r4, 0X18);
    // 0x800B2558: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B255C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800B2560: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800B2564: addu        $a3, $t8, $a0
    ctx->r7 = ADD32(ctx->r24, ctx->r4);
    // 0x800B2568: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x800B256C: sltu        $at, $s1, $a3
    ctx->r1 = ctx->r17 < ctx->r7 ? 1 : 0;
    // 0x800B2570: beq         $at, $zero, L_800B25B0
    if (ctx->r1 == 0) {
        // 0x800B2574: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_800B25B0;
    }
    // 0x800B2574: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800B2578: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800B257C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2580:
    // 0x800B2580: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B2584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B2588:
    // 0x800B2588: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800B258C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B2590: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2594: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B2598: bne         $v0, $a1, L_800B2588
    if (ctx->r2 != ctx->r5) {
        // 0x800B259C: sb          $t9, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r25;
            goto L_800B2588;
    }
    // 0x800B259C: sb          $t9, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r25;
    // 0x800B25A0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800B25A4: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x800B25A8: bnel        $at, $zero, L_800B2580
    if (ctx->r1 != 0) {
        // 0x800B25AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B2580;
    }
    goto skip_0;
    // 0x800B25AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800B25B0:
    // 0x800B25B0: subu        $a1, $a3, $s1
    ctx->r5 = SUB32(ctx->r7, ctx->r17);
    // 0x800B25B4: sra         $t0, $a1, 4
    ctx->r8 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B25B8: sll         $a1, $t0, 4
    ctx->r5 = S32(ctx->r8 << 4);
    // 0x800B25BC: jal         0x8002E660
    // 0x800B25C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800B25C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800B25C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B25C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B25CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B25D0: jr          $ra
    // 0x800B25D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B25D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _anseq_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082660: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082660);
    return;
    // 0x80082664: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bsbanpackwhack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D8: jal         0x8008CABC
    // 0x808001DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808001E0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808001E4: jal         0x8008E078
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001EC: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001F0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(37, 0X4B4) << 16);
            goto L_80800224;
    }
    // 0x808001F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(37, 0X4B4) << 16);
    // 0x808001F4: lwc1        $f6, 0x4B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(37, 0X4B4));
    // 0x808001F8: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808001FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800200: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800204: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800208: jal         0x800F0E00
    // 0x8080020C: nop

    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x8080020C: nop

    after_2:
    // 0x80800210: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800214: jal         0x800F1574
    // 0x80800218: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    func_800F1574(rdram, ctx);
        goto after_3;
    // 0x80800218: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    after_3:
    // 0x8080021C: b           L_80800254
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800254;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800224:
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(37, 0X4B8) << 16);
    // 0x80800228: lwc1        $f10, 0x4B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(37, 0X4B8));
    // 0x8080022C: lwc1        $f8, 0x16C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800230: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800234: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800238: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080023C: jal         0x800F0E00
    // 0x80800240: nop

    func_800F0E00(rdram, ctx);
        goto after_4;
    // 0x80800240: nop

    after_4:
    // 0x80800244: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800248: jal         0x800F1574
    // 0x8080024C: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    func_800F1574(rdram, ctx);
        goto after_5;
    // 0x8080024C: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    after_5:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800254:
    // 0x80800254: jal         0x8009B9B0
    // 0x80800258: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800258: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
    // 0x8080025C: lui         $a1, 0x3E6B
    ctx->r5 = S32(0X3E6B << 16);
    // 0x80800260: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800264: jal         0x8008B348
    // 0x80800268: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800268: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8080026C: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800270: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800280;
    }
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: addiu       $a1, $zero, 0x587
    ctx->r5 = ADD32(0, 0X587);
    // 0x80800278: jal         0x8009DE38
    // 0x8080027C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_8;
    // 0x8080027C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
L_80800280:
    // 0x80800280: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800284: jal         0x8008B348
    // 0x80800288: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80800288: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_9:
    // 0x8080028C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800298: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080029C: jal         0x8009DF94
    // 0x808002A0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_10;
    // 0x808002A0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_10:
L_808002A4:
    // 0x808002A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808002A8: jal         0x8008B348
    // 0x808002AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x808002AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_11:
    // 0x808002B0: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808002B4: lui         $a2, 0x3F4C
        ctx->r6 = S32(0X3F4C << 16);
            goto L_808002CC;
    }
    // 0x808002B4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808002B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x808002C4: jal         0x8009DF94
    // 0x808002C8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_12;
    // 0x808002C8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_12:
L_808002CC:
    // 0x808002CC: jal         0x80084508
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_13;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002D8: bnel        $v0, $at, L_80800338
    if (ctx->r2 != ctx->r1) {
        // 0x808002DC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800338;
    }
    goto skip_0;
    // 0x808002DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x808002E0: jal         0x8008B2B4
    // 0x808002E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_14;
    // 0x808002E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_14:
    // 0x808002E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(37, 0X4BC) << 16);
    // 0x808002EC: lwc1        $f16, 0x4BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(37, 0X4BC));
    // 0x808002F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(37, 0X4C0) << 16);
    // 0x808002F4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808002F8: nop

    // 0x808002FC: bc1fl       L_80800338
    if (!c1cs) {
        // 0x80800300: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800338;
    }
    goto skip_1;
    // 0x80800300: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80800304: lwc1        $f18, 0x4C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(37, 0X4C0));
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800310: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800314: nop

    // 0x80800318: bc1fl       L_80800338
    if (!c1cs) {
        // 0x8080031C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800338;
    }
    goto skip_2;
    // 0x8080031C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x80800320: jal         0x80084518
    // 0x80800324: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _babackpack_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800324: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x80800074
    // 0x80800330: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80800074_bsbanpackwhack(rdram, ctx);
        goto after_16;
    // 0x80800330: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_16:
    // 0x80800334: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800338:
    // 0x80800338: lwc1        $f4, 0x170($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X170);
    // 0x8080033C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800340: nop

    // 0x80800344: bc1tl       L_80800388
    if (c1cs) {
        // 0x80800348: lui         $a1, 0x3E28
        ctx->r5 = S32(0X3E28 << 16);
            goto L_80800388;
    }
    goto skip_3;
    // 0x80800348: lui         $a1, 0x3E28
    ctx->r5 = S32(0X3E28 << 16);
    skip_3:
    // 0x8080034C: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800358: jal         0x8009E55C
    // 0x8080035C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_8009E55C(rdram, ctx);
        goto after_17;
    // 0x8080035C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_17:
    // 0x80800360: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800364: addiu       $a2, $a2, 0x4510
    ctx->r6 = ADD32(ctx->r6, 0X4510);
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x8009E4E0
    // 0x80800370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E4E0(rdram, ctx);
        goto after_18;
    // 0x80800370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080037C: jal         0x8009E5A4
    // 0x80800380: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8009E5A4(rdram, ctx);
        goto after_19;
    // 0x80800380: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x80800384: lui         $a1, 0x3E28
    ctx->r5 = S32(0X3E28 << 16);
L_80800388:
    // 0x80800388: ori         $a1, $a1, 0xDB8C
    ctx->r5 = ctx->r5 | 0XDB8C;
    // 0x8080038C: jal         0x8008B348
    // 0x80800390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isAt(rdram, ctx);
        goto after_20;
    // 0x80800390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_20:
    // 0x80800394: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003CC;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x80095760
    // 0x808003A0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    baflag_set(rdram, ctx);
        goto after_21;
    // 0x808003A0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_21:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x80084538
    // 0x808003AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babackpack_set_state(rdram, ctx);
        goto after_22;
    // 0x808003AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x800A0CD0
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_23;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x808003BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003C4: nop

    // 0x808003C8: swc1        $f6, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f6.u32l;
L_808003CC:
    // 0x808003CC: lui         $a1, 0x3F53
    ctx->r5 = S32(0X3F53 << 16);
    // 0x808003D0: ori         $a1, $a1, 0x1F8A
    ctx->r5 = ctx->r5 | 0X1F8A;
    // 0x808003D4: jal         0x8008B348
    // 0x808003D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isAt(rdram, ctx);
        goto after_24;
    // 0x808003D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_24:
    // 0x808003DC: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808003E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800414;
    }
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: jal         0x80095774
    // 0x808003E8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    baflag_clear(rdram, ctx);
        goto after_25;
    // 0x808003E8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_25:
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003F4: jal         0x8009E4E0
    // 0x808003F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_26;
    // 0x808003F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_26:
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: jal         0x80084538
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_27;
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x800A0CD0
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_28;
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
L_80800414:
    // 0x80800414: lui         $a1, 0x3F31
    ctx->r5 = S32(0X3F31 << 16);
    // 0x80800418: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x8080041C: jal         0x8008B348
    // 0x80800420: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isAt(rdram, ctx);
        goto after_29;
    // 0x80800420: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
    // 0x80800424: beq         $v0, $zero, L_80800434
    if (ctx->r2 == 0) {
        // 0x80800428: nop
    
            goto L_80800434;
    }
    // 0x80800428: nop

    // 0x8080042C: jal         0x8009BC90
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_30;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_80800434:
    // 0x80800434: jal         0x8008B324
    // 0x80800438: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isStopped(rdram, ctx);
        goto after_31;
    // 0x80800438: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_31:
    // 0x8080043C: beq         $v0, $zero, L_80800448
    if (ctx->r2 == 0) {
        // 0x80800440: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800448;
    }
    // 0x80800440: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800444: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80800448:
    // 0x80800448: jal         0x8008E35C
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_32;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800450: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800454: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800460;
    }
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $t7, $zero, 0x4C
    ctx->r15 = ADD32(0, 0X4C);
    // 0x8080045C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_80800460:
    // 0x80800460: jal         0x80091A58
    // 0x80800464: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_33;
    // 0x80800464: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_33:
    // 0x80800468: beql        $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800480;
    }
    goto skip_4;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800470: jal         0x8009FE84
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_34;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800478: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800480:
    // 0x80800480: jal         0x8009E5C8
    // 0x80800484: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_35;
    // 0x80800484: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_35:
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080048C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800490: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800494: jr          $ra
    // 0x80800498: nop

    return;
    // 0x80800498: nop

;}
RECOMP_FUNC void chlavagargoyle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2324, 0XD7C) << 16);
    // 0x808006E4: jr          $ra
    // 0x808006E8: addiu       $v0, $v0, 0xD7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2324, 0XD7C));
    return;
    // 0x808006E8: addiu       $v0, $v0, 0xD7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2324, 0XD7C));
;}
RECOMP_FUNC void bsmum_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800790: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1160) << 16);
    // 0x80800794: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800798: jr          $ra
    // 0x8080079C: lw          $v0, 0x1160($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1160));
    return;
    // 0x8080079C: lw          $v0, 0x1160($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1160));
;}
RECOMP_FUNC void basudie_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E4: jal         0x8008E35C
    // 0x808004E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x808004E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004EC: beq         $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800504;
    }
    // 0x808004F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004F4: jal         0x8009BCC4
    // 0x808004F8: lui         $a1, 0xC37A
    ctx->r5 = S32(0XC37A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x808004F8: lui         $a1, 0xC37A
    ctx->r5 = S32(0XC37A << 16);
    after_1:
    // 0x808004FC: b           L_80800510
    // 0x80800500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800510;
    // 0x80800500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800504:
    // 0x80800504: jal         0x8009BC90
    // 0x80800508: nop

    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800508: nop

    after_2:
    // 0x8080050C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800510:
    // 0x80800510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800514: jr          $ra
    // 0x80800518: nop

    return;
    // 0x80800518: nop

    // 0x8080051C: nop

;}
RECOMP_FUNC void chglowbo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801198: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1628, 0X15D0) << 16);
    // 0x8080119C: jr          $ra
    // 0x808011A0: addiu       $v0, $v0, 0x15D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X15D0));
    return;
    // 0x808011A0: addiu       $v0, $v0, 0x15D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X15D0));
;}
RECOMP_FUNC void _chfloaty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087720: syscall     612
    recomp_syscall_handler(rdram, ctx, 0x80087720);
    return;
    // 0x80087724: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DD728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD728: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800DD72C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DD730: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800DD734: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800DD738: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800DD73C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800DD740: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800DD744: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800DD748: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DD74C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DD750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DD754: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800DD758: lh          $t6, 0x2C($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2C);
    // 0x800DD75C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800DD760: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800DD764: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x800DD768: jal         0x80018BA8
    // 0x800DD76C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    mlMtx_get_stack_pointer(rdram, ctx);
        goto after_0;
    // 0x800DD76C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DD770: jal         0x80018BB4
    // 0x800DD774: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    func_80018BB4(rdram, ctx);
        goto after_1;
    // 0x800DD774: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_1:
    // 0x800DD778: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x800DD77C: jal         0x80018C28
    // 0x800DD780: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_2;
    // 0x800DD780: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    after_2:
    // 0x800DD784: lh          $v0, 0x2E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2E);
    // 0x800DD788: beq         $v0, $zero, L_800DD7C8
    if (ctx->r2 == 0) {
        // 0x800DD78C: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800DD7C8;
    }
    // 0x800DD78C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800DD790: beq         $t8, $zero, L_800DD7C8
    if (ctx->r24 == 0) {
        // 0x800DD794: nop
    
            goto L_800DD7C8;
    }
    // 0x800DD794: nop

    // 0x800DD798: lh          $a2, 0x20($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X20);
    // 0x800DD79C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800DD7A0: beql        $a2, $zero, L_800DD7B4
    if (ctx->r6 == 0) {
        // 0x800DD7A4: lh          $a2, 0x14($s2)
        ctx->r6 = MEM_H(ctx->r18, 0X14);
            goto L_800DD7B4;
    }
    goto skip_0;
    // 0x800DD7A4: lh          $a2, 0x14($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X14);
    skip_0:
    // 0x800DD7A8: jal         0x8010F070
    // 0x800DD7AC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8010F070(rdram, ctx);
        goto after_3;
    // 0x800DD7AC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x800DD7B0: lh          $a2, 0x14($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X14);
L_800DD7B4:
    // 0x800DD7B4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DD7B8: beq         $a2, $zero, L_800DD7C8
    if (ctx->r6 == 0) {
        // 0x800DD7BC: nop
    
            goto L_800DD7C8;
    }
    // 0x800DD7BC: nop

    // 0x800DD7C0: jal         0x8010F070
    // 0x800DD7C4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8010F070(rdram, ctx);
        goto after_4;
    // 0x800DD7C4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_4:
L_800DD7C8:
    // 0x800DD7C8: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800DD7CC: addiu       $s6, $s6, -0x313C
    ctx->r22 = ADD32(ctx->r22, -0X313C);
    // 0x800DD7D0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800DD7D4: beql        $v0, $zero, L_800DD81C
    if (ctx->r2 == 0) {
        // 0x800DD7D8: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800DD81C;
    }
    goto skip_1;
    // 0x800DD7D8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_1:
    // 0x800DD7DC: lh          $a2, 0x20($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X20);
    // 0x800DD7E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800DD7E4: beql        $a2, $zero, L_800DD7F8
    if (ctx->r6 == 0) {
        // 0x800DD7E8: lh          $a2, 0x14($s2)
        ctx->r6 = MEM_H(ctx->r18, 0X14);
            goto L_800DD7F8;
    }
    goto skip_2;
    // 0x800DD7E8: lh          $a2, 0x14($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X14);
    skip_2:
    // 0x800DD7EC: jalr        $v0
    // 0x800DD7F0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x800DD7F0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x800DD7F4: lh          $a2, 0x14($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X14);
L_800DD7F8:
    // 0x800DD7F8: addiu       $s5, $sp, 0x6C
    ctx->r21 = ADD32(ctx->r29, 0X6C);
    // 0x800DD7FC: beql        $a2, $zero, L_800DD81C
    if (ctx->r6 == 0) {
        // 0x800DD800: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800DD81C;
    }
    goto skip_3;
    // 0x800DD800: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_3:
    // 0x800DD804: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800DD808: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DD80C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DD810: jalr        $t9
    // 0x800DD814: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x800DD814: nop

    after_6:
    // 0x800DD818: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800DD81C:
    // 0x800DD81C: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800DD820: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800DD824: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800DD828: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x800DD82C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800DD830: lh          $t2, 0x8($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X8);
    // 0x800DD834: lw          $t4, -0x36A0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X36A0);
    // 0x800DD838: addiu       $s5, $sp, 0x6C
    ctx->r21 = ADD32(ctx->r29, 0X6C);
    // 0x800DD83C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800DD840: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800DD844: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800DD848: jal         0x8002E330
    // 0x800DD84C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800DD84C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_7:
    // 0x800DD850: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800DD854: lh          $t5, 0xA($s2)
    ctx->r13 = MEM_H(ctx->r18, 0XA);
    // 0x800DD858: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800DD85C: addiu       $s1, $s2, 0x2
    ctx->r17 = ADD32(ctx->r18, 0X2);
    // 0x800DD860: beq         $t5, $zero, L_800DD95C
    if (ctx->r13 == 0) {
        // 0x800DD864: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_800DD95C;
    }
    // 0x800DD864: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800DD868: lh          $v0, 0x2E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2E);
L_800DD86C:
    // 0x800DD86C: beq         $v0, $zero, L_800DD8AC
    if (ctx->r2 == 0) {
        // 0x800DD870: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800DD8AC;
    }
    // 0x800DD870: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800DD874: beql        $t6, $zero, L_800DD8B0
    if (ctx->r14 == 0) {
        // 0x800DD878: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_800DD8B0;
    }
    goto skip_4;
    // 0x800DD878: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800DD87C: lh          $a2, 0x20($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X20);
    // 0x800DD880: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800DD884: beql        $a2, $zero, L_800DD898
    if (ctx->r6 == 0) {
        // 0x800DD888: lh          $a2, 0x14($s1)
        ctx->r6 = MEM_H(ctx->r17, 0X14);
            goto L_800DD898;
    }
    goto skip_5;
    // 0x800DD888: lh          $a2, 0x14($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X14);
    skip_5:
    // 0x800DD88C: jal         0x8010F070
    // 0x800DD890: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8010F070(rdram, ctx);
        goto after_8;
    // 0x800DD890: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_8:
    // 0x800DD894: lh          $a2, 0x14($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X14);
L_800DD898:
    // 0x800DD898: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DD89C: beql        $a2, $zero, L_800DD8B0
    if (ctx->r6 == 0) {
        // 0x800DD8A0: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_800DD8B0;
    }
    goto skip_6;
    // 0x800DD8A0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_6:
    // 0x800DD8A4: jal         0x8010F070
    // 0x800DD8A8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8010F070(rdram, ctx);
        goto after_9;
    // 0x800DD8A8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_9:
L_800DD8AC:
    // 0x800DD8AC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_800DD8B0:
    // 0x800DD8B0: beql        $v0, $zero, L_800DD8F4
    if (ctx->r2 == 0) {
        // 0x800DD8B4: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800DD8F4;
    }
    goto skip_7;
    // 0x800DD8B4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_7:
    // 0x800DD8B8: lh          $a2, 0x20($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X20);
    // 0x800DD8BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800DD8C0: beql        $a2, $zero, L_800DD8D4
    if (ctx->r6 == 0) {
        // 0x800DD8C4: lh          $a2, 0x14($s1)
        ctx->r6 = MEM_H(ctx->r17, 0X14);
            goto L_800DD8D4;
    }
    goto skip_8;
    // 0x800DD8C4: lh          $a2, 0x14($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X14);
    skip_8:
    // 0x800DD8C8: jalr        $v0
    // 0x800DD8CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x800DD8CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_10:
    // 0x800DD8D0: lh          $a2, 0x14($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X14);
L_800DD8D4:
    // 0x800DD8D4: beql        $a2, $zero, L_800DD8F4
    if (ctx->r6 == 0) {
        // 0x800DD8D8: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800DD8F4;
    }
    goto skip_9;
    // 0x800DD8D8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_9:
    // 0x800DD8DC: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800DD8E0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DD8E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DD8E8: jalr        $t9
    // 0x800DD8EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800DD8EC: nop

    after_11:
    // 0x800DD8F0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800DD8F4:
    // 0x800DD8F4: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800DD8F8: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800DD8FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800DD900: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800DD904: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800DD908: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x800DD90C: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800DD910: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DD914: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800DD918: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800DD91C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800DD920: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x800DD924: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800DD928: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x800DD92C: lw          $t5, -0x36A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X36A0);
    // 0x800DD930: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800DD934: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800DD938: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800DD93C: jal         0x8002E330
    // 0x800DD940: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_12;
    // 0x800DD940: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_12:
    // 0x800DD944: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800DD948: lh          $t6, 0xA($s3)
    ctx->r14 = MEM_H(ctx->r19, 0XA);
    // 0x800DD94C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800DD950: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800DD954: bnel        $t6, $zero, L_800DD86C
    if (ctx->r14 != 0) {
        // 0x800DD958: lh          $v0, 0x2E($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X2E);
            goto L_800DD86C;
    }
    goto skip_10;
    // 0x800DD958: lh          $v0, 0x2E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2E);
    skip_10:
L_800DD95C:
    // 0x800DD95C: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x800DD960: addiu       $t7, $t9, 0x40
    ctx->r15 = ADD32(ctx->r25, 0X40);
    // 0x800DD964: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x800DD968: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD96C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800DD970: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800DD974: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800DD978: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD97C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800DD980: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800DD984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DD988: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD98C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DD990: jr          $ra
    // 0x800DD994: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800DD994: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800A98_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A9C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800AA0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80800AA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800AAC: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80800AB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AB4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800AB8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800ABC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x800EFA4C
    // 0x80800AC8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800AC8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80800ACC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x800EF9A8
    // 0x80800ADC: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    func_800EF9A8(rdram, ctx);
        goto after_1;
    // 0x80800ADC: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    after_1:
    // 0x80800AE0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x800EF8BC
    // 0x80800AF0: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    func_800EF8BC(rdram, ctx);
        goto after_2;
    // 0x80800AF0: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x80800AF4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B00: jal         0x800EF934
    // 0x80800B04: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    func_800EF934(rdram, ctx);
        goto after_3;
    // 0x80800B04: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    after_3:
    // 0x80800B08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B0C: jal         0x800EF04C
    // 0x80800B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B20: jr          $ra
    // 0x80800B24: nop

    return;
    // 0x80800B24: nop

;}
RECOMP_FUNC void func_8080129C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080129C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808012A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012A8: jal         0x800D8FF8
    // 0x808012AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808012AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808012B0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808012B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B8: jal         0x80100094
    // 0x808012BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808012BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808012C0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808012C4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808012C8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808012CC: bgez        $t8, L_8080130C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808012D0: nop
    
            goto L_8080130C;
    }
    // 0x808012D0: nop

    // 0x808012D4: lbu         $t9, 0x85($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X85);
    // 0x808012D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808012E0: bne         $t9, $at, L_80801300
    if (ctx->r25 != ctx->r1) {
        // 0x808012E4: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_80801300;
    }
    // 0x808012E4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808012E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808012EC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808012F0: jal         0x8008A0E0
    // 0x808012F4: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808012F4: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    after_2:
    // 0x808012F8: b           L_8080130C
    // 0x808012FC: nop

        goto L_8080130C;
    // 0x808012FC: nop

L_80801300:
    // 0x80801300: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801304: jal         0x8008A0E0
    // 0x80801308: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801308: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    after_3:
L_8080130C:
    // 0x8080130C: jal         0x8010D23C
    // 0x80801310: nop

    func_8010D23C(rdram, ctx);
        goto after_4;
    // 0x80801310: nop

    after_4:
    // 0x80801314: beql        $v0, $zero, L_8080133C
    if (ctx->r2 == 0) {
        // 0x80801318: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080133C;
    }
    goto skip_0;
    // 0x80801318: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080131C: jal         0x8010D278
    // 0x80801320: nop

    func_8010D278(rdram, ctx);
        goto after_5;
    // 0x80801320: nop

    after_5:
    // 0x80801324: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80801328: beql        $v0, $at, L_8080133C
    if (ctx->r2 == ctx->r1) {
        // 0x8080132C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080133C;
    }
    goto skip_1;
    // 0x8080132C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80801330: jal         0x8010D254
    // 0x80801334: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_8010D254(rdram, ctx);
        goto after_6;
    // 0x80801334: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_6:
    // 0x80801338: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_8080133C:
    // 0x8080133C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801340: jal         0x800F1DF4
    // 0x80801344: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F1DF4(rdram, ctx);
        goto after_7;
    // 0x80801344: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x80801348: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080134C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801350: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801354: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x80801358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080135C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80801360: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801368: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8080136C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801370: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801374: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80801378: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080137C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801380: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80801384: jal         0x8008FB10
    // 0x80801388: nop

    func_8008FB10(rdram, ctx);
        goto after_8;
    // 0x80801388: nop

    after_8:
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801390: jal         0x80100094
    // 0x80801394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80801394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80801398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080139C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808013A0: jal         0x800897D8
    // 0x808013A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x808013A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808013A8: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808013AC: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808013B0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808013B4: sltiu       $at, $t2, 0x14
    ctx->r1 = ctx->r10 < 0X14 ? 1 : 0;
    // 0x808013B8: beq         $at, $zero, L_808022AC
    if (ctx->r1 == 0) {
        // 0x808013BC: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808022AC;
    }
    // 0x808013BC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808013C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3DF0) << 16);
    // 0x808013C4: addu        $at, $at, $t2
    gpr jr_addend_808013CC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x808013C8: lw          $t2, 0x3DF0($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DF0));
    // 0x808013CC: jr          $t2
    // 0x808013D0: nop

    switch (jr_addend_808013CC >> 2) {
        case 0: goto L_808013D4; break;
        case 1: goto L_808014AC; break;
        case 2: goto L_808015AC; break;
        case 3: goto L_808022AC; break;
        case 4: goto L_80801754; break;
        case 5: goto L_808018BC; break;
        case 6: goto L_80801974; break;
        case 7: goto L_808019FC; break;
        case 8: goto L_80801D40; break;
        case 9: goto L_80801E4C; break;
        case 10: goto L_80801F14; break;
        case 11: goto L_80801F54; break;
        case 12: goto L_80801CCC; break;
        case 13: goto L_80802004; break;
        case 14: goto L_808020F4; break;
        case 15: goto L_80802118; break;
        case 16: goto L_8080181C; break;
        case 17: goto L_808020D0; break;
        case 18: goto L_80801DBC; break;
        case 19: goto L_808022AC; break;
        default: switch_error(__func__, 0x808013CC, 0x80803DF0);
    }
    // 0x808013D0: nop

L_808013D4:
    // 0x808013D4: lbu         $t3, 0x77($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X77);
    // 0x808013D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808013DC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808013E0: andi        $t4, $t3, 0xFFF0
    ctx->r12 = ctx->r11 & 0XFFF0;
    // 0x808013E4: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x808013E8: sb          $t5, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r13;
    // 0x808013EC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x808013F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F8: sb          $t6, 0x8F($t7)
    MEM_B(0X8F, ctx->r15) = ctx->r14;
    // 0x808013FC: jal         0x80101E14
    // 0x80801400: sb          $zero, 0x8E($t7)
    MEM_B(0X8E, ctx->r15) = 0;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80801400: sb          $zero, 0x8E($t7)
    MEM_B(0X8E, ctx->r15) = 0;
    after_11:
    // 0x80801404: beq         $v0, $zero, L_80801428
    if (ctx->r2 == 0) {
        // 0x80801408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801428;
    }
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080140C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X416C) << 16);
    // 0x80801410: addiu       $a2, $a2, 0x416C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X416C));
    // 0x80801414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801418: jal         0x80089D18
    // 0x8080141C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x8080141C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_12:
    // 0x80801420: b           L_80801450
    // 0x80801424: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
        goto L_80801450;
    // 0x80801424: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_80801428:
    // 0x80801428: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080142C: jal         0x80101E14
    // 0x80801430: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80801430: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_13:
    // 0x80801434: beq         $v0, $zero, L_8080144C
    if (ctx->r2 == 0) {
        // 0x80801438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080144C;
    }
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080143C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4178) << 16);
    // 0x80801440: addiu       $a2, $a2, 0x4178
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4178));
    // 0x80801444: jal         0x80089D18
    // 0x80801448: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80801448: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_14:
L_8080144C:
    // 0x8080144C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_80801450:
    // 0x80801450: lbu         $t9, 0x90($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X90);
    // 0x80801454: bne         $t9, $zero, L_808022AC
    if (ctx->r25 != 0) {
        // 0x80801458: nop
    
            goto L_808022AC;
    }
    // 0x80801458: nop

    // 0x8080145C: jal         0x80090178
    // 0x80801460: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_15;
    // 0x80801460: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80801464: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801468: nop
    
            goto L_808022AC;
    }
    // 0x80801468: nop

    // 0x8080146C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801470: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80801474: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801478: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080147C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801480: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80801484: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x80801488: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080148C: jal         0x8008A1C8
    // 0x80801490: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80801490: nop

    after_16:
    // 0x80801494: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080149C: jal         0x808007C4
    // 0x808014A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_17;
    // 0x808014A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x808014A4: b           L_808022AC
    // 0x808014A8: nop

        goto L_808022AC;
    // 0x808014A8: nop

L_808014AC:
    // 0x808014AC: lbu         $t2, 0x77($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X77);
    // 0x808014B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808014B4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808014B8: andi        $t3, $t2, 0xFFF0
    ctx->r11 = ctx->r10 & 0XFFF0;
    // 0x808014BC: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x808014C0: sb          $t4, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r12;
    // 0x808014C4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808014C8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D0: sb          $t5, 0x8F($t6)
    MEM_B(0X8F, ctx->r14) = ctx->r13;
    // 0x808014D4: jal         0x80101E14
    // 0x808014D8: sb          $zero, 0x8E($t6)
    MEM_B(0X8E, ctx->r14) = 0;
    func_80101E14(rdram, ctx);
        goto after_18;
    // 0x808014D8: sb          $zero, 0x8E($t6)
    MEM_B(0X8E, ctx->r14) = 0;
    after_18:
    // 0x808014DC: beq         $v0, $zero, L_80801500
    if (ctx->r2 == 0) {
        // 0x808014E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801500;
    }
    // 0x808014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X416C) << 16);
    // 0x808014E8: addiu       $a2, $a2, 0x416C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X416C));
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F0: jal         0x80089D18
    // 0x808014F4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x808014F4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x808014F8: b           L_80801528
    // 0x808014FC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
        goto L_80801528;
    // 0x808014FC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
L_80801500:
    // 0x80801500: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80801504: jal         0x80101E14
    // 0x80801508: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80801508: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_20:
    // 0x8080150C: beq         $v0, $zero, L_80801524
    if (ctx->r2 == 0) {
        // 0x80801510: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801524;
    }
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801514: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4178) << 16);
    // 0x80801518: addiu       $a2, $a2, 0x4178
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4178));
    // 0x8080151C: jal         0x80089D18
    // 0x80801520: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80801520: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_21:
L_80801524:
    // 0x80801524: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
L_80801528:
    // 0x80801528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801530: lbu         $t8, 0x90($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X90);
    // 0x80801534: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80801538: bne         $t8, $at, L_808022AC
    if (ctx->r24 != ctx->r1) {
        // 0x8080153C: nop
    
            goto L_808022AC;
    }
    // 0x8080153C: nop

    // 0x80801540: jal         0x80101E14
    // 0x80801544: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_22;
    // 0x80801544: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_22:
    // 0x80801548: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x8080154C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801550: jal         0x808003DC
    // 0x80801554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_23;
    // 0x80801554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80801558: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    // 0x8080155C: lbu         $t2, 0x7A($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801560: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801564: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80801568: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080156C: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
    // 0x80801570: lbu         $t1, 0x71($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X71);
    // 0x80801574: andi        $t3, $t2, 0xFFF1
    ctx->r11 = ctx->r10 & 0XFFF1;
    // 0x80801578: ori         $t6, $t3, 0x6
    ctx->r14 = ctx->r11 | 0X6;
    // 0x8080157C: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
    // 0x80801580: ori         $t7, $t6, 0x30
    ctx->r15 = ctx->r14 | 0X30;
    // 0x80801584: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80801588: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x8080158C: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
    // 0x80801590: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x80801594: sb          $t2, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r10;
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080159C: jal         0x808007C4
    // 0x808015A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_24;
    // 0x808015A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x808015A4: b           L_808022AC
    // 0x808015A8: nop

        goto L_808022AC;
    // 0x808015A8: nop

L_808015AC:
    // 0x808015AC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808015B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808015B4: jal         0x80101E14
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808015BC: beq         $v0, $zero, L_808015D4
    if (ctx->r2 == 0) {
        // 0x808015C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015D4;
    }
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4184) << 16);
    // 0x808015C8: addiu       $a2, $a2, 0x4184
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4184));
    // 0x808015CC: jal         0x80089D18
    // 0x808015D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x808015D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_26:
L_808015D4:
    // 0x808015D4: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808015D8: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x808015DC: sltiu       $at, $t3, 0x64
    ctx->r1 = ctx->r11 < 0X64 ? 1 : 0;
    // 0x808015E0: beq         $at, $zero, L_80801684
    if (ctx->r1 == 0) {
        // 0x808015E4: nop
    
            goto L_80801684;
    }
    // 0x808015E4: nop

    // 0x808015E8: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x808015EC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808015F0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x808015F4: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x808015F8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808015FC: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80801600: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80801604: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80801608: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x8080160C: beq         $at, $zero, L_80801628
    if (ctx->r1 == 0) {
        // 0x80801610: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80801628;
    }
    // 0x80801610: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80801614: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801618: andi        $t1, $t0, 0xFFF1
    ctx->r9 = ctx->r8 & 0XFFF1;
    // 0x8080161C: ori         $t2, $t1, 0x6
    ctx->r10 = ctx->r9 | 0X6;
    // 0x80801620: b           L_808016FC
    // 0x80801624: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
        goto L_808016FC;
    // 0x80801624: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
L_80801628:
    // 0x80801628: sltiu       $at, $v0, 0x28
    ctx->r1 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x8080162C: beql        $at, $zero, L_8080164C
    if (ctx->r1 == 0) {
        // 0x80801630: sltiu       $at, $v0, 0x3C
        ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
            goto L_8080164C;
    }
    goto skip_2;
    // 0x80801630: sltiu       $at, $v0, 0x3C
    ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
    skip_2:
    // 0x80801634: lbu         $t3, 0x7A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801638: andi        $t4, $t3, 0xFFF1
    ctx->r12 = ctx->r11 & 0XFFF1;
    // 0x8080163C: ori         $t6, $t4, 0x4
    ctx->r14 = ctx->r12 | 0X4;
    // 0x80801640: b           L_808016FC
    // 0x80801644: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
        goto L_808016FC;
    // 0x80801644: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
    // 0x80801648: sltiu       $at, $v0, 0x3C
    ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
L_8080164C:
    // 0x8080164C: beql        $at, $zero, L_8080166C
    if (ctx->r1 == 0) {
        // 0x80801650: lbu         $t9, 0x7A($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X7A);
            goto L_8080166C;
    }
    goto skip_3;
    // 0x80801650: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    skip_3:
    // 0x80801654: lbu         $t5, 0x7A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801658: andi        $t7, $t5, 0xFFF1
    ctx->r15 = ctx->r13 & 0XFFF1;
    // 0x8080165C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80801660: b           L_808016FC
    // 0x80801664: sb          $t8, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r24;
        goto L_808016FC;
    // 0x80801664: sb          $t8, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r24;
    // 0x80801668: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
L_8080166C:
    // 0x8080166C: andi        $t1, $t9, 0xFFF1
    ctx->r9 = ctx->r25 & 0XFFF1;
    // 0x80801670: andi        $t2, $t1, 0xCF
    ctx->r10 = ctx->r9 & 0XCF;
    // 0x80801674: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x80801678: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8080167C: b           L_808016FC
    // 0x80801680: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
        goto L_808016FC;
    // 0x80801680: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
L_80801684:
    // 0x80801684: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E40) << 16);
    // 0x80801688: jal         0x800DC298
    // 0x8080168C: lwc1        $f12, 0x3E40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E40));
    func_800DC298(rdram, ctx);
        goto after_27;
    // 0x8080168C: lwc1        $f12, 0x3E40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E40));
    after_27:
    // 0x80801690: beq         $v0, $zero, L_808016C4
    if (ctx->r2 == 0) {
        // 0x80801694: nop
    
            goto L_808016C4;
    }
    // 0x80801694: nop

    // 0x80801698: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
    // 0x8080169C: sll         $t6, $t4, 20
    ctx->r14 = S32(ctx->r12 << 20);
    // 0x808016A0: srl         $t5, $t6, 29
    ctx->r13 = S32(U32(ctx->r14) >> 29);
    // 0x808016A4: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x808016A8: beq         $at, $zero, L_808016C4
    if (ctx->r1 == 0) {
        // 0x808016AC: nop
    
            goto L_808016C4;
    }
    // 0x808016AC: nop

    // 0x808016B0: lbu         $t7, 0x7A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7A);
    // 0x808016B4: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x808016B8: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808016BC: b           L_808016FC
    // 0x808016C0: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
        goto L_808016FC;
    // 0x808016C0: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
L_808016C4:
    // 0x808016C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E44) << 16);
    // 0x808016C8: jal         0x800DC298
    // 0x808016CC: lwc1        $f12, 0x3E44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E44));
    func_800DC298(rdram, ctx);
        goto after_28;
    // 0x808016CC: lwc1        $f12, 0x3E44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E44));
    after_28:
    // 0x808016D0: beql        $v0, $zero, L_80801700
    if (ctx->r2 == 0) {
        // 0x808016D4: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80801700;
    }
    goto skip_4;
    // 0x808016D4: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_4:
    // 0x808016D8: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x808016DC: sll         $t1, $t0, 20
    ctx->r9 = S32(ctx->r8 << 20);
    // 0x808016E0: srl         $t2, $t1, 29
    ctx->r10 = S32(U32(ctx->r9) >> 29);
    // 0x808016E4: blezl       $t2, L_80801700
    if (SIGNED(ctx->r10) <= 0) {
        // 0x808016E8: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80801700;
    }
    goto skip_5;
    // 0x808016E8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_5:
    // 0x808016EC: lbu         $t3, 0x7A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7A);
    // 0x808016F0: andi        $t4, $t3, 0xFFCF
    ctx->r12 = ctx->r11 & 0XFFCF;
    // 0x808016F4: ori         $t6, $t4, 0x20
    ctx->r14 = ctx->r12 | 0X20;
    // 0x808016F8: sb          $t6, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r14;
L_808016FC:
    // 0x808016FC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_80801700:
    // 0x80801700: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80801704: jal         0x80101E14
    // 0x80801708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x80801708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080170C: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801714: lbu         $t5, 0x77($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X77);
    // 0x80801718: addiu       $a1, $zero, 0x11DF
    ctx->r5 = ADD32(0, 0X11DF);
    // 0x8080171C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801720: andi        $t7, $t5, 0xFFF0
    ctx->r15 = ctx->r13 & 0XFFF0;
    // 0x80801724: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80801728: jal         0x80800354
    // 0x8080172C: sb          $t8, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r24;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_30;
    // 0x8080172C: sb          $t8, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r24;
    after_30:
    // 0x80801730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801734: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801738: jal         0x80800144
    // 0x8080173C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800144_chevilmumbo(rdram, ctx);
        goto after_31;
    // 0x8080173C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x80801740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801744: jal         0x808007C4
    // 0x80801748: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_32;
    // 0x80801748: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_32:
    // 0x8080174C: b           L_808022AC
    // 0x80801750: nop

        goto L_808022AC;
    // 0x80801750: nop

L_80801754:
    // 0x80801754: jal         0x80101DDC
    // 0x80801758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_33;
    // 0x80801758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x8080175C: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x80801760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801790;
    }
    // 0x80801760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801764: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80801768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080176C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80801770: jal         0x808007C4
    // 0x80801774: sb          $zero, 0x8F($t9)
    MEM_B(0X8F, ctx->r25) = 0;
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_34;
    // 0x80801774: sb          $zero, 0x8F($t9)
    MEM_B(0X8F, ctx->r25) = 0;
    after_34:
    // 0x80801778: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X427C) << 16);
    // 0x8080177C: addiu       $a1, $a1, 0x427C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X427C));
    // 0x80801780: jal         0x800EE7F8
    // 0x80801784: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_35;
    // 0x80801784: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_35:
    // 0x80801788: b           L_808022AC
    // 0x8080178C: nop

        goto L_808022AC;
    // 0x8080178C: nop

L_80801790:
    // 0x80801790: lui         $a1, 0x3F5E
    ctx->r5 = S32(0X3F5E << 16);
    // 0x80801794: jal         0x80101E14
    // 0x80801798: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    func_80101E14(rdram, ctx);
        goto after_36;
    // 0x80801798: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_36:
    // 0x8080179C: beq         $v0, $zero, L_808017C0
    if (ctx->r2 == 0) {
        // 0x808017A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017C0;
    }
    // 0x808017A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41D0) << 16);
    // 0x808017A8: addiu       $a2, $a2, 0x41D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41D0));
    // 0x808017AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B0: jal         0x80089D18
    // 0x808017B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_37;
    // 0x808017B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_37:
    // 0x808017B8: b           L_808022AC
    // 0x808017BC: nop

        goto L_808022AC;
    // 0x808017BC: nop

L_808017C0:
    // 0x808017C0: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x808017C4: jal         0x80101E14
    // 0x808017C8: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x808017C8: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_38:
    // 0x808017CC: beq         $v0, $zero, L_808017F0
    if (ctx->r2 == 0) {
        // 0x808017D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017F0;
    }
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41DC) << 16);
    // 0x808017D8: addiu       $a2, $a2, 0x41DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41DC));
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E0: jal         0x80089D18
    // 0x808017E4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x808017E4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_39:
    // 0x808017E8: b           L_808022AC
    // 0x808017EC: nop

        goto L_808022AC;
    // 0x808017EC: nop

L_808017F0:
    // 0x808017F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4388) << 16);
    // 0x808017F4: jal         0x80101E4C
    // 0x808017F8: addiu       $a1, $a1, 0x4388
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4388));
    func_80101E4C(rdram, ctx);
        goto after_40;
    // 0x808017F8: addiu       $a1, $a1, 0x4388
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4388));
    after_40:
    // 0x808017FC: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801804: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41E8) << 16);
    // 0x80801808: addiu       $a2, $a2, 0x41E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41E8));
    // 0x8080180C: jal         0x80089D18
    // 0x80801810: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_41;
    // 0x80801810: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_41:
    // 0x80801814: b           L_808022AC
    // 0x80801818: nop

        goto L_808022AC;
    // 0x80801818: nop

L_8080181C:
    // 0x8080181C: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80801820: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80801824: bltz        $t2, L_808022AC
    if (SIGNED(ctx->r10) < 0) {
        // 0x80801828: nop
    
            goto L_808022AC;
    }
    // 0x80801828: nop

    // 0x8080182C: jal         0x8010D254
    // 0x80801830: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_8010D254(rdram, ctx);
        goto after_42;
    // 0x80801830: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_42:
    // 0x80801834: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80801838: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080183C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801840: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801844: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80801848: nop

    // 0x8080184C: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80801850: nop
    
            goto L_808022AC;
    }
    // 0x80801850: nop

    // 0x80801854: jal         0x8008FA60
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_43;
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x8080185C: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801860: nop
    
            goto L_808022AC;
    }
    // 0x80801860: nop

    // 0x80801864: jal         0x80090248
    // 0x80801868: nop

    func_80090248(rdram, ctx);
        goto after_44;
    // 0x80801868: nop

    after_44:
    // 0x8080186C: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801870: nop
    
            goto L_808022AC;
    }
    // 0x80801870: nop

    // 0x80801874: jal         0x800FDC28
    // 0x80801878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_45;
    // 0x80801878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_45:
    // 0x8080187C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801880: jal         0x80090734
    // 0x80801884: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80090734(rdram, ctx);
        goto after_46;
    // 0x80801884: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_46:
    // 0x80801888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080188C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801890: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80801894: jal         0x808001F4
    // 0x80801898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_47;
    // 0x80801898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_47:
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018A0: addiu       $a1, $zero, 0x11E2
    ctx->r5 = ADD32(0, 0X11E2);
    // 0x808018A4: jal         0x80800354
    // 0x808018A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_48;
    // 0x808018A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_48:
    // 0x808018AC: jal         0x800DA544
    // 0x808018B0: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA544(rdram, ctx);
        goto after_49;
    // 0x808018B0: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_49:
    // 0x808018B4: b           L_808022AC
    // 0x808018B8: nop

        goto L_808022AC;
    // 0x808018B8: nop

L_808018BC:
    // 0x808018BC: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x808018C0: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    // 0x808018C4: jal         0x80101E14
    // 0x808018C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_50;
    // 0x808018C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808018CC: beq         $v0, $zero, L_808018E0
    if (ctx->r2 == 0) {
        // 0x808018D0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1676, 0X3E48) << 16);
            goto L_808018E0;
    }
    // 0x808018D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E48) << 16);
    // 0x808018D4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x808018D8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808018DC: sb          $t3, 0x8E($t4)
    MEM_B(0X8E, ctx->r12) = ctx->r11;
L_808018E0:
    // 0x808018E0: jal         0x800DC298
    // 0x808018E4: lwc1        $f12, 0x3E48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E48));
    func_800DC298(rdram, ctx);
        goto after_51;
    // 0x808018E4: lwc1        $f12, 0x3E48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E48));
    after_51:
    // 0x808018E8: beq         $v0, $zero, L_80801914
    if (ctx->r2 == 0) {
        // 0x808018EC: lw          $t6, 0x58($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X58);
            goto L_80801914;
    }
    // 0x808018EC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808018F0: lbu         $t5, 0x8D($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X8D);
    // 0x808018F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808018F8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808018FC: bne         $t5, $at, L_8080190C
    if (ctx->r13 != ctx->r1) {
        // 0x80801900: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_8080190C;
    }
    // 0x80801900: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80801904: b           L_80801914
    // 0x80801908: sb          $t7, 0x8D($t6)
    MEM_B(0X8D, ctx->r14) = ctx->r15;
        goto L_80801914;
    // 0x80801908: sb          $t7, 0x8D($t6)
    MEM_B(0X8D, ctx->r14) = ctx->r15;
L_8080190C:
    // 0x8080190C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801910: sb          $t8, 0x8D($t9)
    MEM_B(0X8D, ctx->r25) = ctx->r24;
L_80801914:
    // 0x80801914: jal         0x80101DDC
    // 0x80801918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_52;
    // 0x80801918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x8080191C: beq         $v0, $zero, L_80801948
    if (ctx->r2 == 0) {
        // 0x80801920: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801948;
    }
    // 0x80801920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801924: jal         0x80088178
    // 0x80801928: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_53;
    // 0x80801928: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_53:
    // 0x8080192C: jal         0x800DA544
    // 0x80801930: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    func_800DA544(rdram, ctx);
        goto after_54;
    // 0x80801930: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    after_54:
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801938: jal         0x808007C4
    // 0x8080193C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_55;
    // 0x8080193C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_55:
    // 0x80801940: b           L_808022AC
    // 0x80801944: nop

        goto L_808022AC;
    // 0x80801944: nop

L_80801948:
    // 0x80801948: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4398) << 16);
    // 0x8080194C: jal         0x80101E4C
    // 0x80801950: addiu       $a1, $a1, 0x4398
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4398));
    func_80101E4C(rdram, ctx);
        goto after_56;
    // 0x80801950: addiu       $a1, $a1, 0x4398
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4398));
    after_56:
    // 0x80801954: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801958: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080195C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X41F8) << 16);
    // 0x80801960: addiu       $a2, $a2, 0x41F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X41F8));
    // 0x80801964: jal         0x80089D18
    // 0x80801968: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_57;
    // 0x80801968: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_57:
    // 0x8080196C: b           L_808022AC
    // 0x80801970: nop

        goto L_808022AC;
    // 0x80801970: nop

L_80801974:
    // 0x80801974: jal         0x80800E50
    // 0x80801978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E50_chevilmumbo(rdram, ctx);
        goto after_58;
    // 0x80801978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x8080197C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80801980: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801988: lbu         $t1, 0x90($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X90);
    // 0x8080198C: bnel        $t1, $at, L_808019D0
    if (ctx->r9 != ctx->r1) {
        // 0x80801990: lbu         $t5, 0x74($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X74);
            goto L_808019D0;
    }
    goto skip_6;
    // 0x80801990: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    skip_6:
    // 0x80801994: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080199C: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x808019A0: jal         0x80800E50
    // 0x808019A4: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    func_80800E50_chevilmumbo(rdram, ctx);
        goto after_59;
    // 0x808019A4: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    after_59:
    // 0x808019A8: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x808019AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B0: jal         0x808003DC
    // 0x808019B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_60;
    // 0x808019B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x808019B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019BC: jal         0x808007C4
    // 0x808019C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_61;
    // 0x808019C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_61:
    // 0x808019C4: b           L_808022AC
    // 0x808019C8: nop

        goto L_808022AC;
    // 0x808019C8: nop

    // 0x808019CC: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
L_808019D0:
    // 0x808019D0: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808019D4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808019D8: ori         $t7, $t5, 0x20
    ctx->r15 = ctx->r13 | 0X20;
    // 0x808019DC: jal         0x80101E14
    // 0x808019E0: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    func_80101E14(rdram, ctx);
        goto after_62;
    // 0x808019E0: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    after_62:
    // 0x808019E4: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x808019E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x808019E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019EC: jal         0x808003DC
    // 0x808019F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_63;
    // 0x808019F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_63:
    // 0x808019F4: b           L_808022AC
    // 0x808019F8: nop

        goto L_808022AC;
    // 0x808019F8: nop

L_808019FC:
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A00: jal         0x80101E14
    // 0x80801A04: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_64;
    // 0x80801A04: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_64:
    // 0x80801A08: beq         $v0, $zero, L_80801A24
    if (ctx->r2 == 0) {
        // 0x80801A0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A24;
    }
    // 0x80801A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A14: jal         0x80108B04
    // 0x80801A18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_65;
    // 0x80801A18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_65:
    // 0x80801A1C: b           L_80801CBC
    // 0x80801A20: nop

        goto L_80801CBC;
    // 0x80801A20: nop

L_80801A24:
    // 0x80801A24: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
    // 0x80801A28: jal         0x80101E14
    // 0x80801A2C: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_66;
    // 0x80801A2C: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_66:
    // 0x80801A30: beq         $v0, $zero, L_80801B40
    if (ctx->r2 == 0) {
        // 0x80801A34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B40;
    }
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A3C: jal         0x80108B04
    // 0x80801A40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_67;
    // 0x80801A40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_67:
    // 0x80801A44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E4C) << 16);
    // 0x80801A48: lwc1        $f12, 0x3E4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E4C));
    // 0x80801A4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E50) << 16);
    // 0x80801A50: jal         0x800DC178
    // 0x80801A54: lwc1        $f14, 0x3E50($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E50));
    func_800DC178(rdram, ctx);
        goto after_68;
    // 0x80801A54: lwc1        $f14, 0x3E50($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E50));
    after_68:
    // 0x80801A58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E54) << 16);
    // 0x80801A5C: lwc1        $f12, 0x3E54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E54));
    // 0x80801A60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E58) << 16);
    // 0x80801A64: lwc1        $f14, 0x3E58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E58));
    // 0x80801A68: jal         0x800DC178
    // 0x80801A6C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_69;
    // 0x80801A6C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_69:
    // 0x80801A70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E5C) << 16);
    // 0x80801A74: lwc1        $f16, 0x3E5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E5C));
    // 0x80801A78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801A7C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801A80: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801A84: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80801A88: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801A8C: nop

    // 0x80801A90: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801A94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801A98: nop

    // 0x80801A9C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801AA0: beql        $t8, $zero, L_80801AF0
    if (ctx->r24 == 0) {
        // 0x80801AA4: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_80801AF0;
    }
    goto skip_7;
    // 0x80801AA4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_7:
    // 0x80801AA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801AAC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801AB0: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80801AB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801AB8: nop

    // 0x80801ABC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801AC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801AC4: nop

    // 0x80801AC8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801ACC: bne         $t8, $zero, L_80801AE4
    if (ctx->r24 != 0) {
        // 0x80801AD0: nop
    
            goto L_80801AE4;
    }
    // 0x80801AD0: nop

    // 0x80801AD4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80801AD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801ADC: b           L_80801AFC
    // 0x80801AE0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80801AFC;
    // 0x80801AE0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80801AE4:
    // 0x80801AE4: b           L_80801AFC
    // 0x80801AE8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80801AFC;
    // 0x80801AE8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80801AEC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_80801AF0:
    // 0x80801AF0: nop

    // 0x80801AF4: bltz        $t8, L_80801AE4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801AF8: nop
    
            goto L_80801AE4;
    }
    // 0x80801AF8: nop

L_80801AFC:
    // 0x80801AFC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801B00: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801B04: sll         $t0, $t8, 21
    ctx->r8 = S32(ctx->r24 << 21);
    // 0x80801B08: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80801B0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801B10: ori         $a2, $a2, 0x9C4
    ctx->r6 = ctx->r6 | 0X9C4;
    // 0x80801B14: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801B18: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80801B1C: nop

    // 0x80801B20: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x80801B24: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80801B28: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80801B2C: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x80801B30: jal         0x800C4140
    // 0x80801B34: addiu       $a0, $a0, 0x48F
    ctx->r4 = ADD32(ctx->r4, 0X48F);
    func_800C4140(rdram, ctx);
        goto after_70;
    // 0x80801B34: addiu       $a0, $a0, 0x48F
    ctx->r4 = ADD32(ctx->r4, 0X48F);
    after_70:
    // 0x80801B38: b           L_80801CBC
    // 0x80801B3C: nop

        goto L_80801CBC;
    // 0x80801B3C: nop

L_80801B40:
    // 0x80801B40: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801B44: jal         0x80101E14
    // 0x80801B48: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_71;
    // 0x80801B48: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_71:
    // 0x80801B4C: beq         $v0, $zero, L_80801C4C
    if (ctx->r2 == 0) {
        // 0x80801B50: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1676, 0X3E60) << 16);
            goto L_80801C4C;
    }
    // 0x80801B50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E60) << 16);
    // 0x80801B54: lwc1        $f12, 0x3E60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E60));
    // 0x80801B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E64) << 16);
    // 0x80801B5C: jal         0x800DC178
    // 0x80801B60: lwc1        $f14, 0x3E64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E64));
    func_800DC178(rdram, ctx);
        goto after_72;
    // 0x80801B60: lwc1        $f14, 0x3E64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E64));
    after_72:
    // 0x80801B64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E68) << 16);
    // 0x80801B68: lwc1        $f12, 0x3E68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E68));
    // 0x80801B6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E6C) << 16);
    // 0x80801B70: lwc1        $f14, 0x3E6C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E6C));
    // 0x80801B74: jal         0x800DC178
    // 0x80801B78: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_73;
    // 0x80801B78: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_73:
    // 0x80801B7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E70) << 16);
    // 0x80801B80: lwc1        $f10, 0x3E70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E70));
    // 0x80801B84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801B88: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801B8C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801B90: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801B94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801B98: nop

    // 0x80801B9C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801BA0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80801BA4: nop

    // 0x80801BA8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80801BAC: beql        $t6, $zero, L_80801BFC
    if (ctx->r14 == 0) {
        // 0x80801BB0: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_80801BFC;
    }
    goto skip_8;
    // 0x80801BB0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x80801BB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801BB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801BBC: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801BC0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801BC4: nop

    // 0x80801BC8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801BCC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80801BD0: nop

    // 0x80801BD4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80801BD8: bne         $t6, $zero, L_80801BF0
    if (ctx->r14 != 0) {
        // 0x80801BDC: nop
    
            goto L_80801BF0;
    }
    // 0x80801BDC: nop

    // 0x80801BE0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80801BE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801BE8: b           L_80801C08
    // 0x80801BEC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80801C08;
    // 0x80801BEC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80801BF0:
    // 0x80801BF0: b           L_80801C08
    // 0x80801BF4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80801C08;
    // 0x80801BF4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801BF8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_80801BFC:
    // 0x80801BFC: nop

    // 0x80801C00: bltz        $t6, L_80801BF0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80801C04: nop
    
            goto L_80801BF0;
    }
    // 0x80801C04: nop

L_80801C08:
    // 0x80801C08: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801C0C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801C10: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x80801C14: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80801C18: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801C1C: ori         $a2, $a2, 0x9C4
    ctx->r6 = ctx->r6 | 0X9C4;
    // 0x80801C20: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801C24: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80801C28: nop

    // 0x80801C2C: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x80801C30: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80801C34: sll         $t0, $t4, 11
    ctx->r8 = S32(ctx->r12 << 11);
    // 0x80801C38: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80801C3C: jal         0x800C4140
    // 0x80801C40: addiu       $a0, $a0, 0x5F9
    ctx->r4 = ADD32(ctx->r4, 0X5F9);
    func_800C4140(rdram, ctx);
        goto after_74;
    // 0x80801C40: addiu       $a0, $a0, 0x5F9
    ctx->r4 = ADD32(ctx->r4, 0X5F9);
    after_74:
    // 0x80801C44: b           L_80801CBC
    // 0x80801C48: nop

        goto L_80801CBC;
    // 0x80801C48: nop

L_80801C4C:
    // 0x80801C4C: jal         0x80101DDC
    // 0x80801C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_75;
    // 0x80801C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x80801C54: beq         $v0, $zero, L_80801CBC
    if (ctx->r2 == 0) {
        // 0x80801C58: nop
    
            goto L_80801CBC;
    }
    // 0x80801C58: nop

    // 0x80801C5C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80801C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C64: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80801C68: bltzl       $t6, L_80801C90
    if (SIGNED(ctx->r14) < 0) {
        // 0x80801C6C: lw          $t8, 0x6C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X6C);
            goto L_80801C90;
    }
    goto skip_9;
    // 0x80801C6C: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    skip_9:
    // 0x80801C70: jal         0x808003DC
    // 0x80801C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_76;
    // 0x80801C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_76:
    // 0x80801C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C7C: jal         0x808007C4
    // 0x80801C80: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_77;
    // 0x80801C80: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_77:
    // 0x80801C84: b           L_80801CBC
    // 0x80801C88: nop

        goto L_80801CBC;
    // 0x80801C88: nop

    // 0x80801C8C: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
L_80801C90:
    // 0x80801C90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C98: andi        $t1, $t8, 0x1FF
    ctx->r9 = ctx->r24 & 0X1FF;
    // 0x80801C9C: beq         $t1, $zero, L_80801CB4
    if (ctx->r9 == 0) {
        // 0x80801CA0: nop
    
            goto L_80801CB4;
    }
    // 0x80801CA0: nop

    // 0x80801CA4: jal         0x808007C4
    // 0x80801CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_78;
    // 0x80801CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80801CAC: b           L_80801CBC
    // 0x80801CB0: nop

        goto L_80801CBC;
    // 0x80801CB0: nop

L_80801CB4:
    // 0x80801CB4: jal         0x808007C4
    // 0x80801CB8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_79;
    // 0x80801CB8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_79:
L_80801CBC:
    // 0x80801CBC: jal         0x80800E50
    // 0x80801CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E50_chevilmumbo(rdram, ctx);
        goto after_80;
    // 0x80801CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80801CC4: b           L_808022AC
    // 0x80801CC8: nop

        goto L_808022AC;
    // 0x80801CC8: nop

L_80801CCC:
    // 0x80801CCC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80801CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801CD4: lbu         $v0, 0x90($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X90);
    // 0x80801CD8: beq         $v0, $at, L_80801D00
    if (ctx->r2 == ctx->r1) {
        // 0x80801CDC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801D00;
    }
    // 0x80801CDC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801CE0: beq         $v0, $at, L_80801D20
    if (ctx->r2 == ctx->r1) {
        // 0x80801CE4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80801D20;
    }
    // 0x80801CE4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801CE8: beq         $v0, $at, L_808022AC
    if (ctx->r2 == ctx->r1) {
        // 0x80801CEC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_808022AC;
    }
    // 0x80801CEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80801CF0: beq         $v0, $at, L_808022AC
    if (ctx->r2 == ctx->r1) {
        // 0x80801CF4: nop
    
            goto L_808022AC;
    }
    // 0x80801CF4: nop

    // 0x80801CF8: b           L_808022AC
    // 0x80801CFC: nop

        goto L_808022AC;
    // 0x80801CFC: nop

L_80801D00:
    // 0x80801D00: jal         0x800DA298
    // 0x80801D04: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_81;
    // 0x80801D04: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_81:
    // 0x80801D08: bne         $v0, $zero, L_808022AC
    if (ctx->r2 != 0) {
        // 0x80801D0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D10: jal         0x808003DC
    // 0x80801D14: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_82;
    // 0x80801D14: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_82:
    // 0x80801D18: b           L_808022AC
    // 0x80801D1C: nop

        goto L_808022AC;
    // 0x80801D1C: nop

L_80801D20:
    // 0x80801D20: jal         0x800DA298
    // 0x80801D24: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA298(rdram, ctx);
        goto after_83;
    // 0x80801D24: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_83:
    // 0x80801D28: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80801D2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x80801D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D30: jal         0x808003DC
    // 0x80801D34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_84;
    // 0x80801D34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_84:
    // 0x80801D38: b           L_808022AC
    // 0x80801D3C: nop

        goto L_808022AC;
    // 0x80801D3C: nop

L_80801D40:
    // 0x80801D40: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80801D44: lbu         $t4, 0x90($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X90);
    // 0x80801D48: bne         $t4, $zero, L_80801DAC
    if (ctx->r12 != 0) {
        // 0x80801D4C: nop
    
            goto L_80801DAC;
    }
    // 0x80801D4C: nop

    // 0x80801D50: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801D54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801D58: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801D5C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80801D60: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80801D64: nop

    // 0x80801D68: bc1fl       L_80801D80
    if (!c1cs) {
        // 0x80801D6C: lbu         $t0, 0x93($t9)
        ctx->r8 = MEM_BU(ctx->r25, 0X93);
            goto L_80801D80;
    }
    goto skip_10;
    // 0x80801D6C: lbu         $t0, 0x93($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X93);
    skip_10:
    // 0x80801D70: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80801D74: b           L_80801DAC
    // 0x80801D78: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80801DAC;
    // 0x80801D78: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80801D7C: lbu         $t0, 0x93($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X93);
L_80801D80:
    // 0x80801D80: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D88: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80801D8C: bne         $at, $zero, L_80801DA4
    if (ctx->r1 != 0) {
        // 0x80801D90: nop
    
            goto L_80801DA4;
    }
    // 0x80801D90: nop

    // 0x80801D94: jal         0x808007C4
    // 0x80801D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_85;
    // 0x80801D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80801D9C: b           L_80801DAC
    // 0x80801DA0: nop

        goto L_80801DAC;
    // 0x80801DA0: nop

L_80801DA4:
    // 0x80801DA4: jal         0x808007C4
    // 0x80801DA8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_86;
    // 0x80801DA8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_86:
L_80801DAC:
    // 0x80801DAC: jal         0x80800E50
    // 0x80801DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E50_chevilmumbo(rdram, ctx);
        goto after_87;
    // 0x80801DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_87:
    // 0x80801DB4: b           L_808022AC
    // 0x80801DB8: nop

        goto L_808022AC;
    // 0x80801DB8: nop

L_80801DBC:
    // 0x80801DBC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80801DC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801DC4: lbu         $v0, 0x90($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X90);
    // 0x80801DC8: beql        $v0, $zero, L_80801DE4
    if (ctx->r2 == 0) {
        // 0x80801DCC: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80801DE4;
    }
    goto skip_11;
    // 0x80801DCC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_11:
    // 0x80801DD0: beq         $v0, $at, L_80801E3C
    if (ctx->r2 == ctx->r1) {
        // 0x80801DD4: nop
    
            goto L_80801E3C;
    }
    // 0x80801DD4: nop

    // 0x80801DD8: b           L_80801E3C
    // 0x80801DDC: nop

        goto L_80801E3C;
    // 0x80801DDC: nop

    // 0x80801DE0: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_80801DE4:
    // 0x80801DE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801DE8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801DEC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80801DF0: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80801DF4: nop

    // 0x80801DF8: bc1fl       L_80801E10
    if (!c1cs) {
        // 0x80801DFC: lbu         $t6, 0x93($t7)
        ctx->r14 = MEM_BU(ctx->r15, 0X93);
            goto L_80801E10;
    }
    goto skip_12;
    // 0x80801DFC: lbu         $t6, 0x93($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X93);
    skip_12:
    // 0x80801E00: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80801E04: b           L_80801E3C
    // 0x80801E08: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80801E3C;
    // 0x80801E08: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80801E0C: lbu         $t6, 0x93($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X93);
L_80801E10:
    // 0x80801E10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E18: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80801E1C: bne         $at, $zero, L_80801E34
    if (ctx->r1 != 0) {
        // 0x80801E20: nop
    
            goto L_80801E34;
    }
    // 0x80801E20: nop

    // 0x80801E24: jal         0x808007C4
    // 0x80801E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_88;
    // 0x80801E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
    // 0x80801E2C: b           L_80801E3C
    // 0x80801E30: nop

        goto L_80801E3C;
    // 0x80801E30: nop

L_80801E34:
    // 0x80801E34: jal         0x808007C4
    // 0x80801E38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_89;
    // 0x80801E38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_89:
L_80801E3C:
    // 0x80801E3C: jal         0x80800E50
    // 0x80801E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E50_chevilmumbo(rdram, ctx);
        goto after_90;
    // 0x80801E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_90:
    // 0x80801E44: b           L_808022AC
    // 0x80801E48: nop

        goto L_808022AC;
    // 0x80801E48: nop

L_80801E4C:
    // 0x80801E4C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801E50: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E58: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801E5C: jal         0x80101DDC
    // 0x80801E60: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_80101DDC(rdram, ctx);
        goto after_91;
    // 0x80801E60: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_91:
    // 0x80801E64: beq         $v0, $zero, L_80801E88
    if (ctx->r2 == 0) {
        // 0x80801E68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E88;
    }
    // 0x80801E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E6C: jal         0x808007C4
    // 0x80801E70: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_92;
    // 0x80801E70: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_92:
    // 0x80801E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E78: jal         0x80089C98
    // 0x80801E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_93;
    // 0x80801E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_93:
    // 0x80801E80: b           L_80801EE4
    // 0x80801E84: nop

        goto L_80801EE4;
    // 0x80801E84: nop

L_80801E88:
    // 0x80801E88: jal         0x80101F24
    // 0x80801E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_94;
    // 0x80801E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_94:
    // 0x80801E90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801E94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E74) << 16);
    // 0x80801E98: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80801E9C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801EA0: lwc1        $f14, 0x3E74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E74));
    // 0x80801EA4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801EA8: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80801EAC: jal         0x800F10B4
    // 0x80801EB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_95;
    // 0x80801EB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_95:
    // 0x80801EB4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EBC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801EC0: jal         0x80089C98
    // 0x80801EC4: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_96;
    // 0x80801EC4: nop

    after_96:
    // 0x80801EC8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4244) << 16);
    // 0x80801ECC: lui         $a3, 0x3E42
    ctx->r7 = S32(0X3E42 << 16);
    // 0x80801ED0: ori         $a3, $a3, 0x8F5C
    ctx->r7 = ctx->r7 | 0X8F5C;
    // 0x80801ED4: addiu       $a2, $a2, 0x4244
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4244));
    // 0x80801ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EDC: jal         0x80089D20
    // 0x80801EE0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_97;
    // 0x80801EE0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_97:
L_80801EE4:
    // 0x80801EE4: jal         0x80101F24
    // 0x80801EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_98;
    // 0x80801EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x80801EEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E78) << 16);
    // 0x80801EF0: lwc1        $f6, 0x3E78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E78));
    // 0x80801EF4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801EF8: nop

    // 0x80801EFC: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80801F00: nop
    
            goto L_808022AC;
    }
    // 0x80801F00: nop

    // 0x80801F04: jal         0x808011F4
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011F4_chevilmumbo(rdram, ctx);
        goto after_99;
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_99:
    // 0x80801F0C: b           L_808022AC
    // 0x80801F10: nop

        goto L_808022AC;
    // 0x80801F10: nop

L_80801F14:
    // 0x80801F14: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801F18: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801F24: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F2C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80801F30: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801F34: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80801F38: nop

    // 0x80801F3C: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80801F40: nop
    
            goto L_808022AC;
    }
    // 0x80801F40: nop

    // 0x80801F44: jal         0x808007C4
    // 0x80801F48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_100;
    // 0x80801F48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_100:
    // 0x80801F4C: b           L_808022AC
    // 0x80801F50: nop

        goto L_808022AC;
    // 0x80801F50: nop

L_80801F54:
    // 0x80801F54: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801F58: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F60: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801F64: jal         0x80101DDC
    // 0x80801F68: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80101DDC(rdram, ctx);
        goto after_101;
    // 0x80801F68: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_101:
    // 0x80801F6C: beq         $v0, $zero, L_80801F90
    if (ctx->r2 == 0) {
        // 0x80801F70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801F90;
    }
    // 0x80801F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F74: jal         0x80089CD0
    // 0x80801F78: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_102;
    // 0x80801F78: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_102:
    // 0x80801F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F80: jal         0x80800ECC
    // 0x80801F84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800ECC_chevilmumbo(rdram, ctx);
        goto after_103;
    // 0x80801F84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_103:
    // 0x80801F88: b           L_808022AC
    // 0x80801F8C: nop

        goto L_808022AC;
    // 0x80801F8C: nop

L_80801F90:
    // 0x80801F90: jal         0x80101F24
    // 0x80801F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_104;
    // 0x80801F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_104:
    // 0x80801F98: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801F9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801FA0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801FA4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801FA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801FAC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801FB0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80801FB4: jal         0x800F10B4
    // 0x80801FB8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_105;
    // 0x80801FB8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_105:
    // 0x80801FBC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FC4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801FC8: jal         0x80089C98
    // 0x80801FCC: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_106;
    // 0x80801FCC: nop

    after_106:
    // 0x80801FD0: jal         0x80101F24
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_107;
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x80801FD8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801FDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801FE0: nop

    // 0x80801FE4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801FE8: nop

    // 0x80801FEC: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80801FF0: nop
    
            goto L_808022AC;
    }
    // 0x80801FF0: nop

    // 0x80801FF4: jal         0x808011F4
    // 0x80801FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011F4_chevilmumbo(rdram, ctx);
        goto after_108;
    // 0x80801FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_108:
    // 0x80801FFC: b           L_808022AC
    // 0x80802000: nop

        goto L_808022AC;
    // 0x80802000: nop

L_80802004:
    // 0x80802004: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802008: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080200C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80802010: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80802014: nop

    // 0x80802018: bc1t        L_80802038
    if (c1cs) {
        // 0x8080201C: nop
    
            goto L_80802038;
    }
    // 0x8080201C: nop

    // 0x80802020: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80802024: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802028: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8080202C: nop

    // 0x80802030: bc1fl       L_80802068
    if (!c1cs) {
        // 0x80802034: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80802068;
    }
    goto skip_13;
    // 0x80802034: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_13:
L_80802038:
    // 0x80802038: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8080203C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802040: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E7C) << 16);
    // 0x80802044: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80802048: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080204C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80802050: lwc1        $f18, 0x3E7C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E7C));
    // 0x80802054: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802058: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8080205C: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80802060: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80802064: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80802068:
    // 0x80802068: nop

    // 0x8080206C: bc1fl       L_80802080
    if (!c1cs) {
        // 0x80802070: c.eq.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
            goto L_80802080;
    }
    goto skip_14;
    // 0x80802070: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    skip_14:
    // 0x80802074: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80802078: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080207C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_80802080:
    // 0x80802080: nop

    // 0x80802084: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80802088: nop
    
            goto L_808022AC;
    }
    // 0x80802088: nop

    // 0x8080208C: jal         0x80101DDC
    // 0x80802090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_109;
    // 0x80802090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_109:
    // 0x80802094: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80802098: addiu       $a0, $zero, 0x423
        ctx->r4 = ADD32(0, 0X423);
            goto L_808022AC;
    }
    // 0x80802098: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x8080209C: jal         0x800DA9E4
    // 0x808020A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_110;
    // 0x808020A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_110:
    // 0x808020A4: bne         $v0, $zero, L_808020C0
    if (ctx->r2 != 0) {
        // 0x808020A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020C0;
    }
    // 0x808020A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020B0: jal         0x808007C4
    // 0x808020B4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_111;
    // 0x808020B4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_111:
    // 0x808020B8: b           L_808022AC
    // 0x808020BC: nop

        goto L_808022AC;
    // 0x808020BC: nop

L_808020C0:
    // 0x808020C0: jal         0x808007C4
    // 0x808020C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_112;
    // 0x808020C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_112:
    // 0x808020C8: b           L_808022AC
    // 0x808020CC: nop

        goto L_808022AC;
    // 0x808020CC: nop

L_808020D0:
    // 0x808020D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4244) << 16);
    // 0x808020D4: lui         $a3, 0x3E42
    ctx->r7 = S32(0X3E42 << 16);
    // 0x808020D8: ori         $a3, $a3, 0x8F5C
    ctx->r7 = ctx->r7 | 0X8F5C;
    // 0x808020DC: addiu       $a2, $a2, 0x4244
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4244));
    // 0x808020E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020E4: jal         0x80089D20
    // 0x808020E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_113;
    // 0x808020E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_113:
    // 0x808020EC: b           L_808022AC
    // 0x808020F0: nop

        goto L_808022AC;
    // 0x808020F0: nop

L_808020F4:
    // 0x808020F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4244) << 16);
    // 0x808020F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X43A4) << 16);
    // 0x808020FC: addiu       $a3, $a3, 0x43A4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X43A4));
    // 0x80802100: addiu       $a2, $a2, 0x4244
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4244));
    // 0x80802104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802108: jal         0x80089D28
    // 0x8080210C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_114;
    // 0x8080210C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_114:
    // 0x80802110: b           L_808022AC
    // 0x80802114: nop

        goto L_808022AC;
    // 0x80802114: nop

L_80802118:
    // 0x80802118: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8080211C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802120: lbu         $v0, 0x90($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X90);
    // 0x80802124: beq         $v0, $zero, L_8080214C
    if (ctx->r2 == 0) {
        // 0x80802128: nop
    
            goto L_8080214C;
    }
    // 0x80802128: nop

    // 0x8080212C: beq         $v0, $at, L_808022AC
    if (ctx->r2 == ctx->r1) {
        // 0x80802130: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808022AC;
    }
    // 0x80802130: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802134: beq         $v0, $at, L_80802294
    if (ctx->r2 == ctx->r1) {
        // 0x80802138: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80802294;
    }
    // 0x80802138: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080213C: beq         $v0, $at, L_808022AC
    if (ctx->r2 == ctx->r1) {
        // 0x80802140: nop
    
            goto L_808022AC;
    }
    // 0x80802140: nop

    // 0x80802144: b           L_808022AC
    // 0x80802148: nop

        goto L_808022AC;
    // 0x80802148: nop

L_8080214C:
    // 0x8080214C: jal         0x80101F24
    // 0x80802150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_115;
    // 0x80802150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_115:
    // 0x80802154: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80802158: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080215C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E80) << 16);
    // 0x80802160: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802164: nop

    // 0x80802168: bc1fl       L_8080219C
    if (!c1cs) {
        // 0x8080216C: lui         $a1, 0x3F19
        ctx->r5 = S32(0X3F19 << 16);
            goto L_8080219C;
    }
    goto skip_15;
    // 0x8080216C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    skip_15:
    // 0x80802170: lwc1        $f10, 0x3E80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E80));
    // 0x80802174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802178: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080217C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80802180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802184: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X41A4) << 16);
    // 0x80802188: bc1fl       L_8080219C
    if (!c1cs) {
        // 0x8080218C: lui         $a1, 0x3F19
        ctx->r5 = S32(0X3F19 << 16);
            goto L_8080219C;
    }
    goto skip_16;
    // 0x8080218C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    skip_16:
    // 0x80802190: jal         0x80089D50
    // 0x80802194: addiu       $a3, $a3, 0x41A4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X41A4));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_116;
    // 0x80802194: addiu       $a3, $a3, 0x41A4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X41A4));
    after_116:
    // 0x80802198: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_8080219C:
    // 0x8080219C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808021A0: jal         0x80101E14
    // 0x808021A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_117;
    // 0x808021A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_117:
    // 0x808021A8: beq         $v0, $zero, L_808021BC
    if (ctx->r2 == 0) {
        // 0x808021AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021BC;
    }
    // 0x808021AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021B0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808021B4: jal         0x80086670
    // 0x808021B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_118;
    // 0x808021B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_118:
L_808021BC:
    // 0x808021BC: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x808021C0: sll         $t9, $t3, 19
    ctx->r25 = S32(ctx->r11 << 19);
    // 0x808021C4: bgezl       $t9, L_80802228
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808021C8: lui         $a1, 0x3F4C
        ctx->r5 = S32(0X3F4C << 16);
            goto L_80802228;
    }
    goto skip_17;
    // 0x808021C8: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    skip_17:
    // 0x808021CC: jal         0x80101F24
    // 0x808021D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_119;
    // 0x808021D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_119:
    // 0x808021D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E84) << 16);
    // 0x808021D8: lwc1        $f16, 0x3E84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E84));
    // 0x808021DC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808021E0: nop

    // 0x808021E4: bc1fl       L_80802208
    if (!c1cs) {
        // 0x808021E8: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80802208;
    }
    goto skip_18;
    // 0x808021E8: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_18:
    // 0x808021EC: jal         0x8001210C
    // 0x808021F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_120;
    // 0x808021F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_120:
    // 0x808021F4: beql        $v0, $zero, L_80802208
    if (ctx->r2 == 0) {
        // 0x808021F8: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80802208;
    }
    goto skip_19;
    // 0x808021F8: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_19:
    // 0x808021FC: jal         0x80800FF8
    // 0x80802200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FF8_chevilmumbo(rdram, ctx);
        goto after_121;
    // 0x80802200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_121:
    // 0x80802204: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
L_80802208:
    // 0x80802208: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8080220C: jal         0x80101E14
    // 0x80802210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_122;
    // 0x80802210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_122:
    // 0x80802214: beql        $v0, $zero, L_80802228
    if (ctx->r2 == 0) {
        // 0x80802218: lui         $a1, 0x3F4C
        ctx->r5 = S32(0X3F4C << 16);
            goto L_80802228;
    }
    goto skip_20;
    // 0x80802218: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    skip_20:
    // 0x8080221C: jal         0x808010C4
    // 0x80802220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010C4_chevilmumbo(rdram, ctx);
        goto after_123;
    // 0x80802220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_123:
    // 0x80802224: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
L_80802228:
    // 0x80802228: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080222C: jal         0x80101E14
    // 0x80802230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_124;
    // 0x80802230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_124:
    // 0x80802234: beq         $v0, $zero, L_80802244
    if (ctx->r2 == 0) {
        // 0x80802238: nop
    
            goto L_80802244;
    }
    // 0x80802238: nop

    // 0x8080223C: jal         0x800FDC28
    // 0x80802240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_125;
    // 0x80802240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_125:
L_80802244:
    // 0x80802244: jal         0x800D8FF8
    // 0x80802248: nop

    func_800D8FF8(rdram, ctx);
        goto after_126;
    // 0x80802248: nop

    after_126:
    // 0x8080224C: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802254: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80802258: jal         0x80101DDC
    // 0x8080225C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80101DDC(rdram, ctx);
        goto after_127;
    // 0x8080225C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_127:
    // 0x80802260: beq         $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80802264: nop
    
            goto L_808022AC;
    }
    // 0x80802264: nop

    // 0x80802268: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080226C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802274: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80802278: nop

    // 0x8080227C: bc1f        L_808022AC
    if (!c1cs) {
        // 0x80802280: nop
    
            goto L_808022AC;
    }
    // 0x80802280: nop

    // 0x80802284: jal         0x808003DC
    // 0x80802288: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_128;
    // 0x80802288: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_128:
    // 0x8080228C: b           L_808022AC
    // 0x80802290: nop

        goto L_808022AC;
    // 0x80802290: nop

L_80802294:
    // 0x80802294: jal         0x800DA298
    // 0x80802298: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    func_800DA298(rdram, ctx);
        goto after_129;
    // 0x80802298: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    after_129:
    // 0x8080229C: bne         $v0, $zero, L_808022AC
    if (ctx->r2 != 0) {
        // 0x808022A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808022AC;
    }
    // 0x808022A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022A4: jal         0x808003DC
    // 0x808022A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_130;
    // 0x808022A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_130:
L_808022AC:
    // 0x808022AC: jal         0x801022E4
    // 0x808022B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_131;
    // 0x808022B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_131:
    // 0x808022B4: addiu       $at, $zero, 0x36C
    ctx->r1 = ADD32(0, 0X36C);
    // 0x808022B8: beq         $v0, $at, L_80802348
    if (ctx->r2 == ctx->r1) {
        // 0x808022BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802348;
    }
    // 0x808022BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022C0: addiu       $at, $zero, 0x36E
    ctx->r1 = ADD32(0, 0X36E);
    // 0x808022C4: beq         $v0, $at, L_808022DC
    if (ctx->r2 == ctx->r1) {
        // 0x808022C8: addiu       $at, $zero, 0x480
        ctx->r1 = ADD32(0, 0X480);
            goto L_808022DC;
    }
    // 0x808022C8: addiu       $at, $zero, 0x480
    ctx->r1 = ADD32(0, 0X480);
    // 0x808022CC: beq         $v0, $at, L_80802328
    if (ctx->r2 == ctx->r1) {
        // 0x808022D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802328;
    }
    // 0x808022D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022D4: b           L_80802378
    // 0x808022D8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80802378;
    // 0x808022D8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_808022DC:
    // 0x808022DC: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x808022E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022E4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808022E8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x808022EC: bgez        $t7, L_80802304
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808022F0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1676, 0X415C) << 16);
            goto L_80802304;
    }
    // 0x808022F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X415C) << 16);
    // 0x808022F4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X43B4) << 16);
    // 0x808022F8: addiu       $a3, $a3, 0x43B4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X43B4));
    // 0x808022FC: jal         0x80089D28
    // 0x80802300: addiu       $a2, $a2, 0x415C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X415C));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_132;
    // 0x80802300: addiu       $a2, $a2, 0x415C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X415C));
    after_132:
L_80802304:
    // 0x80802304: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X426C) << 16);
    // 0x80802308: lui         $a3, 0x3F47
    ctx->r7 = S32(0X3F47 << 16);
    // 0x8080230C: ori         $a3, $a3, 0xAE14
    ctx->r7 = ctx->r7 | 0XAE14;
    // 0x80802310: addiu       $a2, $a2, 0x426C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X426C));
    // 0x80802314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802318: jal         0x80089D20
    // 0x8080231C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_133;
    // 0x8080231C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_133:
    // 0x80802320: b           L_80802378
    // 0x80802324: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80802378;
    // 0x80802324: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80802328:
    // 0x80802328: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4254) << 16);
    // 0x8080232C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X43C4) << 16);
    // 0x80802330: addiu       $a3, $a3, 0x43C4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X43C4));
    // 0x80802334: addiu       $a2, $a2, 0x4254
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4254));
    // 0x80802338: jal         0x80089D28
    // 0x8080233C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_134;
    // 0x8080233C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_134:
    // 0x80802340: b           L_80802378
    // 0x80802344: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80802378;
    // 0x80802344: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80802348:
    // 0x80802348: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X43D4) << 16);
    // 0x8080234C: jal         0x80101E4C
    // 0x80802350: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X43D4));
    func_80101E4C(rdram, ctx);
        goto after_135;
    // 0x80802350: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X43D4));
    after_135:
    // 0x80802354: beq         $v0, $zero, L_80802374
    if (ctx->r2 == 0) {
        // 0x80802358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802374;
    }
    // 0x80802358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080235C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4254) << 16);
    // 0x80802360: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X43D4) << 16);
    // 0x80802364: addiu       $a3, $a3, 0x43D4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X43D4));
    // 0x80802368: addiu       $a2, $a2, 0x4254
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4254));
    // 0x8080236C: jal         0x80089D28
    // 0x80802370: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_136;
    // 0x80802370: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_136:
L_80802374:
    // 0x80802374: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80802378:
    // 0x80802378: addiu       $a0, $zero, 0xFB
    ctx->r4 = ADD32(0, 0XFB);
    // 0x8080237C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802380: srl         $t8, $t6, 10
    ctx->r24 = S32(U32(ctx->r14) >> 10);
    // 0x80802384: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x80802388: bnel        $at, $zero, L_808023B4
    if (ctx->r1 != 0) {
        // 0x8080238C: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_808023B4;
    }
    goto skip_21;
    // 0x8080238C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    skip_21:
    // 0x80802390: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x80802394: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802398: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8080239C: sll         $t2, $t1, 20
    ctx->r10 = S32(ctx->r9 << 20);
    // 0x808023A0: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x808023A4: bne         $t3, $at, L_808023B0
    if (ctx->r11 != ctx->r1) {
        // 0x808023A8: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_808023B0;
    }
    // 0x808023A8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x808023AC: sb          $t4, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r12;
L_808023B0:
    // 0x808023B0: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
L_808023B4:
    // 0x808023B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808023B8: lbu         $t9, 0x92($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X92);
    // 0x808023BC: bne         $t9, $at, L_808023CC
    if (ctx->r25 != ctx->r1) {
        // 0x808023C0: nop
    
            goto L_808023CC;
    }
    // 0x808023C0: nop

    // 0x808023C4: jal         0x800D2498
    // 0x808023C8: lbu         $a1, 0x93($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X93);
    func_800D2498(rdram, ctx);
        goto after_137;
    // 0x808023C8: lbu         $a1, 0x93($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X93);
    after_137:
L_808023CC:
    // 0x808023CC: jal         0x80800000
    // 0x808023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chevilmumbo(rdram, ctx);
        goto after_138;
    // 0x808023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_138:
    // 0x808023D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808023D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808023DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808023E0: jr          $ra
    // 0x808023E4: nop

    return;
    // 0x808023E4: nop

;}
RECOMP_FUNC void func_800A0CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0CFC: jal         0x800A0D14
    // 0x800A0D00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800A0D14(rdram, ctx);
        goto after_0;
    // 0x800A0D00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x800A0D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0D0C: jr          $ra
    // 0x800A0D10: nop

    return;
    // 0x800A0D10: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B98: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083B98);
    return;
    // 0x80083B9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808006BC_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006C8: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x808006CC: beql        $t7, $zero, L_8080070C
    if (ctx->r15 == 0) {
        // 0x808006D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080070C;
    }
    goto skip_0;
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006D4: jal         0x800CEAD0
    // 0x808006D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_0;
    // 0x808006D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808006DC: beql        $v0, $zero, L_8080070C
    if (ctx->r2 == 0) {
        // 0x808006E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080070C;
    }
    goto skip_1;
    // 0x808006E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808006E4: jal         0x800CEAA8
    // 0x808006E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x808006E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808006EC: beq         $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006F0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808006FC;
    }
    // 0x808006F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006F4: jal         0x800CE88C
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_808006FC:
    // 0x808006FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800700: jal         0x80101FDC
    // 0x80800704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080070C:
    // 0x8080070C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
