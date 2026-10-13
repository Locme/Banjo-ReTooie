#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void fxtwinkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080002C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800030: jal         0x800B53A4
    // 0x80800034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800038: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2838, 0XF0) << 16);
    // 0x8080003C: addiu       $t6, $t6, 0xF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2838, 0XF0));
    // 0x80800040: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080004C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800054: jal         0x800BABB8
    // 0x80800058: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800058: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8080005C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800060: jal         0x800BA3FC
    // 0x80800064: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x80800064: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_2:
    // 0x80800068: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080006C: jal         0x800BA22C
    // 0x80800070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void badata_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800884: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800888: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080088C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800894: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1958) << 16);
    // 0x80800898: jal         0x808006AC
    // 0x8080089C: addiu       $a1, $a1, 0x1958
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1958));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x8080089C: addiu       $a1, $a1, 0x1958
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1958));
    after_0:
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C7C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801C80: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21E8) << 16);
    // 0x80801C84: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801C88: jr          $ra
    // 0x80801C8C: lw          $v0, 0x21E8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21E8));
    return;
    // 0x80801C8C: lw          $v0, 0x21E8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21E8));
;}
RECOMP_FUNC void func_800A3328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A332C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A3330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3334: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A3338: lw          $a1, 0xA0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XA0);
    // 0x800A333C: jal         0x800EE7F8
    // 0x800A3340: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A3340: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_0:
    // 0x800A3344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A334C: jr          $ra
    // 0x800A3350: nop

    return;
    // 0x800A3350: nop

;}
RECOMP_FUNC void func_800EB880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB880: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800EB884: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EB888: multu       $a2, $a2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB88C: addiu       $v0, $v0, 0x2EA0
    ctx->r2 = ADD32(ctx->r2, 0X2EA0);
    // 0x800EB890: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800EB894: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800EB898: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800EB89C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800EB8A0: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x800EB8A4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800EB8A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800EB8AC: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800EB8B0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800EB8B4: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800EB8B8: jr          $ra
    // 0x800EB8BC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    return;
    // 0x800EB8BC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A68: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A68);
    return;
    // 0x80086A6C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080078C_susubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800794: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800798: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8080079C: jal         0x800A93E4
    // 0x808007A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A93E4(rdram, ctx);
        goto after_0;
    // 0x808007A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808007A4: jal         0x80110024
    // 0x808007A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x808007A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808007AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808007B0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808007B4: jal         0x800F5A00
    // 0x808007B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808007B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x808007BC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808007C0: jal         0x800F5DC8
    // 0x808007C4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F5DC8(rdram, ctx);
        goto after_3;
    // 0x808007C4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x808007C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808007CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007D0: jal         0x80089578
    // 0x808007D4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _ncpod_entrypoint_23(rdram, ctx);
        goto after_4;
    // 0x808007D4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x808007D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808007DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007E0: jal         0x80089580
    // 0x808007E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _ncpod_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x808007E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x808007E8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808007EC: jal         0x800880B0
    // 0x808007F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _gcdialogcamera_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808007F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_6:
    // 0x808007F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007FC: jal         0x80089570
    // 0x80800800: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    _ncpod_entrypoint_22(rdram, ctx);
        goto after_7;
    // 0x80800800: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x80800804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080080C: jr          $ra
    // 0x80800810: nop

    return;
    // 0x80800810: nop

;}
RECOMP_FUNC void func_80803F6C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803F74: jal         0x808090D8
    // 0x80803F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808090D8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803F7C: jal         0x80807C8C
    // 0x80803F80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80803F80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80803F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803F8C: jr          $ra
    // 0x80803F90: nop

    return;
    // 0x80803F90: nop

;}
RECOMP_FUNC void func_800B5DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5DFC: jr          $ra
    // 0x800B5E00: nop

    return;
    // 0x800B5E00: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x8080048C: jal         0x80800194
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800194_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void chegggrenade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800304: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800308: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080030C: jal         0x8008A488
    // 0x80800310: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800310: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800314: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x80800318: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080031C: jal         0x8008A3D0
    // 0x80800320: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800320: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800324: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2116, 0X444) << 16);
    // 0x80800328: lwc1        $f4, 0x444($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2116, 0X444));
    // 0x8080032C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800334: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800338: jal         0x8008A380
    // 0x8080033C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080033C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: jal         0x8008A460
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080034C: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x80800350: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x80800354: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x80800358: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8080035C: jal         0x8008A468
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x8008A470
    // 0x8080036C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x8080036C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800370: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x80800374: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800378: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8080037C: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800380: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x80800384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800388: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void func_800F9C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9C6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F9C70: lbu         $t6, 0x5520($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5520);
    // 0x800F9C74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F9C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9C7C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x800F9C80: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x800F9C84: beq         $at, $zero, L_800F9EAC
    if (ctx->r1 == 0) {
        // 0x800F9C88: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800F9EAC;
    }
    // 0x800F9C88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F9C8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F9C90: addu        $at, $at, $t7
    gpr jr_addend_800F9C98 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800F9C94: lw          $t7, 0x60F0($at)
    ctx->r15 = ADD32(ctx->r1, 0X60F0);
    // 0x800F9C98: jr          $t7
    // 0x800F9C9C: nop

    switch (jr_addend_800F9C98 >> 2) {
        case 0: goto L_800F9CA0; break;
        case 1: goto L_800F9CC0; break;
        case 2: goto L_800F9CE0; break;
        case 3: goto L_800F9D00; break;
        case 4: goto L_800F9D10; break;
        case 5: goto L_800F9D30; break;
        case 6: goto L_800F9D50; break;
        case 7: goto L_800F9D60; break;
        case 8: goto L_800F9D80; break;
        case 9: goto L_800F9D90; break;
        case 10: goto L_800F9DA0; break;
        case 11: goto L_800F9DDC; break;
        case 12: goto L_800F9DFC; break;
        case 13: goto L_800F9E0C; break;
        case 14: goto L_800F9E2C; break;
        case 15: goto L_800F9E3C; break;
        case 16: goto L_800F9E4C; break;
        case 17: goto L_800F9E88; break;
        default: switch_error(__func__, 0x800F9C98, 0x801260F0);
    }
    // 0x800F9C9C: nop

L_800F9CA0:
    // 0x800F9CA0: jal         0x800C9510
    // 0x800F9CA4: nop

    func_800C9510(rdram, ctx);
        goto after_0;
    // 0x800F9CA4: nop

    after_0:
    // 0x800F9CA8: bnel        $v0, $zero, L_800F9EB0
    if (ctx->r2 != 0) {
        // 0x800F9CAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_0;
    // 0x800F9CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F9CB0: jal         0x800F9488
    // 0x800F9CB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800F9488(rdram, ctx);
        goto after_1;
    // 0x800F9CB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x800F9CB8: b           L_800F9EB0
    // 0x800F9CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9CC0:
    // 0x800F9CC0: jal         0x800C95D4
    // 0x800F9CC4: nop

    func_800C95D4(rdram, ctx);
        goto after_2;
    // 0x800F9CC4: nop

    after_2:
    // 0x800F9CC8: beql        $v0, $zero, L_800F9EB0
    if (ctx->r2 == 0) {
        // 0x800F9CCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_1;
    // 0x800F9CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800F9CD0: jal         0x800F9488
    // 0x800F9CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_3;
    // 0x800F9CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800F9CD8: b           L_800F9EB0
    // 0x800F9CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9CE0:
    // 0x800F9CE0: jal         0x800C9510
    // 0x800F9CE4: nop

    func_800C9510(rdram, ctx);
        goto after_4;
    // 0x800F9CE4: nop

    after_4:
    // 0x800F9CE8: bnel        $v0, $zero, L_800F9EB0
    if (ctx->r2 != 0) {
        // 0x800F9CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_2;
    // 0x800F9CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800F9CF0: jal         0x800F9488
    // 0x800F9CF4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800F9488(rdram, ctx);
        goto after_5;
    // 0x800F9CF4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x800F9CF8: b           L_800F9EB0
    // 0x800F9CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D00:
    // 0x800F9D00: jal         0x800F9488
    // 0x800F9D04: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800F9488(rdram, ctx);
        goto after_6;
    // 0x800F9D04: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
    // 0x800F9D08: b           L_800F9EB0
    // 0x800F9D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D10:
    // 0x800F9D10: jal         0x800C95D4
    // 0x800F9D14: nop

    func_800C95D4(rdram, ctx);
        goto after_7;
    // 0x800F9D14: nop

    after_7:
    // 0x800F9D18: beql        $v0, $zero, L_800F9EB0
    if (ctx->r2 == 0) {
        // 0x800F9D1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_3;
    // 0x800F9D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800F9D20: jal         0x800F9488
    // 0x800F9D24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_8;
    // 0x800F9D24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800F9D28: b           L_800F9EB0
    // 0x800F9D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D30:
    // 0x800F9D30: jal         0x800C9510
    // 0x800F9D34: nop

    func_800C9510(rdram, ctx);
        goto after_9;
    // 0x800F9D34: nop

    after_9:
    // 0x800F9D38: bnel        $v0, $zero, L_800F9EB0
    if (ctx->r2 != 0) {
        // 0x800F9D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_4;
    // 0x800F9D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800F9D40: jal         0x800F9488
    // 0x800F9D44: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800F9488(rdram, ctx);
        goto after_10;
    // 0x800F9D44: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_10:
    // 0x800F9D48: b           L_800F9EB0
    // 0x800F9D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D50:
    // 0x800F9D50: jal         0x800F9488
    // 0x800F9D54: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800F9488(rdram, ctx);
        goto after_11;
    // 0x800F9D54: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_11:
    // 0x800F9D58: b           L_800F9EB0
    // 0x800F9D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D60:
    // 0x800F9D60: jal         0x800C95D4
    // 0x800F9D64: nop

    func_800C95D4(rdram, ctx);
        goto after_12;
    // 0x800F9D64: nop

    after_12:
    // 0x800F9D68: beql        $v0, $zero, L_800F9EB0
    if (ctx->r2 == 0) {
        // 0x800F9D6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_5;
    // 0x800F9D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800F9D70: jal         0x800F9488
    // 0x800F9D74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_13;
    // 0x800F9D74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x800F9D78: b           L_800F9EB0
    // 0x800F9D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D80:
    // 0x800F9D80: jal         0x800F9488
    // 0x800F9D84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_14;
    // 0x800F9D84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
    // 0x800F9D88: b           L_800F9EB0
    // 0x800F9D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9D90:
    // 0x800F9D90: jal         0x800F9488
    // 0x800F9D94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_15;
    // 0x800F9D94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x800F9D98: b           L_800F9EB0
    // 0x800F9D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9DA0:
    // 0x800F9DA0: jal         0x800F929C
    // 0x800F9DA4: nop

    func_800F929C(rdram, ctx);
        goto after_16;
    // 0x800F9DA4: nop

    after_16:
    // 0x800F9DA8: jal         0x800878A0
    // 0x800F9DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plsu_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x800F9DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x800F9DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F9DB4: bne         $v0, $at, L_800F9DCC
    if (ctx->r2 != ctx->r1) {
        // 0x800F9DB8: nop
    
            goto L_800F9DCC;
    }
    // 0x800F9DB8: nop

    // 0x800F9DBC: jal         0x800F9488
    // 0x800F9DC0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800F9488(rdram, ctx);
        goto after_18;
    // 0x800F9DC0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_18:
    // 0x800F9DC4: b           L_800F9EB0
    // 0x800F9DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9DCC:
    // 0x800F9DCC: jal         0x800F9488
    // 0x800F9DD0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F9488(rdram, ctx);
        goto after_19;
    // 0x800F9DD0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_19:
    // 0x800F9DD4: b           L_800F9EB0
    // 0x800F9DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9DDC:
    // 0x800F9DDC: jal         0x800C9510
    // 0x800F9DE0: nop

    func_800C9510(rdram, ctx);
        goto after_20;
    // 0x800F9DE0: nop

    after_20:
    // 0x800F9DE4: bnel        $v0, $zero, L_800F9EB0
    if (ctx->r2 != 0) {
        // 0x800F9DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_6;
    // 0x800F9DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800F9DEC: jal         0x800F9488
    // 0x800F9DF0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800F9488(rdram, ctx);
        goto after_21;
    // 0x800F9DF0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_21:
    // 0x800F9DF4: b           L_800F9EB0
    // 0x800F9DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9DFC:
    // 0x800F9DFC: jal         0x800F9488
    // 0x800F9E00: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800F9488(rdram, ctx);
        goto after_22;
    // 0x800F9E00: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_22:
    // 0x800F9E04: b           L_800F9EB0
    // 0x800F9E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E0C:
    // 0x800F9E0C: jal         0x800C95D4
    // 0x800F9E10: nop

    func_800C95D4(rdram, ctx);
        goto after_23;
    // 0x800F9E10: nop

    after_23:
    // 0x800F9E14: beql        $v0, $zero, L_800F9EB0
    if (ctx->r2 == 0) {
        // 0x800F9E18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_7;
    // 0x800F9E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x800F9E1C: jal         0x800F9488
    // 0x800F9E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_24;
    // 0x800F9E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x800F9E24: b           L_800F9EB0
    // 0x800F9E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E2C:
    // 0x800F9E2C: jal         0x800F9488
    // 0x800F9E30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_25;
    // 0x800F9E30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
    // 0x800F9E34: b           L_800F9EB0
    // 0x800F9E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E3C:
    // 0x800F9E3C: jal         0x800F9488
    // 0x800F9E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_26;
    // 0x800F9E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_26:
    // 0x800F9E44: b           L_800F9EB0
    // 0x800F9E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E4C:
    // 0x800F9E4C: jal         0x800F8A5C
    // 0x800F9E50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F8A5C(rdram, ctx);
        goto after_27;
    // 0x800F9E50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_27:
    // 0x800F9E54: jal         0x800EA05C
    // 0x800F9E58: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_28;
    // 0x800F9E58: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_28:
    // 0x800F9E5C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800F9E60: bne         $v0, $t8, L_800F9E78
    if (ctx->r2 != ctx->r24) {
        // 0x800F9E64: nop
    
            goto L_800F9E78;
    }
    // 0x800F9E64: nop

    // 0x800F9E68: jal         0x800F9488
    // 0x800F9E6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800F9488(rdram, ctx);
        goto after_29;
    // 0x800F9E6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_29:
    // 0x800F9E70: b           L_800F9EB0
    // 0x800F9E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E78:
    // 0x800F9E78: jal         0x800F9488
    // 0x800F9E7C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800F9488(rdram, ctx);
        goto after_30;
    // 0x800F9E7C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_30:
    // 0x800F9E80: b           L_800F9EB0
    // 0x800F9E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9EB0;
    // 0x800F9E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9E88:
    // 0x800F9E88: jal         0x800F8A5C
    // 0x800F9E8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F8A5C(rdram, ctx);
        goto after_31;
    // 0x800F9E8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_31:
    // 0x800F9E90: jal         0x800EA05C
    // 0x800F9E94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_32;
    // 0x800F9E94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_32:
    // 0x800F9E98: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800F9E9C: bnel        $v0, $t9, L_800F9EB0
    if (ctx->r2 != ctx->r25) {
        // 0x800F9EA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9EB0;
    }
    goto skip_8;
    // 0x800F9EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800F9EA4: jal         0x800F9488
    // 0x800F9EA8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800F9488(rdram, ctx);
        goto after_33;
    // 0x800F9EA8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_33:
L_800F9EAC:
    // 0x800F9EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9EB0:
    // 0x800F9EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F9EB4: jr          $ra
    // 0x800F9EB8: nop

    return;
    // 0x800F9EB8: nop

    // 0x800F9EBC: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EB8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EB8);
    return;
    // 0x80083EBC: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_800D3724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3724: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D3728: addiu       $t7, $t7, -0x4AA0
    ctx->r15 = ADD32(ctx->r15, -0X4AA0);
    // 0x800D372C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3730: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D3734: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800D3738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D373C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3740: beq         $t8, $zero, L_800D3758
    if (ctx->r24 == 0) {
        // 0x800D3744: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800D3758;
    }
    // 0x800D3744: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D3748: jal         0x800D6C34
    // 0x800D374C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_800D6C34(rdram, ctx);
        goto after_0;
    // 0x800D374C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_0:
    // 0x800D3750: b           L_800D3758
    // 0x800D3754: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D3758;
    // 0x800D3754: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D3758:
    // 0x800D3758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D375C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3760: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D3764: jr          $ra
    // 0x800D3768: nop

    return;
    // 0x800D3768: nop

    // 0x800D376C: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B58: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B58);
    return;
    // 0x80083B5C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsbswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1ED0) << 16);
    // 0x808010AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010B0: jr          $ra
    // 0x808010B4: lw          $v0, 0x1ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1ED0));
    return;
    // 0x808010B4: lw          $v0, 0x1ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1ED0));
;}
RECOMP_FUNC void func_8080003C_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2204, 0X25A8) << 16);
    // 0x80800044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080004C: addiu       $t6, $t6, 0x25A8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2204, 0X25A8));
    // 0x80800050: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800054: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080005C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800060: jal         0x800BBCB8
    // 0x80800064: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800064: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_808002B4_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002C4: jal         0x80106790
    // 0x808002C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002D0: jal         0x8008FCF4
    // 0x808002D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008FCF4(rdram, ctx);
        goto after_1;
    // 0x808002D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002DC: bnel        $v0, $at, L_80800328
    if (ctx->r2 != ctx->r1) {
        // 0x808002E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800328;
    }
    goto skip_0;
    // 0x808002E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002E4: jal         0x800880D0
    // 0x808002E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808002E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80102424
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002F8: jal         0x8010A570
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80103110
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080030C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800314: lhu         $t7, 0x1A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1A);
    // 0x80800318: srl         $a0, $t7, 5
    ctx->r4 = S32(U32(ctx->r15) >> 5);
    // 0x8080031C: jal         0x800F7F98
    // 0x80800320: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    func_800F7F98(rdram, ctx);
        goto after_6;
    // 0x80800320: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    after_6:
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800328:
    // 0x80800328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void func_80800140_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: beq         $a1, $at, L_80800194
    if (ctx->r5 == ctx->r1) {
        // 0x80800150: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800194;
    }
    // 0x80800150: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800154: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800158: beq         $a1, $at, L_80800178
    if (ctx->r5 == ctx->r1) {
        // 0x8080015C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800178;
    }
    // 0x8080015C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800160: bne         $a1, $at, L_808001A4
    if (ctx->r5 != ctx->r1) {
        // 0x80800164: nop
    
            goto L_808001A4;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x80109EEC
    // 0x8080016C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80109EEC(rdram, ctx);
        goto after_0;
    // 0x8080016C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_0:
    // 0x80800170: b           L_808001B0
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001B0;
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800178:
    // 0x80800178: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800180: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800184: jal         0x8008A4B0
    // 0x80800188: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800188: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_1:
    // 0x8080018C: b           L_808001B0
    // 0x80800190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001B0;
    // 0x80800190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800194:
    // 0x80800194: jal         0x800FFAB0
    // 0x80800198: nop

    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800198: nop

    after_2:
    // 0x8080019C: b           L_808001B0
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001B0;
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A4:
    // 0x808001A4: b           L_808001B0
    // 0x808001A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001B0;
    // 0x808001A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001B0:
    // 0x808001B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void func_80800634_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800638: addiu       $v1, $v1, 0x7194
    ctx->r3 = ADD32(ctx->r3, 0X7194);
    // 0x8080063C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800648: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080064C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80800650: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80800654: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x80800658: bgez        $t9, L_80800678
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080065C: sll         $t1, $v0, 11
        ctx->r9 = S32(ctx->r2 << 11);
            goto L_80800678;
    }
    // 0x8080065C: sll         $t1, $v0, 11
    ctx->r9 = S32(ctx->r2 << 11);
    // 0x80800660: bgez        $t1, L_80800670
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800664: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800670;
    }
    // 0x80800664: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800668: b           L_80800670
    // 0x8080066C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80800670;
    // 0x8080066C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80800670:
    // 0x80800670: jal         0x8010DCB4
    // 0x80800674: nop

    func_8010DCB4(rdram, ctx);
        goto after_0;
    // 0x80800674: nop

    after_0:
L_80800678:
    // 0x80800678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080067C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void func_808000B8_chtransparencypot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000D0: bne         $t7, $at, L_808000F4
    if (ctx->r15 != ctx->r1) {
        // 0x808000D4: addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
            goto L_808000F4;
    }
    // 0x808000D4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x808000D8: jal         0x800D9078
    // 0x808000DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808000F4;
    }
    // 0x808000E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000EC: jal         0x8080001C
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080001C_chtransparencypot(rdram, ctx);
        goto after_1;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808000F4:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_808000A8_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000B0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: jal         0x80100094
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000CC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: beq         $a2, $at, L_80800128
    if (ctx->r6 == ctx->r1) {
        // 0x808000DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800128;
    }
    // 0x808000DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000E0: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x808000E4: beq         $a2, $at, L_80800114
    if (ctx->r6 == ctx->r1) {
        // 0x808000E8: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_80800114;
    }
    // 0x808000E8: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x808000EC: beq         $a2, $at, L_80800104
    if (ctx->r6 == ctx->r1) {
        // 0x808000F0: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80800104;
    }
    // 0x808000F0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x808000F4: beq         $a2, $at, L_80800114
    if (ctx->r6 == ctx->r1) {
        // 0x808000F8: nop
    
            goto L_80800114;
    }
    // 0x808000F8: nop

    // 0x808000FC: b           L_80800154
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800154;
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800104:
    // 0x80800104: jal         0x800FFAB0
    // 0x80800108: nop

    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800108: nop

    after_1:
    // 0x8080010C: b           L_80800154
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: jal         0x80100094
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080011C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800120: b           L_80800150
    // 0x80800124: sw          $t6, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r14;
        goto L_80800150;
    // 0x80800124: sw          $t6, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r14;
L_80800128:
    // 0x80800128: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080012C: jal         0x80800718
    // 0x80800130: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80800718_cheggproximity(rdram, ctx);
        goto after_3;
    // 0x80800130: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800134: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lbu         $t8, 0x39($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X39);
    // 0x8080013C: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80800140: b           L_80800150
    // 0x80800144: sb          $t9, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r25;
        goto L_80800150;
    // 0x80800144: sb          $t9, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r25;
    // 0x80800148: b           L_80800154
    // 0x8080014C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800154;
    // 0x8080014C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800150:
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800154:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_800936CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800936CC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800936D0: jr          $ra
    // 0x800936D4: sb          $a1, 0xA2($t6)
    MEM_B(0XA2, ctx->r14) = ctx->r5;
    return;
    // 0x800936D4: sb          $a1, 0xA2($t6)
    MEM_B(0XA2, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800984_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080098C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800990: jal         0x80085808
    // 0x80800994: addiu       $a1, $zero, 0x329
    ctx->r5 = ADD32(0, 0X329);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800994: addiu       $a1, $zero, 0x329
    ctx->r5 = ADD32(0, 0X329);
    after_0:
    // 0x80800998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080099C: jal         0x80085810
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808009A4: jal         0x80085818
    // 0x808009A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808009A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808009AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B4: jr          $ra
    // 0x808009B8: nop

    return;
    // 0x808009B8: nop

;}
RECOMP_FUNC void idscroll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800078: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080007C: jal         0x800D8FF8
    // 0x80800080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800084: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80800094: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800098: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080009C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000A0: addiu       $a2, $a2, -0x7258
    ctx->r6 = ADD32(ctx->r6, -0X7258);
    // 0x808000A4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808000A8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808000AC: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x808000B0: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808000B4: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x808000B8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x808000BC: nop

    // 0x808000C0: slti        $at, $v0, 0x2001
    ctx->r1 = SIGNED(ctx->r2) < 0X2001 ? 1 : 0;
    // 0x808000C4: bne         $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x808000C8: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808000EC;
    }
    // 0x808000C8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808000CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D0: nop

    // 0x808000D4: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x808000D8: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x808000DC: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808000E0: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808000E4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808000E8: nop

L_808000EC:
    // 0x808000EC: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x808000F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000F4: jal         0x80088660
    // 0x808000F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

    // 0x8080010C: nop

;}
RECOMP_FUNC void func_80800FC4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800FD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FD8: jal         0x80100094
    // 0x80800FDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800FE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800FE8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FEC: lhu         $t6, 0x72($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X72);
    // 0x80800FF0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800FF8: bnel        $t7, $at, L_80801078
    if (ctx->r15 != ctx->r1) {
        // 0x80800FFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801078;
    }
    goto skip_0;
    // 0x80800FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801000: bgez        $a2, L_8080101C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80801004: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8080101C;
    }
    // 0x80801004: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80801008: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8080100C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80801010: negu        $t2, $a2
    ctx->r10 = SUB32(0, ctx->r6);
    // 0x80801014: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80801018: bne         $at, $zero, L_80801074
    if (ctx->r1 != 0) {
        // 0x8080101C: sll         $a0, $a1, 2
        ctx->r4 = S32(ctx->r5 << 2);
            goto L_80801074;
    }
L_8080101C:
    // 0x8080101C: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80801020: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80801024: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x80801028: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x8080102C: blez        $a2, L_80801058
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801030: sw          $t4, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r12;
            goto L_80801058;
    }
    // 0x80801030: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x80801034: bne         $a0, $zero, L_80801074
    if (ctx->r4 != 0) {
        // 0x80801038: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801074;
    }
    // 0x80801038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080103C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1752, 0X4D34) << 16);
    // 0x80801040: addiu       $a3, $a3, 0x4D34
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4D34));
    // 0x80801044: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801048: jal         0x8010D930
    // 0x8080104C: addiu       $a2, $t0, 0x4
    ctx->r6 = ADD32(ctx->r8, 0X4);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x8080104C: addiu       $a2, $t0, 0x4
    ctx->r6 = ADD32(ctx->r8, 0X4);
    after_1:
    // 0x80801050: b           L_80801078
    // 0x80801054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801078;
    // 0x80801054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801058:
    // 0x80801058: bne         $a0, $zero, L_80801074
    if (ctx->r4 != 0) {
        // 0x8080105C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801074;
    }
    // 0x8080105C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801060: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1752, 0X4D20) << 16);
    // 0x80801064: addiu       $a3, $a3, 0x4D20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4D20));
    // 0x80801068: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080106C: jal         0x8010D930
    // 0x80801070: addiu       $a2, $t0, 0x4
    ctx->r6 = ADD32(ctx->r8, 0X4);
    func_8010D930(rdram, ctx);
        goto after_2;
    // 0x80801070: addiu       $a2, $t0, 0x4
    ctx->r6 = ADD32(ctx->r8, 0X4);
    after_2:
L_80801074:
    // 0x80801074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801078:
    // 0x80801078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080107C: jr          $ra
    // 0x80801080: nop

    return;
    // 0x80801080: nop

;}
RECOMP_FUNC void func_808004DC_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808004EC: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
    // 0x808004F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808004F4: andi        $a2, $a3, 0xFFFF
    ctx->r6 = ctx->r7 & 0XFFFF;
    // 0x808004F8: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x808004FC: lwc1        $f6, 0x4C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x80800500: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x80800504: lwc1        $f8, 0x48($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80800508: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
    // 0x8080050C: lwc1        $f10, 0x38($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80800510: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80800514: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800518: jal         0x80103140
    // 0x8080051C: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x8080051C: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    after_0:
    // 0x80800520: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800524: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800528: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
    // 0x8080052C: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80800530: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800534: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80800538: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080053C: sb          $t1, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r9;
    // 0x80800540: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x80800544: andi        $t9, $t7, 0xFFF1
    ctx->r25 = ctx->r15 & 0XFFF1;
    // 0x80800548: sll         $t3, $t2, 20
    ctx->r11 = S32(ctx->r10 << 20);
    // 0x8080054C: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x80800550: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800554: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x80800558: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x8080055C: sb          $t5, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r13;
    // 0x80800560: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x80800564: andi        $t7, $t5, 0xCF
    ctx->r15 = ctx->r13 & 0XCF;
    // 0x80800568: sll         $t1, $t0, 18
    ctx->r9 = S32(ctx->r8 << 18);
    // 0x8080056C: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80800570: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800574: andi        $t4, $t3, 0x30
    ctx->r12 = ctx->r11 & 0X30;
    // 0x80800578: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x8080057C: sb          $t6, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r14;
    // 0x80800580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080058C: jr          $ra
    // 0x80800590: nop

    return;
    // 0x80800590: nop

;}
RECOMP_FUNC void func_80802164_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802164: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080216C: jal         0x800DB9B0
    // 0x80802170: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80802170: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802174: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802178: jal         0x8010A654
    // 0x8080217C: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_8010A654(rdram, ctx);
        goto after_1;
    // 0x8080217C: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_1:
    // 0x80802180: jal         0x800DA298
    // 0x80802184: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80802184: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_2:
    // 0x80802188: beql        $v0, $zero, L_8080228C
    if (ctx->r2 == 0) {
        // 0x8080218C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080228C;
    }
    goto skip_0;
    // 0x8080218C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80802190: jal         0x8010D254
    // 0x80802194: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8010D254(rdram, ctx);
        goto after_3;
    // 0x80802194: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80802198: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X26AC) << 16);
    // 0x8080219C: addiu       $a2, $a2, 0x26AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X26AC));
    // 0x808021A0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808021A4: jal         0x800F0064
    // 0x808021A8: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    func_800F0064(rdram, ctx);
        goto after_4;
    // 0x808021A8: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    after_4:
    // 0x808021AC: beq         $v0, $zero, L_80802220
    if (ctx->r2 == 0) {
        // 0x808021B0: lwc1        $f0, 0x30($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80802220;
    }
    // 0x808021B0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808021B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X26B0) << 16);
    // 0x808021B8: lwc1        $f4, 0x26B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X26B0));
    // 0x808021BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X26BC) << 16);
    // 0x808021C0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808021C4: nop

    // 0x808021C8: bc1fl       L_80802224
    if (!c1cs) {
        // 0x808021CC: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80802224;
    }
    goto skip_1;
    // 0x808021CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x808021D0: lwc1        $f6, 0x26BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X26BC));
    // 0x808021D4: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x808021D8: nop

    // 0x808021DC: bc1fl       L_80802224
    if (!c1cs) {
        // 0x808021E0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80802224;
    }
    goto skip_2;
    // 0x808021E0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x808021E4: jal         0x800F54E4
    // 0x808021E8: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808021E8: nop

    after_5:
    // 0x808021EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808021F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X26AC) << 16);
    // 0x808021F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X26B8) << 16);
    // 0x808021F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808021FC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80802200: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80802204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802208: addiu       $a2, $a2, 0x26B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X26B8));
    // 0x8080220C: addiu       $a1, $a1, 0x26AC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X26AC));
    // 0x80802210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802214: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x80802218: jal         0x800F7F00
    // 0x8080221C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800F7F00(rdram, ctx);
        goto after_6;
    // 0x8080221C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_6:
L_80802220:
    // 0x80802220: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_80802224:
    // 0x80802224: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x80802228: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x8080222C: bgezl       $t1, L_80802258
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802230: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80802258;
    }
    goto skip_3;
    // 0x80802230: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x80802234: jal         0x80090178
    // 0x80802238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_7;
    // 0x80802238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8080223C: bne         $v0, $zero, L_80802254
    if (ctx->r2 != 0) {
        // 0x80802240: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1700, 0X26C4) << 16);
            goto L_80802254;
    }
    // 0x80802240: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1700, 0X26C4) << 16);
    // 0x80802244: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X26D0) << 16);
    // 0x80802248: addiu       $a1, $a1, 0x26D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X26D0));
    // 0x8080224C: jal         0x8008FA94
    // 0x80802250: addiu       $a0, $a0, 0x26C4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1700, 0X26C4));
    func_8008FA94(rdram, ctx);
        goto after_8;
    // 0x80802250: addiu       $a0, $a0, 0x26C4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1700, 0X26C4));
    after_8:
L_80802254:
    // 0x80802254: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_80802258:
    // 0x80802258: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x8080225C: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80802260: bgezl       $t5, L_8080228C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80802264: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080228C;
    }
    goto skip_4;
    // 0x80802264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80802268: jal         0x80090178
    // 0x8080226C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80090178(rdram, ctx);
        goto after_9;
    // 0x8080226C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
    // 0x80802270: bne         $v0, $zero, L_80802288
    if (ctx->r2 != 0) {
        // 0x80802274: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1700, 0X26DC) << 16);
            goto L_80802288;
    }
    // 0x80802274: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1700, 0X26DC) << 16);
    // 0x80802278: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X26E8) << 16);
    // 0x8080227C: addiu       $a1, $a1, 0x26E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X26E8));
    // 0x80802280: jal         0x8008FA94
    // 0x80802284: addiu       $a0, $a0, 0x26DC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1700, 0X26DC));
    func_8008FA94(rdram, ctx);
        goto after_10;
    // 0x80802284: addiu       $a0, $a0, 0x26DC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1700, 0X26DC));
    after_10:
L_80802288:
    // 0x80802288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080228C:
    // 0x8080228C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802290: jr          $ra
    // 0x80802294: nop

    return;
    // 0x80802294: nop

;}
RECOMP_FUNC void func_80800674_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080067C: jal         0x80800098
    // 0x80800680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x80800680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800684: jal         0x80082FE0
    // 0x80800688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void func_808003FC_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080040C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800410: jal         0x80100094
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800418: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080041C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800420: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800424: jal         0x800EE7F8
    // 0x80800428: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800428: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x8080042C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80800430: addiu       $a1, $s1, 0x24
    ctx->r5 = ADD32(ctx->r17, 0X24);
    // 0x80800434: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800438: jal         0x800EE7F8
    // 0x8080043C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080043C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800440: jal         0x80105BAC
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_3;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x80105230
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_4;
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800454: jal         0x80105834
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_5;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080045C: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x80800460: jal         0x800EE7F8
    // 0x80800464: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800464: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jal         0x800EE7F8
    // 0x80800470: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800470: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800474: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800478: jal         0x800EE7F8
    // 0x8080047C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080047C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80800480: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800484: jal         0x800EE7F8
    // 0x80800488: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800488: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    after_9:
    // 0x8080048C: jal         0x80105A5C
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_10;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800494: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x80800498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B0;
    }
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808004A0: jal         0x80800268
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800268_chnastycavemen(rdram, ctx);
        goto after_11;
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x808004A8: jal         0x80088830
    // 0x808004AC: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_12;
    // 0x808004AC: nop

    after_12:
L_808004B0:
    // 0x808004B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004BC: jr          $ra
    // 0x808004C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808004C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808004D8_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E0: jal         0x80800000
    // 0x808004E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsride(rdram, ctx);
        goto after_0;
    // 0x808004E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004E8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808004EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808004F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004F4: jal         0x8008CB3C
    // 0x808004F8: addiu       $a1, $zero, 0x281
    ctx->r5 = ADD32(0, 0X281);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808004F8: addiu       $a1, $zero, 0x281
    ctx->r5 = ADD32(0, 0X281);
    after_1:
    // 0x808004FC: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80800500: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800504: jal         0x80093230
    // 0x80800508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80093230(rdram, ctx);
        goto after_2;
    // 0x80800508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080050C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: sw          $zero, 0x160($t6)
    MEM_W(0X160, ctx->r14) = 0;
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void func_808008DC_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008E8: jal         0x800D9078
    // 0x808008EC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808008EC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x808008F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x808008F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808008FC: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800900: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800904: nop

    // 0x80800908: bc1fl       L_80800938
    if (!c1cs) {
        // 0x8080090C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800938;
    }
    goto skip_0;
    // 0x8080090C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800910: jal         0x800889A0
    // 0x80800914: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800914: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80800918: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X129C) << 16);
    // 0x8080091C: lwc1        $f12, 0x129C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X129C));
    // 0x80800920: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X12A0) << 16);
    // 0x80800924: jal         0x800DC178
    // 0x80800928: lwc1        $f14, 0x12A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X12A0));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800928: lwc1        $f14, 0x12A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X12A0));
    after_2:
    // 0x8080092C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800930: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x80800934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800938:
    // 0x80800938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void func_80800938_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800938: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080093C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800940: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080094C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800950: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800954: jal         0x80100094
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080095C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800964: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800968: beq         $a2, $at, L_808009A8
    if (ctx->r6 == ctx->r1) {
        // 0x8080096C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_808009A8;
    }
    // 0x8080096C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80800970: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800974: beq         $a2, $at, L_808009B8
    if (ctx->r6 == ctx->r1) {
        // 0x80800978: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_808009B8;
    }
    // 0x80800978: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080097C: beq         $a2, $at, L_80800B5C
    if (ctx->r6 == ctx->r1) {
        // 0x80800980: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_80800B5C;
    }
    // 0x80800980: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800984: beq         $a2, $at, L_80800B78
    if (ctx->r6 == ctx->r1) {
        // 0x80800988: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80800B78;
    }
    // 0x80800988: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080098C: beq         $a2, $at, L_80800C28
    if (ctx->r6 == ctx->r1) {
        // 0x80800990: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_80800C28;
    }
    // 0x80800990: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800994: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800998: beq         $a2, $at, L_80800A74
    if (ctx->r6 == ctx->r1) {
        // 0x8080099C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A74;
    }
    // 0x8080099C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009A0: b           L_80800C90
    // 0x808009A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C90;
    // 0x808009A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009A8:
    // 0x808009A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808009AC: sb          $v1, 0xC3($t0)
    MEM_B(0XC3, ctx->r8) = ctx->r3;
    // 0x808009B0: b           L_80800C90
    // 0x808009B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C90;
    // 0x808009B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808009B8:
    // 0x808009B8: lbu         $v0, 0x79($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X79);
    // 0x808009BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009C0: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x808009C4: beql        $t6, $zero, L_808009EC
    if (ctx->r14 == 0) {
        // 0x808009C8: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_808009EC;
    }
    goto skip_0;
    // 0x808009C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x808009CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009D0: beq         $t6, $at, L_80800A14
    if (ctx->r14 == ctx->r1) {
        // 0x808009D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A14;
    }
    // 0x808009D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009D8: beql        $t6, $at, L_80800A48
    if (ctx->r14 == ctx->r1) {
        // 0x808009DC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800A48;
    }
    goto skip_1;
    // 0x808009DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_1:
    // 0x808009E0: b           L_80800C90
    // 0x808009E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C90;
    // 0x808009E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808009E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_808009EC:
    // 0x808009EC: jal         0x80085728
    // 0x808009F0: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x808009F0: nop

    after_1:
    // 0x808009F4: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x808009F8: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800A6C;
    }
    // 0x808009F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808009FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A04: jal         0x80801A3C
    // 0x80800A08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A3C_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x80800A08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80800A0C: b           L_80800C90
    // 0x80800A10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C90;
    // 0x80800A10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A14:
    // 0x80800A14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A1C: jal         0x80085728
    // 0x80800A20: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800A20: nop

    after_3:
    // 0x80800A24: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x80800A28: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800A6C;
    }
    // 0x80800A28: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800A34: jal         0x80801A3C
    // 0x80800A38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A3C_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80800A38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800A3C: b           L_80800C90
    // 0x80800A40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C90;
    // 0x80800A40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800A44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800A48:
    // 0x80800A48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A4C: jal         0x80085728
    // 0x80800A50: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800A50: nop

    after_5:
    // 0x80800A54: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x80800A58: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800A6C;
    }
    // 0x80800A58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A64: jal         0x80801A3C
    // 0x80800A68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A3C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x80800A68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
L_80800A6C:
    // 0x80800A6C: b           L_80800C90
    // 0x80800A70: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C90;
    // 0x80800A70: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A74:
    // 0x80800A74: jal         0x80801844
    // 0x80800A78: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80801844_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80800A78: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_7:
    // 0x80800A7C: jal         0x800EA05C
    // 0x80800A80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x80800A80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_8:
    // 0x80800A84: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80800A88: beq         $v0, $at, L_80800A9C
    if (ctx->r2 == ctx->r1) {
        // 0x80800A8C: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A9C;
    }
    // 0x80800A8C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A90: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80800A94: beql        $v0, $at, L_80800AA0
    if (ctx->r2 == ctx->r1) {
        // 0x80800A98: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800AA0;
    }
    goto skip_2;
    // 0x80800A98: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_2:
L_80800A9C:
    // 0x80800A9C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80800AA0:
    // 0x80800AA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AA8: lbu         $v1, 0x79($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X79);
    // 0x80800AAC: srl         $t8, $v1, 4
    ctx->r24 = S32(U32(ctx->r3) >> 4);
    // 0x80800AB0: beq         $t8, $zero, L_80800AD8
    if (ctx->r24 == 0) {
        // 0x80800AB4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80800AD8;
    }
    // 0x80800AB4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80800AB8: beq         $t8, $at, L_80800AD8
    if (ctx->r24 == ctx->r1) {
        // 0x80800ABC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800AD8;
    }
    // 0x80800ABC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AC0: beq         $t8, $at, L_80800AD8
    if (ctx->r24 == ctx->r1) {
        // 0x80800AC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800AD8;
    }
    // 0x80800AC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800AC8: beq         $t8, $at, L_80800B44
    if (ctx->r24 == ctx->r1) {
        // 0x80800ACC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80800B44;
    }
    // 0x80800ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800AD0: b           L_80800C90
    // 0x80800AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AD8:
    // 0x80800AD8: addiu       $a0, $v1, 0x419
    ctx->r4 = ADD32(ctx->r3, 0X419);
    // 0x80800ADC: jal         0x800DA9E4
    // 0x80800AE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800DA9E4(rdram, ctx);
        goto after_9;
    // 0x80800AE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_9:
    // 0x80800AE4: bne         $v0, $zero, L_80800B28
    if (ctx->r2 != 0) {
        // 0x80800AE8: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B28;
    }
    // 0x80800AE8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AEC: jal         0x800D395C
    // 0x80800AF0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800D395C(rdram, ctx);
        goto after_10;
    // 0x80800AF0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_10:
    // 0x80800AF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800AF8: bne         $v0, $zero, L_80800B28
    if (ctx->r2 != 0) {
        // 0x80800AFC: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B28;
    }
    // 0x80800AFC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800B04: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B10: jal         0x80085708
    // 0x80800B14: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800B14: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    after_11:
    // 0x80800B18: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800B20: b           L_80800C8C
    // 0x80800B24: sb          $v1, 0xC6($t0)
    MEM_B(0XC6, ctx->r8) = ctx->r3;
        goto L_80800C8C;
    // 0x80800B24: sb          $v1, 0xC6($t0)
    MEM_B(0XC6, ctx->r8) = ctx->r3;
L_80800B28:
    // 0x80800B28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800B2C: sb          $v1, 0xC4($t0)
    MEM_B(0XC4, ctx->r8) = ctx->r3;
    // 0x80800B30: sb          $v1, 0xC3($t0)
    MEM_B(0XC3, ctx->r8) = ctx->r3;
    // 0x80800B34: jal         0x800A54F8
    // 0x80800B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A54F8(rdram, ctx);
        goto after_12;
    // 0x80800B38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80800B3C: b           L_80800C90
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B44:
    // 0x80800B44: sb          $v1, 0xC4($t0)
    MEM_B(0XC4, ctx->r8) = ctx->r3;
    // 0x80800B48: sb          $v1, 0xC3($t0)
    MEM_B(0XC3, ctx->r8) = ctx->r3;
    // 0x80800B4C: jal         0x8008A0A8
    // 0x80800B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800B54: b           L_80800C90
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B5C:
    // 0x80800B5C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800B60: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800B64: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800B68: jal         0x808006CC
    // 0x80800B6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808006CC_chdodgemcontrol(rdram, ctx);
        goto after_14;
    // 0x80800B6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_14:
    // 0x80800B70: b           L_80800C90
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B78:
    // 0x80800B78: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800B7C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80800B80: addiu       $t2, $t1, -0x10D4
    ctx->r10 = ADD32(ctx->r9, -0X10D4);
    // 0x80800B84: sltiu       $at, $t2, 0x29
    ctx->r1 = ctx->r10 < 0X29 ? 1 : 0;
    // 0x80800B88: beq         $at, $zero, L_80800C8C
    if (ctx->r1 == 0) {
        // 0x80800B8C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80800C8C;
    }
    // 0x80800B8C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800B90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4B4C) << 16);
    // 0x80800B94: addu        $at, $at, $t2
    gpr jr_addend_80800B9C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800B98: lw          $t2, 0x4B4C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4B4C));
    // 0x80800B9C: jr          $t2
    // 0x80800BA0: nop

    switch (jr_addend_80800B9C >> 2) {
        case 0: goto L_80800BE0; break;
        case 1: goto L_80800BE0; break;
        case 2: goto L_80800BE0; break;
        case 3: goto L_80800C18; break;
        case 4: goto L_80800C8C; break;
        case 5: goto L_80800BD8; break;
        case 6: goto L_80800C8C; break;
        case 7: goto L_80800C8C; break;
        case 8: goto L_80800C8C; break;
        case 9: goto L_80800C8C; break;
        case 10: goto L_80800C8C; break;
        case 11: goto L_80800C8C; break;
        case 12: goto L_80800C8C; break;
        case 13: goto L_80800C8C; break;
        case 14: goto L_80800C8C; break;
        case 15: goto L_80800C8C; break;
        case 16: goto L_80800C8C; break;
        case 17: goto L_80800C8C; break;
        case 18: goto L_80800C8C; break;
        case 19: goto L_80800C8C; break;
        case 20: goto L_80800C8C; break;
        case 21: goto L_80800C8C; break;
        case 22: goto L_80800C8C; break;
        case 23: goto L_80800C8C; break;
        case 24: goto L_80800BE0; break;
        case 25: goto L_80800BE8; break;
        case 26: goto L_80800BE0; break;
        case 27: goto L_80800BF8; break;
        case 28: goto L_80800BE0; break;
        case 29: goto L_80800C08; break;
        case 30: goto L_80800C8C; break;
        case 31: goto L_80800C8C; break;
        case 32: goto L_80800C8C; break;
        case 33: goto L_80800C8C; break;
        case 34: goto L_80800C8C; break;
        case 35: goto L_80800C8C; break;
        case 36: goto L_80800C8C; break;
        case 37: goto L_80800C8C; break;
        case 38: goto L_80800C8C; break;
        case 39: goto L_80800C8C; break;
        case 40: goto L_80800BA4; break;
        default: switch_error(__func__, 0x80800B9C, 0x80804B4C);
    }
    // 0x80800BA0: nop

L_80800BA4:
    // 0x80800BA4: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80800BA8: bnel        $t3, $zero, L_80800BC4
    if (ctx->r11 != 0) {
        // 0x80800BAC: lbu         $a0, 0x79($a3)
        ctx->r4 = MEM_BU(ctx->r7, 0X79);
            goto L_80800BC4;
    }
    goto skip_3;
    // 0x80800BAC: lbu         $a0, 0x79($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X79);
    skip_3:
    // 0x80800BB0: jal         0x808008EC
    // 0x80800BB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808008EC_chdodgemcontrol(rdram, ctx);
        goto after_15;
    // 0x80800BB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_15:
    // 0x80800BB8: b           L_80800C94
    // 0x80800BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC0: lbu         $a0, 0x79($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X79);
L_80800BC4:
    // 0x80800BC4: srl         $t4, $a0, 4
    ctx->r12 = S32(U32(ctx->r4) >> 4);
    // 0x80800BC8: jal         0x808005CC
    // 0x80800BCC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_808005CC_chdodgemcontrol(rdram, ctx);
        goto after_16;
    // 0x80800BCC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_16:
    // 0x80800BD0: b           L_80800C94
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BD8:
    // 0x80800BD8: b           L_80800C90
    // 0x80800BDC: lbu         $v0, 0xC1($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC1);
        goto L_80800C90;
    // 0x80800BDC: lbu         $v0, 0xC1($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC1);
L_80800BE0:
    // 0x80800BE0: b           L_80800C90
    // 0x80800BE4: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
        goto L_80800C90;
    // 0x80800BE4: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
L_80800BE8:
    // 0x80800BE8: jal         0x800D211C
    // 0x80800BEC: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800D211C(rdram, ctx);
        goto after_17;
    // 0x80800BEC: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_17:
    // 0x80800BF0: b           L_80800C94
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF8:
    // 0x80800BF8: jal         0x800D211C
    // 0x80800BFC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800D211C(rdram, ctx);
        goto after_18;
    // 0x80800BFC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_18:
    // 0x80800C00: b           L_80800C94
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C08:
    // 0x80800C08: jal         0x800D211C
    // 0x80800C0C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_800D211C(rdram, ctx);
        goto after_19;
    // 0x80800C0C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_19:
    // 0x80800C10: b           L_80800C94
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C18:
    // 0x80800C18: jal         0x808008EC
    // 0x80800C1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808008EC_chdodgemcontrol(rdram, ctx);
        goto after_20;
    // 0x80800C1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_20:
    // 0x80800C20: b           L_80800C94
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C28:
    // 0x80800C28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800C2C: bnel        $t5, $at, L_80800C90
    if (ctx->r13 != ctx->r1) {
        // 0x80800C30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800C90;
    }
    goto skip_4;
    // 0x80800C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80800C34: lbu         $t6, 0xC5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC5);
    // 0x80800C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800C40: blezl       $t6, L_80800C90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800C44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800C90;
    }
    goto skip_5;
    // 0x80800C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80800C48: lbu         $t7, 0xAC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XAC);
L_80800C4C:
    // 0x80800C4C: bnel        $t7, $zero, L_80800C68
    if (ctx->r15 != 0) {
        // 0x80800C50: lbu         $t8, 0xC5($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0XC5);
            goto L_80800C68;
    }
    goto skip_6;
    // 0x80800C50: lbu         $t8, 0xC5($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XC5);
    skip_6:
    // 0x80800C54: jal         0x808004E4
    // 0x80800C58: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808004E4_chdodgemcontrol(rdram, ctx);
        goto after_21;
    // 0x80800C58: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_21:
    // 0x80800C5C: b           L_80800C90
    // 0x80800C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C64: lbu         $t8, 0xC5($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XC5);
L_80800C68:
    // 0x80800C68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800C6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800C70: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800C74: bnel        $at, $zero, L_80800C4C
    if (ctx->r1 != 0) {
        // 0x80800C78: lbu         $t7, 0xAC($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0XAC);
            goto L_80800C4C;
    }
    goto skip_7;
    // 0x80800C78: lbu         $t7, 0xAC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XAC);
    skip_7:
    // 0x80800C7C: b           L_80800C90
    // 0x80800C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C90;
    // 0x80800C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C84: b           L_80800C90
    // 0x80800C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C90;
    // 0x80800C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C8C:
    // 0x80800C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C90:
    // 0x80800C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C94:
    // 0x80800C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C98: jr          $ra
    // 0x80800C9C: nop

    return;
    // 0x80800C9C: nop

;}
RECOMP_FUNC void bstnt_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FA4: jal         0x800852F0
    // 0x80800FA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800FA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800FAC: beq         $v0, $zero, L_80800FD0
    if (ctx->r2 == 0) {
        // 0x80800FB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FD0;
    }
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB8: jal         0x80092744
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092744(rdram, ctx);
        goto after_1;
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800FC0: jal         0x80084F58
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapulse_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800FC8: b           L_80801044
    // 0x80800FCC: sb          $zero, 0x168($s0)
    MEM_B(0X168, ctx->r16) = 0;
        goto L_80801044;
    // 0x80800FCC: sb          $zero, 0x168($s0)
    MEM_B(0X168, ctx->r16) = 0;
L_80800FD0:
    // 0x80800FD0: jal         0x80085300
    // 0x80800FD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_get(rdram, ctx);
        goto after_3;
    // 0x80800FD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800FD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800FDC: nop

    // 0x80800FE0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800FE4: nop

    // 0x80800FE8: bc1fl       L_80801044
    if (!c1cs) {
        // 0x80800FEC: sb          $zero, 0x168($s0)
        MEM_B(0X168, ctx->r16) = 0;
            goto L_80801044;
    }
    goto skip_0;
    // 0x80800FEC: sb          $zero, 0x168($s0)
    MEM_B(0X168, ctx->r16) = 0;
    skip_0:
    // 0x80800FF0: jal         0x80084F68
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapulse_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FF8: jal         0x80084F50
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapulse_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801000: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801004: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801008: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080100C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801010: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801014: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801018: jal         0x800F12D4
    // 0x8080101C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_6;
    // 0x8080101C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80801020: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801024: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80801028: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80801034: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80801038: jal         0x80092750
    // 0x8080103C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    func_80092750(rdram, ctx);
        goto after_7;
    // 0x8080103C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    after_7:
    // 0x80801040: sb          $zero, 0x168($s0)
    MEM_B(0X168, ctx->r16) = 0;
L_80801044:
    // 0x80801044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080104C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801050: jr          $ra
    // 0x80801054: nop

    return;
    // 0x80801054: nop

;}
RECOMP_FUNC void func_80801084_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801084: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80801088: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080108C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801090: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801098: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080109C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808010A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808010A4: jal         0x800F0064
    // 0x808010A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x808010A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x808010AC: beq         $v0, $zero, L_808011FC
    if (ctx->r2 == 0) {
        // 0x808010B0: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(1752, 0X4E0C) << 16);
            goto L_808011FC;
    }
    // 0x808010B0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1752, 0X4E0C) << 16);
    // 0x808010B4: addiu       $t7, $t7, 0x4E0C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1752, 0X4E0C));
    // 0x808010B8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808010BC: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x808010C0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x808010C4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808010C8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808010CC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x808010D0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808010D4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808010D8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808010DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808010E0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x808010E4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808010E8: jal         0x800EE7F8
    // 0x808010EC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808010EC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808010F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808010F4: jal         0x800EE7F8
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808010FC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801100: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801104: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80801108: nop

    // 0x8080110C: bc1fl       L_8080117C
    if (!c1cs) {
        // 0x80801110: sub.s       $f8, $f12, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8080117C;
    }
    goto skip_0;
    // 0x80801110: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    skip_0:
    // 0x80801114: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801118: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8080111C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80801120: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801124: nop

    // 0x80801128: bc1fl       L_8080117C
    if (!c1cs) {
        // 0x8080112C: sub.s       $f8, $f12, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8080117C;
    }
    goto skip_1;
    // 0x8080112C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x80801130: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801134: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801138: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080113C: jal         0x800DC178
    // 0x80801140: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801140: nop

    after_3:
    // 0x80801144: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801148: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8080114C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801150: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80801154: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801158: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080115C: jal         0x800DC178
    // 0x80801160: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801160: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80801164: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801168: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8080116C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801170: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80801174: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801178: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
L_8080117C:
    // 0x8080117C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801180: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80801184: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801188: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8080118C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80801190: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80801194: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801198: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8080119C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808011A0: jal         0x800EEF94
    // 0x808011A4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    func_800EEF94(rdram, ctx);
        goto after_5;
    // 0x808011A4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x808011A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808011AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808011B0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808011B4: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x808011B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808011BC: jal         0x800EF368
    // 0x808011C0: nop

    func_800EF368(rdram, ctx);
        goto after_6;
    // 0x808011C0: nop

    after_6:
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808011CC: jal         0x800EFB24
    // 0x808011D0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x808011D0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x808011D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808011D8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808011DC: jal         0x800EE780
    // 0x808011E0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x808011E0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x808011E4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808011E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808011EC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x808011F0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808011F4: b           L_80801200
    // 0x808011F8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
        goto L_80801200;
    // 0x808011F8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_808011FC:
    // 0x808011FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801200:
    // 0x80801200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801204: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801208: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080120C: jr          $ra
    // 0x80801210: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801210: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_808015F4_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808015F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801600: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801604: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80801608: jal         0x80100094
    // 0x8080160C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080160C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801610: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801614: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1332, 0X2F8C) << 16);
    // 0x80801618: addiu       $t8, $t8, 0x2F8C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1332, 0X2F8C));
    // 0x8080161C: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80801620: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80801624: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80801628: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8080162C: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x80801630: sb          $s0, 0x1B($t6)
    MEM_B(0X1B, ctx->r14) = ctx->r16;
    // 0x80801634: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x80801638: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8080163C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80801640: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80801644:
    // 0x80801644: bne         $t0, $s0, L_80801654
    if (ctx->r8 != ctx->r16) {
        // 0x80801648: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80801654;
    }
    // 0x80801648: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080164C: b           L_80801658
    // 0x80801650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80801658;
    // 0x80801650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801654:
    // 0x80801654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80801658:
    // 0x80801658: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x8080165C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80801660: addiu       $t2, $t2, 0x6
    ctx->r10 = ADD32(ctx->r10, 0X6);
    // 0x80801664: beq         $a3, $t9, L_8080168C
    if (ctx->r7 == ctx->r25) {
        // 0x80801668: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_8080168C;
    }
    // 0x80801668: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8080166C: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x80801670: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x80801674: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
L_80801678:
    // 0x80801678: sb          $a2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r6;
    // 0x8080167C: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x80801680: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80801684: bnel        $a3, $a1, L_80801678
    if (ctx->r7 != ctx->r5) {
        // 0x80801688: addu        $t5, $v0, $a1
        ctx->r13 = ADD32(ctx->r2, ctx->r5);
            goto L_80801678;
    }
    goto skip_0;
    // 0x80801688: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    skip_0:
L_8080168C:
    // 0x8080168C: bne         $t0, $t3, L_80801644
    if (ctx->r8 != ctx->r11) {
        // 0x80801690: addiu       $t1, $t1, 0x6
        ctx->r9 = ADD32(ctx->r9, 0X6);
            goto L_80801644;
    }
    // 0x80801690: addiu       $t1, $t1, 0x6
    ctx->r9 = ADD32(ctx->r9, 0X6);
    // 0x80801694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801698: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080169C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808016A0: jr          $ra
    // 0x808016A4: nop

    return;
    // 0x808016A4: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F80: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F80);
    return;
    // 0x80083F84: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80802114_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080211C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802120: jal         0x80100094
    // 0x80802124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802128: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080212C: jal         0x800D9078
    // 0x80802130: addiu       $a0, $v0, 0x5C
    ctx->r4 = ADD32(ctx->r2, 0X5C);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80802130: addiu       $a0, $v0, 0x5C
    ctx->r4 = ADD32(ctx->r2, 0X5C);
    after_1:
    // 0x80802134: beq         $v0, $zero, L_80802144
    if (ctx->r2 == 0) {
        // 0x80802138: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802144;
    }
    // 0x80802138: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080213C: jal         0x80109EF4
    // 0x80802140: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EF4(rdram, ctx);
        goto after_2;
    // 0x80802140: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
L_80802144:
    // 0x80802144: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802148: jal         0x800D9078
    // 0x8080214C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x8080214C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_3:
    // 0x80802150: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802154: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802158: lbu         $v1, 0x55($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X55);
    // 0x8080215C: beq         $v1, $zero, L_80802180
    if (ctx->r3 == 0) {
        // 0x80802160: nop
    
            goto L_80802180;
    }
    // 0x80802160: nop

    // 0x80802164: beq         $v1, $at, L_808021A0
    if (ctx->r3 == ctx->r1) {
        // 0x80802168: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808021A0;
    }
    // 0x80802168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080216C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802170: beq         $v1, $at, L_808021C8
    if (ctx->r3 == ctx->r1) {
        // 0x80802174: nop
    
            goto L_808021C8;
    }
    // 0x80802174: nop

    // 0x80802178: b           L_80802210
    // 0x8080217C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802210;
    // 0x8080217C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802180:
    // 0x80802180: jal         0x800CEAA8
    // 0x80802184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_4;
    // 0x80802184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80802188: beq         $v0, $zero, L_8080220C
    if (ctx->r2 == 0) {
        // 0x8080218C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080220C;
    }
    // 0x8080218C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802190: jal         0x800CE88C
    // 0x80802194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_5;
    // 0x80802194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80802198: b           L_80802210
    // 0x8080219C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802210;
    // 0x8080219C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808021A0:
    // 0x808021A0: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x808021A4: jal         0x800CE8D8
    // 0x808021A8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_800CE8D8(rdram, ctx);
        goto after_6;
    // 0x808021A8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_6:
    // 0x808021AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808021B0: jal         0x800CE88C
    // 0x808021B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_7;
    // 0x808021B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808021B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808021BC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808021C0: b           L_8080220C
    // 0x808021C4: sb          $t7, 0x55($t8)
    MEM_B(0X55, ctx->r24) = ctx->r15;
        goto L_8080220C;
    // 0x808021C4: sb          $t7, 0x55($t8)
    MEM_B(0X55, ctx->r24) = ctx->r15;
L_808021C8:
    // 0x808021C8: jal         0x800CEAD0
    // 0x808021CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_8;
    // 0x808021CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x808021D0: beq         $v0, $zero, L_8080220C
    if (ctx->r2 == 0) {
        // 0x808021D4: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_8080220C;
    }
    // 0x808021D4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808021D8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x808021DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(932, 0X2EE4) << 16);
    // 0x808021E0: addiu       $a1, $a1, 0x2EE4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(932, 0X2EE4));
    // 0x808021E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808021E8: jal         0x800C4AF0
    // 0x808021EC: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    func_800C4AF0(rdram, ctx);
        goto after_9;
    // 0x808021EC: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    after_9:
    // 0x808021F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808021F4: jal         0x80800F34
    // 0x808021F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_10;
    // 0x808021F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_10:
    // 0x808021FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802200: addiu       $a1, $zero, 0xF9D
    ctx->r5 = ADD32(0, 0XF9D);
    // 0x80802204: jal         0x8080238C
    // 0x80802208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_11;
    // 0x80802208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_8080220C:
    // 0x8080220C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802210:
    // 0x80802210: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802214: jr          $ra
    // 0x80802218: nop

    return;
    // 0x80802218: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A438: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A438);
    return;
    // 0x8008A43C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gczoombox_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B08: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B08);
    return;
    // 0x80087B0C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80093F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_banjo_detail(rdram, ctx);
    // 0x80093F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093F38: jal         0x8009EA2C
    // 0x80093F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x80093F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80093F40: beq         $v0, $zero, L_80093F5C
    if (ctx->r2 == 0) {
        // 0x80093F44: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80093F5C;
    }
    // 0x80093F44: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80093F48: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80093F4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80093F50: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80093F54: b           L_80093F6C
    // 0x80093F58: lw          $v0, 0x7DDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DDC);
        goto L_80093F6C;
    // 0x80093F58: lw          $v0, 0x7DDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DDC);
L_80093F5C:
    // 0x80093F5C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80093F60: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80093F64: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80093F68: lw          $v0, 0x7DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DD8);
L_80093F6C:
    // 0x80093F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093F74: jr          $ra
    // 0x80093F78: nop

    return;
    // 0x80093F78: nop

;}
RECOMP_FUNC void chelectricfence_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001E8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1180, 0X558) << 16);
    // 0x808001EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001F8: addiu       $t6, $t6, 0x558
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1180, 0X558));
    // 0x808001FC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800200: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800204: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800208: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080020C: jal         0x800BBCB8
    // 0x80800210: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800210: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800214: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1180, 0X51C) << 16);
    // 0x80800218: addiu       $t7, $t7, 0x51C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1180, 0X51C));
    // 0x8080021C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800228: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080022C: jal         0x800BBCB8
    // 0x80800230: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800230: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x80800234: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1180, 0X58C) << 16);
    // 0x80800238: addiu       $a2, $a2, 0x58C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1180, 0X58C));
    // 0x8080023C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800240: jal         0x80089D18
    // 0x80800244: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800244: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800248: jal         0x800C8A98
    // 0x8080024C: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x8080024C: nop

    after_3:
    // 0x80800250: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800258: jal         0x800C8CB8
    // 0x8080025C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x8080025C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800260: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800264: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1180, 0X598) << 16);
    // 0x80800268: addiu       $a1, $a1, 0x598
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1180, 0X598));
    // 0x8080026C: jal         0x800C8E84
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080027C: jal         0x800C8E54
    // 0x80800280: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_800C8E54(rdram, ctx);
        goto after_6;
    // 0x80800280: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_6:
    // 0x80800284: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800288: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x800863E8
    // 0x80800294: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800294: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_7:
    // 0x80800298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080029C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void func_808010F4_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808010F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801100: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80801104: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80801108: sll         $t9, $t7, 20
    ctx->r25 = S32(ctx->r15 << 20);
    // 0x8080110C: bgezl       $t9, L_808012B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801110: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012B8;
    }
    goto skip_0;
    // 0x80801110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801114: lhu         $t0, 0x64($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X64);
    // 0x80801118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080111C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80801120: beql        $t1, $zero, L_808012B8
    if (ctx->r9 == 0) {
        // 0x80801124: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012B8;
    }
    goto skip_1;
    // 0x80801124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801128: jal         0x80100094
    // 0x8080112C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080112C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801130: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80801134: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801138: jal         0x801039E4
    // 0x8080113C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x8080113C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_1:
    // 0x80801140: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801144: jal         0x80101F24
    // 0x80801148: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x80801148: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8080114C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80801150: lhu         $t4, 0x72($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X72);
    // 0x80801154: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x80801158: addiu       $t6, $t5, -0x2
    ctx->r14 = ADD32(ctx->r13, -0X2);
    // 0x8080115C: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80801160: beq         $at, $zero, L_80801254
    if (ctx->r1 == 0) {
        // 0x80801164: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801254;
    }
    // 0x80801164: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801168: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A38) << 16);
    // 0x8080116C: addu        $at, $at, $t6
    gpr jr_addend_80801174 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801170: lw          $t6, 0x2A38($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A38));
    // 0x80801174: jr          $t6
    // 0x80801178: nop

    switch (jr_addend_80801174 >> 2) {
        case 0: goto L_8080117C; break;
        case 1: goto L_80801254; break;
        case 2: goto L_80801254; break;
        case 3: goto L_80801254; break;
        case 4: goto L_808011C4; break;
        case 5: goto L_8080120C; break;
        case 6: goto L_8080120C; break;
        case 7: goto L_8080120C; break;
        default: switch_error(__func__, 0x80801174, 0x80802A38);
    }
    // 0x80801178: nop

L_8080117C:
    // 0x8080117C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A58) << 16);
    // 0x80801180: lwc1        $f4, 0x2A58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A58));
    // 0x80801184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801188: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080118C: nop

    // 0x80801190: bc1fl       L_808011B0
    if (!c1cs) {
        // 0x80801194: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_808011B0;
    }
    goto skip_2;
    // 0x80801194: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80801198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A5C) << 16);
    // 0x8080119C: lwc1        $f6, 0x2A5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A5C));
    // 0x808011A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808011A4: b           L_808011B8
    // 0x808011A8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
        goto L_808011B8;
    // 0x808011A8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x808011AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_808011B0:
    // 0x808011B0: nop

    // 0x808011B4: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_808011B8:
    // 0x808011B8: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808011BC: b           L_80801274
    // 0x808011C0: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
        goto L_80801274;
    // 0x808011C0: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
L_808011C4:
    // 0x808011C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808011C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808011CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808011D0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808011D4: nop

    // 0x808011D8: bc1fl       L_808011F0
    if (!c1cs) {
        // 0x808011DC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808011F0;
    }
    goto skip_3;
    // 0x808011DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_3:
    // 0x808011E0: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808011E4: b           L_80801200
    // 0x808011E8: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
        goto L_80801200;
    // 0x808011E8: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x808011EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808011F0:
    // 0x808011F0: nop

    // 0x808011F4: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x808011F8: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808011FC: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
L_80801200:
    // 0x80801200: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80801204: b           L_80801274
    // 0x80801208: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
        goto L_80801274;
    // 0x80801208: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_8080120C:
    // 0x8080120C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A60) << 16);
    // 0x80801210: lwc1        $f16, 0x2A60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A60));
    // 0x80801214: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801218: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080121C: nop

    // 0x80801220: bc1fl       L_80801240
    if (!c1cs) {
        // 0x80801224: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80801240;
    }
    goto skip_4;
    // 0x80801224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x80801228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A64) << 16);
    // 0x8080122C: lwc1        $f18, 0x2A64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A64));
    // 0x80801230: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801234: b           L_80801248
    // 0x80801238: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
        goto L_80801248;
    // 0x80801238: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8080123C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80801240:
    // 0x80801240: nop

    // 0x80801244: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
L_80801248:
    // 0x80801248: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8080124C: b           L_80801274
    // 0x80801250: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_80801274;
    // 0x80801250: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_80801254:
    // 0x80801254: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A68) << 16);
    // 0x80801258: lwc1        $f16, 0x2A68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A68));
    // 0x8080125C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80801260: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801264: jal         0x800F0E00
    // 0x80801268: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x80801268: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_3:
    // 0x8080126C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80801270: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_80801274:
    // 0x80801274: jal         0x800B2768
    // 0x80801278: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B2768(rdram, ctx);
        goto after_4;
    // 0x80801278: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8080127C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801280: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801284: jal         0x80103CB8
    // 0x80801288: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80103CB8(rdram, ctx);
        goto after_5;
    // 0x80801288: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x8080128C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801290: jal         0x800B2840
    // 0x80801294: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B2840(rdram, ctx);
        goto after_6;
    // 0x80801294: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80801298: addiu       $t7, $s0, 0x4C
    ctx->r15 = ADD32(ctx->r16, 0X4C);
    // 0x8080129C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808012A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808012A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808012AC: jal         0x80087990
    // 0x808012B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808012B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x808012B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012B8:
    // 0x808012B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808012C0: jr          $ra
    // 0x808012C4: nop

    return;
    // 0x808012C4: nop

;}
RECOMP_FUNC void func_808007E4_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007F0: jal         0x80100094
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808007F8: beq         $v0, $zero, L_80800808
    if (ctx->r2 == 0) {
        // 0x808007FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800808;
    }
    // 0x808007FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800800: jal         0x800897C8
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800808:
    // 0x80800808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800810: jr          $ra
    // 0x80800814: nop

    return;
    // 0x80800814: nop

    // 0x80800818: nop

    // 0x8080081C: nop

;}
RECOMP_FUNC void func_80800374_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800378: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080037C: addiu       $at, $zero, 0x10B1
    ctx->r1 = ADD32(0, 0X10B1);
    // 0x80800380: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800388: beq         $a1, $at, L_808003C4
    if (ctx->r5 == ctx->r1) {
        // 0x8080038C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808003C4;
    }
    // 0x8080038C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800390: addiu       $at, $zero, 0x10B3
    ctx->r1 = ADD32(0, 0X10B3);
    // 0x80800394: beq         $a1, $at, L_808003FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003FC;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: addiu       $at, $zero, 0x10F2
    ctx->r1 = ADD32(0, 0X10F2);
    // 0x808003A0: beq         $a1, $at, L_80800430
    if (ctx->r5 == ctx->r1) {
        // 0x808003A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: addiu       $at, $zero, 0x10F3
    ctx->r1 = ADD32(0, 0X10F3);
    // 0x808003AC: beq         $a1, $at, L_80800430
    if (ctx->r5 == ctx->r1) {
        // 0x808003B0: addiu       $at, $zero, 0x1101
        ctx->r1 = ADD32(0, 0X1101);
            goto L_80800430;
    }
    // 0x808003B0: addiu       $at, $zero, 0x1101
    ctx->r1 = ADD32(0, 0X1101);
    // 0x808003B4: beq         $a1, $at, L_80800430
    if (ctx->r5 == ctx->r1) {
        // 0x808003B8: nop
    
            goto L_80800430;
    }
    // 0x808003B8: nop

    // 0x808003BC: b           L_8080045C
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080045C;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003C4:
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x808004BC
    // 0x808003CC: addiu       $a1, $zero, 0x10F2
    ctx->r5 = ADD32(0, 0X10F2);
    func_808004BC_chconga(rdram, ctx);
        goto after_0;
    // 0x808003CC: addiu       $a1, $zero, 0x10F2
    ctx->r5 = ADD32(0, 0X10F2);
    after_0:
    // 0x808003D0: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80100094
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003E0: jal         0x80089FE0
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x80102424
    // 0x808003F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808003F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808003F4: b           L_80800468
    // 0x808003F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800468;
    // 0x808003F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003FC:
    // 0x808003FC: jal         0x808004BC
    // 0x80800400: addiu       $a1, $zero, 0x10F3
    ctx->r5 = ADD32(0, 0X10F3);
    func_808004BC_chconga(rdram, ctx);
        goto after_4;
    // 0x80800400: addiu       $a1, $zero, 0x10F3
    ctx->r5 = ADD32(0, 0X10F3);
    after_4:
    // 0x80800404: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x80100094
    // 0x80800410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800414: jal         0x80089FE0
    // 0x80800418: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800418: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80102424
    // 0x80800424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800428: b           L_80800468
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800468;
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800430:
    // 0x80800430: jal         0x80102424
    // 0x80800434: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800434: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: jal         0x80105A9C
    // 0x80800440: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_80105A9C(rdram, ctx);
        goto after_9;
    // 0x80800440: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_9:
    // 0x80800444: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80800448: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080044C: jal         0x80101180
    // 0x80800450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x80800450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800454: b           L_80800468
    // 0x80800458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800468;
    // 0x80800458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080045C:
    // 0x8080045C: jal         0x80102424
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800468:
    // 0x80800468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080046C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void chlightfader_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080024C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800250: jal         0x800C954C
    // 0x80800254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800C954C(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800258: bne         $v0, $zero, L_8080027C
    if (ctx->r2 != 0) {
        // 0x8080025C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8080027C;
    }
    // 0x8080025C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800264: addiu       $a0, $a0, 0x63F0
    ctx->r4 = ADD32(ctx->r4, 0X63F0);
    // 0x80800268: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080026C: jal         0x80086D40
    // 0x80800270: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _chbaddiesetup_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800270: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800274: b           L_80800288
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800288;
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080027C:
    // 0x8080027C: jal         0x800C8B84
    // 0x80800280: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x80800280: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800288:
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_800DE0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE0D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DE0DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800DE0E0: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800DE0E4: addiu       $s4, $s4, -0x313C
    ctx->r20 = ADD32(ctx->r20, -0X313C);
    // 0x800DE0E8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800DE0EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800DE0F0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800DE0F4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800DE0F8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800DE0FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800DE100: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800DE104: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DE108: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DE10C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800DE110: lh          $t6, 0xA($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XA);
    // 0x800DE114: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800DE118: beq         $t7, $zero, L_800DE198
    if (ctx->r15 == 0) {
        // 0x800DE11C: sw          $t6, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r14;
            goto L_800DE198;
    }
    // 0x800DE11C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800DE120: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x800DE124: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DE128: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DE12C: blez        $t8, L_800DE198
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800DE130: addiu       $s7, $sp, 0x48
        ctx->r23 = ADD32(ctx->r29, 0X48);
            goto L_800DE198;
    }
    // 0x800DE130: addiu       $s7, $sp, 0x48
    ctx->r23 = ADD32(ctx->r29, 0X48);
    // 0x800DE134: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800DE138: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800DE13C: addiu       $s5, $s5, -0x36B8
    ctx->r21 = ADD32(ctx->r21, -0X36B8);
    // 0x800DE140: addiu       $s6, $s6, -0x31A8
    ctx->r22 = ADD32(ctx->r22, -0X31A8);
    // 0x800DE144: lw          $a0, 0x20($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X20);
L_800DE148:
    // 0x800DE148: jal         0x800ADE2C
    // 0x800DE14C: lh          $a1, 0xC($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XC);
    func_800ADE2C(rdram, ctx);
        goto after_0;
    // 0x800DE14C: lh          $a1, 0xC($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XC);
    after_0:
    // 0x800DE150: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800DE154: jal         0x80019AA0
    // 0x800DE158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_1;
    // 0x800DE158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800DE15C: jal         0x80018BA8
    // 0x800DE160: nop

    mlMtx_get_stack_pointer(rdram, ctx);
        goto after_2;
    // 0x800DE160: nop

    after_2:
    // 0x800DE164: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800DE168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DE16C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800DE170: jalr        $t9
    // 0x800DE174: lh          $a2, 0xE($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XE);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800DE174: lh          $a2, 0xE($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XE);
    after_3:
    // 0x800DE178: jal         0x80018DAC
    // 0x800DE17C: nop

    mlMtxPop(rdram, ctx);
        goto after_4;
    // 0x800DE17C: nop

    after_4:
    // 0x800DE180: lh          $t0, 0x8($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X8);
    // 0x800DE184: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DE188: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800DE18C: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DE190: bnel        $at, $zero, L_800DE148
    if (ctx->r1 != 0) {
        // 0x800DE194: lw          $a0, 0x20($s5)
        ctx->r4 = MEM_W(ctx->r21, 0X20);
            goto L_800DE148;
    }
    goto skip_0;
    // 0x800DE194: lw          $a0, 0x20($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X20);
    skip_0:
L_800DE198:
    // 0x800DE198: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800DE19C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DE1A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DE1A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE1A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800DE1AC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800DE1B0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800DE1B4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800DE1B8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800DE1BC: jr          $ra
    // 0x800DE1C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800DE1C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800008_chmumbopadstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: bne         $a1, $at, L_80800070
    if (ctx->r5 != ctx->r1) {
        // 0x8080001C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800070;
    }
    // 0x8080001C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800020: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80800024: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800028: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080002C: jal         0x80086670
    // 0x80800030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800034: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800038: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1920, 0XA0) << 16);
    // 0x8080003C: addiu       $t7, $t7, 0xA0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1920, 0XA0));
    // 0x80800040: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x80800044: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080004C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800050: jal         0x800BABB8
    // 0x80800054: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80800058: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1920, 0X10C) << 16);
    // 0x8080005C: addiu       $a1, $a1, 0x10C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1920, 0X10C));
    // 0x80800060: jal         0x800C4AF0
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800068: b           L_80800074
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800074;
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800070:
    // 0x80800070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800074:
    // 0x80800074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800078: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080007C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800634: jal         0x808005B8
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808005B8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080063C: bne         $v0, $zero, L_8080064C
    if (ctx->r2 != 0) {
        // 0x80800640: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080064C;
    }
    // 0x80800640: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800644: b           L_8080065C
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080065C;
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080064C:
    // 0x8080064C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800650: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800658: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8080065C:
    // 0x8080065C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800664: jr          $ra
    // 0x80800668: nop

    return;
    // 0x80800668: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B98: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B98);
    return;
    // 0x80089B9C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
