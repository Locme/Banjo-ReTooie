#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800D3C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D44: jal         0x80106790
    // 0x80800D48: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800D48: nop

    after_0:
    // 0x80800D4C: lhu         $v0, 0x72($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X72);
    // 0x80800D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D58: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800D5C: xori        $t7, $t6, 0x9
    ctx->r15 = ctx->r14 ^ 0X9;
    // 0x80800D60: jr          $ra
    // 0x80800D64: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
    return;
    // 0x80800D64: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
;}
RECOMP_FUNC void _chanim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085988: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x80085988);
    return;
    // 0x8008598C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chintrochar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E8C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X532C) << 16);
    // 0x80803E90: jr          $ra
    // 0x80803E94: addiu       $v0, $v0, 0x532C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X532C));
    return;
    // 0x80803E94: addiu       $v0, $v0, 0x532C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X532C));
;}
RECOMP_FUNC void func_80800F24_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F28: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F34: beq         $a1, $at, L_80800F88
    if (ctx->r5 == ctx->r1) {
        // 0x80800F38: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800F88;
    }
    // 0x80800F38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800F3C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800F40: bne         $a1, $at, L_80800FB0
    if (ctx->r5 != ctx->r1) {
        // 0x80800F44: nop
    
            goto L_80800FB0;
    }
    // 0x80800F44: nop

    // 0x80800F48: jal         0x80800FCC
    // 0x80800F4C: nop

    func_80800FCC_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800F4C: nop

    after_0:
    // 0x80800F50: jal         0x800DA298
    // 0x80800F54: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800F54: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    after_1:
    // 0x80800F58: beq         $v0, $zero, L_80800FB8
    if (ctx->r2 == 0) {
        // 0x80800F5C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FB8;
    }
    // 0x80800F5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F60: jal         0x80101FDC
    // 0x80800F64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800F64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800F68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1192, 0X1090) << 16);
    // 0x80800F6C: lwc1        $f4, 0x1090($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1192, 0X1090));
    // 0x80800F70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F78: jal         0x80103110
    // 0x80800F7C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800F7C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_3:
    // 0x80800F80: b           L_80800FBC
    // 0x80800F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FBC;
    // 0x80800F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F88:
    // 0x80800F88: jal         0x80101080
    // 0x80800F8C: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x80800F8C: nop

    after_4:
    // 0x80800F90: jal         0x80106790
    // 0x80800F94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800F94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F9C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800FA0: jal         0x80086688
    // 0x80800FA4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80800FA4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_6:
    // 0x80800FA8: b           L_80800FBC
    // 0x80800FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FBC;
    // 0x80800FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FB0:
    // 0x80800FB0: b           L_80800FBC
    // 0x80800FB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FBC;
    // 0x80800FB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FB8:
    // 0x80800FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FBC:
    // 0x80800FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FC4: jr          $ra
    // 0x80800FC8: nop

    return;
    // 0x80800FC8: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004EC: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x808004F0: jal         0x8008CDB8
    // 0x808004F4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x808004F4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x808004F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808004FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080050C: jal         0x8009FFD8
    // 0x80800510: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800510: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x8009B9B0
    // 0x8080051C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080051C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800520: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800524: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x8009F1C8
    // 0x80800530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x80800530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080053C: jal         0x8009F1C8
    // 0x80800540: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800540: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x800A0CF4
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800554: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80800558: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x8080055C: jal         0x800FC660
    // 0x80800560: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x80800560: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x80800564: jal         0x80800000
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbwhirl(rdram, ctx);
        goto after_7;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080056C: jal         0x8009D874
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_8;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080057C: jal         0x80098140
    // 0x80800580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_9;
    // 0x80800580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800588: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080058C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800590: jr          $ra
    // 0x80800594: nop

    return;
    // 0x80800594: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F00: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F00);
    return;
    // 0x80087F04: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfantasylakebits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2376, 0XA30) << 16);
    // 0x808006EC: jr          $ra
    // 0x808006F0: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2376, 0XA30));
    return;
    // 0x808006F0: addiu       $v0, $v0, 0xA30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2376, 0XA30));
;}
RECOMP_FUNC void sumumbofx_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F74: jal         0x800C8CB8
    // 0x80800F78: lh          $a0, 0x5E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5E);
    func_800C8CB8(rdram, ctx);
        goto after_0;
    // 0x80800F78: lh          $a0, 0x5E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5E);
    after_0:
    // 0x80800F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F84: jr          $ra
    // 0x80800F88: nop

    return;
    // 0x80800F88: nop

;}
RECOMP_FUNC void func_800D1C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D1C60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D1C64: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D1C68: jr          $ra
    // 0x800D1C6C: lh          $v0, -0x51B0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X51B0);
    return;
    // 0x800D1C6C: lh          $v0, -0x51B0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X51B0);
;}
RECOMP_FUNC void bsclimb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003DC: jal         0x8008CABC
    // 0x808003E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808003E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808003E8: jal         0x800956B8
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_1;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003F0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808003F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003F8: beq         $v0, $zero, L_80800410
    if (ctx->r2 == 0) {
        // 0x808003FC: nop
    
            goto L_80800410;
    }
    // 0x808003FC: nop

    // 0x80800400: beq         $v0, $at, L_8080045C
    if (ctx->r2 == ctx->r1) {
        // 0x80800404: nop
    
            goto L_8080045C;
    }
    // 0x80800404: nop

    // 0x80800408: b           L_80800490
    // 0x8080040C: nop

        goto L_80800490;
    // 0x8080040C: nop

L_80800410:
    // 0x80800410: jal         0x800D8FF8
    // 0x80800414: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800414: nop

    after_2:
    // 0x80800418: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080041C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800428: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    // 0x8080042C: lui         $a2, 0x403D
    ctx->r6 = S32(0X403D << 16);
    // 0x80800430: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    // 0x80800434: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800438: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8080043C: nop

    // 0x80800440: bc1f        L_80800490
    if (!c1cs) {
        // 0x80800444: nop
    
            goto L_80800490;
    }
    // 0x80800444: nop

    // 0x80800448: jal         0x8008CCBC
    // 0x8080044C: ori         $a2, $a2, 0x70A4
    ctx->r6 = ctx->r6 | 0X70A4;
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x8080044C: ori         $a2, $a2, 0x70A4
    ctx->r6 = ctx->r6 | 0X70A4;
    after_3:
    // 0x80800450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800454: b           L_80800490
    // 0x80800458: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800490;
    // 0x80800458: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_8080045C:
    // 0x8080045C: jal         0x8008B324
    // 0x80800460: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800460: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800464: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x80800468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800490;
    }
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: lui         $a2, 0x4028
    ctx->r6 = S32(0X4028 << 16);
    // 0x80800470: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x80800474: jal         0x8008CB3C
    // 0x80800478: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_5;
    // 0x80800478: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_5:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80800484: jal         0x80800258
    // 0x80800488: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_80800258_bsclimb(rdram, ctx);
        goto after_6;
    // 0x80800488: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_6:
    // 0x8080048C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800490:
    // 0x80800490: jal         0x8080005C
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080005C_bsclimb(rdram, ctx);
        goto after_7;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800498: jal         0x80800298
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800298_bsclimb(rdram, ctx);
        goto after_8;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004A0: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x808004A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B0;
    }
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x808004AC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808004B0:
    // 0x808004B0: jal         0x80091A58
    // 0x808004B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x808004B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x808004B8: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x808004C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808004C8:
    // 0x808004C8: lw          $t9, 0x160($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X160);
    // 0x808004CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004D0: bnel        $t9, $zero, L_808004E0
    if (ctx->r25 != 0) {
        // 0x808004D4: sw          $zero, 0x160($s0)
        MEM_W(0X160, ctx->r16) = 0;
            goto L_808004E0;
    }
    goto skip_0;
    // 0x808004D4: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    skip_0:
    // 0x808004D8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x808004DC: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_808004E0:
    // 0x808004E0: jal         0x8009E5C8
    // 0x808004E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808004E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808004E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004F4: jr          $ra
    // 0x808004F8: nop

    return;
    // 0x808004F8: nop

;}
RECOMP_FUNC void func_800A3514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A351C: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3520: jal         0x800EE7F8
    // 0x800A3524: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A3524: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x800A3528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A352C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3530: jr          $ra
    // 0x800A3534: nop

    return;
    // 0x800A3534: nop

;}
RECOMP_FUNC void func_80802878_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802880: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802884: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802888: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080288C: jal         0x80100094
    // 0x80802890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802894: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802898: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8080289C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808028A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808028A4: beq         $v1, $zero, L_808028C4
    if (ctx->r3 == 0) {
        // 0x808028A8: nop
    
            goto L_808028C4;
    }
    // 0x808028A8: nop

    // 0x808028AC: beq         $v1, $at, L_808028CC
    if (ctx->r3 == ctx->r1) {
        // 0x808028B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808028CC;
    }
    // 0x808028B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028B4: beq         $v1, $at, L_808028E0
    if (ctx->r3 == ctx->r1) {
        // 0x808028B8: nop
    
            goto L_808028E0;
    }
    // 0x808028B8: nop

    // 0x808028BC: b           L_80802900
    // 0x808028C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802900;
    // 0x808028C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808028C4:
    // 0x808028C4: jal         0x80802778
    // 0x808028C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802778_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808028C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_808028CC:
    // 0x808028CC: jal         0x800856E0
    // 0x808028D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808028D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808028D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808028D8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808028DC: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
L_808028E0:
    // 0x808028E0: jal         0x808029C8
    // 0x808028E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808029C8_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808028E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808028E8: jal         0x800880B8
    // 0x808028EC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808028EC: nop

    after_4:
    // 0x808028F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808028F4: jal         0x800856D8
    // 0x808028F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808028F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808028FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802900:
    // 0x80802900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802904: jr          $ra
    // 0x80802908: nop

    return;
    // 0x80802908: nop

;}
RECOMP_FUNC void bsbbuster_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800204: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800208: jal         0x8008CABC
    // 0x8080020C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080020C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800210: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800214: jal         0x8008AF24
    // 0x80800218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800220: jal         0x8008B1A0
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080022C: jal         0x8008AED4
    // 0x80800230: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800230: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_3:
    // 0x80800234: lui         $a1, 0x3F82
    ctx->r5 = S32(0X3F82 << 16);
    // 0x80800238: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x8080023C: jal         0x8008B1BC
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80800244: lui         $a2, 0x3EE8
    ctx->r6 = S32(0X3EE8 << 16);
    // 0x80800248: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800250: jal         0x8008B1D4
    // 0x80800254: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80800254: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080025C: jal         0x8008B134
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800264: jal         0x8008B064
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080026C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800270: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080027C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800280: jal         0x8009FFD8
    // 0x80800284: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80800284: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x8009BCB4
    // 0x80800290: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x80800290: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8009B9B0
    // 0x8080029C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x8080029C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x8009BA9C
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_11;
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x800A0CF4
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_12;
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x80095774
    // 0x808002C0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    baflag_clear(rdram, ctx);
        goto after_13;
    // 0x808002C0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_13:
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: jal         0x80095774
    // 0x808002CC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x808002CC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_14:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x80095774
    // 0x808002D8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    baflag_clear(rdram, ctx);
        goto after_15;
    // 0x808002D8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_15:
    // 0x808002DC: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x808002E0: sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
    // 0x808002E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(65, 0X718) << 16);
    // 0x808002E8: lwc1        $f4, 0x718($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X718));
    // 0x808002EC: sb          $zero, 0x162($s0)
    MEM_B(0X162, ctx->r16) = 0;
    // 0x808002F0: sb          $zero, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = 0;
    // 0x808002F4: sb          $zero, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = 0;
    // 0x808002F8: sb          $zero, 0x160($s0)
    MEM_B(0X160, ctx->r16) = 0;
    // 0x808002FC: sb          $zero, 0x161($s0)
    MEM_B(0X161, ctx->r16) = 0;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800308: jal         0x80800000
    // 0x8080030C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    bsbbuster_setSubstate(rdram, ctx);
        goto after_16;
    // 0x8080030C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    after_16:
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800314: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080031C: jr          $ra
    // 0x80800320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _subaddiefind_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C38: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C38);
    return;
    // 0x80089C3C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808009BC_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808009C0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808009C4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808009C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808009CC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808009D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808009D4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808009D8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808009DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808009E0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009EC: lbu         $t7, 0x7E($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X7E);
    // 0x808009F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808009F4: addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
    // 0x808009F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808009FC: sb          $t8, 0x7E($s1)
    MEM_B(0X7E, ctx->r17) = ctx->r24;
    // 0x80800A00: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800A04: beql        $t9, $zero, L_80800ACC
    if (ctx->r25 == 0) {
        // 0x80800A08: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800ACC;
    }
    goto skip_0;
    // 0x80800A08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800A0C: jal         0x800D674C
    // 0x80800A10: addiu       $a0, $zero, 0x9CF
    ctx->r4 = ADD32(0, 0X9CF);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800A10: addiu       $a0, $zero, 0x9CF
    ctx->r4 = ADD32(0, 0X9CF);
    after_1:
    // 0x80800A14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800A18: jal         0x800E2588
    // 0x80800A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x80800A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800A20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800A24: jal         0x800E2594
    // 0x80800A28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80800A28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800A2C: jal         0x800E24D8
    // 0x80800A30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_4;
    // 0x80800A30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800A34: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80800A38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800A3C: blez        $v1, L_80800AC0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800A40: nop
    
            goto L_80800AC0;
    }
    // 0x80800A40: nop

    // 0x80800A44: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800A48: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
L_80800A4C:
    // 0x80800A4C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800A50: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80800A54: nop

    // 0x80800A58: bc1fl       L_80800AB4
    if (!c1cs) {
        // 0x80800A5C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800AB4;
    }
    goto skip_1;
    // 0x80800A5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800A60: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800A64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800A74: jal         0x800EFA4C
    // 0x80800A78: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80800A78: nop

    after_5:
    // 0x80800A7C: jal         0x800E2530
    // 0x80800A80: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    func_800E2530(rdram, ctx);
        goto after_6;
    // 0x80800A80: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    after_6:
    // 0x80800A84: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800A88: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80800A8C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800A90: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800A94: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80800A98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AA0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800AA4: jal         0x800E2720
    // 0x80800AA8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800E2720(rdram, ctx);
        goto after_7;
    // 0x80800AA8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_7:
    // 0x80800AAC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80800AB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800AB4:
    // 0x80800AB4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800AB8: bne         $at, $zero, L_80800A4C
    if (ctx->r1 != 0) {
        // 0x80800ABC: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_80800A4C;
    }
    // 0x80800ABC: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_80800AC0:
    // 0x80800AC0: jal         0x800E2A14
    // 0x80800AC4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E2A14(rdram, ctx);
        goto after_8;
    // 0x80800AC4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x80800AC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800ACC:
    // 0x80800ACC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800AD0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AD8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800ADC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800AE0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800AE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8080000C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800018: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: jal         0x8080242C
    // 0x8080002C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8080242C_chklungo(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800030: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80800034: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: addiu       $a0, $a0, 0x318
    ctx->r4 = ADD32(ctx->r4, 0X318);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a0, $a0, 0x318
    ctx->r4 = ADD32(ctx->r4, 0X318);
    after_2:
    // 0x80800040: beq         $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x80800044: nop
    
            goto L_80800058;
    }
    // 0x80800044: nop

    // 0x80800048: jal         0x800FFAB0
    // 0x8080004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800050: b           L_808002C0
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C0;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800058:
    // 0x80800058: jal         0x80088848
    // 0x8080005C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x8080005C: nop

    after_4:
    // 0x80800060: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800064: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080008C;
    }
    // 0x80800064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080006C: addiu       $a1, $zero, 0x90C
    ctx->r5 = ADD32(0, 0X90C);
    // 0x80800070: jal         0x801032B0
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_5;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080007C: jal         0x80801964
    // 0x80800080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80801964_chklungo(rdram, ctx);
        goto after_6;
    // 0x80800080: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x80800084: b           L_808002C0
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C0;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080008C:
    // 0x8080008C: jal         0x80109FE8
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_7;
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800098: addiu       $a1, $s0, 0x7C
    ctx->r5 = ADD32(ctx->r16, 0X7C);
    // 0x8080009C: jal         0x80089F70
    // 0x808000A0: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808000A0: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_8:
    // 0x808000A4: addiu       $a1, $s0, 0x88
    ctx->r5 = ADD32(ctx->r16, 0X88);
    // 0x808000A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000B0: jal         0x8008A2A0
    // 0x808000B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808000B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808000B8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3A3C) << 16);
    // 0x808000BC: addiu       $a1, $a1, 0x3A3C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3A3C));
    // 0x808000C0: jal         0x8008A300
    // 0x808000C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x808000C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808000C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: jal         0x8008A2A8
    // 0x808000D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _susubgame_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x808000D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_11:
    // 0x808000D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000DC: jal         0x808020F0
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808020F0_chklungo(rdram, ctx);
        goto after_12;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808000E4: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x808000E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3910) << 16);
    // 0x808000EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000F0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x808000F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808000F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000FC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800100: lwc1        $f4, 0x3910($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3910));
    // 0x80800104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800108: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8080010C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x80800110: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x80800114: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80800118: jal         0x80802DF4
    // 0x8080011C: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    func_80802DF4_chklungo(rdram, ctx);
        goto after_13;
    // 0x8080011C: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    after_13:
    // 0x80800120: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    // 0x80800124: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x80800128: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080012C: bnel        $t0, $zero, L_80800140
    if (ctx->r8 != 0) {
        // 0x80800130: sh          $t1, 0x22($s0)
        MEM_H(0X22, ctx->r16) = ctx->r9;
            goto L_80800140;
    }
    goto skip_0;
    // 0x80800130: sh          $t1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r9;
    skip_0:
    // 0x80800134: b           L_80800140
    // 0x80800138: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
        goto L_80800140;
    // 0x80800138: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x8080013C: sh          $t1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r9;
L_80800140:
    // 0x80800140: lw          $t2, 0x78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X78);
    // 0x80800144: sll         $t4, $t2, 26
    ctx->r12 = S32(ctx->r10 << 26);
    // 0x80800148: bgezl       $t4, L_808002C0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080014C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C0;
    }
    goto skip_1;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800150: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x80800154: addiu       $a0, $zero, 0x3A1
    ctx->r4 = ADD32(0, 0X3A1);
    // 0x80800158: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x8080015C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80800160: jal         0x80088480
    // 0x80800164: sb          $t7, 0x70($s1)
    MEM_B(0X70, ctx->r17) = ctx->r15;
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800164: sb          $t7, 0x70($s1)
    MEM_B(0X70, ctx->r17) = ctx->r15;
    after_14:
    // 0x80800168: sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // 0x8080016C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800170: addiu       $a1, $zero, 0x3A1
    ctx->r5 = ADD32(0, 0X3A1);
    // 0x80800174: addiu       $a2, $s0, 0x4C
    ctx->r6 = ADD32(ctx->r16, 0X4C);
    // 0x80800178: jal         0x8008A0C0
    // 0x8080017C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x8080017C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x80800180: addiu       $a2, $s0, 0x64
    ctx->r6 = ADD32(ctx->r16, 0X64);
    // 0x80800184: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800190: jal         0x8008A0C0
    // 0x80800194: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x80800194: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
    // 0x80800198: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x8080019C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1240, 0X38A2) << 16);
    // 0x808001A0: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808001A4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808001A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808001AC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x808001B0: jal         0x800DA298
    // 0x808001B4: lh          $a0, 0x38A2($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A2));
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808001B4: lh          $a0, 0x38A2($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A2));
    after_17:
    // 0x808001B8: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x808001BC: nop
    
            goto L_8080024C;
    }
    // 0x808001BC: nop

    // 0x808001C0: jal         0x800F54E4
    // 0x808001C4: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808001C4: nop

    after_18:
    // 0x808001C8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808001CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808001D0: sh          $t0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r8;
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D8: jal         0x800F608C
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_19;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808001E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001E4: jal         0x800F8294
    // 0x808001E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F8294(rdram, ctx);
        goto after_20;
    // 0x808001E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x808001EC: jal         0x800F497C
    // 0x808001F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F497C(rdram, ctx);
        goto after_21;
    // 0x808001F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x808001F4: jal         0x800878F8
    // 0x808001F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_22;
    // 0x808001F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_22:
    // 0x808001FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800204: jal         0x80802588
    // 0x80800208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802588_chklungo(rdram, ctx);
        goto after_23;
    // 0x80800208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x8080020C: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x80800210: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3916) << 16);
    // 0x80800214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800218: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8080021C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80800220: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800224: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80800228: lh          $a1, 0x3916($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3916));
    // 0x8080022C: jal         0x80803158
    // 0x80800230: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_80803158_chklungo(rdram, ctx);
        goto after_24;
    // 0x80800230: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_24:
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800238: jal         0x80801964
    // 0x8080023C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801964_chklungo(rdram, ctx);
        goto after_25;
    // 0x8080023C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x80800240: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800244: b           L_808002BC
    // 0x80800248: sh          $t3, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r11;
        goto L_808002BC;
    // 0x80800248: sh          $t3, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r11;
L_8080024C:
    // 0x8080024C: jal         0x800D395C
    // 0x80800250: nop

    func_800D395C(rdram, ctx);
        goto after_26;
    // 0x80800250: nop

    after_26:
    // 0x80800254: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x80800258: nop
    
            goto L_80800298;
    }
    // 0x80800258: nop

    // 0x8080025C: lh          $t4, 0x8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8);
    // 0x80800260: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800268: bne         $t4, $at, L_80800284
    if (ctx->r12 != ctx->r1) {
        // 0x8080026C: addiu       $a1, $zero, 0x1633
        ctx->r5 = ADD32(0, 0X1633);
            goto L_80800284;
    }
    // 0x8080026C: addiu       $a1, $zero, 0x1633
    ctx->r5 = ADD32(0, 0X1633);
    // 0x80800270: jal         0x80803158
    // 0x80800274: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80803158_chklungo(rdram, ctx);
        goto after_27;
    // 0x80800274: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_27:
    // 0x80800278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080027C: jal         0x80801964
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801964_chklungo(rdram, ctx);
        goto after_28;
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
L_80800284:
    // 0x80800284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800288: jal         0x80801964
    // 0x8080028C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801964_chklungo(rdram, ctx);
        goto after_29;
    // 0x8080028C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_29:
    // 0x80800290: b           L_808002C0
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C0;
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: jal         0x800861A8
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
    // 0x808002A0: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x808002A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002AC: bnel        $t5, $at, L_808002C0
    if (ctx->r13 != ctx->r1) {
        // 0x808002B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C0;
    }
    goto skip_2;
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808002B4: jal         0x80801964
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801964_chklungo(rdram, ctx);
        goto after_31;
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_31:
L_808002BC:
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C0:
    // 0x808002C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808002CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C334C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C334C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3354: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3358: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C335C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3360: beq         $t6, $zero, L_800C3384
    if (ctx->r14 == 0) {
        // 0x800C3364: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3384;
    }
    // 0x800C3364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3368: jal         0x800C1414
    // 0x800C336C: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C336C: nop

    after_0:
    // 0x800C3370: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3378: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x800C337C: jal         0x800C13A0
    // 0x800C3380: sb          $t7, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r15;
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C3380: sb          $t7, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r15;
    after_1:
L_800C3384:
    // 0x800C3384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C338C: jr          $ra
    // 0x800C3390: nop

    return;
    // 0x800C3390: nop

;}
RECOMP_FUNC void func_808000F0_chklungoforcefield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000FC: jal         0x800D8FF8
    // 0x80800100: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800104: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800108: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080010C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1248, 0X46C) << 16);
    // 0x80800110: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800114: addiu       $a3, $a3, 0x46C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1248, 0X46C));
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800124: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800128: jal         0x80089D50
    // 0x8080012C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080012C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80800130: jal         0x80089C90
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1248, 0X3F0) << 16);
    // 0x8080013C: lwc1        $f18, 0x3F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1248, 0X3F0));
    // 0x80800140: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800148: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    // 0x8080014C: lui         $a3, 0x45FA
    ctx->r7 = S32(0X45FA << 16);
    // 0x80800150: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800154: jal         0x800F12D4
    // 0x80800158: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_800F12D4(rdram, ctx);
        goto after_3;
    // 0x80800158: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_3:
    // 0x8080015C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800168: jal         0x80089D38
    // 0x8080016C: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080016C: nop

    after_4:
    // 0x80800170: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80800174: beql        $t7, $zero, L_808001C4
    if (ctx->r15 == 0) {
        // 0x80800178: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001C4;
    }
    goto skip_0;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080017C: jal         0x80089C90
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800184: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800188: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080018C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800190: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800194: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    // 0x80800198: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x8080019C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808001A0: jal         0x800F12D4
    // 0x808001A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F12D4(rdram, ctx);
        goto after_6;
    // 0x808001A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x808001A8: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x808001B4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808001B8: jal         0x800C8E54
    // 0x808001BC: nop

    func_800C8E54(rdram, ctx);
        goto after_7;
    // 0x808001BC: nop

    after_7:
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C4:
    // 0x808001C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_80800000_chbkcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800014: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800018: addiu       $v0, $t7, -0x32
    ctx->r2 = ADD32(ctx->r15, -0X32);
    // 0x8080001C: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x80800020: nop
    
            goto L_8080003C;
    }
    // 0x80800020: nop

    // 0x80800024: beq         $v0, $at, L_80800070
    if (ctx->r2 == ctx->r1) {
        // 0x80800028: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800070;
    }
    // 0x80800028: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080002C: beq         $v0, $at, L_808000A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: nop
    
            goto L_808000A4;
    }
    // 0x80800030: nop

    // 0x80800034: b           L_808000DC
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808000DC;
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080003C:
    // 0x8080003C: jal         0x800D1A04
    // 0x80800040: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x80800044: bnel        $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x80800048: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800048: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8080004C: jal         0x800DA298
    // 0x80800050: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    after_1:
    // 0x80800054: beql        $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x80800058: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000DC;
    }
    goto skip_1;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8080005C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
L_80800060:
    // 0x80800060: jal         0x800FFA88
    // 0x80800064: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800064: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x80800068: b           L_80800124
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800070:
    // 0x80800070: jal         0x800DA298
    // 0x80800074: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_3:
    // 0x80800078: bnel        $v0, $zero, L_80800094
    if (ctx->r2 != 0) {
        // 0x8080007C: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800094;
    }
    goto skip_2;
    // 0x8080007C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x80800080: jal         0x800DA298
    // 0x80800084: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_4:
    // 0x80800088: beql        $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x8080008C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000DC;
    }
    goto skip_3;
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_3:
    // 0x80800090: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80800094:
    // 0x80800094: jal         0x800FFA88
    // 0x80800098: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_5;
    // 0x80800098: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x8080009C: b           L_80800124
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A4:
    // 0x808000A4: jal         0x800DA298
    // 0x808000A8: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    after_6:
    // 0x808000AC: bnel        $v0, $zero, L_808000C8
    if (ctx->r2 != 0) {
        // 0x808000B0: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808000C8;
    }
    goto skip_4;
    // 0x808000B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_4:
    // 0x808000B4: jal         0x800DA298
    // 0x808000B8: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808000B8: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_7:
    // 0x808000BC: beql        $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000DC;
    }
    goto skip_5;
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_5:
    // 0x808000C4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_808000C8:
    // 0x808000C8: jal         0x800FFA88
    // 0x808000CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808000CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_8:
    // 0x808000D0: b           L_80800124
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808000DC:
    // 0x808000DC: jal         0x80100094
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000EC: jal         0x80089F70
    // 0x808000F0: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808000F0: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_10:
    // 0x808000F4: jal         0x800DA298
    // 0x808000F8: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808000F8: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    after_11:
    // 0x808000FC: bne         $v0, $zero, L_80800118
    if (ctx->r2 != 0) {
        // 0x80800100: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800118;
    }
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800108: jal         0x80102424
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800110: b           L_80800124
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800118:
    // 0x80800118: jal         0x80102424
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800124:
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void chdrips_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X5F0) << 16);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800028: jal         0x800DC178
    // 0x8080002C: lwc1        $f14, 0x5F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5F0));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080002C: lwc1        $f14, 0x5F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5F0));
    after_0:
    // 0x80800030: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X5F4) << 16);
    // 0x80800034: lwc1        $f4, 0x5F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5F4));
    // 0x80800038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080003C: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x80800040: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800044: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800048: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080004C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800054: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800058: nop

    // 0x8080005C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800060: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800064: nop

    // 0x80800068: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080006C: beql        $a0, $zero, L_808000BC
    if (ctx->r4 == 0) {
        // 0x80800070: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_808000BC;
    }
    goto skip_0;
    // 0x80800070: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80800074: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080007C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800080: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800084: nop

    // 0x80800088: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8080008C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800090: nop

    // 0x80800094: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800098: bne         $a0, $zero, L_808000B0
    if (ctx->r4 != 0) {
        // 0x8080009C: nop
    
            goto L_808000B0;
    }
    // 0x8080009C: nop

    // 0x808000A0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x808000A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000A8: b           L_808000C8
    // 0x808000AC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808000C8;
    // 0x808000AC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808000B0:
    // 0x808000B0: b           L_808000C8
    // 0x808000B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808000C8;
    // 0x808000B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808000B8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_808000BC:
    // 0x808000BC: nop

    // 0x808000C0: bltz        $a0, L_808000B0
    if (SIGNED(ctx->r4) < 0) {
        // 0x808000C4: nop
    
            goto L_808000B0;
    }
    // 0x808000C4: nop

L_808000C8:
    // 0x808000C8: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x808000CC: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x808000D0: ori         $at, $at, 0xBD53
    ctx->r1 = ctx->r1 | 0XBD53;
    // 0x808000D4: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x808000D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808000DC: jal         0x800C4140
    // 0x808000E0: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_1;
    // 0x808000E0: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    after_1:
    // 0x808000E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000E8: jal         0x800889A0
    // 0x808000EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808000EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void chswitch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001BC: jal         0x800DA298
    // 0x808001C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808001C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001D4: jal         0x80103110
    // 0x808001D8: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808001D8: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
    after_1:
    // 0x808001DC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808001E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E8: jal         0x80102E08
    // 0x808001EC: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    func_80102E08(rdram, ctx);
        goto after_2;
    // 0x808001EC: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void baflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800DF350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF350: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF354: jr          $ra
    // 0x800DF358: lw          $v0, -0x36C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36C0);
    return;
    // 0x800DF358: lw          $v0, -0x36C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36C0);
;}
RECOMP_FUNC void _glhittableDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088618: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088618);
    return;
    // 0x8008861C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chflysaucercrate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1696, 0XD78) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xD78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1696, 0XD78));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xD78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1696, 0XD78));
;}
RECOMP_FUNC void func_80800108_chswappy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800108_chswappy");
    // 0x80800108: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080010C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800114: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080011C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800120: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800124: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x80800128: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8080012C: beq         $t6, $at, L_80800154
    if (ctx->r14 == ctx->r1) {
        // 0x80800130: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_80800154;
    }
    // 0x80800130: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80800134: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800138: beq         $t6, $at, L_808001A8
    if (ctx->r14 == ctx->r1) {
        // 0x8080013C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A8;
    }
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800144: beql        $t6, $at, L_808001BC
    if (ctx->r14 == ctx->r1) {
        // 0x80800148: lbu         $a0, 0x79($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X79);
            goto L_808001BC;
    }
    goto skip_0;
    // 0x80800148: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    skip_0:
    // 0x8080014C: b           L_808001F8
    // 0x80800150: nop

        goto L_808001F8;
    // 0x80800150: nop

L_80800154:
    // 0x80800154: jal         0x800878A0
    // 0x80800158: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x8080015C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800160: beq         $v0, $at, L_808001F8
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001F8;
    }
    // 0x80800164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800168: jal         0x800F5A00
    // 0x8080016C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8080016C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x80800170: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800174: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800178: jal         0x800EFFB4
    // 0x8080017C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800EFFB4(rdram, ctx);
        goto after_2;
    // 0x8080017C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80800180: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x80800184: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_808001F8;
    }
    // 0x80800184: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800188: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8080018C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800190: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    // 0x80800194: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800198: jal         0x80089F20
    // 0x8080019C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080019C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_3:
    // 0x808001A0: b           L_808001F8
    // 0x808001A4: nop

        goto L_808001F8;
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: jal         0x808000B0
    // 0x808001AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000B0_chswappy(rdram, ctx);
        goto after_4;
    // 0x808001AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808001B0: b           L_808001F8
    // 0x808001B4: nop

        goto L_808001F8;
    // 0x808001B4: nop

    // 0x808001B8: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
L_808001BC:
    // 0x808001BC: srl         $t9, $a0, 4
    ctx->r25 = S32(U32(ctx->r4) >> 4);
    // 0x808001C0: jal         0x800F6BE4
    // 0x808001C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_5;
    // 0x808001C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_5:
    // 0x808001C8: beql        $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    goto skip_1;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001D0: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x808001D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808001D8: srl         $t0, $a0, 4
    ctx->r8 = S32(U32(ctx->r4) >> 4);
    // 0x808001DC: jal         0x800F7B9C
    // 0x808001E0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_6;
    // 0x808001E0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x808001E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E8: bne         $v0, $at, L_808001F8
    if (ctx->r2 != ctx->r1) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001F0:
    // 0x808001F0: jal         0x808000B0
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_7;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_808001F8:
    // 0x808001F8: jal         0x800F8B88
    // 0x808001FC: nop

    func_800F8B88(rdram, ctx);
        goto after_8;
    // 0x808001FC: nop

    after_8:
    // 0x80800200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800204: bne         $v0, $at, L_80800214
    if (ctx->r2 != ctx->r1) {
        // 0x80800208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800214;
    }
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80800488
    // 0x80800210: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    chswappy_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800210: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_9:
L_80800214:
    // 0x80800214: lbu         $t1, 0x7E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7E);
    // 0x80800218: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x8080021C: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
    // 0x80800220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800228: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

;}
RECOMP_FUNC void suexpressjoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808001DC: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x808001E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001E4: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x808001E8: addiu       $t1, $t1, 0x1818
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x808001EC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808001F0: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x808001F4: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x808001F8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808001FC: addiu       $t0, $a1, 0x20
    ctx->r8 = ADD32(ctx->r5, 0X20);
    // 0x80800200: beq         $a2, $zero, L_80800414
    if (ctx->r6 == 0) {
        // 0x80800204: lbu         $t2, 0xA($t8)
        ctx->r10 = MEM_BU(ctx->r24, 0XA);
            goto L_80800414;
    }
    // 0x80800204: lbu         $t2, 0xA($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XA);
    // 0x80800208: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8080020C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800210: jal         0x800D52F4
    // 0x80800214: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_800D52F4(rdram, ctx);
        goto after_0;
    // 0x80800214: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_0:
    // 0x80800218: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8080021C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x80800220: addiu       $t1, $t1, 0x1818
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x80800224: lh          $t9, 0x4($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X4);
    // 0x80800228: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080022C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800230: bnel        $v0, $t9, L_80800418
    if (ctx->r2 != ctx->r25) {
        // 0x80800234: lbu         $t6, 0x8($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X8);
            goto L_80800418;
    }
    goto skip_0;
    // 0x80800234: lbu         $t6, 0x8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X8);
    skip_0:
    // 0x80800238: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8080023C: jal         0x800D52A4
    // 0x80800240: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_800D52A4(rdram, ctx);
        goto after_1;
    // 0x80800240: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800244: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x80800248: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8080024C: addiu       $t1, $t1, 0x1818
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x80800250: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800254: bgez        $t2, L_8080026C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800258: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8080026C;
    }
    // 0x80800258: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080025C: lh          $t3, 0x6($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X6);
    // 0x80800260: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800264: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80800268: lbu         $t2, 0xA($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0XA);
L_8080026C:
    // 0x8080026C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80800270: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800274: jal         0x800D5298
    // 0x80800278: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_800D5298(rdram, ctx);
        goto after_2;
    // 0x80800278: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_2:
    // 0x8080027C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x80800280: addiu       $t1, $t1, 0x1818
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x80800284: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800288: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080028C: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800290: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_808002A0;
    }
    // 0x80800290: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA40) << 16);
    // 0x80800298: lwc1        $f6, 0xA40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA40));
    // 0x8080029C: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_808002A0:
    // 0x808002A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808002A4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002A8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808002AC: nop

    // 0x808002B0: bc1fl       L_808002E8
    if (!c1cs) {
        // 0x808002B4: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_808002E8;
    }
    goto skip_1;
    // 0x808002B4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_1:
    // 0x808002B8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808002BC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808002C0: jal         0x800D8FF8
    // 0x808002C4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808002C4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_3:
    // 0x808002C8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x808002CC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808002D0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808002D4: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002D8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808002DC: b           L_80800308
    // 0x808002E0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
        goto L_80800308;
    // 0x808002E0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x808002E4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_808002E8:
    // 0x808002E8: nop

    // 0x808002EC: bc1fl       L_8080030C
    if (!c1cs) {
        // 0x808002F0: lbu         $v0, 0x8($a3)
        ctx->r2 = MEM_BU(ctx->r7, 0X8);
            goto L_8080030C;
    }
    goto skip_2;
    // 0x808002F0: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    skip_2:
    // 0x808002F4: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x808002F8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808002FC: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80800300: lbu         $t2, 0xA($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XA);
    // 0x80800304: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_80800308:
    // 0x80800308: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
L_8080030C:
    // 0x8080030C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80800310: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800314: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x80800318: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8080031C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA44) << 16);
    // 0x80800324: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800328: lwc1        $f6, 0xA44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA44));
    // 0x8080032C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800330: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800334: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800338: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8080033C: nop

    // 0x80800340: bc1f        L_8080034C
    if (!c1cs) {
        // 0x80800344: nop
    
            goto L_8080034C;
    }
    // 0x80800344: nop

    // 0x80800348: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8080034C:
    tooie_mouth_open_step(rdram, ctx);
    // 0x8080034C: bgez        $v0, L_80800360
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800350: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800360;
    }
    // 0x80800350: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800354: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800358: nop

    // 0x8080035C: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_80800360:
    // 0x80800360: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800364: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800368: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080036C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80800370: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800374: jal         0x800F15F8
    // 0x80800378: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x80800378: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8080037C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800380: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800384: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800388: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x8080038C: addiu       $t1, $t1, 0x1818
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x80800390: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800394: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800398: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080039C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808003A0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808003A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808003A8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808003AC: beql        $t5, $zero, L_808003FC
    if (ctx->r13 == 0) {
        // 0x808003B0: mfc1        $t5, $f18
        ctx->r13 = (int32_t)ctx->f18.u32l;
            goto L_808003FC;
    }
    goto skip_3;
    // 0x808003B0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x808003B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808003BC: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x808003C0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808003C4: nop

    // 0x808003C8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808003CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808003D0: nop

    // 0x808003D4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808003D8: bne         $t5, $zero, L_808003F0
    if (ctx->r13 != 0) {
        // 0x808003DC: nop
    
            goto L_808003F0;
    }
    // 0x808003DC: nop

    // 0x808003E0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x808003E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003E8: b           L_80800408
    // 0x808003EC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80800408;
    // 0x808003EC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_808003F0:
    // 0x808003F0: b           L_80800408
    // 0x808003F4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80800408;
    // 0x808003F4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808003F8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
L_808003FC:
    // 0x808003FC: nop

    // 0x80800400: bltz        $t5, L_808003F0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800404: nop
    
            goto L_808003F0;
    }
    // 0x80800404: nop

L_80800408:
    // 0x80800408: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8080040C: b           L_808004D0
    // 0x80800410: sb          $t5, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r13;
        goto L_808004D0;
    // 0x80800410: sb          $t5, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r13;
L_80800414:
    // 0x80800414: lbu         $t6, 0x8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X8);
L_80800418:
    // 0x80800418: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080041C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800420: bgez        $t6, L_80800434
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800424: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800434;
    }
    // 0x80800424: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800428: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080042C: nop

    // 0x80800430: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80800434:
    // 0x80800434: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA48) << 16);
    // 0x80800438: lwc1        $f8, 0xA48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA48));
    // 0x8080043C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800440: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800444: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    tooie_mouth_close_step(rdram, ctx);
    // 0x80800448: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8080044C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800450: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800454: nop

    // 0x80800458: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8080045C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800460: nop

    // 0x80800464: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800468: beql        $t8, $zero, L_808004B8
    if (ctx->r24 == 0) {
        // 0x8080046C: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_808004B8;
    }
    goto skip_4;
    // 0x8080046C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x80800470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800474: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800478: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8080047C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800480: nop

    // 0x80800484: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800488: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8080048C: nop

    // 0x80800490: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800494: bne         $t8, $zero, L_808004AC
    if (ctx->r24 != 0) {
        // 0x80800498: nop
    
            goto L_808004AC;
    }
    // 0x80800498: nop

    // 0x8080049C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x808004A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808004A4: b           L_808004C4
    // 0x808004A8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_808004C4;
    // 0x808004A8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_808004AC:
    // 0x808004AC: b           L_808004C4
    // 0x808004B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_808004C4;
    // 0x808004B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808004B4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_808004B8:
    // 0x808004B8: nop

    // 0x808004BC: bltz        $t8, L_808004AC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808004C0: nop
    
            goto L_808004AC;
    }
    // 0x808004C0: nop

L_808004C4:
    // 0x808004C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004C8: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
    // 0x808004CC: nop

L_808004D0:
    // 0x808004D0: lh          $t9, 0x6($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X6);
    // 0x808004D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808004D8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808004DC: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x808004E0: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x808004E4: lbu         $a2, 0xC($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0XC);
    // 0x808004E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA4C) << 16);
    // 0x808004F0: blezl       $a2, L_80800658
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808004F4: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800658;
    }
    goto skip_5;
    // 0x808004F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_5:
    // 0x808004F8: lwc1        $f12, 0xA4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA4C));
    // 0x808004FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA50) << 16);
    // 0x80800500: lwc1        $f2, 0xA50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA50));
    // 0x80800504: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
L_80800508:
    // 0x80800508: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8080050C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800510: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800514: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80800518: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8080051C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800520: bgez        $t8, L_80800534
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800524: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800534;
    }
    // 0x80800524: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800528: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080052C: nop

    // 0x80800530: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800534:
    // 0x80800534: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80800538: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8080053C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800540: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80800544: bgez        $t9, L_80800558
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800548: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800558;
    }
    // 0x80800548: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080054C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800550: nop

    // 0x80800554: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80800558:
    // 0x80800558: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080055C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800560: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800564: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800568: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    tooie_mouth_channel_step(rdram, ctx);
    // 0x8080056C: add.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800570: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800574: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800578: nop

    // 0x8080057C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800580: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800584: nop

    // 0x80800588: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8080058C: beql        $t4, $zero, L_808005DC
    if (ctx->r12 == 0) {
        // 0x80800590: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_808005DC;
    }
    goto skip_6;
    // 0x80800590: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x80800594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800598: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080059C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808005A0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808005A4: nop

    // 0x808005A8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808005AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x808005B0: nop

    // 0x808005B4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x808005B8: bne         $t4, $zero, L_808005D0
    if (ctx->r12 != 0) {
        // 0x808005BC: nop
    
            goto L_808005D0;
    }
    // 0x808005BC: nop

    // 0x808005C0: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x808005C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808005C8: b           L_808005E8
    // 0x808005CC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_808005E8;
    // 0x808005CC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_808005D0:
    // 0x808005D0: b           L_808005E8
    // 0x808005D4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_808005E8;
    // 0x808005D4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x808005D8: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_808005DC:
    // 0x808005DC: nop

    // 0x808005E0: bltz        $t4, L_808005D0
    if (SIGNED(ctx->r12) < 0) {
        // 0x808005E4: nop
    
            goto L_808005D0;
    }
    // 0x808005E4: nop

L_808005E8:
    // 0x808005E8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x808005EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808005F0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x808005F4: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x808005F8: bgez        $t5, L_80800610
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808005FC: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800610;
    }
    // 0x808005FC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800600: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800604: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800608: nop

    // 0x8080060C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80800610:
    tooie_mouth_channel_weight(rdram, ctx);
    // 0x80800610: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80800614: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800618: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080061C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800620: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80800624: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80800628: lwc1        $f4, 0x1C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x8080062C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800630: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80800634: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800638: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080063C: addu        $a1, $t1, $t7
    ctx->r5 = ADD32(ctx->r9, ctx->r15);
    // 0x80800640: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
    // 0x80800644: lbu         $a2, 0xC($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0XC);
    // 0x80800648: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8080064C: bnel        $at, $zero, L_80800508
    if (ctx->r1 != 0) {
        // 0x80800650: lw          $t4, 0x4($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X4);
            goto L_80800508;
    }
    goto skip_7;
    // 0x80800650: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    skip_7:
    // 0x80800654: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800658:
    // 0x80800658: lwc1        $f18, 0x1C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x8080065C: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80800660: nop

    // 0x80800664: bc1tl       L_808006B0
    if (c1cs) {
        // 0x80800668: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808006B0;
    }
    goto skip_8;
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x8080066C: blez        $a2, L_808006AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800670: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808006AC;
    }
    // 0x80800670: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800674: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800678: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
L_8080067C:
    // 0x8080067C: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80800680: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800684: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800688: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080068C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80800690: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x80800694: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800698: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x8080069C: lbu         $t4, 0xC($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XC);
    // 0x808006A0: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808006A4: bnel        $at, $zero, L_8080067C
    if (ctx->r1 != 0) {
        // 0x808006A8: lwc1        $f4, 0xC($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8080067C;
    }
    goto skip_9;
    // 0x808006A8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    skip_9:
L_808006AC:
    // 0x808006AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006B0:
    // 0x808006B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void func_80104504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010450C: lh          $a1, 0x8E($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X8E);
    // 0x80104510: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80104514: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104518: beql        $a1, $zero, L_80104538
    if (ctx->r5 == 0) {
        // 0x8010451C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80104538;
    }
    goto skip_0;
    // 0x8010451C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80104520: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    // 0x80104524: jal         0x800B32C0
    // 0x80104528: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x80104528: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010452C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80104530: sh          $zero, 0x8E($a2)
    MEM_H(0X8E, ctx->r6) = 0;
    // 0x80104534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104538:
    // 0x80104538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010453C: jr          $ra
    // 0x80104540: nop

    return;
    // 0x80104540: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800008: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080001C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800020: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800024: jal         0x80100074
    // 0x80800028: addiu       $a2, $t6, 0x20
    ctx->r6 = ADD32(ctx->r14, 0X20);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a2, $t6, 0x20
    ctx->r6 = ADD32(ctx->r14, 0X20);
    after_0:
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x80100094
    // 0x80800034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800038: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x8080003C: sh          $t7, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r15;
    // 0x80800040: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_800A0110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0118: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A011C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800A0120: jal         0x80084658
    // 0x800A0124: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    _badata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800A0124: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800A0128: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A012C: jal         0x8008AED4
    // 0x800A0130: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x800A0130: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A0134: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A0138: jal         0x8008B1BC
    // 0x800A013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x800A013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A0140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A0148: jr          $ra
    // 0x800A014C: nop

    return;
    // 0x800A014C: nop

;}
RECOMP_FUNC void _bahold_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D20: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D20);
    return;
    // 0x80084D24: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void bskazstilt_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080045C: addiu       $a1, $zero, 0x149
    ctx->r5 = ADD32(0, 0X149);
    // 0x80800460: jal         0x8008CB3C
    // 0x80800464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x80800468: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080046C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080047C: jal         0x8009FFD8
    // 0x80800480: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800480: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800484: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800488: jal         0x8009B9B0
    // 0x8080048C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080048C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800490: jal         0x8080013C
    // 0x80800494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080013C_bskazstilt(rdram, ctx);
        goto after_3;
    // 0x80800494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080049C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void chintrotext_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800668: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080066C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800670: jal         0x800880F0
    // 0x80800674: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    _gcintrotext_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800674: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800678: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080067C: beq         $v0, $at, L_808006AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800680: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_808006AC;
    }
    // 0x80800680: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: bne         $t6, $zero, L_80800694
    if (ctx->r14 != 0) {
        // 0x80800688: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800694;
    }
    // 0x80800688: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080068C: blezl       $v0, L_808006B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800690: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006B0;
    }
    goto skip_0;
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80800694:
    // 0x80800694: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080069C: jal         0x8080060C
    // 0x808006A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    chintrotext_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808006A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808006A4: b           L_808006B0
    // 0x808006A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B0;
    // 0x808006A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006AC:
    // 0x808006AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006B0:
    // 0x808006B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006B8: jr          $ra
    // 0x808006BC: nop

    return;
    // 0x808006BC: nop

;}
RECOMP_FUNC void func_80800AF0_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B00: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    // 0x80800B04: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80800B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B0C: jal         0x80108528
    // 0x80800B10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80800B10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800B14: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800B18: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800B1C: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80800B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void bamovegoto_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080006C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800070: sw          $zero, 0x80($t6)
    MEM_W(0X80, ctx->r14) = 0;
    // 0x80800074: lw          $t7, 0xC8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC8);
    // 0x80800078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800080: sw          $zero, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = 0;
    // 0x80800084: lw          $t8, 0xC8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC8);
    // 0x80800088: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080008C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800090: swc1        $f4, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->f4.u32l;
    // 0x80800094: lw          $t0, 0xC8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC8);
    // 0x80800098: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    // 0x8080009C: lw          $t1, 0xC8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC8);
    // 0x808000A0: sb          $zero, 0x56($t1)
    MEM_B(0X56, ctx->r9) = 0;
    // 0x808000A4: lw          $t2, 0xC8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC8);
    // 0x808000A8: sb          $zero, 0x54($t2)
    MEM_B(0X54, ctx->r10) = 0;
    // 0x808000AC: lw          $t3, 0xC8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC8);
    // 0x808000B0: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
    // 0x808000B4: lw          $t4, 0xC8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC8);
    // 0x808000B8: swc1        $f8, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->f8.u32l;
    // 0x808000BC: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x808000C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x808000C4: jal         0x800EFD24
    // 0x808000C8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x808000CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: lw          $a0, 0xC8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC8);
    // 0x808000D4: jal         0x800EFD24
    // 0x808000D8: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x808000D8: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    after_1:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_800DF720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF720: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF724: jr          $ra
    // 0x800DF728: sw          $a0, -0x368C($at)
    MEM_W(-0X368C, ctx->r1) = ctx->r4;
    return;
    // 0x800DF728: sw          $a0, -0x368C($at)
    MEM_W(-0X368C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800B4790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4790: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B4794: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B4798: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800B479C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B47A0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800B47A4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800B47A8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800B47AC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800B47B0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800B47B4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800B47B8: jal         0x800D8FF8
    // 0x800B47BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800B47BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800B47C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B47C4: lbu         $t6, 0x7F1C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7F1C);
    tooie_particle_age_floor(rdram, ctx);
    // 0x800B47C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800B47CC: beql        $t6, $zero, L_800B5000
    if (ctx->r14 == 0) {
        // 0x800B47D0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800B5000;
    }
    goto skip_0;
    // 0x800B47D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800B47D4: lw          $s0, 0x8C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8C);
    // 0x800B47D8: lw          $t7, 0x90($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X90);
    // 0x800B47DC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800B47E0: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
    // 0x800B47E4: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x800B47E8: beq         $at, $zero, L_800B4EDC
    if (ctx->r1 == 0) {
        // 0x800B47EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B4EDC;
    }
    // 0x800B47EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B47F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800B47F4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800B47F8: lh          $t8, 0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X36);
L_800B47FC:
    // 0x800B47FC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B4800: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800B4804: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800B4808: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B480C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800B4810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4814: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B4818: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B481C: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800B4820: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B4824: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B4828: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x800B482C: nop

    // 0x800B4830: bc1fl       L_800B4870
    if (!c1cs) {
        // 0x800B4834: div.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
            goto L_800B4870;
    }
    goto skip_1;
    // 0x800B4834: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    skip_1:
    // 0x800B4838: lw          $t9, 0x90($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X90);
    // 0x800B483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4840: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800B4844: addiu       $a1, $t9, -0x3C
    ctx->r5 = ADD32(ctx->r25, -0X3C);
    // 0x800B4848: jal         0x8001BBA0
    // 0x800B484C: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800B484C: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    after_1:
    // 0x800B4850: lbu         $t1, 0x7($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X7);
    // 0x800B4854: bnel        $s5, $t1, L_800B4ED0
    if (ctx->r21 != ctx->r9) {
        // 0x800B4858: lw          $t6, 0x90($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X90);
            goto L_800B4ED0;
    }
    goto skip_2;
    // 0x800B4858: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    skip_2:
    // 0x800B485C: lw          $t2, 0x94($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X94);
    // 0x800B4860: addiu       $t3, $t2, -0x3C
    ctx->r11 = ADD32(ctx->r10, -0X3C);
    // 0x800B4864: b           L_800B4ECC
    // 0x800B4868: sw          $t3, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r11;
        goto L_800B4ECC;
    // 0x800B4868: sw          $t3, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r11;
    // 0x800B486C: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_800B4870:
    // 0x800B4870: lwc1        $f14, 0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800B4874: addiu       $s3, $s0, 0x6
    ctx->r19 = ADD32(ctx->r16, 0X6);
    // 0x800B4878: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B487C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800B4880: nop

    // 0x800B4884: bc1fl       L_800B489C
    if (!c1cs) {
        // 0x800B4888: lwc1        $f2, 0x1C($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
            goto L_800B489C;
    }
    goto skip_3;
    // 0x800B4888: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    skip_3:
    // 0x800B488C: div.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800B4890: b           L_800B48C8
    // 0x800B4894: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_800B48C8;
    // 0x800B4894: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800B4898: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
L_800B489C:
    // 0x800B489C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B48A0: nop

    // 0x800B48A4: bc1fl       L_800B48B8
    if (!c1cs) {
        // 0x800B48A8: sub.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B48B8;
    }
    goto skip_4;
    // 0x800B48A8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800B48AC: b           L_800B48C8
    // 0x800B48B0: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
        goto L_800B48C8;
    // 0x800B48B0: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
    // 0x800B48B4: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
L_800B48B8:
    // 0x800B48B8: sub.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x800B48BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B48C0: sub.s       $f18, $f22, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x800B48C4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_800B48C8:
    // 0x800B48C8: lh          $t4, 0x34($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X34);
    // 0x800B48CC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800B48D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B48D4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B48D8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800B48DC: lh          $t7, 0x32($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X32);
    // 0x800B48E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B48E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B48E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B48EC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B48F0: nop

    // 0x800B48F4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B48F8: nop

    // 0x800B48FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B4900: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B4904: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800B4908: nop

    // 0x800B490C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B4910: sh          $t8, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r24;
    // 0x800B4914: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800B4918: bne         $t9, $at, L_800B49DC
    if (ctx->r25 != ctx->r1) {
        // 0x800B491C: nop
    
            goto L_800B49DC;
    }
    // 0x800B491C: nop

    // 0x800B4920: lbu         $v0, 0x52($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X52);
    // 0x800B4924: beql        $v0, $zero, L_800B49E0
    if (ctx->r2 == 0) {
        // 0x800B4928: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800B49E0;
    }
    goto skip_5;
    // 0x800B4928: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_5:
    // 0x800B492C: beq         $v0, $s5, L_800B4944
    if (ctx->r2 == ctx->r21) {
        // 0x800B4930: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B4944;
    }
    // 0x800B4930: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B4934: beql        $v0, $at, L_800B4994
    if (ctx->r2 == ctx->r1) {
        // 0x800B4938: lh          $t9, 0x2E($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X2E);
            goto L_800B4994;
    }
    goto skip_6;
    // 0x800B4938: lh          $t9, 0x2E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2E);
    skip_6:
    // 0x800B493C: b           L_800B49E0
    // 0x800B4940: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B49E0;
    // 0x800B4940: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B4944:
    // 0x800B4944: lh          $t1, 0x2E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2E);
    // 0x800B4948: lh          $t0, 0x2C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2C);
    // 0x800B494C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800B4950: nop

    // 0x800B4954: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B4958: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    tooie_particle_whole(rdram, ctx, 0);
    // 0x800B495C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B4960: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800B4964: nop

    // 0x800B4968: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800B496C: sh          $t4, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r12;
    // 0x800B4970: lh          $t5, 0x2C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2C);
    // 0x800B4974: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x800B4978: sra         $t7, $t5, 8
    ctx->r15 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B497C: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B4980: bnel        $at, $zero, L_800B49E0
    if (ctx->r1 != 0) {
        // 0x800B4984: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800B49E0;
    }
    goto skip_7;
    // 0x800B4984: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_7:
    // 0x800B4988: b           L_800B49DC
    // 0x800B498C: sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
        goto L_800B49DC;
    // 0x800B498C: sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // 0x800B4990: lh          $t9, 0x2E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2E);
L_800B4994:
    // 0x800B4994: lh          $t8, 0x2C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2C);
    // 0x800B4998: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B499C: nop

    // 0x800B49A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B49A4: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    tooie_particle_whole(rdram, ctx, 1);
    // 0x800B49A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B49AC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800B49B0: nop

    // 0x800B49B4: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x800B49B8: sh          $t0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r8;
    // 0x800B49BC: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
    // 0x800B49C0: lbu         $v0, 0xB($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB);
    // 0x800B49C4: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800B49C8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B49CC: bne         $at, $zero, L_800B49DC
    if (ctx->r1 != 0) {
        // 0x800B49D0: sll         $t5, $v0, 8
        ctx->r13 = S32(ctx->r2 << 8);
            goto L_800B49DC;
    }
    // 0x800B49D0: sll         $t5, $v0, 8
    ctx->r13 = S32(ctx->r2 << 8);
    // 0x800B49D4: addiu       $t7, $t5, -0x100
    ctx->r15 = ADD32(ctx->r13, -0X100);
    // 0x800B49D8: sh          $t7, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r15;
L_800B49DC:
    // 0x800B49DC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B49E0:
    // 0x800B49E0: lh          $t9, 0x26($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X26);
    // 0x800B49E4: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B49E8: lh          $t2, 0x20($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X20);
    // 0x800B49EC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800B49F0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800B49F4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B49F8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B49FC: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800B4A00: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800B4A04: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B4A08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B4A0C: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800B4A10: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800B4A14: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800B4A18: nop

    // 0x800B4A1C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    tooie_particle_whole(rdram, ctx, 2);
    // 0x800B4A20: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B4A24: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800B4A28: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B4A2C: nop

    // 0x800B4A30: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x800B4A34: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800B4A38: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B4A3C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x800B4A40: lh          $t3, -0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X2);
    // 0x800B4A44: lh          $t0, 0x24($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X24);
    // 0x800B4A48: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800B4A4C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800B4A50: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B4A54: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B4A58: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800B4A5C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    tooie_particle_whole(rdram, ctx, 3);
    // 0x800B4A60: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800B4A64: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800B4A68: bne         $at, $zero, L_800B49E0
    if (ctx->r1 != 0) {
        // 0x800B4A6C: sh          $t5, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r13;
            goto L_800B49E0;
    }
    // 0x800B4A6C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x800B4A70: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B4A74: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x800B4A78: beql        $t7, $zero, L_800B4AF4
    if (ctx->r15 == 0) {
        // 0x800B4A7C: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_800B4AF4;
    }
    goto skip_8;
    // 0x800B4A7C: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    skip_8:
    // 0x800B4A80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B4A84: lh          $t6, 0x26($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X26);
    // 0x800B4A88: lwc1        $f16, 0xD0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XD0);
    tooie_particle_drag(rdram, ctx, 0);
    // 0x800B4A8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4A90: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x800B4A94: nop

    // 0x800B4A98: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800B4A9C: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800B4AA0: beql        $a0, $s2, L_800B4ADC
    if (ctx->r4 == ctx->r18) {
        // 0x800B4AA4: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_800B4ADC;
    }
    goto skip_9;
    // 0x800B4AA4: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_9:
    // 0x800B4AA8: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_800B4AAC:
    // 0x800B4AAC: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x800B4AB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4AB4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800B4AB8: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x800B4ABC: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800B4AC0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800B4AC4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x800B4AC8: lwc1        $f16, 0xD0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XD0);
    tooie_particle_drag(rdram, ctx, 0);
    // 0x800B4ACC: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800B4AD0: bnel        $a0, $s2, L_800B4AAC
    if (ctx->r4 != ctx->r18) {
        // 0x800B4AD4: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_800B4AAC;
    }
    goto skip_10;
    // 0x800B4AD4: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_10:
    // 0x800B4AD8: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_800B4ADC:
    // 0x800B4ADC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800B4AE0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800B4AE4: nop

    // 0x800B4AE8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x800B4AEC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B4AF0: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
L_800B4AF4:
    // 0x800B4AF4: beq         $t8, $zero, L_800B4B40
    if (ctx->r24 == 0) {
        // 0x800B4AF8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B4B40;
    }
    // 0x800B4AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B4AFC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B4B00: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B4B04: lwc1        $f14, 0xD0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XD0);
    tooie_particle_drag(rdram, ctx, 1);
    // 0x800B4B08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4B0C: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800B4B10: beql        $a0, $s2, L_800B4B3C
    if (ctx->r4 == ctx->r18) {
        // 0x800B4B14: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800B4B3C;
    }
    goto skip_11;
    // 0x800B4B14: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_11:
    // 0x800B4B18: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
L_800B4B1C:
    // 0x800B4B1C: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x800B4B20: lwc1        $f14, 0xD0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XD0);
    tooie_particle_drag(rdram, ctx, 1);
    // 0x800B4B24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4B28: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B4B2C: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800B4B30: bnel        $a0, $s2, L_800B4B1C
    if (ctx->r4 != ctx->r18) {
        // 0x800B4B34: lwc1        $f16, 0x14($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
            goto L_800B4B1C;
    }
    goto skip_12;
    // 0x800B4B34: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    skip_12:
    // 0x800B4B38: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800B4B3C:
    // 0x800B4B3C: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
L_800B4B40:
    // 0x800B4B40: lw          $a0, 0x88($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X88);
    // 0x800B4B44: beql        $a0, $zero, L_800B4B64
    if (ctx->r4 == 0) {
        // 0x800B4B48: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800B4B64;
    }
    goto skip_13;
    // 0x800B4B48: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_13:
    // 0x800B4B4C: jal         0x80088E50
    // 0x800B4B50: nop

    _idwater_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800B4B50: nop

    after_2:
    // 0x800B4B54: lh          $t2, 0x98($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X98);
    // 0x800B4B58: addu        $t0, $v0, $t2
    ctx->r8 = ADD32(ctx->r2, ctx->r10);
    // 0x800B4B5C: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x800B4B60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800B4B64:
    // 0x800B4B64: jal         0x800EE88C
    // 0x800B4B68: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x800B4B68: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800B4B6C: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
    // 0x800B4B70: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B4B74: beql        $t4, $zero, L_800B4BC0
    if (ctx->r12 == 0) {
        // 0x800B4B78: lbu         $t0, 0x39($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X39);
            goto L_800B4BC0;
    }
    goto skip_14;
    // 0x800B4B78: lbu         $t0, 0x39($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X39);
    skip_14:
    // 0x800B4B7C: lb          $t7, 0x39($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X39);
    // 0x800B4B80: bltzl       $t7, L_800B4BC0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B4B84: lbu         $t0, 0x39($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X39);
            goto L_800B4BC0;
    }
    goto skip_15;
    // 0x800B4B84: lbu         $t0, 0x39($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X39);
    skip_15:
    // 0x800B4B88: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    // 0x800B4B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4B90: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800B4B94: addiu       $a1, $t6, -0x3C
    ctx->r5 = ADD32(ctx->r14, -0X3C);
    // 0x800B4B98: jal         0x8001BBA0
    // 0x800B4B9C: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    rare_memcpy(rdram, ctx);
        goto after_4;
    // 0x800B4B9C: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    after_4:
    // 0x800B4BA0: lbu         $t1, 0x7($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X7);
    // 0x800B4BA4: bnel        $s5, $t1, L_800B4ED0
    if (ctx->r21 != ctx->r9) {
        // 0x800B4BA8: lw          $t6, 0x90($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X90);
            goto L_800B4ED0;
    }
    goto skip_16;
    // 0x800B4BA8: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    skip_16:
    // 0x800B4BAC: lw          $t8, 0x94($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X94);
    // 0x800B4BB0: addiu       $t2, $t8, -0x3C
    ctx->r10 = ADD32(ctx->r24, -0X3C);
    // 0x800B4BB4: b           L_800B4ECC
    // 0x800B4BB8: sw          $t2, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r10;
        goto L_800B4ECC;
    // 0x800B4BB8: sw          $t2, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r10;
    // 0x800B4BBC: lbu         $t0, 0x39($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X39);
L_800B4BC0:
    // 0x800B4BC0: lbu         $t4, 0x38($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X38);
    // 0x800B4BC4: andi        $t3, $t0, 0xFF7F
    ctx->r11 = ctx->r8 & 0XFF7F;
    // 0x800B4BC8: blez        $t4, L_800B4EC8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B4BCC: sb          $t3, 0x39($s0)
        MEM_B(0X39, ctx->r16) = ctx->r11;
            goto L_800B4EC8;
    }
    // 0x800B4BCC: sb          $t3, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r11;
    // 0x800B4BD0: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800B4BD4: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800B4BD8: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800B4BDC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B4BE0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800B4BE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B4BE8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B4BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B4BF0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800B4BF4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B4BF8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B4BFC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B4C00: nop

    // 0x800B4C04: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B4C08: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B4C0C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800B4C10: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B4C14: jal         0x800EFA4C
    // 0x800B4C18: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x800B4C18: nop

    after_5:
    // 0x800B4C1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B4C20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B4C24: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x800B4C28: jal         0x800B46B0
    // 0x800B4C2C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_800B46B0(rdram, ctx);
        goto after_6;
    // 0x800B4C2C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x800B4C30: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800B4C34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B4C38: jal         0x800EE940
    // 0x800B4C3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE940(rdram, ctx);
        goto after_7;
    // 0x800B4C3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_7:
    // 0x800B4C40: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800B4C44: beql        $t9, $zero, L_800B4ECC
    if (ctx->r25 == 0) {
        // 0x800B4C48: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_800B4ECC;
    }
    goto skip_17;
    // 0x800B4C48: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_17:
    // 0x800B4C4C: lh          $t1, 0xAA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XAA);
    // 0x800B4C50: beql        $t1, $zero, L_800B4D04
    if (ctx->r9 == 0) {
        // 0x800B4C54: lh          $t3, 0x8($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8);
            goto L_800B4D04;
    }
    goto skip_18;
    // 0x800B4C54: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
    skip_18:
    // 0x800B4C58: lh          $t8, 0x28($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X28);
    // 0x800B4C5C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800B4C60: jal         0x800F2100
    // 0x800B4C64: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    mlAbsF(rdram, ctx);
        goto after_8;
    // 0x800B4C64: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_8:
    // 0x800B4C68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B4C6C: lwc1        $f6, 0x5630($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5630);
    // 0x800B4C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B4C74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B4C78: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B4C7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4C80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B4C84: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800B4C88: nop

    // 0x800B4C8C: bc1f        L_800B4C9C
    if (!c1cs) {
        // 0x800B4C90: nop
    
            goto L_800B4C9C;
    }
    // 0x800B4C90: nop

    // 0x800B4C94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B4C98: nop

L_800B4C9C:
    // 0x800B4C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B4CA0: lwc1        $f8, 0x7F14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F14);
    // 0x800B4CA4: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x800B4CA8: nop

    // 0x800B4CAC: bc1fl       L_800B4D04
    if (!c1cs) {
        // 0x800B4CB0: lh          $t3, 0x8($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8);
            goto L_800B4D04;
    }
    goto skip_19;
    // 0x800B4CB0: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
    skip_19:
    // 0x800B4CB4: lwc1        $f12, 0xB4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x800B4CB8: lwc1        $f14, 0xB8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x800B4CBC: jal         0x800DC178
    // 0x800B4CC0: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x800B4CC0: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x800B4CC4: lw          $t2, 0xBC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XBC);
    // 0x800B4CC8: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B4CCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B4CD0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800B4CD4: lh          $a0, 0xAA($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XAA);
    // 0x800B4CD8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B4CDC: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800B4CE0: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B4CE4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B4CE8: jal         0x800C3FC0
    // 0x800B4CEC: nop

    func_800C3FC0(rdram, ctx);
        goto after_10;
    // 0x800B4CEC: nop

    after_10:
    // 0x800B4CF0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800B4CF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B4CF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B4CFC: swc1        $f8, 0x7F14($at)
    MEM_W(0X7F14, ctx->r1) = ctx->f8.u32l;
    // 0x800B4D00: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
L_800B4D04:
    // 0x800B4D04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B4D08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B4D0C: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800B4D10: sh          $t4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r12;
    // 0x800B4D14: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B4D18: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B4D1C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800B4D20: lh          $t5, 0x28($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X28);
    // 0x800B4D24: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800B4D28: jal         0x800F2100
    // 0x800B4D2C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    mlAbsF(rdram, ctx);
        goto after_11;
    // 0x800B4D2C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_11:
    // 0x800B4D30: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4D34: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800B4D38: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4D3C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B4D40: nop

    // 0x800B4D44: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    // 0x800B4D48: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B4D4C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800B4D50: beql        $t9, $zero, L_800B4DAC
    if (ctx->r25 == 0) {
        // 0x800B4D54: andi        $t5, $v0, 0x2
        ctx->r13 = ctx->r2 & 0X2;
            goto L_800B4DAC;
    }
    goto skip_20;
    // 0x800B4D54: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    skip_20:
    // 0x800B4D58: lh          $t1, 0x26($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X26);
    // 0x800B4D5C: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4D60: lh          $t0, 0x2A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2A);
    // 0x800B4D64: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800B4D68: nop

    // 0x800B4D6C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4D70: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B4D74: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4D78: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4D7C: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4D80: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B4D84: nop

    // 0x800B4D88: sh          $t2, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r10;
    // 0x800B4D8C: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4D90: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4D94: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4D98: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800B4D9C: nop

    // 0x800B4DA0: sh          $t4, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r12;
    // 0x800B4DA4: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B4DA8: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
L_800B4DAC:
    // 0x800B4DAC: bnel        $t5, $zero, L_800B4E04
    if (ctx->r13 != 0) {
        // 0x800B4DB0: lh          $t0, 0x20($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X20);
            goto L_800B4E04;
    }
    goto skip_21;
    // 0x800B4DB0: lh          $t0, 0x20($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X20);
    skip_21:
    // 0x800B4DB4: lh          $t7, 0x32($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X32);
    // 0x800B4DB8: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4DBC: lh          $t1, 0x34($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X34);
    // 0x800B4DC0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B4DC4: nop

    // 0x800B4DC8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4DCC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800B4DD0: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4DD4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4DD8: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4DDC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B4DE0: nop

    // 0x800B4DE4: sh          $t9, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r25;
    // 0x800B4DE8: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4DEC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4DF0: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4DF4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B4DF8: nop

    // 0x800B4DFC: sh          $t2, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r10;
    // 0x800B4E00: lh          $t0, 0x20($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X20);
L_800B4E04:
    // 0x800B4E04: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4E08: lh          $t5, 0x22($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X22);
    // 0x800B4E0C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B4E10: lh          $t9, 0x24($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X24);
    // 0x800B4E14: lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X38);
    // 0x800B4E18: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4E1C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B4E20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B4E24: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800B4E28: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4E2C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4E30: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B4E34: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4E38: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800B4E3C: nop

    // 0x800B4E40: sh          $t4, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r12;
    // 0x800B4E44: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4E48: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4E4C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4E50: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4E54: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B4E58: nop

    // 0x800B4E5C: sh          $t6, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r14;
    // 0x800B4E60: lwc1        $f8, 0xB0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x800B4E64: sb          $t2, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r10;
    // 0x800B4E68: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B4E6C: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B4E70: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800B4E74: bne         $t2, $zero, L_800B4EC8
    if (ctx->r10 != 0) {
        // 0x800B4E78: sh          $t8, 0x24($s0)
        MEM_H(0X24, ctx->r16) = ctx->r24;
            goto L_800B4EC8;
    }
    // 0x800B4E78: sh          $t8, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r24;
    // 0x800B4E7C: lw          $v0, 0xC0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC0);
    // 0x800B4E80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B4E84: beql        $v0, $zero, L_800B4E98
    if (ctx->r2 == 0) {
        // 0x800B4E88: lw          $t0, 0x90($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X90);
            goto L_800B4E98;
    }
    goto skip_22;
    // 0x800B4E88: lw          $t0, 0x90($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X90);
    skip_22:
    // 0x800B4E8C: jalr        $v0
    // 0x800B4E90: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_12;
    // 0x800B4E90: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_12:
    // 0x800B4E94: lw          $t0, 0x90($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X90);
L_800B4E98:
    // 0x800B4E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4E9C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800B4EA0: addiu       $a1, $t0, -0x3C
    ctx->r5 = ADD32(ctx->r8, -0X3C);
    // 0x800B4EA4: jal         0x8001BBA0
    // 0x800B4EA8: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    rare_memcpy(rdram, ctx);
        goto after_13;
    // 0x800B4EA8: sw          $a1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r5;
    after_13:
    // 0x800B4EAC: lbu         $t4, 0x7($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X7);
    // 0x800B4EB0: bnel        $s5, $t4, L_800B4ED0
    if (ctx->r21 != ctx->r12) {
        // 0x800B4EB4: lw          $t6, 0x90($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X90);
            goto L_800B4ED0;
    }
    goto skip_23;
    // 0x800B4EB4: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    skip_23:
    // 0x800B4EB8: lw          $t5, 0x94($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X94);
    // 0x800B4EBC: addiu       $t7, $t5, -0x3C
    ctx->r15 = ADD32(ctx->r13, -0X3C);
    // 0x800B4EC0: b           L_800B4ECC
    // 0x800B4EC4: sw          $t7, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r15;
        goto L_800B4ECC;
    // 0x800B4EC4: sw          $t7, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r15;
L_800B4EC8:
    // 0x800B4EC8: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_800B4ECC:
    // 0x800B4ECC: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
L_800B4ED0:
    // 0x800B4ED0: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x800B4ED4: bnel        $at, $zero, L_800B47FC
    if (ctx->r1 != 0) {
        // 0x800B4ED8: lh          $t8, 0x36($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X36);
            goto L_800B47FC;
    }
    goto skip_24;
    // 0x800B4ED8: lh          $t8, 0x36($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X36);
    skip_24:
L_800B4EDC:
    // 0x800B4EDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B4EE0: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800B4EE4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800B4EE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B4EEC: nop

    // 0x800B4EF0: bc1fl       L_800B4F20
    if (!c1cs) {
        // 0x800B4EF4: lbu         $v0, 0x7($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X7);
            goto L_800B4F20;
    }
    goto skip_25;
    // 0x800B4EF4: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    skip_25:
    // 0x800B4EF8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800B4EFC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800B4F00: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x800B4F04: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800B4F08: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x800B4F0C: nop

    // 0x800B4F10: bc1fl       L_800B4F20
    if (!c1cs) {
        // 0x800B4F14: lbu         $v0, 0x7($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X7);
            goto L_800B4F20;
    }
    goto skip_26;
    // 0x800B4F14: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    skip_26:
    // 0x800B4F18: sb          $t9, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r25;
    // 0x800B4F1C: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
L_800B4F20:
    // 0x800B4F20: beql        $v0, $zero, L_800B4F3C
    if (ctx->r2 == 0) {
        // 0x800B4F24: lwc1        $f8, 0x20($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
            goto L_800B4F3C;
    }
    goto skip_27;
    // 0x800B4F24: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    skip_27:
    // 0x800B4F28: beql        $v0, $s5, L_800B4F94
    if (ctx->r2 == ctx->r21) {
        // 0x800B4F2C: lwc1        $f4, 0x20($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
            goto L_800B4F94;
    }
    goto skip_28;
    // 0x800B4F2C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    skip_28:
    // 0x800B4F30: b           L_800B5000
    // 0x800B4F34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800B5000;
    // 0x800B4F34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F38: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
L_800B4F3C:
    // 0x800B4F3C: sub.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800B4F40: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x800B4F44: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800B4F48: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x800B4F4C: nop

    // 0x800B4F50: bc1fl       L_800B5000
    if (!c1cs) {
        // 0x800B4F54: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800B5000;
    }
    goto skip_29;
    // 0x800B4F54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_29:
    // 0x800B4F58: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800B4F5C: jal         0x800DC178
    // 0x800B4F60: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x800B4F60: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    after_14:
    // 0x800B4F64: lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X90);
    // 0x800B4F68: lw          $t1, 0x94($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X94);
    // 0x800B4F6C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800B4F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B4F74: sltu        $at, $a1, $t1
    ctx->r1 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x800B4F78: beq         $at, $zero, L_800B4FFC
    if (ctx->r1 == 0) {
        // 0x800B4F7C: addiu       $t8, $a1, 0x3C
        ctx->r24 = ADD32(ctx->r5, 0X3C);
            goto L_800B4FFC;
    }
    // 0x800B4F7C: addiu       $t8, $a1, 0x3C
    ctx->r24 = ADD32(ctx->r5, 0X3C);
    // 0x800B4F80: jal         0x800B9B50
    // 0x800B4F84: sw          $t8, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r24;
    func_800B9B50(rdram, ctx);
        goto after_15;
    // 0x800B4F84: sw          $t8, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r24;
    after_15:
    // 0x800B4F88: b           L_800B5000
    // 0x800B4F8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800B5000;
    // 0x800B4F8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F90: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
L_800B4F94:
    // 0x800B4F94: sub.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800B4F98: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x800B4F9C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800B4FA0: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800B4FA4: nop

    // 0x800B4FA8: bc1fl       L_800B5000
    if (!c1cs) {
        // 0x800B4FAC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800B5000;
    }
    goto skip_30;
    // 0x800B4FAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_30:
    // 0x800B4FB0: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800B4FB4: jal         0x800DC178
    // 0x800B4FB8: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x800B4FB8: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    after_16:
    // 0x800B4FBC: lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X90);
    // 0x800B4FC0: lw          $t2, 0x94($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X94);
    // 0x800B4FC4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800B4FC8: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800B4FCC: subu        $t0, $t2, $a1
    ctx->r8 = SUB32(ctx->r10, ctx->r5);
    // 0x800B4FD0: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800B4FD4: mflo        $t3
    ctx->r11 = lo;
    // 0x800B4FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B4FDC: blez        $t3, L_800B4FF8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B4FE0: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_800B4FF8;
    }
    // 0x800B4FE0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800B4FE4: addiu       $t4, $a1, 0x3C
    ctx->r12 = ADD32(ctx->r5, 0X3C);
    // 0x800B4FE8: jal         0x800B9B50
    // 0x800B4FEC: sw          $t4, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r12;
    func_800B9B50(rdram, ctx);
        goto after_17;
    // 0x800B4FEC: sw          $t4, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r12;
    after_17:
    // 0x800B4FF0: b           L_800B5000
    // 0x800B4FF4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800B5000;
    // 0x800B4FF4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800B4FF8:
    // 0x800B4FF8: sb          $t5, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r13;
L_800B4FFC:
    // 0x800B4FFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800B5000:
    // 0x800B5000: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B5004: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800B5008: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800B500C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800B5010: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5014: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800B5018: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800B501C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800B5020: jr          $ra
    // 0x800B5024: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B5024: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_808023AC_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808023B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023B4: jal         0x808026A0
    // 0x808023B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808026A0_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x808023B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808023BC: jal         0x800EA05C
    // 0x808023C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808023C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808023C4: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808023C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808023CC: beq         $v0, $at, L_808023E4
    if (ctx->r2 == ctx->r1) {
        // 0x808023D0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808023E4;
    }
    // 0x808023D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808023D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808023D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808023DC: b           L_808023F4
    // 0x808023E0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
        goto L_808023F4;
    // 0x808023E0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_808023E4:
    // 0x808023E4: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x808023E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808023EC: nop

    // 0x808023F0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_808023F4:
    // 0x808023F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808023F8: beql        $a1, $at, L_8080240C
    if (ctx->r5 == ctx->r1) {
        // 0x808023FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080240C;
    }
    goto skip_0;
    // 0x808023FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802400: jal         0x8080282C
    // 0x80802404: nop

    func_8080282C_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80802404: nop

    after_2:
    // 0x80802408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080240C:
    // 0x8080240C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802410: jr          $ra
    // 0x80802414: nop

    return;
    // 0x80802414: nop

;}
RECOMP_FUNC void func_808015A4_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015A4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808015A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808015AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808015B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808015B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808015B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808015BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015C0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808015C4: jal         0x80100094
    // 0x808015C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808015C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808015CC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808015D0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x808015D4: jal         0x80088368
    // 0x808015D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808015D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x808015DC: blez        $v0, L_80801638
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808015E0: addiu       $s2, $s4, 0x4DC
        ctx->r18 = ADD32(ctx->r20, 0X4DC);
            goto L_80801638;
    }
    // 0x808015E0: addiu       $s2, $s4, 0x4DC
    ctx->r18 = ADD32(ctx->r20, 0X4DC);
    // 0x808015E4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x808015E8: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x808015EC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x808015F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808015F4:
    // 0x808015F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808015F8: jal         0x800899A8
    // 0x808015FC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808015FC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x80801600: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801604: beq         $at, $zero, L_80801610
    if (ctx->r1 == 0) {
        // 0x80801608: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80801610;
    }
    // 0x80801608: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8080160C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80801610:
    // 0x80801610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801614: jal         0x800AA20C
    // 0x80801618: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800AA20C(rdram, ctx);
        goto after_3;
    // 0x80801618: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080161C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801620: jal         0x80088368
    // 0x80801624: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801624: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801628: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080162C: bnel        $at, $zero, L_808015F4
    if (ctx->r1 != 0) {
        // 0x80801630: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808015F4;
    }
    goto skip_0;
    // 0x80801630: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80801634: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801638:
    // 0x80801638: jal         0x80088368
    // 0x8080163C: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x8080163C: nop

    after_5:
    // 0x80801640: blez        $v0, L_80801684
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801644: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_80801684;
    }
    // 0x80801644: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80801648: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x8080164C: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80801650: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80801654:
    // 0x80801654: addiu       $a0, $s4, 0x4DC
    ctx->r4 = ADD32(ctx->r20, 0X4DC);
    // 0x80801658: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080165C: bne         $s3, $t0, L_8080166C
    if (ctx->r19 != ctx->r8) {
        // 0x80801660: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_8080166C;
    }
    // 0x80801660: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801664: jal         0x800899C0
    // 0x80801668: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    _sumultiscore_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80801668: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_6:
L_8080166C:
    // 0x8080166C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801670: jal         0x80088368
    // 0x80801674: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80801674: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801678: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080167C: bnel        $at, $zero, L_80801654
    if (ctx->r1 != 0) {
        // 0x80801680: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_80801654;
    }
    goto skip_1;
    // 0x80801680: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80801684:
    // 0x80801684: jal         0x80088368
    // 0x80801688: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801688: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_8:
    // 0x8080168C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80801690: bne         $at, $zero, L_8080170C
    if (ctx->r1 != 0) {
        // 0x80801694: addiu       $s2, $sp, 0x5C
        ctx->r18 = ADD32(ctx->r29, 0X5C);
            goto L_8080170C;
    }
    // 0x80801694: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x80801698: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8080169C:
    // 0x8080169C: blez        $s0, L_808016F8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808016A0: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_808016F8;
    }
    // 0x808016A0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x808016A4: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x808016A8: addu        $v0, $s2, $t1
    ctx->r2 = ADD32(ctx->r18, ctx->r9);
    // 0x808016AC: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x808016B0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x808016B4: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x808016B8: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x808016BC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808016C0: beq         $at, $zero, L_808016F8
    if (ctx->r1 == 0) {
        // 0x808016C4: nop
    
            goto L_808016F8;
    }
    // 0x808016C4: nop

    // 0x808016C8: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x808016CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808016D0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_808016D4:
    // 0x808016D4: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x808016D8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x808016DC: bne         $at, $zero, L_808016F8
    if (ctx->r1 != 0) {
        // 0x808016E0: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_808016F8;
    }
    // 0x808016E0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x808016E4: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x808016E8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808016EC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808016F0: bnel        $at, $zero, L_808016D4
    if (ctx->r1 != 0) {
        // 0x808016F4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_808016D4;
    }
    goto skip_2;
    // 0x808016F4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    skip_2:
L_808016F8:
    // 0x808016F8: jal         0x80088368
    // 0x808016FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x808016FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_9:
    // 0x80801700: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801704: bne         $at, $zero, L_8080169C
    if (ctx->r1 != 0) {
        // 0x80801708: addiu       $a2, $sp, 0x60
        ctx->r6 = ADD32(ctx->r29, 0X60);
            goto L_8080169C;
    }
    // 0x80801708: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8080170C:
    // 0x8080170C: jal         0x800FC6B0
    // 0x80801710: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x80801710: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x80801714: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80801718: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8080171C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801720: addiu       $s2, $s4, 0x4DC
    ctx->r18 = ADD32(ctx->r20, 0X4DC);
    // 0x80801724: beq         $t5, $t6, L_80801774
    if (ctx->r13 == ctx->r14) {
        // 0x80801728: addiu       $s0, $zero, 0x10CE
        ctx->r16 = ADD32(0, 0X10CE);
            goto L_80801774;
    }
    // 0x80801728: addiu       $s0, $zero, 0x10CE
    ctx->r16 = ADD32(0, 0X10CE);
    // 0x8080172C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801734: jal         0x800899A8
    // 0x80801738: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80801738: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_11:
    // 0x8080173C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80801740: beql        $v0, $t7, L_8080176C
    if (ctx->r2 == ctx->r15) {
        // 0x80801744: sw          $s1, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->r17;
            goto L_8080176C;
    }
    goto skip_3;
    // 0x80801744: sw          $s1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r17;
    skip_3:
    // 0x80801748: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080174C:
    // 0x8080174C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801750: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801754: jal         0x800899A8
    // 0x80801758: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x80801758: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_12:
    // 0x8080175C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80801760: bnel        $v0, $t8, L_8080174C
    if (ctx->r2 != ctx->r24) {
        // 0x80801764: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080174C;
    }
    goto skip_4;
    // 0x80801764: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80801768: sw          $s1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r17;
L_8080176C:
    // 0x8080176C: b           L_80801774
    // 0x80801770: addiu       $s0, $zero, 0x10CD
    ctx->r16 = ADD32(0, 0X10CD);
        goto L_80801774;
    // 0x80801770: addiu       $s0, $zero, 0x10CD
    ctx->r16 = ADD32(0, 0X10CD);
L_80801774:
    // 0x80801774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801778: jal         0x8008A090
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801780: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801784: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801788: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8080178C: sw          $s0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r16;
    // 0x80801790: sw          $t9, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r25;
    // 0x80801794: swc1        $f4, 0x9F8($s4)
    MEM_W(0X9F8, ctx->r20) = ctx->f4.u32l;
    // 0x80801798: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8080179C: jal         0x80101FDC
    // 0x808017A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808017A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x808017A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808017A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808017B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808017B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808017B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808017BC: jr          $ra
    // 0x808017C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808017C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _gsproplookup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C88: syscall     732
    recomp_syscall_handler(rdram, ctx, 0x80088C88);
    return;
    // 0x80088C8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chbounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: jal         0x80800190
    // 0x80800670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800190_chbounce(rdram, ctx);
        goto after_0;
    // 0x80800670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void func_808022E4_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808022E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808022EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808022F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808022F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808022F8: jal         0x80106790
    // 0x808022FC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808022FC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802300: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80802304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802308: jal         0x80100094
    // 0x8080230C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080230C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802310: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80802314: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80802318: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8080231C: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x80802320: beq         $t6, $at, L_80802360
    if (ctx->r14 == ctx->r1) {
        // 0x80802324: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80802360;
    }
    // 0x80802324: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80802328: beq         $t6, $at, L_80802340
    if (ctx->r14 == ctx->r1) {
        // 0x8080232C: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80802340;
    }
    // 0x8080232C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80802330: beq         $t6, $at, L_80802350
    if (ctx->r14 == ctx->r1) {
        // 0x80802334: nop
    
            goto L_80802350;
    }
    // 0x80802334: nop

    // 0x80802338: b           L_8080236C
    // 0x8080233C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080236C;
    // 0x8080233C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802340:
    // 0x80802340: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80802344: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80802348: b           L_80802368
    // 0x8080234C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80802368;
    // 0x8080234C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80802350:
    // 0x80802350: jal         0x808009F4
    // 0x80802354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80802354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80802358: b           L_8080236C
    // 0x8080235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080236C;
    // 0x8080235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802360:
    // 0x80802360: jal         0x80090708
    // 0x80802364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x80802364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_80802368:
    // 0x80802368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080236C:
    // 0x8080236C: jal         0x80102424
    // 0x80802370: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80802370: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80802374: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80802378: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x8080237C: addiu       $t2, $t1, -0x5
    ctx->r10 = ADD32(ctx->r9, -0X5);
    // 0x80802380: sltiu       $at, $t2, 0x13
    ctx->r1 = ctx->r10 < 0X13 ? 1 : 0;
    // 0x80802384: beq         $at, $zero, L_808026C4
    if (ctx->r1 == 0) {
        // 0x80802388: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808026C4;
    }
    // 0x80802388: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080238C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X37C4) << 16);
    // 0x80802390: addu        $at, $at, $t2
    gpr jr_addend_80802398 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80802394: lw          $t2, 0x37C4($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37C4));
    // 0x80802398: jr          $t2
    // 0x8080239C: nop

    switch (jr_addend_80802398 >> 2) {
        case 0: goto L_808023F0; break;
        case 1: goto L_80802434; break;
        case 2: goto L_8080246C; break;
        case 3: goto L_80802484; break;
        case 4: goto L_808024EC; break;
        case 5: goto L_808024FC; break;
        case 6: goto L_808026C4; break;
        case 7: goto L_808026C4; break;
        case 8: goto L_808026C4; break;
        case 9: goto L_80802564; break;
        case 10: goto L_808025D4; break;
        case 11: goto L_80802574; break;
        case 12: goto L_808026C4; break;
        case 13: goto L_80802684; break;
        case 14: goto L_808023A0; break;
        case 15: goto L_808023B0; break;
        case 16: goto L_808026C4; break;
        case 17: goto L_808026C4; break;
        case 18: goto L_808023E0; break;
        default: switch_error(__func__, 0x80802398, 0x808037C4);
    }
    // 0x8080239C: nop

L_808023A0:
    // 0x808023A0: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808023A4: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808023A8: b           L_808026C4
    // 0x808023AC: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_808026C4;
    // 0x808023AC: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808023B0:
    // 0x808023B0: jal         0x800DA544
    // 0x808023B4: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808023B4: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    after_5:
    // 0x808023B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808023BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808023C0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x808023C4: addiu       $a2, $zero, 0x20B0
    ctx->r6 = ADD32(0, 0X20B0);
    // 0x808023C8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808023CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808023D0: jal         0x80800850
    // 0x808023D4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_80800850_chclockworkmouse(rdram, ctx);
        goto after_6;
    // 0x808023D4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x808023D8: b           L_808026C4
    // 0x808023DC: nop

        goto L_808026C4;
    // 0x808023DC: nop

L_808023E0:
    // 0x808023E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808023E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808023E8: b           L_808026C4
    // 0x808023EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808026C4;
    // 0x808023EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808023F0:
    // 0x808023F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808023F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808023F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808023FC: jal         0x808008DC
    // 0x80802400: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x80802400: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_7:
    // 0x80802404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802408: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x8080240C: jal         0x80801B44
    // 0x80802410: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_8;
    // 0x80802410: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x80802414: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80802418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080241C: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80802420: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802424: jal         0x801058C4
    // 0x80802428: lh          $a1, 0xC($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XC);
    func_801058C4(rdram, ctx);
        goto after_9;
    // 0x80802428: lh          $a1, 0xC($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XC);
    after_9:
    // 0x8080242C: b           L_808026C4
    // 0x80802430: nop

        goto L_808026C4;
    // 0x80802430: nop

L_80802434:
    // 0x80802434: jal         0x800FDC28
    // 0x80802438: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800FDC28(rdram, ctx);
        goto after_10;
    // 0x80802438: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_10:
    // 0x8080243C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80802440: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80802444: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80802448: bgezl       $t8, L_80802464
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080244C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80802464;
    }
    goto skip_0;
    // 0x8080244C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80802450: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80802454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802458: b           L_808026C4
    // 0x8080245C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_808026C4;
    // 0x8080245C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80802460: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80802464:
    // 0x80802464: b           L_808026C4
    // 0x80802468: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_808026C4;
    // 0x80802468: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_8080246C:
    // 0x8080246C: jal         0x80800024
    // 0x80802470: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800024_chclockworkmouse(rdram, ctx);
        goto after_11;
    // 0x80802470: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80802474: jal         0x80090658
    // 0x80802478: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_12;
    // 0x80802478: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x8080247C: b           L_808026C4
    // 0x80802480: nop

        goto L_808026C4;
    // 0x80802480: nop

L_80802484:
    // 0x80802484: jal         0x80105AE8
    // 0x80802488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105AE8(rdram, ctx);
        goto after_13;
    // 0x80802488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080248C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3810) << 16);
    // 0x80802490: lwc1        $f10, 0x3810($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3810));
    // 0x80802494: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802498: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080249C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808024A0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808024A4: bc1f        L_808024DC
    if (!c1cs) {
        // 0x808024A8: nop
    
            goto L_808024DC;
    }
    // 0x808024A8: nop

    // 0x808024AC: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808024B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808024B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808024B8: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808024BC: bgez        $t1, L_808024CC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808024C0: nop
    
            goto L_808024CC;
    }
    // 0x808024C0: nop

    // 0x808024C4: b           L_808024CC
    // 0x808024C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_808024CC;
    // 0x808024C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_808024CC:
    // 0x808024CC: jal         0x80800968
    // 0x808024D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800968_chclockworkmouse(rdram, ctx);
        goto after_14;
    // 0x808024D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
    // 0x808024D4: b           L_808026C4
    // 0x808024D8: nop

        goto L_808026C4;
    // 0x808024D8: nop

L_808024DC:
    // 0x808024DC: jal         0x808008DC
    // 0x808024E0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_15;
    // 0x808024E0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x808024E4: b           L_808026C4
    // 0x808024E8: nop

        goto L_808026C4;
    // 0x808024E8: nop

L_808024EC:
    // 0x808024EC: jal         0x80800024
    // 0x808024F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800024_chclockworkmouse(rdram, ctx);
        goto after_16;
    // 0x808024F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x808024F4: b           L_808026C4
    // 0x808024F8: nop

        goto L_808026C4;
    // 0x808024F8: nop

L_808024FC:
    // 0x808024FC: jal         0x80105AE8
    // 0x80802500: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80105AE8(rdram, ctx);
        goto after_17;
    // 0x80802500: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x80802504: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3814) << 16);
    // 0x80802508: lwc1        $f16, 0x3814($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3814));
    // 0x8080250C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802510: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802514: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80802518: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080251C: bc1f        L_80802554
    if (!c1cs) {
        // 0x80802520: nop
    
            goto L_80802554;
    }
    // 0x80802520: nop

    // 0x80802524: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80802528: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080252C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802530: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80802534: bgez        $t4, L_80802544
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802538: nop
    
            goto L_80802544;
    }
    // 0x80802538: nop

    // 0x8080253C: b           L_80802544
    // 0x80802540: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80802544;
    // 0x80802540: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80802544:
    // 0x80802544: jal         0x80800968
    // 0x80802548: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800968_chclockworkmouse(rdram, ctx);
        goto after_18;
    // 0x80802548: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x8080254C: b           L_808026C4
    // 0x80802550: nop

        goto L_808026C4;
    // 0x80802550: nop

L_80802554:
    // 0x80802554: jal         0x808008DC
    // 0x80802558: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_19;
    // 0x80802558: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_19:
    // 0x8080255C: b           L_808026C4
    // 0x80802560: nop

        goto L_808026C4;
    // 0x80802560: nop

L_80802564:
    // 0x80802564: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802568: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080256C: b           L_808026C4
    // 0x80802570: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_808026C4;
    // 0x80802570: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80802574:
    // 0x80802574: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80802578: jal         0x800D0A9C
    // 0x8080257C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_20;
    // 0x8080257C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80802580: beq         $v0, $zero, L_80802594
    if (ctx->r2 == 0) {
        // 0x80802584: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80802594;
    }
    // 0x80802584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802588: addiu       $t5, $zero, 0x142D
    ctx->r13 = ADD32(0, 0X142D);
    // 0x8080258C: b           L_8080259C
    // 0x80802590: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
        goto L_8080259C;
    // 0x80802590: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80802594:
    // 0x80802594: addiu       $t6, $zero, 0x1429
    ctx->r14 = ADD32(0, 0X1429);
    // 0x80802598: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080259C:
    // 0x8080259C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808025A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808025A4: jal         0x8080079C
    // 0x808025A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080079C_chclockworkmouse(rdram, ctx);
        goto after_21;
    // 0x808025A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_21:
    // 0x808025AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808025B4: jal         0x80801B44
    // 0x808025B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_22;
    // 0x808025B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_22:
    // 0x808025BC: jal         0x800FDC28
    // 0x808025C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_23;
    // 0x808025C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x808025C4: jal         0x800FC660
    // 0x808025C8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_24;
    // 0x808025C8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_24:
    // 0x808025CC: b           L_808026C4
    // 0x808025D0: nop

        goto L_808026C4;
    // 0x808025D0: nop

L_808025D4:
    // 0x808025D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808025D8: jal         0x80090658
    // 0x808025DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_25;
    // 0x808025DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x808025E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808025E4: jal         0x80090734
    // 0x808025E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_26;
    // 0x808025E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x808025EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808025F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808025F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808025F8: jal         0x8080079C
    // 0x808025FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080079C_chclockworkmouse(rdram, ctx);
        goto after_27;
    // 0x808025FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_27:
    // 0x80802600: jal         0x80800090
    // 0x80802604: nop

    func_80800090_chclockworkmouse(rdram, ctx);
        goto after_28;
    // 0x80802604: nop

    after_28:
    // 0x80802608: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080260C: beq         $v0, $at, L_80802628
    if (ctx->r2 == ctx->r1) {
        // 0x80802610: addiu       $a0, $zero, 0x4A
        ctx->r4 = ADD32(0, 0X4A);
            goto L_80802628;
    }
    // 0x80802610: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80802614: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802618: beq         $v0, $at, L_8080264C
    if (ctx->r2 == ctx->r1) {
        // 0x8080261C: addiu       $a0, $zero, 0x4A
        ctx->r4 = ADD32(0, 0X4A);
            goto L_8080264C;
    }
    // 0x8080261C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80802620: b           L_80802670
    // 0x80802624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802670;
    // 0x80802624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802628:
    // 0x80802628: jal         0x800D0A9C
    // 0x8080262C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_29;
    // 0x8080262C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80802630: beq         $v0, $zero, L_80802644
    if (ctx->r2 == 0) {
        // 0x80802634: addiu       $t8, $zero, 0x1428
        ctx->r24 = ADD32(0, 0X1428);
            goto L_80802644;
    }
    // 0x80802634: addiu       $t8, $zero, 0x1428
    ctx->r24 = ADD32(0, 0X1428);
    // 0x80802638: addiu       $t7, $zero, 0x142C
    ctx->r15 = ADD32(0, 0X142C);
    // 0x8080263C: b           L_8080266C
    // 0x80802640: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_8080266C;
    // 0x80802640: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80802644:
    // 0x80802644: b           L_8080266C
    // 0x80802648: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8080266C;
    // 0x80802648: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8080264C:
    // 0x8080264C: jal         0x800D0A9C
    // 0x80802650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_30;
    // 0x80802650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80802654: beq         $v0, $zero, L_80802668
    if (ctx->r2 == 0) {
        // 0x80802658: addiu       $t0, $zero, 0x142A
        ctx->r8 = ADD32(0, 0X142A);
            goto L_80802668;
    }
    // 0x80802658: addiu       $t0, $zero, 0x142A
    ctx->r8 = ADD32(0, 0X142A);
    // 0x8080265C: addiu       $t9, $zero, 0x142E
    ctx->r25 = ADD32(0, 0X142E);
    // 0x80802660: b           L_8080266C
    // 0x80802664: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8080266C;
    // 0x80802664: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_80802668:
    // 0x80802668: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8080266C:
    // 0x8080266C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802670:
    // 0x80802670: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802674: jal         0x80801B44
    // 0x80802678: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_31;
    // 0x80802678: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_31:
    // 0x8080267C: b           L_808026C4
    // 0x80802680: nop

        goto L_808026C4;
    // 0x80802680: nop

L_80802684:
    // 0x80802684: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80802688: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802690: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802694: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80802698: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8080269C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808026A0: jal         0x801058C4
    // 0x808026A4: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    func_801058C4(rdram, ctx);
        goto after_32;
    // 0x808026A4: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    after_32:
    // 0x808026A8: jal         0x808021C4
    // 0x808026AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_33;
    // 0x808026AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808026B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808026B4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808026B8: addiu       $a2, $zero, 0x20B0
    ctx->r6 = ADD32(0, 0X20B0);
    // 0x808026BC: jal         0x80800850
    // 0x808026C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_80800850_chclockworkmouse(rdram, ctx);
        goto after_34;
    // 0x808026C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_34:
L_808026C4:
    // 0x808026C4: jal         0x80800CC0
    // 0x808026C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chclockworkmouse(rdram, ctx);
        goto after_35;
    // 0x808026C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808026CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808026D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808026D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808026D8: jr          $ra
    // 0x808026DC: nop

    return;
    // 0x808026DC: nop

;}
RECOMP_FUNC void func_8009CC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC10: jr          $ra
    // 0x8009CC14: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    return;
    // 0x8009CC14: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083740: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083740);
    return;
    // 0x80083744: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void chgoldstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2136, 0X990) << 16);
    // 0x80800844: jr          $ra
    // 0x80800848: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2136, 0X990));
    return;
    // 0x80800848: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2136, 0X990));
    // 0x8080084C: nop

;}
RECOMP_FUNC void _chfishshootgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A18: syscall     188
    recomp_syscall_handler(rdram, ctx, 0x80085A18);
    return;
    // 0x80085A1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glrecord_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886A0: syscall     698
    recomp_syscall_handler(rdram, ctx, 0x800886A0);
    return;
    // 0x800886A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _ncbaspiral_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089188: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089188);
    return;
    // 0x8008918C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080010C_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800110: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800118: jal         0x80082838
    // 0x8080011C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080011C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: addiu       $a1, $zero, 0x1DF
    ctx->r5 = ADD32(0, 0X1DF);
    // 0x80800128: jal         0x8008CDB8
    // 0x8080012C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x8080012C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800130: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800134: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800144: jal         0x8009FFD8
    // 0x80800148: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800148: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080014C: jal         0x8009EF04
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800154: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800158: nop

    // 0x8080015C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800160: nop

    // 0x80800164: bc1t        L_80800180
    if (c1cs) {
        // 0x80800168: nop
    
            goto L_80800180;
    }
    // 0x80800168: nop

    // 0x8080016C: jal         0x8009EEB8
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_4;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800174: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800178: jal         0x8009C914
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800180:
    // 0x80800180: jal         0x8009C990
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_6;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800188: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080018C: jal         0x8009B9C0
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_7;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x8009B9B0
    // 0x8080019C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x8080019C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x8009BCB4
    // 0x808001A8: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x808001A8: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_9:
    // 0x808001AC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void func_800E97C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E97C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E97C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E97C8: jal         0x800EA09C
    // 0x800E97CC: nop

    func_800EA09C(rdram, ctx);
        goto after_0;
    // 0x800E97CC: nop

    after_0:
    // 0x800E97D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E97D4: beql        $v0, $at, L_800E97F8
    if (ctx->r2 == ctx->r1) {
        // 0x800E97D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E97F8;
    }
    goto skip_0;
    // 0x800E97D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E97DC: jal         0x800EA45C
    // 0x800E97E0: nop

    func_800EA45C(rdram, ctx);
        goto after_1;
    // 0x800E97E0: nop

    after_1:
    // 0x800E97E4: jal         0x800A5CFC
    // 0x800E97E8: nop

    func_800A5CFC(rdram, ctx);
        goto after_2;
    // 0x800E97E8: nop

    after_2:
    // 0x800E97EC: jal         0x800EA51C
    // 0x800E97F0: nop

    func_800EA51C(rdram, ctx);
        goto after_3;
    // 0x800E97F0: nop

    after_3:
    // 0x800E97F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E97F8:
    // 0x800E97F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E97FC: jr          $ra
    // 0x800E9800: nop

    return;
    // 0x800E9800: nop

;}
