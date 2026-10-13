#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80115DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115DEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80115DF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115DF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80115DF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80115DFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80115E00: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80115E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80115E08: lbu         $t6, 0x1D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1D);
    // 0x80115E0C: bnel        $t6, $zero, L_80115E24
    if (ctx->r14 != 0) {
        // 0x80115E10: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80115E24;
    }
    goto skip_0;
    // 0x80115E10: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80115E14: jal         0x80115D88
    // 0x80115E18: nop

    func_80115D88(rdram, ctx);
        goto after_0;
    // 0x80115E18: nop

    after_0:
    // 0x80115E1C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80115E20: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_80115E24:
    // 0x80115E24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80115E28: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80115E2C: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80115E30: swc1        $f6, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f6.u32l;
    // 0x80115E34: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80115E38: lwc1        $f12, 0x20($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80115E3C: jal         0x800F1DCC
    // 0x80115E40: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80115E40: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    after_1:
    // 0x80115E44: jal         0x800F2100
    // 0x80115E48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80115E48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80115E4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80115E50: lwc1        $f8, 0x6614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6614);
    // 0x80115E54: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80115E58: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80115E5C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80115E60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80115E64: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80115E68: swc1        $f18, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f18.u32l;
    // 0x80115E6C: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x80115E70: sb          $t9, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = ctx->r25;
    // 0x80115E74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80115E78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80115E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80115E80: jr          $ra
    // 0x80115E84: nop

    return;
    // 0x80115E84: nop

;}
RECOMP_FUNC void chpiranha_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1804, 0X1B60) << 16);
    // 0x80801A64: jr          $ra
    // 0x80801A68: addiu       $v0, $v0, 0x1B60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1B60));
    return;
    // 0x80801A68: addiu       $v0, $v0, 0x1B60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1B60));
;}
RECOMP_FUNC void _idflasha_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D78: syscall     738
    recomp_syscall_handler(rdram, ctx, 0x80088D78);
    return;
    // 0x80088D7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _baflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BB8: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084BB8);
    return;
    // 0x80084BBC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void glsavegame_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808004A8: lb          $t6, 0x762A($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X762A);
    // 0x808004AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808004B0: jr          $ra
    // 0x808004B4: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x808004B4: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800A84EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A84EC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A84F0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A84F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A84F8: addiu       $t8, $t8, 0x7688
    ctx->r24 = ADD32(ctx->r24, 0X7688);
    // 0x800A84FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8500: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800A8504: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800A8508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A850C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8510: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800A8514: beq         $a2, $zero, L_800A852C
    if (ctx->r6 == 0) {
        // 0x800A8518: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800A852C;
    }
    // 0x800A8518: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A851C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A8520: jal         0x800158E4
    // 0x800A8524: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800158E4(rdram, ctx);
        goto after_0;
    // 0x800A8524: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A8528: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_800A852C:
    // 0x800A852C: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x800A8530: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A8534: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A8538: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800A853C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800A8540: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800A8544: jal         0x800A8424
    // 0x800A8548: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800A8424(rdram, ctx);
        goto after_1;
    // 0x800A8548: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A854C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800A8550: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800A8554: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8558: jal         0x8001592C
    // 0x800A855C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8001592C(rdram, ctx);
        goto after_2;
    // 0x800A855C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800A8560: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A8564: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A8568: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A856C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800A8570: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800A8574: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800A8578: beql        $a1, $zero, L_800A858C
    if (ctx->r5 == 0) {
        // 0x800A857C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800A858C;
    }
    goto skip_0;
    // 0x800A857C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x800A8580: jal         0x80015CE8
    // 0x800A8584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80015CE8(rdram, ctx);
        goto after_3;
    // 0x800A8584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800A8588: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800A858C:
    // 0x800A858C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x800A8590: jal         0x800C54CC
    // 0x800A8594: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800C54CC(rdram, ctx);
        goto after_4;
    // 0x800A8594: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x800A8598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A859C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A85A0: jr          $ra
    // 0x800A85A4: nop

    return;
    // 0x800A85A4: nop

;}
RECOMP_FUNC void _chhoney_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B78: syscall     424
    recomp_syscall_handler(rdram, ctx, 0x80086B78);
    return;
    // 0x80086B7C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void glcutDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800394: jr          $ra
    // 0x80800398: lbu         $v0, 0x75F1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75F1);
    return;
    // 0x80800398: lbu         $v0, 0x75F1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75F1);
;}
RECOMP_FUNC void func_8001A1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A1E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001A1EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A1F0: jal         0x8001A0F0
    // 0x8001A1F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8001A0F0(rdram, ctx);
        goto after_0;
    // 0x8001A1F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001A1F8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A1FC: addiu       $v1, $v1, -0x4128
    ctx->r3 = ADD32(ctx->r3, -0X4128);
    // 0x8001A200: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8001A204: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8001A208: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001A20C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8001A210: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8001A214: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001A218: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001A21C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001A220: addiu       $t7, $t7, -0x4308
    ctx->r15 = ADD32(ctx->r15, -0X4308);
    // 0x8001A224: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A228: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001A22C: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8001A230: jal         0x8001A11C
    // 0x8001A234: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8001A11C(rdram, ctx);
        goto after_1;
    // 0x8001A234: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8001A238: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A23C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001A240: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8001A244: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A248: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8001A24C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8001A250: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8001A254: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001A258: jal         0x80013D10
    // 0x8001A25C: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    func_80013D10(rdram, ctx);
        goto after_2;
    // 0x8001A25C: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    after_2:
    // 0x8001A260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A268: jr          $ra
    // 0x8001A26C: nop

    return;
    // 0x8001A26C: nop

;}
RECOMP_FUNC void bapulse_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gcdialogcamera_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080022C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800230: jal         0x800856F0
    // 0x80800234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080023C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void func_8080064C_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800654: jal         0x8010C710
    // 0x80800658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8010C710(rdram, ctx);
        goto after_0;
    // 0x80800658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080065C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800668: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080066C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x80800670: jal         0x8010CD88
    // 0x80800674: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8010CD88(rdram, ctx);
        goto after_1;
    // 0x80800674: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800678: bne         $v0, $zero, L_80800688
    if (ctx->r2 != 0) {
        // 0x8080067C: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800688;
    }
    // 0x8080067C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800680: b           L_808006D0
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006D0;
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800688:
    // 0x80800688: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCDC) << 16);
    // 0x8080068C: lwc1        $f6, 0xCDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCDC));
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCE0) << 16);
    // 0x80800694: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80800698: nop

    // 0x8080069C: bc1t        L_808006B8
    if (c1cs) {
        // 0x808006A0: nop
    
            goto L_808006B8;
    }
    // 0x808006A0: nop

    // 0x808006A4: lwc1        $f8, 0xCE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCE0));
    // 0x808006A8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808006AC: nop

    // 0x808006B0: bc1f        L_808006C0
    if (!c1cs) {
        // 0x808006B4: nop
    
            goto L_808006C0;
    }
    // 0x808006B4: nop

L_808006B8:
    // 0x808006B8: b           L_808006D0
    // 0x808006BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006D0;
    // 0x808006BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006C0:
    // 0x808006C0: jal         0x800F54E4
    // 0x808006C4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808006C4: nop

    after_2:
    // 0x808006C8: jal         0x800F6478
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_3;
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_808006D0:
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void func_80092D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092D44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80092D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092D4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80092D50: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80092D54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80092D58: jal         0x800921E0
    // 0x80092D5C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092D5C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80092D60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80092D64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80092D68: jal         0x800921E0
    // 0x80092D6C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800921E0(rdram, ctx);
        goto after_1;
    // 0x80092D6C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80092D70: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80092D74: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80092D78: jal         0x800EE780
    // 0x80092D7C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80092D7C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80092D80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80092D84: jal         0x800EF334
    // 0x80092D88: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80092D88: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_3:
    // 0x80092D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092D90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80092D94: jr          $ra
    // 0x80092D98: nop

    return;
    // 0x80092D98: nop

;}
RECOMP_FUNC void rare_memset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCF8: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x8001BCFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BD00: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001BD04: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8001BD08: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001BD0C: beq         $at, $zero, L_8001BD24
    if (ctx->r1 == 0) {
        // 0x8001BD10: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8001BD24;
    }
    // 0x8001BD10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001BD14:
    // 0x8001BD14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BD18: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001BD1C: bne         $at, $zero, L_8001BD14
    if (ctx->r1 != 0) {
        // 0x8001BD20: sb          $a1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r5;
            goto L_8001BD14;
    }
    // 0x8001BD20: sb          $a1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r5;
L_8001BD24:
    // 0x8001BD24: jr          $ra
    // 0x8001BD28: nop

    return;
    // 0x8001BD28: nop

;}
RECOMP_FUNC void _sucoasterdata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A250: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A250);
    return;
    // 0x8008A254: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gzpublic_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A980: syscall     882
    recomp_syscall_handler(rdram, ctx, 0x8008A980);
    return;
    // 0x8008A984: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chclimbbase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080000C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800018: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x8080001C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800020: addiu       $a1, $zero, 0x1FA
    ctx->r5 = ADD32(0, 0X1FA);
    // 0x80800024: jal         0x800882E0
    // 0x80800028: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    _gccubesearch_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x8080002C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800030: addiu       $a1, $zero, 0x1FB
    ctx->r5 = ADD32(0, 0X1FB);
    // 0x80800034: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800038: jal         0x800882E0
    // 0x8080003C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _gccubesearch_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080003C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800040: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800044: bne         $v1, $zero, L_8080005C
    if (ctx->r3 != 0) {
        // 0x80800048: nop
    
            goto L_8080005C;
    }
    // 0x80800048: nop

    // 0x8080004C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800050: nop
    
            goto L_8080005C;
    }
    // 0x80800050: nop

    // 0x80800054: b           L_808000E8
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E8;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080005C:
    // 0x8080005C: beq         $v1, $zero, L_808000A4
    if (ctx->r3 == 0) {
        // 0x80800060: nop
    
            goto L_808000A4;
    }
    // 0x80800060: nop

    // 0x80800064: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800070: jal         0x800EFB8C
    // 0x80800074: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800EFB8C(rdram, ctx);
        goto after_2;
    // 0x80800074: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800078: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x800EFB8C
    // 0x80800084: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EFB8C(rdram, ctx);
        goto after_3;
    // 0x80800084: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80800088: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080008C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800090: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800094: nop

    // 0x80800098: bc1f        L_808000A4
    if (!c1cs) {
        // 0x8080009C: nop
    
            goto L_808000A4;
    }
    // 0x8080009C: nop

    // 0x808000A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000A4:
    // 0x808000A4: beq         $v1, $zero, L_808000CC
    if (ctx->r3 == 0) {
        // 0x808000A8: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_808000CC;
    }
    // 0x808000A8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808000AC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808000B0: jal         0x800EE7F8
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x808000B8: lhu         $t6, 0x6E($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X6E);
    // 0x808000BC: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x808000C0: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808000C4: b           L_808000E4
    // 0x808000C8: sh          $t8, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r24;
        goto L_808000E4;
    // 0x808000C8: sh          $t8, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r24;
L_808000CC:
    // 0x808000CC: jal         0x800EE7F8
    // 0x808000D0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x808000D4: lhu         $t9, 0x6E($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X6E);
    // 0x808000D8: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808000DC: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x808000E0: sh          $t1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r9;
L_808000E4:
    // 0x808000E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E8:
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808000F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C58: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C58);
    return;
    // 0x80082C5C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void cadbfunc_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C68: jal         0x80800BE0
    // 0x80800C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800BE0_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C70: bne         $v0, $zero, L_80800C80
    if (ctx->r2 != 0) {
        // 0x80800C74: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800C80;
    }
    // 0x80800C74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800C78: b           L_80800C8C
    // 0x80800C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C8C;
    // 0x80800C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C80:
    // 0x80800C80: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80800C8C:
    // 0x80800C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C94: jr          $ra
    // 0x80800C98: nop

    return;
    // 0x80800C98: nop

;}
RECOMP_FUNC void func_800D1604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D160C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D1610: jal         0x8001B084
    // 0x800D1614: lw          $a0, -0x4DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4DB0);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800D1614: lw          $a0, -0x4DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4DB0);
    after_0:
    // 0x800D1618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D161C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D1620: sw          $zero, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = 0;
    // 0x800D1624: jr          $ra
    // 0x800D1628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D1628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800008_bahold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x80800014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800018: beq         $a1, $zero, L_80800028
    if (ctx->r5 == 0) {
        // 0x8080001C: sw          $a1, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->r5;
            goto L_80800028;
    }
    // 0x8080001C: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    // 0x80800020: b           L_80800028
    // 0x80800024: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800028;
    // 0x80800024: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800028:
    // 0x80800028: jal         0x8009ADF0
    // 0x8080002C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5B8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5B8);
    return;
    // 0x8008A5BC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void susplinet_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80800360: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800364: lh          $t8, 0x36($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X36);
    // 0x80800368: jr          $ra
    // 0x8080036C: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    return;
    // 0x8080036C: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
;}
RECOMP_FUNC void func_80800720_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080072C: jal         0x80100094
    // 0x80800730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800734: beq         $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x80800738: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800744;
    }
    // 0x80800738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080073C: jal         0x800897C8
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800744:
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080074C: jr          $ra
    // 0x80800750: nop

    return;
    // 0x80800750: nop

;}
RECOMP_FUNC void boot___osResetGlobalIntMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80800D74_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D7C: jal         0x800DC0C0
    // 0x80800D80: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800D80: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2478) << 16);
    // 0x80800D88: lwc1        $f4, 0x2478($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2478));
    // 0x80800D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D90: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800D94: nop

    // 0x80800D98: bc1fl       L_80800E38
    if (!c1cs) {
        // 0x80800D9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E38;
    }
    goto skip_0;
    // 0x80800D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800DA0: jal         0x800DC128
    // 0x80800DA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800DA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800DA8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800DAC: jal         0x800B53A4
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800DB4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800DB8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800DBC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800DC0: jal         0x800DC178
    // 0x80800DC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800DC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800DC8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800DCC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800DD0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800DD4: jal         0x800DC178
    // 0x80800DD8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800DD8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800DDC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800DE0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800DE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800DE8: lwc1        $f6, 0x38($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800DEC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800DF0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800DF4: jal         0x800EEB9C
    // 0x80800DF8: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x80800DF8: nop

    after_5:
    // 0x80800DFC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800E00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800E04: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1688, 0X26A0) << 16);
    // 0x80800E08: addiu       $t7, $t7, 0x26A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1688, 0X26A0));
    // 0x80800E0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E14: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800E18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800E20: jal         0x800BABB8
    // 0x80800E24: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800E24: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80800E28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E2C: jal         0x800BA22C
    // 0x80800E30: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800E30: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E38:
    // 0x80800E38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800E3C: jr          $ra
    // 0x80800E40: nop

    return;
    // 0x80800E40: nop

;}
RECOMP_FUNC void _chlagoonbilldrillcover_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086768: syscall     367
    recomp_syscall_handler(rdram, ctx, 0x80086768);
    return;
    // 0x8008676C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800274_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080027C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800288: bne         $a1, $at, L_808002A0
    if (ctx->r5 != ctx->r1) {
        // 0x8080028C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808002A0;
    }
    // 0x8080028C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800290: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800298: b           L_8080035C
    // 0x8080029C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
        goto L_8080035C;
    // 0x8080029C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
L_808002A0:
    // 0x808002A0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    // 0x808002A4: jal         0x800DA298
    // 0x808002A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002AC: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002B0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808002BC;
    }
    // 0x808002B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002B4: b           L_8080035C
    // 0x808002B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080035C;
    // 0x808002B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002BC:
    // 0x808002BC: slti        $at, $a1, 0x68
    ctx->r1 = SIGNED(ctx->r5) < 0X68 ? 1 : 0;
    // 0x808002C0: bne         $at, $zero, L_8080035C
    if (ctx->r1 != 0) {
        // 0x808002C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080035C;
    }
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002C8: slti        $at, $a1, 0x6C
    ctx->r1 = SIGNED(ctx->r5) < 0X6C ? 1 : 0;
    // 0x808002CC: beq         $at, $zero, L_8080035C
    if (ctx->r1 == 0) {
        // 0x808002D0: addiu       $v1, $a1, -0x68
        ctx->r3 = ADD32(ctx->r5, -0X68);
            goto L_8080035C;
    }
    // 0x808002D0: addiu       $v1, $a1, -0x68
    ctx->r3 = ADD32(ctx->r5, -0X68);
    // 0x808002D4: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x808002D8: beq         $t6, $zero, L_808002E8
    if (ctx->r14 == 0) {
        // 0x808002DC: andi        $t2, $v1, 0x1
        ctx->r10 = ctx->r3 & 0X1;
            goto L_808002E8;
    }
    // 0x808002DC: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x808002E0: b           L_808002EC
    // 0x808002E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808002EC;
    // 0x808002E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808002E8:
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002F0: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x808002F4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808002F8: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002FC: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x80800300: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x80800304: andi        $t9, $t7, 0xFE00
    ctx->r25 = ctx->r15 & 0XFE00;
    // 0x80800308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080030C: mflo        $t3
    ctx->r11 = lo;
    // 0x80800310: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80800314: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800318: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8080031C: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80800320: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x80800324: andi        $t2, $t0, 0x1FF
    ctx->r10 = ctx->r8 & 0X1FF;
    // 0x80800328: bne         $t2, $at, L_80800354
    if (ctx->r10 != ctx->r1) {
        // 0x8080032C: nop
    
            goto L_80800354;
    }
    // 0x8080032C: nop

    // 0x80800330: jal         0x800DA544
    // 0x80800334: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800334: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80800338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800344: jal         0x80085708
    // 0x80800348: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800348: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x8080034C: jal         0x800FC6B0
    // 0x80800350: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x80800350: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
L_80800354:
    // 0x80800354: b           L_8080035C
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080035C;
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080035C:
    // 0x8080035C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E38: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E38);
    return;
    // 0x80082E3C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_8080175C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080175C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801764: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801768: lwc1        $f0, 0x98($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8080176C: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80801770: jal         0x800A4C68
    // 0x80801774: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800A4C68(rdram, ctx);
        goto after_0;
    // 0x80801774: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80801778: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080177C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801780: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801784: jal         0x800C5148
    // 0x80801788: nop

    func_800C5148(rdram, ctx);
        goto after_1;
    // 0x80801788: nop

    after_1:
    // 0x8080178C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801790: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801794: jr          $ra
    // 0x80801798: nop

    return;
    // 0x80801798: nop

;}
RECOMP_FUNC void chcrusher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1624, 0XC40) << 16);
    // 0x8080072C: jr          $ra
    // 0x80800730: addiu       $v0, $v0, 0xC40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XC40));
    return;
    // 0x80800730: addiu       $v0, $v0, 0xC40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XC40));
;}
RECOMP_FUNC void func_80801680_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080168C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801690: jal         0x80100094
    // 0x80801694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080169C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808016A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808016A4: addiu       $t8, $t7, -0xC
    ctx->r24 = ADD32(ctx->r15, -0XC);
    // 0x808016A8: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x808016AC: beq         $at, $zero, L_80801734
    if (ctx->r1 == 0) {
        // 0x808016B0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801734;
    }
    // 0x808016B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808016B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X375C) << 16);
    // 0x808016B8: addu        $at, $at, $t8
    gpr jr_addend_808016C0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808016BC: lw          $t8, 0x375C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X375C));
    // 0x808016C0: jr          $t8
    // 0x808016C4: nop

    switch (jr_addend_808016C0 >> 2) {
        case 0: goto L_808016C8; break;
        case 1: goto L_808016C8; break;
        case 2: goto L_80801734; break;
        case 3: goto L_80801734; break;
        case 4: goto L_808016D8; break;
        case 5: goto L_808016D8; break;
        case 6: goto L_80801734; break;
        case 7: goto L_80801734; break;
        case 8: goto L_80801734; break;
        case 9: goto L_80801734; break;
        case 10: goto L_80801734; break;
        case 11: goto L_808016E8; break;
        default: switch_error(__func__, 0x808016C0, 0x8080375C);
    }
    // 0x808016C4: nop

L_808016C8:
    // 0x808016C8: jal         0x80801964
    // 0x808016CC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80801964_chklungo(rdram, ctx);
        goto after_1;
    // 0x808016CC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
    // 0x808016D0: b           L_80801738
    // 0x808016D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801738;
    // 0x808016D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016D8:
    // 0x808016D8: jal         0x80801964
    // 0x808016DC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801964_chklungo(rdram, ctx);
        goto after_2;
    // 0x808016DC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x808016E0: b           L_80801738
    // 0x808016E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801738;
    // 0x808016E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016E8:
    // 0x808016E8: lh          $t9, 0x1A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1A);
    // 0x808016EC: bne         $t9, $zero, L_8080171C
    if (ctx->r25 != 0) {
        // 0x808016F0: nop
    
            goto L_8080171C;
    }
    // 0x808016F0: nop

    // 0x808016F4: jal         0x80801964
    // 0x808016F8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80801964_chklungo(rdram, ctx);
        goto after_3;
    // 0x808016F8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_3:
    // 0x808016FC: jal         0x800FC6B0
    // 0x80801700: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x80801700: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x80801704: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    // 0x80801708: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8080170C: jal         0x80101180
    // 0x80801710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80801710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80801714: b           L_80801738
    // 0x80801718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801738;
    // 0x80801718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080171C:
    // 0x8080171C: jal         0x800FC6B0
    // 0x80801720: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC6B0(rdram, ctx);
        goto after_6;
    // 0x80801720: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x80801724: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    // 0x80801728: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8080172C: jal         0x80101180
    // 0x80801730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80801730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80801734:
    // 0x80801734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801738:
    // 0x80801738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080173C: jr          $ra
    // 0x80801740: nop

    return;
    // 0x80801740: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1E0: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1E0);
    return;
    // 0x8008A1E4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void ncbafixpos_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080018C: jal         0x800A5800
    // 0x80800190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x80800190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800194: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800198: jal         0x80085668
    // 0x8080019C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_1;
    // 0x8080019C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808001A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x808001A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808001B0: jal         0x80085668
    // 0x808001B4: sb          $t6, 0x18($t7)
    MEM_B(0X18, ctx->r15) = ctx->r14;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_2;
    // 0x808001B4: sb          $t6, 0x18($t7)
    MEM_B(0X18, ctx->r15) = ctx->r14;
    after_2:
    // 0x808001B8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x808001C0: sb          $t8, 0x19($t9)
    MEM_B(0X19, ctx->r25) = ctx->r24;
    // 0x808001C4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x808001C8: jal         0x800855A0
    // 0x808001CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    _cadbfunc_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808001CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x808001D0: jal         0x80085580
    // 0x808001D4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808001D4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x808001D8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001DC: jal         0x800855B0
    // 0x808001E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _cadbfunc_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808001E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001EC: jal         0x80111B8C
    // 0x808001F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80111B8C(rdram, ctx);
        goto after_6;
    // 0x808001F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808001F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001F8: jal         0x800855C0
    // 0x808001FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _cadbfunc_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x808001FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80800200: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8080020C: sb          $zero, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = 0;
    // 0x80800210: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80800214: jal         0x80112570
    // 0x80800218: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80112570(rdram, ctx);
        goto after_8;
    // 0x80800218: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_8:
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800224: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_80094DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094DA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094DAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80094DB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80094DB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80094DB8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80094DBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094DC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80094DC4: jal         0x80094C64
    // 0x80094DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80094C64(rdram, ctx);
        goto after_0;
    // 0x80094DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80094DCC: beq         $v0, $zero, L_80094E24
    if (ctx->r2 == 0) {
        // 0x80094DD0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094E24;
    }
    // 0x80094DD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094DD4:
    // 0x80094DD4: jal         0x800883E8
    // 0x80094DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80094DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80094DDC: beql        $v0, $zero, L_80094E10
    if (ctx->r2 == 0) {
        // 0x80094DE0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80094E10;
    }
    goto skip_0;
    // 0x80094DE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80094DE4: jal         0x800883E0
    // 0x80094DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80094DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80094DEC: jal         0x800D1C5C
    // 0x80094DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1C5C(rdram, ctx);
        goto after_3;
    // 0x80094DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80094DF4: jal         0x800D27F4
    // 0x80094DF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D27F4(rdram, ctx);
        goto after_4;
    // 0x80094DF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80094DFC: bnel        $v0, $zero, L_80094E10
    if (ctx->r2 != 0) {
        // 0x80094E00: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80094E10;
    }
    goto skip_1;
    // 0x80094E00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80094E04: b           L_80094E28
    // 0x80094E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80094E28;
    // 0x80094E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80094E0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80094E10:
    // 0x80094E10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80094E14: jal         0x80094C64
    // 0x80094E18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80094C64(rdram, ctx);
        goto after_5;
    // 0x80094E18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80094E1C: bne         $v0, $zero, L_80094DD4
    if (ctx->r2 != 0) {
        // 0x80094E20: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094DD4;
    }
    // 0x80094E20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094E24:
    // 0x80094E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094E28:
    // 0x80094E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80094E2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80094E30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80094E34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80094E38: jr          $ra
    // 0x80094E3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80094E3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800C08_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C14: jal         0x80101F24
    // 0x80800C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5000) << 16);
    // 0x80800C20: lwc1        $f4, 0x5000($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5000));
    // 0x80800C24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5004) << 16);
    // 0x80800C28: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800C2C: nop

    // 0x80800C30: bc1tl       L_80800D10
    if (c1cs) {
        // 0x80800C34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D10;
    }
    goto skip_0;
    // 0x80800C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800C38: lwc1        $f6, 0x5004($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5004));
    // 0x80800C3C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800C40: nop

    // 0x80800C44: bc1tl       L_80800D10
    if (c1cs) {
        // 0x80800C48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D10;
    }
    goto skip_1;
    // 0x80800C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800C4C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800C50: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800C54: bgezl       $t8, L_80800D10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800C58: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D10;
    }
    goto skip_2;
    // 0x80800C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800C5C: jal         0x8001210C
    // 0x80800C60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x80800C60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x80800C64: beq         $v0, $zero, L_80800D0C
    if (ctx->r2 == 0) {
        // 0x80800C68: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800D0C;
    }
    // 0x80800C68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800C6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800C70: jal         0x8008A0E0
    // 0x80800C74: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800C74: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800C78: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800C7C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800C80: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800C84: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800C88: bne         $t0, $zero, L_80800CE0
    if (ctx->r8 != 0) {
        // 0x80800C8C: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800CE0;
    }
    // 0x80800C8C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800C90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C98: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1852, 0X5588) << 16);
    // 0x80800C9C: addiu       $t1, $t1, 0x5588
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1852, 0X5588));
    // 0x80800CA0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800CA4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800CB0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80800CB4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800CB8: jal         0x800BBCB8
    // 0x80800CBC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800CBC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x80800CC0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X55C0) << 16);
    // 0x80800CC4: addiu       $a3, $a3, 0x55C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X55C0));
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CCC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800CD0: jal         0x80089D50
    // 0x80800CD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800CD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800CD8: b           L_80800D10
    // 0x80800CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D10;
    // 0x80800CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CE0:
    // 0x80800CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CE4: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1852, 0X55DC) << 16);
    // 0x80800CE8: addiu       $t2, $t2, 0x55DC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1852, 0X55DC));
    // 0x80800CEC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800CF0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800CFC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80800D00: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800D04: jal         0x800BBCB8
    // 0x80800D08: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800D08: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
L_80800D0C:
    // 0x80800D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D10:
    // 0x80800D10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D18: jr          $ra
    // 0x80800D1C: nop

    return;
    // 0x80800D1C: nop

;}
RECOMP_FUNC void func_808003DC_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E8: jal         0x8008CABC
    // 0x808003EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003F0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808003F4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x808003F8: lw          $v1, 0x15C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X15C);
    // 0x808003FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800400: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800404: beq         $v1, $at, L_8080042C
    if (ctx->r3 == ctx->r1) {
        // 0x80800408: lui         $a1, 0x3E19
        ctx->r5 = S32(0X3E19 << 16);
            goto L_8080042C;
    }
    // 0x80800408: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x8080040C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800410: beq         $v1, $at, L_808004F0
    if (ctx->r3 == ctx->r1) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F0;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080041C: beq         $v1, $at, L_80800664
    if (ctx->r3 == ctx->r1) {
        // 0x80800420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800664;
    }
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: b           L_8080068C
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080068C;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080042C:
    // 0x8080042C: jal         0x8008B348
    // 0x80800430: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800430: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_1:
    // 0x80800434: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800444;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: jal         0x80095760
    // 0x80800440: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80800440: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_2:
L_80800444:
    // 0x80800444: lui         $a1, 0x3E39
    ctx->r5 = S32(0X3E39 << 16);
    // 0x80800448: ori         $a1, $a1, 0xDB23
    ctx->r5 = ctx->r5 | 0XDB23;
    // 0x8080044C: jal         0x8008B348
    // 0x80800450: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800450: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800454: beq         $v0, $zero, L_8080047C
    if (ctx->r2 == 0) {
        // 0x80800458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080047C;
    }
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: addiu       $a1, $zero, 0x50D
    ctx->r5 = ADD32(0, 0X50D);
    // 0x80800460: jal         0x8009DE38
    // 0x80800464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800468: lui         $a2, 0x3F90
    ctx->r6 = S32(0X3F90 << 16);
    // 0x8080046C: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x8009DBF0
    // 0x80800478: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DBF0(rdram, ctx);
        goto after_5;
    // 0x80800478: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_5:
L_8080047C:
    // 0x8080047C: lui         $a1, 0x3EAB
    ctx->r5 = S32(0X3EAB << 16);
    // 0x80800480: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800484: jal         0x8008B348
    // 0x80800488: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800488: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8080048C: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: jal         0x80084F30
    // 0x80800498: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _bamum_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800498: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x8080049C: jal         0x80800060
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800060_bsmumattack(rdram, ctx);
        goto after_8;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_808004A4:
    // 0x808004A4: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x808004A8: ori         $a1, $a1, 0xCB3
    ctx->r5 = ctx->r5 | 0XCB3;
    // 0x808004AC: jal         0x8008B348
    // 0x808004B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808004B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x808004B4: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x808004B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800688;
    }
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x800919F4
    // 0x808004C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_10;
    // 0x808004C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x808004C4: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x808001B4
    // 0x808004D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001B4_bsmumattack(rdram, ctx);
        goto after_11;
    // 0x808004D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808004D8: b           L_8080068C
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080068C;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004E0:
    // 0x808004E0: jal         0x808001B4
    // 0x808004E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001B4_bsmumattack(rdram, ctx);
        goto after_12;
    // 0x808004E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808004E8: b           L_8080068C
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080068C;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F0:
    // 0x808004F0: jal         0x800852F0
    // 0x808004F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_13;
    // 0x808004F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x80085300
    // 0x80800500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_14;
    // 0x80800500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800504: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800508: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080050C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800510: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800514: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800518: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080051C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800520: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800524: jal         0x800F10B4
    // 0x80800528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80800528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8080052C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800530: jal         0x80084F30
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamum_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800538: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080053C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800540: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800544: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800548: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080054C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800550: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800554: jal         0x800F10B4
    // 0x80800558: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x80800558: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x8080055C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800560: jal         0x808000AC
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_bsmumattack(rdram, ctx);
        goto after_18;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080056C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800570: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800574: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800578: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080057C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800580: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800584: jal         0x800F10B4
    // 0x80800588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x80800588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x8080058C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800590: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800594: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x80085308
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isAt_falling(rdram, ctx);
        goto after_20;
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808005A4: beql        $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x808005A8: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_808005B8;
    }
    goto skip_0;
    // 0x808005A8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    skip_0:
    // 0x808005AC: jal         0x800853E8
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawandglow_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808005B4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
L_808005B8:
    // 0x808005B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: jal         0x80085308
    // 0x808005C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isAt_falling(rdram, ctx);
        goto after_22;
    // 0x808005C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x808005C8: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D8;
    }
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80095774
    // 0x808005D4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_clear(rdram, ctx);
        goto after_23;
    // 0x808005D4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_23:
L_808005D8:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x80085330
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_24;
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x808005E4: beql        $v0, $zero, L_80800634
    if (ctx->r2 == 0) {
        // 0x808005E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800634;
    }
    goto skip_1;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808005EC: jal         0x800DC0C0
    // 0x808005F0: nop

    func_800DC0C0(rdram, ctx);
        goto after_25;
    // 0x808005F0: nop

    after_25:
    // 0x808005F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800608: addiu       $a1, $zero, 0x513
    ctx->r5 = ADD32(0, 0X513);
    // 0x8080060C: bc1f        L_80800628
    if (!c1cs) {
        // 0x80800610: nop
    
            goto L_80800628;
    }
    // 0x80800610: nop

    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: jal         0x8009DE38
    // 0x8080061C: addiu       $a1, $zero, 0x512
    ctx->r5 = ADD32(0, 0X512);
    func_8009DE38(rdram, ctx);
        goto after_26;
    // 0x8080061C: addiu       $a1, $zero, 0x512
    ctx->r5 = ADD32(0, 0X512);
    after_26:
    // 0x80800620: b           L_80800634
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800634;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800628:
    // 0x80800628: jal         0x8009DE38
    // 0x8080062C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_27;
    // 0x8080062C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_27:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800634:
    // 0x80800634: jal         0x800919F4
    // 0x80800638: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_28;
    // 0x80800638: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_28:
    // 0x8080063C: beq         $v0, $zero, L_80800650
    if (ctx->r2 == 0) {
        // 0x80800640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800650;
    }
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x80085330
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_29;
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8080064C: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x80800650: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800688;
    }
L_80800650:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x808001B4
    // 0x80800658: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001B4_bsmumattack(rdram, ctx);
        goto after_30;
    // 0x80800658: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_30:
    // 0x8080065C: b           L_8080068C
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080068C;
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800664:
    // 0x80800664: jal         0x80084F30
    // 0x80800668: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bamum_entrypoint_5(rdram, ctx);
        goto after_31;
    // 0x80800668: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_31:
    // 0x8080066C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800670: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800674: jal         0x8008B348
    // 0x80800678: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_32;
    // 0x80800678: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_32:
    // 0x8080067C: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x80800680: addiu       $t6, $zero, 0xEF
        ctx->r14 = ADD32(0, 0XEF);
            goto L_80800688;
    }
    // 0x80800680: addiu       $t6, $zero, 0xEF
    ctx->r14 = ADD32(0, 0XEF);
    // 0x80800684: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_80800688:
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080068C:
    // 0x8080068C: jal         0x80095738
    // 0x80800690: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_isTrue(rdram, ctx);
        goto after_33;
    // 0x80800690: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_33:
    // 0x80800694: beq         $v0, $zero, L_808006A4
    if (ctx->r2 == 0) {
        // 0x80800698: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006A4;
    }
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x800853C8
    // 0x808006A0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    _bawandglow_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x808006A0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_34:
L_808006A4:
    // 0x808006A4: jal         0x808000E0
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000E0_bsmumattack(rdram, ctx);
        goto after_35;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x8009E5C8
    // 0x808006B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    bs_setState(rdram, ctx);
        goto after_36;
    // 0x808006B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_36:
    // 0x808006B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
RECOMP_FUNC void func_800F9F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F9F1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9F20: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800F9F24: jr          $ra
    // 0x800F9F28: lh          $v0, 0x5532($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5532);
    return;
    // 0x800F9F28: lh          $v0, 0x5532($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5532);
;}
RECOMP_FUNC void func_800B42DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B42DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B42E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B42E4: jal         0x8001B084
    // 0x800B42E8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B42E8: nop

    after_0:
    // 0x800B42EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B42F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B42F4: jr          $ra
    // 0x800B42F8: nop

    return;
    // 0x800B42F8: nop

;}
RECOMP_FUNC void func_808086B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808086B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808086B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808086B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808086BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808086C0: jal         0x80802458
    // 0x808086C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808086C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808086C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808086CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808086D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808086D4: beq         $a2, $at, L_808086F8
    if (ctx->r6 == ctx->r1) {
        // 0x808086D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808086F8;
    }
    // 0x808086D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808086DC: beq         $a2, $at, L_80808768
    if (ctx->r6 == ctx->r1) {
        // 0x808086E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808768;
    }
    // 0x808086E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808086E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808086E8: beq         $a2, $at, L_808087CC
    if (ctx->r6 == ctx->r1) {
        // 0x808086EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808087CC;
    }
    // 0x808086EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808086F0: b           L_80808834
    // 0x808086F4: sw          $a2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r6;
        goto L_80808834;
    // 0x808086F4: sw          $a2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r6;
L_808086F8:
    // 0x808086F8: jal         0x8009BB00
    // 0x808086FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808086FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808700: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA584) << 16);
    // 0x80808704: lwc1        $f4, -0x5A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA584));
    // 0x80808708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080870C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80808710: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80808714: jal         0x8009B9B0
    // 0x80808718: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80808718: nop

    after_2:
    // 0x8080871C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808720: jal         0x80802A40
    // 0x80808724: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80802A40_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808724: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80808728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080872C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80808730: jal         0x808025C8
    // 0x80808734: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_808025C8_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80808734: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80808738: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080873C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808740: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    // 0x80808744: jal         0x80800424
    // 0x80808748: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80808748: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x8080874C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80808750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808754: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x80808758: jal         0x8008CCBC
    // 0x8080875C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_6;
    // 0x8080875C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_6:
    // 0x80808760: b           L_80808830
    // 0x80808764: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80808830;
    // 0x80808764: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80808768:
    // 0x80808768: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8080876C: jal         0x8009B9B0
    // 0x80808770: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x80808770: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_7:
    // 0x80808774: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80808778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080877C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80808780: jal         0x8009E55C
    // 0x80808784: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    func_8009E55C(rdram, ctx);
        goto after_8;
    // 0x80808784: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    after_8:
    // 0x80808788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080878C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80808790: jal         0x8009E5A4
    // 0x80808794: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_9;
    // 0x80808794: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x80808798: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080879C: addiu       $a2, $a2, 0x42F0
    ctx->r6 = ADD32(ctx->r6, 0X42F0);
    // 0x808087A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808087A4: jal         0x8009E4E0
    // 0x808087A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E4E0(rdram, ctx);
        goto after_10;
    // 0x808087A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808087AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808087B0: jal         0x80095760
    // 0x808087B4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    baflag_set(rdram, ctx);
        goto after_11;
    // 0x808087B4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_11:
    // 0x808087B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808087BC: jal         0x80802A40
    // 0x808087C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80802A40_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x808087C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_12:
    // 0x808087C4: b           L_80808830
    // 0x808087C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80808830;
    // 0x808087C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_808087CC:
    // 0x808087CC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808087D0: jal         0x8080633C
    // 0x808087D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x808087D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_13:
    // 0x808087D8: jal         0x8009BB00
    // 0x808087DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x808087DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808087E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808087E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808087E8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808087EC: nop

    // 0x808087F0: bc1fl       L_80808804
    if (!c1cs) {
        // 0x808087F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808804;
    }
    goto skip_0;
    // 0x808087F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808087F8: jal         0x8009B9B0
    // 0x808087FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x808087FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
    // 0x80808800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80808804:
    // 0x80808804: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80808808: jal         0x8009E5A4
    // 0x8080880C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8009E5A4(rdram, ctx);
        goto after_16;
    // 0x8080880C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_16:
    // 0x80808810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808814: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80808818: jal         0x8009E55C
    // 0x8080881C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_17;
    // 0x8080881C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_17:
    // 0x80808820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808824: jal         0x80095774
    // 0x80808828: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    baflag_clear(rdram, ctx);
        goto after_18;
    // 0x80808828: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_18:
    // 0x8080882C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80808830:
    // 0x80808830: sw          $a2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r6;
L_80808834:
    // 0x80808834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080883C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80808840: jr          $ra
    // 0x80808844: nop

    return;
    // 0x80808844: nop

;}
RECOMP_FUNC void suquiz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080068C: jal         0x80800584
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    suquiz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800694: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800698: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080069C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808006A0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x808006A4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808006A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x808006B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF94) << 16);
    // 0x808006B4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808006B8: lwc1        $f0, 0xF94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF94));
    // 0x808006BC: jr          $ra
    // 0x808006C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808006C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800304_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080030C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800314: jal         0x800B53A4
    // 0x80800318: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800318: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x8080031C: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: addiu       $a2, $zero, 0x6F7
    ctx->r6 = ADD32(0, 0X6F7);
    // 0x80800328: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8080032C: lw          $t7, 0x18C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18C);
    // 0x80800330: jal         0x80800000
    // 0x80800334: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_80800000_bsdronexform(rdram, ctx);
        goto after_1;
    // 0x80800334: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80800338: jal         0x800B53A4
    // 0x8080033C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x8080033C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_2:
    // 0x80800340: lw          $t8, 0x18C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18C);
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: addiu       $a2, $zero, 0x6F8
    ctx->r6 = ADD32(0, 0X6F8);
    // 0x8080034C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80800350: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x80800354: jal         0x80800000
    // 0x80800358: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    func_80800000_bsdronexform(rdram, ctx);
        goto after_3;
    // 0x80800358: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_3:
    // 0x8080035C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800360: lw          $t0, 0x18C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18C);
    // 0x80800364: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080036C: swc1        $f0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f0.u32l;
    // 0x80800370: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
    // 0x80800374: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800378: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080037C: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x80800380: lw          $t2, 0x18C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18C);
    // 0x80800384: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X117C) << 16);
    // 0x80800388: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8080038C: lw          $t3, 0x18C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18C);
    // 0x80800390: swc1        $f6, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f6.u32l;
    // 0x80800394: lw          $t4, 0x18C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18C);
    // 0x80800398: lwc1        $f8, 0x117C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X117C));
    // 0x8080039C: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x808003A0: lw          $t5, 0x18C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18C);
    // 0x808003A4: sb          $zero, 0x1C($t5)
    MEM_B(0X1C, ctx->r13) = 0;
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80012F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012F04: jr          $ra
    // 0x80012F08: addiu       $v0, $v0, 0x5BB8
    ctx->r2 = ADD32(ctx->r2, 0X5BB8);
    return;
    // 0x80012F08: addiu       $v0, $v0, 0x5BB8
    ctx->r2 = ADD32(ctx->r2, 0X5BB8);
;}
RECOMP_FUNC void func_8008D214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008D218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D21C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008D220: jal         0x800C6E38
    // 0x8008D224: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D224: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x8008D228: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D22C: beq         $t6, $zero, L_8008D270
    if (ctx->r14 == 0) {
        // 0x8008D230: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D270;
    }
    // 0x8008D230: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D234: jal         0x800964DC
    // 0x8008D238: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800964DC(rdram, ctx);
        goto after_1;
    // 0x8008D238: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8008D23C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008D240: jal         0x80096364
    // 0x8008D244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80096364(rdram, ctx);
        goto after_2;
    // 0x8008D244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8008D248: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008D24C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008D250: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D254: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8008D258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D25C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8008D260: nop

    // 0x8008D264: bc1fl       L_8008D274
    if (!c1cs) {
        // 0x8008D268: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008D274;
    }
    goto skip_0;
    // 0x8008D268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008D26C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D270:
    // 0x8008D270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008D274:
    // 0x8008D274: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008D278: jr          $ra
    // 0x8008D27C: nop

    return;
    // 0x8008D27C: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BA8: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082BA8);
    return;
    // 0x80082BAC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_800261D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800261D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800261D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800261D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800261DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800261E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800261E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800261E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800261EC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x800261F0: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x800261F4: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x800261F8: sw          $t1, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r9;
    // 0x800261FC: addiu       $t2, $zero, 0xFC
    ctx->r10 = ADD32(0, 0XFC);
    // 0x80026200: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80026204: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80026208: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002620C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026214: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80026218: jal         0x8002ACE0
    // 0x8002621C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8002ACE0(rdram, ctx);
        goto after_0;
    // 0x8002621C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80026220: b           L_80026228
    // 0x80026224: nop

        goto L_80026228;
    // 0x80026224: nop

L_80026228:
    // 0x80026228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002622C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026230: jr          $ra
    // 0x80026234: nop

    return;
    // 0x80026234: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A548: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A548);
    return;
    // 0x8008A54C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsbflip_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: jal         0x80800064
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800064_bsbflip(rdram, ctx);
        goto after_0;
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void baalarm_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080004C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800054: jal         0x800C2E04
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080005C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800064: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x80800068: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8080006C: jal         0x800C3418
    // 0x80800070: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_800C3418(rdram, ctx);
        goto after_1;
    // 0x80800070: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_1:
    // 0x80800074: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800078: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080007C: jal         0x800C330C
    // 0x80800080: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x80800080: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    after_2:
    // 0x80800084: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080008C: jal         0x800C431C
    // 0x80800090: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    func_800C431C(rdram, ctx);
        goto after_3;
    // 0x80800090: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    after_3:
    // 0x80800094: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80800098: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080009C: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_800E1610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E1614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E1618: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E161C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E1620: jal         0x800E1540
    // 0x800E1624: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800E1540(rdram, ctx);
        goto after_0;
    // 0x800E1624: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E1628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800E162C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E1630: jal         0x800E13F0
    // 0x800E1634: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800E13F0(rdram, ctx);
        goto after_1;
    // 0x800E1634: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800E1638: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E163C: jal         0x800E144C
    // 0x800E1640: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800E144C(rdram, ctx);
        goto after_2;
    // 0x800E1640: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800E1644: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1648: jal         0x800E14B8
    // 0x800E164C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800E14B8(rdram, ctx);
        goto after_3;
    // 0x800E164C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800E1650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E1654: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1658: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E165C: jr          $ra
    // 0x800E1660: nop

    return;
    // 0x800E1660: nop

;}
