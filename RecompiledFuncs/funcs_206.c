#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808032C0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808032C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808032C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808032CC: jal         0x80807BB8
    // 0x808032D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808032D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808032D4: jal         0x80808DB0
    // 0x808032D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808032D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808032DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032E0: jal         0x80802670
    // 0x808032E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80802670_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808032E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808032E8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808032EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032F0: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    // 0x808032F4: jal         0x80800424
    // 0x808032F8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808032F8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    after_3:
    // 0x808032FC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80803300: addiu       $a1, $a1, 0x42D8
    ctx->r5 = ADD32(ctx->r5, 0X42D8);
    // 0x80803304: jal         0x80084A70
    // 0x80803308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80803308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080330C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803318: jr          $ra
    // 0x8080331C: nop

    return;
    // 0x8080331C: nop

;}
RECOMP_FUNC void func_80800000_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800EA05C
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x111
    ctx->r1 = ADD32(0, 0X111);
    // 0x80800018: bne         $v0, $at, L_80800078
    if (ctx->r2 != ctx->r1) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800078;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80800024: jal         0x800D0B68
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080002C: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800030: addiu       $a0, $zero, 0x42
        ctx->r4 = ADD32(0, 0X42);
            goto L_80800044;
    }
    // 0x80800030: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80800034: jal         0x800FFAB0
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080003C: b           L_808000F4
    // 0x80800040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F4;
    // 0x80800040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800044:
    // 0x80800044: jal         0x800D0A9C
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080004C: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x808009F8
    // 0x8080005C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808009F8_choildrill(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800060: b           L_808000F4
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F4;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800068:
    // 0x80800068: jal         0x808009F8
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009F8_choildrill(rdram, ctx);
        goto after_5;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800070: b           L_808000F4
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F4;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: jal         0x808009F8
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808009F8_choildrill(rdram, ctx);
        goto after_6;
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800080: jal         0x800DA298
    // 0x80800084: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800084: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_7:
    // 0x80800088: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x8080008C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x80103110
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8080009C: b           L_808000F4
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F4;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x808000A8: jal         0x8008A0D0
    // 0x808000AC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808000AC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1240) << 16);
    // 0x808000B4: lwc1        $f6, 0x1240($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1240));
    // 0x808000B8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000BC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808000C0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808000C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808000C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808000CC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808000D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808000D4: jal         0x800EFA4C
    // 0x808000D8: nop

    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x808000D8: nop

    after_10:
    // 0x808000DC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000E4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808000E8: jal         0x800BEF00
    // 0x808000EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800BEF00(rdram, ctx);
        goto after_11;
    // 0x808000EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_808007BC_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007C0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808007C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808007D4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x808007D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808007DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808007E0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808007E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808007EC: jal         0x8008A1F0
    // 0x808007F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808007F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x808007F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007F8: bne         $v0, $zero, L_80800808
    if (ctx->r2 != 0) {
        // 0x808007FC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800808;
    }
    // 0x808007FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800800: b           L_8080082C
    // 0x80800804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080082C;
    // 0x80800804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800808:
    // 0x80800808: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080080C: jal         0x8008A1F8
    // 0x80800810: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800810: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800814: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800818: beql        $v0, $at, L_8080082C
    if (ctx->r2 == ctx->r1) {
        // 0x8080081C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080082C;
    }
    goto skip_0;
    // 0x8080081C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800820: b           L_8080082C
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080082C:
    // 0x8080082C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800834: jr          $ra
    // 0x80800838: nop

    return;
    // 0x80800838: nop

;}
RECOMP_FUNC void func_8080203C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080203C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802044: jal         0x800839B8
    // 0x80802048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80802048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080204C: jal         0x80800E54
    // 0x80802050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080205C: jr          $ra
    // 0x80802060: nop

    return;
    // 0x80802060: nop

;}
RECOMP_FUNC void func_80800890_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080089C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808008A0: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x808008A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808008A8: srl         $t6, $a0, 23
    ctx->r14 = S32(U32(ctx->r4) >> 23);
    // 0x808008AC: jal         0x800D0A9C
    // 0x808008B0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x808008B0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808008B4: beq         $v0, $zero, L_80800944
    if (ctx->r2 == 0) {
        // 0x808008B8: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80800944;
    }
    // 0x808008B8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808008BC: lw          $a0, 0xC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC);
    // 0x808008C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808008C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C8: srl         $t7, $a0, 23
    ctx->r15 = S32(U32(ctx->r4) >> 23);
    // 0x808008CC: jal         0x800D0B68
    // 0x808008D0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x808008D0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x808008D4: bne         $v0, $zero, L_80800944
    if (ctx->r2 != 0) {
        // 0x808008D8: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80800944;
    }
    // 0x808008D8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808008DC: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x808008E0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808008E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2626, 0XC18) << 16);
    // 0x808008E8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x808008EC: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x808008F0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808008F4: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x808008F8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x808008FC: lh          $t0, 0x4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X4);
    // 0x80800900: lw          $a0, 0xC18($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(2626, 0XC18));
    // 0x80800904: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800908: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8080090C: lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0XC);
    // 0x80800910: srl         $t3, $a2, 23
    ctx->r11 = S32(U32(ctx->r6) >> 23);
    // 0x80800914: jal         0x80108C90
    // 0x80800918: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_80108C90(rdram, ctx);
        goto after_2;
    // 0x80800918: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_2:
    // 0x8080091C: jal         0x80088458
    // 0x80800920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    _glreflight_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800920: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800924: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x80800928: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8080092C: beq         $t4, $at, L_8080093C
    if (ctx->r12 == ctx->r1) {
        // 0x80800930: nop
    
            goto L_8080093C;
    }
    // 0x80800930: nop

    // 0x80800934: jal         0x8010A570
    // 0x80800938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
L_8080093C:
    // 0x8080093C: b           L_80800948
    // 0x80800940: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_80800948;
    // 0x80800940: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80800944:
    // 0x80800944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800948:
    // 0x80800948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080094C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800950: jr          $ra
    // 0x80800954: nop

    return;
    // 0x80800954: nop

;}
RECOMP_FUNC void func_80800ADC_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE4: jal         0x80082FF0
    // 0x80800AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AEC: jal         0x80800198
    // 0x80800AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800198_bsmumswim(rdram, ctx);
        goto after_1;
    // 0x80800AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AFC: jr          $ra
    // 0x80800B00: nop

    return;
    // 0x80800B00: nop

;}
RECOMP_FUNC void func_800A4B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A4B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4B14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A4B18: jal         0x800852F0
    // 0x800A4B1C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x800A4B1C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x800A4B20: jal         0x800F65D0
    // 0x800A4B24: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F65D0(rdram, ctx);
        goto after_1;
    // 0x800A4B24: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_1:
    // 0x800A4B28: beql        $v0, $zero, L_800A4B3C
    if (ctx->r2 == 0) {
        // 0x800A4B2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4B3C;
    }
    goto skip_0;
    // 0x800A4B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800A4B30: jal         0x80090C34
    // 0x800A4B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090C34(rdram, ctx);
        goto after_2;
    // 0x800A4B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A4B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A4B3C:
    // 0x800A4B3C: jal         0x80090C28
    // 0x800A4B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80090C28(rdram, ctx);
        goto after_3;
    // 0x800A4B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800A4B44: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A4B48: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x800A4B4C: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x800A4B50: beq         $at, $zero, L_800A4BF4
    if (ctx->r1 == 0) {
        // 0x800A4B54: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A4BF4;
    }
    // 0x800A4B54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A4B58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4B5C: addu        $at, $at, $t6
    gpr jr_addend_800A4B64 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A4B60: lw          $t6, 0x558C($at)
    ctx->r14 = ADD32(ctx->r1, 0X558C);
    // 0x800A4B64: jr          $t6
    // 0x800A4B68: nop

    switch (jr_addend_800A4B64 >> 2) {
        case 0: goto L_800A4C30; break;
        case 1: goto L_800A4BC4; break;
        case 2: goto L_800A4BF4; break;
        case 3: goto L_800A4BD4; break;
        case 4: goto L_800A4B6C; break;
        case 5: goto L_800A4BE4; break;
        case 6: goto L_800A4BF4; break;
        case 7: goto L_800A4BF4; break;
        case 8: goto L_800A4BF4; break;
        case 9: goto L_800A4C30; break;
        default: switch_error(__func__, 0x800A4B64, 0x8012558C);
    }
    // 0x800A4B68: nop

L_800A4B6C:
    // 0x800A4B6C: jal         0x800A4338
    // 0x800A4B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4338(rdram, ctx);
        goto after_4;
    // 0x800A4B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A4B74: bnel        $v0, $zero, L_800A4C38
    if (ctx->r2 != 0) {
        // 0x800A4B78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4C38;
    }
    goto skip_1;
    // 0x800A4B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A4B7C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x800A4B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A4B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4B88: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800A4B8C: beq         $t8, $zero, L_800A4BB4
    if (ctx->r24 == 0) {
        // 0x800A4B90: nop
    
            goto L_800A4BB4;
    }
    // 0x800A4B90: nop

    // 0x800A4B94: jal         0x800A3F14
    // 0x800A4B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3F14(rdram, ctx);
        goto after_5;
    // 0x800A4B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A4B9C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x800A4BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4BA4: jal         0x800A3B78
    // 0x800A4BA8: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    func_800A3B78(rdram, ctx);
        goto after_6;
    // 0x800A4BA8: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    after_6:
    // 0x800A4BAC: b           L_800A4BBC
    // 0x800A4BB0: nop

        goto L_800A4BBC;
    // 0x800A4BB0: nop

L_800A4BB4:
    // 0x800A4BB4: jal         0x800A3F14
    // 0x800A4BB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3F14(rdram, ctx);
        goto after_7;
    // 0x800A4BB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_800A4BBC:
    // 0x800A4BBC: b           L_800A4C30
    // 0x800A4BC0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4C30;
    // 0x800A4BC0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4BC4:
    // 0x800A4BC4: jal         0x800A4A14
    // 0x800A4BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4A14(rdram, ctx);
        goto after_8;
    // 0x800A4BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800A4BCC: b           L_800A4C30
    // 0x800A4BD0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4C30;
    // 0x800A4BD0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4BD4:
    // 0x800A4BD4: jal         0x800A4A4C
    // 0x800A4BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4A4C(rdram, ctx);
        goto after_9;
    // 0x800A4BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800A4BDC: b           L_800A4C30
    // 0x800A4BE0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4C30;
    // 0x800A4BE0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4BE4:
    // 0x800A4BE4: jal         0x800A4AD0
    // 0x800A4BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4AD0(rdram, ctx);
        goto after_10;
    // 0x800A4BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A4BEC: b           L_800A4C30
    // 0x800A4BF0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4C30;
    // 0x800A4BF0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4BF4:
    // 0x800A4BF4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800A4BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4BFC: beq         $t0, $zero, L_800A4C24
    if (ctx->r8 == 0) {
        // 0x800A4C00: nop
    
            goto L_800A4C24;
    }
    // 0x800A4C00: nop

    // 0x800A4C04: jal         0x800A3F14
    // 0x800A4C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3F14(rdram, ctx);
        goto after_11;
    // 0x800A4C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x800A4C0C: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x800A4C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4C14: jal         0x800A3B78
    // 0x800A4C18: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    func_800A3B78(rdram, ctx);
        goto after_12;
    // 0x800A4C18: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    after_12:
    // 0x800A4C1C: b           L_800A4C30
    // 0x800A4C20: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4C30;
    // 0x800A4C20: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4C24:
    // 0x800A4C24: jal         0x800A4A74
    // 0x800A4C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4A74(rdram, ctx);
        goto after_13;
    // 0x800A4C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800A4C2C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4C30:
    // 0x800A4C30: sb          $zero, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = 0;
    // 0x800A4C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4C38:
    // 0x800A4C38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4C40: jr          $ra
    // 0x800A4C44: nop

    return;
    // 0x800A4C44: nop

;}
RECOMP_FUNC void func_808000B4_sccustom_big(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000B8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808000BC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808000C0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808000C8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808000CC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808000D4: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808000D8: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x808000DC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808000E0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808000E4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808000E8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808000EC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000F8: jal         0x8008A5D8
    // 0x808000FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800100: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800104: jal         0x8008A610
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080010C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800110: jal         0x8008A5F8
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800118: jal         0x800B8C50
    // 0x8080011C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    func_800B8C50(rdram, ctx);
        goto after_3;
    // 0x8080011C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_3:
    // 0x80800120: jal         0x800B8C98
    // 0x80800124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B8C98(rdram, ctx);
        goto after_4;
    // 0x80800124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800128: jal         0x800B8CE0
    // 0x8080012C: addiu       $a0, $zero, 0xC26
    ctx->r4 = ADD32(0, 0XC26);
    func_800B8CE0(rdram, ctx);
        goto after_5;
    // 0x8080012C: addiu       $a0, $zero, 0xC26
    ctx->r4 = ADD32(0, 0XC26);
    after_5:
    // 0x80800130: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80800134: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800138: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8080013C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800140: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80800144: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800148: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x8080014C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80800150: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800154: add.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800158: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1f        L_80800198
    if (!c1cs) {
        // 0x80800164: nop
    
            goto L_80800198;
    }
    // 0x80800164: nop

    // 0x80800168: sub.s       $f18, $f26, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x8080016C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800170: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800174: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800178: div.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8080017C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800180: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80800184: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800188: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080018C: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80800190: b           L_80800198
    // 0x80800194: nop

        goto L_80800198;
    // 0x80800194: nop

L_80800198:
    // 0x80800198: jal         0x800E7188
    // 0x8080019C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7188(rdram, ctx);
        goto after_6;
    // 0x8080019C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808001A0: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
    // 0x808001A4: jal         0x800B8C8C
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_7;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001AC: jal         0x800B7F14
    // 0x808001B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B7F14(rdram, ctx);
        goto after_8;
    // 0x808001B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x808001B4: bltz        $s3, L_80800240
    if (SIGNED(ctx->r19) < 0) {
        // 0x808001B8: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_80800240;
    }
    // 0x808001B8: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x808001BC: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x808001C0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x808001C4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808001C8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x808001CC: cvt.s.w     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    ctx->f22.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808001D0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_808001D4:
    // 0x808001D4: subu        $t7, $s3, $s0
    ctx->r15 = SUB32(ctx->r19, ctx->r16);
    // 0x808001D8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x808001DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001E0: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x808001E4: mul.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x808001E8: add.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x808001EC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x808001F0: nop

    // 0x808001F4: bc1f        L_80800200
    if (!c1cs) {
        // 0x808001F8: nop
    
            goto L_80800200;
    }
    // 0x808001F8: nop

    // 0x808001FC: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_80800200:
    // 0x80800200: bnel        $s4, $s2, L_80800218
    if (ctx->r20 != ctx->r18) {
        // 0x80800204: lbu         $a3, 0x0($t9)
        ctx->r7 = MEM_BU(ctx->r25, 0X0);
            goto L_80800218;
    }
    goto skip_0;
    // 0x80800204: lbu         $a3, 0x0($t9)
    ctx->r7 = MEM_BU(ctx->r25, 0X0);
    skip_0:
    // 0x80800208: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8080020C: b           L_80800218
    // 0x80800210: lbu         $a3, 0x0($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X0);
        goto L_80800218;
    // 0x80800210: lbu         $a3, 0x0($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X0);
    // 0x80800214: lbu         $a3, 0x0($t9)
    ctx->r7 = MEM_BU(ctx->r25, 0X0);
L_80800218:
    // 0x80800218: add.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8080021C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800220: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800224: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800228: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080022C: jal         0x800B8DEC
    // 0x80800230: nop

    func_800B8DEC(rdram, ctx);
        goto after_9;
    // 0x80800230: nop

    after_9:
    // 0x80800234: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800238: bgezl       $s0, L_808001D4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8080023C: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_808001D4;
    }
    goto skip_1;
    // 0x8080023C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_1:
L_80800240:
    // 0x80800240: jal         0x800B811C
    // 0x80800244: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B811C(rdram, ctx);
        goto after_10;
    // 0x80800244: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x80800248: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080024C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800250: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800254: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800258: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080025C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800260: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800264: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800268: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8080026C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800270: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800274: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080027C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B00: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084B00);
    return;
    // 0x80084B04: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void glhittableDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800320: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80800324: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800328: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8080032C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x80800330: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x80800334: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800338: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x8080033C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80800340: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80800344: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80800348: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x8080034C: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x80800350: sll         $t4, $t3, 22
    ctx->r12 = S32(ctx->r11 << 22);
    // 0x80800354: sll         $t7, $t6, 22
    ctx->r15 = S32(ctx->r14 << 22);
    // 0x80800358: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x8080035C: srl         $t5, $t4, 29
    ctx->r13 = S32(U32(ctx->r12) >> 29);
    // 0x80800360: jr          $ra
    // 0x80800364: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
    return;
    // 0x80800364: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1268, 0X930) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X930));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X930));
;}
RECOMP_FUNC void _chdeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087828: syscall     633
    recomp_syscall_handler(rdram, ctx, 0x80087828);
    return;
    // 0x8008782C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BF8_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C00: jal         0x80090A2C
    // 0x80800C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80800C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C08: jal         0x80800508
    // 0x80800C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: nop

    return;
    // 0x80800C1C: nop

;}
RECOMP_FUNC void func_8008D5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D5C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D5C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D5CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D5D0: jal         0x80095748
    // 0x8008D5D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x8008D5D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8008D5D8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D5DC: beq         $t6, $zero, L_8008D620
    if (ctx->r14 == 0) {
        // 0x8008D5E0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D620;
    }
    // 0x8008D5E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D5E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D5E8: jal         0x80095748
    // 0x8008D5EC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_isFalse(rdram, ctx);
        goto after_1;
    // 0x8008D5EC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_1:
    // 0x8008D5F0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D5F4: beq         $t7, $zero, L_8008D620
    if (ctx->r15 == 0) {
        // 0x8008D5F8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D620;
    }
    // 0x8008D5F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D5FC: jal         0x800C6E38
    // 0x8008D600: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x8008D600: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x8008D604: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D608: beq         $t8, $zero, L_8008D620
    if (ctx->r24 == 0) {
        // 0x8008D60C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008D620;
    }
    // 0x8008D60C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008D610: jal         0x800A3304
    // 0x8008D614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_3;
    // 0x8008D614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008D618: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D61C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008D620:
    // 0x8008D620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D628: jr          $ra
    // 0x8008D62C: nop

    return;
    // 0x8008D62C: nop

;}
RECOMP_FUNC void func_800F9A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9A4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9A50: sb          $zero, 0x5520($at)
    MEM_B(0X5520, ctx->r1) = 0;
    // 0x800F9A54: jal         0x800F9488
    // 0x800F9A58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9488(rdram, ctx);
        goto after_0;
    // 0x800F9A58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800F9A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9A64: jr          $ra
    // 0x800F9A68: nop

    return;
    // 0x800F9A68: nop

;}
RECOMP_FUNC void func_80801ECC_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801ED4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801ED8: jal         0x80100094
    // 0x80801EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801EE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801EE4: lwc1        $f4, 0x9C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80801EE8: addiu       $a0, $zero, 0x448
    ctx->r4 = ADD32(0, 0X448);
    // 0x80801EEC: addiu       $a1, $v0, 0x90
    ctx->r5 = ADD32(ctx->r2, 0X90);
    // 0x80801EF0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801EF4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80801EF8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801EFC: jal         0x80108528
    // 0x80801F00: nop

    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80801F00: nop

    after_1:
    // 0x80801F04: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F08: addiu       $a0, $zero, 0x682
    ctx->r4 = ADD32(0, 0X682);
    // 0x80801F0C: lwc1        $f8, 0x9C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X9C);
    // 0x80801F10: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x80801F14: jal         0x800DA298
    // 0x80801F18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801F18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801F1C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80801F20: bne         $v0, $zero, L_80801F44
    if (ctx->r2 != 0) {
        // 0x80801F24: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80801F44;
    }
    // 0x80801F24: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F28: lh          $t8, 0x84($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X84);
    // 0x80801F2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X264C) << 16);
    // 0x80801F30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80801F34: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801F38: lwc1        $f10, 0x264C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X264C));
    // 0x80801F3C: b           L_80801F50
    // 0x80801F40: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
        goto L_80801F50;
    // 0x80801F40: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
L_80801F44:
    // 0x80801F44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X25B4) << 16);
    // 0x80801F48: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X25B4));
    // 0x80801F4C: swc1        $f16, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f16.u32l;
L_80801F50:
    // 0x80801F50: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2668) << 16);
    // 0x80801F54: addiu       $a2, $a2, 0x2668
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2668));
    // 0x80801F58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801F5C: jal         0x80089D18
    // 0x80801F60: addiu       $a1, $a3, 0x90
    ctx->r5 = ADD32(ctx->r7, 0X90);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801F60: addiu       $a1, $a3, 0x90
    ctx->r5 = ADD32(ctx->r7, 0X90);
    after_3:
    // 0x80801F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801F6C: jr          $ra
    // 0x80801F70: nop

    return;
    // 0x80801F70: nop

;}
RECOMP_FUNC void func_80108B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108B08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80108B0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80108B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108B14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80108B18: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80108B1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108B20: addiu       $a0, $a0, -0x74BC
    ctx->r4 = ADD32(ctx->r4, -0X74BC);
    // 0x80108B24: lhu         $a3, 0x12($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X12);
    // 0x80108B28: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x80108B2C: jal         0x80086D40
    // 0x80108B30: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    _chbaddiesetup_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80108B30: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_0:
    // 0x80108B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108B3C: jr          $ra
    // 0x80108B40: nop

    return;
    // 0x80108B40: nop

;}
RECOMP_FUNC void func_800F99FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F99FC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F9A00: lbu         $t6, 0x5520($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5520);
    // 0x800F9A04: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800F9A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F9A0C: bne         $t6, $at, L_800F9A1C
    if (ctx->r14 != ctx->r1) {
        // 0x800F9A10: nop
    
            goto L_800F9A1C;
    }
    // 0x800F9A10: nop

    // 0x800F9A14: jr          $ra
    // 0x800F9A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F9A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F9A1C:
    // 0x800F9A1C: jr          $ra
    // 0x800F9A20: nop

    return;
    // 0x800F9A20: nop

;}
RECOMP_FUNC void _fxgenlist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AF0: syscall     723
    recomp_syscall_handler(rdram, ctx, 0x80088AF0);
    return;
    // 0x80088AF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bafly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BD0: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BD0);
    return;
    // 0x80084BD4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazmove_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808005C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808005CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808005D0: jal         0x8008CABC
    // 0x808005D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808005D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808005D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808005DC: jal         0x8008CAC8
    // 0x808005E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_1;
    // 0x808005E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808005E4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808005E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808005F0: beq         $v0, $at, L_80800618
    if (ctx->r2 == ctx->r1) {
        // 0x808005F4: addiu       $t6, $zero, 0xA6
        ctx->r14 = ADD32(0, 0XA6);
            goto L_80800618;
    }
    // 0x808005F4: addiu       $t6, $zero, 0xA6
    ctx->r14 = ADD32(0, 0XA6);
    // 0x808005F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005FC: beq         $v0, $at, L_80800648
    if (ctx->r2 == ctx->r1) {
        // 0x80800600: addiu       $t7, $zero, 0x24F
        ctx->r15 = ADD32(0, 0X24F);
            goto L_80800648;
    }
    // 0x80800600: addiu       $t7, $zero, 0x24F
    ctx->r15 = ADD32(0, 0X24F);
    // 0x80800604: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800608: beq         $v0, $at, L_80800678
    if (ctx->r2 == ctx->r1) {
        // 0x8080060C: addiu       $t8, $zero, 0x24D
        ctx->r24 = ADD32(0, 0X24D);
            goto L_80800678;
    }
    // 0x8080060C: addiu       $t8, $zero, 0x24D
    ctx->r24 = ADD32(0, 0X24D);
    // 0x80800610: b           L_808006A8
    // 0x80800614: addiu       $t9, $zero, 0xA6
    ctx->r25 = ADD32(0, 0XA6);
        goto L_808006A8;
    // 0x80800614: addiu       $t9, $zero, 0xA6
    ctx->r25 = ADD32(0, 0XA6);
L_80800618:
    // 0x80800618: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC44) << 16);
    // 0x8080061C: lwc1        $f4, 0xC44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC44));
    // 0x80800620: lui         $a3, 0x3F0A
    ctx->r7 = S32(0X3F0A << 16);
    // 0x80800624: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80800628: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x8080062C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800630: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800634: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    // 0x80800638: jal         0x8008C9F0
    // 0x8080063C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_2;
    // 0x8080063C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800640: b           L_808006D0
    // 0x80800644: nop

        goto L_808006D0;
    // 0x80800644: nop

L_80800648:
    // 0x80800648: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC48) << 16);
    // 0x8080064C: lwc1        $f6, 0xC48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC48));
    // 0x80800650: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800654: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80800658: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080065C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800660: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800664: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80800668: jal         0x8008C9F0
    // 0x8080066C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x8080066C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800670: b           L_808006D0
    // 0x80800674: nop

        goto L_808006D0;
    // 0x80800674: nop

L_80800678:
    // 0x80800678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC4C) << 16);
    // 0x8080067C: lwc1        $f8, 0xC4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC4C));
    // 0x80800680: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80800684: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80800688: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080068C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800690: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800694: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80800698: jal         0x8008C9F0
    // 0x8080069C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x8080069C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x808006A0: b           L_808006D0
    // 0x808006A4: nop

        goto L_808006D0;
    // 0x808006A4: nop

L_808006A8:
    // 0x808006A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC50) << 16);
    // 0x808006AC: lwc1        $f10, 0xC50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC50));
    // 0x808006B0: lui         $a3, 0x3F0A
    ctx->r7 = S32(0X3F0A << 16);
    // 0x808006B4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x808006B8: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x808006BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006C0: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x808006C4: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x808006C8: jal         0x8008C9F0
    // 0x808006CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x808006CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
L_808006D0:
    // 0x808006D0: jal         0x8008AF24
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x8008AED4
    // 0x808006E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x808006E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: jal         0x8008B1BC
    // 0x808006EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x808006EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808006F0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808006F4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808006F8: jal         0x8008B1C8
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_9;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x8008B24C
    // 0x80800708: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setStart(rdram, ctx);
        goto after_10;
    // 0x80800708: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x8008B134
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_11;
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800718: jal         0x8008B064
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800724: jal         0x8008CA30
    // 0x80800728: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_13;
    // 0x80800728: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x8080072C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800730: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800738: jal         0x8008C9BC
    // 0x8080073C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_14;
    // 0x8080073C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_14:
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800744: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800748: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080074C: jr          $ra
    // 0x80800750: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800750: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chsabreman_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086388: syscall     314
    recomp_syscall_handler(rdram, ctx, 0x80086388);
    return;
    // 0x8008638C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800020_ncbaledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x80112524
    // 0x8080002C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080002C: nop

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
RECOMP_FUNC void badronemem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800038: jal         0x8001B084
    // 0x8080003C: lw          $a0, 0x18C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18C);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080003C: lw          $a0, 0x18C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18C);
    after_0:
    // 0x80800040: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: sw          $zero, 0x18C($t7)
    MEM_W(0X18C, ctx->r15) = 0;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_80028C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80028C08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028C0C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80028C10: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80028C14: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80028C18: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80028C1C: bne         $t7, $zero, L_80028C2C
    if (ctx->r15 != 0) {
        // 0x80028C20: nop
    
            goto L_80028C2C;
    }
    // 0x80028C20: nop

    // 0x80028C24: b           L_80028DE0
    // 0x80028C28: nop

        goto L_80028DE0;
    // 0x80028C28: nop

L_80028C2C:
    // 0x80028C2C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80028C30: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80028C34: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80028C38: beq         $at, $zero, L_80028C4C
    if (ctx->r1 == 0) {
        // 0x80028C3C: nop
    
            goto L_80028C4C;
    }
    // 0x80028C3C: nop

    // 0x80028C40: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80028C44: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80028C48: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
L_80028C4C:
    // 0x80028C4C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80028C50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80028C54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80028C58: lh          $t4, 0x2($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2);
    // 0x80028C5C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80028C60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028C64: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80028C68: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80028C6C: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x80028C70: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028C74: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80028C78: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80028C7C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80028C80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028C84: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80028C88: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80028C8C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80028C90: jal         0x800288C0
    // 0x80028C94: nop

    func_800288C0(rdram, ctx);
        goto after_0;
    // 0x80028C94: nop

    after_0:
    // 0x80028C98: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80028C9C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80028CA0:
    // 0x80028CA0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80028CA4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80028CA8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80028CAC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80028CB0: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80028CB4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80028CB8: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80028CBC: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x80028CC0: bne         $at, $zero, L_80028CA0
    if (ctx->r1 != 0) {
        // 0x80028CC4: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_80028CA0;
    }
    // 0x80028CC4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80028CC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80028CCC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80028CD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80028CD4: lh          $t4, 0x2($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2);
    // 0x80028CD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028CDC: lwc1        $f18, 0x1D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1D20);
    // 0x80028CE0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80028CE4: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x80028CE8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80028CEC: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80028CF0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80028CF4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80028CF8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80028CFC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80028D00: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80028D04: nop

    // 0x80028D08: sh          $t8, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r24;
    // 0x80028D0C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80028D10: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80028D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80028D18: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80028D1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028D20: lwc1        $f8, 0x1D24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1D24);
    // 0x80028D24: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80028D28: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x80028D2C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80028D30: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80028D34: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80028D38: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80028D3C: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80028D40: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80028D44: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80028D48: nop

    // 0x80028D4C: sh          $t3, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r11;
    // 0x80028D50: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80028D54: sh          $zero, 0xC($t4)
    MEM_H(0XC, ctx->r12) = 0;
    // 0x80028D58: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x80028D5C: lui         $at, 0xC680
    ctx->r1 = S32(0XC680 << 16);
    // 0x80028D60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028D64: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80028D68: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80028D6C: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80028D70: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80028D74: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80028D78: nop

    // 0x80028D7C: sh          $t8, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r24;
    // 0x80028D80: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x80028D84: lui         $at, 0xC680
    ctx->r1 = S32(0XC680 << 16);
    // 0x80028D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80028D8C: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80028D90: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80028D94: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80028D98: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80028D9C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80028DA0: nop

    // 0x80028DA4: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x80028DA8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80028DAC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_80028DB0:
    // 0x80028DB0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80028DB4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80028DB8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80028DBC: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x80028DC0: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x80028DC4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80028DC8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80028DCC: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x80028DD0: bne         $at, $zero, L_80028DB0
    if (ctx->r1 != 0) {
        // 0x80028DD4: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_80028DB0;
    }
    // 0x80028DD4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80028DD8: b           L_80028DE0
    // 0x80028DDC: nop

        goto L_80028DE0;
    // 0x80028DDC: nop

L_80028DE0:
    // 0x80028DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028DE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80028DE8: jr          $ra
    // 0x80028DEC: nop

    return;
    // 0x80028DEC: nop

;}
RECOMP_FUNC void func_8080042C_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800434: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080043C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800440: bgez        $t8, L_8080045C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800444: nop
    
            goto L_8080045C;
    }
    // 0x80800444: nop

    // 0x80800448: jal         0x80089BD8
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800450: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80800454: b           L_8080045C
    // 0x80800458: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
        goto L_8080045C;
    // 0x80800458: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_8080045C:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C18: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C18);
    return;
    // 0x80083C1C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80108618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010861C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80108624: jal         0x800DA298
    // 0x80108628: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80108628: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8010862C: beql        $v0, $zero, L_80108648
    if (ctx->r2 == 0) {
        // 0x80108630: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80108648;
    }
    goto skip_0;
    // 0x80108630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80108634: jal         0x800FFAB0
    // 0x80108638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80108638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010863C: b           L_80108648
    // 0x80108640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80108648;
    // 0x80108640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80108648:
    // 0x80108648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010864C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108650: jr          $ra
    // 0x80108654: nop

    return;
    // 0x80108654: nop

;}
RECOMP_FUNC void func_80802824_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080282C: jal         0x80104248
    // 0x80802830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80802830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802838: jal         0x8008AED4
    // 0x8080283C: addiu       $a1, $zero, 0x109
    ctx->r5 = ADD32(0, 0X109);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8080283C: addiu       $a1, $zero, 0x109
    ctx->r5 = ADD32(0, 0X109);
    after_1:
    // 0x80802840: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80802844: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80802848: jal         0x80101CDC
    // 0x8080284C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x8080284C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80802850: jal         0x808026D0
    // 0x80802854: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808026D0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80802854: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80802858: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080285C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80802860: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80802864: bgezl       $t9, L_80802878
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802868: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802878;
    }
    goto skip_0;
    // 0x80802868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080286C: jal         0x808000B8
    // 0x80802870: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_808000B8_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80802870: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80802874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802878:
    // 0x80802878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080287C: jr          $ra
    // 0x80802880: nop

    return;
    // 0x80802880: nop

;}
RECOMP_FUNC void _bsmumcast_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083878: syscall     77
    recomp_syscall_handler(rdram, ctx, 0x80083878);
    return;
    // 0x8008387C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800390_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800394: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: beq         $a1, $at, L_808003B8
    if (ctx->r5 == ctx->r1) {
        // 0x808003A0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003B8;
    }
    // 0x808003A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003A8: beq         $a1, $at, L_808003C8
    if (ctx->r5 == ctx->r1) {
        // 0x808003AC: nop
    
            goto L_808003C8;
    }
    // 0x808003AC: nop

    // 0x808003B0: b           L_808003E4
    // 0x808003B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003E4;
    // 0x808003B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003B8:
    // 0x808003B8: jal         0x80800CC8
    // 0x808003BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800CC8_chstonepillar(rdram, ctx);
        goto after_0;
    // 0x808003BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x808003C0: b           L_808003E4
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003E4;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C8:
    // 0x808003C8: jal         0x80800C44
    // 0x808003CC: nop

    func_80800C44_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x808003CC: nop

    after_1:
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003E4;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003D8: b           L_808003E4
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003E4;
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E4:
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DF0: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DF0);
    return;
    // 0x80084DF4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80094E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094E80: jal         0x800964D0
    // 0x80094E84: nop

    func_800964D0(rdram, ctx);
        goto after_0;
    // 0x80094E84: nop

    after_0:
    // 0x80094E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094E90: jr          $ra
    // 0x80094E94: nop

    return;
    // 0x80094E94: nop

;}
RECOMP_FUNC void func_8080033C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080033C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800340: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800348: beq         $a1, $at, L_8080036C
    if (ctx->r5 == ctx->r1) {
        // 0x8080034C: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080036C;
    }
    // 0x8080034C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800350: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800354: beq         $a1, $at, L_80800380
    if (ctx->r5 == ctx->r1) {
        // 0x80800358: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800380;
    }
    // 0x80800358: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080035C: beq         $a1, $at, L_808003D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800360: nop
    
            goto L_808003D4;
    }
    // 0x80800360: nop

    // 0x80800364: b           L_808003FC
    // 0x80800368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x80800368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080036C:
    // 0x8080036C: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x80800370: jal         0x8080040C
    // 0x80800374: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    func_8080040C_chcoderoombits(rdram, ctx);
        goto after_0;
    // 0x80800374: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    after_0:
    // 0x80800378: b           L_808003FC
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800380:
    // 0x80800380: jal         0x800BEC10
    // 0x80800384: nop

    func_800BEC10(rdram, ctx);
        goto after_1;
    // 0x80800384: nop

    after_1:
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080038C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800390: jal         0x800DBEFC
    // 0x80800394: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800394: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80800398: jal         0x800F54E4
    // 0x8080039C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x8080039C: nop

    after_3:
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003A4: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x808003A8: jal         0x800F7CF4
    // 0x808003AC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F7CF4(rdram, ctx);
        goto after_4;
    // 0x808003AC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808003B0: jal         0x800F54E4
    // 0x808003B4: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808003B4: nop

    after_5:
    // 0x808003B8: jal         0x800F53D0
    // 0x808003BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_6;
    // 0x808003BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C4: jal         0x800946C4
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_7;
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003CC: b           L_808003FC
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D4:
    // 0x808003D4: jal         0x808004B8
    // 0x808003D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_808004B8_chcoderoombits(rdram, ctx);
        goto after_8;
    // 0x808003D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_8:
    // 0x808003DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003E0: jal         0x80101FDC
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808003E8: b           L_808003FC
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003F0: b           L_808003FC
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003FC:
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_8080103C_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080103C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080104C: lui         $a1, 0xC2F0
    ctx->r5 = S32(0XC2F0 << 16);
    // 0x80801050: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80801054: jal         0x80086880
    // 0x80801058: addiu       $a3, $zero, 0xC2
    ctx->r7 = ADD32(0, 0XC2);
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801058: addiu       $a3, $zero, 0xC2
    ctx->r7 = ADD32(0, 0XC2);
    after_0:
    // 0x8080105C: beq         $v0, $zero, L_80801078
    if (ctx->r2 == 0) {
        // 0x80801060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801078;
    }
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801064: jal         0x800868C0
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080106C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801070: jal         0x800868A8
    // 0x80801074: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801074: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    after_2:
L_80801078:
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080107C: jal         0x8010A800
    // 0x80801080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x80801080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801084: jal         0x8010A63C
    // 0x80801088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_4;
    // 0x80801088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080108C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void func_80800884_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800884: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080088C: jal         0x80088848
    // 0x80800890: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800890: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800894: bnel        $v0, $zero, L_808008D0
    if (ctx->r2 != 0) {
        // 0x80800898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008D0;
    }
    goto skip_0;
    // 0x80800898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080089C: jal         0x8010D600
    // 0x808008A0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D600(rdram, ctx);
        goto after_1;
    // 0x808008A0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808008A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008A8: jal         0x80102D78
    // 0x808008AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_2;
    // 0x808008AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x808008B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008B4: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x808008B8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808008BC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808008C0: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x808008C4: jal         0x80102BF8
    // 0x808008C8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_3;
    // 0x808008C8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_3:
    // 0x808008CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008D0:
    // 0x808008D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008D4: jr          $ra
    // 0x808008D8: nop

    return;
    // 0x808008D8: nop

;}
RECOMP_FUNC void func_800E046C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E046C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x800E0470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E0474: bnel        $a1, $v0, L_800E0488
    if (ctx->r5 != ctx->r2) {
        // 0x800E0478: lh          $v1, 0x0($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X0);
            goto L_800E0488;
    }
    goto skip_0;
    // 0x800E0478: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    skip_0:
    // 0x800E047C: jr          $ra
    // 0x800E0480: lwc1        $f0, 0x5D70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D70);
    return;
    // 0x800E0480: lwc1        $f0, 0x5D70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D70);
    // 0x800E0484: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
L_800E0488:
    // 0x800E0488: subu        $t6, $a1, $v1
    ctx->r14 = SUB32(ctx->r5, ctx->r3);
    // 0x800E048C: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800E0490: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800E0494: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E0498: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E049C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E04A0: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800E04A4: jr          $ra
    // 0x800E04A8: nop

    return;
    // 0x800E04A8: nop

;}
RECOMP_FUNC void func_80800438_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080043C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800444: jal         0x8009EF1C
    // 0x80800448: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800448: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080044C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800450: jal         0x8009EF10
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800458: bne         $v0, $zero, L_80800470
    if (ctx->r2 != 0) {
        // 0x8080045C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800470;
    }
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x8009B9B0
    // 0x80800464: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800464: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800468: b           L_808004A4
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A4;
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800470:
    // 0x80800470: jal         0x808001B8
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001B8_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800478: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080047C: jal         0x80800164
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800484: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800488: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080048C: jal         0x800F1214
    // 0x80800490: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x80800490: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800494: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800498: jal         0x8009B9B0
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A4:
    // 0x808004A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void gcaudiolist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800008: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8080000C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2638, 0XF0) << 16);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800018: lw          $a1, 0xF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(2638, 0XF0));
    // 0x8080001C: jal         0x800C4AF0
    // 0x80800020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_801120CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801120CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801120D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801120D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801120D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801120DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801120E0: jal         0x80110840
    // 0x801120E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x801120E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x801120E8: jal         0x800F53E4
    // 0x801120EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53E4(rdram, ctx);
        goto after_1;
    // 0x801120EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801120F0: beq         $v0, $zero, L_80112108
    if (ctx->r2 == 0) {
        // 0x801120F4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80112108;
    }
    // 0x801120F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801120F8: jal         0x800A3048
    // 0x801120FC: nop

    func_800A3048(rdram, ctx);
        goto after_2;
    // 0x801120FC: nop

    after_2:
    // 0x80112100: b           L_80112114
    // 0x80112104: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80112114;
    // 0x80112104: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80112108:
    // 0x80112108: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8011210C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80112110: nop

L_80112114:
    // 0x80112114: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80112118: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8011211C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80112120: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80112124: swc1        $f6, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f6.u32l;
    // 0x80112128: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8011212C: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x80112130: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80112134: swc1        $f10, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f10.u32l;
    // 0x80112138: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8011213C: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80112140: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80112144: swc1        $f18, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f18.u32l;
    // 0x80112148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011214C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112150: jr          $ra
    // 0x80112154: nop

    return;
    // 0x80112154: nop

    // 0x80112158: nop

    // 0x8011215C: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FB0: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FB0);
    return;
    // 0x80083FB4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80096388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096388: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x8009638C: jr          $ra
    // 0x80096390: lw          $v0, 0x9C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X9C);
    return;
    // 0x80096390: lw          $v0, 0x9C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X9C);
;}
RECOMP_FUNC void bainvisible_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800874: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800878: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8080087C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800880: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800884: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800888: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8080088C: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80800890: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800894: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800898: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080089C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808008A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008A4: blez        $a1, L_8080095C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808008A8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080095C;
    }
    // 0x808008A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808008B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808008B4: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x808008B8: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
L_808008BC:
    // 0x808008BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808008C0: jal         0x8009BC08
    // 0x808008C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8009BC08(rdram, ctx);
        goto after_0;
    // 0x808008C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x808008C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008CC: jal         0x800EFC7C
    // 0x808008D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x808008D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_1:
    // 0x808008D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808008D8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x808008DC: blez        $s0, L_80800938
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808008E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800938;
    }
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E4: addu        $t6, $s4, $s2
    ctx->r14 = ADD32(ctx->r20, ctx->r18);
    // 0x808008E8: lwc1        $f4, -0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, -0X4);
    // 0x808008EC: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x808008F0: addu        $v0, $s4, $a1
    ctx->r2 = ADD32(ctx->r20, ctx->r5);
    // 0x808008F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808008F8: addu        $v1, $s5, $a1
    ctx->r3 = ADD32(ctx->r21, ctx->r5);
    // 0x808008FC: bc1fl       L_8080093C
    if (!c1cs) {
        // 0x80800900: sll         $a1, $a0, 2
        ctx->r5 = S32(ctx->r4 << 2);
            goto L_8080093C;
    }
    goto skip_0;
    // 0x80800900: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    skip_0:
    // 0x80800904: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
L_80800908:
    // 0x80800908: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8080090C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80800910: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80800914: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800918: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8080091C: blez        $a0, L_80800938
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800920: swc1        $f6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
            goto L_80800938;
    }
    // 0x80800920: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800924: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800928: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8080092C: nop

    // 0x80800930: bc1tl       L_80800908
    if (c1cs) {
        // 0x80800934: lw          $t7, -0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, -0X4);
            goto L_80800908;
    }
    goto skip_1;
    // 0x80800934: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    skip_1:
L_80800938:
    // 0x80800938: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
L_8080093C:
    // 0x8080093C: addu        $t8, $s5, $a1
    ctx->r24 = ADD32(ctx->r21, ctx->r5);
    // 0x80800940: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800944: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x80800948: addu        $t9, $s4, $a1
    ctx->r25 = ADD32(ctx->r20, ctx->r5);
    // 0x8080094C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800950: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800954: bne         $s0, $s6, L_808008BC
    if (ctx->r16 != ctx->r22) {
        // 0x80800958: swc1        $f0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
            goto L_808008BC;
    }
    // 0x80800958: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
L_8080095C:
    // 0x8080095C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800960: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800964: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800968: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080096C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800970: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800974: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800978: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8080097C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800980: jr          $ra
    // 0x80800984: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800984: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80800988: nop

    // 0x8080098C: nop

;}
RECOMP_FUNC void func_8080096C_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080096C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800974: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800978: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080097C: jal         0x80100094
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800984: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800988: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080098C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800990: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80800994: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080099C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x808009A0: bgezl       $t9, L_80800B5C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808009A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_0;
    // 0x808009A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009A8: beql        $a0, $zero, L_80800B5C
    if (ctx->r4 == 0) {
        // 0x808009AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_1;
    // 0x808009AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808009B0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x808009B4: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    // 0x808009B8: srl         $t0, $v0, 22
    ctx->r8 = S32(U32(ctx->r2) >> 22);
    // 0x808009BC: beq         $t0, $at, L_808009E4
    if (ctx->r8 == ctx->r1) {
        // 0x808009C0: addiu       $at, $zero, 0x26D
        ctx->r1 = ADD32(0, 0X26D);
            goto L_808009E4;
    }
    // 0x808009C0: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x808009C4: beq         $t0, $at, L_808009EC
    if (ctx->r8 == ctx->r1) {
        // 0x808009C8: addiu       $at, $zero, 0x26E
        ctx->r1 = ADD32(0, 0X26E);
            goto L_808009EC;
    }
    // 0x808009C8: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x808009CC: beq         $t0, $at, L_808009FC
    if (ctx->r8 == ctx->r1) {
        // 0x808009D0: addiu       $at, $zero, 0x26F
        ctx->r1 = ADD32(0, 0X26F);
            goto L_808009FC;
    }
    // 0x808009D0: addiu       $at, $zero, 0x26F
    ctx->r1 = ADD32(0, 0X26F);
    // 0x808009D4: beq         $t0, $at, L_808009F4
    if (ctx->r8 == ctx->r1) {
        // 0x808009D8: nop
    
            goto L_808009F4;
    }
    // 0x808009D8: nop

    // 0x808009DC: b           L_80800A00
    // 0x808009E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800A00;
    // 0x808009E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808009E4:
    // 0x808009E4: b           L_80800A00
    // 0x808009E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_80800A00;
    // 0x808009E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_808009EC:
    // 0x808009EC: b           L_80800A00
    // 0x808009F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_80800A00;
    // 0x808009F0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_808009F4:
    // 0x808009F4: b           L_80800A00
    // 0x808009F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
        goto L_80800A00;
    // 0x808009F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
L_808009FC:
    // 0x808009FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80800A00:
    // 0x80800A00: beql        $a1, $zero, L_80800B5C
    if (ctx->r5 == 0) {
        // 0x80800A04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_2;
    // 0x80800A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800A08: beql        $v1, $zero, L_80800B5C
    if (ctx->r3 == 0) {
        // 0x80800A0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_3;
    // 0x80800A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800A14: jal         0x8008A440
    // 0x80800A18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800A18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800A1C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800A20: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A28: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80800A2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800A30: bnel        $v0, $t2, L_80800B5C
    if (ctx->r2 != ctx->r10) {
        // 0x80800A34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_4;
    // 0x80800A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800A38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800A3C: jal         0x8008A448
    // 0x80800A40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800A40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800A44: jal         0x80800908
    // 0x80800A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800908_chtoothyfish(rdram, ctx);
        goto after_3;
    // 0x80800A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800A4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800A54: bltz        $v0, L_80800B58
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800A58: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80800B58;
    }
    // 0x80800A58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800A5C: addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // 0x80800A60: lbu         $t3, 0x39($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X39);
    // 0x80800A64: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800A68: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80800A6C: bne         $a1, $at, L_80800B3C
    if (ctx->r5 != ctx->r1) {
        // 0x80800A70: sb          $t4, 0x39($v1)
        MEM_B(0X39, ctx->r3) = ctx->r12;
            goto L_80800B3C;
    }
    // 0x80800A70: sb          $t4, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r12;
    // 0x80800A74: blezl       $v0, L_80800ADC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800A78: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80800ADC;
    }
    goto skip_5;
    // 0x80800A78: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_5:
    // 0x80800A7C: lbu         $t5, 0x33($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X33);
    // 0x80800A80: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800A84: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    // 0x80800A88: bne         $t5, $zero, L_80800AD8
    if (ctx->r13 != 0) {
        // 0x80800A8C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800AD8;
    }
    // 0x80800A8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A90: lbu         $t6, 0x39($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X39);
    // 0x80800A94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A98: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800A9C: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80800AA0: sb          $t7, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r15;
    // 0x80800AA4: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80800AA8: swc1        $f4, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f4.u32l;
    // 0x80800AAC: lbu         $t0, 0x39($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X39);
    // 0x80800AB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AB4: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80800AB8: slti        $at, $t0, 0x1E
    ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
    // 0x80800ABC: bnel        $at, $zero, L_80800ADC
    if (ctx->r1 != 0) {
        // 0x80800AC0: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80800ADC;
    }
    goto skip_6;
    // 0x80800AC0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_6:
    // 0x80800AC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800AC8: jal         0x80108B04
    // 0x80800ACC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80800ACC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800AD0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800AD8:
    // 0x80800AD8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80800ADC:
    // 0x80800ADC: beq         $at, $zero, L_80800B3C
    if (ctx->r1 == 0) {
        // 0x80800AE0: addu        $t1, $a3, $a2
        ctx->r9 = ADD32(ctx->r7, ctx->r6);
            goto L_80800B3C;
    }
    // 0x80800AE0: addu        $t1, $a3, $a2
    ctx->r9 = ADD32(ctx->r7, ctx->r6);
    // 0x80800AE4: lbu         $t2, 0x35($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X35);
    // 0x80800AE8: addiu       $a1, $a2, 0x1
    ctx->r5 = ADD32(ctx->r6, 0X1);
    // 0x80800AEC: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x80800AF0: bne         $t2, $zero, L_80800B3C
    if (ctx->r10 != 0) {
        // 0x80800AF4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800B3C;
    }
    // 0x80800AF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AF8: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
    // 0x80800AFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B00: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80800B04: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x80800B08: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x80800B0C: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80800B10: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    // 0x80800B14: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x80800B18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B1C: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x80800B20: bnel        $at, $zero, L_80800B40
    if (ctx->r1 != 0) {
        // 0x80800B24: addu        $t8, $a3, $a2
        ctx->r24 = ADD32(ctx->r7, ctx->r6);
            goto L_80800B40;
    }
    goto skip_7;
    // 0x80800B24: addu        $t8, $a3, $a2
    ctx->r24 = ADD32(ctx->r7, ctx->r6);
    skip_7:
    // 0x80800B28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800B2C: jal         0x80108B04
    // 0x80800B30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800B30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800B34: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B38: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800B3C:
    // 0x80800B3C: addu        $t8, $a3, $a2
    ctx->r24 = ADD32(ctx->r7, ctx->r6);
L_80800B40:
    // 0x80800B40: lbu         $t9, 0x34($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X34);
    // 0x80800B44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B48: bnel        $t9, $zero, L_80800B5C
    if (ctx->r25 != 0) {
        // 0x80800B4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B5C;
    }
    goto skip_8;
    // 0x80800B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80800B50: jal         0x80800350
    // 0x80800B54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800350_chtoothyfish(rdram, ctx);
        goto after_6;
    // 0x80800B54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
L_80800B58:
    // 0x80800B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B5C:
    // 0x80800B5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B60: jr          $ra
    // 0x80800B64: nop

    return;
    // 0x80800B64: nop

;}
RECOMP_FUNC void func_8010FDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FDEC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010FDF0: addiu       $t6, $zero, 0x29
    ctx->r14 = ADD32(0, 0X29);
    // 0x8010FDF4: sb          $t6, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r14;
    // 0x8010FDF8: jr          $ra
    // 0x8010FDFC: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8010FDFC: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bskazwingwhack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837A8: syscall     73
    recomp_syscall_handler(rdram, ctx, 0x800837A8);
    return;
    // 0x800837AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80000404: addiu       $t0, $t0, 0x44E0
    ctx->r8 = ADD32(ctx->r8, 0X44E0);
    // 0x80000408: addiu       $t1, $zero, 0x3F90
    ctx->r9 = ADD32(0, 0X3F90);
L_8000040C:
    // 0x8000040C: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000410: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000414: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80000418: bne         $t1, $zero, L_8000040C
    if (ctx->r9 != 0) {
        // 0x8000041C: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8000040C;
    }
    // 0x8000041C: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000420: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80000424: lui         $sp, 0x8000
    ctx->r29 = S32(0X8000 << 16);
    // 0x80000428: addiu       $t2, $t2, 0x450
    ctx->r10 = ADD32(ctx->r10, 0X450);
    // 0x8000042C: jr          $t2
    // 0x80000430: addiu       $sp, $sp, 0x64E0
    ctx->r29 = ADD32(ctx->r29, 0X64E0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000430: addiu       $sp, $sp, 0x64E0
    ctx->r29 = ADD32(ctx->r29, 0X64E0);
;}
RECOMP_FUNC void func_800BEA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BEA30: jal         0x800BE7F8
    // 0x800BEA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BE7F8(rdram, ctx);
        goto after_0;
    // 0x800BEA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800BEA38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEA3C: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BEA40: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BEA44: beql        $t6, $zero, L_800BEA58
    if (ctx->r14 == 0) {
        // 0x800BEA48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BEA58;
    }
    goto skip_0;
    // 0x800BEA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BEA4C: jal         0x80087F98
    // 0x800BEA50: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _gcmapsects_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x800BEA50: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800BEA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BEA58:
    // 0x800BEA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEA5C: jr          $ra
    // 0x800BEA60: nop

    return;
    // 0x800BEA60: nop

;}
RECOMP_FUNC void func_800C4140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4140: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800C4144: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x800C4148: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x800C414C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800C4150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4154: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C4158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C415C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C4160: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C4164: andi        $a0, $a0, 0x7FF
    ctx->r4 = ctx->r4 & 0X7FF;
    // 0x800C4168: bgez        $t8, L_800C4180
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C416C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C4180;
    }
    // 0x800C416C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4170: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C4174: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4178: nop

    // 0x800C417C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C4180:
    // 0x800C4180: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800C4184: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C4188: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C418C: srl         $a2, $t6, 6
    ctx->r6 = S32(U32(ctx->r14) >> 6);
    // 0x800C4190: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C4194: srl         $t2, $t0, 16
    ctx->r10 = S32(U32(ctx->r8) >> 16);
    // 0x800C4198: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800C419C: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800C41A0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800C41A4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800C41A8: andi        $t9, $a2, 0x7FE0
    ctx->r25 = ctx->r6 & 0X7FE0;
    // 0x800C41AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C41B0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C41B4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C41B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800C41BC: bgez        $t1, L_800C41D0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C41C0: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_800C41D0;
    }
    // 0x800C41C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C41C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C41C8: nop

    // 0x800C41CC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800C41D0:
    // 0x800C41D0: bgez        $t3, L_800C41E8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800C41D4: swc1        $f4, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
            goto L_800C41E8;
    }
    // 0x800C41D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C41D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C41DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C41E0: nop

    // 0x800C41E4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C41E8:
    // 0x800C41E8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800C41EC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800C41F0: jal         0x800C401C
    // 0x800C41F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C401C(rdram, ctx);
        goto after_0;
    // 0x800C41F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800C41F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C41FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C4200: jr          $ra
    // 0x800C4204: nop

    return;
    // 0x800C4204: nop

;}
RECOMP_FUNC void func_80800570_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080057C: jal         0x80101FDC
    // 0x80800580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800584: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800588: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080058C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800590: beq         $t6, $at, L_808005B4
    if (ctx->r14 == ctx->r1) {
        // 0x80800594: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808005B4;
    }
    // 0x80800594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800598: beq         $t6, $at, L_808005F0
    if (ctx->r14 == ctx->r1) {
        // 0x8080059C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808005F0;
    }
    // 0x8080059C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005A4: beq         $t6, $at, L_8080060C
    if (ctx->r14 == ctx->r1) {
        // 0x808005A8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080060C;
    }
    // 0x808005A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005AC: b           L_80800624
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005B4:
    // 0x808005B4: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x808005B8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808005BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005C0: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x808005C4: ori         $t9, $t8, 0x30
    ctx->r25 = ctx->r24 | 0X30;
    // 0x808005C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808005CC: jal         0x800DC178
    // 0x808005D0: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808005D0: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    after_1:
    // 0x808005D4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808005D8: jal         0x80089A80
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiebounce_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005E0: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808005E4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x808005E8: b           L_80800620
    // 0x808005EC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800620;
    // 0x808005EC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_808005F0:
    // 0x808005F0: jal         0x800EE7F8
    // 0x808005F4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808005F4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x8008A4B0
    // 0x80800600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800604: b           L_80800624
    // 0x80800608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800624;
    // 0x80800608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080060C:
    // 0x8080060C: jal         0x800EE7F8
    // 0x80800610: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800610: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80800614: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800618: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8080061C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800620:
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800624:
    // 0x80800624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080062C: jr          $ra
    // 0x80800630: nop

    return;
    // 0x80800630: nop

;}
