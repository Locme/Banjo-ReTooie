#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chidgoldhorde_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A10: syscall     187
    recomp_syscall_handler(rdram, ctx, 0x80085A10);
    return;
    // 0x80085A14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chgoldsnakehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(724, 0X508) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x508
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X508));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x508
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X508));
;}
RECOMP_FUNC void func_8080004C_gctransitionDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2654, 0X105C) << 16);
    // 0x80800050: addiu       $v1, $v0, 0x105C
    ctx->r3 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2654, 0X105C));
    // 0x80800054: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80800058: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2654, 0X105C) << 16);
    // 0x8080005C: addiu       $t7, $t7, 0x105C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2654, 0X105C));
    // 0x80800060: beql        $t6, $zero, L_80800090
    if (ctx->r14 == 0) {
        // 0x80800064: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80800068: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
L_8080006C:
    // 0x8080006C: bnel        $a0, $v0, L_80800080
    if (ctx->r4 != ctx->r2) {
        // 0x80800070: lhu         $v0, 0x4($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X4);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800070: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    skip_1:
    // 0x80800074: jr          $ra
    // 0x80800078: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800078: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080007C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
L_80800080:
    // 0x80800080: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800084: bne         $v0, $zero, L_8080006C
    if (ctx->r2 != 0) {
        // 0x80800088: nop
    
            goto L_8080006C;
    }
    // 0x80800088: nop

    // 0x8080008C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800090:
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_8008FCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FCC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FCD0: jal         0x800F54E4
    // 0x8008FCD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FCD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FCD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FCDC: jal         0x800F52B8
    // 0x8008FCE0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F52B8(rdram, ctx);
        goto after_1;
    // 0x8008FCE0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FCE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FCEC: jr          $ra
    // 0x8008FCF0: nop

    return;
    // 0x8008FCF0: nop

;}
RECOMP_FUNC void func_808008B4_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008BC: jal         0x800EA05C
    // 0x808008C0: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808008C0: nop

    after_0:
    // 0x808008C4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x808008C8: lh          $t6, 0xBC0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x808008CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808008D0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x808008D4: bne         $v0, $t6, L_808008E4
    if (ctx->r2 != ctx->r14) {
        // 0x808008D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008E4;
    }
    // 0x808008D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008DC: b           L_80800944
    // 0x808008E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800944;
    // 0x808008E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E4:
    // 0x808008E4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x808008E8: addiu       $t8, $t8, 0xBC0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x808008EC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x808008F0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x808008F4: bnel        $v0, $t9, L_80800908
    if (ctx->r2 != ctx->r25) {
        // 0x808008F8: lh          $t0, 0x8($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X8);
            goto L_80800908;
    }
    goto skip_0;
    // 0x808008F8: lh          $t0, 0x8($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x808008FC: b           L_80800944
    // 0x80800900: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80800944;
    // 0x80800900: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800904: lh          $t0, 0x8($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X8);
L_80800908:
    // 0x80800908: bnel        $v0, $t0, L_8080091C
    if (ctx->r2 != ctx->r8) {
        // 0x8080090C: lh          $t1, 0x10($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X10);
            goto L_8080091C;
    }
    goto skip_1;
    // 0x8080090C: lh          $t1, 0x10($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X10);
    skip_1:
    // 0x80800910: b           L_80800944
    // 0x80800914: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80800944;
    // 0x80800914: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80800918: lh          $t1, 0x10($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X10);
L_8080091C:
    // 0x8080091C: bnel        $v0, $t1, L_80800930
    if (ctx->r2 != ctx->r9) {
        // 0x80800920: lh          $t2, 0x18($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X18);
            goto L_80800930;
    }
    goto skip_2;
    // 0x80800920: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
    skip_2:
    // 0x80800924: b           L_80800944
    // 0x80800928: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_80800944;
    // 0x80800928: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x8080092C: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
L_80800930:
    // 0x80800930: bnel        $v0, $t2, L_80800944
    if (ctx->r2 != ctx->r10) {
        // 0x80800934: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800944;
    }
    goto skip_3;
    // 0x80800934: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_3:
    // 0x80800938: b           L_80800944
    // 0x8080093C: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
        goto L_80800944;
    // 0x8080093C: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x80800940: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800944:
    // 0x80800944: jr          $ra
    // 0x80800948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CD0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CD0);
    return;
    // 0x80083CD4: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_80800EF0_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800EF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800EF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800EFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F00: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800F04: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800F08: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800F0C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800F10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F14: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800F18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800F24: jal         0x800F12D4
    // 0x80800F28: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F12D4(rdram, ctx);
        goto after_0;
    // 0x80800F28: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800F2C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2284, 0X291C) << 16);
    // 0x80800F30: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800F34: addiu       $t7, $t7, 0x291C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2284, 0X291C));
    // 0x80800F38: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800F3C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80800F40: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800F44: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800F48: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F54: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800F58: jal         0x80100094
    // 0x80800F5C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800F5C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_1:
    // 0x80800F60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800F6C: jal         0x80801A9C
    // 0x80800F70: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_80801A9C_chfactorymagnet(rdram, ctx);
        goto after_2;
    // 0x80800F70: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800F74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800F78: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800F7C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800F80: jal         0x800EFE50
    // 0x80800F84: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_800EFE50(rdram, ctx);
        goto after_3;
    // 0x80800F84: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80800F88: beq         $s1, $zero, L_80800F98
    if (ctx->r17 == 0) {
        // 0x80800F8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800F98;
    }
    // 0x80800F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F90: jal         0x80089888
    // 0x80800F94: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800F94: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_4:
L_80800F98:
    // 0x80800F98: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA4: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800FA8: bnel        $t2, $at, L_80800FBC
    if (ctx->r10 != ctx->r1) {
        // 0x80800FAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    goto skip_0;
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800FB0: jal         0x808016A4
    // 0x80800FB4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_808016A4_chfactorymagnet(rdram, ctx);
        goto after_5;
    // 0x80800FB4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FBC:
    // 0x80800FBC: jal         0x80101870
    // 0x80800FC0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x80800FC0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_6:
    // 0x80800FC4: beq         $s1, $zero, L_80800FD4
    if (ctx->r17 == 0) {
        // 0x80800FC8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800FD4;
    }
    // 0x80800FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FCC: jal         0x80089880
    // 0x80800FD0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800FD0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_7:
L_80800FD4:
    // 0x80800FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FD8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FDC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800FE0: jr          $ra
    // 0x80800FE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800FE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gclightsDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080052C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800530: jal         0x800C911C
    // 0x80800534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C911C(rdram, ctx);
        goto after_0;
    // 0x80800534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800538: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8080053C: jal         0x800EE830
    // 0x80800540: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x80800540: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

    // 0x80800554: nop

    // 0x80800558: nop

    // 0x8080055C: nop

;}
RECOMP_FUNC void func_8080009C_bssplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A8: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808000B4: jal         0x8008CDB8
    // 0x808000B8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x808000B8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_0:
    // 0x808000BC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808000C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000D0: jal         0x8009FFD8
    // 0x808000D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808000D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x808000D8: jal         0x80800000
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bssplat_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: addiu       $a1, $zero, 0x427
    ctx->r5 = ADD32(0, 0X427);
    // 0x808000E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000EC: jal         0x8009DF18
    // 0x808000F0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x808000F0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_3:
    // 0x808000F4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808000F8: jal         0x8008E944
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_4;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_8002AA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AA30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002AA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AA38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002AA3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002AA40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002AA44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002AA48: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002AA4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AA50: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8002AA54: jal         0x80027AF0
    // 0x8002AA58: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80027AF0(rdram, ctx);
        goto after_0;
    // 0x8002AA58: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x8002AA5C: b           L_8002AA64
    // 0x8002AA60: nop

        goto L_8002AA64;
    // 0x8002AA60: nop

L_8002AA64:
    // 0x8002AA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AA68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002AA6C: jr          $ra
    // 0x8002AA70: nop

    return;
    // 0x8002AA70: nop

;}
RECOMP_FUNC void func_8008DA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008DA30: jal         0x800C6E38
    // 0x8008DA34: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008DA34: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8008DA38: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DA3C: beq         $t6, $zero, L_8008DA98
    if (ctx->r14 == 0) {
        // 0x8008DA40: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008DA98;
    }
    // 0x8008DA40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DA44: jal         0x8009BB50
    // 0x8008DA48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_1;
    // 0x8008DA48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008DA4C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008DA50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DA54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DA58: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008DA5C: nop

    // 0x8008DA60: bc1f        L_8008DA6C
    if (!c1cs) {
        // 0x8008DA64: nop
    
            goto L_8008DA6C;
    }
    // 0x8008DA64: nop

    // 0x8008DA68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DA6C:
    // 0x8008DA6C: beql        $v0, $zero, L_8008DA9C
    if (ctx->r2 == 0) {
        // 0x8008DA70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008DA9C;
    }
    goto skip_0;
    // 0x8008DA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008DA74: jal         0x800A0FCC
    // 0x8008DA78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A0FCC(rdram, ctx);
        goto after_2;
    // 0x8008DA78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008DA7C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008DA80: beq         $t7, $zero, L_8008DA98
    if (ctx->r15 == 0) {
        // 0x8008DA84: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008DA98;
    }
    // 0x8008DA84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008DA88: jal         0x800976DC
    // 0x8008DA8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800976DC(rdram, ctx);
        goto after_3;
    // 0x8008DA8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008DA90: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DA94: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8008DA98:
    // 0x8008DA98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DA9C:
    // 0x8008DA9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DAA0: jr          $ra
    // 0x8008DAA4: nop

    return;
    // 0x8008DAA4: nop

;}
RECOMP_FUNC void bakey_setControllerIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091BF8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091BFC: jal         0x800BD268
    // 0x80091C00: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BD268(rdram, ctx);
        goto after_0;
    // 0x80091C00: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091C0C: jr          $ra
    // 0x80091C10: nop

    return;
    // 0x80091C10: nop

;}
RECOMP_FUNC void _chanim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085980: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x80085980);
    return;
    // 0x80085984: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808010F8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010F8: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808010FC: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80801100: jr          $ra
    // 0x80801104: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80801104: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_800F5950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5950: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F5954: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F5958: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F595C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5964: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F5968: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F596C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F5970: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F5974: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5978: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x800F597C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800F5980: jal         0x800A3148
    // 0x800F5984: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800A3148(rdram, ctx);
        goto after_0;
    // 0x800F5984: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F5988: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F598C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F5990: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F5994: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5998: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800F599C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F59A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F59A4: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F59A8: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x800F59AC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800F59B0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800F59B4: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x800F59B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800F59BC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F59C0: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800F59C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F59C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F59CC: jr          $ra
    // 0x800F59D0: nop

    return;
    // 0x800F59D0: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F08: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F08);
    return;
    // 0x80087F0C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802594_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080259C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808025A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808025A4: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x808025A8: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x808025AC: jal         0x8008A240
    // 0x808025B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808025B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x808025B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808025B8: jal         0x80802760
    // 0x808025BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80802760_sucoaster(rdram, ctx);
        goto after_1;
    // 0x808025BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808025C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808025C4: bne         $v0, $at, L_808025D4
    if (ctx->r2 != ctx->r1) {
        // 0x808025C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808025D4;
    }
    // 0x808025C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025CC: b           L_8080263C
    // 0x808025D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080263C;
    // 0x808025D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808025D4:
    // 0x808025D4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808025D8: lw          $a1, 0x40($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X40);
    // 0x808025DC: jal         0x800F64A4
    // 0x808025E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x808025E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808025E4: beq         $v0, $zero, L_808025F4
    if (ctx->r2 == 0) {
        // 0x808025E8: nop
    
            goto L_808025F4;
    }
    // 0x808025E8: nop

    // 0x808025EC: b           L_8080263C
    // 0x808025F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080263C;
    // 0x808025F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808025F4:
    // 0x808025F4: jal         0x800F5C94
    // 0x808025F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F5C94(rdram, ctx);
        goto after_3;
    // 0x808025F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808025FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802600: bne         $v0, $at, L_80802610
    if (ctx->r2 != ctx->r1) {
        // 0x80802604: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80802610;
    }
    // 0x80802604: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80802608: b           L_8080263C
    // 0x8080260C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080263C;
    // 0x8080260C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802610:
    // 0x80802610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802614: jal         0x800F52B8
    // 0x80802618: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_4;
    // 0x80802618: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x8080261C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80802620: beq         $v0, $at, L_80802630
    if (ctx->r2 == ctx->r1) {
        // 0x80802624: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80802630;
    }
    // 0x80802624: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80802628: bnel        $v0, $at, L_8080263C
    if (ctx->r2 != ctx->r1) {
        // 0x8080262C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080263C;
    }
    goto skip_0;
    // 0x8080262C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80802630:
    // 0x80802630: b           L_8080263C
    // 0x80802634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080263C;
    // 0x80802634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080263C:
    // 0x8080263C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802644: jr          $ra
    // 0x80802648: nop

    return;
    // 0x80802648: nop

;}
RECOMP_FUNC void func_800C67D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67D8: jr          $ra
    // 0x800C67DC: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    return;
    // 0x800C67DC: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
;}
RECOMP_FUNC void _glhittableDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088650: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088650);
    return;
    // 0x80088654: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CE0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CE0);
    return;
    // 0x80082CE4: addi        $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
;}
RECOMP_FUNC void bsclimb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080031C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800324: jal         0x8008FE68
    // 0x80800328: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800328: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: jal         0x80098590
    // 0x80800334: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80098590(rdram, ctx);
        goto after_1;
    // 0x80800334: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x8009E77C
    // 0x80800340: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8009E77C(rdram, ctx);
        goto after_2;
    // 0x80800340: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x80800344: bne         $v0, $zero, L_8080036C
    if (ctx->r2 != 0) {
        // 0x80800348: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_8080036C;
    }
    // 0x80800348: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080034C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800350: jal         0x800F1E6C
    // 0x80800354: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F1E6C(rdram, ctx);
        goto after_3;
    // 0x80800354: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x8009C914
    // 0x80800360: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x80800360: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x80800364: jal         0x8009C974
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_5;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8080036C:
    // 0x8080036C: jal         0x800C6DA0
    // 0x80800370: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800C6DA0(rdram, ctx);
        goto after_6;
    // 0x80800370: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_6:
    // 0x80800374: lui         $a2, 0x4028
    ctx->r6 = S32(0X4028 << 16);
    // 0x80800378: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x8008CB3C
    // 0x80800384: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x80800384: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_7:
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: jal         0x8008CA4C
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_8;
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800394: jal         0x808000E8
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000E8_bsclimb(rdram, ctx);
        goto after_9;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080039C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003A0: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808003AC: jal         0x80800258
    // 0x808003B0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80800258_bsclimb(rdram, ctx);
        goto after_10;
    // 0x808003B0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_10:
    // 0x808003B4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003C4: jr          $ra
    // 0x808003C8: nop

    return;
    // 0x808003C8: nop

;}
RECOMP_FUNC void func_808007A0_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808007B4: jal         0x80091A30
    // 0x808007B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_0;
    // 0x808007B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808007BC: beql        $v0, $zero, L_808007F0
    if (ctx->r2 == 0) {
        // 0x808007C0: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_808007F0;
    }
    goto skip_0;
    // 0x808007C0: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x808007C4: jal         0x8009BB50
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_1;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808007D0: nop

    // 0x808007D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808007D8: nop

    // 0x808007DC: bc1fl       L_808007F0
    if (!c1cs) {
        // 0x808007E0: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_808007F0;
    }
    goto skip_1;
    // 0x808007E0: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_1:
    // 0x808007E4: jal         0x8009BC6C
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007EC: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_808007F0:
    // 0x808007F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007F4: beq         $v0, $at, L_80800814
    if (ctx->r2 == ctx->r1) {
        // 0x808007F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800814;
    }
    // 0x808007F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007FC: beq         $v0, $at, L_80800858
    if (ctx->r2 == ctx->r1) {
        // 0x80800800: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800858;
    }
    // 0x80800800: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800804: beq         $v0, $at, L_80800884
    if (ctx->r2 == ctx->r1) {
        // 0x80800808: nop
    
            goto L_80800884;
    }
    // 0x80800808: nop

    // 0x8080080C: b           L_808008E0
    // 0x80800810: nop

        goto L_808008E0;
    // 0x80800810: nop

L_80800814:
    // 0x80800814: jal         0x80800100
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800100_bsbanshack(rdram, ctx);
        goto after_3;
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080081C: jal         0x8008CAEC
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800824: beq         $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800834;
    }
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x808005DC
    // 0x80800830: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808005DC_bsbanshack(rdram, ctx);
        goto after_5;
    // 0x80800830: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_80800834:
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: jal         0x8008DF8C
    // 0x8080083C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x8080083C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_6:
    // 0x80800840: beq         $v0, $zero, L_808008E0
    if (ctx->r2 == 0) {
        // 0x80800844: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E0;
    }
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: jal         0x808005DC
    // 0x8080084C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005DC_bsbanshack(rdram, ctx);
        goto after_7;
    // 0x8080084C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800850: b           L_808008E0
    // 0x80800854: nop

        goto L_808008E0;
    // 0x80800854: nop

L_80800858:
    // 0x80800858: jal         0x80800100
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800100_bsbanshack(rdram, ctx);
        goto after_8;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: jal         0x8008DF8C
    // 0x80800868: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_9;
    // 0x80800868: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_9:
    // 0x8080086C: beq         $v0, $zero, L_808008E0
    if (ctx->r2 == 0) {
        // 0x80800870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E0;
    }
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x808005DC
    // 0x80800878: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005DC_bsbanshack(rdram, ctx);
        goto after_10;
    // 0x80800878: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080087C: b           L_808008E0
    // 0x80800880: nop

        goto L_808008E0;
    // 0x80800880: nop

L_80800884:
    // 0x80800884: jal         0x8008E078
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080088C: beq         $v0, $zero, L_808008E0
    if (ctx->r2 == 0) {
        // 0x80800890: nop
    
            goto L_808008E0;
    }
    // 0x80800890: nop

    // 0x80800894: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: bne         $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x808008A0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_808008AC;
    }
    // 0x808008A0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x808008A4: jal         0x8009FE58
    // 0x808008A8: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    func_8009FE58(rdram, ctx);
        goto after_12;
    // 0x808008A8: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    after_12:
L_808008AC:
    // 0x808008AC: jal         0x8008CAEC
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008B4: beq         $v0, $zero, L_808008C4
    if (ctx->r2 == 0) {
        // 0x808008B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C4;
    }
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: addiu       $t7, $zero, 0x16C
    ctx->r15 = ADD32(0, 0X16C);
    // 0x808008C0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808008C4:
    // 0x808008C4: jal         0x80800074
    // 0x808008C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800074_bsbanshack(rdram, ctx);
        goto after_14;
    // 0x808008C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x808008CC: bne         $v0, $zero, L_808008E0
    if (ctx->r2 != 0) {
        // 0x808008D0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_808008E0;
    }
    // 0x808008D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: jal         0x8009B9B0
    // 0x808008DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x808008DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
L_808008E0:
    // 0x808008E0: jal         0x8008E260
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_16;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808008E8: beq         $v0, $zero, L_808008F8
    if (ctx->r2 == 0) {
        // 0x808008EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F8;
    }
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x808008F4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808008F8:
    // 0x808008F8: jal         0x8009E5C8
    // 0x808008FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x808008FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080090C: jr          $ra
    // 0x80800910: nop

    return;
    // 0x80800910: nop

;}
RECOMP_FUNC void func_80800034_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: jal         0x808003A8
    // 0x80800040: nop

    glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800040: nop

    after_0:
    // 0x80800044: jal         0x808003C8
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    glglobalsettings_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080004C: jal         0x808004CC
    // 0x80800050: nop

    glglobalsettings_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800050: nop

    after_2:
    // 0x80800054: jal         0x808004F0
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    glglobalsettings_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080005C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800060: jal         0x80800408
    // 0x80800064: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    glglobalsettings_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x80800068: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080006C: jal         0x80800458
    // 0x80800070: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    glglobalsettings_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800070: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_80800384_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: jr          $ra
    // 0x80800388: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800388: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _subaddiefind_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C40: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C40);
    return;
    // 0x80089C44: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddiedraw25d_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C10: syscall     806
    recomp_syscall_handler(rdram, ctx, 0x80089C10);
    return;
    // 0x80089C14: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802060_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802060: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802068: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8080206C: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x80802070: srl         $t6, $a0, 5
    ctx->r14 = S32(U32(ctx->r4) >> 5);
    // 0x80802074: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80802078: jal         0x800F6C5C
    // 0x8080207C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_800F6C5C(rdram, ctx);
        goto after_0;
    // 0x8080207C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80802080: beql        $v0, $zero, L_80802158
    if (ctx->r2 == 0) {
        // 0x80802084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802158;
    }
    goto skip_0;
    // 0x80802084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802088: jal         0x800F55D0
    // 0x8080208C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F55D0(rdram, ctx);
        goto after_1;
    // 0x8080208C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80802090: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80802094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802098: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8080209C: bnel        $v0, $t8, L_80802158
    if (ctx->r2 != ctx->r24) {
        // 0x808020A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802158;
    }
    goto skip_1;
    // 0x808020A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808020A4: jal         0x800F5A00
    // 0x808020A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808020A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x808020AC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1700, 0X26A4) << 16);
    // 0x808020B0: addiu       $a0, $a0, 0x26A4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1700, 0X26A4));
    // 0x808020B4: jal         0x800882A8
    // 0x808020B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _gccubesearch_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808020B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x808020BC: beq         $v0, $zero, L_808020D4
    if (ctx->r2 == 0) {
        // 0x808020C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808020D4;
    }
    // 0x808020C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808020C4: jal         0x80088C00
    // 0x808020C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808020C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808020CC: b           L_8080214C
    // 0x808020D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_8080214C;
    // 0x808020D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808020D4:
    // 0x808020D4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x808020D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808020DC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808020E0: jal         0x808002EC
    // 0x808020E4: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    chchuffy_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808020E4: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_5:
    // 0x808020E8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808020EC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808020F0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x808020F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808020F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808020FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80802100: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80802104: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80802108: bc1f        L_80802138
    if (!c1cs) {
        // 0x8080210C: nop
    
            goto L_80802138;
    }
    // 0x8080210C: nop

    // 0x80802110: lwc1        $f8, 0x48($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80802114: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802118: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080211C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80802120: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80802124: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80802128: jal         0x800EF1B8
    // 0x8080212C: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x8080212C: nop

    after_6:
    // 0x80802130: b           L_80802144
    // 0x80802134: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
        goto L_80802144;
    // 0x80802134: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
L_80802138:
    // 0x80802138: jal         0x800EF1B8
    // 0x8080213C: lw          $a1, 0x48($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x8080213C: lw          $a1, 0x48($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X48);
    after_7:
    // 0x80802140: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
L_80802144:
    // 0x80802144: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80802148: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8080214C:
    // 0x8080214C: jal         0x800F77E8
    // 0x80802150: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F77E8(rdram, ctx);
        goto after_8;
    // 0x80802150: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80802154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802158:
    // 0x80802158: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080215C: jr          $ra
    // 0x80802160: nop

    return;
    // 0x80802160: nop

;}
RECOMP_FUNC void func_80800870_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080087C: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80800880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800884: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800888: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8080088C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800890: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800894: bc1fl       L_808008EC
    if (!c1cs) {
        // 0x80800898: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008EC;
    }
    goto skip_0;
    // 0x80800898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080089C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008A0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808008A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008A8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x808008AC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808008B4: jal         0x800F10B4
    // 0x808008B8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808008B8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_0:
    // 0x808008BC: jal         0x800C4B64
    // 0x808008C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800C4B64(rdram, ctx);
        goto after_1;
    // 0x808008C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x808008C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1668, 0X1028) << 16);
    // 0x808008CC: addiu       $a2, $a2, 0x1028
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1668, 0X1028));
    // 0x808008D0: jal         0x80089D18
    // 0x808008D4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808008D4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x808008D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFEC) << 16);
    // 0x808008DC: lwc1        $f16, 0xFEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFEC));
    // 0x808008E0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808008E4: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x808008E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008EC:
    // 0x808008EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void func_808004F4_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800500: jal         0x800DA298
    // 0x80800504: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800504: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_0:
    // 0x80800508: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x8080050C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080052C;
    }
    // 0x8080050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: jal         0x80102424
    // 0x80800514: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800514: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: lbu         $t7, 0x74($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X74);
    // 0x80800520: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800524: b           L_80800534
    // 0x80800528: sb          $t8, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r24;
        goto L_80800534;
    // 0x80800528: sb          $t8, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r24;
L_8080052C:
    // 0x8080052C: jal         0x80102424
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800534:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void func_8009BF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BF64: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BF68: jal         0x800136E4
    // 0x8009BF6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009BF6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009BF70: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009BF74: lw          $t7, 0xDC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XDC);
    // 0x8009BF78: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8009BF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BF84: jr          $ra
    // 0x8009BF88: nop

    return;
    // 0x8009BF88: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080087C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800880: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800888: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8080088C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800890: jal         0x801067C4
    // 0x80800894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800898: beq         $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x8080089C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808008D8;
    }
    // 0x8080089C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808008A0:
    // 0x808008A0: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808008A4: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x808008A8: bltz        $t8, L_808008C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x808008AC: nop
    
            goto L_808008C8;
    }
    // 0x808008AC: nop

    // 0x808008B0: lw          $t9, 0x6C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X6C);
    // 0x808008B4: srl         $t0, $t9, 21
    ctx->r8 = S32(U32(ctx->r25) >> 21);
    // 0x808008B8: bne         $s0, $t0, L_808008C8
    if (ctx->r16 != ctx->r8) {
        // 0x808008BC: nop
    
            goto L_808008C8;
    }
    // 0x808008BC: nop

    // 0x808008C0: b           L_808008DC
    // 0x808008C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808008DC;
    // 0x808008C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808008C8:
    // 0x808008C8: jal         0x8010682C
    // 0x808008CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x808008CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808008D0: bne         $v0, $zero, L_808008A0
    if (ctx->r2 != 0) {
        // 0x808008D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808008A0;
    }
    // 0x808008D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808008D8:
    // 0x808008D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008DC:
    // 0x808008DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008E8: jr          $ra
    // 0x808008EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808008EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chdrips_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1816, 0X610) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x610
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1816, 0X610));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x610
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1816, 0X610));
;}
RECOMP_FUNC void func_808049E8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808049E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808049EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808049F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808049F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808049F8: jal         0x80087D58
    // 0x808049FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _gcnewoption_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x808049FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80804A00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A04: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80804A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804A0C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80804A10: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80804A14: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80804A18: addiu       $a2, $a2, 0xA
    ctx->r6 = ADD32(ctx->r6, 0XA);
    // 0x80804A1C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80804A20: jal         0x80087CF8
    // 0x80804A24: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80804A24: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80804A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804A2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804A30: jr          $ra
    // 0x80804A34: nop

    return;
    // 0x80804A34: nop

;}
RECOMP_FUNC void bsdroneslide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080014C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800154: sb          $zero, 0x190($a0)
    MEM_B(0X190, ctx->r4) = 0;
    // 0x80800158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080015C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800160: jal         0x8008E148
    // 0x80800164: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8008E148(rdram, ctx);
        goto after_0;
    // 0x80800164: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800168: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D4;
    }
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800174: jal         0x80800110
    // 0x80800178: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_80800110_bsdroneslide(rdram, ctx);
        goto after_1;
    // 0x80800178: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8080017C: jal         0x8009C984
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800184: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: jal         0x800136E4
    // 0x8080018C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x8080018C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_3:
    // 0x80800190: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800194: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800198: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8080019C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808001A0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: bc1tl       L_808001CC
    if (c1cs) {
        // 0x808001AC: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_808001CC;
    }
    goto skip_0;
    // 0x808001AC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    skip_0:
    // 0x808001B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001B4: nop

    // 0x808001B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808001BC: nop

    // 0x808001C0: bc1f        L_808001CC
    if (!c1cs) {
        // 0x808001C4: nop
    
            goto L_808001CC;
    }
    // 0x808001C4: nop

    // 0x808001C8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_808001CC:
    // 0x808001CC: jal         0x8009B9C0
    // 0x808001D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_4;
    // 0x808001D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
L_808001D4:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80800080
    // 0x808001DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800080_bsdroneslide(rdram, ctx);
        goto after_5;
    // 0x808001DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void func_800FCCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCCD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCCD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCCDC: jal         0x800FB5F8
    // 0x800FCCE0: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCCE0: nop

    after_0:
    // 0x800FCCE4: beq         $v0, $zero, L_800FCD00
    if (ctx->r2 == 0) {
        // 0x800FCCE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FCD00;
    }
    // 0x800FCCE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCCEC: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x800FCCF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FCCF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800FCCF8: bne         $t6, $at, L_800FCD08
    if (ctx->r14 != ctx->r1) {
        // 0x800FCCFC: nop
    
            goto L_800FCD08;
    }
    // 0x800FCCFC: nop

L_800FCD00:
    // 0x800FCD00: b           L_800FCD08
    // 0x800FCD04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800FCD08;
    // 0x800FCD04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800FCD08:
    // 0x800FCD08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FCD0C: jr          $ra
    // 0x800FCD10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FCD10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80114CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114CB0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80114CB4: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80114CB8: jr          $ra
    // 0x80114CBC: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80114CBC: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void bamovegoto_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: jal         0x80800000
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bamovegoto(rdram, ctx);
        goto after_0;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void func_800D3E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E14: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D3E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E24: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800D3E28: jal         0x800DA298
    // 0x800D3E2C: lhu         $a0, -0x4A46($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A46);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800D3E2C: lhu         $a0, -0x4A46($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A46);
    after_0:
    // 0x800D3E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3E38: jr          $ra
    // 0x800D3E3C: nop

    return;
    // 0x800D3E3C: nop

;}
RECOMP_FUNC void func_800D6C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6C64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D6C68: lh          $v0, -0x419E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X419E);
    // 0x800D6C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D6C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6C74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D6C78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6C7C: bltz        $v0, L_800D6CD8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D6C80: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800D6CD8;
    }
    // 0x800D6C80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D6C84: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D6C88: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D6C8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D6C90: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D6C94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D6C98: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800D6C9C: addiu       $s1, $s1, -0x4800
    ctx->r17 = ADD32(ctx->r17, -0X4800);
    // 0x800D6CA0: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800D6CA4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_800D6CA8:
    // 0x800D6CA8: srl         $t8, $v0, 18
    ctx->r24 = S32(U32(ctx->r2) >> 18);
    // 0x800D6CAC: slti        $at, $t8, 0x1DDD
    ctx->r1 = SIGNED(ctx->r24) < 0X1DDD ? 1 : 0;
    // 0x800D6CB0: bne         $at, $zero, L_800D6CC0
    if (ctx->r1 != 0) {
        // 0x800D6CB4: slti        $at, $t8, 0x1ED8
        ctx->r1 = SIGNED(ctx->r24) < 0X1ED8 ? 1 : 0;
            goto L_800D6CC0;
    }
    // 0x800D6CB4: slti        $at, $t8, 0x1ED8
    ctx->r1 = SIGNED(ctx->r24) < 0X1ED8 ? 1 : 0;
    // 0x800D6CB8: bnel        $at, $zero, L_800D6CCC
    if (ctx->r1 != 0) {
        // 0x800D6CBC: addiu       $s0, $s0, -0xC
        ctx->r16 = ADD32(ctx->r16, -0XC);
            goto L_800D6CCC;
    }
    goto skip_0;
    // 0x800D6CBC: addiu       $s0, $s0, -0xC
    ctx->r16 = ADD32(ctx->r16, -0XC);
    skip_0:
L_800D6CC0:
    // 0x800D6CC0: jal         0x800D6408
    // 0x800D6CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D6408(rdram, ctx);
        goto after_0;
    // 0x800D6CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D6CC8: addiu       $s0, $s0, -0xC
    ctx->r16 = ADD32(ctx->r16, -0XC);
L_800D6CCC:
    // 0x800D6CCC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800D6CD0: beql        $at, $zero, L_800D6CA8
    if (ctx->r1 == 0) {
        // 0x800D6CD4: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_800D6CA8;
    }
    goto skip_1;
    // 0x800D6CD4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_800D6CD8:
    // 0x800D6CD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6CDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D6CE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D6CE4: jr          $ra
    // 0x800D6CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D6CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8008BCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BCEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008BCF0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8008BCF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BCF8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8008BCFC: lh          $a0, 0xA($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XA);
    // 0x8008BD00: jal         0x8008B9C4
    // 0x8008BD04: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8008B9C4(rdram, ctx);
        goto after_0;
    // 0x8008BD04: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8008BD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BD0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BD10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008BD14: jr          $ra
    // 0x8008BD18: nop

    return;
    // 0x8008BD18: nop

;}
RECOMP_FUNC void _chpodiumbankaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872B8: syscall     545
    recomp_syscall_handler(rdram, ctx, 0x800872B8);
    return;
    // 0x800872BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808020F0_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808020F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808020FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802100: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80802104: jal         0x80100094
    // 0x80802108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080210C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80802110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802114: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80802118: beq         $a2, $zero, L_8080213C
    if (ctx->r6 == 0) {
        // 0x8080211C: sh          $a2, 0x18($v0)
        MEM_H(0X18, ctx->r2) = ctx->r6;
            goto L_8080213C;
    }
    // 0x8080211C: sh          $a2, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r6;
    // 0x80802120: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802124: beq         $a2, $a1, L_8080214C
    if (ctx->r6 == ctx->r5) {
        // 0x80802128: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080214C;
    }
    // 0x80802128: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080212C: beql        $a2, $at, L_808021E0
    if (ctx->r6 == ctx->r1) {
        // 0x80802130: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_808021E0;
    }
    goto skip_0;
    // 0x80802130: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80802134: b           L_80802200
    // 0x80802138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802200;
    // 0x80802138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080213C:
    // 0x8080213C: jal         0x80089C98
    // 0x80802140: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80802140: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80802144: b           L_80802200
    // 0x80802148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802200;
    // 0x80802148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080214C:
    // 0x8080214C: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x80802150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802154: beql        $v1, $zero, L_8080217C
    if (ctx->r3 == 0) {
        // 0x80802158: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8080217C;
    }
    goto skip_1;
    // 0x80802158: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x8080215C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802160: beql        $v1, $at, L_8080219C
    if (ctx->r3 == ctx->r1) {
        // 0x80802164: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8080219C;
    }
    goto skip_2;
    // 0x80802164: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_2:
    // 0x80802168: beq         $v1, $a1, L_808021BC
    if (ctx->r3 == ctx->r5) {
        // 0x8080216C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_808021BC;
    }
    // 0x8080216C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80802170: b           L_80802200
    // 0x80802174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802200;
    // 0x80802174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802178: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8080217C:
    // 0x8080217C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80802180: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802184: jal         0x800DC178
    // 0x80802188: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80802188: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080218C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802190: b           L_808021FC
    // 0x80802194: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_808021FC;
    // 0x80802194: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80802198: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8080219C:
    // 0x8080219C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808021A0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808021A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808021A8: jal         0x800DC178
    // 0x808021AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808021AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x808021B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808021B4: b           L_808021FC
    // 0x808021B8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_808021FC;
    // 0x808021B8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_808021BC:
    // 0x808021BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808021C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808021C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808021C8: jal         0x800DC178
    // 0x808021CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808021CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_4:
    // 0x808021D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808021D4: b           L_808021FC
    // 0x808021D8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_808021FC;
    // 0x808021D8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x808021DC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_808021E0:
    // 0x808021E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808021E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808021E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808021EC: jal         0x800DC178
    // 0x808021F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808021F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_5:
    // 0x808021F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808021F8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_808021FC:
    // 0x808021FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802200:
    // 0x80802200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802204: jr          $ra
    // 0x80802208: nop

    return;
    // 0x80802208: nop

;}
RECOMP_FUNC void func_80800824_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080082C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800830: jal         0x800C8A98
    // 0x80800834: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x80800834: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800838: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080083C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800840: jal         0x800C8CB8
    // 0x80800844: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x80800844: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800848: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1892, 0XAC8) << 16);
    // 0x8080084C: addiu       $a1, $a1, 0xAC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1892, 0XAC8));
    // 0x80800850: jal         0x800C8E84
    // 0x80800854: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80800854: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800858: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080085C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800860: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800864: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080086C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800870: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800874: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800878: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080087C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800880: jal         0x800C8E54
    // 0x80800884: nop

    func_800C8E54(rdram, ctx);
        goto after_3;
    // 0x80800884: nop

    after_3:
    // 0x80800888: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x8080088C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800890: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800894: jal         0x800863E8
    // 0x80800898: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800898: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x8080089C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008A4: jr          $ra
    // 0x808008A8: nop

    return;
    // 0x808008A8: nop

    // 0x808008AC: nop

;}
RECOMP_FUNC void func_80800194_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800198: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080019C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808001A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808001A8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x808001AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808001B4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808001B8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x808001BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001C0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808001C4: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
L_808001C8:
    // 0x808001C8: jal         0x800D3E14
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3E14(rdram, ctx);
        goto after_0;
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808001D0: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x808001D4: nop
    
            goto L_808001E8;
    }
    // 0x808001D4: nop

    // 0x808001D8: jal         0x800D3DD0
    // 0x808001DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3DD0(rdram, ctx);
        goto after_1;
    // 0x808001DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808001E0: beql        $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x808001E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_808001E8:
    // 0x808001E8: beq         $s0, $s3, L_808001FC
    if (ctx->r16 == ctx->r19) {
        // 0x808001EC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808001FC;
    }
    // 0x808001EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808001F4:
    // 0x808001F4: bne         $s1, $s2, L_808001C8
    if (ctx->r17 != ctx->r18) {
        // 0x808001F8: nop
    
            goto L_808001C8;
    }
    // 0x808001F8: nop

L_808001FC:
    // 0x808001FC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800200: jal         0x80087D20
    // 0x80800204: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800204: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80800208: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x8080020C: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800270;
    }
    // 0x8080020C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800210: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1708, 0X8E4) << 16);
    // 0x80800214: addiu       $t6, $t6, 0x8E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1708, 0X8E4));
    // 0x80800218: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8080021C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800220: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800224: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80800228: lhu         $at, 0x4($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X4);
    // 0x8080022C: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    // 0x80800230: jal         0x80087D00
    // 0x80800234: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800234: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x80800238: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x8080023C: sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16 << 2);
    // 0x80800240: subu        $a2, $a2, $s0
    ctx->r6 = SUB32(ctx->r6, ctx->r16);
    // 0x80800244: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800248: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8080024C: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800250: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800254: jal         0x80087CF8
    // 0x80800258: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x80800258: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x8080025C: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x80800260: jal         0x800D3F58
    // 0x80800264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D3F58(rdram, ctx);
        goto after_5;
    // 0x80800264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800268: b           L_80800338
    // 0x8080026C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
        goto L_80800338;
    // 0x8080026C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
L_80800270:
    // 0x80800270: jal         0x80087D28
    // 0x80800274: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x80800274: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x80800278: beq         $v0, $zero, L_808002E0
    if (ctx->r2 == 0) {
        // 0x8080027C: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_808002E0;
    }
    // 0x8080027C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800280: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1708, 0X8EC) << 16);
    // 0x80800284: addiu       $t1, $t1, 0x8EC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1708, 0X8EC));
    // 0x80800288: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8080028C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800290: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800294: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80800298: lhu         $at, 0x4($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X4);
    // 0x8080029C: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    // 0x808002A0: jal         0x80087D00
    // 0x808002A4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x808002A4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_7:
    // 0x808002A8: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x808002AC: sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16 << 2);
    // 0x808002B0: subu        $a2, $a2, $s0
    ctx->r6 = SUB32(ctx->r6, ctx->r16);
    // 0x808002B4: addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // 0x808002B8: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x808002BC: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x808002C0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808002C4: jal         0x80087CF8
    // 0x808002C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x808002C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_8:
    // 0x808002CC: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x808002D0: jal         0x800D3F58
    // 0x808002D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D3F58(rdram, ctx);
        goto after_9;
    // 0x808002D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808002D8: b           L_80800338
    // 0x808002DC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
        goto L_80800338;
    // 0x808002DC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
L_808002E0:
    // 0x808002E0: jal         0x80087D30
    // 0x808002E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_10;
    // 0x808002E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_10:
    // 0x808002E8: beq         $v0, $zero, L_80800334
    if (ctx->r2 == 0) {
        // 0x808002EC: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(1708, 0X8F4) << 16);
            goto L_80800334;
    }
    // 0x808002EC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1708, 0X8F4) << 16);
    // 0x808002F0: addiu       $t7, $t7, 0x8F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1708, 0X8F4));
    // 0x808002F4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808002F8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808002FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800300: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80800304: lhu         $at, 0x4($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X4);
    // 0x80800308: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    // 0x8080030C: jal         0x80087D00
    // 0x80800310: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800310: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_11:
    // 0x80800314: sll         $a2, $s1, 2
    ctx->r6 = S32(ctx->r17 << 2);
    // 0x80800318: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8080031C: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x80800320: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80800324: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800328: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080032C: jal         0x80087CF8
    // 0x80800330: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800330: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
L_80800334:
    // 0x80800334: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
L_80800338:
    // 0x80800338: beql        $t2, $zero, L_8080034C
    if (ctx->r10 == 0) {
        // 0x8080033C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080034C;
    }
    goto skip_1;
    // 0x8080033C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800340: jal         0x800D3FD4
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D3FD4(rdram, ctx);
        goto after_13;
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080034C:
    // 0x8080034C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800358: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080035C: jr          $ra
    // 0x80800360: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800360: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bahold_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D38: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D38);
    return;
    // 0x80084D3C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D3A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3A90: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800D3A94: addiu       $a1, $a1, 0x7010
    ctx->r5 = ADD32(ctx->r5, 0X7010);
    // 0x800D3A98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D3A9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D3AA4: jal         0x800D3B6C
    // 0x800D3AA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3AA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800D3AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3AB4: jr          $ra
    // 0x800D3AB8: nop

    return;
    // 0x800D3AB8: nop

;}
RECOMP_FUNC void chintrotext_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080060C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800618: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080061C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800620: jal         0x800A9C98
    // 0x80800624: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x80800624: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800628: bne         $v0, $zero, L_8080064C
    if (ctx->r2 != 0) {
        // 0x8080062C: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8080064C;
    }
    // 0x8080062C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800630: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800634: addiu       $a0, $a0, 0x61B0
    ctx->r4 = ADD32(ctx->r4, 0X61B0);
    // 0x80800638: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080063C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800640: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800644: jal         0x80086D48
    // 0x80800648: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800648: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
L_8080064C:
    // 0x8080064C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800650: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void chfactoryworkerwear_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2172, 0X438) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2172, 0X438));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2172, 0X438));
;}
RECOMP_FUNC void func_80801110_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801114: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80801118: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080111C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801120: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801124: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801128: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8080112C: jal         0x80100094
    // 0x80801130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801134: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80801138: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080113C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801140: beq         $a2, $at, L_808012A4
    if (ctx->r6 == ctx->r1) {
        // 0x80801144: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_808012A4;
    }
    // 0x80801144: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80801148: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8080114C: beq         $a2, $at, L_80801200
    if (ctx->r6 == ctx->r1) {
        // 0x80801150: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_80801200;
    }
    // 0x80801150: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80801154: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801158: beq         $a2, $at, L_808011E8
    if (ctx->r6 == ctx->r1) {
        // 0x8080115C: addiu       $v0, $sp, 0x48
        ctx->r2 = ADD32(ctx->r29, 0X48);
            goto L_808011E8;
    }
    // 0x8080115C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80801160: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801164: beq         $a2, $at, L_808011B8
    if (ctx->r6 == ctx->r1) {
        // 0x80801168: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_808011B8;
    }
    // 0x80801168: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8080116C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80801170: beq         $a2, $at, L_808012F0
    if (ctx->r6 == ctx->r1) {
        // 0x80801174: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(740, 0X18B0) << 16);
            goto L_808012F0;
    }
    // 0x80801174: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(740, 0X18B0) << 16);
    // 0x80801178: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080117C: beq         $a2, $at, L_80801308
    if (ctx->r6 == ctx->r1) {
        // 0x80801180: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_80801308;
    }
    // 0x80801180: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80801184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801188: bne         $a2, $at, L_80801330
    if (ctx->r6 != ctx->r1) {
        // 0x8080118C: nop
    
            goto L_80801330;
    }
    // 0x8080118C: nop

    // 0x80801190: jal         0x8080000C
    // 0x80801194: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8080000C_chfishshootgame(rdram, ctx);
        goto after_1;
    // 0x80801194: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80801198: jal         0x80088848
    // 0x8080119C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x8080119C: nop

    after_2:
    // 0x808011A0: beq         $v0, $zero, L_80801338
    if (ctx->r2 == 0) {
        // 0x808011A4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80801338;
    }
    // 0x808011A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808011A8: jal         0x80102424
    // 0x808011AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808011AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x808011B0: b           L_8080133C
    // 0x808011B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080133C;
    // 0x808011B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011B8:
    // 0x808011B8: beq         $v0, $zero, L_808011D8
    if (ctx->r2 == 0) {
        // 0x808011BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808011D8;
    }
    // 0x808011BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808011C0: bnel        $v0, $at, L_8080133C
    if (ctx->r2 != ctx->r1) {
        // 0x808011C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080133C;
    }
    goto skip_0;
    // 0x808011C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808011C8: jal         0x80800AF0
    // 0x808011CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800AF0_chfishshootgame(rdram, ctx);
        goto after_4;
    // 0x808011CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x808011D0: b           L_8080133C
    // 0x808011D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080133C;
    // 0x808011D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011D8:
    // 0x808011D8: jal         0x80800B30
    // 0x808011DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800B30_chfishshootgame(rdram, ctx);
        goto after_5;
    // 0x808011DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x808011E0: b           L_8080133C
    // 0x808011E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080133C;
    // 0x808011E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011E8:
    // 0x808011E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808011EC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808011F0: jal         0x8080076C
    // 0x808011F4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080076C_chfishshootgame(rdram, ctx);
        goto after_6;
    // 0x808011F4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_6:
    // 0x808011F8: b           L_8080133C
    // 0x808011FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080133C;
    // 0x808011FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801200:
    // 0x80801200: bne         $v0, $zero, L_8080128C
    if (ctx->r2 != 0) {
        // 0x80801204: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080128C;
    }
    // 0x80801204: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801208: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080120C: jal         0x80100094
    // 0x80801210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80801210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801214: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801218: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8080121C: jal         0x800D0634
    // 0x80801220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_8;
    // 0x80801220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80801224: beq         $v0, $zero, L_8080126C
    if (ctx->r2 == 0) {
        // 0x80801228: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080126C;
    }
    // 0x80801228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080122C: jal         0x80106790
    // 0x80801230: nop

    func_80106790(rdram, ctx);
        goto after_9;
    // 0x80801230: nop

    after_9:
    // 0x80801234: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801238: jal         0x800EE7F8
    // 0x8080123C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x8080123C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_10:
    // 0x80801240: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801244: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801248: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8080124C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801250: nop

    // 0x80801254: bc1f        L_80801264
    if (!c1cs) {
        // 0x80801258: nop
    
            goto L_80801264;
    }
    // 0x80801258: nop

    // 0x8080125C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80801260: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_80801264:
    // 0x80801264: b           L_8080127C
    // 0x80801268: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
        goto L_8080127C;
    // 0x80801268: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_8080126C:
    // 0x8080126C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801270: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801274: jal         0x800EE7F8
    // 0x80801278: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80801278: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
L_8080127C:
    // 0x8080127C: jal         0x80085738
    // 0x80801280: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    _capod_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x80801280: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_12:
    // 0x80801284: b           L_8080133C
    // 0x80801288: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080133C;
    // 0x80801288: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080128C:
    // 0x8080128C: jal         0x80800A90
    // 0x80801290: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80800A90_chfishshootgame(rdram, ctx);
        goto after_13;
    // 0x80801290: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_13:
    // 0x80801294: jal         0x80085738
    // 0x80801298: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    _capod_entrypoint_19(rdram, ctx);
        goto after_14;
    // 0x80801298: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_14:
    // 0x8080129C: b           L_8080133C
    // 0x808012A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080133C;
    // 0x808012A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808012A4:
    // 0x808012A4: bne         $v0, $zero, L_808012E8
    if (ctx->r2 != 0) {
        // 0x808012A8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808012E8;
    }
    // 0x808012A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808012AC: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x808012B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808012B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808012B8: jal         0x8008A2C8
    // 0x808012BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x808012BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x808012C0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808012C4: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x808012C8: addiu       $a1, $zero, 0xFF0
    ctx->r5 = ADD32(0, 0XFF0);
    // 0x808012CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808012D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808012D4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808012D8: jal         0x8008A208
    // 0x808012DC: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x808012DC: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_16:
    // 0x808012E0: b           L_8080133C
    // 0x808012E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080133C;
    // 0x808012E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808012E8:
    // 0x808012E8: b           L_8080133C
    // 0x808012EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080133C;
    // 0x808012EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808012F0:
    // 0x808012F0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x808012F4: addiu       $a0, $a0, 0x18B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(740, 0X18B0));
    // 0x808012F8: jal         0x80088090
    // 0x808012FC: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x808012FC: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_17:
    // 0x80801300: b           L_8080133C
    // 0x80801304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080133C;
    // 0x80801304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801308:
    // 0x80801308: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080130C: and         $a3, $v0, $at
    ctx->r7 = ctx->r2 & ctx->r1;
    // 0x80801310: srl         $t9, $a3, 16
    ctx->r25 = S32(U32(ctx->r7) >> 16);
    // 0x80801314: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80801318: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080131C: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80801320: jal         0x8008A2B8
    // 0x80801324: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80801324: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_18:
    // 0x80801328: b           L_80801340
    // 0x8080132C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801340;
    // 0x8080132C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801330:
    // 0x80801330: b           L_8080133C
    // 0x80801334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080133C;
    // 0x80801334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801338:
    // 0x80801338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080133C:
    // 0x8080133C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801340:
    // 0x80801340: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801344: jr          $ra
    // 0x80801348: nop

    return;
    // 0x80801348: nop

;}
RECOMP_FUNC void func_800E3B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3B90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3B94: jal         0x800CA440
    // 0x800E3B98: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA440(rdram, ctx);
        goto after_0;
    // 0x800E3B98: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3BA4: jr          $ra
    // 0x800E3BA8: nop

    return;
    // 0x800E3BA8: nop

;}
