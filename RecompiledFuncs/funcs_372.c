#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbabykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827D0: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827D0);
    return;
    // 0x800827D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800B7B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B30: jr          $ra
    // 0x800B7B34: sh          $a0, -0x7E6C($at)
    MEM_H(-0X7E6C, ctx->r1) = ctx->r4;
    return;
    // 0x800B7B34: sh          $a0, -0x7E6C($at)
    MEM_H(-0X7E6C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800800_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800808: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080080C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800810: jal         0x80100094
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800818: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x8080081C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080084C;
    }
    // 0x8080081C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800820: jal         0x80100094
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800828: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080082C: jal         0x80089888
    // 0x80800830: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800830: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800838: jal         0x80100094
    // 0x8080083C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080083C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800844: jal         0x80089880
    // 0x80800848: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800848: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_8080084C:
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800854: jr          $ra
    // 0x80800858: nop

    return;
    // 0x80800858: nop

;}
RECOMP_FUNC void ncpod_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808004E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808004E8: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x808004EC: jal         0x808002E8
    // 0x808004F0: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    func_808002E8_ncpod(rdram, ctx);
        goto after_0;
    // 0x808004F0: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    after_0:
    // 0x808004F4: beq         $v0, $zero, L_80800534
    if (ctx->r2 == 0) {
        // 0x808004F8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800534;
    }
    // 0x808004F8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808004FC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80800500: lhu         $t9, 0x18($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X18);
    // 0x80800504: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800508: beql        $t0, $zero, L_80800538
    if (ctx->r8 == 0) {
        // 0x8080050C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800538;
    }
    goto skip_0;
    // 0x8080050C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80800510: jal         0x80101074
    // 0x80800514: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80101074(rdram, ctx);
        goto after_1;
    // 0x80800514: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800518: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8080051C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800520: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800524: jal         0x8010114C
    // 0x80800528: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800528: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_2:
    // 0x8080052C: b           L_8080053C
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080053C;
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800534:
    // 0x80800534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800538:
    // 0x80800538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080053C:
    // 0x8080053C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800540: jr          $ra
    // 0x80800544: nop

    return;
    // 0x80800544: nop

;}
RECOMP_FUNC void func_80110840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110840: jr          $ra
    // 0x80110844: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    return;
    // 0x80110844: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
;}
RECOMP_FUNC void bstaxi_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080148C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801490: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21C8) << 16);
    // 0x80801494: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801498: jr          $ra
    // 0x8080149C: lw          $v0, 0x21C8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21C8));
    return;
    // 0x8080149C: lw          $v0, 0x21C8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21C8));
;}
RECOMP_FUNC void gcnewoption_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F0C: jr          $ra
    // 0x80802F10: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    return;
    // 0x80802F10: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
;}
RECOMP_FUNC void func_8080022C_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: jr          $ra
    // 0x80800230: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800230: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8008E2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E2B4: jal         0x8009E6F8
    // 0x8008E2B8: nop

    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x8008E2B8: nop

    after_0:
    // 0x8008E2BC: addiu       $t6, $v0, -0x2B
    ctx->r14 = ADD32(ctx->r2, -0X2B);
    // 0x8008E2C0: sltiu       $at, $t6, 0x22
    ctx->r1 = ctx->r14 < 0X22 ? 1 : 0;
    // 0x8008E2C4: beq         $at, $zero, L_8008E2E8
    if (ctx->r1 == 0) {
        // 0x8008E2C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8008E2E8;
    }
    // 0x8008E2C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008E2CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E2D0: addu        $at, $at, $t6
    gpr jr_addend_8008E2D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008E2D4: lw          $t6, 0x4AE8($at)
    ctx->r14 = ADD32(ctx->r1, 0X4AE8);
    // 0x8008E2D8: jr          $t6
    // 0x8008E2DC: nop

    switch (jr_addend_8008E2D8 >> 2) {
        case 0: goto L_8008E2E0; break;
        case 1: goto L_8008E2E0; break;
        case 2: goto L_8008E2E0; break;
        case 3: goto L_8008E2E0; break;
        case 4: goto L_8008E2E8; break;
        case 5: goto L_8008E2E0; break;
        case 6: goto L_8008E2E8; break;
        case 7: goto L_8008E2E8; break;
        case 8: goto L_8008E2E8; break;
        case 9: goto L_8008E2E8; break;
        case 10: goto L_8008E2E8; break;
        case 11: goto L_8008E2E8; break;
        case 12: goto L_8008E2E8; break;
        case 13: goto L_8008E2E8; break;
        case 14: goto L_8008E2E0; break;
        case 15: goto L_8008E2E8; break;
        case 16: goto L_8008E2E8; break;
        case 17: goto L_8008E2E8; break;
        case 18: goto L_8008E2E8; break;
        case 19: goto L_8008E2E8; break;
        case 20: goto L_8008E2E8; break;
        case 21: goto L_8008E2E8; break;
        case 22: goto L_8008E2E8; break;
        case 23: goto L_8008E2E8; break;
        case 24: goto L_8008E2E8; break;
        case 25: goto L_8008E2E8; break;
        case 26: goto L_8008E2E8; break;
        case 27: goto L_8008E2E8; break;
        case 28: goto L_8008E2E8; break;
        case 29: goto L_8008E2E8; break;
        case 30: goto L_8008E2E8; break;
        case 31: goto L_8008E2E8; break;
        case 32: goto L_8008E2E8; break;
        case 33: goto L_8008E2E0; break;
        default: switch_error(__func__, 0x8008E2D8, 0x80124AE8);
    }
    // 0x8008E2DC: nop

L_8008E2E0:
    // 0x8008E2E0: b           L_8008E2EC
    // 0x8008E2E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8008E2EC;
    // 0x8008E2E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8008E2E8:
    // 0x8008E2E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008E2EC:
    // 0x8008E2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E2F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008E2F8: jr          $ra
    // 0x8008E2FC: nop

    return;
    // 0x8008E2FC: nop

;}
RECOMP_FUNC void func_80800968_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080096C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800974: jal         0x80100094
    // 0x80800978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080097C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800980: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800984: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800988: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X2044) << 16);
    // 0x8080098C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800990: addiu       $a2, $a2, 0x2044
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X2044));
    // 0x80800994: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x80800998: bc1fl       L_808009C0
    if (!c1cs) {
        // 0x8080099C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009C0;
    }
    goto skip_0;
    // 0x8080099C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009A0: jal         0x80089D18
    // 0x808009A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808009A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808009AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009B4: nop

    // 0x808009B8: swc1        $f8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f8.u32l;
    // 0x808009BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009C0:
    // 0x808009C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009C4: jr          $ra
    // 0x808009C8: nop

    return;
    // 0x808009C8: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E80: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E80);
    return;
    // 0x80083E84: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_800C31DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C31DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C31E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C31E4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C31E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C31EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C31F0: beq         $t6, $zero, L_800C3214
    if (ctx->r14 == 0) {
        // 0x800C31F4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3214;
    }
    // 0x800C31F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C31F8: jal         0x800C1414
    // 0x800C31FC: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C31FC: nop

    after_0:
    // 0x800C3200: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3208: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C320C: jal         0x800C13A0
    // 0x800C3210: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C3210: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    after_1:
L_800C3214:
    // 0x800C3214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C321C: jr          $ra
    // 0x800C3220: nop

    return;
    // 0x800C3220: nop

;}
RECOMP_FUNC void _chchuffycont_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C40: syscall     433
    recomp_syscall_handler(rdram, ctx, 0x80086C40);
    return;
    // 0x80086C44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chtntmineshoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087388: syscall     559
    recomp_syscall_handler(rdram, ctx, 0x80087388);
    return;
    // 0x8008738C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800100_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800104: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800108: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080010C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800110: jal         0x800D9078
    // 0x80800114: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800114: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800118: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080011C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800120: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800124: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80800128: beq         $at, $zero, L_80800394
    if (ctx->r1 == 0) {
        // 0x8080012C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80800394;
    }
    // 0x8080012C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800130: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1216, 0XEE4) << 16);
    // 0x80800138: addu        $at, $at, $t7
    gpr jr_addend_80800140 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080013C: lw          $t7, 0xEE4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1216, 0XEE4));
    // 0x80800140: jr          $t7
    // 0x80800144: nop

    switch (jr_addend_80800140 >> 2) {
        case 0: goto L_80800148; break;
        case 1: goto L_808001E8; break;
        case 2: goto L_80800200; break;
        case 3: goto L_80800274; break;
        case 4: goto L_808002A4; break;
        case 5: goto L_808002D4; break;
        case 6: goto L_80800304; break;
        case 7: goto L_80800394; break;
        case 8: goto L_8080031C; break;
        default: switch_error(__func__, 0x80800140, 0x80800EE4);
    }
    // 0x80800144: nop

L_80800148:
    // 0x80800148: jal         0x80800980
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800980_chbiggafoot(rdram, ctx);
        goto after_1;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800150: jal         0x808009EC
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009EC_chbiggafoot(rdram, ctx);
        goto after_2;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800158: beq         $v0, $zero, L_808001A0
    if (ctx->r2 == 0) {
        // 0x8080015C: nop
    
            goto L_808001A0;
    }
    // 0x8080015C: nop

    // 0x80800160: jal         0x800F54E4
    // 0x80800164: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800164: nop

    after_3:
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080016C: jal         0x800F7F98
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80102424
    // 0x8080017C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x8080017C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80108B04
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_6;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x8008A4B0
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800198: b           L_808001DC
    // 0x8080019C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
        goto L_808001DC;
    // 0x8080019C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_808001A0:
    // 0x808001A0: jal         0x808008FC
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008FC_chbiggafoot(rdram, ctx);
        goto after_8;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001A8: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001AC: nop
    
            goto L_808001D0;
    }
    // 0x808001AC: nop

    // 0x808001B0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001BC: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x808001C0: jal         0x80102424
    // 0x808001C4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808001C4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_9:
    // 0x808001C8: b           L_808001DC
    // 0x808001CC: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
        goto L_808001DC;
    // 0x808001CC: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_808001D0:
    // 0x808001D0: jal         0x808008D4
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chbiggafoot(rdram, ctx);
        goto after_10;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001D8: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_808001DC:
    // 0x808001DC: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x808001E0: b           L_80800394
    // 0x808001E4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80800394;
    // 0x808001E4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_808001E8:
    // 0x808001E8: jal         0x80800980
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800980_chbiggafoot(rdram, ctx);
        goto after_11;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001F0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808001F4: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x808001F8: b           L_80800394
    // 0x808001FC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
        goto L_80800394;
    // 0x808001FC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80800200:
    // 0x80800200: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800204: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800208: bltz        $t4, L_80800238
    if (SIGNED(ctx->r12) < 0) {
        // 0x8080020C: nop
    
            goto L_80800238;
    }
    // 0x8080020C: nop

    // 0x80800210: jal         0x80101F24
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800218: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1216, 0XF08) << 16);
    // 0x8080021C: lwc1        $f4, 0xF08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1216, 0XF08));
    // 0x80800220: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800224: nop

    // 0x80800228: bc1f        L_80800238
    if (!c1cs) {
        // 0x8080022C: nop
    
            goto L_80800238;
    }
    // 0x8080022C: nop

    // 0x80800230: jal         0x8010A590
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_13;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_80800238:
    // 0x80800238: jal         0x80800980
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800980_chbiggafoot(rdram, ctx);
        goto after_14;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800240: jal         0x80101DDC
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_15;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800248: beql        $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x8080024C: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80800268;
    }
    goto skip_0;
    // 0x8080024C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800250: jal         0x8010A570
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_16;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80101FDC
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800264: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_80800268:
    // 0x80800268: srl         $t5, $v1, 10
    ctx->r13 = S32(U32(ctx->r3) >> 10);
    // 0x8080026C: b           L_80800394
    // 0x80800270: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
        goto L_80800394;
    // 0x80800270: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80800274:
    // 0x80800274: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800278: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x8080027C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80800288: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x8080028C: jal         0x80102BF8
    // 0x80800290: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80102BF8(rdram, ctx);
        goto after_18;
    // 0x80800290: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_18:
    // 0x80800294: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800298: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080029C: b           L_80800394
    // 0x808002A0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_80800394;
    // 0x808002A0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_808002A4:
    // 0x808002A4: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808002A8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808002AC: jal         0x80101E14
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808002B4: beql        $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002B8: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_808002C8;
    }
    goto skip_1;
    // 0x808002B8: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808002BC: jal         0x80800BA4
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BA4_chbiggafoot(rdram, ctx);
        goto after_20;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808002C4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_808002C8:
    // 0x808002C8: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808002CC: b           L_80800394
    // 0x808002D0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_80800394;
    // 0x808002D0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_808002D4:
    // 0x808002D4: jal         0x80101DDC
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_21;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808002DC: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002EC;
    }
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80102424
    // 0x808002E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x808002E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
L_808002EC:
    // 0x808002EC: jal         0x80800C04
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C04_chbiggafoot(rdram, ctx);
        goto after_23;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808002F4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808002F8: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x808002FC: b           L_80800394
    // 0x80800300: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_80800394;
    // 0x80800300: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80800304:
    // 0x80800304: jal         0x80800C04
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C04_chbiggafoot(rdram, ctx);
        goto after_24;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8080030C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800310: srl         $t9, $v1, 10
    ctx->r25 = S32(U32(ctx->r3) >> 10);
    // 0x80800314: b           L_80800394
    // 0x80800318: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
        goto L_80800394;
    // 0x80800318: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_8080031C:
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x80102D78
    // 0x80800324: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_25;
    // 0x80800324: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_25:
    // 0x80800328: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080032C: jal         0x80101F24
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_26;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800334: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1216, 0X1124) << 16);
    // 0x80800338: addiu       $a1, $a1, 0x1124
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1216, 0X1124));
    // 0x8080033C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800340: jal         0x800F3780
    // 0x80800344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_27;
    // 0x80800344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_27:
    // 0x80800348: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080034C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800350: nop

    // 0x80800354: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800358: jal         0x800D8FF8
    // 0x8080035C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_28;
    // 0x8080035C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_28:
    // 0x80800360: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800370: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800374: jal         0x80102B2C
    // 0x80800378: nop

    func_80102B2C(rdram, ctx);
        goto after_29;
    // 0x80800378: nop

    after_29:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x8010B990
    // 0x80800384: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_30;
    // 0x80800384: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_30:
    // 0x80800388: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080038C: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x80800390: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80800394:
    // 0x80800394: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80800398: bne         $at, $zero, L_80800414
    if (ctx->r1 != 0) {
        // 0x8080039C: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_80800414;
    }
    // 0x8080039C: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x808003A0: beql        $at, $zero, L_80800418
    if (ctx->r1 == 0) {
        // 0x808003A4: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800418;
    }
    goto skip_2;
    // 0x808003A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x808003A8: jal         0x800D8FF8
    // 0x808003AC: nop

    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x808003AC: nop

    after_31:
    // 0x808003B0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808003B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808003BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003C0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808003C4: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x808003C8: jal         0x80013970
    // 0x808003CC: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    func_80013970(rdram, ctx);
        goto after_32;
    // 0x808003CC: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    after_32:
    // 0x808003D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808003D4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808003D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003DC: lui         $a3, 0xBE4C
    ctx->r7 = S32(0XBE4C << 16);
    // 0x808003E0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003EC: jal         0x800F10B4
    // 0x808003F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_33;
    // 0x808003F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_33:
    // 0x808003F4: jal         0x800D8FF8
    // 0x808003F8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x808003F8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    after_34:
    // 0x808003FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800400: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800404: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800408: jal         0x800F15F8
    // 0x8080040C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_800F15F8(rdram, ctx);
        goto after_35;
    // 0x8080040C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_35:
    // 0x80800410: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_80800414:
    // 0x80800414: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_80800418:
    // 0x80800418: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8080041C: jal         0x800EE7F8
    // 0x80800420: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_36;
    // 0x80800420: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_36:
    // 0x80800424: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800428: lui         $a1, 0x430C
    ctx->r5 = S32(0X430C << 16);
    // 0x8080042C: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x80800430: jal         0x80089F18
    // 0x80800434: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_37;
    // 0x80800434: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_37:
    // 0x80800438: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x8080043C: beq         $t1, $zero, L_8080044C
    if (ctx->r9 == 0) {
        // 0x80800440: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_8080044C;
    }
    // 0x80800440: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800444: jal         0x80089F38
    // 0x80800448: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sudeflect_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x80800448: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_38:
L_8080044C:
    // 0x8080044C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800450: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80800454: jal         0x800EF1B8
    // 0x80800458: lui         $a2, 0xC37A
    ctx->r6 = S32(0XC37A << 16);
    func_800EF1B8(rdram, ctx);
        goto after_39;
    // 0x80800458: lui         $a2, 0xC37A
    ctx->r6 = S32(0XC37A << 16);
    after_39:
    // 0x8080045C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800460: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800464: lw          $a2, 0x50($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X50);
    // 0x80800468: jal         0x800EFA4C
    // 0x8080046C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_40;
    // 0x8080046C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_40:
    // 0x80800470: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X113C) << 16);
    // 0x80800474: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1216, 0X1148) << 16);
    // 0x80800478: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8080047C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800480: addiu       $a3, $a3, 0x1148
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1216, 0X1148));
    // 0x80800484: addiu       $a2, $a2, 0x113C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X113C));
    // 0x80800488: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080048C: jal         0x80089F30
    // 0x80800490: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _sudeflect_entrypoint_3(rdram, ctx);
        goto after_41;
    // 0x80800490: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_41:
    // 0x80800494: jal         0x80800A9C
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A9C_chbiggafoot(rdram, ctx);
        goto after_42;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080049C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808004A8: jr          $ra
    // 0x808004AC: nop

    return;
    // 0x808004AC: nop

;}
RECOMP_FUNC void func_80021A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021A00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021A08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80021A0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021A10: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A14: sb          $zero, -0x15D0($at)
    MEM_B(-0X15D0, ctx->r1) = 0;
    // 0x80021A18: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A1C: sb          $zero, -0x15CF($at)
    MEM_B(-0X15CF, ctx->r1) = 0;
    // 0x80021A20: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A24: sb          $zero, -0x15CE($at)
    MEM_B(-0X15CE, ctx->r1) = 0;
    // 0x80021A28: lbu         $s0, 0x2B($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X2B);
    // 0x80021A2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021A30: beq         $s0, $at, L_80021A58
    if (ctx->r16 == ctx->r1) {
        // 0x80021A34: nop
    
            goto L_80021A58;
    }
    // 0x80021A34: nop

    // 0x80021A38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021A3C: beq         $s0, $at, L_80021A6C
    if (ctx->r16 == ctx->r1) {
        // 0x80021A40: nop
    
            goto L_80021A6C;
    }
    // 0x80021A40: nop

    // 0x80021A44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80021A48: beq         $s0, $at, L_80021A80
    if (ctx->r16 == ctx->r1) {
        // 0x80021A4C: nop
    
            goto L_80021A80;
    }
    // 0x80021A4C: nop

    // 0x80021A50: b           L_80021A94
    // 0x80021A54: nop

        goto L_80021A94;
    // 0x80021A54: nop

L_80021A58:
    // 0x80021A58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021A5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A60: sb          $t6, -0x15CF($at)
    MEM_B(-0X15CF, ctx->r1) = ctx->r14;
    // 0x80021A64: b           L_80021A94
    // 0x80021A68: nop

        goto L_80021A94;
    // 0x80021A68: nop

L_80021A6C:
    // 0x80021A6C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80021A70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A74: sb          $t7, -0x15CE($at)
    MEM_B(-0X15CE, ctx->r1) = ctx->r15;
    // 0x80021A78: b           L_80021A94
    // 0x80021A7C: nop

        goto L_80021A94;
    // 0x80021A7C: nop

L_80021A80:
    // 0x80021A80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80021A84: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021A88: sb          $t8, -0x15D0($at)
    MEM_B(-0X15D0, ctx->r1) = ctx->r24;
    // 0x80021A8C: b           L_80021A94
    // 0x80021A90: nop

        goto L_80021A94;
    // 0x80021A90: nop

L_80021A94:
    // 0x80021A94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80021A98:
    // 0x80021A98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80021A9C: jal         0x80021AD0
    // 0x80021AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80021AD0(rdram, ctx);
        goto after_0;
    // 0x80021AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80021AA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80021AA8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80021AAC: blez        $t0, L_80021A98
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80021AB0: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80021A98;
    }
    // 0x80021AB0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80021AB4: b           L_80021ABC
    // 0x80021AB8: nop

        goto L_80021ABC;
    // 0x80021AB8: nop

L_80021ABC:
    // 0x80021ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80021AC8: jr          $ra
    // 0x80021ACC: nop

    return;
    // 0x80021ACC: nop

;}
RECOMP_FUNC void func_80800A54_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A54: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800A58: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80800A5C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A64: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800A68: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800A6C: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    // 0x80800A70: jal         0x80100094
    // 0x80800A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A78: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80800A7C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800A80: slti        $at, $a2, 0x58
    ctx->r1 = SIGNED(ctx->r6) < 0X58 ? 1 : 0;
    // 0x80800A84: bne         $at, $zero, L_80800AA8
    if (ctx->r1 != 0) {
        // 0x80800A88: addiu       $t6, $a2, -0x29
        ctx->r14 = ADD32(ctx->r6, -0X29);
            goto L_80800AA8;
    }
    // 0x80800A88: addiu       $t6, $a2, -0x29
    ctx->r14 = ADD32(ctx->r6, -0X29);
    // 0x80800A8C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A90: beq         $a2, $at, L_80800AF0
    if (ctx->r6 == ctx->r1) {
        // 0x80800A94: addiu       $at, $zero, 0xB8
        ctx->r1 = ADD32(0, 0XB8);
            goto L_80800AF0;
    }
    // 0x80800A94: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x80800A98: beq         $a2, $at, L_80800F00
    if (ctx->r6 == ctx->r1) {
        // 0x80800A9C: nop
    
            goto L_80800F00;
    }
    // 0x80800A9C: nop

    // 0x80800AA0: b           L_80800F18
    // 0x80800AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F18;
    // 0x80800AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AA8:
    // 0x80800AA8: slti        $at, $a2, 0xF
    ctx->r1 = SIGNED(ctx->r6) < 0XF ? 1 : 0;
    // 0x80800AAC: bne         $at, $zero, L_80800AD0
    if (ctx->r1 != 0) {
        // 0x80800AB0: sltiu       $at, $t6, 0x2F
        ctx->r1 = ctx->r14 < 0X2F ? 1 : 0;
            goto L_80800AD0;
    }
    // 0x80800AB0: sltiu       $at, $t6, 0x2F
    ctx->r1 = ctx->r14 < 0X2F ? 1 : 0;
    // 0x80800AB4: beq         $at, $zero, L_80800AE8
    if (ctx->r1 == 0) {
        // 0x80800AB8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800AE8;
    }
    // 0x80800AB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800ABC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X24B8) << 16);
    // 0x80800AC0: addu        $at, $at, $t6
    gpr jr_addend_80800AC8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800AC4: lw          $t6, 0x24B8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1364, 0X24B8));
    // 0x80800AC8: jr          $t6
    // 0x80800ACC: nop

    switch (jr_addend_80800AC8 >> 2) {
        case 0: goto L_80800EC8; break;
        case 1: goto L_80800ED8; break;
        case 2: goto L_80800AE8; break;
        case 3: goto L_80800EE8; break;
        case 4: goto L_80800AE8; break;
        case 5: goto L_80800B00; break;
        case 6: goto L_80800B1C; break;
        case 7: goto L_80800AE8; break;
        case 8: goto L_80800E3C; break;
        case 9: goto L_80800AE8; break;
        case 10: goto L_80800AE8; break;
        case 11: goto L_80800AE8; break;
        case 12: goto L_80800AE8; break;
        case 13: goto L_80800AE8; break;
        case 14: goto L_80800AE8; break;
        case 15: goto L_80800AE8; break;
        case 16: goto L_80800AE8; break;
        case 17: goto L_80800AE8; break;
        case 18: goto L_80800AE8; break;
        case 19: goto L_80800AE8; break;
        case 20: goto L_80800B38; break;
        case 21: goto L_80800AE8; break;
        case 22: goto L_80800AE8; break;
        case 23: goto L_80800AE8; break;
        case 24: goto L_80800AE8; break;
        case 25: goto L_80800AE8; break;
        case 26: goto L_80800AE8; break;
        case 27: goto L_80800AE8; break;
        case 28: goto L_80800AE8; break;
        case 29: goto L_80800AE8; break;
        case 30: goto L_80800AE8; break;
        case 31: goto L_80800AE8; break;
        case 32: goto L_80800AE8; break;
        case 33: goto L_80800AE8; break;
        case 34: goto L_80800C58; break;
        case 35: goto L_80800C98; break;
        case 36: goto L_80800AE8; break;
        case 37: goto L_80800AE8; break;
        case 38: goto L_80800AE8; break;
        case 39: goto L_80800AE8; break;
        case 40: goto L_80800AE8; break;
        case 41: goto L_80800DF4; break;
        case 42: goto L_80800AE8; break;
        case 43: goto L_80800AE8; break;
        case 44: goto L_80800AE8; break;
        case 45: goto L_80800AE8; break;
        case 46: goto L_80800E10; break;
        default: switch_error(__func__, 0x80800AC8, 0x808024B8);
    }
    // 0x80800ACC: nop

L_80800AD0:
    // 0x80800AD0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800AD4: beq         $a2, $at, L_80800CA0
    if (ctx->r6 == ctx->r1) {
        // 0x80800AD8: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_80800CA0;
    }
    // 0x80800AD8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80800ADC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800AE0: beq         $a2, $at, L_80800D90
    if (ctx->r6 == ctx->r1) {
        // 0x80800AE4: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_80800D90;
    }
    // 0x80800AE4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_80800AE8:
    // 0x80800AE8: b           L_80800F18
    // 0x80800AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F18;
    // 0x80800AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AF0:
    // 0x80800AF0: jal         0x80800F28
    // 0x80800AF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80800F28_chaliendad(rdram, ctx);
        goto after_1;
    // 0x80800AF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x80800AF8: b           L_80800F18
    // 0x80800AFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800AFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B00:
    // 0x80800B00: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80800B04: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800B08: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800B0C: jal         0x80801110
    // 0x80800B10: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801110_chaliendad(rdram, ctx);
        goto after_2;
    // 0x80800B10: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x80800B14: b           L_80800F18
    // 0x80800B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B1C:
    // 0x80800B1C: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80800B20: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800B24: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800B28: jal         0x80801220
    // 0x80800B2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801220_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80800B2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x80800B30: b           L_80800F18
    // 0x80800B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B38:
    // 0x80800B38: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80800B3C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800B40: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800B44: beq         $v0, $zero, L_80800B78
    if (ctx->r2 == 0) {
        // 0x80800B48: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80800B78;
    }
    // 0x80800B48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800B4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B50: beq         $v0, $at, L_80800BC0
    if (ctx->r2 == ctx->r1) {
        // 0x80800B54: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_80800BC0;
    }
    // 0x80800B54: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800B58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B5C: beq         $v0, $at, L_80800BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80800B60: addiu       $a0, $zero, 0x466
        ctx->r4 = ADD32(0, 0X466);
            goto L_80800BFC;
    }
    // 0x80800B60: addiu       $a0, $zero, 0x466
    ctx->r4 = ADD32(0, 0X466);
    // 0x80800B64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B68: beq         $v0, $at, L_80800C20
    if (ctx->r2 == ctx->r1) {
        // 0x80800B6C: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_80800C20;
    }
    // 0x80800B6C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80800B70: b           L_80800F18
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B78:
    // 0x80800B78: jal         0x800EE7F8
    // 0x80800B7C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800B7C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800B80: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B88: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800B8C: lui         $a3, 0x404C
    ctx->r7 = S32(0X404C << 16);
    // 0x80800B90: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x80800B94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B9C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800BA0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800BA4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80800BA8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800BAC: jal         0x80086590
    // 0x80800BB0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    _chlifeforcespell_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800BB0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_5:
    // 0x80800BB4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BB8: b           L_80800F14
    // 0x80800BBC: sw          $v0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r2;
        goto L_80800F14;
    // 0x80800BBC: sw          $v0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r2;
L_80800BC0:
    // 0x80800BC0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800BC4: jal         0x800EE7F8
    // 0x80800BC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800BC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_6:
    // 0x80800BCC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800BD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BD4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800BD8: addiu       $a0, $zero, 0x45B
    ctx->r4 = ADD32(0, 0X45B);
    // 0x80800BDC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800BE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800BE8: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80800BEC: jal         0x80108528
    // 0x80800BF0: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    func_80108528(rdram, ctx);
        goto after_7;
    // 0x80800BF0: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80800BF4: b           L_80800F18
    // 0x80800BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BFC:
    // 0x80800BFC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C04: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80800C08: jal         0x80108528
    // 0x80800C0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_8;
    // 0x80800C0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x80800C10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800C14: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80800C18: b           L_80800F14
    // 0x80800C1C: sw          $t9, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r25;
        goto L_80800F14;
    // 0x80800C1C: sw          $t9, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r25;
L_80800C20:
    // 0x80800C20: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800C24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800C28: jal         0x8008A0E0
    // 0x80800C2C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800C2C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x80800C30: beq         $v0, $zero, L_80800F14
    if (ctx->r2 == 0) {
        // 0x80800C34: addiu       $a0, $zero, 0x467
        ctx->r4 = ADD32(0, 0X467);
            goto L_80800F14;
    }
    // 0x80800C34: addiu       $a0, $zero, 0x467
    ctx->r4 = ADD32(0, 0X467);
    // 0x80800C38: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C40: jal         0x80108528
    // 0x80800C44: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_80108528(rdram, ctx);
        goto after_10;
    // 0x80800C44: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_10:
    // 0x80800C48: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80800C4C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80800C50: b           L_80800F14
    // 0x80800C54: sw          $t3, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r11;
        goto L_80800F14;
    // 0x80800C54: sw          $t3, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r11;
L_80800C58:
    // 0x80800C58: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800C5C: jal         0x80108B04
    // 0x80800C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800C64: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800C68: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800C6C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800C70: jal         0x80801D40
    // 0x80800C74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_12;
    // 0x80800C74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800C78: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800C7C: jal         0x80102424
    // 0x80800C80: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800C80: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_13:
    // 0x80800C84: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C8C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80800C90: b           L_80800F14
    // 0x80800C94: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
        goto L_80800F14;
    // 0x80800C94: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
L_80800C98:
    // 0x80800C98: b           L_80800F14
    // 0x80800C9C: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
        goto L_80800F14;
    // 0x80800C9C: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
L_80800CA0:
    // 0x80800CA0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800CA4: beq         $v0, $at, L_80800CC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800CA8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800CC8;
    }
    // 0x80800CA8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800CAC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80800CB0: beq         $v0, $at, L_80800D58
    if (ctx->r2 == ctx->r1) {
        // 0x80800CB4: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_80800D58;
    }
    // 0x80800CB4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80800CB8: beq         $v0, $at, L_80800D24
    if (ctx->r2 == ctx->r1) {
        // 0x80800CBC: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800D24;
    }
    // 0x80800CBC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800CC0: b           L_80800F18
    // 0x80800CC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F18;
    // 0x80800CC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CC8:
    // 0x80800CC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800CCC: jal         0x800EE88C
    // 0x80800CD0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE88C(rdram, ctx);
        goto after_14;
    // 0x80800CD0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_14:
    // 0x80800CD4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80800CD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2574) << 16);
    // 0x80800CDC: lwc1        $f8, 0x2574($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2574));
    // 0x80800CE0: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80800CE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800CE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800CEC: swc1        $f10, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f10.u32l;
    // 0x80800CF0: jal         0x80102424
    // 0x80800CF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800CF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_15:
    // 0x80800CF8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800CFC: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800D00: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x80800D04: jal         0x80801D40
    // 0x80800D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_16;
    // 0x80800D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x80800D0C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800D10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D14: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800D18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800D1C: b           L_80800F18
    // 0x80800D20: swc1        $f16, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f16.u32l;
        goto L_80800F18;
    // 0x80800D20: swc1        $f16, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f16.u32l;
L_80800D24:
    // 0x80800D24: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800D28: jal         0x800EE88C
    // 0x80800D2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE88C(rdram, ctx);
        goto after_17;
    // 0x80800D2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_17:
    // 0x80800D30: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800D34: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x80800D38: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800D3C: jal         0x80801D40
    // 0x80800D40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_18;
    // 0x80800D40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80800D44: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800D48: jal         0x80102424
    // 0x80800D4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x80800D4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x80800D50: b           L_80800F18
    // 0x80800D54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F18;
    // 0x80800D54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800D58:
    // 0x80800D58: jal         0x80801C60
    // 0x80800D5C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801C60_chaliendad(rdram, ctx);
        goto after_20;
    // 0x80800D5C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_20:
    // 0x80800D60: jal         0x80088840
    // 0x80800D64: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_21;
    // 0x80800D64: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_21:
    // 0x80800D68: beq         $v0, $zero, L_80800D78
    if (ctx->r2 == 0) {
        // 0x80800D6C: nop
    
            goto L_80800D78;
    }
    // 0x80800D6C: nop

    // 0x80800D70: jal         0x80088830
    // 0x80800D74: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_22;
    // 0x80800D74: nop

    after_22:
L_80800D78:
    // 0x80800D78: jal         0x800DA544
    // 0x80800D7C: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    func_800DA544(rdram, ctx);
        goto after_23;
    // 0x80800D7C: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    after_23:
    // 0x80800D80: b           L_80800F18
    // 0x80800D84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F18;
    // 0x80800D84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800D88: b           L_80800F18
    // 0x80800D8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F18;
    // 0x80800D8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800D90:
    // 0x80800D90: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x80800D94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D98: addiu       $a0, $t7, 0x4
    ctx->r4 = ADD32(ctx->r15, 0X4);
    // 0x80800D9C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800DA0: bne         $t9, $at, L_80800DEC
    if (ctx->r25 != ctx->r1) {
        // 0x80800DA4: nop
    
            goto L_80800DEC;
    }
    // 0x80800DA4: nop

    // 0x80800DA8: jal         0x800E39A8
    // 0x80800DAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800E39A8(rdram, ctx);
        goto after_24;
    // 0x80800DAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_24:
    // 0x80800DB0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800DB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800DB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800DBC: lui         $a3, 0xC47A
    ctx->r7 = S32(0XC47A << 16);
    // 0x80800DC0: jal         0x800EF214
    // 0x80800DC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EF214(rdram, ctx);
        goto after_25;
    // 0x80800DC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_25:
    // 0x80800DC8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800DCC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80800DD0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800DD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DD8: swc1        $f18, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f18.u32l;
    // 0x80800DDC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800DE0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80800DE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800DE8: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
L_80800DEC:
    // 0x80800DEC: b           L_80800F18
    // 0x80800DF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F18;
    // 0x80800DF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800DF4:
    // 0x80800DF4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80800DF8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1364, 0X25E4) << 16);
    // 0x80800DFC: addiu       $a0, $a0, 0x25E4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1364, 0X25E4));
    // 0x80800E00: jal         0x80088090
    // 0x80800E04: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800E04: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    after_26:
    // 0x80800E08: b           L_80800F18
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E10:
    // 0x80800E10: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800E14: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80800E18: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800E1C: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x80800E20: and         $t4, $a2, $at
    ctx->r12 = ctx->r6 & ctx->r1;
    // 0x80800E24: srl         $a2, $t4, 16
    ctx->r6 = S32(U32(ctx->r12) >> 16);
    // 0x80800E28: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80800E2C: jal         0x80801254
    // 0x80800E30: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801254_chaliendad(rdram, ctx);
        goto after_27;
    // 0x80800E30: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_27:
    // 0x80800E34: b           L_80800F1C
    // 0x80800E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F1C;
    // 0x80800E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E3C:
    // 0x80800E3C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800E40: addiu       $at, $zero, 0x45B
    ctx->r1 = ADD32(0, 0X45B);
    // 0x80800E44: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800E48: bne         $t6, $at, L_80800E90
    if (ctx->r14 != ctx->r1) {
        // 0x80800E4C: addiu       $a1, $zero, 0x1A
        ctx->r5 = ADD32(0, 0X1A);
            goto L_80800E90;
    }
    // 0x80800E4C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80800E50: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800E54: jal         0x80801D40
    // 0x80800E58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_28;
    // 0x80800E58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x80800E5C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80800E60: addiu       $t9, $zero, 0x62
    ctx->r25 = ADD32(0, 0X62);
    // 0x80800E64: addiu       $a1, $zero, 0x12AA
    ctx->r5 = ADD32(0, 0X12AA);
    // 0x80800E68: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800E6C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800E70: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800E74: jal         0x8008A208
    // 0x80800E78: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800E78: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    after_29:
    // 0x80800E7C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800E80: jal         0x80102424
    // 0x80800E84: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x80800E84: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_30:
    // 0x80800E88: b           L_80800F18
    // 0x80800E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E90:
    // 0x80800E90: jal         0x80801DD0
    // 0x80800E94: nop

    func_80801DD0_chaliendad(rdram, ctx);
        goto after_31;
    // 0x80800E94: nop

    after_31:
    // 0x80800E98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E9C: bne         $v0, $at, L_80800F14
    if (ctx->r2 != ctx->r1) {
        // 0x80800EA0: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800F14;
    }
    // 0x80800EA0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800EA4: jal         0x80108B04
    // 0x80800EA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_32;
    // 0x80800EA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80800EAC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800EB0: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x80800EB4: addiu       $a2, $zero, 0x2030
    ctx->r6 = ADD32(0, 0X2030);
    // 0x80800EB8: jal         0x80801D40
    // 0x80800EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_33;
    // 0x80800EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_33:
    // 0x80800EC0: b           L_80800F18
    // 0x80800EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EC8:
    // 0x80800EC8: jal         0x80801E28
    // 0x80800ECC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801E28_chaliendad(rdram, ctx);
        goto after_34;
    // 0x80800ECC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_34:
    // 0x80800ED0: b           L_80800F18
    // 0x80800ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ED8:
    // 0x80800ED8: jal         0x80801E80
    // 0x80800EDC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801E80_chaliendad(rdram, ctx);
        goto after_35;
    // 0x80800EDC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_35:
    // 0x80800EE0: b           L_80800F18
    // 0x80800EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE8:
    // 0x80800EE8: jal         0x80801C60
    // 0x80800EEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801C60_chaliendad(rdram, ctx);
        goto after_36;
    // 0x80800EEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_36:
    // 0x80800EF0: jal         0x800FFAB0
    // 0x80800EF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800FFAB0(rdram, ctx);
        goto after_37;
    // 0x80800EF4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_37:
    // 0x80800EF8: b           L_80800F18
    // 0x80800EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F18;
    // 0x80800EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F00:
    // 0x80800F00: jal         0x80801DD0
    // 0x80800F04: nop

    func_80801DD0_chaliendad(rdram, ctx);
        goto after_38;
    // 0x80800F04: nop

    after_38:
    // 0x80800F08: addiu       $t7, $zero, 0x12A9
    ctx->r15 = ADD32(0, 0X12A9);
    // 0x80800F0C: b           L_80800F18
    // 0x80800F10: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
        goto L_80800F18;
    // 0x80800F10: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
L_80800F14:
    // 0x80800F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F18:
    // 0x80800F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F1C:
    // 0x80800F1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800F20: jr          $ra
    // 0x80800F24: nop

    return;
    // 0x80800F24: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: jal         0x80106790
    // 0x808000C0: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808000C0: nop

    after_0:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: lw          $v0, 0x3C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3C);
    // 0x808000CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void _bsthrow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EF8: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083EF8);
    return;
    // 0x80083EFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808000EC_suexpressmorph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000F0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x808000F8: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x808000FC: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80800100: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80800104: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80800108: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8080010C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80800110: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80800114: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800118: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8080011C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800120: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800124: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80800128: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x8080012C: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x80800130: multu       $t6, $s7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800134: addiu       $s6, $s6, 0x1320
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800138: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8080013C: addiu       $s0, $a1, 0x8
    ctx->r16 = ADD32(ctx->r5, 0X8);
    // 0x80800140: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800144: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800148: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8080014C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800150: mflo        $t7
    ctx->r15 = lo;
    // 0x80800154: addu        $v0, $s6, $t7
    ctx->r2 = ADD32(ctx->r22, ctx->r15);
    // 0x80800158: lbu         $v1, 0x7($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X7);
    // 0x8080015C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80800160: addu        $s2, $t8, $a1
    ctx->r18 = ADD32(ctx->r24, ctx->r5);
    // 0x80800164: blez        $v1, L_80800280
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800168: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800280;
    }
    // 0x80800168: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8080016C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3170, 0X7D0) << 16);
    // 0x80800174: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80800178: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080017C: lwc1        $f20, 0x7D0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3170, 0X7D0));
    // 0x80800180: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
L_80800184:
    // 0x80800184: c.le.s      $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f4.fl <= ctx->f26.fl;
    // 0x80800188: nop

    // 0x8080018C: bc1f        L_808001BC
    if (!c1cs) {
        // 0x80800190: nop
    
            goto L_808001BC;
    }
    // 0x80800190: nop

    // 0x80800194: lbu         $t0, 0x5($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X5);
    // 0x80800198: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080019C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x808001A0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x808001A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808001A8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x808001AC: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x808001B0: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x808001B4: b           L_808001D0
    // 0x808001B8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_808001D0;
    // 0x808001B8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_808001BC:
    // 0x808001BC: jal         0x800D8FF8
    // 0x808001C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001C0: nop

    after_0:
    // 0x808001C4: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x808001C8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808001CC: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
L_808001D0:
    // 0x808001D0: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808001D4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808001D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808001DC: nop

    // 0x808001E0: bc1fl       L_80800218
    if (!c1cs) {
        // 0x808001E4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80800218;
    }
    goto skip_0;
    // 0x808001E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x808001E8: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808001EC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808001F0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808001F4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x808001F8: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x80800200: nop

    // 0x80800204: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800208: lh          $t4, 0x2($s5)
        ctx->r12 = MEM_H(ctx->r21, 0X2);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800208: lh          $t4, 0x2($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X2);
    skip_1:
    // 0x8080020C: b           L_8080024C
    // 0x80800210: swc1        $f22, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f22.u32l;
        goto L_8080024C;
    // 0x80800210: swc1        $f22, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f22.u32l;
    // 0x80800214: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80800218:
    // 0x80800218: nop

    // 0x8080021C: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800220: lh          $t4, 0x2($s5)
        ctx->r12 = MEM_H(ctx->r21, 0X2);
            goto L_80800250;
    }
    goto skip_2;
    // 0x80800220: lh          $t4, 0x2($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X2);
    skip_2:
    // 0x80800224: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800228: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8080022C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800230: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80800234: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800238: c.lt.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl < ctx->f18.fl;
    // 0x8080023C: nop

    // 0x80800240: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800244: lh          $t4, 0x2($s5)
        ctx->r12 = MEM_H(ctx->r21, 0X2);
            goto L_80800250;
    }
    goto skip_3;
    // 0x80800244: lh          $t4, 0x2($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X2);
    skip_3:
    // 0x80800248: swc1        $f24, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f24.u32l;
L_8080024C:
    // 0x8080024C: lh          $t4, 0x2($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X2);
L_80800250:
    // 0x80800250: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800254: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80800258: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080025C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800260: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800264: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800268: mflo        $t5
    ctx->r13 = lo;
    // 0x8080026C: addu        $v0, $s6, $t5
    ctx->r2 = ADD32(ctx->r22, ctx->r13);
    // 0x80800270: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x80800274: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800278: bnel        $at, $zero, L_80800184
    if (ctx->r1 != 0) {
        // 0x8080027C: lwc1        $f4, 0x0($s2)
        ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
            goto L_80800184;
    }
    goto skip_4;
    // 0x8080027C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    skip_4:
L_80800280:
    // 0x80800280: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800284: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800288: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080028C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800290: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800294: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80800298: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8080029C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A0: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x808002A4: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x808002A8: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x808002AC: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x808002B0: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _bsdronebitten_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083018: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083018);
    return;
    // 0x8008301C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800C1C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C24: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800C28: beq         $t6, $zero, L_80800C40
    if (ctx->r14 == 0) {
        // 0x80800C2C: nop
    
            goto L_80800C40;
    }
    // 0x80800C2C: nop

    // 0x80800C30: jal         0x80800B0C
    // 0x80800C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800B0C_bssub(rdram, ctx);
        goto after_0;
    // 0x80800C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C38: b           L_80800C48
    // 0x80800C3C: nop

        goto L_80800C48;
    // 0x80800C3C: nop

L_80800C40:
    // 0x80800C40: jal         0x80085240
    // 0x80800C44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800C44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
L_80800C48:
    // 0x80800C48: jal         0x808008D8
    // 0x80800C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_2;
    // 0x80800C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: nop

    return;
    // 0x80800C5C: nop

;}
RECOMP_FUNC void func_80104268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010426C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80104270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104274: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104278: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8010427C: addiu       $a0, $a0, 0x6E70
    ctx->r4 = ADD32(ctx->r4, 0X6E70);
    // 0x80104280: jal         0x800B3044
    // 0x80104284: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x80104284: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80104288: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8010428C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104290: jal         0x8008B518
    // 0x80104294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B518(rdram, ctx);
        goto after_1;
    // 0x80104294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80104298: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8010429C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801042A0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x801042A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801042A8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801042AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801042B0: jr          $ra
    // 0x801042B4: nop

    return;
    // 0x801042B4: nop

;}
RECOMP_FUNC void idflashbaddie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000D4: jal         0x80106520
    // 0x808000D8: addiu       $a0, $a2, -0x64
    ctx->r4 = ADD32(ctx->r6, -0X64);
    func_80106520(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a0, $a2, -0x64
    ctx->r4 = ADD32(ctx->r6, -0X64);
    after_0:
    // 0x808000DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800110;
    }
    // 0x808000E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E8: jal         0x80088D60
    // 0x808000EC: nop

    _idflasha_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000EC: nop

    after_1:
    // 0x808000F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2922, 0X140) << 16);
    // 0x808000F8: lwc1        $f8, 0x140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2922, 0X140));
    // 0x808000FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800100: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800108: b           L_8080011C
    // 0x8080010C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
        goto L_8080011C;
    // 0x8080010C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
L_80800110:
    // 0x80800110: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800114: nop

    // 0x80800118: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_8080011C:
    // 0x8080011C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800120: addiu       $a2, $a2, -0x7238
    ctx->r6 = ADD32(ctx->r6, -0X7238);
    // 0x80800124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: jal         0x80088660
    // 0x8080012C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080012C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_800FB540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB548: lbu         $t6, 0x33($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X33);
    // 0x800FB54C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FB550: bnel        $t6, $zero, L_800FB5B0
    if (ctx->r14 != 0) {
        // 0x800FB554: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FB5B0;
    }
    goto skip_0;
    // 0x800FB554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FB558: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    // 0x800FB55C: jal         0x800FED70
    // 0x800FB560: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FED70(rdram, ctx);
        goto after_0;
    // 0x800FB560: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FB564: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FB568: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FB56C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800FB570: sb          $t7, 0x33($a1)
    MEM_B(0X33, ctx->r5) = ctx->r15;
    // 0x800FB574: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800FB578: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800FB57C: addiu       $v1, $v1, 0x3DE0
    ctx->r3 = ADD32(ctx->r3, 0X3DE0);
    // 0x800FB580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FB584:
    // 0x800FB584: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800FB588: bnel        $a0, $t8, L_800FB5A4
    if (ctx->r4 != ctx->r24) {
        // 0x800FB58C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800FB5A4;
    }
    goto skip_1;
    // 0x800FB58C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800FB590: jal         0x800DA544
    // 0x800FB594: addiu       $a0, $v0, 0x53E
    ctx->r4 = ADD32(ctx->r2, 0X53E);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x800FB594: addiu       $a0, $v0, 0x53E
    ctx->r4 = ADD32(ctx->r2, 0X53E);
    after_1:
    // 0x800FB598: b           L_800FB5B0
    // 0x800FB59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FB5B0;
    // 0x800FB59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB5A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800FB5A4:
    // 0x800FB5A4: bne         $v0, $a1, L_800FB584
    if (ctx->r2 != ctx->r5) {
        // 0x800FB5A8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800FB584;
    }
    // 0x800FB5A8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800FB5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FB5B0:
    // 0x800FB5B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FB5B4: jr          $ra
    // 0x800FB5B8: nop

    return;
    // 0x800FB5B8: nop

;}
RECOMP_FUNC void func_808004C4_bskazjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004D4: jal         0x8008CABC
    // 0x808004D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808004E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004E8: beq         $v1, $at, L_80800504
    if (ctx->r3 == ctx->r1) {
        // 0x808004EC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800504;
    }
    // 0x808004EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004F4: beq         $v1, $at, L_8080051C
    if (ctx->r3 == ctx->r1) {
        // 0x808004F8: nop
    
            goto L_8080051C;
    }
    // 0x808004F8: nop

    // 0x808004FC: b           L_80800568
    // 0x80800500: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
        goto L_80800568;
    // 0x80800500: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800504:
    // 0x80800504: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800508: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080050C: jal         0x8008CB3C
    // 0x80800510: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800510: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    after_1:
    // 0x80800514: b           L_80800564
    // 0x80800518: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80800564;
    // 0x80800518: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8080051C:
    // 0x8080051C: jal         0x8008AF24
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800528: jal         0x8008AED4
    // 0x8080052C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x8080052C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_3:
    // 0x80800530: lui         $a1, 0x3F31
    ctx->r5 = S32(0X3F31 << 16);
    // 0x80800534: ori         $a1, $a1, 0x3405
    ctx->r5 = ctx->r5 | 0X3405;
    // 0x80800538: jal         0x8008B24C
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x8008B1BC
    // 0x80800548: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800548: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x8008B134
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800558: jal         0x8008B064
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800560: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800564:
    // 0x80800564: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800568:
    // 0x80800568: sw          $v1, 0x15C($t6)
    MEM_W(0X15C, ctx->r14) = ctx->r3;
    // 0x8080056C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800570: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800574: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_80800470_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800478: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080047C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800480: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800484: bnel        $t7, $at, L_80800498
    if (ctx->r15 != ctx->r1) {
        // 0x80800488: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800498;
    }
    goto skip_0;
    // 0x80800488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080048C: jal         0x808000E8
    // 0x80800490: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800498:
    // 0x80800498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void _badust_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A08: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A08);
    return;
    // 0x80084A0C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void boot_inflate_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000DDC: sw          $ra, 0xA44($sp)
    MEM_W(0XA44, ctx->r29) = ctx->r31;
    // 0x80000DE0: sw          $s6, 0xA74($sp)
    MEM_W(0XA74, ctx->r29) = ctx->r22;
    // 0x80000DE4: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x80000DE8: addiu       $s6, $s6, 0x6500
    ctx->r22 = ADD32(ctx->r22, 0X6500);
    // 0x80000DEC: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80000DF0: addiu       $a0, $a0, 0x6504
    ctx->r4 = ADD32(ctx->r4, 0X6504);
    // 0x80000DF4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80000DF8: addiu       $a1, $a1, 0x6EC8
    ctx->r5 = ADD32(ctx->r5, 0X6EC8);
    // 0x80000DFC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80000E00: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80000E04: jal         0x800012B0
    // 0x80000E08: nop

    boot_inflate_codes(rdram, ctx);
        goto after_0;
    // 0x80000E08: nop

    after_0:
    // 0x80000E0C: lw          $s6, 0xA74($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA74);
    // 0x80000E10: lw          $ra, 0xA44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA44);
    // 0x80000E14: jr          $ra
    // 0x80000E18: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x80000E18: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void subaddiefade_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808003D4: jal         0x800EFA88
    // 0x808003D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFA88(rdram, ctx);
        goto after_0;
    // 0x808003D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808003DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003E0: jal         0x80800370
    // 0x808003E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    subaddiefade_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808003E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808003E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void _bareact_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F80: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F80);
    return;
    // 0x80084F84: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chtalontorpedoboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086758: syscall     365
    recomp_syscall_handler(rdram, ctx, 0x80086758);
    return;
    // 0x8008675C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chfaircoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800D9078
    // 0x80800014: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x80800018: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080001C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800020: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800024: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800028: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080002C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800030: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800034: jal         0x800F10B4
    // 0x80800038: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800038: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080003C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800040: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800044: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800048: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x8080004C: jal         0x800EFE50
    // 0x80800050: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800054: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2128, 0X140) << 16);
    // 0x80800058: lwc1        $f8, 0x140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2128, 0X140));
    // 0x8080005C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800060: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800064: jal         0x8001395C
    // 0x80800068: nop

    func_8001395C(rdram, ctx);
        goto after_3;
    // 0x80800068: nop

    after_3:
    // 0x8080006C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800070: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800074: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800078: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080007C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800080: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800084: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80800088: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080008C: bc1f        L_808000A4
    if (!c1cs) {
        // 0x80800090: swc1        $f4, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
            goto L_808000A4;
    }
    // 0x80800090: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80800094: jal         0x800FFAB0
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080009C: jal         0x800FC660
    // 0x808000A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x808000A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_5:
L_808000A4:
    // 0x808000A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E90: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E90);
    return;
    // 0x80089E94: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800C6704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6704: jr          $ra
    // 0x800C6708: lbu         $v0, 0x8E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8E);
    return;
    // 0x800C6708: lbu         $v0, 0x8E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8E);
;}
RECOMP_FUNC void func_808005E0_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005F0: jal         0x800B53A4
    // 0x808005F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808005F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808005F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800604: jal         0x800BA3FC
    // 0x80800608: addiu       $a1, $a1, 0x9DF
    ctx->r5 = ADD32(ctx->r5, 0X9DF);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a1, $a1, 0x9DF
    ctx->r5 = ADD32(ctx->r5, 0X9DF);
    after_1:
    // 0x8080060C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2360, 0XFD0) << 16);
    // 0x80800610: addiu       $t6, $t6, 0xFD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2360, 0XFD0));
    // 0x80800614: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800618: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080061C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800624: jal         0x800BABB8
    // 0x80800628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8080062C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800634: jr          $ra
    // 0x80800638: nop

    return;
    // 0x80800638: nop

;}
RECOMP_FUNC void func_80800504_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080050C: jal         0x808001A8
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800518: jal         0x800A0CF4
    // 0x8080051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x8080051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800524: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800528: jal         0x8009E55C
    // 0x8080052C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_2;
    // 0x8080052C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_80800650_chwallsnakebaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800658: jal         0x80105010
    // 0x8080065C: nop

    func_80105010(rdram, ctx);
        goto after_0;
    // 0x8080065C: nop

    after_0:
    // 0x80800660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800668: jr          $ra
    // 0x8080066C: nop

    return;
    // 0x8080066C: nop

;}
RECOMP_FUNC void func_80105CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105CD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80105CD4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80105CD8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80105CDC: addiu       $s4, $s4, 0x6ED0
    ctx->r20 = ADD32(ctx->r20, 0X6ED0);
    // 0x80105CE0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80105CE4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80105CE8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80105CEC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80105CF0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80105CF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80105CF8: beq         $a0, $zero, L_80105DD8
    if (ctx->r4 == 0) {
        // 0x80105CFC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80105DD8;
    }
    // 0x80105CFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80105D00: jal         0x800B3034
    // 0x80105D04: nop

    freelist_capacity(rdram, ctx);
        goto after_0;
    // 0x80105D04: nop

    after_0:
    // 0x80105D08: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80105D0C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80105D10: bne         $at, $zero, L_80105DC8
    if (ctx->r1 != 0) {
        // 0x80105D14: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_80105DC8;
    }
    // 0x80105D14: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80105D18: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80105D1C: addiu       $s2, $s2, 0x4440
    ctx->r18 = ADD32(ctx->r18, 0X4440);
    // 0x80105D20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
L_80105D24:
    // 0x80105D24: jal         0x800B31B8
    // 0x80105D28: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_1;
    // 0x80105D28: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80105D2C: beq         $v0, $zero, L_80105DB8
    if (ctx->r2 == 0) {
        // 0x80105D30: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80105DB8;
    }
    // 0x80105D30: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80105D34: jal         0x800B301C
    // 0x80105D38: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    freelist_at(rdram, ctx);
        goto after_2;
    // 0x80105D38: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_2:
    // 0x80105D3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80105D40: jal         0x8001BAFC
    // 0x80105D44: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    defrag(rdram, ctx);
        goto after_3;
    // 0x80105D44: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_3:
    // 0x80105D48: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80105D4C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80105D50: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80105D54: jal         0x801063EC
    // 0x80105D58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_801063EC(rdram, ctx);
        goto after_4;
    // 0x80105D58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80105D5C: jal         0x800B2F58
    // 0x80105D60: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    vector_defrag(rdram, ctx);
        goto after_5;
    // 0x80105D60: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x80105D64: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80105D68: jal         0x800B296C
    // 0x80105D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    vector_end(rdram, ctx);
        goto after_6;
    // 0x80105D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80105D70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80105D74: jal         0x800B28C4
    // 0x80105D78: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    vector_begin(rdram, ctx);
        goto after_7;
    // 0x80105D78: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x80105D7C: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80105D80: beq         $at, $zero, L_80105DB8
    if (ctx->r1 == 0) {
        // 0x80105D84: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80105DB8;
    }
    // 0x80105D84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80105D88: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
L_80105D8C:
    // 0x80105D8C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80105D90: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80105D94: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x80105D98: beql        $v0, $zero, L_80105DAC
    if (ctx->r2 == 0) {
        // 0x80105D9C: addiu       $s0, $s0, 0xA8
        ctx->r16 = ADD32(ctx->r16, 0XA8);
            goto L_80105DAC;
    }
    goto skip_0;
    // 0x80105D9C: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    skip_0:
    // 0x80105DA0: jalr        $v0
    // 0x80105DA4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80105DA4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_8:
    // 0x80105DA8: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
L_80105DAC:
    // 0x80105DAC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80105DB0: bnel        $at, $zero, L_80105D8C
    if (ctx->r1 != 0) {
        // 0x80105DB4: lh          $t7, 0x4($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X4);
            goto L_80105D8C;
    }
    goto skip_1;
    // 0x80105DB4: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    skip_1:
L_80105DB8:
    // 0x80105DB8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80105DBC: slt         $at, $s3, $s5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80105DC0: bnel        $at, $zero, L_80105D24
    if (ctx->r1 != 0) {
        // 0x80105DC4: lw          $a0, 0x0($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X0);
            goto L_80105D24;
    }
    goto skip_2;
    // 0x80105DC4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    skip_2:
L_80105DC8:
    // 0x80105DC8: jal         0x800B32E4
    // 0x80105DCC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    freelist_defrag(rdram, ctx);
        goto after_9;
    // 0x80105DCC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_9:
    // 0x80105DD0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80105DD4: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
L_80105DD8:
    // 0x80105DD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80105DDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80105DE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80105DE4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80105DE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80105DEC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80105DF0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80105DF4: jr          $ra
    // 0x80105DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80105DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chnicecavemen_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086118: syscall     279
    recomp_syscall_handler(rdram, ctx, 0x80086118);
    return;
    // 0x8008611C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80109600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109600: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80109604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109608: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010960C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80109610: jal         0x80103DFC
    // 0x80109614: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80103DFC(rdram, ctx);
        goto after_0;
    // 0x80109614: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80109618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8010961C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80109620: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80109624: jal         0x80109538
    // 0x80109628: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80109538(rdram, ctx);
        goto after_1;
    // 0x80109628: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8010962C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80109634: jr          $ra
    // 0x80109638: nop

    return;
    // 0x80109638: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800360: jal         0x808002F8
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_808002F8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800368: bne         $v0, $zero, L_80800378
    if (ctx->r2 != 0) {
        // 0x8080036C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800378;
    }
    // 0x8080036C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800370: b           L_80800394
    // 0x80800374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800394;
    // 0x80800374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800378:
    // 0x80800378: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080037C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800384: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80800388: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080038C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800390: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
L_80800394:
    // 0x80800394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080039C: jr          $ra
    // 0x808003A0: nop

    return;
    // 0x808003A0: nop

;}
RECOMP_FUNC void func_808008D8_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808008E4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808008E8: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808008EC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808008F0: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x808008F4: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x808008F8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x808008FC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800900: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800904: jal         0x800EFA4C
    // 0x80800908: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800908: nop

    after_0:
    // 0x8080090C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800914: jr          $ra
    // 0x80800918: nop

    return;
    // 0x80800918: nop

;}
RECOMP_FUNC void func_8009B1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B1FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B204: jal         0x800D8FF8
    // 0x8009B208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009B208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009B20C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009B210: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B214: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8009B218: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B21C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009B220: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8009B224: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8009B228: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B22C: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B230: lwc1        $f12, 0x38($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8009B234: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8009B238: nop

    // 0x8009B23C: bc1f        L_8009B250
    if (!c1cs) {
        // 0x8009B240: nop
    
            goto L_8009B250;
    }
    // 0x8009B240: nop

    // 0x8009B244: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x8009B248: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B24C: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
L_8009B250:
    // 0x8009B250: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009B254: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    // 0x8009B258: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B25C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009B260: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8009B264: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8009B268: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8009B26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B274: jr          $ra
    // 0x8009B278: nop

    return;
    // 0x8009B278: nop

;}
RECOMP_FUNC void _baduo_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084950: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084950);
    return;
    // 0x80084954: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800B2840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2840: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800B2844: jr          $ra
    // 0x800B2848: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800B2848: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void func_80800080_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800084: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: jal         0x80100094
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800098: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8080009C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x808000A0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808000A4: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808000A8: bltzl       $t8, L_808005C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x808000AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005C0;
    }
    goto skip_0;
    // 0x808000AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000B0: jal         0x8010D254
    // 0x808000B4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x808000B4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000B8: jal         0x801072A8
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C0: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000C4: nop
    
            goto L_808000D8;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x801072E4
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072E4(rdram, ctx);
        goto after_3;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D0: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000D4: nop
    
            goto L_808000E0;
    }
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: jal         0x8010D690
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010D690(rdram, ctx);
        goto after_4;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808000E0:
    // 0x808000E0: jal         0x800D90A4
    // 0x808000E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x808000E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x808000E8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808000EC: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808000F0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000F4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808000F8: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x808000FC: beq         $at, $zero, L_808005BC
    if (ctx->r1 == 0) {
        // 0x80800100: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808005BC;
    }
    // 0x80800100: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800104: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC60) << 16);
    // 0x80800108: addu        $at, $at, $t1
    gpr jr_addend_80800110 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8080010C: lw          $t1, 0xC60($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC60));
    // 0x80800110: jr          $t1
    // 0x80800114: nop

    switch (jr_addend_80800110 >> 2) {
        case 0: goto L_80800118; break;
        case 1: goto L_8080023C; break;
        case 2: goto L_80800254; break;
        case 3: goto L_8080027C; break;
        case 4: goto L_808004BC; break;
        case 5: goto L_80800500; break;
        case 6: goto L_80800540; break;
        case 7: goto L_808005A0; break;
        default: switch_error(__func__, 0x80800110, 0x80800C60);
    }
    // 0x80800114: nop

L_80800118:
    // 0x80800118: jal         0x800D8FF8
    // 0x8080011C: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x8080011C: nop

    after_6:
    // 0x80800120: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800128: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080012C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800130: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800134: ori         $a1, $a1, 0x27
    ctx->r5 = ctx->r5 | 0X27;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800140: jal         0x8010B990
    // 0x80800144: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    func_8010B990(rdram, ctx);
        goto after_7;
    // 0x80800144: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x80800148: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080014C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800150: jal         0x800BFA1C
    // 0x80800154: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800BFA1C(rdram, ctx);
        goto after_8;
    // 0x80800154: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_8:
    // 0x80800158: bne         $v0, $zero, L_80800170
    if (ctx->r2 != 0) {
        // 0x8080015C: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80800170;
    }
    // 0x8080015C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80800160: jal         0x800FFAB0
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800168: b           L_808005C0
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800170:
    // 0x80800170: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80800174: beql        $t3, $zero, L_808005C0
    if (ctx->r11 == 0) {
        // 0x80800178: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005C0;
    }
    goto skip_1;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080017C: jal         0x8010AA54
    // 0x80800180: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_8010AA54(rdram, ctx);
        goto after_10;
    // 0x80800180: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x80800184: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800188: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080018C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800190: jal         0x800EFDE8
    // 0x80800194: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EFDE8(rdram, ctx);
        goto after_11;
    // 0x80800194: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_11:
    // 0x80800198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC80) << 16);
    // 0x8080019C: lwc1        $f0, 0xC80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC80));
    // 0x808001A0: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808001A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC84) << 16);
    // 0x808001AC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808001B0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808001B4: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808001B8: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x808001BC: lwc1        $f4, 0xC84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC84));
    // 0x808001C0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x808001C4: nop

    // 0x808001C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808001CC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x808001D0: jal         0x800EEFFC
    // 0x808001D4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    func_800EEFFC(rdram, ctx);
        goto after_12;
    // 0x808001D4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    after_12:
    // 0x808001D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808001DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x808001E8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808001EC: nop

    // 0x808001F0: bc1f        L_80800214
    if (!c1cs) {
        // 0x808001F4: nop
    
            goto L_80800214;
    }
    // 0x808001F4: nop

    // 0x808001F8: jal         0x8010B990
    // 0x808001FC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_8010B990(rdram, ctx);
        goto after_13;
    // 0x808001FC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_13:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8080092C
    // 0x80800208: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_14;
    // 0x80800208: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x8080020C: b           L_808005C0
    // 0x80800210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x80800210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800214:
    // 0x80800214: beq         $t4, $zero, L_808005BC
    if (ctx->r12 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XF00) << 16);
    // 0x80800220: addiu       $a2, $a2, 0xF00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XF00));
    // 0x80800224: jal         0x80089D18
    // 0x80800228: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800228: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x8080022C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC88) << 16);
    // 0x80800230: lwc1        $f6, 0xC88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC88));
    // 0x80800234: b           L_808005BC
    // 0x80800238: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005BC;
    // 0x80800238: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080023C:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800244: jal         0x80800A88
    // 0x80800248: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800A88_chnutsnbolts(rdram, ctx);
        goto after_16;
    // 0x80800248: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_16:
    // 0x8080024C: b           L_808005C0
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800254:
    // 0x80800254: jal         0x80800B80
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B80_chnutsnbolts(rdram, ctx);
        goto after_17;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080025C: jal         0x80101DDC
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_18;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800264: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x8080092C
    // 0x80800270: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_19;
    // 0x80800270: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x80800274: b           L_808005C0
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080027C:
    // 0x8080027C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800288: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8080028C: bgez        $t7, L_80800308
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800290: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_80800308;
    }
    // 0x80800290: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800294: jal         0x80089BF0
    // 0x80800298: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_20;
    // 0x80800298: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_20:
    // 0x8080029C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808002A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808002A4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808002A8: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x808002AC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x808002B8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x808002BC: jal         0x80102BF8
    // 0x808002C0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_80102BF8(rdram, ctx);
        goto after_21;
    // 0x808002C0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_21:
    // 0x808002C4: jal         0x80101F24
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_22;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808002CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1304, 0XF14) << 16);
    // 0x808002D0: addiu       $a1, $a1, 0xF14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1304, 0XF14));
    // 0x808002D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808002D8: jal         0x800F3780
    // 0x808002DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_23;
    // 0x808002DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_23:
    // 0x808002E0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808002E4: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808002E8: ori         $a1, $a1, 0x5025
    ctx->r5 = ctx->r5 | 0X5025;
    // 0x808002EC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808002F8: jal         0x8010C3A8
    // 0x808002FC: nop

    func_8010C3A8(rdram, ctx);
        goto after_24;
    // 0x808002FC: nop

    after_24:
    // 0x80800300: b           L_808004AC
    // 0x80800304: nop

        goto L_808004AC;
    // 0x80800304: nop

L_80800308:
    // 0x80800308: lbu         $t0, 0x16($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X16);
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: bne         $t0, $zero, L_808003A8
    if (ctx->r8 != 0) {
        // 0x80800314: nop
    
            goto L_808003A8;
    }
    // 0x80800314: nop

    // 0x80800318: jal         0x80089F78
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800320: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800324: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x80102D78
    // 0x8080032C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102D78(rdram, ctx);
        goto after_26;
    // 0x8080032C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_26:
    // 0x80800330: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800334: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800338: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080033C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800340: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800344: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800348: addiu       $t1, $zero, 0x5800
    ctx->r9 = ADD32(0, 0X5800);
    // 0x8080034C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800358: jal         0x80089F90
    // 0x8080035C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_27;
    // 0x8080035C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_27:
    // 0x80800360: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800364: lhu         $t3, 0xE($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XE);
    // 0x80800368: sh          $t3, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r11;
L_8080036C:
    // 0x8080036C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800370: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800374: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80800378: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080037C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800380: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800384: lh          $a2, 0x14($t4)
    ctx->r6 = MEM_H(ctx->r12, 0X14);
    // 0x80800388: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800394: addiu       $a1, $t4, 0x8
    ctx->r5 = ADD32(ctx->r12, 0X8);
    // 0x80800398: jal         0x80089F80
    // 0x8080039C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_28;
    // 0x8080039C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x808003A0: b           L_808003CC
    // 0x808003A4: nop

        goto L_808003CC;
    // 0x808003A4: nop

L_808003A8:
    // 0x808003A8: jal         0x80102D78
    // 0x808003AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102D78(rdram, ctx);
        goto after_29;
    // 0x808003AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_29:
    // 0x808003B0: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x808003B4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808003B8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x808003C4: jal         0x80102BF8
    // 0x808003C8: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_80102BF8(rdram, ctx);
        goto after_30;
    // 0x808003C8: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_30:
L_808003CC:
    // 0x808003CC: jal         0x800D8FF8
    // 0x808003D0: nop

    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x808003D0: nop

    after_31:
    // 0x808003D4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808003D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003DC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x808003E0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003E4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003E8: lwc1        $f14, 0x1C($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x808003EC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808003F0: jal         0x800F15F8
    // 0x808003F4: nop

    func_800F15F8(rdram, ctx);
        goto after_32;
    // 0x808003F4: nop

    after_32:
    // 0x808003F8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808003FC: jal         0x80101F24
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_33;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800404: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1304, 0XF14) << 16);
    // 0x80800408: addiu       $a1, $a1, 0xF14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1304, 0XF14));
    // 0x8080040C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800410: jal         0x800F3780
    // 0x80800414: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_34;
    // 0x80800414: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_34:
    // 0x80800418: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x8080041C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800420: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x80800424: jal         0x8010C3A8
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_35;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x8080042C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800430: lbu         $t7, 0x16($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X16);
    // 0x80800434: bne         $t7, $zero, L_8080048C
    if (ctx->r15 != 0) {
        // 0x80800438: nop
    
            goto L_8080048C;
    }
    // 0x80800438: nop

    // 0x8080043C: jal         0x80089F78
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800444: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x80800448: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1304, 0XC8C) << 16);
            goto L_808004AC;
    }
    // 0x80800448: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC8C) << 16);
    // 0x8080044C: jal         0x800DC298
    // 0x80800450: lwc1        $f12, 0xC8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC8C));
    func_800DC298(rdram, ctx);
        goto after_37;
    // 0x80800450: lwc1        $f12, 0xC8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC8C));
    after_37:
    // 0x80800454: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x80800458: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808004AC;
    }
    // 0x80800458: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080045C: jal         0x8010C9B0
    // 0x80800460: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_38;
    // 0x80800460: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_38:
    // 0x80800464: beql        $v0, $zero, L_8080047C
    if (ctx->r2 == 0) {
        // 0x80800468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080047C;
    }
    goto skip_2;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8080046C: jal         0x8010C500
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_39;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800474: bne         $v0, $zero, L_808004AC
    if (ctx->r2 != 0) {
        // 0x80800478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004AC;
    }
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080047C:
    // 0x8080047C: jal         0x8080092C
    // 0x80800480: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_40;
    // 0x80800480: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_40:
    // 0x80800484: b           L_808004AC
    // 0x80800488: nop

        goto L_808004AC;
    // 0x80800488: nop

L_8080048C:
    // 0x8080048C: jal         0x800F54E4
    // 0x80800490: nop

    func_800F54E4(rdram, ctx);
        goto after_41;
    // 0x80800490: nop

    after_41:
    // 0x80800494: jal         0x800F6478
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_42;
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_42:
    // 0x8080049C: bne         $v0, $zero, L_808004AC
    if (ctx->r2 != 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004AC;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x8080092C
    // 0x808004A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_43;
    // 0x808004A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_43:
L_808004AC:
    // 0x808004AC: jal         0x80800BD4
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BD4_chnutsnbolts(rdram, ctx);
        goto after_44;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808004B4: b           L_808005C0
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004BC:
    // 0x808004BC: jal         0x80800BD4
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BD4_chnutsnbolts(rdram, ctx);
        goto after_45;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x808004C4: jal         0x800F54E4
    // 0x808004C8: nop

    func_800F54E4(rdram, ctx);
        goto after_46;
    // 0x808004C8: nop

    after_46:
    // 0x808004CC: jal         0x800F6478
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_47;
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_47:
    // 0x808004D4: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x808004D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004E0: jal         0x80800A88
    // 0x808004E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800A88_chnutsnbolts(rdram, ctx);
        goto after_48;
    // 0x808004E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_48:
    // 0x808004E8: bne         $v0, $zero, L_808005BC
    if (ctx->r2 != 0) {
        // 0x808004EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: jal         0x8080092C
    // 0x808004F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_49;
    // 0x808004F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_49:
    // 0x808004F8: b           L_808005C0
    // 0x808004FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x808004FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800500:
    // 0x80800500: jal         0x80800C04
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C04_chnutsnbolts(rdram, ctx);
        goto after_50;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80800508: jal         0x80101DDC
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_51;
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800510: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x80800514: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x8080092C
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_52;
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_52:
    // 0x80800520: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800524: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800528: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080052C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800530: jal         0x800DC178
    // 0x80800534: nop

    func_800DC178(rdram, ctx);
        goto after_53;
    // 0x80800534: nop

    after_53:
    // 0x80800538: b           L_808005BC
    // 0x8080053C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808005BC;
    // 0x8080053C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800540:
    // 0x80800540: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: lbu         $t8, 0x16($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X16);
    // 0x8080054C: bne         $t8, $zero, L_80800560
    if (ctx->r24 != 0) {
        // 0x80800550: nop
    
            goto L_80800560;
    }
    // 0x80800550: nop

    // 0x80800554: jal         0x8008A050
    // 0x80800558: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddiefx_entrypoint_0(rdram, ctx);
        goto after_54;
    // 0x80800558: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_54:
    // 0x8080055C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
L_80800560:
    // 0x80800560: jal         0x800D9078
    // 0x80800564: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    func_800D9078(rdram, ctx);
        goto after_55;
    // 0x80800564: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    after_55:
    // 0x80800568: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x8080056C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x8008A058
    // 0x80800574: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_56;
    // 0x80800574: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_56:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800580: jal         0x80800A88
    // 0x80800584: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800A88_chnutsnbolts(rdram, ctx);
        goto after_57;
    // 0x80800584: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_57:
    // 0x80800588: bne         $v0, $zero, L_808005BC
    if (ctx->r2 != 0) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x8080092C
    // 0x80800594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_58;
    // 0x80800594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_58:
    // 0x80800598: b           L_808005C0
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005C0;
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005A0:
    // 0x808005A0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: lbu         $t9, 0x16($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X16);
    // 0x808005AC: bnel        $t9, $zero, L_808005C0
    if (ctx->r25 != 0) {
        // 0x808005B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005C0;
    }
    goto skip_3;
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808005B4: jal         0x8008A050
    // 0x808005B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddiefx_entrypoint_0(rdram, ctx);
        goto after_59;
    // 0x808005B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_59:
L_808005BC:
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005C0:
    // 0x808005C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_800EF3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF3DC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF3E0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF3E4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF3E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF3EC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF3F0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800EF3F4: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF3F8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EF3FC: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800EF400: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF404: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF408: jr          $ra
    // 0x800EF40C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EF40C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800BC8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC8A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8A4: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, -0X7D20);
    // 0x800BC8A8: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x800BC8AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC8B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC8B4: beql        $t6, $zero, L_800BC8EC
    if (ctx->r14 == 0) {
        // 0x800BC8B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BC8EC;
    }
    goto skip_0;
    // 0x800BC8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BC8BC: jal         0x8001B084
    // 0x800BC8C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800BC8C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x800BC8C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8C8: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, -0X7D20);
    // 0x800BC8CC: jal         0x8001B084
    // 0x800BC8D0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800BC8D0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x800BC8D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8D8: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, -0X7D20);
    // 0x800BC8DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BC8E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800BC8E4: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800BC8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC8EC:
    // 0x800BC8EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC8F0: jr          $ra
    // 0x800BC8F4: nop

    return;
    // 0x800BC8F4: nop

;}
RECOMP_FUNC void func_80801C0C_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801C10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801C14: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80801C18: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80801C1C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801C20: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801C24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801C28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801C2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801C30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801C34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801C38: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801C3C: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80801C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801C44: lwc1        $f0, 0x1DC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1DC);
    // 0x80801C48: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80801C4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801C50: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801C54: lw          $t8, 0x1E4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1E4);
    // 0x80801C58: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801C60: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80801C64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80801C68: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80801C6C: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x80801C70: addiu       $s5, $zero, 0xFD
    ctx->r21 = ADD32(0, 0XFD);
    // 0x80801C74: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80801C78: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80801C7C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801C80: mfc1        $s7, $f18
    ctx->r23 = (int32_t)ctx->f18.u32l;
    // 0x80801C84: bgezl       $t0, L_80801C98
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801C88: lh          $t3, 0x1E6($t1)
        ctx->r11 = MEM_H(ctx->r9, 0X1E6);
            goto L_80801C98;
    }
    goto skip_0;
    // 0x80801C88: lh          $t3, 0x1E6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X1E6);
    skip_0:
    // 0x80801C8C: b           L_80801CB0
    // 0x80801C90: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
        goto L_80801CB0;
    // 0x80801C90: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80801C94: lh          $t3, 0x1E6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X1E6);
L_80801C98:
    // 0x80801C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801C9C: bgez        $t3, L_80801CAC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80801CA0: nop
    
            goto L_80801CAC;
    }
    // 0x80801CA0: nop

    // 0x80801CA4: b           L_80801CAC
    // 0x80801CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CAC;
    // 0x80801CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CAC:
    // 0x80801CAC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_80801CB0:
    // 0x80801CB0: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80801CB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801CB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801CBC: beq         $t5, $zero, L_80801D44
    if (ctx->r13 == 0) {
        // 0x80801CC0: nop
    
            goto L_80801D44;
    }
    // 0x80801CC0: nop

    // 0x80801CC4: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
L_80801CC8:
    // 0x80801CC8: bne         $s5, $a0, L_80801CDC
    if (ctx->r21 != ctx->r4) {
        // 0x80801CCC: nop
    
            goto L_80801CDC;
    }
    // 0x80801CCC: nop

    // 0x80801CD0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801CD4: b           L_80801D30
    // 0x80801CD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80801D30;
    // 0x80801CD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801CDC:
    // 0x80801CDC: jal         0x80800E24
    // 0x80801CE0: nop

    func_80800E24_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80801CE0: nop

    after_0:
    // 0x80801CE4: beq         $v0, $zero, L_80801CF4
    if (ctx->r2 == 0) {
        // 0x80801CE8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80801CF4;
    }
    // 0x80801CE8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801CEC: b           L_80801D00
    // 0x80801CF0: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
        goto L_80801D00;
    // 0x80801CF0: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
L_80801CF4:
    // 0x80801CF4: jal         0x800D36C4
    // 0x80801CF8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    func_800D36C4(rdram, ctx);
        goto after_1;
    // 0x80801CF8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    after_1:
    // 0x80801CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80801D00:
    // 0x80801D00: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // 0x80801D04: slt         $at, $s7, $s2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80801D08: beql        $at, $zero, L_80801D34
    if (ctx->r1 == 0) {
        // 0x80801D0C: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80801D34;
    }
    goto skip_1;
    // 0x80801D0C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_1:
    // 0x80801D10: bnel        $s4, $zero, L_80801D20
    if (ctx->r20 != 0) {
        // 0x80801D14: lbu         $t7, 0x0($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X0);
            goto L_80801D20;
    }
    goto skip_2;
    // 0x80801D14: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    skip_2:
    // 0x80801D18: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x80801D1C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
L_80801D20:
    // 0x80801D20: bnel        $s3, $t7, L_80801D34
    if (ctx->r19 != ctx->r15) {
        // 0x80801D24: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80801D34;
    }
    goto skip_3;
    // 0x80801D24: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_3:
    // 0x80801D28: b           L_80801D44
    // 0x80801D2C: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
        goto L_80801D44;
    // 0x80801D2C: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
L_80801D30:
    // 0x80801D30: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_80801D34:
    // 0x80801D34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801D38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801D3C: bne         $a0, $zero, L_80801CC8
    if (ctx->r4 != 0) {
        // 0x80801D40: nop
    
            goto L_80801CC8;
    }
    // 0x80801D40: nop

L_80801D44:
    // 0x80801D44: beq         $s4, $zero, L_80801DC4
    if (ctx->r20 == 0) {
        // 0x80801D48: addiu       $s3, $zero, 0x20
        ctx->r19 = ADD32(0, 0X20);
            goto L_80801DC4;
    }
    // 0x80801D48: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x80801D4C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80801D50: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D58: lwc1        $f10, 0x1DC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1DC);
    // 0x80801D5C: subu        $t6, $s2, $s7
    ctx->r14 = SUB32(ctx->r18, ctx->r23);
    // 0x80801D60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80801D64: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80801D68: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801D6C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80801D70: nop

    // 0x80801D74: bc1tl       L_80801DC8
    if (c1cs) {
        // 0x80801D78: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801DC8;
    }
    goto skip_4;
    // 0x80801D78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80801D7C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80801D80: blez        $s1, L_80801DB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80801D84: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_80801DB0;
    }
    // 0x80801D84: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80801D88: addu        $s0, $t9, $s1
    ctx->r16 = ADD32(ctx->r25, ctx->r17);
    // 0x80801D8C: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x80801D90: beq         $s3, $t0, L_80801DB0
    if (ctx->r19 == ctx->r8) {
        // 0x80801D94: nop
    
            goto L_80801DB0;
    }
    // 0x80801D94: nop

    // 0x80801D98: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80801D9C:
    // 0x80801D9C: blez        $s1, L_80801DB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80801DA0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80801DB0;
    }
    // 0x80801DA0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80801DA4: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80801DA8: bnel        $s3, $t1, L_80801D9C
    if (ctx->r19 != ctx->r9) {
        // 0x80801DAC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80801D9C;
    }
    goto skip_5;
    // 0x80801DAC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_5:
L_80801DB0:
    // 0x80801DB0: bnel        $s1, $zero, L_80801DC8
    if (ctx->r17 != 0) {
        // 0x80801DB4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801DC8;
    }
    goto skip_6;
    // 0x80801DB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x80801DB8: jal         0x80800694
    // 0x80801DBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    gczoombox_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801DBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80801DC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801DC4:
    // 0x80801DC4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801DC8:
    // 0x80801DC8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80801DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801DD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801DD4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DD8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801DDC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801DE0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801DE4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80801DE8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80801DEC: jr          $ra
    // 0x80801DF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801DF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
