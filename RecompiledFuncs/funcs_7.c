#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void dbzone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800390: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800398: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080039C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808003A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808003A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x808003B4: addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
    // 0x808003B8: addiu       $s6, $sp, 0x44
    ctx->r22 = ADD32(ctx->r29, 0X44);
    // 0x808003BC: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808003C4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808003C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808003CC: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x808003D0: mflo        $t7
    ctx->r15 = lo;
    // 0x808003D4: addu        $s3, $t7, $a0
    ctx->r19 = ADD32(ctx->r15, ctx->r4);
    // 0x808003D8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x808003DC: jal         0x800EE940
    // 0x808003E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x808003E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x808003E4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x808003E8: addiu       $s2, $a3, 0x2
    ctx->r18 = ADD32(ctx->r7, 0X2);
    // 0x808003EC: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x808003F0: beq         $at, $zero, L_80800454
    if (ctx->r1 == 0) {
        // 0x808003F4: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80800454;
    }
    // 0x808003F4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003FC:
    // 0x808003FC: jal         0x8080010C
    // 0x80800400: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_8080010C_dbzone(rdram, ctx);
        goto after_1;
    // 0x80800400: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_1:
    // 0x80800404: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800408: subu        $t8, $s0, $s2
        ctx->r24 = SUB32(ctx->r16, ctx->r18);
            goto L_80800444;
    }
    // 0x80800408: subu        $t8, $s0, $s2
    ctx->r24 = SUB32(ctx->r16, ctx->r18);
    // 0x8080040C: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x80800410: mflo        $t9
    ctx->r25 = lo;
    // 0x80800414: addu        $t0, $s4, $s1
    ctx->r8 = ADD32(ctx->r20, ctx->r17);
    // 0x80800418: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8080041C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800420: bne         $s5, $zero, L_8080042C
    if (ctx->r21 != 0) {
        // 0x80800424: nop
    
            goto L_8080042C;
    }
    // 0x80800424: nop

    // 0x80800428: break       7
    do_break(2155873320);
L_8080042C:
    // 0x8080042C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800430: bne         $s5, $at, L_80800444
    if (ctx->r21 != ctx->r1) {
        // 0x80800434: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800444;
    }
    // 0x80800434: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800438: bne         $t8, $at, L_80800444
    if (ctx->r24 != ctx->r1) {
        // 0x8080043C: nop
    
            goto L_80800444;
    }
    // 0x8080043C: nop

    // 0x80800440: break       6
    do_break(2155873344);
L_80800444:
    // 0x80800444: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x80800448: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8080044C: bnel        $at, $zero, L_808003FC
    if (ctx->r1 != 0) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003FC;
    }
    goto skip_0;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800454:
    // 0x80800454: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800458: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8080045C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800464: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800468: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080046C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800470: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800474: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800478: jr          $ra
    // 0x8080047C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080047C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827C0: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827C0);
    return;
    // 0x800827C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800ED9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ED9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ED9BC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED9C0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800ED9C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ED9C8: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800ED9CC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED9D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800ED9D4: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800ED9D8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED9DC: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x800ED9E0: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED9E4: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x800ED9E8: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED9EC: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x800ED9F0: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED9F4: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x800ED9F8: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800ED9FC: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x800EDA00: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x800EDA04: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x800EDA08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800EDA0C: jal         0x800ED964
    // 0x800EDA10: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    func_800ED964(rdram, ctx);
        goto after_0;
    // 0x800EDA10: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    after_0:
    // 0x800EDA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EDA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EDA1C: jr          $ra
    // 0x800EDA20: nop

    return;
    // 0x800EDA20: nop

;}
RECOMP_FUNC void func_8080000C_chalienbeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x8080001C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800020: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800024: jal         0x800EE7F8
    // 0x80800028: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8080002C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800038: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8080003C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: addiu       $a0, $a2, 0x28
    ctx->r4 = ADD32(ctx->r6, 0X28);
    // 0x80800044: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800048: jal         0x800EE7F8
    // 0x8080004C: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080004C: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080005C: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800060: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x80800064: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
    // 0x80800068: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x8080006C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800070: jal         0x80089C98
    // 0x80800074: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800074: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    after_2:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void _idflashbaddie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DD8: syscall     741
    recomp_syscall_handler(rdram, ctx, 0x80088DD8);
    return;
    // 0x80088DDC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8009C15C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C15C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C160: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009C164: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009C168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C16C: lw          $a1, 0xE4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE4);
    // 0x8009C170: jal         0x800EE7F8
    // 0x8009C174: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C174: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x8009C178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C180: jr          $ra
    // 0x8009C184: nop

    return;
    // 0x8009C184: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801328: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080132C: jal         0x80800144
    // 0x80801330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801338: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x8080133C: jal         0x8008CB3C
    // 0x80801340: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801340: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801344: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801348: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801358: jal         0x8009FFD8
    // 0x8080135C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080135C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801360: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801364: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080136C: jal         0x8008C9BC
    // 0x80801370: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80801370: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80801374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F2C) << 16);
    // 0x80801378: lwc1        $f4, 0x1F2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F2C));
    // 0x8080137C: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80801380: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801388: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8080138C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80801390: jal         0x8008C9F0
    // 0x80801394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80801394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080139C: jal         0x8008CA30
    // 0x808013A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_5;
    // 0x808013A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x808013A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808013A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808013AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808013B0: jr          $ra
    // 0x808013B4: nop

    return;
    // 0x808013B4: nop

;}
RECOMP_FUNC void func_800A6B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6B24: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800A6B28: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800A6B2C: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x800A6B30: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x800A6B34: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800A6B38: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800A6B3C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x800A6B40: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800A6B44: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800A6B48: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800A6B4C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x800A6B50: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800A6B54: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800A6B58: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800A6B5C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800A6B60: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800A6B64: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A6B68: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A6B6C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800A6B70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6B74: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A6B78: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800A6B7C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800A6B80: nop

    // 0x800A6B84: bc1tl       L_800A6D6C
    if (c1cs) {
        // 0x800A6B88: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800A6D6C;
    }
    goto skip_0;
    // 0x800A6B88: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x800A6B8C: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x800A6B90: addiu       $s7, $sp, 0xBC
    ctx->r23 = ADD32(ctx->r29, 0XBC);
    // 0x800A6B94: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800A6B98: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A6B9C: jal         0x800F5BC4
    // 0x800A6BA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F5BC4(rdram, ctx);
        goto after_0;
    // 0x800A6BA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800A6BA4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800A6BA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800A6BAC: jal         0x800EF04C
    // 0x800A6BB0: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x800A6BB0: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    after_1:
    // 0x800A6BB4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800A6BB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A6BBC: jal         0x800C8760
    // 0x800A6BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8760(rdram, ctx);
        goto after_2;
    // 0x800A6BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800A6BC4: beq         $v0, $zero, L_800A6D20
    if (ctx->r2 == 0) {
        // 0x800A6BC8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A6D20;
    }
    // 0x800A6BC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A6BCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6BD0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800A6BD4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A6BD8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800A6BDC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800A6BE0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A6BE4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800A6BE8: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x800A6BEC: addiu       $s4, $sp, 0xA4
    ctx->r20 = ADD32(ctx->r29, 0XA4);
    // 0x800A6BF0: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800A6BF4: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_800A6BF8:
    // 0x800A6BF8: jal         0x800C89A8
    // 0x800A6BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C89A8(rdram, ctx);
        goto after_3;
    // 0x800A6BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A6C00: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x800A6C04: bne         $t7, $zero, L_800A6CFC
    if (ctx->r15 != 0) {
        // 0x800A6C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A6CFC;
    }
    // 0x800A6C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A6C0C: jal         0x800C8800
    // 0x800A6C10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8800(rdram, ctx);
        goto after_4;
    // 0x800A6C10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800A6C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A6C18: jal         0x800C8898
    // 0x800A6C1C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C8898(rdram, ctx);
        goto after_5;
    // 0x800A6C1C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x800A6C20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A6C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A6C28: jal         0x800EFB24
    // 0x800A6C2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x800A6C2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x800A6C30: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800A6C34: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800A6C38: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800A6C3C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800A6C40: nop

    // 0x800A6C44: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800A6C48: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A6C4C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A6C50: jal         0x8002DCA0
    // 0x800A6C54: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x800A6C54: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_7:
    // 0x800A6C58: c.eq.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl == ctx->f24.fl;
    // 0x800A6C5C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A6C60: bc1tl       L_800A6D00
    if (c1cs) {
        // 0x800A6C64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A6D00;
    }
    goto skip_1;
    // 0x800A6C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800A6C68: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800A6C6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800A6C70: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A6C74: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800A6C78: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800A6C7C: nop

    // 0x800A6C80: bc1tl       L_800A6D00
    if (c1cs) {
        // 0x800A6C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A6D00;
    }
    goto skip_2;
    // 0x800A6C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800A6C88: div.s       $f2, $f26, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800A6C8C: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800A6C90: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800A6C94: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800A6C98: sub.s       $f12, $f0, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800A6C9C: lwc1        $f20, 0x8C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A6CA0: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x800A6CA4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A6CA8: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x800A6CAC: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800A6CB0: nop

    // 0x800A6CB4: mul.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A6CB8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800A6CBC: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x800A6CC0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800A6CC4: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x800A6CC8: bc1f        L_800A6CF0
    if (!c1cs) {
        // 0x800A6CCC: swc1        $f18, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
            goto L_800A6CF0;
    }
    // 0x800A6CCC: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x800A6CD0: sub.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f20.fl;
    // 0x800A6CD4: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800A6CD8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A6CDC: sub.s       $f0, $f30, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x800A6CE0: mul.s       $f10, $f28, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800A6CE4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A6CE8: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x800A6CEC: nop

L_800A6CF0:
    // 0x800A6CF0: jal         0x800A69F0
    // 0x800A6CF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800A69F0(rdram, ctx);
        goto after_8;
    // 0x800A6CF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x800A6CF8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800A6CFC:
    // 0x800A6CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A6D00:
    // 0x800A6D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6D04: jal         0x800C878C
    // 0x800A6D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800C878C(rdram, ctx);
        goto after_9;
    // 0x800A6D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800A6D0C: beq         $v0, $zero, L_800A6D20
    if (ctx->r2 == 0) {
        // 0x800A6D10: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A6D20;
    }
    // 0x800A6D10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A6D14: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x800A6D18: bnel        $at, $zero, L_800A6BF8
    if (ctx->r1 != 0) {
        // 0x800A6D1C: addiu       $s1, $zero, 0xFF
        ctx->r17 = ADD32(0, 0XFF);
            goto L_800A6BF8;
    }
    goto skip_3;
    // 0x800A6D1C: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    skip_3:
L_800A6D20:
    // 0x800A6D20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6D24: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800A6D28: bne         $s3, $zero, L_800A6D68
    if (ctx->r19 != 0) {
        // 0x800A6D2C: addiu       $s0, $sp, 0x78
        ctx->r16 = ADD32(ctx->r29, 0X78);
            goto L_800A6D68;
    }
    // 0x800A6D2C: addiu       $s0, $sp, 0x78
    ctx->r16 = ADD32(ctx->r29, 0X78);
    // 0x800A6D30: jal         0x800EFD24
    // 0x800A6D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x800A6D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A6D38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A6D3C: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x800A6D40: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x800A6D44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A6D48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A6D4C: jal         0x800EFA4C
    // 0x800A6D50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x800A6D50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800A6D54: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800A6D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A6D5C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800A6D60: jal         0x800A69F0
    // 0x800A6D64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800A69F0(rdram, ctx);
        goto after_12;
    // 0x800A6D64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_12:
L_800A6D68:
    // 0x800A6D68: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800A6D6C:
    // 0x800A6D6C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800A6D70: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800A6D74: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800A6D78: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800A6D7C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800A6D80: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x800A6D84: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800A6D88: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D8C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D90: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800A6D94: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800A6D98: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800A6D9C: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6DA0: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x800A6DA4: jr          $ra
    // 0x800A6DA8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800A6DA8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80800000_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: addiu       $a0, $a1, 0x51F
    ctx->r4 = ADD32(ctx->r5, 0X51F);
    // 0x8080000C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800018: jal         0x80088280
    // 0x8080001C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: jal         0x80088C00
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080002C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1592, 0X6E0) << 16);
    // 0x80800030: lwc1        $f4, 0x6E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1592, 0X6E0));
    // 0x80800034: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800038: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8080003C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800040: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80800044: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802DAC: jal         0x80800038
    // 0x80802DB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802DB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802DB8: beq         $v0, $at, L_80802DE8
    if (ctx->r2 == ctx->r1) {
        // 0x80802DBC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80802DE8;
    }
    // 0x80802DBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802DC0: jal         0x80800000
    // 0x80802DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802DC8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80802DCC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80802DD0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802DD4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80802DD8: jal         0x80087B88
    // 0x80802DDC: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    _gczoombox_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80802DDC: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    after_2:
    // 0x80802DE0: b           L_80802DEC
    // 0x80802DE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802DEC;
    // 0x80802DE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802DE8:
    // 0x80802DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802DEC:
    // 0x80802DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802DF4: jr          $ra
    // 0x80802DF8: nop

    return;
    // 0x80802DF8: nop

;}
RECOMP_FUNC void func_8080182C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080182C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801834: jal         0x80800030
    // 0x80801838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800030_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80801838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080183C: jal         0x80082FE0
    // 0x80801840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801848: jal         0x8009BF5C
    // 0x8080184C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x8080184C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80801850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801854: jal         0x8009C4CC
    // 0x80801858: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80801858: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080185C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801864: jr          $ra
    // 0x80801868: nop

    return;
    // 0x80801868: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E70: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E70);
    return;
    // 0x80083E74: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_8008FFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FFE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FFEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FFF0: jal         0x800F54E4
    // 0x8008FFF4: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FFF4: nop

    after_0:
    // 0x8008FFF8: jal         0x800F5EF8
    // 0x8008FFFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x8008FFFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090008: jr          $ra
    // 0x8009000C: nop

    return;
    // 0x8009000C: nop

;}
RECOMP_FUNC void _chchuffycont_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C30: syscall     433
    recomp_syscall_handler(rdram, ctx, 0x80086C30);
    return;
    // 0x80086C34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800EA600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA600: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA604: addiu       $v0, $v0, 0x2DD0
    ctx->r2 = ADD32(ctx->r2, 0X2DD0);
    // 0x800EA608: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800EA60C: jr          $ra
    // 0x800EA610: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    return;
    // 0x800EA610: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void _batimer_isGreaterThan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085320: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085320);
    return;
    // 0x80085324: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsdronebitten_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083028: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083028);
    return;
    // 0x8008302C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800DB8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB8BC: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x800DB8C0: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x800DB8C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DB8C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800DB8CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DB8D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DB8D4: mflo        $a1
    ctx->r5 = lo;
    // 0x800DB8D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DB8DC: jal         0x800E6DB4
    // 0x800DB8E0: nop

    func_800E6DB4(rdram, ctx);
        goto after_0;
    // 0x800DB8E0: nop

    after_0:
    // 0x800DB8E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800DB8E8: addiu       $a1, $a1, 0x5D30
    ctx->r5 = ADD32(ctx->r5, 0X5D30);
    // 0x800DB8EC: jal         0x800E6A10
    // 0x800DB8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E6A10(rdram, ctx);
        goto after_1;
    // 0x800DB8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800DB8F4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800DB8F8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800DB8FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800DB900: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800DB904: mflo        $t7
    ctx->r15 = lo;
    // 0x800DB908: addiu       $a1, $a1, 0x5D34
    ctx->r5 = ADD32(ctx->r5, 0X5D34);
    // 0x800DB90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DB910: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800DB914: mfhi        $t8
    ctx->r24 = hi;
    // 0x800DB918: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x800DB91C: beq         $at, $zero, L_800DB930
    if (ctx->r1 == 0) {
        // 0x800DB920: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800DB930;
    }
    // 0x800DB920: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800DB924: jal         0x800E6A10
    // 0x800DB928: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800E6A10(rdram, ctx);
        goto after_2;
    // 0x800DB928: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_2:
    // 0x800DB92C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_800DB930:
    // 0x800DB930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DB934: jal         0x800E6DB4
    // 0x800DB938: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_3;
    // 0x800DB938: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800DB93C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800DB940: addiu       $a1, $a1, 0x5D38
    ctx->r5 = ADD32(ctx->r5, 0X5D38);
    // 0x800DB944: jal         0x800E6A10
    // 0x800DB948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E6A10(rdram, ctx);
        goto after_4;
    // 0x800DB948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800DB94C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800DB950: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800DB954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DB958: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800DB95C: mfhi        $t9
    ctx->r25 = hi;
    // 0x800DB960: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800DB964: beq         $at, $zero, L_800DB980
    if (ctx->r1 == 0) {
        // 0x800DB968: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_800DB980;
    }
    // 0x800DB968: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800DB96C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800DB970: addiu       $a1, $a1, 0x5D3C
    ctx->r5 = ADD32(ctx->r5, 0X5D3C);
    // 0x800DB974: jal         0x800E6A10
    // 0x800DB978: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_800E6A10(rdram, ctx);
        goto after_5;
    // 0x800DB978: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_5:
    // 0x800DB97C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_800DB980:
    // 0x800DB980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DB984: jal         0x800E6DB4
    // 0x800DB988: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_6;
    // 0x800DB988: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x800DB98C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800DB990: addiu       $a1, $a1, 0x5D40
    ctx->r5 = ADD32(ctx->r5, 0X5D40);
    // 0x800DB994: jal         0x800E6A10
    // 0x800DB998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E6A10(rdram, ctx);
        goto after_7;
    // 0x800DB998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800DB99C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DB9A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DB9A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800DB9A8: jr          $ra
    // 0x800DB9AC: nop

    return;
    // 0x800DB9AC: nop

;}
RECOMP_FUNC void ncpod_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: jr          $ra
    // 0x808002E4: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    return;
    // 0x808002E4: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
;}
RECOMP_FUNC void func_800CE2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE2DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE2E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE2E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CE2E8: addiu       $a0, $a0, -0x4FE0
    ctx->r4 = ADD32(ctx->r4, -0X4FE0);
    // 0x800CE2EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800CE2F0: jal         0x800DAA8C
    // 0x800CE2F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DAA8C(rdram, ctx);
        goto after_0;
    // 0x800CE2F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800CE2F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE2FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE300: jr          $ra
    // 0x800CE304: nop

    return;
    // 0x800CE304: nop

;}
RECOMP_FUNC void bashoes_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x80800528: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080052C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800530: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80800534: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800538: nop

    // 0x8080053C: bc1f        L_8080054C
    if (!c1cs) {
        // 0x80800540: nop
    
            goto L_8080054C;
    }
    // 0x80800540: nop

    // 0x80800544: jr          $ra
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080054C:
    // 0x8080054C: jr          $ra
    // 0x80800550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80801E4C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801E50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801E60: jal         0x800DA544
    // 0x80801E64: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80801E64: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    after_0:
    // 0x80801E68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80801E6C: bnel        $t6, $zero, L_80801EB4
    if (ctx->r14 != 0) {
        // 0x80801E70: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80801EB4;
    }
    goto skip_0;
    // 0x80801E70: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    skip_0:
    // 0x80801E74: jal         0x8008A6B0
    // 0x80801E78: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    _sujiggy_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801E78: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_1:
    // 0x80801E7C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801E80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801E84: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80801E88: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80801E8C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80801E90: jal         0x800CE8D8
    // 0x80801E94: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CE8D8(rdram, ctx);
        goto after_2;
    // 0x80801E94: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80801E98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801E9C: jal         0x800CE88C
    // 0x80801EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x80801EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801EA4: jal         0x800343B0
    // 0x80801EA8: nop

    osGetCount_recomp(rdram, ctx);
        goto after_4;
    // 0x80801EA8: nop

    after_4:
    // 0x80801EAC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80801EB0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
L_80801EB4:
    // 0x80801EB4: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x80801EB8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801EBC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80801EC0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80801EC4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80801EC8: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80801ECC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80801ED0: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80801ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801ED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801EDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801EE0: jr          $ra
    // 0x80801EE4: nop

    return;
    // 0x80801EE4: nop

;}
RECOMP_FUNC void _bareact_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F90: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F90);
    return;
    // 0x80084F94: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsthrow_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F08: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083F08);
    return;
    // 0x80083F0C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void idflashbaddie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: jr          $ra
    // 0x808000A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801C58_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C60: jal         0x80800128
    // 0x80801C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801C68: jal         0x80082FE0
    // 0x80801C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801C70: jal         0x80084800
    // 0x80801C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801C78: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80801C7C: bne         $v0, $at, L_80801C8C
    if (ctx->r2 != ctx->r1) {
        // 0x80801C80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801C8C;
    }
    // 0x80801C80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801C84: jal         0x8009B800
    // 0x80801C88: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_3;
    // 0x80801C88: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
L_80801C8C:
    // 0x80801C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C94: jr          $ra
    // 0x80801C98: nop

    return;
    // 0x80801C98: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080034C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800354: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800358: jal         0x800F2EFC
    // 0x8080035C: addiu       $a1, $a3, 0x98
    ctx->r5 = ADD32(ctx->r7, 0X98);
    func_800F2EFC(rdram, ctx);
        goto after_0;
    // 0x8080035C: addiu       $a1, $a3, 0x98
    ctx->r5 = ADD32(ctx->r7, 0X98);
    after_0:
    // 0x80800360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B20: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B20);
    return;
    // 0x80089B24: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80800498_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800498: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080049C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XDFC) << 16);
    // 0x808004A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004AC: jal         0x800DC298
    // 0x808004B0: lwc1        $f12, 0xDFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XDFC));
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x808004B0: lwc1        $f12, 0xDFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XDFC));
    after_0:
    // 0x808004B4: beq         $v0, $zero, L_808004C4
    if (ctx->r2 == 0) {
        // 0x808004B8: nop
    
            goto L_808004C4;
    }
    // 0x808004B8: nop

    // 0x808004BC: jal         0x808009BC
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009BC_chseaweedbaddy(rdram, ctx);
        goto after_1;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808004C4:
    // 0x808004C4: jal         0x8008A498
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004CC: jal         0x80107200
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80107200(rdram, ctx);
        goto after_3;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: jal         0x80100094
    // 0x808004DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808004DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808004E0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808004E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x808004F0: jal         0x80089F70
    // 0x808004F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808004F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x808004F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808004FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800500: jal         0x800EE7F8
    // 0x80800504: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800504: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    after_6:
    // 0x80800508: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE00) << 16);
    // 0x8080050C: lwc1        $f6, 0xE00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE00));
    // 0x80800510: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080051C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800520: jal         0x80102FDC
    // 0x80800524: nop

    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80800524: nop

    after_7:
    // 0x80800528: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080052C: jal         0x800DC0C0
    // 0x80800530: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80800530: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80800534: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800538: jal         0x80101EE4
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_9;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800548: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EA0: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089EA0);
    return;
    // 0x80089EA4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _idglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CE0: syscall     734
    recomp_syscall_handler(rdram, ctx, 0x80088CE0);
    return;
    // 0x80088CE4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80110024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011002C: lh          $a1, 0x14($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X14);
    // 0x80110030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80110034: beq         $a1, $zero, L_80110050
    if (ctx->r5 == 0) {
        // 0x80110038: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_80110050;
    }
    // 0x80110038: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8011003C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80110040: jal         0x800894D0
    // 0x80110044: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _ncpod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80110044: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80110048: b           L_80110054
    // 0x8011004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80110054;
    // 0x8011004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110050:
    // 0x80110050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110054:
    // 0x80110054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110058: jr          $ra
    // 0x8011005C: nop

    return;
    // 0x8011005C: nop

;}
RECOMP_FUNC void func_8080061C_chswampplatform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800620: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800624: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800628: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800630: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800634: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800638: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080063C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800640: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800644: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800648: jal         0x800DA298
    // 0x8080064C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080064C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_0:
    // 0x80800650: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x80800654: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800750;
    }
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800658: jal         0x80100094
    // 0x8080065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800660: beq         $v0, $zero, L_8080077C
    if (ctx->r2 == 0) {
        // 0x80800664: addiu       $a0, $zero, 0x28E
        ctx->r4 = ADD32(0, 0X28E);
            goto L_8080077C;
    }
    // 0x80800664: addiu       $a0, $zero, 0x28E
    ctx->r4 = ADD32(0, 0X28E);
    // 0x80800668: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8080066C: jal         0x80089C40
    // 0x80800670: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800670: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x80800674: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080067C: jal         0x80100094
    // 0x80800680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800688: jal         0x80089888
    // 0x8080068C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080068C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x80800690: blez        $s3, L_80800730
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80800694: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800730;
    }
    // 0x80800694: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800698: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080069C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808006A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808006A4: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
L_808006A8:
    // 0x808006A8: jal         0x80103EF4
    // 0x808006AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80103EF4(rdram, ctx);
        goto after_5;
    // 0x808006AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808006B0: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x808006B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808006B8: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x808006BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808006C0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x808006C4: lwc1        $f12, 0x28($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808006C8: c.eq.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl == ctx->f12.fl;
    // 0x808006CC: nop

    // 0x808006D0: bc1tl       L_80800710
    if (c1cs) {
        // 0x808006D4: lwc1        $f10, 0x38($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
            goto L_80800710;
    }
    goto skip_0;
    // 0x808006D4: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    skip_0:
    // 0x808006D8: lwc1        $f14, 0x2C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x808006DC: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1tl       L_80800710
    if (c1cs) {
        // 0x808006E8: lwc1        $f10, 0x38($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
            goto L_80800710;
    }
    goto skip_1;
    // 0x808006E8: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    skip_1:
    // 0x808006EC: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x808006F0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x808006F4: nop

    // 0x808006F8: bc1tl       L_80800710
    if (c1cs) {
        // 0x808006FC: lwc1        $f10, 0x38($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
            goto L_80800710;
    }
    goto skip_2;
    // 0x808006FC: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    skip_2:
    // 0x80800700: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800704: jal         0x800DF500
    // 0x80800708: nop

    func_800DF500(rdram, ctx);
        goto after_6;
    // 0x80800708: nop

    after_6:
    // 0x8080070C: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
L_80800710:
    // 0x80800710: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800714: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800718: swc1        $f10, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f10.u32l;
    // 0x8080071C: jal         0x80101870
    // 0x80800720: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80101870(rdram, ctx);
        goto after_7;
    // 0x80800720: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800724: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800728: bne         $s2, $s3, L_808006A8
    if (ctx->r18 != ctx->r19) {
        // 0x8080072C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808006A8;
    }
    // 0x8080072C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800730:
    // 0x80800730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800734: jal         0x80100094
    // 0x80800738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080073C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800740: jal         0x80089880
    // 0x80800744: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x80800744: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
    // 0x80800748: b           L_80800780
    // 0x8080074C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800780;
    // 0x8080074C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800750:
    // 0x80800750: jal         0x80103EF4
    // 0x80800754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103EF4(rdram, ctx);
        goto after_10;
    // 0x80800754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800758: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080075C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800760: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800768: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8080076C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800770: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800774: jal         0x80101870
    // 0x80800778: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    func_80101870(rdram, ctx);
        goto after_11;
    // 0x80800778: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    after_11:
L_8080077C:
    // 0x8080077C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800780:
    // 0x80800780: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800784: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800788: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080078C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800790: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800794: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800798: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8080079C: jr          $ra
    // 0x808007A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808007A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8002A7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A7E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A7E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A7EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002A7F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002A7F4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8002A7F8: beq         $t7, $zero, L_8002A878
    if (ctx->r15 == 0) {
        // 0x8002A7FC: nop
    
            goto L_8002A878;
    }
    // 0x8002A7FC: nop

    // 0x8002A800: jal         0x80021794
    // 0x8002A804: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x8002A804: nop

    after_0:
    // 0x8002A808: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002A80C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A810: bne         $t8, $zero, L_8002A820
    if (ctx->r24 != 0) {
        // 0x8002A814: nop
    
            goto L_8002A820;
    }
    // 0x8002A814: nop

    // 0x8002A818: b           L_8002A880
    // 0x8002A81C: nop

        goto L_8002A880;
    // 0x8002A81C: nop

L_8002A820:
    // 0x8002A820: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A824: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002A828: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x8002A82C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002A830: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A834: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x8002A838: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x8002A83C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8002A840: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002A844: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A848: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8002A84C: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8002A850: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002A854: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A858: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x8002A85C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A860: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8002A864: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A868: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002A86C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A870: jal         0x8002B684
    // 0x8002A874: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x8002A874: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_1:
L_8002A878:
    // 0x8002A878: b           L_8002A880
    // 0x8002A87C: nop

        goto L_8002A880;
    // 0x8002A87C: nop

L_8002A880:
    // 0x8002A880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A888: jr          $ra
    // 0x8002A88C: nop

    return;
    // 0x8002A88C: nop

;}
RECOMP_FUNC void bsbanshack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ABC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800AC0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XCE0) << 16);
    // 0x80800AC4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: lw          $v0, 0xCE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCE0));
    return;
    // 0x80800ACC: lw          $v0, 0xCE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCE0));
;}
RECOMP_FUNC void _chdinofoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F70: syscall     265
    recomp_syscall_handler(rdram, ctx, 0x80085F70);
    return;
    // 0x80085F74: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chnicecavemen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086108: syscall     279
    recomp_syscall_handler(rdram, ctx, 0x80086108);
    return;
    // 0x8008610C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80803304_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803304: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080330C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80803310: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80803314: jal         0x800EE7F8
    // 0x80803318: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80803318: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8080331C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80803320: jal         0x800EE7F8
    // 0x80803324: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80803324: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80803328: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080332C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80803330: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803334: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80803338: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x8080333C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80803340: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80803344: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80803348: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080334C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80803350: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80803354: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80803358: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080335C: jal         0x800C6A7C
    // 0x80803360: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x80803360: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80803364: bne         $v0, $zero, L_80803374
    if (ctx->r2 != 0) {
        // 0x80803368: lwc1        $f16, 0x2C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80803374;
    }
    // 0x80803368: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080336C: b           L_80803380
    // 0x80803370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803380;
    // 0x80803370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803374:
    // 0x80803374: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80803378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080337C: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
L_80803380:
    // 0x80803380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803384: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80803388: jr          $ra
    // 0x8080338C: nop

    return;
    // 0x8080338C: nop

;}
RECOMP_FUNC void func_800BECE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BECE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BECE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BECE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BECEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BECF0: jal         0x800EE830
    // 0x800BECF4: addiu       $a1, $a1, -0x78D0
    ctx->r5 = ADD32(ctx->r5, -0X78D0);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800BECF4: addiu       $a1, $a1, -0x78D0
    ctx->r5 = ADD32(ctx->r5, -0X78D0);
    after_0:
    // 0x800BECF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BECFC: addiu       $a1, $a1, -0x78C4
    ctx->r5 = ADD32(ctx->r5, -0X78C4);
    // 0x800BED00: jal         0x800EE830
    // 0x800BED04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800BED04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800BED08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BED0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BED10: jr          $ra
    // 0x800BED14: nop

    return;
    // 0x800BED14: nop

;}
RECOMP_FUNC void func_800BA28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA28C: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x800BA290: lw          $t7, 0x8C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8C);
    // 0x800BA294: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800BA298: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800BA29C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800BA2A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800BA2A4: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800BA2A8: beq         $v0, $zero, L_800BA2BC
    if (ctx->r2 == 0) {
        // 0x800BA2AC: nop
    
            goto L_800BA2BC;
    }
    // 0x800BA2AC: nop

    // 0x800BA2B0: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x800BA2B4: xori        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 ^ 0X2;
    // 0x800BA2B8: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
L_800BA2BC:
    // 0x800BA2BC: jr          $ra
    // 0x800BA2C0: nop

    return;
    // 0x800BA2C0: nop

;}
RECOMP_FUNC void _baduo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084920: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084920);
    return;
    // 0x80084924: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80092898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009289C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800928A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800928A4: jal         0x80084530
    // 0x800928A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _babackpack_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x800928A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800928AC: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x800928B0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800928B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800928B8: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x800928BC: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x800928C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800928C4: sb          $t7, 0x14($t8)
    MEM_B(0X14, ctx->r24) = ctx->r15;
    // 0x800928C8: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x800928CC: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
    // 0x800928D0: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x800928D4: sb          $zero, 0x16($t0)
    MEM_B(0X16, ctx->r8) = 0;
    // 0x800928D8: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x800928DC: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x800928E0: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800928E4: sb          $zero, 0x13($t2)
    MEM_B(0X13, ctx->r10) = 0;
    // 0x800928E8: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x800928EC: sh          $zero, 0xC($t3)
    MEM_H(0XC, ctx->r11) = 0;
    // 0x800928F0: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x800928F4: sb          $zero, 0xA2($t4)
    MEM_B(0XA2, ctx->r12) = 0;
    // 0x800928F8: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x800928FC: jal         0x800936E8
    // 0x80092900: sh          $zero, 0x9C($t5)
    MEM_H(0X9C, ctx->r13) = 0;
    func_800936E8(rdram, ctx);
        goto after_1;
    // 0x80092900: sh          $zero, 0x9C($t5)
    MEM_H(0X9C, ctx->r13) = 0;
    after_1:
    // 0x80092904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092908: jal         0x80093700
    // 0x8009290C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093700(rdram, ctx);
        goto after_2;
    // 0x8009290C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80092910: jal         0x800AE020
    // 0x80092914: nop

    func_800AE020(rdram, ctx);
        goto after_3;
    // 0x80092914: nop

    after_3:
    // 0x80092918: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x8009291C: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // 0x80092920: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80092924: jal         0x800AE080
    // 0x80092928: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_800AE080(rdram, ctx);
        goto after_4;
    // 0x80092928: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_4:
    // 0x8009292C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80092930: jal         0x800E09B8
    // 0x80092934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800E09B8(rdram, ctx);
        goto after_5;
    // 0x80092934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x80092938: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8009293C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80092940: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80092944: jal         0x800AE6FC
    // 0x80092948: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800AE6FC(rdram, ctx);
        goto after_6;
    // 0x80092948: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8009294C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80092950: jal         0x800DBFF8
    // 0x80092954: sb          $zero, 0x88($t9)
    MEM_B(0X88, ctx->r25) = 0;
    func_800DBFF8(rdram, ctx);
        goto after_7;
    // 0x80092954: sb          $zero, 0x88($t9)
    MEM_B(0X88, ctx->r25) = 0;
    after_7:
    // 0x80092958: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x8009295C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80092960: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x80092964: sw          $zero, 0x84($t1)
    MEM_W(0X84, ctx->r9) = 0;
    // 0x80092968: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x8009296C: sb          $zero, 0x7C($t2)
    MEM_B(0X7C, ctx->r10) = 0;
    // 0x80092970: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x80092974: sb          $zero, 0x81($t3)
    MEM_B(0X81, ctx->r11) = 0;
    // 0x80092978: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8009297C: jal         0x800EFD24
    // 0x80092980: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x80092980: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_8:
    // 0x80092984: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80092988: jal         0x800EFD24
    // 0x8009298C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x8009298C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_9:
    // 0x80092990: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80092994: jal         0x800EFD24
    // 0x80092998: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x80092998: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_10:
    // 0x8009299C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800929A0: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x800929A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800929A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800929AC: swc1        $f4, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f4.u32l;
    // 0x800929B0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800929B4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800929B8: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800929BC: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x800929C0: jal         0x80093370
    // 0x800929C4: swc1        $f0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f0.u32l;
    func_80093370(rdram, ctx);
        goto after_11;
    // 0x800929C4: swc1        $f0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f0.u32l;
    after_11:
    // 0x800929C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800929CC: jal         0x8009337C
    // 0x800929D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_12;
    // 0x800929D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x800929D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800929D8: jal         0x80093230
    // 0x800929DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_13;
    // 0x800929DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x800929E0: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x800929E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800929E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800929EC: jal         0x800931AC
    // 0x800929F0: sb          $zero, 0x15($t6)
    MEM_B(0X15, ctx->r14) = 0;
    func_800931AC(rdram, ctx);
        goto after_14;
    // 0x800929F0: sb          $zero, 0x15($t6)
    MEM_B(0X15, ctx->r14) = 0;
    after_14:
    // 0x800929F4: jal         0x80092778
    // 0x800929F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_15;
    // 0x800929F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800929FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092A00: jal         0x80092864
    // 0x80092A04: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_16;
    // 0x80092A04: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80092A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80092A0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80092A10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80092A14: jr          $ra
    // 0x80092A18: nop

    return;
    // 0x80092A18: nop

;}
RECOMP_FUNC void func_808023FC_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802400: beq         $a1, $zero, L_8080242C
    if (ctx->r5 == 0) {
        // 0x80802404: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080242C;
    }
    // 0x80802404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080240C: beq         $a1, $at, L_808024F8
    if (ctx->r5 == ctx->r1) {
        // 0x80802410: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808024F8;
    }
    // 0x80802410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802414: beq         $a1, $at, L_808025C4
    if (ctx->r5 == ctx->r1) {
        // 0x80802418: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808025C4;
    }
    // 0x80802418: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080241C: beql        $a1, $at, L_80802694
    if (ctx->r5 == ctx->r1) {
        // 0x80802420: lui         $at, 0xC337
        ctx->r1 = S32(0XC337 << 16);
            goto L_80802694;
    }
    goto skip_0;
    // 0x80802420: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    skip_0:
    // 0x80802424: b           L_80802758
    // 0x80802428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802758;
    // 0x80802428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080242C:
    // 0x8080242C: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x80802430: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802434: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802438: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x8080243C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802440: nop

    // 0x80802444: bc1fl       L_808024D8
    if (!c1cs) {
        // 0x80802448: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808024D8;
    }
    goto skip_1;
    // 0x80802448: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_1:
    // 0x8080244C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802450: nop

    // 0x80802454: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80802458: nop

    // 0x8080245C: bc1fl       L_808024D8
    if (!c1cs) {
        // 0x80802460: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808024D8;
    }
    goto skip_2;
    // 0x80802460: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_2:
    // 0x80802464: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80802468: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080246C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80802470: beq         $t7, $at, L_808024A0
    if (ctx->r15 == ctx->r1) {
        // 0x80802474: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808024A0;
    }
    // 0x80802474: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80802478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080247C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802484: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80802488: nop

    // 0x8080248C: bc1f        L_808024A0
    if (!c1cs) {
        // 0x80802490: nop
    
            goto L_808024A0;
    }
    // 0x80802490: nop

    // 0x80802494: jal         0x80802AF8
    // 0x80802498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802AF8_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80802498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080249C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808024A0:
    // 0x808024A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BC4) << 16);
    // 0x808024A4: lwc1        $f16, 0x4BC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BC4));
    // 0x808024A8: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808024AC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808024B0: nop

    // 0x808024B4: bc1fl       L_80802758
    if (!c1cs) {
        // 0x808024B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802758;
    }
    goto skip_3;
    // 0x808024B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808024BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808024C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BC8) << 16);
    // 0x808024C4: lwc1        $f16, 0x4BC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BC8));
    // 0x808024C8: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x808024CC: b           L_80802754
    // 0x808024D0: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
        goto L_80802754;
    // 0x808024D0: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x808024D4: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
L_808024D8:
    // 0x808024D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808024DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808024E0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808024E4: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x808024E8: jal         0x80801764
    // 0x808024EC: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x808024EC: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x808024F0: b           L_80802758
    // 0x808024F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802758;
    // 0x808024F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808024F8:
    // 0x808024F8: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x808024FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802500: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802504: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x80802508: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080250C: nop

    // 0x80802510: bc1fl       L_808025A4
    if (!c1cs) {
        // 0x80802514: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808025A4;
    }
    goto skip_4;
    // 0x80802514: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_4:
    // 0x80802518: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080251C: nop

    // 0x80802520: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80802524: nop

    // 0x80802528: bc1fl       L_808025A4
    if (!c1cs) {
        // 0x8080252C: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808025A4;
    }
    goto skip_5;
    // 0x8080252C: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_5:
    // 0x80802530: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80802534: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802538: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080253C: beq         $t9, $at, L_8080256C
    if (ctx->r25 == ctx->r1) {
        // 0x80802540: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_8080256C;
    }
    // 0x80802540: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80802544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802548: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8080254C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802550: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802554: nop

    // 0x80802558: bc1f        L_8080256C
    if (!c1cs) {
        // 0x8080255C: nop
    
            goto L_8080256C;
    }
    // 0x8080255C: nop

    // 0x80802560: jal         0x80802AF8
    // 0x80802564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802AF8_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80802564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80802568: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080256C:
    // 0x8080256C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BCC) << 16);
    // 0x80802570: lwc1        $f8, 0x4BCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BCC));
    // 0x80802574: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802578: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080257C: nop

    // 0x80802580: bc1fl       L_80802758
    if (!c1cs) {
        // 0x80802584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802758;
    }
    goto skip_6;
    // 0x80802584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80802588: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080258C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BD0) << 16);
    // 0x80802590: lwc1        $f16, 0x4BD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BD0));
    // 0x80802594: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802598: b           L_80802754
    // 0x8080259C: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
        goto L_80802754;
    // 0x8080259C: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x808025A0: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
L_808025A4:
    // 0x808025A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808025A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808025AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808025B0: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x808025B4: jal         0x80801764
    // 0x808025B8: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_3;
    // 0x808025B8: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    after_3:
    // 0x808025BC: b           L_80802758
    // 0x808025C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802758;
    // 0x808025C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808025C4:
    // 0x808025C4: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x808025C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808025CC: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808025D0: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x808025D4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808025D8: nop

    // 0x808025DC: bc1fl       L_80802670
    if (!c1cs) {
        // 0x808025E0: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802670;
    }
    goto skip_7;
    // 0x808025E0: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_7:
    // 0x808025E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808025E8: nop

    // 0x808025EC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808025F0: nop

    // 0x808025F4: bc1fl       L_80802670
    if (!c1cs) {
        // 0x808025F8: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802670;
    }
    goto skip_8;
    // 0x808025F8: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_8:
    // 0x808025FC: lhu         $t0, 0x72($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X72);
    // 0x80802600: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802604: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80802608: beq         $t1, $at, L_80802638
    if (ctx->r9 == ctx->r1) {
        // 0x8080260C: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802638;
    }
    // 0x8080260C: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80802610: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802614: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802618: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080261C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80802620: nop

    // 0x80802624: bc1f        L_80802638
    if (!c1cs) {
        // 0x80802628: nop
    
            goto L_80802638;
    }
    // 0x80802628: nop

    // 0x8080262C: jal         0x80802AF8
    // 0x80802630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802AF8_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x80802630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80802634: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80802638:
    // 0x80802638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BD4) << 16);
    // 0x8080263C: lwc1        $f6, 0x4BD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BD4));
    // 0x80802640: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802644: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802648: nop

    // 0x8080264C: bc1fl       L_80802758
    if (!c1cs) {
        // 0x80802650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802758;
    }
    goto skip_9;
    // 0x80802650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80802654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802658: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BD8) << 16);
    // 0x8080265C: lwc1        $f16, 0x4BD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BD8));
    // 0x80802660: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802664: b           L_80802754
    // 0x80802668: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
        goto L_80802754;
    // 0x80802668: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x8080266C: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
L_80802670:
    // 0x80802670: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802674: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802678: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080267C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80802680: jal         0x80801764
    // 0x80802684: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802684: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    after_5:
    // 0x80802688: b           L_80802758
    // 0x8080268C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802758;
    // 0x8080268C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802690: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
L_80802694:
    // 0x80802694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802698: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8080269C: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x808026A0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808026A4: nop

    // 0x808026A8: bc1fl       L_8080273C
    if (!c1cs) {
        // 0x808026AC: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_8080273C;
    }
    goto skip_10;
    // 0x808026AC: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_10:
    // 0x808026B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808026B4: nop

    // 0x808026B8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808026BC: nop

    // 0x808026C0: bc1fl       L_8080273C
    if (!c1cs) {
        // 0x808026C4: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_8080273C;
    }
    goto skip_11;
    // 0x808026C4: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_11:
    // 0x808026C8: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x808026CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808026D0: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x808026D4: beq         $t3, $at, L_80802704
    if (ctx->r11 == ctx->r1) {
        // 0x808026D8: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802704;
    }
    // 0x808026D8: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x808026DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808026E0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808026E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808026E8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808026EC: nop

    // 0x808026F0: bc1f        L_80802704
    if (!c1cs) {
        // 0x808026F4: nop
    
            goto L_80802704;
    }
    // 0x808026F4: nop

    // 0x808026F8: jal         0x80802AF8
    // 0x808026FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802AF8_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x808026FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x80802700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80802704:
    // 0x80802704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BDC) << 16);
    // 0x80802708: lwc1        $f18, 0x4BDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BDC));
    // 0x8080270C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802710: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80802714: nop

    // 0x80802718: bc1fl       L_80802758
    if (!c1cs) {
        // 0x8080271C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802758;
    }
    goto skip_12;
    // 0x8080271C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x80802720: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802724: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BE0) << 16);
    // 0x80802728: lwc1        $f16, 0x4BE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BE0));
    // 0x8080272C: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802730: b           L_80802754
    // 0x80802734: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
        goto L_80802754;
    // 0x80802734: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80802738: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
L_8080273C:
    // 0x8080273C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802740: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802744: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802748: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8080274C: jal         0x80801764
    // 0x80802750: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_7;
    // 0x80802750: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    after_7:
L_80802754:
    // 0x80802754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802758:
    // 0x80802758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080275C: jr          $ra
    // 0x80802760: nop

    return;
    // 0x80802760: nop

;}
RECOMP_FUNC void func_80800090_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1596, 0X1E0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1596, 0X1E0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1596, 0X1E0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8080000C_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: addiu       $a1, $zero, 0x4E3
    ctx->r5 = ADD32(0, 0X4E3);
    // 0x80800028: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080002C: jal         0x80089FD0
    // 0x80800030: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: jal         0x80100094
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800044: jal         0x80089FD8
    // 0x80800048: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieitem_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x8010A828
    // 0x80800054: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8010A828(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_8080083C_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080083C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800840: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800844: addiu       $at, $zero, 0xFE4
    ctx->r1 = ADD32(0, 0XFE4);
    // 0x80800848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080084C: beq         $a1, $at, L_80800888
    if (ctx->r5 == ctx->r1) {
        // 0x80800850: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800888;
    }
    // 0x80800850: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800854: addiu       $at, $zero, 0xFE6
    ctx->r1 = ADD32(0, 0XFE6);
    // 0x80800858: beq         $a1, $at, L_80800888
    if (ctx->r5 == ctx->r1) {
        // 0x8080085C: addiu       $at, $zero, 0xFE8
        ctx->r1 = ADD32(0, 0XFE8);
            goto L_80800888;
    }
    // 0x8080085C: addiu       $at, $zero, 0xFE8
    ctx->r1 = ADD32(0, 0XFE8);
    // 0x80800860: beq         $a1, $at, L_80800978
    if (ctx->r5 == ctx->r1) {
        // 0x80800864: addiu       $at, $zero, 0xFEA
        ctx->r1 = ADD32(0, 0XFEA);
            goto L_80800978;
    }
    // 0x80800864: addiu       $at, $zero, 0xFEA
    ctx->r1 = ADD32(0, 0XFEA);
    // 0x80800868: beq         $a1, $at, L_808008AC
    if (ctx->r5 == ctx->r1) {
        // 0x8080086C: addiu       $a0, $zero, 0xB4
        ctx->r4 = ADD32(0, 0XB4);
            goto L_808008AC;
    }
    // 0x8080086C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x80800870: addiu       $at, $zero, 0x1040
    ctx->r1 = ADD32(0, 0X1040);
    // 0x80800874: beq         $a1, $at, L_80800954
    if (ctx->r5 == ctx->r1) {
        // 0x80800878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800954;
    }
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: addiu       $at, $zero, 0x105B
    ctx->r1 = ADD32(0, 0X105B);
    // 0x80800880: bne         $a1, $at, L_808009C8
    if (ctx->r5 != ctx->r1) {
        // 0x80800884: nop
    
            goto L_808009C8;
    }
    // 0x80800884: nop

L_80800888:
    // 0x80800888: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080088C: addiu       $t6, $zero, 0x53
    ctx->r14 = ADD32(0, 0X53);
    // 0x80800890: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800894: addiu       $a1, $zero, 0xFEA
    ctx->r5 = ADD32(0, 0XFEA);
    // 0x80800898: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x8080089C: jal         0x8008A208
    // 0x808008A0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808008A0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808008A4: b           L_80800A40
    // 0x808008A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A40;
    // 0x808008A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008AC:
    // 0x808008AC: jal         0x800DA298
    // 0x808008B0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808008B0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_1:
    // 0x808008B4: beq         $v0, $zero, L_80800908
    if (ctx->r2 == 0) {
        // 0x808008B8: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_80800908;
    }
    // 0x808008B8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808008BC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808008C0: jal         0x80800C00
    // 0x808008C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800C00_chpawnbroker(rdram, ctx);
        goto after_2;
    // 0x808008C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x808008C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808008CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008D0: addiu       $t7, $zero, 0x53
    ctx->r15 = ADD32(0, 0X53);
    // 0x808008D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808008D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008DC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808008E0: jal         0x8008A208
    // 0x808008E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808008E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808008E8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808008EC: addiu       $at, $zero, 0x1040
    ctx->r1 = ADD32(0, 0X1040);
    // 0x808008F0: bnel        $t8, $at, L_80800A40
    if (ctx->r24 != ctx->r1) {
        // 0x808008F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A40;
    }
    goto skip_0;
    // 0x808008F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808008F8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808008FC: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800900: b           L_80800A3C
    // 0x80800904: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_80800A3C;
    // 0x80800904: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800908:
    // 0x80800908: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8080090C: jal         0x80800C00
    // 0x80800910: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800C00_chpawnbroker(rdram, ctx);
        goto after_4;
    // 0x80800910: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80800914: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800918: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080091C: addiu       $t1, $zero, 0x53
    ctx->r9 = ADD32(0, 0X53);
    // 0x80800920: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800924: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800928: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080092C: jal         0x8008A208
    // 0x80800930: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800930: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800934: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80800938: addiu       $at, $zero, 0x1040
    ctx->r1 = ADD32(0, 0X1040);
    // 0x8080093C: bnel        $t2, $at, L_80800A40
    if (ctx->r10 != ctx->r1) {
        // 0x80800940: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A40;
    }
    goto skip_1;
    // 0x80800940: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800944: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800948: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8080094C: b           L_80800A3C
    // 0x80800950: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_80800A3C;
    // 0x80800950: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800954:
    // 0x80800954: jal         0x80100094
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080095C: jal         0x80089FE0
    // 0x80800960: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800960: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x80102424
    // 0x8080096C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x8080096C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800970: b           L_80800A40
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A40;
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800978:
    // 0x80800978: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080097C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800980: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800984: bgez        $t8, L_80800994
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800988: nop
    
            goto L_80800994;
    }
    // 0x80800988: nop

    // 0x8080098C: b           L_80800994
    // 0x80800990: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800994;
    // 0x80800990: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800994:
    // 0x80800994: jal         0x80102424
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080099C: jal         0x80106790
    // 0x808009A0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x808009A0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_10:
    // 0x808009A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009A8: jal         0x80102424
    // 0x808009AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808009AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808009B8: jal         0x80800B88
    // 0x808009BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800B88_chpawnbroker(rdram, ctx);
        goto after_12;
    // 0x808009BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_12:
    // 0x808009C0: b           L_80800A40
    // 0x808009C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A40;
    // 0x808009C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009C8:
    // 0x808009C8: jal         0x800DA298
    // 0x808009CC: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x808009CC: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    after_13:
    // 0x808009D0: beq         $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x808009D4: nop
    
            goto L_808009E0;
    }
    // 0x808009D4: nop

    // 0x808009D8: b           L_80800A24
    // 0x808009DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80800A24;
    // 0x808009DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_808009E0:
    // 0x808009E0: jal         0x800DA298
    // 0x808009E4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808009E4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_14:
    // 0x808009E8: beq         $v0, $zero, L_80800A24
    if (ctx->r2 == 0) {
        // 0x808009EC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800A24;
    }
    // 0x808009EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009F0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x808009F4: jal         0x800D0B68
    // 0x808009F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_15;
    // 0x808009F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808009FC: beq         $v0, $zero, L_80800A1C
    if (ctx->r2 == 0) {
        // 0x80800A00: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800A1C;
    }
    // 0x80800A00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800A04: jal         0x800D0A9C
    // 0x80800A08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_16;
    // 0x80800A08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800A0C: beq         $v0, $zero, L_80800A1C
    if (ctx->r2 == 0) {
        // 0x80800A10: nop
    
            goto L_80800A1C;
    }
    // 0x80800A10: nop

    // 0x80800A14: b           L_80800A24
    // 0x80800A18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80800A24;
    // 0x80800A18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80800A1C:
    // 0x80800A1C: b           L_80800A24
    // 0x80800A20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80800A24;
    // 0x80800A20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80800A24:
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: jal         0x80800AA8
    // 0x80800A2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80800AA8_chpawnbroker(rdram, ctx);
        goto after_17;
    // 0x80800A2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_17:
    // 0x80800A30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A34: jal         0x80102424
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_80800A3C:
    // 0x80800A3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A40:
    // 0x80800A40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: nop

    return;
    // 0x80800A4C: nop

;}
RECOMP_FUNC void func_8010A874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A874: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010A878: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010A87C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010A880: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010A884: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010A888: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010A88C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010A890: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010A894: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010A898: jal         0x800EB800
    // 0x8010A89C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_800EB800(rdram, ctx);
        goto after_0;
    // 0x8010A89C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010A8A0: addiu       $s5, $sp, 0x40
    ctx->r21 = ADD32(ctx->r29, 0X40);
    // 0x8010A8A4: jal         0x800E3A30
    // 0x8010A8A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800E3A30(rdram, ctx);
        goto after_1;
    // 0x8010A8A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8010A8AC: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8010A8B0: jal         0x801067C4
    // 0x8010A8B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_801067C4(rdram, ctx);
        goto after_2;
    // 0x8010A8B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x8010A8B8: beq         $v0, $zero, L_8010A94C
    if (ctx->r2 == 0) {
        // 0x8010A8BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010A94C;
    }
    // 0x8010A8BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010A8C0: addiu       $s4, $zero, 0x7
    ctx->r20 = ADD32(0, 0X7);
L_8010A8C4:
    // 0x8010A8C4: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8010A8C8: lhu         $t6, 0x14($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X14);
    // 0x8010A8CC: beq         $t6, $zero, L_8010A93C
    if (ctx->r14 == 0) {
        // 0x8010A8D0: nop
    
            goto L_8010A93C;
    }
    // 0x8010A8D0: nop

    // 0x8010A8D4: lhu         $t7, 0x64($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X64);
    // 0x8010A8D8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8010A8DC: beq         $t8, $zero, L_8010A93C
    if (ctx->r24 == 0) {
        // 0x8010A8E0: nop
    
            goto L_8010A93C;
    }
    // 0x8010A8E0: nop

    // 0x8010A8E4: lbu         $t9, 0x78($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X78);
    // 0x8010A8E8: beql        $t9, $zero, L_8010A904
    if (ctx->r25 == 0) {
        // 0x8010A8EC: lw          $s2, 0x28($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X28);
            goto L_8010A904;
    }
    goto skip_0;
    // 0x8010A8EC: lw          $s2, 0x28($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X28);
    skip_0:
    // 0x8010A8F0: jal         0x8008A7B0
    // 0x8010A8F4: nop

    _subaddiezone_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8010A8F4: nop

    after_3:
    // 0x8010A8F8: beq         $v0, $zero, L_8010A93C
    if (ctx->r2 == 0) {
        // 0x8010A8FC: nop
    
            goto L_8010A93C;
    }
    // 0x8010A8FC: nop

    // 0x8010A900: lw          $s2, 0x28($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X28);
L_8010A904:
    // 0x8010A904: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8010A908: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010A90C: sll         $t0, $s2, 23
    ctx->r8 = S32(ctx->r18 << 23);
    // 0x8010A910: srl         $s2, $t0, 24
    ctx->r18 = S32(U32(ctx->r8) >> 24);
L_8010A914:
    // 0x8010A914: and         $t2, $s2, $s1
    ctx->r10 = ctx->r18 & ctx->r17;
    // 0x8010A918: beq         $t2, $zero, L_8010A92C
    if (ctx->r10 == 0) {
        // 0x8010A91C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8010A92C;
    }
    // 0x8010A91C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010A920: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8010A924: jal         0x800EB3D0
    // 0x8010A928: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EB3D0(rdram, ctx);
        goto after_4;
    // 0x8010A928: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
L_8010A92C:
    // 0x8010A92C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010A930: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x8010A934: bne         $s0, $s4, L_8010A914
    if (ctx->r16 != ctx->r20) {
        // 0x8010A938: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_8010A914;
    }
    // 0x8010A938: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_8010A93C:
    // 0x8010A93C: jal         0x8010682C
    // 0x8010A940: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8010682C(rdram, ctx);
        goto after_5;
    // 0x8010A940: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_5:
    // 0x8010A944: bne         $v0, $zero, L_8010A8C4
    if (ctx->r2 != 0) {
        // 0x8010A948: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010A8C4;
    }
    // 0x8010A948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8010A94C:
    // 0x8010A94C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010A950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010A954: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A958: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010A95C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010A960: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010A964: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010A968: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010A96C: jr          $ra
    // 0x8010A970: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8010A970: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8010A974: nop

    // 0x8010A978: nop

    // 0x8010A97C: nop

;}
RECOMP_FUNC void func_808001E8_chgobiwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F8: jal         0x800DA298
    // 0x808001FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_0:
    // 0x80800200: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800204: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x800FFAB0
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800210: b           L_8080023C
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800218:
    // 0x80800218: jal         0x80105A9C
    // 0x8080021C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x8080021C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_2:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80102FDC
    // 0x80800228: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80800228: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_3:
    // 0x8080022C: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    // 0x80800230: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800234: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080023C:
    // 0x8080023C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_80800218_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800220: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800224: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080022C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X70A8) << 16);
    // 0x80800230: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800234: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800238: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080023C: jal         0x80087D88
    // 0x80800240: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X70A8));
    _gcnewoption_entrypoint_30(rdram, ctx);
        goto after_0;
    // 0x80800240: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X70A8));
    after_0:
    // 0x80800244: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800248: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8080024C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800250:
    // 0x80800250: jal         0x80800E38
    // 0x80800254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800E38_chquiz(rdram, ctx);
        goto after_1;
    // 0x80800254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800258: addiu       $a2, $v0, 0xA
    ctx->r6 = ADD32(ctx->r2, 0XA);
    // 0x8080025C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80800260: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800268: jal         0x80087CF8
    // 0x8080026C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080026C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800270: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800274: bnel        $s0, $s3, L_80800250
    if (ctx->r16 != ctx->r19) {
        // 0x80800278: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800250;
    }
    goto skip_0;
    // 0x80800278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800280: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800284: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800288: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080028C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800290: jr          $ra
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chstinger_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2152, 0X870) << 16);
    // 0x808007B4: jr          $ra
    // 0x808007B8: addiu       $v0, $v0, 0x870
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2152, 0X870));
    return;
    // 0x808007B8: addiu       $v0, $v0, 0x870
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2152, 0X870));
    // 0x808007BC: nop

;}
