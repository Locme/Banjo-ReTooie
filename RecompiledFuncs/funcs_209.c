#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void baphysics_set_gravity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BCB4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BCB8: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BCBC: jr          $ra
    // 0x8009BCC0: swc1        $f12, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009BCC0: swc1        $f12, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bapulse_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F60: syscall     144
    recomp_syscall_handler(rdram, ctx, 0x80084F60);
    return;
    // 0x80084F64: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void _badeathmatch_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085538: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085538);
    return;
    // 0x8008553C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800DFBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFBE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DFBEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DFBF0: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800DFBF4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFBF8: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFBFC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFC00: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x800DFC04: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DFC08: jal         0x800EE7F8
    // 0x800DFC0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DFC0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800DFC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFC18: jr          $ra
    // 0x800DFC1C: nop

    return;
    // 0x800DFC1C: nop

;}
RECOMP_FUNC void func_800A8A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8A04: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A8A08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8A0C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A8A10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A8A14: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A8A18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8A1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8A24: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800A8A28: lw          $a0, 0x7688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7688);
    // 0x800A8A2C: jal         0x80015CC0
    // 0x800A8A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80015CC0(rdram, ctx);
        goto after_0;
    // 0x800A8A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x800A8A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A8A3C: jr          $ra
    // 0x800A8A40: nop

    return;
    // 0x800A8A40: nop

;}
RECOMP_FUNC void _chwarppad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B58: syscall     199
    recomp_syscall_handler(rdram, ctx, 0x80085B58);
    return;
    // 0x80085B5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EE8: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088EE8);
    return;
    // 0x80088EEC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _changlerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086710: syscall     359
    recomp_syscall_handler(rdram, ctx, 0x80086710);
    return;
    // 0x80086714: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void glsplinefind_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800088: jal         0x800EE84C
    // 0x8080008C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE84C(rdram, ctx);
        goto after_0;
    // 0x8080008C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800090: jal         0x808000A8
    // 0x80800094: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    glsplinefind_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800094: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void sueggmisc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000C0: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808000C4: sll         $t7, $a0, 11
    ctx->r15 = S32(ctx->r4 << 11);
    // 0x808000C8: jal         0x800883C0
    // 0x808000CC: srl         $a0, $t7, 20
    ctx->r4 = S32(U32(ctx->r15) >> 20);
    _gcegg_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000CC: srl         $a0, $t7, 20
    ctx->r4 = S32(U32(ctx->r15) >> 20);
    after_0:
    // 0x808000D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000DC: jal         0x80800120
    // 0x808000E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    sueggmisc_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808000E4: jal         0x800F54E4
    // 0x808000E8: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000E8: nop

    after_2:
    // 0x808000EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000F0: jal         0x800883E0
    // 0x808000F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808000F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808000F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800100: jal         0x800F7664
    // 0x80800104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7664(rdram, ctx);
        goto after_4;
    // 0x80800104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800108: jal         0x800FFAB0
    // 0x8080010C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x8080010C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80800444_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: jal         0x80800480
    // 0x80800450: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_0;
    // 0x80800450: nop

    after_0:
    // 0x80800454: beq         $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800458: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080046C;
    }
    // 0x80800458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080045C: jal         0x800DA298
    // 0x80800460: nop

    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800460: nop

    after_1:
    // 0x80800464: b           L_80800474
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800474;
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080046C:
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800474:
    // 0x80800474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void func_8080011C_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: jal         0x80090708
    // 0x80800130: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x80800130: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80102424
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080014C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800150: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800154: jal         0x8008FC28
    // 0x80800158: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_8008FC28(rdram, ctx);
        goto after_2;
    // 0x80800158: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8080015C: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80800160: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x80800164: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80800168: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8080016C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80800170: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80800174: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
    // 0x80800178: jal         0x800FC6B0
    // 0x8080017C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x8080017C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void sucoasterdata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x808001AC: beq         $at, $zero, L_80800214
    if (ctx->r1 == 0) {
        // 0x808001B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800214;
    }
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3282, 0X378) << 16);
    // 0x808001BC: addu        $at, $at, $t6
    gpr jr_addend_808001C4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001C0: lw          $t6, 0x378($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3282, 0X378));
    // 0x808001C4: jr          $t6
    // 0x808001C8: nop

    switch (jr_addend_808001C4 >> 2) {
        case 0: goto L_808001CC; break;
        case 1: goto L_808001D4; break;
        case 2: goto L_808001DC; break;
        case 3: goto L_808001E4; break;
        case 4: goto L_808001EC; break;
        case 5: goto L_808001F4; break;
        case 6: goto L_808001FC; break;
        case 7: goto L_80800204; break;
        case 8: goto L_8080020C; break;
        default: switch_error(__func__, 0x808001C4, 0x80800378);
    }
    // 0x808001C8: nop

L_808001CC:
    // 0x808001CC: jr          $ra
    // 0x808001D0: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    return;
    // 0x808001D0: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
L_808001D4:
    // 0x808001D4: jr          $ra
    // 0x808001D8: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x808001D8: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_808001DC:
    // 0x808001DC: jr          $ra
    // 0x808001E0: addiu       $v0, $zero, 0x154
    ctx->r2 = ADD32(0, 0X154);
    return;
    // 0x808001E0: addiu       $v0, $zero, 0x154
    ctx->r2 = ADD32(0, 0X154);
L_808001E4:
    // 0x808001E4: jr          $ra
    // 0x808001E8: addiu       $v0, $zero, 0x168
    ctx->r2 = ADD32(0, 0X168);
    return;
    // 0x808001E8: addiu       $v0, $zero, 0x168
    ctx->r2 = ADD32(0, 0X168);
L_808001EC:
    // 0x808001EC: jr          $ra
    // 0x808001F0: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x808001F0: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_808001F4:
    // 0x808001F4: jr          $ra
    // 0x808001F8: addiu       $v0, $zero, 0x17C
    ctx->r2 = ADD32(0, 0X17C);
    return;
    // 0x808001F8: addiu       $v0, $zero, 0x17C
    ctx->r2 = ADD32(0, 0X17C);
L_808001FC:
    // 0x808001FC: jr          $ra
    // 0x80800200: addiu       $v0, $zero, 0x1A4
    ctx->r2 = ADD32(0, 0X1A4);
    return;
    // 0x80800200: addiu       $v0, $zero, 0x1A4
    ctx->r2 = ADD32(0, 0X1A4);
L_80800204:
    // 0x80800204: jr          $ra
    // 0x80800208: addiu       $v0, $zero, 0x1B8
    ctx->r2 = ADD32(0, 0X1B8);
    return;
    // 0x80800208: addiu       $v0, $zero, 0x1B8
    ctx->r2 = ADD32(0, 0X1B8);
L_8080020C:
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $v0, $zero, 0x1CC
    ctx->r2 = ADD32(0, 0X1CC);
    return;
    // 0x80800210: addiu       $v0, $zero, 0x1CC
    ctx->r2 = ADD32(0, 0X1CC);
L_80800214:
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085100: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085100);
    return;
    // 0x80085104: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800EFD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EFD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFD68: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EFD6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EFD70: jal         0x800137AC
    // 0x800EFD74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EFD74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EFD78: jal         0x800F2100
    // 0x800EFD7C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800EFD7C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800EFD80: jal         0x800137C4
    // 0x800EFD84: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_2;
    // 0x800EFD84: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800EFD88: jal         0x800F2100
    // 0x800EFD8C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x800EFD8C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800EFD90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800EFD94: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EFD98: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800EFD9C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EFDA0: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EFDA4: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800EFDA8: nop

    // 0x800EFDAC: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EFDB0: nop

    // 0x800EFDB4: mul.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800EFDB8: nop

    // 0x800EFDBC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EFDC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EFDC4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800EFDC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800EFDCC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EFDD0: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800EFDD4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800EFDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFDDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EFDE0: jr          $ra
    // 0x800EFDE4: nop

    return;
    // 0x800EFDE4: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085020: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085020);
    return;
    // 0x80085024: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800024_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080003C: jal         0x800DA524
    // 0x80800040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800044: jal         0x800DA524
    // 0x80800048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8080004C: jal         0x800DA524
    // 0x80800050: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800054: jal         0x800DA524
    // 0x80800058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8080005C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800068: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x8080006C: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x80800070: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800074: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    // 0x80800078: jal         0x8008A2A0
    // 0x8080007C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080007C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    after_5:
    // 0x80800080: jal         0x8008A2F8
    // 0x80800084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_800F7180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7180: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7188: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F718C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7198: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F719C: jal         0x8009E674
    // 0x800F71A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F71A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F71A4: beq         $v0, $zero, L_800F71C0
    if (ctx->r2 == 0) {
        // 0x800F71A8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F71C0;
    }
    // 0x800F71A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F71AC: jal         0x80084800
    // 0x800F71B0: nop

    _badrone_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800F71B0: nop

    after_1:
    // 0x800F71B4: xori        $t7, $v0, 0xE
    ctx->r15 = ctx->r2 ^ 0XE;
    // 0x800F71B8: b           L_800F71C4
    // 0x800F71BC: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
        goto L_800F71C4;
    // 0x800F71BC: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_800F71C0:
    // 0x800F71C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F71C4:
    // 0x800F71C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F71C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F71CC: jr          $ra
    // 0x800F71D0: nop

    return;
    // 0x800F71D0: nop

;}
RECOMP_FUNC void _basub_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851C0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851C0);
    return;
    // 0x800851C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896B0: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x800896B0);
    return;
    // 0x800896B4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800388_chvandoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080038C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800394: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800398: jal         0x80101FDC
    // 0x8080039C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080039C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: beq         $a1, $at, L_808003DC
    if (ctx->r5 == ctx->r1) {
        // 0x808003B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003DC;
    }
    // 0x808003B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003B4: beq         $a1, $at, L_808003F4
    if (ctx->r5 == ctx->r1) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F4;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003C0: beq         $a1, $at, L_80800418
    if (ctx->r5 == ctx->r1) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800418;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003CC: beql        $a1, $at, L_8080042C
    if (ctx->r5 == ctx->r1) {
        // 0x808003D0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8080042C;
    }
    goto skip_0;
    // 0x808003D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x808003D4: b           L_8080043C
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003DC:
    // 0x808003DC: jal         0x80103110
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003E4: jal         0x800DA524
    // 0x808003E8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808003E8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_2:
    // 0x808003EC: b           L_8080043C
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F4:
    // 0x808003F4: jal         0x80103110
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808003FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800404: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800408: jal         0x800DA544
    // 0x8080040C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080040C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800410: b           L_8080043C
    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800418:
    // 0x80800418: jal         0x80103110
    // 0x8080041C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x8080041C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800420: b           L_8080043C
    // 0x80800424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x80800424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800428: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8080042C:
    // 0x8080042C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800430: nop

    // 0x80800434: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080043C:
    // 0x8080043C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void func_8011607C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011607C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80116080: jr          $ra
    // 0x80116084: sh          $a1, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r5;
    return;
    // 0x80116084: sh          $a1, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void mlspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008CC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x808008D0: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x808008D4: jal         0x800EFB24
    // 0x808008D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x808008D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808008DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

;}
RECOMP_FUNC void bsvan_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801210: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801214: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CDC) << 16);
    // 0x80801218: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080121C: jr          $ra
    // 0x80801220: lw          $v0, 0x1CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CDC));
    return;
    // 0x80801220: lw          $v0, 0x1CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CDC));
;}
RECOMP_FUNC void idwave_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003A8: jal         0x800D8FF8
    // 0x808003AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808003AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003B0: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808003B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808003B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003BC: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808003C0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003C4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808003C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5C4) << 16);
    // 0x808003CC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808003D0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003D4: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x808003D8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x808003DC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808003E0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x808003E4: lwc1        $f6, 0x5C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5C4));
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5C8) << 16);
    // 0x808003EC: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x808003F0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003F4: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808003F8: nop

    // 0x808003FC: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800400: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80800404: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800408: lwc1        $f10, 0x5C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5C8));
    // 0x8080040C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800414: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800418: nop

    // 0x8080041C: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80800420: jal         0x800138D0
    // 0x80800424: nop

    func_800138D0(rdram, ctx);
        goto after_1;
    // 0x80800424: nop

    after_1:
    // 0x80800428: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080042C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5CC) << 16);
    // 0x80800430: lwc1        $f18, 0x5CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5CC));
    // 0x80800434: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800438: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080043C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800440: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800444: nop

    // 0x80800448: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080044C: jal         0x80013970
    // 0x80800450: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x80800450: nop

    after_2:
    // 0x80800454: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800458: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080045C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800460: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800464: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800468: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080046C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800470: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80800474: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5D0) << 16);
    // 0x80800478: lwc1        $f8, 0x5D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5D0));
    // 0x8080047C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800480: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800484: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080048C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80800490: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80800494: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800498: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8080049C: nop

    // 0x808004A0: mul.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x808004A4: jal         0x80013970
    // 0x808004A8: nop

    func_80013970(rdram, ctx);
        goto after_3;
    // 0x808004A8: nop

    after_3:
    // 0x808004AC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808004B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5D4) << 16);
    // 0x808004B4: lwc1        $f8, 0x5D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5D4));
    // 0x808004B8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808004BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808004C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004C4: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x808004C8: nop

    // 0x808004CC: mul.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808004D0: jal         0x800138D0
    // 0x808004D4: nop

    func_800138D0(rdram, ctx);
        goto after_4;
    // 0x808004D4: nop

    after_4:
    // 0x808004D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808004E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808004E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004E8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808004EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808004F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004F4: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x808004F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5D8) << 16);
    // 0x808004FC: lwc1        $f6, 0x5D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5D8));
    // 0x80800500: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800504: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800508: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080050C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800510: addiu       $a2, $a2, -0x72E8
    ctx->r6 = ADD32(ctx->r6, -0X72E8);
    // 0x80800514: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80800518: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080051C: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80800520: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800524: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800528: bc1f        L_80800544
    if (!c1cs) {
        // 0x8080052C: swc1        $f16, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
            goto L_80800544;
    }
    // 0x8080052C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80800530: add.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800534: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800538: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8080053C: b           L_80800558
    // 0x80800540: sh          $t7, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r15;
        goto L_80800558;
    // 0x80800540: sh          $t7, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r15;
L_80800544:
    // 0x80800544: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800548: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080054C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80800550: nop

    // 0x80800554: sh          $t9, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r25;
L_80800558:
    // 0x80800558: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080055C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800560: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80800564: nop

    // 0x80800568: bc1fl       L_80800588
    if (!c1cs) {
        // 0x8080056C: sub.s       $f6, $f18, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
            goto L_80800588;
    }
    goto skip_0;
    // 0x8080056C: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    skip_0:
    // 0x80800570: add.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800574: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800578: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8080057C: b           L_80800598
    // 0x80800580: sh          $t1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r9;
        goto L_80800598;
    // 0x80800580: sh          $t1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r9;
    // 0x80800584: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
L_80800588:
    // 0x80800588: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080058C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80800590: nop

    // 0x80800594: sh          $t3, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r11;
L_80800598:
    // 0x80800598: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080059C: jal         0x80088660
    // 0x808005A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _glid_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808005A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

    // 0x808005B8: nop

    // 0x808005BC: nop

;}
RECOMP_FUNC void _cothemedll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087870: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087870);
    return;
    // 0x80087874: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800364_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800368: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800370: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800374: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800378: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080037C: jal         0x80800800
    // 0x80800380: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80800800_chcheatomenu(rdram, ctx);
        goto after_0;
    // 0x80800380: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800384: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800388: jal         0x800F1418
    // 0x8080038C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800F1418(rdram, ctx);
        goto after_1;
    // 0x8080038C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800390: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800398: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080039C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808003AC: jal         0x80087D08
    // 0x808003B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808003B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808003B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1708, 0X870) << 16);
    // 0x808003B8: lwc1        $f6, 0x870($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1708, 0X870));
    // 0x808003BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003C8: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808003CC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x808003D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808003D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808003D8: jal         0x80087DD8
    // 0x808003DC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_3;
    // 0x808003DC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808003E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003E4: jal         0x80087D98
    // 0x808003E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_4;
    // 0x808003E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_4:
    // 0x808003EC: blez        $s2, L_80800410
    if (SIGNED(ctx->r18) <= 0) {
        // 0x808003F0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800410;
    }
    // 0x808003F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808003F8:
    // 0x808003F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80087D90
    // 0x80800400: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_5;
    // 0x80800400: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
    after_5:
    // 0x80800404: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800408: bnel        $s0, $s2, L_808003F8
    if (ctx->r16 != ctx->r18) {
        // 0x8080040C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808003F8;
    }
    goto skip_0;
    // 0x8080040C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80800410:
    // 0x80800410: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800414: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800418: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080041C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800420: jr          $ra
    // 0x80800424: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800424: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800C04_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C08: addiu       $at, $zero, 0x10C1
    ctx->r1 = ADD32(0, 0X10C1);
    // 0x80800C0C: beq         $a1, $at, L_80800C38
    if (ctx->r5 == ctx->r1) {
        // 0x80800C10: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800C38;
    }
    // 0x80800C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C14: addiu       $at, $zero, 0x10C3
    ctx->r1 = ADD32(0, 0X10C3);
    // 0x80800C18: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800C1C: addiu       $at, $zero, 0x10F6
        ctx->r1 = ADD32(0, 0X10F6);
            goto L_80800C54;
    }
    // 0x80800C1C: addiu       $at, $zero, 0x10F6
    ctx->r1 = ADD32(0, 0X10F6);
    // 0x80800C20: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800C24: addiu       $at, $zero, 0x1119
        ctx->r1 = ADD32(0, 0X1119);
            goto L_80800C54;
    }
    // 0x80800C24: addiu       $at, $zero, 0x1119
    ctx->r1 = ADD32(0, 0X1119);
    // 0x80800C28: beq         $a1, $at, L_80800C64
    if (ctx->r5 == ctx->r1) {
        // 0x80800C2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800C64;
    }
    // 0x80800C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C30: b           L_80800C8C
    // 0x80800C34: nop

        goto L_80800C8C;
    // 0x80800C34: nop

L_80800C38:
    // 0x80800C38: bne         $a2, $zero, L_80800C4C
    if (ctx->r6 != 0) {
        // 0x80800C3C: addiu       $v1, $zero, 0x1E
        ctx->r3 = ADD32(0, 0X1E);
            goto L_80800C4C;
    }
    // 0x80800C3C: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80800C40: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80800C44: b           L_80800C8C
    // 0x80800C48: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_80800C8C;
    // 0x80800C48: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
L_80800C4C:
    // 0x80800C4C: b           L_80800C8C
    // 0x80800C50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800C8C;
    // 0x80800C50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800C54:
    // 0x80800C54: jal         0x800D211C
    // 0x80800C58: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    func_800D211C(rdram, ctx);
        goto after_0;
    // 0x80800C58: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_0:
    // 0x80800C5C: b           L_80800C90
    // 0x80800C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C90;
    // 0x80800C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C64:
    // 0x80800C64: bne         $a2, $zero, L_80800C78
    if (ctx->r6 != 0) {
        // 0x80800C68: nop
    
            goto L_80800C78;
    }
    // 0x80800C68: nop

    // 0x80800C6C: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80800C70: b           L_80800C8C
    // 0x80800C74: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_80800C8C;
    // 0x80800C74: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
L_80800C78:
    // 0x80800C78: jal         0x800D211C
    // 0x80800C7C: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x80800C7C: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_1:
    // 0x80800C80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800C84: b           L_80800C8C
    // 0x80800C88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800C8C;
    // 0x80800C88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800C8C:
    // 0x80800C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C90:
    // 0x80800C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C94: jr          $ra
    // 0x80800C98: nop

    return;
    // 0x80800C98: nop

;}
RECOMP_FUNC void _bskazjump_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083480: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083480);
    return;
    // 0x80083484: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808004C4_cadbmgrDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x808004C8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808004CC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808004D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x808004D4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808004D8: bltz        $v0, L_80800520
    if (SIGNED(ctx->r2) < 0) {
        // 0x808004DC: lw          $v1, -0x4($t7)
        ctx->r3 = MEM_W(ctx->r15, -0X4);
            goto L_80800520;
    }
    // 0x808004DC: lw          $v1, -0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, -0X4);
    // 0x808004E0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x808004E4: addu        $a2, $a0, $t8
    ctx->r6 = ADD32(ctx->r4, ctx->r24);
L_808004E8:
    // 0x808004E8: lbu         $t9, 0x3C($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3C);
    // 0x808004EC: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808004F0: bnel        $a1, $t9, L_80800518
    if (ctx->r5 != ctx->r25) {
        // 0x808004F4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80800518;
    }
    goto skip_0;
    // 0x808004F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x808004F8: beql        $at, $zero, L_80800518
    if (ctx->r1 == 0) {
        // 0x808004FC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80800518;
    }
    goto skip_1;
    // 0x808004FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_1:
    // 0x80800500: lbu         $a0, 0x3D($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X3D);
    // 0x80800504: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800508: bnel        $at, $zero, L_80800518
    if (ctx->r1 != 0) {
        // 0x8080050C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80800518;
    }
    goto skip_2;
    // 0x8080050C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_2:
    // 0x80800510: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800514: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80800518:
    // 0x80800518: bgez        $v0, L_808004E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8080051C: addiu       $a2, $a2, -0x2
        ctx->r6 = ADD32(ctx->r6, -0X2);
            goto L_808004E8;
    }
    // 0x8080051C: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
L_80800520:
    // 0x80800520: jr          $ra
    // 0x80800524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _rtlight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890A8: syscall     760
    recomp_syscall_handler(rdram, ctx, 0x800890A8);
    return;
    // 0x800890AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8008AAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AAC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008AAC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AAC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AACC: jal         0x8008AEDC
    // 0x8008AAD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_0;
    // 0x8008AAD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008AAD4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008AAD8: jal         0x8008AA0C
    // 0x8008AADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AA0C(rdram, ctx);
        goto after_1;
    // 0x8008AADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008AAE0: jal         0x8008C0C8
    // 0x8008AAE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008C0C8(rdram, ctx);
        goto after_2;
    // 0x8008AAE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8008AAE8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008AAEC: jal         0x8008A990
    // 0x8008AAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008A990(rdram, ctx);
        goto after_3;
    // 0x8008AAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008AAF4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008AAF8: jal         0x8008B2AC
    // 0x8008AAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B2AC(rdram, ctx);
        goto after_4;
    // 0x8008AAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AB00: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008AB04: lb          $t7, 0x1B($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1B);
    // 0x8008AB08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AB0C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008AB10: bltz        $t7, L_8008AB1C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8008AB14: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8008AB1C;
    }
    // 0x8008AB14: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008AB18: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8008AB1C:
    // 0x8008AB1C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008AB20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008AB24: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8008AB28: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8008AB2C: nop

    // 0x8008AB30: bc1fl       L_8008AB48
    if (!c1cs) {
        // 0x8008AB34: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8008AB48;
    }
    goto skip_0;
    // 0x8008AB34: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_0:
    // 0x8008AB38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008AB3C: nop

    // 0x8008AB40: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8008AB44: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_8008AB48:
    // 0x8008AB48: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AB4C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8008AB50: nop

    // 0x8008AB54: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8008AB58: nop

    // 0x8008AB5C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008AB60: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8008AB64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008AB68: jal         0x8008C1C0
    // 0x8008AB6C: nop

    func_8008C1C0(rdram, ctx);
        goto after_5;
    // 0x8008AB6C: nop

    after_5:
    // 0x8008AB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AB78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008AB7C: jr          $ra
    // 0x8008AB80: nop

    return;
    // 0x8008AB80: nop

;}
RECOMP_FUNC void func_800A965C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A965C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9660: lh          $t6, 0x76D2($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X76D2);
    // 0x800A9664: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800A9668: jr          $ra
    // 0x800A966C: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
    return;
    // 0x800A966C: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
;}
RECOMP_FUNC void func_800B5054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5058: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B505C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800B5060: addiu       $s3, $s3, 0x7F18
    ctx->r19 = ADD32(ctx->r19, 0X7F18);
    // 0x800B5064: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x800B5068: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B506C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B5070: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B5074: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B5078: blez        $t6, L_800B50B4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B507C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B50B4;
    }
    // 0x800B507C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B5080: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800B5084: addiu       $s2, $s2, 0x7F10
    ctx->r18 = ADD32(ctx->r18, 0X7F10);
    // 0x800B5088: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B508C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_800B5090:
    // 0x800B5090: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800B5094: jal         0x800BA2C4
    // 0x800B5098: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800BA2C4(rdram, ctx);
        goto after_0;
    // 0x800B5098: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x800B509C: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x800B50A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B50A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800B50A8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B50AC: bnel        $at, $zero, L_800B5090
    if (ctx->r1 != 0) {
        // 0x800B50B0: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_800B5090;
    }
    goto skip_0;
    // 0x800B50B0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_800B50B4:
    // 0x800B50B4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800B50B8: addiu       $s2, $s2, 0x7F10
    ctx->r18 = ADD32(ctx->r18, 0X7F10);
    // 0x800B50BC: jal         0x8001B084
    // 0x800B50C0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800B50C0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x800B50C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B50C8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800B50CC: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x800B50D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B50D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B50D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B50DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B50E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B50E4: sb          $zero, 0x7F1D($at)
    MEM_B(0X7F1D, ctx->r1) = 0;
    // 0x800B50E8: jr          $ra
    // 0x800B50EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B50EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsbtrot_entrypoint_51(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CBC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80802CC0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2F10) << 16);
    // 0x80802CC4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802CC8: jr          $ra
    // 0x80802CCC: lw          $v0, 0x2F10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F10));
    return;
    // 0x80802CCC: lw          $v0, 0x2F10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F10));
;}
RECOMP_FUNC void func_8080000C_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8010A800
    // 0x8080001C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8010A800(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800020: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80800028: beql        $a0, $zero, L_80800048
    if (ctx->r4 == 0) {
        // 0x8080002C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800048;
    }
    goto skip_0;
    // 0x8080002C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x80800030: jal         0x80106790
    // 0x80800034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800038: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: b           L_80800048
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800048;
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800048:
    // 0x80800048: beq         $a0, $zero, L_80800080
    if (ctx->r4 == 0) {
        // 0x8080004C: lui         $a1, 0x8200
        ctx->r5 = S32(0X8200 << 16);
            goto L_80800080;
    }
    // 0x8080004C: lui         $a1, 0x8200
    ctx->r5 = S32(0X8200 << 16);
    // 0x80800050: jal         0x80102F74
    // 0x80800054: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80102F74(rdram, ctx);
        goto after_2;
    // 0x80800054: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800058: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x8080005C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x8080005C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800060: lbu         $t7, 0x7A($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X7A);
    // 0x80800064: ori         $t8, $t7, 0xC0
    ctx->r24 = ctx->r15 | 0XC0;
    // 0x80800068: b           L_80800080
    // 0x8080006C: sb          $t8, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r24;
        goto L_80800080;
    // 0x8080006C: sb          $t8, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r24;
L_80800070:
    // 0x80800070: lbu         $t9, 0x7A($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X7A);
    // 0x80800074: andi        $t0, $t9, 0xFF3F
    ctx->r8 = ctx->r25 & 0XFF3F;
    // 0x80800078: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8080007C: sb          $t1, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r9;
L_80800080:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800EC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800EC8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800ECC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800ED0: jal         0x80800144
    // 0x80800ED4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800ED4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800ED8: jal         0x8008CABC
    // 0x80800EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800EE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800EE4: jal         0x8008AF24
    // 0x80800EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF0: jal         0x8008B1A0
    // 0x80800EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x80800EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: jal         0x8008AED4
    // 0x80800F00: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800F00: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    after_4:
    // 0x80800F04: lui         $a1, 0x3E1B
    ctx->r5 = S32(0X3E1B << 16);
    // 0x80800F08: ori         $a1, $a1, 0xDA51
    ctx->r5 = ctx->r5 | 0XDA51;
    // 0x80800F0C: jal         0x8008B24C
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F14: lui         $a2, 0x3EC3
    ctx->r6 = S32(0X3EC3 << 16);
    // 0x80800F18: ori         $a2, $a2, 0xC9EF
    ctx->r6 = ctx->r6 | 0XC9EF;
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: jal         0x8008B1D4
    // 0x80800F24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800F24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F2C: jal         0x8008B1BC
    // 0x80800F30: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800F30: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F38: jal         0x8008B134
    // 0x80800F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800F40: jal         0x8008B064
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800F48: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800F4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F5C: jal         0x8009FFD8
    // 0x80800F60: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800F60: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80800F64: jal         0x8009EF04
    // 0x80800F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x80800F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800F6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F70: nop

    // 0x80800F74: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800F78: nop

    // 0x80800F7C: bc1t        L_80800F98
    if (c1cs) {
        // 0x80800F80: nop
    
            goto L_80800F98;
    }
    // 0x80800F80: nop

    // 0x80800F84: jal         0x8009EEB8
    // 0x80800F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x80800F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F90: jal         0x8009C914
    // 0x80800F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x80800F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_80800F98:
    // 0x80800F98: jal         0x8009C990
    // 0x80800F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x80800F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800FA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FA4: jal         0x8009B9C0
    // 0x80800FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x80800FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800FAC: jal         0x80800000
    // 0x80800FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bstaxi(rdram, ctx);
        goto after_16;
    // 0x80800FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800FB4: jal         0x8009C990
    // 0x80800FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80800FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800FBC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800FC0: jal         0x8009BB00
    // 0x80800FC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800FC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800FC8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FD0: jal         0x8009BA68
    // 0x80800FD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800FD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80800FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FDC: jal         0x8009BA58
    // 0x80800FE0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80800FE0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_20:
    // 0x80800FE4: lui         $a1, 0xC4ED
    ctx->r5 = S32(0XC4ED << 16);
    // 0x80800FE8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800FEC: jal         0x8009BCB4
    // 0x80800FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80800FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800FF4: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80800FF8: lui         $a2, 0x3F8B
    ctx->r6 = S32(0X3F8B << 16);
    // 0x80800FFC: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x80801000: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80801004: jal         0x8009D7A4
    // 0x80801008: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_22;
    // 0x80801008: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8080100C: sb          $zero, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = 0;
    // 0x80801010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801014: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801018: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080101C: jr          $ra
    // 0x80801020: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801020: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bsbtrot_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801608: jal         0x8009BC6C
    // 0x8080160C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x8080160C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801610: jal         0x8080061C
    // 0x80801614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80801614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080161C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801620: jr          $ra
    // 0x80801624: nop

    return;
    // 0x80801624: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BC8: jr          $ra
    // 0x80801BCC: lbu         $v0, 0x170($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X170);
    return;
    // 0x80801BCC: lbu         $v0, 0x170($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X170);
;}
RECOMP_FUNC void func_8080247C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080247C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802480: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802484: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080248C: jal         0x80100094
    // 0x80802490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802494: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802498: jal         0x8008A040
    // 0x8080249C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080249C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x808024A0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808024A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808024A8: jal         0x80100094
    // 0x808024AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808024AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808024B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808024B4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808024B8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x808024BC: beql        $t6, $zero, L_808026AC
    if (ctx->r14 == 0) {
        // 0x808024C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808026AC;
    }
    goto skip_0;
    // 0x808024C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808024C4: jal         0x801022E4
    // 0x808024C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x808024C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808024CC: addiu       $at, $zero, 0x36F
    ctx->r1 = ADD32(0, 0X36F);
    // 0x808024D0: beq         $v0, $at, L_808024F8
    if (ctx->r2 == ctx->r1) {
        // 0x808024D4: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808024F8;
    }
    // 0x808024D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808024D8: addiu       $at, $zero, 0x372
    ctx->r1 = ADD32(0, 0X372);
    // 0x808024DC: beq         $v0, $at, L_808025BC
    if (ctx->r2 == ctx->r1) {
        // 0x808024E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808025BC;
    }
    // 0x808024E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024E4: addiu       $at, $zero, 0x373
    ctx->r1 = ADD32(0, 0X373);
    // 0x808024E8: beq         $v0, $at, L_80802568
    if (ctx->r2 == ctx->r1) {
        // 0x808024EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802568;
    }
    // 0x808024EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024F0: b           L_80802608
    // 0x808024F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802608;
    // 0x808024F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808024F8:
    // 0x808024F8: lbu         $t8, 0x67($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X67);
    // 0x808024FC: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80802500: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80802504: bne         $t8, $zero, L_80802540
    if (ctx->r24 != 0) {
        // 0x80802508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802540;
    }
    // 0x80802508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080250C: lui         $a2, 0x3E05
    ctx->r6 = S32(0X3E05 << 16);
    // 0x80802510: jal         0x80102320
    // 0x80802514: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x80802514: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    after_4:
    // 0x80802518: bne         $v0, $zero, L_80802538
    if (ctx->r2 != 0) {
        // 0x8080251C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802538;
    }
    // 0x8080251C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802520: lui         $a1, 0x3E85
    ctx->r5 = S32(0X3E85 << 16);
    // 0x80802524: lui         $a2, 0x3F0C
    ctx->r6 = S32(0X3F0C << 16);
    // 0x80802528: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080252C: jal         0x80102320
    // 0x80802530: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80102320(rdram, ctx);
        goto after_5;
    // 0x80802530: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_5:
    // 0x80802534: beq         $v0, $zero, L_80802540
    if (ctx->r2 == 0) {
        // 0x80802538: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80802540;
    }
L_80802538:
    // 0x80802538: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080253C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80802540:
    // 0x80802540: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80802544: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80802548: beq         $t0, $zero, L_80802558
    if (ctx->r8 == 0) {
        // 0x8080254C: nop
    
            goto L_80802558;
    }
    // 0x8080254C: nop

    // 0x80802550: b           L_80802558
    // 0x80802554: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80802558;
    // 0x80802554: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80802558:
    // 0x80802558: jal         0x808023BC
    // 0x8080255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023BC_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x8080255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802560: b           L_80802614
    // 0x80802564: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_80802614;
    // 0x80802564: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80802568:
    // 0x80802568: lui         $a1, 0x3F07
    ctx->r5 = S32(0X3F07 << 16);
    // 0x8080256C: jal         0x80101E14
    // 0x80802570: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80802570: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    after_7:
    // 0x80802574: beq         $v0, $zero, L_80802584
    if (ctx->r2 == 0) {
        // 0x80802578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802584;
    }
    // 0x80802578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080257C: jal         0x808023BC
    // 0x80802580: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808023BC_chweldarboss(rdram, ctx);
        goto after_8;
    // 0x80802580: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_80802584:
    // 0x80802584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802588: jal         0x80101E14
    // 0x8080258C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x8080258C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_9:
    // 0x80802590: beq         $v0, $zero, L_808025A0
    if (ctx->r2 == 0) {
        // 0x80802594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808025A0;
    }
    // 0x80802594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802598: jal         0x808023BC
    // 0x8080259C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808023BC_chweldarboss(rdram, ctx);
        goto after_10;
    // 0x8080259C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
L_808025A0:
    // 0x808025A0: lui         $a1, 0x3F07
    ctx->r5 = S32(0X3F07 << 16);
    // 0x808025A4: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    // 0x808025A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025AC: jal         0x80102320
    // 0x808025B0: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_80102320(rdram, ctx);
        goto after_11;
    // 0x808025B0: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_11:
    // 0x808025B4: b           L_80802610
    // 0x808025B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80802610;
    // 0x808025B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_808025BC:
    // 0x808025BC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808025C0: jal         0x80101E14
    // 0x808025C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x808025C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_12:
    // 0x808025C8: beq         $v0, $zero, L_808025D8
    if (ctx->r2 == 0) {
        // 0x808025CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808025D8;
    }
    // 0x808025CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025D0: jal         0x808023BC
    // 0x808025D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808023BC_chweldarboss(rdram, ctx);
        goto after_13;
    // 0x808025D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
L_808025D8:
    // 0x808025D8: jal         0x80101F24
    // 0x808025DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_14;
    // 0x808025DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808025E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4538) << 16);
    // 0x808025E4: lwc1        $f4, 0x4538($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4538));
    // 0x808025E8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x808025EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808025F0: nop

    // 0x808025F4: bc1f        L_80802600
    if (!c1cs) {
        // 0x808025F8: nop
    
            goto L_80802600;
    }
    // 0x808025F8: nop

    // 0x808025FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80802600:
    // 0x80802600: b           L_80802610
    // 0x80802604: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
        goto L_80802610;
    // 0x80802604: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80802608:
    // 0x80802608: jal         0x808023BC
    // 0x8080260C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808023BC_chweldarboss(rdram, ctx);
        goto after_15;
    // 0x8080260C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
L_80802610:
    // 0x80802610: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80802614:
    // 0x80802614: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80802618: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1360, 0X4908) << 16);
    // 0x8080261C: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80802620: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80802624: addiu       $a3, $a3, 0x4908
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1360, 0X4908));
    // 0x80802628: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080262C: nop

    // 0x80802630: bc1fl       L_80802640
    if (!c1cs) {
        // 0x80802634: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80802640;
    }
    goto skip_1;
    // 0x80802634: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80802638: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8080263C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80802640:
    // 0x80802640: lw          $t5, 0x70($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X70);
    // 0x80802644: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802648: lbu         $a0, 0xB0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0XB0);
    // 0x8080264C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80802650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802654: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802658: jal         0x80089D68
    // 0x8080265C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x8080265C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_16:
    // 0x80802660: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80802664: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80802668: beq         $t7, $zero, L_808026A8
    if (ctx->r15 == 0) {
        // 0x8080266C: sb          $v0, 0xB0($v1)
        MEM_B(0XB0, ctx->r3) = ctx->r2;
            goto L_808026A8;
    }
    // 0x8080266C: sb          $v0, 0xB0($v1)
    MEM_B(0XB0, ctx->r3) = ctx->r2;
    // 0x80802670: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80802674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X453C) << 16);
    // 0x80802678: lwc1        $f10, 0x453C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X453C));
    // 0x8080267C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802680: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80802684: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80802688: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080268C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802690: jal         0x800F12D4
    // 0x80802694: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_17;
    // 0x80802694: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x80802698: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080269C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808026A0: jal         0x800C31DC
    // 0x808026A4: lbu         $a0, 0xB0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0XB0);
    func_800C31DC(rdram, ctx);
        goto after_18;
    // 0x808026A4: lbu         $a0, 0xB0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0XB0);
    after_18:
L_808026A8:
    // 0x808026A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808026AC:
    // 0x808026AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808026B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808026B4: jr          $ra
    // 0x808026B8: nop

    return;
    // 0x808026B8: nop

;}
RECOMP_FUNC void badust_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080026C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800270: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800274: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800278: jal         0x80088970
    // 0x8080027C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _fxdlsmoke_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080027C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800280: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080028C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800290: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800294: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800298: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080029C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808002A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002A4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808002AC: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808002B0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808002B4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808002B8: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x808002BC: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808002C0: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x808002C4: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808002C8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808002CC: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x808002D0: jal         0x800BA930
    // 0x808002D4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_1;
    // 0x808002D4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_1:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808002E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808002F0: jal         0x800BA450
    // 0x808002F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA450(rdram, ctx);
        goto after_2;
    // 0x808002F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x808002F8: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800304: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800308: jal         0x800BA7C4
    // 0x8080030C: nop

    func_800BA7C4(rdram, ctx);
        goto after_3;
    // 0x8080030C: nop

    after_3:
    // 0x80800310: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080031C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800320: jal         0x800BA7FC
    // 0x80800324: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x80800324: nop

    after_4:
    // 0x80800328: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800334: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800338: jal         0x800BA8F8
    // 0x8080033C: nop

    func_800BA8F8(rdram, ctx);
        goto after_5;
    // 0x8080033C: nop

    after_5:
    // 0x80800340: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80800344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800348: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800354: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800358: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080035C: jal         0x800BA5BC
    // 0x80800360: nop

    func_800BA5BC(rdram, ctx);
        goto after_6;
    // 0x80800360: nop

    after_6:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x800BA22C
    // 0x8080036C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x8080036C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800370: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800374: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void func_800A5CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5CCC: jal         0x8008A510
    // 0x800A5CD0: nop

    _subaddietaxi_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800A5CD0: nop

    after_0:
    // 0x800A5CD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5CD8: jal         0x80085930
    // 0x800A5CDC: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    _chbaddieDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800A5CDC: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    after_1:
    // 0x800A5CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5CE8: jr          $ra
    // 0x800A5CEC: nop

    return;
    // 0x800A5CEC: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808008A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808008A8: jr          $ra
    // 0x808008AC: swc1        $f12, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808008AC: swc1        $f12, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void bakey_held(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800919F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800919F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800919FC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80091A00: addu        $t6, $v0, $a1
    ctx->r14 = ADD32(ctx->r2, ctx->r5);
    // 0x80091A04: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80091A08: beq         $t7, $zero, L_80091A18
    if (ctx->r15 == 0) {
        // 0x80091A0C: nop
    
            goto L_80091A18;
    }
    // 0x80091A0C: nop

    // 0x80091A10: b           L_80091A20
    // 0x80091A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80091A20;
    // 0x80091A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091A18:
    // 0x80091A18: jal         0x800BCE84
    // 0x80091A1C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800BCE84(rdram, ctx);
        goto after_0;
    // 0x80091A1C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
L_80091A20:
    // 0x80091A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091A28: jr          $ra
    // 0x80091A2C: nop

    return;
    // 0x80091A2C: nop

;}
RECOMP_FUNC void func_8080000C_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80106790
    // 0x8080001C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800020: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800030: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800034: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800038: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x8080003C: bltzl       $t8, L_80800104
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800040: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800104;
    }
    goto skip_0;
    // 0x80800040: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800044: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x80800048: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080004C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800050: bnel        $t0, $zero, L_80800104
    if (ctx->r8 != 0) {
        // 0x80800054: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800104;
    }
    goto skip_1;
    // 0x80800054: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080005C: jal         0x800D9058
    // 0x80800060: nop

    func_800D9058(rdram, ctx);
        goto after_2;
    // 0x80800060: nop

    after_2:
    // 0x80800064: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800068: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080006C: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x80800070: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800074: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800080: beq         $t6, $at, L_80800100
    if (ctx->r14 == ctx->r1) {
        // 0x80800084: sh          $t5, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r13;
            goto L_80800100;
    }
    // 0x80800084: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    // 0x80800088: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080008C: beq         $t6, $at, L_80800100
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80800100;
    }
    // 0x80800090: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800094: beql        $t6, $at, L_80800104
    if (ctx->r14 == ctx->r1) {
        // 0x80800098: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800104;
    }
    goto skip_2;
    // 0x80800098: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8080009C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000A8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808000AC: bltzl       $t9, L_80800104
    if (SIGNED(ctx->r25) < 0) {
        // 0x808000B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800104;
    }
    goto skip_3;
    // 0x808000B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808000B4: jal         0x8008A140
    // 0x808000B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x808000BC: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80800100;
    }
    // 0x808000C0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C4: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x808000C8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: srl         $t3, $t1, 22
    ctx->r11 = S32(U32(ctx->r9) >> 22);
    // 0x808000D4: bne         $t3, $zero, L_80800100
    if (ctx->r11 != 0) {
        // 0x808000D8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80800100;
    }
    // 0x808000D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808000DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000E4: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x808000E8: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x808000EC: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x808000F0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808000F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808000F8: jal         0x80089F88
    // 0x808000FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808000FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
L_80800100:
    // 0x80800100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800104:
    // 0x80800104: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800108: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80800370_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800374: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800378: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080037C: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x80800380: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800384: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800388: beq         $at, $zero, L_80800620
    if (ctx->r1 == 0) {
        // 0x8080038C: sw          $a2, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r6;
            goto L_80800620;
    }
    // 0x8080038C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80800390: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1116, 0XA3C) << 16);
    // 0x80800398: addu        $at, $at, $t6
    gpr jr_addend_808003A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080039C: lw          $t6, 0xA3C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1116, 0XA3C));
    // 0x808003A0: jr          $t6
    // 0x808003A4: nop

    switch (jr_addend_808003A0 >> 2) {
        case 0: goto L_808005B8; break;
        case 1: goto L_80800620; break;
        case 2: goto L_808005A0; break;
        case 3: goto L_80800620; break;
        case 4: goto L_80800620; break;
        case 5: goto L_80800620; break;
        case 6: goto L_80800620; break;
        case 7: goto L_80800620; break;
        case 8: goto L_80800620; break;
        case 9: goto L_80800620; break;
        case 10: goto L_80800620; break;
        case 11: goto L_80800620; break;
        case 12: goto L_80800620; break;
        case 13: goto L_80800620; break;
        case 14: goto L_80800620; break;
        case 15: goto L_80800620; break;
        case 16: goto L_8080054C; break;
        case 17: goto L_8080054C; break;
        case 18: goto L_808003A8; break;
        case 19: goto L_80800620; break;
        case 20: goto L_80800620; break;
        case 21: goto L_80800620; break;
        case 22: goto L_80800620; break;
        case 23: goto L_80800620; break;
        case 24: goto L_80800620; break;
        case 25: goto L_80800620; break;
        case 26: goto L_80800620; break;
        case 27: goto L_80800620; break;
        case 28: goto L_80800620; break;
        case 29: goto L_80800620; break;
        case 30: goto L_80800620; break;
        case 31: goto L_80800620; break;
        case 32: goto L_80800620; break;
        case 33: goto L_80800620; break;
        case 34: goto L_80800620; break;
        case 35: goto L_80800620; break;
        case 36: goto L_80800608; break;
        default: switch_error(__func__, 0x808003A0, 0x80800A3C);
    }
    // 0x808003A4: nop

L_808003A8:
    // 0x808003A8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808003AC: addiu       $at, $zero, 0x270
    ctx->r1 = ADD32(0, 0X270);
    // 0x808003B0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x808003B4: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x808003B8: bnel        $t8, $at, L_80800550
    if (ctx->r24 != ctx->r1) {
        // 0x808003BC: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80800550;
    }
    goto skip_0;
    // 0x808003BC: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x808003C0: jal         0x8008A340
    // 0x808003C4: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808003C4: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003C8: bnel        $v0, $zero, L_80800550
    if (ctx->r2 != 0) {
        // 0x808003CC: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80800550;
    }
    goto skip_1;
    // 0x808003CC: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_1:
    // 0x808003D0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808003D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808003DC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x808003E0: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x808003E4: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x808003E8: bnel        $t2, $at, L_80800550
    if (ctx->r10 != ctx->r1) {
        // 0x808003EC: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80800550;
    }
    goto skip_2;
    // 0x808003EC: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_2:
    // 0x808003F0: jal         0x800EC398
    // 0x808003F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EC398(rdram, ctx);
        goto after_1;
    // 0x808003F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x808003F8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003FC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800400: jal         0x800F1DF4
    // 0x80800404: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x80800404: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80800408: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080040C: jal         0x800F2094
    // 0x80800410: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F2094(rdram, ctx);
        goto after_3;
    // 0x80800410: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x80800414: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800424: nop

    // 0x80800428: bc1fl       L_80800550
    if (!c1cs) {
        // 0x8080042C: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80800550;
    }
    goto skip_3;
    // 0x8080042C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_3:
    // 0x80800430: jal         0x80109600
    // 0x80800434: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80109600(rdram, ctx);
        goto after_4;
    // 0x80800434: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_4:
    // 0x80800438: jal         0x8010A570
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: jal         0x80102424
    // 0x80800448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x8008A4B0
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x80103DFC
    // 0x80800460: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80103DFC(rdram, ctx);
        goto after_8;
    // 0x80800460: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80800464: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80800468: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080046C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80800470: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800474: lw          $t4, 0x48($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X48);
    // 0x80800478: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080047C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800480: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800484: jal         0x80086D50
    // 0x80800488: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800488: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_9:
    // 0x8080048C: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x80800490: jal         0x800DA564
    // 0x80800494: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA564(rdram, ctx);
        goto after_10;
    // 0x80800494: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80800498: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080049C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x808004A0: jal         0x800DA544
    // 0x808004A4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x808004A4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_11:
    // 0x808004A8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808004AC: addiu       $t7, $zero, 0x17E3
    ctx->r15 = ADD32(0, 0X17E3);
    // 0x808004B0: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x808004B4: beq         $t6, $zero, L_808004C4
    if (ctx->r14 == 0) {
        // 0x808004B8: nop
    
            goto L_808004C4;
    }
    // 0x808004B8: nop

    // 0x808004BC: b           L_8080051C
    // 0x808004C0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_8080051C;
    // 0x808004C0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_808004C4:
    // 0x808004C4: jal         0x800DA564
    // 0x808004C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA564(rdram, ctx);
        goto after_12;
    // 0x808004C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x808004CC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808004D0: bne         $v0, $at, L_80800518
    if (ctx->r2 != ctx->r1) {
        // 0x808004D4: addiu       $t9, $zero, 0x17E4
        ctx->r25 = ADD32(0, 0X17E4);
            goto L_80800518;
    }
    // 0x808004D4: addiu       $t9, $zero, 0x17E4
    ctx->r25 = ADD32(0, 0X17E4);
    // 0x808004D8: addiu       $t8, $zero, 0x1806
    ctx->r24 = ADD32(0, 0X1806);
    // 0x808004DC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x808004E0: jal         0x800DA544
    // 0x808004E4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x808004E4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_13:
    // 0x808004E8: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x808004EC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x808004F0: jal         0x800DA7A8
    // 0x808004F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800DA7A8(rdram, ctx);
        goto after_14;
    // 0x808004F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_14:
    // 0x808004F8: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800500: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800508: jal         0x800D1000
    // 0x8080050C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_15;
    // 0x8080050C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80800510: b           L_80800520
    // 0x80800514: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_80800520;
    // 0x80800514: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800518:
    // 0x80800518: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_8080051C:
    // 0x8080051C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800520:
    // 0x80800520: addiu       $t0, $zero, 0xA6
    ctx->r8 = ADD32(0, 0XA6);
    // 0x80800524: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800528: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080052C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800530: jal         0x8008A208
    // 0x80800534: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800534: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80800538: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x8080053C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800540: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x80800544: b           L_8080062C
    // 0x80800548: sb          $t2, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r10;
        goto L_8080062C;
    // 0x80800548: sb          $t2, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r10;
L_8080054C:
    // 0x8080054C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_80800550:
    // 0x80800550: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x80800554: srl         $t4, $t3, 22
    ctx->r12 = S32(U32(ctx->r11) >> 22);
    // 0x80800558: bne         $t4, $zero, L_80800584
    if (ctx->r12 != 0) {
        // 0x8080055C: nop
    
            goto L_80800584;
    }
    // 0x8080055C: nop

    // 0x80800560: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x80800564: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80800568: srl         $t5, $a0, 5
    ctx->r13 = S32(U32(ctx->r4) >> 5);
    // 0x8080056C: jal         0x800F64A4
    // 0x80800570: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800F64A4(rdram, ctx);
        goto after_17;
    // 0x80800570: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_17:
    // 0x80800574: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x80800578: nop
    
            goto L_80800584;
    }
    // 0x80800578: nop

    // 0x8080057C: b           L_8080062C
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080062C;
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800584:
    // 0x80800584: jal         0x808009D4
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009D4_charmouredcaveman(rdram, ctx);
        goto after_18;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x80109600
    // 0x80800594: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_80109600(rdram, ctx);
        goto after_19;
    // 0x80800594: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_19:
    // 0x80800598: b           L_8080062C
    // 0x8080059C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x8080059C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A0:
    // 0x808005A0: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x808005A4: jal         0x800DA980
    // 0x808005A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA980(rdram, ctx);
        goto after_20;
    // 0x808005A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x808005AC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x808005B0: b           L_8080062C
    // 0x808005B4: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
        goto L_8080062C;
    // 0x808005B4: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
L_808005B8:
    // 0x808005B8: lh          $v0, 0x68($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X68);
    // 0x808005BC: addiu       $at, $zero, 0x17E2
    ctx->r1 = ADD32(0, 0X17E2);
    // 0x808005C0: bne         $v0, $at, L_808005F8
    if (ctx->r2 != ctx->r1) {
        // 0x808005C4: nop
    
            goto L_808005F8;
    }
    // 0x808005C4: nop

    // 0x808005C8: jal         0x800DA544
    // 0x808005CC: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    func_800DA544(rdram, ctx);
        goto after_21;
    // 0x808005CC: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    after_21:
    // 0x808005D0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x808005DC: jal         0x8010A590
    // 0x808005E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_8010A590(rdram, ctx);
        goto after_22;
    // 0x808005E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_22:
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x80102424
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_23;
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x808005F0: b           L_8080062C
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F8:
    // 0x808005F8: jal         0x800FFAB0
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_24;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800600: b           L_8080062C
    // 0x80800604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x80800604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800608:
    // 0x80800608: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1116, 0XB68) << 16);
    // 0x8080060C: addiu       $a0, $a0, 0xB68
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1116, 0XB68));
    // 0x80800610: jal         0x80088090
    // 0x80800614: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800614: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_25:
    // 0x80800618: b           L_8080062C
    // 0x8080061C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x8080061C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800620:
    // 0x80800620: b           L_8080062C
    // 0x80800624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080062C;
    // 0x80800624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080062C:
    // 0x8080062C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800630: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800634: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800638: jr          $ra
    // 0x8080063C: nop

    return;
    // 0x8080063C: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855D0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855D0);
    return;
    // 0x800855D4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80804054_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804054: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80804058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080405C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80804060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804064: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80804068: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8080406C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80804070: jal         0x80100094
    // 0x80804074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80804078: jal         0x800D8FF8
    // 0x8080407C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080407C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80804080: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80804084: lw          $a2, 0xF0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF0);
    // 0x80804088: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080408C: jal         0x800EF934
    // 0x80804090: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x80804090: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_2:
    // 0x80804094: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80804098: jal         0x800EF04C
    // 0x8080409C: addiu       $a1, $s0, 0xE4
    ctx->r5 = ADD32(ctx->r16, 0XE4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8080409C: addiu       $a1, $s0, 0xE4
    ctx->r5 = ADD32(ctx->r16, 0XE4);
    after_3:
    // 0x808040A0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808040A4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x808040A8: jal         0x800EF934
    // 0x808040AC: lw          $a2, 0x100($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X100);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x808040AC: lw          $a2, 0x100($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X100);
    after_4:
    // 0x808040B0: addiu       $a1, $s0, 0xF4
    ctx->r5 = ADD32(ctx->r16, 0XF4);
    // 0x808040B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808040B8: jal         0x800EF04C
    // 0x808040BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808040BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x808040C0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808040C4: jal         0x800EEAD4
    // 0x808040C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x808040C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x808040CC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808040D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808040D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808040D8: jal         0x800EECE0
    // 0x808040DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EECE0(rdram, ctx);
        goto after_7;
    // 0x808040DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x808040E0: beq         $v0, $zero, L_80804134
    if (ctx->r2 == 0) {
        // 0x808040E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80804134;
    }
    // 0x808040E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808040E8: lwc1        $f12, 0x100($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X100);
    // 0x808040EC: jal         0x800F1DCC
    // 0x808040F0: lwc1        $f14, 0xF0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF0);
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x808040F0: lwc1        $f14, 0xF0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF0);
    after_8:
    // 0x808040F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808040F8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808040FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80804100: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80804104: nop

    // 0x80804108: bc1fl       L_80804124
    if (!c1cs) {
        // 0x8080410C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80804124;
    }
    goto skip_0;
    // 0x8080410C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80804110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804114: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804118: b           L_80804128
    // 0x8080411C: nop

        goto L_80804128;
    // 0x8080411C: nop

    // 0x80804120: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80804124:
    // 0x80804124: nop

L_80804128:
    // 0x80804128: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080412C: b           L_80804140
    // 0x80804130: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
        goto L_80804140;
    // 0x80804130: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80804134:
    // 0x80804134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80804138: nop

    // 0x8080413C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80804140:
    // 0x80804140: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80804144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804148: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8080414C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804150: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80804154: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80804158: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8080415C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80804160: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80804164: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80804168: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080416C: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80804170: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80804174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804178: nop

    // 0x8080417C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804180: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80804184: swc1        $f16, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f16.u32l;
    // 0x80804188: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080418C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804190: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80804194: nop

    // 0x80804198: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8080419C: bne         $at, $zero, L_808041CC
    if (ctx->r1 != 0) {
        // 0x808041A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808041CC;
    }
    // 0x808041A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x808041A4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808041B4: swc1        $f6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f6.u32l;
    // 0x808041B8: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041BC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808041C0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808041C4: b           L_808041F8
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
        goto L_808041F8;
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041CC:
    // 0x808041CC: bgez        $a0, L_808041F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808041D0: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808041F4;
    }
    // 0x808041D0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041D8: nop

    // 0x808041DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808041E0: swc1        $f18, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f18.u32l;
    // 0x808041E4: lwc1        $f4, 0xD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808041EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808041F0: nop

L_808041F4:
    // 0x808041F4: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041F8:
    // 0x808041F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X477C) << 16);
    // 0x808041FC: lwc1        $f10, 0x477C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X477C));
    // 0x80804200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4780) << 16);
    // 0x80804204: lwc1        $f18, 0x4780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4780));
    // 0x80804208: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080420C: lwc1        $f6, 0xD0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80804210: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80804214: nop

    // 0x80804218: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080421C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80804220: swc1        $f10, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f10.u32l;
    // 0x80804224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080422C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void _bsbreegullbash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B00: syscall     26
    recomp_syscall_handler(rdram, ctx, 0x80082B00);
    return;
    // 0x80082B04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800D28_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800D2C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800D34: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800D38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800D3C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800D40: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800D44: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800D48: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800D4C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800D50: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D54: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800D58: jal         0x80100094
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D60: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x80800D64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800D68: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800D6C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800D70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800D74: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80800D78: beq         $t7, $zero, L_80800DF4
    if (ctx->r15 == 0) {
        // 0x80800D7C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800DF4;
    }
    // 0x80800D7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D80: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800D84: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800D88: addiu       $s4, $s2, 0x18
    ctx->r20 = ADD32(ctx->r18, 0X18);
    // 0x80800D8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800D90:
    // 0x80800D90: jal         0x800EEAD4
    // 0x80800D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x80800D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800D98: beql        $s0, $zero, L_80800DB4
    if (ctx->r16 == 0) {
        // 0x80800D9C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800DB4;
    }
    goto skip_0;
    // 0x80800D9C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
    // 0x80800DA0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800DA4: nop

    // 0x80800DA8: bc1f        L_80800DB4
    if (!c1cs) {
        // 0x80800DAC: nop
    
            goto L_80800DB4;
    }
    // 0x80800DAC: nop

    // 0x80800DB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800DB4:
    // 0x80800DB4: beql        $s0, $zero, L_80800DD0
    if (ctx->r16 == 0) {
        // 0x80800DB8: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_80800DD0;
    }
    goto skip_1;
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_1:
    // 0x80800DBC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800DC0: nop

    // 0x80800DC4: bc1fl       L_80800DD8
    if (!c1cs) {
        // 0x80800DC8: swc1        $f24, 0x58($s1)
        MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
            goto L_80800DD8;
    }
    goto skip_2;
    // 0x80800DC8: swc1        $f24, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
    skip_2:
    // 0x80800DCC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80800DD0:
    // 0x80800DD0: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80800DD4: swc1        $f24, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
L_80800DD8:
    // 0x80800DD8: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80800DDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800DE0: addiu       $s1, $s1, 0x60
    ctx->r17 = ADD32(ctx->r17, 0X60);
    // 0x80800DE4: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800DE8: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x80800DEC: bnel        $at, $zero, L_80800D90
    if (ctx->r1 != 0) {
        // 0x80800DF0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800D90;
    }
    goto skip_3;
    // 0x80800DF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_80800DF4:
    // 0x80800DF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800DF8: beq         $s3, $at, L_80800E48
    if (ctx->r19 == ctx->r1) {
        // 0x80800DFC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800E48;
    }
    // 0x80800DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E00: jal         0x80100094
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800E08: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80800E0C: subu        $t0, $t0, $s3
    ctx->r8 = SUB32(ctx->r8, ctx->r19);
    // 0x80800E10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800E14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800E1C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80800E20: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x80800E24: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80800E28: swc1        $f6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f6.u32l;
    // 0x80800E2C: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x80800E30: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800E34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E38: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x80800E3C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80800E40: jal         0x80800824
    // 0x80800E44: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800824_chnewfreezy(rdram, ctx);
        goto after_3;
    // 0x80800E44: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
L_80800E48:
    // 0x80800E48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800E4C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800E50: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800E54: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800E58: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800E5C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800E60: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800E64: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E68: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800E6C: jr          $ra
    // 0x80800E70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800E70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
