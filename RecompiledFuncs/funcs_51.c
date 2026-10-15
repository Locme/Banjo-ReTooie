#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void gcegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: jal         0x800D3948
    // 0x808001BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001C0: bne         $v0, $zero, L_808001D0
    if (ctx->r2 != 0) {
        // 0x808001C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001D0;
    }
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C8: b           L_808001EC
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001EC;
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D0:
    // 0x808001D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2678, 0X20B) << 16);
    // 0x808001D8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808001DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808001E0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x808001E4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x808001E8: lbu         $v0, 0x20B($v1)
    ctx->r2 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(2678, 0X20B));
L_808001EC:
    // 0x808001EC: jr          $ra
    // 0x808001F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808001F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F4: nop

    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void chtiptup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1020, 0X1490) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1490
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X1490));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1490
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X1490));
;}
RECOMP_FUNC void func_808000AC_chshockjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808000B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000BC: bne         $a1, $at, L_808000D4
    if (ctx->r5 != ctx->r1) {
        // 0x808000C0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808000D4;
    }
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: jal         0x800F7B9C
    // 0x808000C8: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    func_800F7B9C(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    after_0:
    // 0x808000CC: b           L_808000DC
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000DC;
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D4:
    // 0x808000D4: b           L_808000DC
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000DC;
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000DC:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void gcmapDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C90: jal         0x80800000
    // 0x80800C94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800000_gcmapDll(rdram, ctx);
        goto after_0;
    // 0x80800C94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800C98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C9C: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x80800CA0: beql        $t6, $zero, L_80800CD8
    if (ctx->r14 == 0) {
        // 0x80800CA4: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CD8;
    }
    goto skip_0;
    // 0x80800CA4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800CA8: jal         0x800D5B24
    // 0x80800CAC: nop

    func_800D5B24(rdram, ctx);
        goto after_1;
    // 0x80800CAC: nop

    after_1:
    // 0x80800CB0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB4: jal         0x800D674C
    // 0x80800CB8: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800CB8: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    after_2:
    // 0x80800CBC: jal         0x800B27FC
    // 0x80800CC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_3;
    // 0x80800CC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800CC4: jal         0x80087A30
    // 0x80800CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800CCC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD0: sw          $v0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r2;
    // 0x80800CD4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80800CD8:
    // 0x80800CD8: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80800CDC: beql        $t0, $zero, L_80800D14
    if (ctx->r8 == 0) {
        // 0x80800CE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800D14;
    }
    goto skip_1;
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800CE4: jal         0x800D5B24
    // 0x80800CE8: nop

    func_800D5B24(rdram, ctx);
        goto after_5;
    // 0x80800CE8: nop

    after_5:
    // 0x80800CEC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CF0: jal         0x800D674C
    // 0x80800CF4: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x80800CF4: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    after_6:
    // 0x80800CF8: jal         0x800B27FC
    // 0x80800CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_7;
    // 0x80800CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800D00: jal         0x80087A30
    // 0x80800D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800D08: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80800D0C: sw          $v0, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r2;
    // 0x80800D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D14:
    // 0x80800D14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D18: jr          $ra
    // 0x80800D1C: nop

    return;
    // 0x80800D1C: nop

;}
RECOMP_FUNC void func_80800090_chmole_hailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1828, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1828, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1828, 0XC0));
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
RECOMP_FUNC void func_8080119C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080119C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808011A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808011A8: jal         0x80092BE8
    // 0x808011AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80092BE8(rdram, ctx);
        goto after_0;
    // 0x808011AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808011B0: jal         0x800D8FF8
    // 0x808011B4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808011B4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808011B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C0: jal         0x800852F0
    // 0x808011C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808011C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808011C8: lbu         $v1, 0x15C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X15C);
    // 0x808011CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808011D0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808011D4: beq         $v1, $at, L_808011F0
    if (ctx->r3 == ctx->r1) {
        // 0x808011D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011F0;
    }
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011E0: beq         $v1, $at, L_80801270
    if (ctx->r3 == ctx->r1) {
        // 0x808011E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801270;
    }
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E8: b           L_80801304
    // 0x808011EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801304;
    // 0x808011EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011F0:
    // 0x808011F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808011F4: jal         0x80085300
    // 0x808011F8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    _batimer_get(rdram, ctx);
        goto after_3;
    // 0x808011F8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x808011FC: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80801200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801204: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801208: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x8080120C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801210: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801214: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    // 0x80801218: jal         0x800F10B4
    // 0x8080121C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080121C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80801220: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801224: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801228: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080122C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801234: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80801238: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080123C: jal         0x8009328C
    // 0x80801240: nop

    func_8009328C(rdram, ctx);
        goto after_5;
    // 0x80801240: nop

    after_5:
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801248: jal         0x8008DF8C
    // 0x8080124C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x8080124C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801250: beq         $v0, $zero, L_80801268
    if (ctx->r2 == 0) {
        // 0x80801254: lwc1        $f10, 0x34($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80801268;
    }
    // 0x80801254: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801258: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
    // 0x8080125C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801260: jal         0x8080101C
    // 0x80801264: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080101C_bsbansack(rdram, ctx);
        goto after_7;
    // 0x80801264: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_80801268:
    // 0x80801268: b           L_80801304
    // 0x8080126C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801304;
    // 0x8080126C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801270:
    // 0x80801270: jal         0x80085300
    // 0x80801274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_8;
    // 0x80801274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80801278: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080127C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801280: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80801284: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801288: jal         0x800F10B4
    // 0x8080128C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x8080128C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80801290: lwc1        $f16, 0x174($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X174);
    // 0x80801294: lwc1        $f18, 0x170($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80801298: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080129C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808012A0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808012A4: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808012A8: jal         0x80013970
    // 0x808012AC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_80013970(rdram, ctx);
        goto after_10;
    // 0x808012AC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x808012B0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808012B4: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    // 0x808012B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012BC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808012C0: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808012C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808012C8: jal         0x8009328C
    // 0x808012CC: nop

    func_8009328C(rdram, ctx);
        goto after_11;
    // 0x808012CC: nop

    after_11:
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012D4: jal         0x80085300
    // 0x808012D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_12;
    // 0x808012D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808012DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808012E0: nop

    // 0x808012E4: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x808012E8: nop

    // 0x808012EC: bc1t        L_808012FC
    if (c1cs) {
        // 0x808012F0: nop
    
            goto L_808012FC;
    }
    // 0x808012F0: nop

    // 0x808012F4: b           L_80801304
    // 0x808012F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801304;
    // 0x808012F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808012FC:
    // 0x808012FC: b           L_80801304
    // 0x80801300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801304;
    // 0x80801300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801304:
    // 0x80801304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801308: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080130C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801310: jr          $ra
    // 0x80801314: nop

    return;
    // 0x80801314: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801088: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080108C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801090: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801094: jal         0x8008CABC
    // 0x80801098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080109C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808010A0: jal         0x8008AF24
    // 0x808010A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808010A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808010A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808010AC: jal         0x8008AED4
    // 0x808010B0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808010B0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_2:
    // 0x808010B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808010B8: jal         0x8008B134
    // 0x808010BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x808010BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808010C0: lui         $a1, 0x3DB1
    ctx->r5 = S32(0X3DB1 << 16);
    // 0x808010C4: ori         $a1, $a1, 0x26E9
    ctx->r5 = ctx->r5 | 0X26E9;
    // 0x808010C8: jal         0x8008B24C
    // 0x808010CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x808010CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808010D0: jal         0x8008B064
    // 0x808010D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x808010D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x808010D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808010DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808010E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808010E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808010EC: jal         0x8009FFD8
    // 0x808010F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_6;
    // 0x808010F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x808010F4: jal         0x8009C990
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_7;
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808010FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801100: jal         0x8009B9C0
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_8;
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801108: jal         0x8009C990
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_9;
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801110: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801114: jal         0x8009BB00
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080111C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801124: jal         0x8009BA68
    // 0x80801128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80801128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x8080112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801130: jal         0x800A0CF4
    // 0x80801134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_12;
    // 0x80801134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080113C: jal         0x800A0CE8
    // 0x80801140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_13;
    // 0x80801140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801148: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8080114C: jal         0x8009BFE4
    // 0x80801150: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_14;
    // 0x80801150: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_14:
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801158: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8080115C: jal         0x8009C554
    // 0x80801160: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_15;
    // 0x80801160: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_15:
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801168: jal         0x8009B9B0
    // 0x8080116C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x8080116C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x80801170: jal         0x8009D658
    // 0x80801174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_17;
    // 0x80801174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080117C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801180: jal         0x80085338
    // 0x80801184: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_18;
    // 0x80801184: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_18:
    // 0x80801188: jal         0x8080013C
    // 0x8080118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080013C_bsblongleg(rdram, ctx);
        goto after_19;
    // 0x8080118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801194: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801198: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080119C: jr          $ra
    // 0x808011A0: nop

    return;
    // 0x808011A0: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(332, 0XB70) << 16);
    // 0x80800B0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B10: jr          $ra
    // 0x80800B14: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB70));
    return;
    // 0x80800B14: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB70));
;}
RECOMP_FUNC void func_8001E3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E3E8: jal         0x8001211C
    // 0x8001E3EC: nop

    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x8001E3EC: nop

    after_0:
    // 0x8001E3F0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E3F4: addiu       $a0, $a0, 0x18D4
    ctx->r4 = ADD32(ctx->r4, 0X18D4);
    // 0x8001E3F8: jal         0x8001D37C
    // 0x8001E3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8001E400: jal         0x8001E2A0
    // 0x8001E404: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E404: nop

    after_2:
    // 0x8001E408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E40C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E410: jr          $ra
    // 0x8001E414: nop

    return;
    // 0x8001E414: nop

;}
RECOMP_FUNC void func_8001A3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A3A0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001A3A4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x8001A3A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A3AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A3B0: bne         $t6, $zero, L_8001A424
    if (ctx->r14 != 0) {
        // 0x8001A3B4: nop
    
            goto L_8001A424;
    }
    // 0x8001A3B4: nop

    // 0x8001A3B8: jal         0x8001ACCC
    // 0x8001A3BC: lui         $a0, 0x4
    if (tooie_more_memory()) ctx->r4 = S32(0X4 << 16); else ctx->r4 = ADD32(0, 0X76C0);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8001A3BC: lui         $a0, 0x4
    if (tooie_more_memory()) ctx->r4 = S32(0X4 << 16); else ctx->r4 = ADD32(0, 0X76C0);
    after_0:
    // 0x8001A3C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A3C4: sw          $v0, -0x4330($at)
    MEM_W(-0X4330, ctx->r1) = ctx->r2;
    // 0x8001A3C8: jal         0x8001ACCC
    // 0x8001A3CC: lui         $a0, 0x4
    if (tooie_more_memory()) ctx->r4 = S32(0X4 << 16); else ctx->r4 = ADD32(0, 0X76C0);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x8001A3CC: lui         $a0, 0x4
    if (tooie_more_memory()) ctx->r4 = S32(0X4 << 16); else ctx->r4 = ADD32(0, 0X76C0);
    after_1:
    // 0x8001A3D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A3D4: lui         $a0, 0x9
    if (tooie_more_memory()) ctx->r4 = S32(0X9 << 16); else ctx->r4 = S32(0X1 << 16);
    // 0x8001A3D8: sw          $v0, -0x432C($at)
    MEM_W(-0X432C, ctx->r1) = ctx->r2;
    // 0x8001A3DC: jal         0x8001ACCC
    // 0x8001A3E0: ori         $a0, $a0, 0x2C00
    ctx->r4 = ctx->r4 | 0X2C00;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8001A3E0: ori         $a0, $a0, 0x2C00
    ctx->r4 = ctx->r4 | 0X2C00;
    after_2:
    // 0x8001A3E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A3E8: lui         $a0, 0x9
    if (tooie_more_memory()) ctx->r4 = S32(0X9 << 16); else ctx->r4 = S32(0X1 << 16);
    // 0x8001A3EC: sw          $v0, -0x4328($at)
    MEM_W(-0X4328, ctx->r1) = ctx->r2;
    // 0x8001A3F0: jal         0x8001ACCC
    // 0x8001A3F4: ori         $a0, $a0, 0x2C00
    ctx->r4 = ctx->r4 | 0X2C00;
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x8001A3F4: ori         $a0, $a0, 0x2C00
    ctx->r4 = ctx->r4 | 0X2C00;
    after_3:
    // 0x8001A3F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A3FC: sw          $v0, -0x4324($at)
    MEM_W(-0X4324, ctx->r1) = ctx->r2;
    // 0x8001A400: jal         0x8001ACCC
    // 0x8001A404: ori         $a0, $zero, 0xD700
    if (tooie_more_memory()) ctx->r4 = 0 | 0XD700; else ctx->r4 = ADD32(0, 0X1AE0);
    heap_alloc(rdram, ctx);
        goto after_4;
    // 0x8001A404: ori         $a0, $zero, 0xD700
    if (tooie_more_memory()) ctx->r4 = 0 | 0XD700; else ctx->r4 = ADD32(0, 0X1AE0);
    after_4:
    // 0x8001A408: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A40C: sw          $v0, -0x4320($at)
    MEM_W(-0X4320, ctx->r1) = ctx->r2;
    // 0x8001A410: jal         0x8001ACCC
    // 0x8001A414: ori         $a0, $zero, 0xD700
    if (tooie_more_memory()) ctx->r4 = 0 | 0XD700; else ctx->r4 = ADD32(0, 0X1AE0);
    heap_alloc(rdram, ctx);
        goto after_5;
    // 0x8001A414: ori         $a0, $zero, 0xD700
    if (tooie_more_memory()) ctx->r4 = 0 | 0XD700; else ctx->r4 = ADD32(0, 0X1AE0);
    after_5:
    // 0x8001A418: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A41C: jal         0x8001A570
    // 0x8001A420: sw          $v0, -0x431C($at)
    MEM_W(-0X431C, ctx->r1) = ctx->r2;
    func_8001A570(rdram, ctx);
        goto after_6;
    // 0x8001A420: sw          $v0, -0x431C($at)
    MEM_W(-0X431C, ctx->r1) = ctx->r2;
    after_6:
L_8001A424:
    // 0x8001A424: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A428: jal         0x800A9800
    // 0x8001A42C: sh          $zero, -0x4126($at)
    MEM_H(-0X4126, ctx->r1) = 0;
    func_800A9800(rdram, ctx);
        goto after_7;
    // 0x8001A42C: sh          $zero, -0x4126($at)
    MEM_H(-0X4126, ctx->r1) = 0;
    after_7:
    // 0x8001A430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A438: jr          $ra
    // 0x8001A43C: nop

    return;
    // 0x8001A43C: nop

;}
RECOMP_FUNC void func_80800AF4_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800B04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B08: jal         0x8008A4B0
    // 0x80800B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B10: jal         0x80103D70
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D70(rdram, ctx);
        goto after_1;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x80101FDC
    // 0x80800B20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800B20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800B24: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800B28: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80800B2C: sll         $t9, $t7, 18
    ctx->r25 = S32(ctx->r15 << 18);
    // 0x80800B30: bgezl       $t9, L_80800B54
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B34: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800B54;
    }
    goto skip_0;
    // 0x80800B34: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800B38: jal         0x80015178
    // 0x80800B3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80015178(rdram, ctx);
        goto after_3;
    // 0x80800B3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800B40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800B44: lbu         $t0, 0x2A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800B48: andi        $t1, $t0, 0xFFDF
    ctx->r9 = ctx->r8 & 0XFFDF;
    // 0x80800B4C: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80800B50: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800B54:
    // 0x80800B54: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800B58: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x80800B5C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B6C: jr          $ra
    // 0x80800B70: nop

    return;
    // 0x80800B70: nop

;}
RECOMP_FUNC void _baeggsetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A58: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A58);
    return;
    // 0x80084A5C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800967C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800967C0: jr          $ra
    // 0x800967C4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x800967C4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80809334_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80809338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080933C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80809340: jal         0x80807BB8
    // 0x80809344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80809348: jal         0x80808DB0
    // 0x8080934C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080934C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80809350: jal         0x80809900
    // 0x80809354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809900_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80809354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80809358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080935C: jal         0x80800858
    // 0x80809360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800858_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80809360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80809364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80809368: jal         0x80809684
    // 0x8080936C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80809684_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x8080936C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80809370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80809374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80809378: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080937C: jr          $ra
    // 0x80809380: nop

    return;
    // 0x80809380: nop

;}
RECOMP_FUNC void chfactorydrums_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F64: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2252, 0X125C) << 16);
    // 0x80800F68: jr          $ra
    // 0x80800F6C: addiu       $v0, $v0, 0x125C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2252, 0X125C));
    return;
    // 0x80800F6C: addiu       $v0, $v0, 0x125C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2252, 0X125C));
;}
RECOMP_FUNC void _bawandglow_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853D8: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853D8);
    return;
    // 0x800853DC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800F604C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F604C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F6058: jal         0x8009EAD0
    // 0x800F605C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8009EAD0(rdram, ctx);
        goto after_0;
    // 0x800F605C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800F6060: jal         0x80084758
    // 0x800F6064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badata_entrypoint_35(rdram, ctx);
        goto after_1;
    // 0x800F6064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F6068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F606C: jal         0x8009E5C8
    // 0x800F6070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x800F6070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800F6074: jal         0x8009EAD0
    // 0x800F6078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8009EAD0(rdram, ctx);
        goto after_3;
    // 0x800F6078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800F607C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6084: jr          $ra
    // 0x800F6088: nop

    return;
    // 0x800F6088: nop

;}
RECOMP_FUNC void func_8009EA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA24: jr          $ra
    // 0x8009EA28: lbu         $v0, 0x7077($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7077);
    return;
    // 0x8009EA28: lbu         $v0, 0x7077($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7077);
;}
RECOMP_FUNC void func_808000D8_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808000DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E8: lui         $at, 0x43E4
    ctx->r1 = S32(0X43E4 << 16);
    // 0x808000EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000F4: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x808000F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000FC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800100: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800104: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800108: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080010C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80800110: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800114: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800118: jal         0x80089F18
    // 0x8080011C: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080011C: nop

    after_0:
    // 0x80800120: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800124: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800128: bltzl       $t8, L_80800940
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080012C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800940;
    }
    goto skip_0;
    // 0x8080012C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800130: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800134: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800138: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080013C: sltiu       $at, $t1, 0xC
    ctx->r1 = ctx->r9 < 0XC ? 1 : 0;
    // 0x80800140: beq         $at, $zero, L_808008F0
    if (ctx->r1 == 0) {
        // 0x80800144: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808008F0;
    }
    // 0x80800144: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1CC0) << 16);
    // 0x8080014C: addu        $at, $at, $t1
    gpr jr_addend_80800154 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800150: lw          $t1, 0x1CC0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1CC0));
    // 0x80800154: jr          $t1
    // 0x80800158: nop

    switch (jr_addend_80800154 >> 2) {
        case 0: goto L_8080015C; break;
        case 1: goto L_80800198; break;
        case 2: goto L_80800260; break;
        case 3: goto L_80800348; break;
        case 4: goto L_80800368; break;
        case 5: goto L_80800700; break;
        case 6: goto L_8080047C; break;
        case 7: goto L_8080063C; break;
        case 8: goto L_808007A4; break;
        case 9: goto L_8080047C; break;
        case 10: goto L_8080063C; break;
        case 11: goto L_808007A4; break;
        default: switch_error(__func__, 0x80800154, 0x80801CC0);
    }
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800160: jal         0x8010C9B0
    // 0x80800164: addiu       $a1, $zero, 0x1388
    ctx->r5 = ADD32(0, 0X1388);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a1, $zero, 0x1388
    ctx->r5 = ADD32(0, 0X1388);
    after_1:
    // 0x80800168: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x8080016C: nop
    
            goto L_808008F0;
    }
    // 0x8080016C: nop

    // 0x80800170: jal         0x800F54E4
    // 0x80800174: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800174: nop

    after_2:
    // 0x80800178: jal         0x800F6720
    // 0x8080017C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6720(rdram, ctx);
        goto after_3;
    // 0x8080017C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800180: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80800950
    // 0x8080018C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_4;
    // 0x8080018C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800190: b           L_808008F0
    // 0x80800194: nop

        goto L_808008F0;
    // 0x80800194: nop

L_80800198:
    // 0x80800198: jal         0x80101DDC
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001A0: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B0;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x80800950
    // 0x808001AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_6;
    // 0x808001AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_808001B0:
    // 0x808001B0: jal         0x800DA298
    // 0x808001B4: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808001B4: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    after_7:
    // 0x808001B8: bnel        $v0, $zero, L_80800200
    if (ctx->r2 != 0) {
        // 0x808001BC: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_80800200;
    }
    goto skip_1;
    // 0x808001BC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    skip_1:
    // 0x808001C0: jal         0x800D90A4
    // 0x808001C4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x808001C4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x808001C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808001CC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1CF0) << 16);
    // 0x808001D4: lwc1        $f14, 0x1CF0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1CF0));
    // 0x808001D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808001DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001E0: jal         0x800F10B4
    // 0x808001E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x808001E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x808001E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x808001F4: jal         0x808011D0
    // 0x808001F8: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_10;
    // 0x808001F8: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_10:
    // 0x808001FC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
L_80800200:
    // 0x80800200: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800204: jal         0x80101E14
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080020C: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: lui         $a0, 0x8CBB
    ctx->r4 = S32(0X8CBB << 16);
    // 0x80800218: lui         $a2, 0x1B58
    ctx->r6 = S32(0X1B58 << 16);
    // 0x8080021C: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x80800220: ori         $a0, $a0, 0x5C1E
    ctx->r4 = ctx->r4 | 0X5C1E;
    // 0x80800224: jal         0x800C4140
    // 0x80800228: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C4140(rdram, ctx);
        goto after_12;
    // 0x80800228: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x8080022C: b           L_808008F0
    // 0x80800230: nop

        goto L_808008F0;
    // 0x80800230: nop

L_80800234:
    // 0x80800234: jal         0x80101E14
    // 0x80800238: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80800238: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x8080023C: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800240: lui         $a0, 0x7FFB
        ctx->r4 = S32(0X7FFB << 16);
            goto L_808008F0;
    }
    // 0x80800240: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800244: lui         $a2, 0x1B58
    ctx->r6 = S32(0X1B58 << 16);
    // 0x80800248: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x8080024C: ori         $a0, $a0, 0x5C1D
    ctx->r4 = ctx->r4 | 0X5C1D;
    // 0x80800250: jal         0x800C4140
    // 0x80800254: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C4140(rdram, ctx);
        goto after_14;
    // 0x80800254: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x80800258: b           L_808008F0
    // 0x8080025C: nop

        goto L_808008F0;
    // 0x8080025C: nop

L_80800260:
    // 0x80800260: jal         0x800DA298
    // 0x80800264: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800264: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    after_15:
    // 0x80800268: bne         $v0, $zero, L_808002E0
    if (ctx->r2 != 0) {
        // 0x8080026C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808002E0;
    }
    // 0x8080026C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800270: jal         0x800D90A4
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_16;
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_16:
    // 0x80800278: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080027C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2400, 0X1CF4) << 16);
            goto L_80800290;
    }
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1CF4) << 16);
    // 0x80800280: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800284: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80800288: bgez        $t4, L_808002C8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080028C: nop
    
            goto L_808002C8;
    }
    // 0x8080028C: nop

L_80800290:
    // 0x80800290: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800294: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800298: lwc1        $f14, 0x1CF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1CF4));
    // 0x8080029C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808002A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808002A4: jal         0x800F10B4
    // 0x808002A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x808002A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x808002AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x808002B8: jal         0x808011D0
    // 0x808002BC: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_18;
    // 0x808002BC: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_18:
    // 0x808002C0: b           L_808008F0
    // 0x808002C4: nop

        goto L_808008F0;
    // 0x808002C4: nop

L_808002C8:
    // 0x808002C8: jal         0x80801314
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801314_chfantasyeyeball(rdram, ctx);
        goto after_19;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808002D0: jal         0x800DA544
    // 0x808002D4: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    func_800DA544(rdram, ctx);
        goto after_20;
    // 0x808002D4: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    after_20:
    // 0x808002D8: b           L_808008F0
    // 0x808002DC: nop

        goto L_808008F0;
    // 0x808002DC: nop

L_808002E0:
    // 0x808002E0: jal         0x8010C9B0
    // 0x808002E4: addiu       $a1, $zero, 0x1388
    ctx->r5 = ADD32(0, 0X1388);
    func_8010C9B0(rdram, ctx);
        goto after_21;
    // 0x808002E4: addiu       $a1, $zero, 0x1388
    ctx->r5 = ADD32(0, 0X1388);
    after_21:
    // 0x808002E8: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808002EC: nop
    
            goto L_808008F0;
    }
    // 0x808002EC: nop

    // 0x808002F0: jal         0x800F54E4
    // 0x808002F4: nop

    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x808002F4: nop

    after_22:
    // 0x808002F8: jal         0x800F6720
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6720(rdram, ctx);
        goto after_23;
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80800300: bne         $v0, $zero, L_80800318
    if (ctx->r2 != 0) {
        // 0x80800304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800318;
    }
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x80800950
    // 0x8080030C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_24;
    // 0x8080030C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x80800310: b           L_808008F0
    // 0x80800314: nop

        goto L_808008F0;
    // 0x80800314: nop

L_80800318:
    // 0x80800318: jal         0x800D90A4
    // 0x8080031C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_25;
    // 0x8080031C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_25:
    // 0x80800320: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800324: nop
    
            goto L_808008F0;
    }
    // 0x80800324: nop

    // 0x80800328: jal         0x808017B4
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017B4_chfantasyeyeball(rdram, ctx);
        goto after_26;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800330: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80800950
    // 0x8080033C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_27;
    // 0x8080033C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x80800340: b           L_808008F0
    // 0x80800344: nop

        goto L_808008F0;
    // 0x80800344: nop

L_80800348:
    // 0x80800348: jal         0x80101DDC
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_28;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800350: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80800950
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_29;
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800360: b           L_808008F0
    // 0x80800364: nop

        goto L_808008F0;
    // 0x80800364: nop

L_80800368:
    // 0x80800368: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x8080036C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800370: jal         0x80101E14
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800378: beq         $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x8080037C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2400, 0X1CF8) << 16);
            goto L_8080045C;
    }
    // 0x8080037C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1CF8) << 16);
    // 0x80800380: lwc1        $f12, 0x1CF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1CF8));
    // 0x80800384: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800388: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080038C: jal         0x800DC178
    // 0x80800390: nop

    func_800DC178(rdram, ctx);
        goto after_31;
    // 0x80800390: nop

    after_31:
    // 0x80800394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1CFC) << 16);
    // 0x80800398: lwc1        $f4, 0x1CFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1CFC));
    // 0x8080039C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003A0: lui         $a2, 0x1B58
    ctx->r6 = S32(0X1B58 << 16);
    // 0x808003A4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003A8: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x808003AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808003B0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808003B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808003B8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808003BC: nop

    // 0x808003C0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808003C4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808003C8: nop

    // 0x808003CC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003D0: beql        $a0, $zero, L_80800420
    if (ctx->r4 == 0) {
        // 0x808003D4: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80800420;
    }
    goto skip_2;
    // 0x808003D4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x808003D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003E0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808003E4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808003E8: nop

    // 0x808003EC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808003F0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808003F4: nop

    // 0x808003F8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003FC: bne         $a0, $zero, L_80800414
    if (ctx->r4 != 0) {
        // 0x80800400: nop
    
            goto L_80800414;
    }
    // 0x80800400: nop

    // 0x80800404: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080040C: b           L_8080042C
    // 0x80800410: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8080042C;
    // 0x80800410: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800414:
    // 0x80800414: b           L_8080042C
    // 0x80800418: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8080042C;
    // 0x80800418: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080041C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80800420:
    // 0x80800420: nop

    // 0x80800424: bltz        $a0, L_80800414
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800428: nop
    
            goto L_80800414;
    }
    // 0x80800428: nop

L_8080042C:
    // 0x8080042C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800430: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80800434: ori         $at, $at, 0x5E3D
    ctx->r1 = ctx->r1 | 0X5E3D;
    // 0x80800438: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8080043C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800440: jal         0x800C4140
    // 0x80800444: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_32;
    // 0x80800444: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    after_32:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x80108B04
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_33;
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80800454: b           L_808008F0
    // 0x80800458: nop

        goto L_808008F0;
    // 0x80800458: nop

L_8080045C:
    // 0x8080045C: jal         0x80101DDC
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_34;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800464: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x80800468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80800950
    // 0x80800470: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_35;
    // 0x80800470: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_35:
    // 0x80800474: b           L_808008F0
    // 0x80800478: nop

        goto L_808008F0;
    // 0x80800478: nop

L_8080047C:
    // 0x8080047C: jal         0x80101DDC
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_36;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800484: beql        $v0, $zero, L_80800550
    if (ctx->r2 == 0) {
        // 0x80800488: lw          $t8, 0x64($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X64);
            goto L_80800550;
    }
    goto skip_3;
    // 0x80800488: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    skip_3:
    // 0x8080048C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800490: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800494: bgezl       $t0, L_80800528
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800498: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80800528;
    }
    goto skip_4;
    // 0x80800498: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_4:
    // 0x8080049C: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: beq         $t1, $zero, L_808004DC
    if (ctx->r9 == 0) {
        // 0x808004A8: nop
    
            goto L_808004DC;
    }
    // 0x808004A8: nop

    // 0x808004AC: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x808004B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808004B4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808004B8: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x808004BC: bne         $t3, $at, L_808004CC
    if (ctx->r11 != ctx->r1) {
        // 0x808004C0: nop
    
            goto L_808004CC;
    }
    // 0x808004C0: nop

    // 0x808004C4: b           L_808004CC
    // 0x808004C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_808004CC;
    // 0x808004C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_808004CC:
    // 0x808004CC: jal         0x80800950
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_37;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808004D4: b           L_80800550
    // 0x808004D8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
        goto L_80800550;
    // 0x808004D8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_808004DC:
    // 0x808004DC: jal         0x80100094
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_38;
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x808004E4: jal         0x8008A040
    // 0x808004E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_39;
    // 0x808004E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_39:
    // 0x808004EC: jal         0x8010A590
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010A590(rdram, ctx);
        goto after_40;
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_40:
    // 0x808004F4: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x808004F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808004FC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800500: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x80800504: bne         $t5, $at, L_80800514
    if (ctx->r13 != ctx->r1) {
        // 0x80800508: nop
    
            goto L_80800514;
    }
    // 0x80800508: nop

    // 0x8080050C: b           L_80800514
    // 0x80800510: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800514;
    // 0x80800510: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800514:
    // 0x80800514: jal         0x80800950
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_41;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8080051C: b           L_80800550
    // 0x80800520: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
        goto L_80800550;
    // 0x80800520: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800524: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800528:
    // 0x80800528: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080052C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800530: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800534: bne         $t7, $at, L_80800544
    if (ctx->r15 != ctx->r1) {
        // 0x80800538: nop
    
            goto L_80800544;
    }
    // 0x80800538: nop

    // 0x8080053C: b           L_80800544
    // 0x80800540: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800544;
    // 0x80800540: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800544:
    // 0x80800544: jal         0x80800950
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_42;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080054C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_80800550:
    // 0x80800550: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800554: bgezl       $t0, L_8080059C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800558: lui         $a1, 0x3EB3
        ctx->r5 = S32(0X3EB3 << 16);
            goto L_8080059C;
    }
    goto skip_5;
    // 0x80800558: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    skip_5:
    // 0x8080055C: jal         0x800D90A4
    // 0x80800560: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_43;
    // 0x80800560: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_43:
    // 0x80800564: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800568: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080056C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1D00) << 16);
    // 0x80800570: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800574: lwc1        $f14, 0x1D00($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1D00));
    // 0x80800578: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080057C: jal         0x800F10B4
    // 0x80800580: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_44;
    // 0x80800580: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_44:
    // 0x80800584: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80800590: jal         0x808011D0
    // 0x80800594: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_45;
    // 0x80800594: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_45:
    // 0x80800598: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
L_8080059C:
    // 0x8080059C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808005A0: jal         0x80101E14
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_46;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808005A8: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808005AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x80801740
    // 0x808005B4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80801740_chfantasyeyeball(rdram, ctx);
        goto after_47;
    // 0x808005B4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_47:
    // 0x808005B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808005BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_808005C0:
    // 0x808005C0: jal         0x800B53A4
    // 0x808005C4: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_800B53A4(rdram, ctx);
        goto after_48;
    // 0x808005C4: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_48:
    // 0x808005C8: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x808005CC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808005D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D4: jal         0x800BA3FC
    // 0x808005D8: addiu       $a1, $v1, 0x9DF
    ctx->r5 = ADD32(ctx->r3, 0X9DF);
    func_800BA3FC(rdram, ctx);
        goto after_49;
    // 0x808005D8: addiu       $a1, $v1, 0x9DF
    ctx->r5 = ADD32(ctx->r3, 0X9DF);
    after_49:
    // 0x808005DC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2400, 0X1EEC) << 16);
    // 0x808005E0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808005E4: addiu       $t1, $t1, 0x1EEC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2400, 0X1EEC));
    // 0x808005E8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808005EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808005F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808005F4: jal         0x800BABB8
    // 0x808005F8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    func_800BABB8(rdram, ctx);
        goto after_50;
    // 0x808005F8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_50:
    // 0x808005FC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80800600: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800604: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800608: bnel        $v1, $at, L_808005C0
    if (ctx->r3 != ctx->r1) {
        // 0x8080060C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_808005C0;
    }
    goto skip_6;
    // 0x8080060C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    skip_6:
    // 0x80800610: lui         $a0, 0xBFDB
    ctx->r4 = S32(0XBFDB << 16);
    // 0x80800614: lui         $a2, 0x1B58
    ctx->r6 = S32(0X1B58 << 16);
    // 0x80800618: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x8080061C: ori         $a0, $a0, 0x5C13
    ctx->r4 = ctx->r4 | 0X5C13;
    // 0x80800620: jal         0x800C4140
    // 0x80800624: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C4140(rdram, ctx);
        goto after_51;
    // 0x80800624: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_51:
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x80108B04
    // 0x80800630: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_52;
    // 0x80800630: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_52:
    // 0x80800634: b           L_808008F0
    // 0x80800638: nop

        goto L_808008F0;
    // 0x80800638: nop

L_8080063C:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x80100094
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_53;
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x80800648: jal         0x8008A040
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_54;
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_54:
    // 0x80800650: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800654: jal         0x800D90A4
    // 0x80800658: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_55;
    // 0x80800658: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_55:
    // 0x8080065C: beq         $v0, $zero, L_80800694
    if (ctx->r2 == 0) {
        // 0x80800660: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2400, 0X1D04) << 16);
            goto L_80800694;
    }
    // 0x80800660: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1D04) << 16);
    // 0x80800664: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x80800668: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080066C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800670: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800674: bne         $t3, $at, L_80800684
    if (ctx->r11 != ctx->r1) {
        // 0x80800678: nop
    
            goto L_80800684;
    }
    // 0x80800678: nop

    // 0x8080067C: b           L_80800684
    // 0x80800680: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800684;
    // 0x80800680: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800684:
    // 0x80800684: jal         0x80800950
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_56;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x8080068C: b           L_808006C8
    // 0x80800690: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_808006C8;
    // 0x80800690: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800694:
    // 0x80800694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800698: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080069C: lwc1        $f14, 0x1D04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1D04));
    // 0x808006A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808006A8: jal         0x800F10B4
    // 0x808006AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_57;
    // 0x808006AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_57:
    // 0x808006B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x808006BC: jal         0x808011D0
    // 0x808006C0: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_58;
    // 0x808006C0: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_58:
    // 0x808006C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808006C8:
    // 0x808006C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808006CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006D0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808006D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006D8: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x808006DC: jal         0x800F10B4
    // 0x808006E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_59;
    // 0x808006E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_59:
    // 0x808006E4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808006E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808006EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808006F0: jal         0x80089C98
    // 0x808006F4: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_60;
    // 0x808006F4: nop

    after_60:
    // 0x808006F8: b           L_808008F0
    // 0x808006FC: nop

        goto L_808008F0;
    // 0x808006FC: nop

L_80800700:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x80100094
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_61;
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_61:
    // 0x8080070C: jal         0x8008A040
    // 0x80800710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_62;
    // 0x80800710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_62:
    // 0x80800714: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800718: jal         0x800D90A4
    // 0x8080071C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_63;
    // 0x8080071C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_63:
    // 0x80800720: beql        $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800724: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800740;
    }
    goto skip_7;
    // 0x80800724: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_7:
    // 0x80800728: jal         0x80801314
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801314_chfantasyeyeball(rdram, ctx);
        goto after_64;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80800950
    // 0x80800738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_65;
    // 0x80800738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_65:
    // 0x8080073C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800740:
    // 0x80800740: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800744: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800748: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080074C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800750: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800754: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800758: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080075C: jal         0x800F10B4
    // 0x80800760: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_66;
    // 0x80800760: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_66:
    // 0x80800764: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800768: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080076C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800770: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800774: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800778: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080077C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800780: jal         0x80089C98
    // 0x80800784: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_67;
    // 0x80800784: nop

    after_67:
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800790: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x80800794: jal         0x808011D0
    // 0x80800798: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_68;
    // 0x80800798: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_68:
    // 0x8080079C: b           L_808008F0
    // 0x808007A0: nop

        goto L_808008F0;
    // 0x808007A0: nop

L_808007A4:
    // 0x808007A4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808007A8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808007AC: bgez        $t8, L_80800830
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808007B0: nop
    
            goto L_80800830;
    }
    // 0x808007B0: nop

    // 0x808007B4: jal         0x800D90A4
    // 0x808007B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_69;
    // 0x808007B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_69:
    // 0x808007BC: jal         0x800D90A4
    // 0x808007C0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_70;
    // 0x808007C0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_70:
    // 0x808007C4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808007C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1D08) << 16);
    // 0x808007CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808007D0: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808007D4: bltzl       $t1, L_80800800
    if (SIGNED(ctx->r9) < 0) {
        // 0x808007D8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800800;
    }
    goto skip_8;
    // 0x808007D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_8:
    // 0x808007DC: jal         0x80801314
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801314_chfantasyeyeball(rdram, ctx);
        goto after_71;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x808007E4: jal         0x800FC6B0
    // 0x808007E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800FC6B0(rdram, ctx);
        goto after_72;
    // 0x808007E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_72:
    // 0x808007EC: jal         0x800FFA88
    // 0x808007F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_73;
    // 0x808007F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_73:
    // 0x808007F4: b           L_80800940
    // 0x808007F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800940;
    // 0x808007F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800800:
    // 0x80800800: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800804: lwc1        $f14, 0x1D08($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1D08));
    // 0x80800808: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080080C: jal         0x800F10B4
    // 0x80800810: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_74;
    // 0x80800810: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_74:
    // 0x80800814: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80800820: jal         0x808011D0
    // 0x80800824: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    func_808011D0_chfantasyeyeball(rdram, ctx);
        goto after_75;
    // 0x80800824: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_75:
    // 0x80800828: b           L_8080084C
    // 0x8080082C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_8080084C;
    // 0x8080082C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800830:
    // 0x80800830: jal         0x800D90A4
    // 0x80800834: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_76;
    // 0x80800834: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_76:
    // 0x80800838: beql        $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x8080083C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8080084C;
    }
    goto skip_9;
    // 0x8080083C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_9:
    // 0x80800840: jal         0x800FFA88
    // 0x80800844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_77;
    // 0x80800844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_77:
    // 0x80800848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8080084C:
    // 0x8080084C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800850: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800854: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800858: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080085C: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800860: jal         0x800F10B4
    // 0x80800864: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_78;
    // 0x80800864: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_78:
    // 0x80800868: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8080086C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800870: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800874: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800878: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8080087C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800880: nop

    // 0x80800884: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80800888: beql        $t3, $zero, L_808008D8
    if (ctx->r11 == 0) {
        // 0x8080088C: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_808008D8;
    }
    goto skip_10;
    // 0x8080088C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x80800890: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800894: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800898: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8080089C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808008A0: nop

    // 0x808008A4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808008A8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808008AC: nop

    // 0x808008B0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x808008B4: bne         $t3, $zero, L_808008CC
    if (ctx->r11 != 0) {
        // 0x808008B8: nop
    
            goto L_808008CC;
    }
    // 0x808008B8: nop

    // 0x808008BC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x808008C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808008C4: b           L_808008E4
    // 0x808008C8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_808008E4;
    // 0x808008C8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_808008CC:
    // 0x808008CC: b           L_808008E4
    // 0x808008D0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_808008E4;
    // 0x808008D0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808008D4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_808008D8:
    // 0x808008D8: nop

    // 0x808008DC: bltz        $t3, L_808008CC
    if (SIGNED(ctx->r11) < 0) {
        // 0x808008E0: nop
    
            goto L_808008CC;
    }
    // 0x808008E0: nop

L_808008E4:
    // 0x808008E4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808008E8: sb          $t3, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r11;
    // 0x808008EC: nop

L_808008F0:
    // 0x808008F0: jal         0x808013F8
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013F8_chfantasyeyeball(rdram, ctx);
        goto after_79;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800900: jal         0x8010C93C
    // 0x80800904: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_8010C93C(rdram, ctx);
        goto after_80;
    // 0x80800904: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_80:
    // 0x80800908: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080090C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800910: srl         $t4, $v0, 10
    ctx->r12 = S32(U32(ctx->r2) >> 10);
    // 0x80800914: beq         $t4, $at, L_8080093C
    if (ctx->r12 == ctx->r1) {
        // 0x80800918: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8080093C;
    }
    // 0x80800918: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080091C: beql        $t4, $at, L_80800940
    if (ctx->r12 == ctx->r1) {
        // 0x80800920: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800940;
    }
    goto skip_11;
    // 0x80800920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80800924: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80800928: sll         $t7, $t5, 11
    ctx->r15 = S32(ctx->r13 << 11);
    // 0x8080092C: bgezl       $t7, L_80800940
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800930: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800940;
    }
    goto skip_12;
    // 0x80800930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80800934: jal         0x80801378
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801378_chfantasyeyeball(rdram, ctx);
        goto after_81;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
L_8080093C:
    // 0x8080093C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800940:
    // 0x80800940: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800944: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800948: jr          $ra
    // 0x8080094C: nop

    return;
    // 0x8080094C: nop

;}
RECOMP_FUNC void func_800D9330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9330: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D9334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9338: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D933C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D9340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D9344: jal         0x800F5898
    // 0x800D9348: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x800D9348: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x800D934C: blezl       $v0, L_800D9384
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D9350: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D9384;
    }
    goto skip_0;
    // 0x800D9350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800D9354:
    // 0x800D9354: jal         0x800F6BE4
    // 0x800D9358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x800D9358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D935C: beq         $v0, $zero, L_800D936C
    if (ctx->r2 == 0) {
        // 0x800D9360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D936C;
    }
    // 0x800D9360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9364: jal         0x800F78C8
    // 0x800D9368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F78C8(rdram, ctx);
        goto after_2;
    // 0x800D9368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_800D936C:
    // 0x800D936C: jal         0x800F5898
    // 0x800D9370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_3;
    // 0x800D9370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x800D9374: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D9378: bne         $at, $zero, L_800D9354
    if (ctx->r1 != 0) {
        // 0x800D937C: nop
    
            goto L_800D9354;
    }
    // 0x800D937C: nop

    // 0x800D9380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D9384:
    // 0x800D9384: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D9388: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D938C: jr          $ra
    // 0x800D9390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D9390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D9394: nop

    // 0x800D9398: nop

    // 0x800D939C: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080056C: jal         0x8009E6C4
    // 0x80800570: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x80800570: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80800574: bne         $v0, $zero, L_80800680
    if (ctx->r2 != 0) {
        // 0x80800578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800680;
    }
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x800844A8
    // 0x80800580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bababykaz_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8080058C: jal         0x800A106C
    // 0x80800590: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800A106C(rdram, ctx);
        goto after_2;
    // 0x80800590: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_2:
    // 0x80800594: jal         0x8009EFA8
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_3;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080059C: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x808005A0: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x8009F1C8
    // 0x808005AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x808005AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005B8: jal         0x8009F1C8
    // 0x808005BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x808005BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x808005C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(68, 0X1720) << 16);
    // 0x808005C4: lwc1        $f0, 0x1720($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X1720));
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: jal         0x800A4D6C
    // 0x808005D8: nop

    func_800A4D6C(rdram, ctx);
        goto after_6;
    // 0x808005D8: nop

    after_6:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x808005E4: jal         0x800959C8
    // 0x808005E8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_800959C8(rdram, ctx);
        goto after_7;
    // 0x808005E8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x8009590C
    // 0x808005F4: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    func_8009590C(rdram, ctx);
        goto after_8;
    // 0x808005F4: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    after_8:
    // 0x808005F8: jal         0x8009E4AC
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_9;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800608: jal         0x8009E55C
    // 0x8080060C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_10;
    // 0x8080060C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_10:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800618: jal         0x8009E53C
    // 0x8080061C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_11;
    // 0x8080061C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800628: jal         0x8009E55C
    // 0x8080062C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_12;
    // 0x8080062C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_12:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x800844C0
    // 0x80800638: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    _bababykaz_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800638: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_13:
    // 0x8080063C: jal         0x800844A0
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080064C: jal         0x800947EC
    // 0x80800650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_15;
    // 0x80800650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800654: jal         0x80800050
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800050_bsbabykaz(rdram, ctx);
        goto after_16;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080065C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800660: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800664: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    // 0x80800668: ori         $a1, $a1, 0x9800
    ctx->r5 = ctx->r5 | 0X9800;
    // 0x8080066C: jal         0x80092864
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_17;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x80095A74
    // 0x8080067C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095A74(rdram, ctx);
        goto after_18;
    // 0x8080067C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
L_80800680:
    // 0x80800680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800688: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
RECOMP_FUNC void func_800DDC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDC28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800DDC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDC30: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800DDC34: lh          $t6, 0x14($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X14);
    // 0x800DDC38: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DDC3C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800DDC40: beq         $t6, $zero, L_800DDD04
    if (ctx->r14 == 0) {
        // 0x800DDC44: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800DDD04;
    }
    // 0x800DDC44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DDC48: lwc1        $f0, -0x36B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X36B8);
    // 0x800DDC4C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x800DDC50: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800DDC54: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DDC58: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x800DDC5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800DDC60: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800DDC64: nop

    // 0x800DDC68: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DDC6C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DDC70: beql        $v0, $a1, L_800DDCBC
    if (ctx->r2 == ctx->r5) {
        // 0x800DDC74: swc1        $f18, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
            goto L_800DDCBC;
    }
    goto skip_0;
    // 0x800DDC74: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    skip_0:
    // 0x800DDC78: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_800DDC7C:
    // 0x800DDC7C: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x800DDC80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800DDC84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800DDC88: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800DDC8C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800DDC90: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DDC94: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DDC98: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x800DDC9C: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x800DDCA0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800DDCA4: nop

    // 0x800DDCA8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DDCAC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DDCB0: bnel        $v0, $a1, L_800DDC7C
    if (ctx->r2 != ctx->r5) {
        // 0x800DDCB4: swc1        $f18, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
            goto L_800DDC7C;
    }
    goto skip_1;
    // 0x800DDCB4: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    skip_1:
    // 0x800DDCB8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_800DDCBC:
    // 0x800DDCBC: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x800DDCC0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800DDCC4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800DDCC8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800DDCCC: nop

    // 0x800DDCD0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DDCD4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DDCD8: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800DDCDC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800DDCE0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800DDCE4: jal         0x800E3D0C
    // 0x800DDCE8: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    func_800E3D0C(rdram, ctx);
        goto after_0;
    // 0x800DDCE8: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DDCEC: beq         $v0, $zero, L_800DDD04
    if (ctx->r2 == 0) {
        // 0x800DDCF0: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_800DDD04;
    }
    // 0x800DDCF0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800DDCF4: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800DDCF8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800DDCFC: jal         0x800DE2A4
    // 0x800DDD00: addu        $a1, $a2, $t9
    ctx->r5 = ADD32(ctx->r6, ctx->r25);
    func_800DE2A4(rdram, ctx);
        goto after_1;
    // 0x800DDD00: addu        $a1, $a2, $t9
    ctx->r5 = ADD32(ctx->r6, ctx->r25);
    after_1:
L_800DDD04:
    // 0x800DDD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDD08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800DDD0C: jr          $ra
    // 0x800DDD10: nop

    return;
    // 0x800DDD10: nop

;}
RECOMP_FUNC void _chproplighter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086538: syscall     335
    recomp_syscall_handler(rdram, ctx, 0x80086538);
    return;
    // 0x8008653C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void baduo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: jr          $ra
    // 0x808000C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800C0A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A2C: jr          $ra
    // 0x800C0A30: nop

    return;
    // 0x800C0A30: nop

;}
RECOMP_FUNC void func_80801ABC_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801AC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801AC8: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801ACC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1008, 0X1D98) << 16);
    // 0x80801AD0: addiu       $t7, $t7, 0x1D98
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1008, 0X1D98));
    // 0x80801AD4: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801AD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801ADC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801AE4: jal         0x800BBCB8
    // 0x80801AE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801AE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80801AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801AF4: jr          $ra
    // 0x80801AF8: nop

    return;
    // 0x80801AF8: nop

;}
RECOMP_FUNC void func_808002CC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002E0: jal         0x8008D04C
    // 0x808002E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x808002E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002EC: jal         0x8008AF24
    // 0x808002F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808002F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: jal         0x8008AED4
    // 0x808002FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808002FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x8008B1BC
    // 0x80800308: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800308: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x8008B24C
    // 0x80800314: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80800314: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x8008B134
    // 0x80800320: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800320: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800324: jal         0x8008B064
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800338: jr          $ra
    // 0x8080033C: nop

    return;
    // 0x8080033C: nop

;}
RECOMP_FUNC void func_800E659C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E659C: addiu       $sp, $sp, -0x4C8
    ctx->r29 = ADD32(ctx->r29, -0X4C8);
    // 0x800E65A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E65A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E65A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E65AC: addiu       $a0, $sp, 0x274
    ctx->r4 = ADD32(ctx->r29, 0X274);
    // 0x800E65B0: addiu       $v0, $sp, 0x34
    ctx->r2 = ADD32(ctx->r29, 0X34);
    // 0x800E65B4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800E65B8:
    // 0x800E65B8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800E65BC: sw          $v1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r3;
    // 0x800E65C0: sw          $v1, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r3;
    // 0x800E65C4: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800E65C8: bne         $v0, $a0, L_800E65B8
    if (ctx->r2 != ctx->r4) {
        // 0x800E65CC: sw          $v1, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r3;
            goto L_800E65B8;
    }
    // 0x800E65CC: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
    // 0x800E65D0: addiu       $t6, $sp, 0x434
    ctx->r14 = ADD32(ctx->r29, 0X434);
    // 0x800E65D4: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800E65D8: beq         $at, $zero, L_800E65F8
    if (ctx->r1 == 0) {
        // 0x800E65DC: addiu       $t7, $sp, 0x494
        ctx->r15 = ADD32(ctx->r29, 0X494);
            goto L_800E65F8;
    }
    // 0x800E65DC: addiu       $t7, $sp, 0x494
    ctx->r15 = ADD32(ctx->r29, 0X494);
    // 0x800E65E0: addiu       $a1, $sp, 0x434
    ctx->r5 = ADD32(ctx->r29, 0X434);
    // 0x800E65E4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800E65E8:
    // 0x800E65E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E65EC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800E65F0: bne         $at, $zero, L_800E65E8
    if (ctx->r1 != 0) {
        // 0x800E65F4: sw          $a0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r4;
            goto L_800E65E8;
    }
    // 0x800E65F4: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
L_800E65F8:
    // 0x800E65F8: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x800E65FC: beq         $at, $zero, L_800E661C
    if (ctx->r1 == 0) {
        // 0x800E6600: addiu       $t8, $sp, 0x4B4
        ctx->r24 = ADD32(ctx->r29, 0X4B4);
            goto L_800E661C;
    }
    // 0x800E6600: addiu       $t8, $sp, 0x4B4
    ctx->r24 = ADD32(ctx->r29, 0X4B4);
    // 0x800E6604: addiu       $a1, $sp, 0x494
    ctx->r5 = ADD32(ctx->r29, 0X494);
    // 0x800E6608: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
L_800E660C:
    // 0x800E660C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E6610: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800E6614: bne         $at, $zero, L_800E660C
    if (ctx->r1 != 0) {
        // 0x800E6618: sw          $a0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r4;
            goto L_800E660C;
    }
    // 0x800E6618: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
L_800E661C:
    // 0x800E661C: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800E6620: beq         $at, $zero, L_800E663C
    if (ctx->r1 == 0) {
        // 0x800E6624: addiu       $t9, $zero, 0x7
        ctx->r25 = ADD32(0, 0X7);
            goto L_800E663C;
    }
    // 0x800E6624: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800E6628: addiu       $a0, $sp, 0x4B4
    ctx->r4 = ADD32(ctx->r29, 0X4B4);
L_800E662C:
    // 0x800E662C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E6630: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800E6634: bne         $at, $zero, L_800E662C
    if (ctx->r1 != 0) {
        // 0x800E6638: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800E662C;
    }
    // 0x800E6638: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
L_800E663C:
    // 0x800E663C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E6640: addiu       $t0, $t0, 0x3244
    ctx->r8 = ADD32(ctx->r8, 0X3244);
    // 0x800E6644: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E6648: addiu       $t1, $sp, 0x4C0
    ctx->r9 = ADD32(ctx->r29, 0X4C0);
    // 0x800E664C: addiu       $t2, $sp, 0x4B8
    ctx->r10 = ADD32(ctx->r29, 0X4B8);
    // 0x800E6650: sw          $t9, 0x4B8($sp)
    MEM_W(0X4B8, ctx->r29) = ctx->r25;
    // 0x800E6654: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800E6658: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800E665C: addiu       $a3, $a3, 0x3204
    ctx->r7 = ADD32(ctx->r7, 0X3204);
    // 0x800E6660: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800E6664: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800E6668: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x800E666C: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800E6670: jal         0x800E589C
    // 0x800E6674: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800E589C(rdram, ctx);
        goto after_0;
    // 0x800E6674: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x800E6678: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800E667C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800E6680: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800E6684: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800E6688: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x800E668C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800E6690: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800E6694:
    // 0x800E6694: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800E6698: sw          $v1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r3;
    // 0x800E669C: sw          $v1, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r3;
    // 0x800E66A0: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800E66A4: bne         $v0, $a0, L_800E6694
    if (ctx->r2 != ctx->r4) {
        // 0x800E66A8: sw          $v1, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r3;
            goto L_800E6694;
    }
    // 0x800E66A8: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
    // 0x800E66AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800E66B0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800E66B4: addiu       $t6, $t6, 0x32A0
    ctx->r14 = ADD32(ctx->r14, 0X32A0);
    // 0x800E66B8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E66BC: addiu       $t7, $sp, 0x4BC
    ctx->r15 = ADD32(ctx->r29, 0X4BC);
    // 0x800E66C0: addiu       $t8, $sp, 0x4B4
    ctx->r24 = ADD32(ctx->r29, 0X4B4);
    // 0x800E66C4: sw          $t5, 0x4B4($sp)
    MEM_W(0X4B4, ctx->r29) = ctx->r13;
    // 0x800E66C8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800E66CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E66D0: addiu       $a3, $a3, 0x3264
    ctx->r7 = ADD32(ctx->r7, 0X3264);
    // 0x800E66D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800E66D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800E66DC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800E66E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E66E4: jal         0x800E589C
    // 0x800E66E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800E589C(rdram, ctx);
        goto after_1;
    // 0x800E66E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_1:
    // 0x800E66EC: lw          $t9, 0x4B8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4B8);
    // 0x800E66F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E66F4: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x800E66F8: lw          $t0, 0x4B4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4B4);
    // 0x800E66FC: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x800E6700: lw          $t1, 0x4C0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C0);
    // 0x800E6704: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x800E6708: lw          $t2, 0x4BC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4BC);
    // 0x800E670C: jal         0x800E5390
    // 0x800E6710: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    func_800E5390(rdram, ctx);
        goto after_2;
    // 0x800E6710: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    after_2:
    // 0x800E6714: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E6718: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E671C: addiu       $sp, $sp, 0x4C8
    ctx->r29 = ADD32(ctx->r29, 0X4C8);
    // 0x800E6720: jr          $ra
    // 0x800E6724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E6724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80806D90_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806D98: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80806D9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806DA0: jal         0x8009E6EC
    // 0x80806DA4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80806DA4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80806DA8: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80806DAC: bne         $v0, $at, L_80806DE0
    if (ctx->r2 != ctx->r1) {
        // 0x80806DB0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80806DE0;
    }
    // 0x80806DB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806DB4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80806DB8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80806DBC: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    // 0x80806DC0: sw          $t7, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->r15;
    // 0x80806DC4: jal         0x8009E5C8
    // 0x80806DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80806DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80806DCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806DD0: jal         0x8009E830
    // 0x80806DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80806DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80806DD8: b           L_80806DEC
    // 0x80806DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80806DEC;
    // 0x80806DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806DE0:
    // 0x80806DE0: jal         0x80805994
    // 0x80806DE4: nop

    bsfirstp_entrypoint_26(rdram, ctx);
        goto after_3;
    // 0x80806DE4: nop

    after_3:
    // 0x80806DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806DEC:
    // 0x80806DEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806DF0: jr          $ra
    // 0x80806DF4: nop

    return;
    // 0x80806DF4: nop

;}
RECOMP_FUNC void chlagoonufoint_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080139C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808013A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808013A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808013AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808013B0: jal         0x80106790
    // 0x808013B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808013B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808013B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1924) << 16);
    // 0x808013BC: lwc1        $f6, 0x1924($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1924));
    // 0x808013C0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x808013C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808013C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808013CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808013D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1928) << 16);
    // 0x808013D4: lwc1        $f10, 0x1928($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1928));
    // 0x808013D8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808013DC: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x808013E0: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x808013E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808013E8: beq         $at, $zero, L_80801604
    if (ctx->r1 == 0) {
        // 0x808013EC: add.s       $f0, $f8, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_80801604;
    }
    // 0x808013EC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
L_808013F0:
    // 0x808013F0: lbu         $t8, 0xC($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC);
    // 0x808013F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808013F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808013FC: bgez        $t8, L_80801410
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801400: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80801410;
    }
    // 0x80801400: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801408: nop

    // 0x8080140C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80801410:
    // 0x80801410: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801414: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801418: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080141C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80801420: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801424: nop

    // 0x80801428: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080142C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801430: nop

    // 0x80801434: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80801438: beql        $t0, $zero, L_80801488
    if (ctx->r8 == 0) {
        // 0x8080143C: mfc1        $t0, $f8
        ctx->r8 = (int32_t)ctx->f8.u32l;
            goto L_80801488;
    }
    goto skip_0;
    // 0x8080143C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80801440: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801444: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801448: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080144C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801450: nop

    // 0x80801454: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801458: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080145C: nop

    // 0x80801460: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80801464: bne         $t0, $zero, L_8080147C
    if (ctx->r8 != 0) {
        // 0x80801468: nop
    
            goto L_8080147C;
    }
    // 0x80801468: nop

    // 0x8080146C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80801470: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801474: b           L_80801494
    // 0x80801478: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80801494;
    // 0x80801478: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8080147C:
    // 0x8080147C: b           L_80801494
    // 0x80801480: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80801494;
    // 0x80801480: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801484: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
L_80801488:
    // 0x80801488: nop

    // 0x8080148C: bltz        $t0, L_8080147C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80801490: nop
    
            goto L_8080147C;
    }
    // 0x80801490: nop

L_80801494:
    // 0x80801494: sb          $t0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r8;
    // 0x80801498: lbu         $t1, 0xD($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XD);
    // 0x8080149C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808014A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808014A4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808014A8: bgez        $t1, L_808014BC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808014AC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808014BC;
    }
    // 0x808014AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808014B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014B4: nop

    // 0x808014B8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_808014BC:
    // 0x808014BC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808014C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808014C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808014C8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808014CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808014D0: nop

    // 0x808014D4: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808014D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808014DC: nop

    // 0x808014E0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x808014E4: beql        $t3, $zero, L_80801534
    if (ctx->r11 == 0) {
        // 0x808014E8: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_80801534;
    }
    goto skip_1;
    // 0x808014E8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x808014EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808014F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808014F4: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808014F8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808014FC: nop

    // 0x80801500: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801504: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80801508: nop

    // 0x8080150C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80801510: bne         $t3, $zero, L_80801528
    if (ctx->r11 != 0) {
        // 0x80801514: nop
    
            goto L_80801528;
    }
    // 0x80801514: nop

    // 0x80801518: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8080151C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801520: b           L_80801540
    // 0x80801524: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80801540;
    // 0x80801524: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80801528:
    // 0x80801528: b           L_80801540
    // 0x8080152C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80801540;
    // 0x8080152C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801530: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_80801534:
    // 0x80801534: nop

    // 0x80801538: bltz        $t3, L_80801528
    if (SIGNED(ctx->r11) < 0) {
        // 0x8080153C: nop
    
            goto L_80801528;
    }
    // 0x8080153C: nop

L_80801540:
    // 0x80801540: sb          $t3, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r11;
    // 0x80801544: lbu         $t4, 0xE($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XE);
    // 0x80801548: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8080154C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80801550: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80801554: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801558: bgez        $t4, L_8080156C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080155C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8080156C;
    }
    // 0x8080155C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801564: nop

    // 0x80801568: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8080156C:
    // 0x8080156C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801570: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801574: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801578: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8080157C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801580: nop

    // 0x80801584: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801588: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8080158C: nop

    // 0x80801590: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80801594: beql        $t6, $zero, L_808015E4
    if (ctx->r14 == 0) {
        // 0x80801598: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_808015E4;
    }
    goto skip_2;
    // 0x80801598: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x8080159C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808015A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808015A4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808015A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808015AC: nop

    // 0x808015B0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808015B4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808015B8: nop

    // 0x808015BC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x808015C0: bne         $t6, $zero, L_808015D8
    if (ctx->r14 != 0) {
        // 0x808015C4: nop
    
            goto L_808015D8;
    }
    // 0x808015C4: nop

    // 0x808015C8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x808015CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808015D0: b           L_808015F0
    // 0x808015D4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_808015F0;
    // 0x808015D4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_808015D8:
    // 0x808015D8: b           L_808015F0
    // 0x808015DC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_808015F0;
    // 0x808015DC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808015E0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_808015E4:
    // 0x808015E4: nop

    // 0x808015E8: bltz        $t6, L_808015D8
    if (SIGNED(ctx->r14) < 0) {
        // 0x808015EC: nop
    
            goto L_808015D8;
    }
    // 0x808015EC: nop

L_808015F0:
    // 0x808015F0: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x808015F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808015F8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808015FC: bne         $at, $zero, L_808013F0
    if (ctx->r1 != 0) {
        // 0x80801600: sb          $t6, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r14;
            goto L_808013F0;
    }
    // 0x80801600: sb          $t6, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r14;
L_80801604:
    // 0x80801604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080160C: jr          $ra
    // 0x80801610: nop

    return;
    // 0x80801610: nop

;}
RECOMP_FUNC void func_8002A310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A310: jr          $ra
    // 0x8002A314: nop

    return;
    // 0x8002A314: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085600: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085600);
    return;
    // 0x80085604: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bsbanbflip_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003B4: jal         0x8008CABC
    // 0x808003B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808003BC: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x808003C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808003C4: ori         $a1, $a1, 0x2546
    ctx->r5 = ctx->r5 | 0X2546;
    // 0x808003C8: jal         0x8008B348
    // 0x808003CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x808003CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003D0: beql        $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x808003D4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800418;
    }
    goto skip_0;
    // 0x808003D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808003D8: jal         0x8008B284
    // 0x808003DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_getPlaybackType(rdram, ctx);
        goto after_2;
    // 0x808003DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808003E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003E4: beql        $v0, $at, L_80800418
    if (ctx->r2 == ctx->r1) {
        // 0x808003E8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800418;
    }
    goto skip_1;
    // 0x808003E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x808003EC: jal         0x8008B264
    // 0x808003F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_getIndex(rdram, ctx);
        goto after_3;
    // 0x808003F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808003F4: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808003F8: bne         $v0, $at, L_80800414
    if (ctx->r2 != ctx->r1) {
        // 0x808003FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800414;
    }
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x80800404: ori         $a2, $a2, 0xD917
    ctx->r6 = ctx->r6 | 0XD917;
    // 0x80800408: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x8080040C: jal         0x8009DF94
    // 0x80800410: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_4;
    // 0x80800410: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
L_80800414:
    // 0x80800414: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800418:
    // 0x80800418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080041C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800420: lw          $v0, 0x15C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X15C);
    // 0x80800424: lui         $a1, 0x3E3C
    ctx->r5 = S32(0X3E3C << 16);
    // 0x80800428: beq         $v0, $at, L_80800448
    if (ctx->r2 == ctx->r1) {
        // 0x8080042C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800448;
    }
    // 0x8080042C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800430: beq         $v0, $at, L_80800468
    if (ctx->r2 == ctx->r1) {
        // 0x80800434: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800468;
    }
    // 0x80800434: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800438: beq         $v0, $at, L_808004A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080043C: nop
    
            goto L_808004A0;
    }
    // 0x8080043C: nop

    // 0x80800440: b           L_808004C8
    // 0x80800444: nop

        goto L_808004C8;
    // 0x80800444: nop

L_80800448:
    // 0x80800448: jal         0x8008B348
    // 0x8080044C: ori         $a1, $a1, 0x1BDA
    ctx->r5 = ctx->r5 | 0X1BDA;
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x8080044C: ori         $a1, $a1, 0x1BDA
    ctx->r5 = ctx->r5 | 0X1BDA;
    after_5:
    // 0x80800450: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800454: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800460;
    }
    // 0x80800454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800458: jal         0x80800064
    // 0x8080045C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    __bsbanbflip_set_substate(rdram, ctx);
        goto after_6;
    // 0x8080045C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_80800460:
    // 0x80800460: b           L_808004C8
    // 0x80800464: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_808004C8;
    // 0x80800464: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800468:
    // 0x80800468: jal         0x80800000
    // 0x8080046C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800000_bsbanbflip(rdram, ctx);
        goto after_7;
    // 0x8080046C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x80800470: jal         0x8008B324
    // 0x80800474: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800474: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x80800478: beq         $v0, $zero, L_80800484
    if (ctx->r2 == 0) {
        // 0x8080047C: addiu       $t6, $zero, 0x2F
        ctx->r14 = ADD32(0, 0X2F);
            goto L_80800484;
    }
    // 0x8080047C: addiu       $t6, $zero, 0x2F
    ctx->r14 = ADD32(0, 0X2F);
    // 0x80800480: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800484:
    // 0x80800484: jal         0x8008DA24
    // 0x80800488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008DA24(rdram, ctx);
        goto after_9;
    // 0x80800488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080048C: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x80800490: addiu       $t7, $zero, 0xA8
        ctx->r15 = ADD32(0, 0XA8);
            goto L_80800498;
    }
    // 0x80800490: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x80800494: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80800498:
    // 0x80800498: b           L_808004C8
    // 0x8080049C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_808004C8;
    // 0x8080049C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_808004A0:
    // 0x808004A0: jal         0x8008B324
    // 0x808004A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isStopped(rdram, ctx);
        goto after_10;
    // 0x808004A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x808004A8: beq         $v0, $zero, L_808004B4
    if (ctx->r2 == 0) {
        // 0x808004AC: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_808004B4;
    }
    // 0x808004AC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808004B0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_808004B4:
    // 0x808004B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004B8: jal         0x800A01F8
    // 0x808004BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A01F8(rdram, ctx);
        goto after_11;
    // 0x808004BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_11:
    // 0x808004C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808004C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_808004C8:
    // 0x808004C8: jal         0x8008E35C
    // 0x808004CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x808004CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_12:
    // 0x808004D0: beq         $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004D4: addiu       $t9, $zero, 0x4C
        ctx->r25 = ADD32(0, 0X4C);
            goto L_808004DC;
    }
    // 0x808004D4: addiu       $t9, $zero, 0x4C
    ctx->r25 = ADD32(0, 0X4C);
    // 0x808004D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_808004DC:
    // 0x808004DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004E0: jal         0x8009E5C8
    // 0x808004E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808004E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_13:
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void func_80802C90_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C98: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x80802C9C: bne         $t6, $zero, L_80802CB4
    if (ctx->r14 != 0) {
        // 0x80802CA0: nop
    
            goto L_80802CB4;
    }
    // 0x80802CA0: nop

    // 0x80802CA4: jal         0x80094BC0
    // 0x80802CA8: nop

    func_80094BC0(rdram, ctx);
        goto after_0;
    // 0x80802CA8: nop

    after_0:
    // 0x80802CAC: b           L_80802CCC
    // 0x80802CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802CCC;
    // 0x80802CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802CB4:
    // 0x80802CB4: jal         0x80085528
    // 0x80802CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _badeathmatch_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80802CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80802CBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802CC0: jal         0x80085540
    // 0x80802CC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _badeathmatch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80802CC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80802CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802CCC:
    // 0x80802CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CD0: jr          $ra
    // 0x80802CD4: nop

    return;
    // 0x80802CD4: nop

;}
RECOMP_FUNC void func_80099A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A58: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A5C: jr          $ra
    // 0x80099A60: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    return;
    // 0x80099A60: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
;}
RECOMP_FUNC void chdinoswitches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1048, 0XC30) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XC30));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XC30));
;}
RECOMP_FUNC void bskazwingwhack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800498: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(300, 0XAB8) << 16);
    // 0x8080049C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004A0: jr          $ra
    // 0x808004A4: lw          $v0, 0xAB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(300, 0XAB8));
    return;
    // 0x808004A4: lw          $v0, 0xAB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(300, 0XAB8));
;}
RECOMP_FUNC void _subaddiemulti_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0A8: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A0A8);
    return;
    // 0x8008A0AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80110770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110778: jal         0x800EE7F8
    // 0x8011077C: addiu       $a0, $a0, 0x74
    ctx->r4 = ADD32(ctx->r4, 0X74);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8011077C: addiu       $a0, $a0, 0x74
    ctx->r4 = ADD32(ctx->r4, 0X74);
    after_0:
    // 0x80110780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110788: jr          $ra
    // 0x8011078C: nop

    return;
    // 0x8011078C: nop

;}
RECOMP_FUNC void func_80103CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103CC0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80103CC4: jal         0x80103BF0
    // 0x80103CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103BF0(rdram, ctx);
        goto after_0;
    // 0x80103CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80103CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103CD4: jr          $ra
    // 0x80103CD8: nop

    return;
    // 0x80103CD8: nop

;}
RECOMP_FUNC void func_80802430_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802430: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80802434: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80802438: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080243C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80802440: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80802444: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80802448: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8080244C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80802450: bgez        $t8, L_80802598
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802454: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80802598;
    }
    // 0x80802454: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80802458: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080245C: jal         0x8008A0E0
    // 0x80802460: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80802460: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802468: jal         0x800DC128
    // 0x8080246C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8080246C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80802470: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80802474: jal         0x800B53A4
    // 0x80802478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80802478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080247C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80802480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D74) << 16);
    // 0x80802484: lwc1        $f6, 0x2D74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D74));
    // 0x80802488: lwc1        $f4, 0x38($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X38);
    // 0x8080248C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1332, 0X3008) << 16);
    // 0x80802490: addiu       $t0, $t0, 0x3008
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1332, 0X3008));
    // 0x80802494: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080249C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808024A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808024A4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808024A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808024AC: jal         0x800BABB8
    // 0x808024B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808024B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x808024B4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808024B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808024BC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808024C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808024C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808024CC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808024D0: nop

    // 0x808024D4: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x808024D8: jal         0x800BA568
    // 0x808024DC: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_800BA568(rdram, ctx);
        goto after_4;
    // 0x808024DC: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_4:
    // 0x808024E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D78) << 16);
    // 0x808024E4: lwc1        $f4, 0x2D78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D78));
    // 0x808024E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D7C) << 16);
    // 0x808024EC: lwc1        $f8, 0x2D7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D7C));
    // 0x808024F0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808024F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024F8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x808024FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80802500: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80802504: jal         0x800BA7C4
    // 0x80802508: nop

    func_800BA7C4(rdram, ctx);
        goto after_5;
    // 0x80802508: nop

    after_5:
    // 0x8080250C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D80) << 16);
    // 0x80802510: lwc1        $f16, 0x2D80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D80));
    // 0x80802514: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D84) << 16);
    // 0x80802518: lwc1        $f4, 0x2D84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D84));
    // 0x8080251C: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80802520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802524: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80802528: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080252C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802530: jal         0x800BA7FC
    // 0x80802534: nop

    func_800BA7FC(rdram, ctx);
        goto after_6;
    // 0x80802534: nop

    after_6:
    // 0x80802538: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8080253C: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80802540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802544: lwc1        $f0, 0x48($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80802548: addiu       $t8, $zero, -0x23
    ctx->r24 = ADD32(0, -0X23);
    // 0x8080254C: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x80802550: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80802554: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80802558: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080255C: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80802560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802564: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x80802568: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080256C: addiu       $a3, $zero, 0x320
    ctx->r7 = ADD32(0, 0X320);
    // 0x80802570: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802574: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80802578: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8080257C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80802580: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80802584: jal         0x800BA994
    // 0x80802588: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800BA994(rdram, ctx);
        goto after_7;
    // 0x80802588: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_7:
    // 0x8080258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802590: jal         0x800BA22C
    // 0x80802594: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x80802594: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_8:
L_80802598:
    // 0x80802598: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080259C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x808025A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808025A4: jr          $ra
    // 0x808025A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808025A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bastatetimer_isActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091570: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80091574: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80091578: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8009157C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80091580: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091584: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80091588: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009158C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80091590: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x80091594: nop

    // 0x80091598: bc1t        L_800915A4
    if (c1cs) {
        // 0x8009159C: nop
    
            goto L_800915A4;
    }
    // 0x8009159C: nop

    // 0x800915A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800915A4:
    // 0x800915A4: jr          $ra
    // 0x800915A8: nop

    return;
    // 0x800915A8: nop

;}
RECOMP_FUNC void func_8080048C_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800494: jal         0x80800000
    // 0x80800498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chfantasydrillfield(rdram, ctx);
        goto after_0;
    // 0x80800498: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080049C: jal         0x800DA298
    // 0x808004A0: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808004A0: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    after_1:
    // 0x808004A4: bnel        $v0, $zero, L_808004C0
    if (ctx->r2 != 0) {
        // 0x808004A8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808004C0;
    }
    goto skip_0;
    // 0x808004A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808004AC: jal         0x800DA544
    // 0x808004B0: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808004B0: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    after_2:
    // 0x808004B4: jal         0x808000C4
    // 0x808004B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000C4_chfantasydrillfield(rdram, ctx);
        goto after_3;
    // 0x808004B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808004BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_808004C0:
    // 0x808004C0: lw          $a0, 0x6C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X6C);
    // 0x808004C4: srl         $t7, $a0, 21
    ctx->r15 = S32(U32(ctx->r4) >> 21);
    // 0x808004C8: jal         0x808003C8
    // 0x808004CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_808003C8_chfantasydrillfield(rdram, ctx);
        goto after_4;
    // 0x808004CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x808004D0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808004D4: sw          $v0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r2;
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void _gcsectionDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088248: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088248);
    return;
    // 0x8008824C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086518: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x80086518);
    return;
    // 0x8008651C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088ED8: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088ED8);
    return;
    // 0x80088EDC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084070: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084070);
    return;
    // 0x80084074: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_8080065C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: jr          $ra
    // 0x80800660: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800660: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chfactorylinkgrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2316, 0X2E0) << 16);
    // 0x808001F8: jr          $ra
    // 0x808001FC: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X2E0));
    return;
    // 0x808001FC: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X2E0));
;}
RECOMP_FUNC void func_80801F00_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F08: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    // 0x80801F0C: beql        $a1, $zero, L_80801F20
    if (ctx->r5 == 0) {
        // 0x80801F10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801F20;
    }
    goto skip_0;
    // 0x80801F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801F14: jal         0x800C8B84
    // 0x80801F18: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80801F18: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F20:
    // 0x80801F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F24: jr          $ra
    // 0x80801F28: nop

    return;
    // 0x80801F28: nop

;}
