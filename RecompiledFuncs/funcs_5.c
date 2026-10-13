#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800068_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1080, 0XB00) << 16);
    // 0x80800078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080007C: jal         0x80086040
    // 0x80800080: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    _chpowerhut_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800080: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    after_0:
    // 0x80800084: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080008C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800090: beq         $t6, $at, L_80800154
    if (ctx->r14 == ctx->r1) {
        // 0x80800094: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800154;
    }
    // 0x80800094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800098: beq         $t6, $at, L_80800154
    if (ctx->r14 == ctx->r1) {
        // 0x8080009C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800154;
    }
    // 0x8080009C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000A0: bne         $t6, $at, L_80800154
    if (ctx->r14 != ctx->r1) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000B0: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x808000B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000BC: bnel        $t7, $at, L_80800120
    if (ctx->r15 != ctx->r1) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800120;
    }
    goto skip_0;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000C4: jal         0x800BF744
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808000D0: jal         0x800BF744
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808000DC: jal         0x800BF744
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808000E8: jal         0x800BF744
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_5;
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000F0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808000F4: jal         0x800BF744
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808000FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800100: jal         0x800BF744
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_7;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80100094
    // 0x80800110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800114: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800118: sb          $t8, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r24;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800120:
    // 0x80800120: jal         0x80100094
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800128: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x8080012C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: bnel        $t9, $at, L_80800158
    if (ctx->r25 != ctx->r1) {
        // 0x80800138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800158;
    }
    goto skip_1;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080013C: jal         0x80100094
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800144: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8080024C
    // 0x80800150: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    func_8080024C_chpowerhutwitchy(rdram, ctx);
        goto after_11;
    // 0x80800150: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_11:
L_80800154:
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800158:
    // 0x80800158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA0: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800CA4: jr          $ra
    // 0x80800CA8: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
    return;
    // 0x80800CA8: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808006F0_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006F8: jal         0x80089758
    // 0x808006FC: nop

    _gemarkersDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006FC: nop

    after_0:
    // 0x80800700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800704: jal         0x800882E8
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080070C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800714: jr          $ra
    // 0x80800718: nop

    return;
    // 0x80800718: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4C0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4C0);
    return;
    // 0x8008A4C4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chprisonbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800E5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800E60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E68: jal         0x80089C30
    // 0x80800E6C: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800E6C: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    after_0:
    // 0x80800E70: beq         $v0, $zero, L_80800ED8
    if (ctx->r2 == 0) {
        // 0x80800E74: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800ED8;
    }
    // 0x80800E74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E78: jal         0x800DA298
    // 0x80800E7C: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800E7C: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    after_1:
    // 0x80800E80: bne         $v0, $zero, L_80800ED8
    if (ctx->r2 != 0) {
        // 0x80800E84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED8;
    }
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E88: jal         0x80100094
    // 0x80800E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E94: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x80800E98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800E9C: addiu       $a3, $zero, 0x430
    ctx->r7 = ADD32(0, 0X430);
    // 0x80800EA0: jal         0x8008A2D0
    // 0x80800EA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800EA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800EA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800EAC: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80800EB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800EB4: addiu       $a1, $zero, 0xF4F
    ctx->r5 = ADD32(0, 0XF4F);
    // 0x80800EB8: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800EBC: jal         0x8008A208
    // 0x80800EC0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800EC0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC8: jal         0x80102424
    // 0x80800ECC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800ECC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x80800ED0: jal         0x800DA544
    // 0x80800ED4: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800ED4: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    after_6:
L_80800ED8:
    // 0x80800ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800EDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EE4: jr          $ra
    // 0x80800EE8: nop

    return;
    // 0x80800EE8: nop

    // 0x80800EEC: nop

;}
RECOMP_FUNC void ncbaspiral_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bssplitup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AA8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AA8);
    return;
    // 0x80083AAC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80801714_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080171C: jal         0x80106790
    // 0x80801720: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801720: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801728: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080172C: jal         0x80102424
    // 0x80801730: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801730: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801734: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801738: lbu         $t7, 0x65($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X65);
    // 0x8080173C: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80801740: jal         0x80803C80
    // 0x80801744: sb          $t8, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r24;
    func_80803C80_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80801744: sb          $t8, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r24;
    after_2:
    // 0x80801748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080174C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801750: jr          $ra
    // 0x80801754: nop

    return;
    // 0x80801754: nop

;}
RECOMP_FUNC void baspin_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: lw          $t6, 0x118($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X118);
    // 0x80800018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80800024: bne         $t7, $at, L_80800054
    if (ctx->r15 != ctx->r1) {
        // 0x80800028: nop
    
            goto L_80800054;
    }
    // 0x80800028: nop

    // 0x8080002C: jal         0x80084C98
    // 0x80800030: nop

    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
    // 0x80800034: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800038: bne         $v0, $at, L_80800054
    if (ctx->r2 != ctx->r1) {
        // 0x8080003C: nop
    
            goto L_80800054;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x800A4CA8
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080004C: jal         0x800893E8
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncba1p_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800054:
    // 0x80800054: jal         0x8009BD88
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD88(rdram, ctx);
        goto after_3;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080005C: jal         0x8008E95C
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_4;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800064: jal         0x800951B4
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_5;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080006C: jal         0x80092BE8
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_6;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800074: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800078: jal         0x8009C914
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800080: jal         0x8009C974
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x800931AC
    // 0x80800090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_9;
    // 0x80800090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_800963E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800963E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800963E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800963EC: jal         0x800963C0
    // 0x800963F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800963C0(rdram, ctx);
        goto after_0;
    // 0x800963F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800963F4: jal         0x80013A7C
    // 0x800963F8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80013A7C(rdram, ctx);
        goto after_1;
    // 0x800963F8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800963FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80096404: jr          $ra
    // 0x80096408: nop

    return;
    // 0x80096408: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036C4: beq         $a0, $zero, L_808036D0
    if (ctx->r4 == 0) {
        // 0x808036C8: nop
    
            goto L_808036D0;
    }
    // 0x808036C8: nop

    // 0x808036CC: sh          $a1, 0x16A($a0)
    MEM_H(0X16A, ctx->r4) = ctx->r5;
L_808036D0:
    // 0x808036D0: jr          $ra
    // 0x808036D4: nop

    return;
    // 0x808036D4: nop

;}
RECOMP_FUNC void func_80800000_bamovespline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80800018: lw          $a1, 0x40($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X40);
    // 0x8080001C: jal         0x800EEB9C
    // 0x80800020: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x80800020: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    after_0:
    // 0x80800024: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x80800028: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080002C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800030: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80800034: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800038: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8080003C: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x80800040: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80800044: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80800048: lw          $a1, 0xC8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC8);
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x80800054: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080005C: jal         0x800D8840
    // 0x80800060: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800D8840(rdram, ctx);
        goto after_2;
    // 0x80800060: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800064: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800068: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080006C: jal         0x800EFA20
    // 0x80800070: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800074: jal         0x800D8840
    // 0x80800078: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800D8840(rdram, ctx);
        goto after_4;
    // 0x80800078: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8080007C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800080: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800084: jal         0x800EFA20
    // 0x80800088: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EFA20(rdram, ctx);
        goto after_5;
    // 0x80800088: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x8080008C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800090: jal         0x800EF3DC
    // 0x80800094: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF3DC(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80800098: jal         0x800D8FF8
    // 0x8080009C: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x8080009C: nop

    after_7:
    // 0x808000A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000A8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808000AC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808000B0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808000B4: jal         0x800EF334
    // 0x808000B8: nop

    func_800EF334(rdram, ctx);
        goto after_8;
    // 0x808000B8: nop

    after_8:
    // 0x808000BC: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x808000C0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808000C4: jal         0x800EF04C
    // 0x808000C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x808000C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x808000CC: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x808000D0: lui         $a1, 0x38D1
    ctx->r5 = S32(0X38D1 << 16);
    // 0x808000D4: ori         $a1, $a1, 0xB717
    ctx->r5 = ctx->r5 | 0XB717;
    // 0x808000D8: jal         0x800F2168
    // 0x808000DC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800F2168(rdram, ctx);
        goto after_10;
    // 0x808000DC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_808020C4_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808020C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808020CC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808020D0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808020D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808020D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808020DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808020E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808020E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808020E8: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x808020EC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808020F0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x808020F4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808020F8: blez        $v0, L_8080214C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808020FC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8080214C;
    }
    // 0x808020FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80802100: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802104: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80802108: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8080210C:
    // 0x8080210C: jal         0x80087AF8
    // 0x80802110: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802110: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_0:
    // 0x80802114: beql        $v0, $zero, L_80802130
    if (ctx->r2 == 0) {
        // 0x80802118: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80802130;
    }
    goto skip_0;
    // 0x80802118: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_0:
    // 0x8080211C: beql        $v0, $s0, L_80802130
    if (ctx->r2 == ctx->r16) {
        // 0x80802120: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80802130;
    }
    goto skip_1;
    // 0x80802120: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_1:
    // 0x80802124: bnel        $v0, $s3, L_80802134
    if (ctx->r2 != ctx->r19) {
        // 0x80802128: lh          $v0, 0x2($s4)
        ctx->r2 = MEM_H(ctx->r20, 0X2);
            goto L_80802134;
    }
    goto skip_2;
    // 0x80802128: lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X2);
    skip_2:
    // 0x8080212C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80802130:
    // 0x80802130: lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X2);
L_80802134:
    // 0x80802134: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80802138: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080213C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802140: bne         $at, $zero, L_8080210C
    if (ctx->r1 != 0) {
        // 0x80802144: nop
    
            goto L_8080210C;
    }
    // 0x80802144: nop

    // 0x80802148: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8080214C:
    // 0x8080214C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    // 0x80802150: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80802154: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80802158: beq         $a0, $zero, L_80802190
    if (ctx->r4 == 0) {
        // 0x8080215C: nop
    
            goto L_80802190;
    }
    // 0x8080215C: nop

    // 0x80802160: jal         0x80087AF8
    // 0x80802164: nop

    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802164: nop

    after_1:
    // 0x80802168: beql        $v0, $zero, L_8080218C
    if (ctx->r2 == 0) {
        // 0x8080216C: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8080218C;
    }
    goto skip_3;
    // 0x8080216C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_3:
    // 0x80802170: beql        $v0, $s0, L_8080218C
    if (ctx->r2 == ctx->r16) {
        // 0x80802174: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8080218C;
    }
    goto skip_4;
    // 0x80802174: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_4:
    // 0x80802178: beql        $v0, $s3, L_8080218C
    if (ctx->r2 == ctx->r19) {
        // 0x8080217C: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8080218C;
    }
    goto skip_5;
    // 0x8080217C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_5:
    // 0x80802180: b           L_80802190
    // 0x80802184: lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X2);
        goto L_80802190;
    // 0x80802184: lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X2);
    // 0x80802188: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8080218C:
    // 0x8080218C: lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X2);
L_80802190:
    // 0x80802190: blezl       $v0, L_80802244
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80802194: lw          $a0, 0x20($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X20);
            goto L_80802244;
    }
    goto skip_6;
    // 0x80802194: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    skip_6:
    // 0x80802198: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
L_8080219C:
    // 0x8080219C: jal         0x80087AF8
    // 0x808021A0: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808021A0: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_2:
    // 0x808021A4: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x808021A8: beq         $at, $zero, L_80802220
    if (ctx->r1 == 0) {
        // 0x808021AC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80802220;
    }
    // 0x808021AC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808021B0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808021B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FE0) << 16);
    // 0x808021B8: addu        $at, $at, $t6
    gpr jr_addend_808021C0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808021BC: lw          $t6, 0x2FE0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FE0));
    // 0x808021C0: jr          $t6
    // 0x808021C4: nop

    switch (jr_addend_808021C0 >> 2) {
        case 0: goto L_808021C8; break;
        case 1: goto L_80802220; break;
        case 2: goto L_808021C8; break;
        case 3: goto L_808021C8; break;
        case 4: goto L_808021EC; break;
        case 5: goto L_80802214; break;
        default: switch_error(__func__, 0x808021C0, 0x80802FE0);
    }
    // 0x808021C4: nop

L_808021C8:
    // 0x808021C8: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x808021CC: lb          $t7, 0x94($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X94);
    // 0x808021D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808021D4: beq         $v0, $t7, L_808021E4
    if (ctx->r2 == ctx->r15) {
        // 0x808021D8: nop
    
            goto L_808021E4;
    }
    // 0x808021D8: nop

    // 0x808021DC: jal         0x80087BE8
    // 0x808021E0: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_3;
    // 0x808021E0: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_3:
L_808021E4:
    // 0x808021E4: b           L_80802228
    // 0x808021E8: sb          $s3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r19;
        goto L_80802228;
    // 0x808021E8: sb          $s3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r19;
L_808021EC:
    // 0x808021EC: bne         $s5, $zero, L_80802228
    if (ctx->r21 != 0) {
        // 0x808021F0: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80802228;
    }
    // 0x808021F0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808021F4: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x808021F8: lb          $t8, 0x94($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X94);
    // 0x808021FC: beq         $v0, $t8, L_8080220C
    if (ctx->r2 == ctx->r24) {
        // 0x80802200: nop
    
            goto L_8080220C;
    }
    // 0x80802200: nop

    // 0x80802204: jal         0x80087B30
    // 0x80802208: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80802208: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_4:
L_8080220C:
    // 0x8080220C: b           L_80802228
    // 0x80802210: sb          $s3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r19;
        goto L_80802228;
    // 0x80802210: sb          $s3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r19;
L_80802214:
    // 0x80802214: addu        $t9, $s4, $s2
    ctx->r25 = ADD32(ctx->r20, ctx->r18);
    // 0x80802218: b           L_80802228
    // 0x8080221C: sb          $v0, 0x94($t9)
    MEM_B(0X94, ctx->r25) = ctx->r2;
        goto L_80802228;
    // 0x8080221C: sb          $v0, 0x94($t9)
    MEM_B(0X94, ctx->r25) = ctx->r2;
L_80802220:
    // 0x80802220: addu        $t0, $s4, $s2
    ctx->r8 = ADD32(ctx->r20, ctx->r18);
    // 0x80802224: sb          $v0, 0x94($t0)
    MEM_B(0X94, ctx->r8) = ctx->r2;
L_80802228:
    // 0x80802228: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x8080222C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80802230: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80802234: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80802238: bne         $at, $zero, L_8080219C
    if (ctx->r1 != 0) {
        // 0x8080223C: nop
    
            goto L_8080219C;
    }
    // 0x8080223C: nop

    // 0x80802240: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
L_80802244:
    // 0x80802244: beql        $a0, $zero, L_808022B8
    if (ctx->r4 == 0) {
        // 0x80802248: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808022B8;
    }
    goto skip_7;
    // 0x80802248: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x8080224C: jal         0x80087AF8
    // 0x80802250: nop

    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80802250: nop

    after_5:
    // 0x80802254: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80802258: beq         $at, $zero, L_808022B0
    if (ctx->r1 == 0) {
        // 0x8080225C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808022B0;
    }
    // 0x8080225C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802260: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80802264: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FF8) << 16);
    // 0x80802268: addu        $at, $at, $t2
    gpr jr_addend_80802270 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8080226C: lw          $t2, 0x2FF8($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FF8));
    // 0x80802270: jr          $t2
    // 0x80802274: nop

    switch (jr_addend_80802270 >> 2) {
        case 0: goto L_80802278; break;
        case 1: goto L_808022B0; break;
        case 2: goto L_80802278; break;
        case 3: goto L_80802278; break;
        case 4: goto L_80802298; break;
        case 5: goto L_808022B0; break;
        case 6: goto L_808022B0; break;
        default: switch_error(__func__, 0x80802270, 0x80802FF8);
    }
    // 0x80802274: nop

L_80802278:
    // 0x80802278: lbu         $t3, 0x24($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X24);
    // 0x8080227C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80802280: beql        $v0, $t3, L_808022B4
    if (ctx->r2 == ctx->r11) {
        // 0x80802284: sb          $s0, 0x24($s4)
        MEM_B(0X24, ctx->r20) = ctx->r16;
            goto L_808022B4;
    }
    goto skip_8;
    // 0x80802284: sb          $s0, 0x24($s4)
    MEM_B(0X24, ctx->r20) = ctx->r16;
    skip_8:
    // 0x80802288: jal         0x80087BE8
    // 0x8080228C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_6;
    // 0x8080228C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    after_6:
    // 0x80802290: b           L_808022B4
    // 0x80802294: sb          $s0, 0x24($s4)
    MEM_B(0X24, ctx->r20) = ctx->r16;
        goto L_808022B4;
    // 0x80802294: sb          $s0, 0x24($s4)
    MEM_B(0X24, ctx->r20) = ctx->r16;
L_80802298:
    // 0x80802298: lbu         $t4, 0x24($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X24);
    // 0x8080229C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808022A0: beql        $v0, $t4, L_808022B4
    if (ctx->r2 == ctx->r12) {
        // 0x808022A4: sb          $s0, 0x24($s4)
        MEM_B(0X24, ctx->r20) = ctx->r16;
            goto L_808022B4;
    }
    goto skip_9;
    // 0x808022A4: sb          $s0, 0x24($s4)
    MEM_B(0X24, ctx->r20) = ctx->r16;
    skip_9:
    // 0x808022A8: jal         0x80087B30
    // 0x808022AC: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808022AC: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    after_7:
L_808022B0:
    // 0x808022B0: sb          $s0, 0x24($s4)
    MEM_B(0X24, ctx->r20) = ctx->r16;
L_808022B4:
    // 0x808022B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808022B8:
    // 0x808022B8: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x808022BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808022C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808022C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808022C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808022CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808022D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808022D4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808022D8: jr          $ra
    // 0x808022DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808022DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808002E0_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808002F8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808002FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800300: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800304: jal         0x80800000
    // 0x80800308: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    func_80800000_glsavegame(rdram, ctx);
        goto after_0;
    // 0x80800308: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    after_0:
    // 0x8080030C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800310: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800314:
    // 0x80800314: jal         0x800884B8
    // 0x80800318: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _glgamestore_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800318: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x8080031C: bne         $v0, $zero, L_80800330
    if (ctx->r2 != 0) {
        // 0x80800320: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800330;
    }
    // 0x80800320: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800328: jal         0x80800020
    // 0x8080032C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800020_glsavegame(rdram, ctx);
        goto after_2;
    // 0x8080032C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
L_80800330:
    // 0x80800330: beq         $s1, $zero, L_80800340
    if (ctx->r17 == 0) {
        // 0x80800334: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800340;
    }
    // 0x80800334: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800338: bnel        $s0, $zero, L_80800314
    if (ctx->r16 != 0) {
        // 0x8080033C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800314;
    }
    goto skip_0;
    // 0x8080033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80800340:
    // 0x80800340: jal         0x8001B084
    // 0x80800344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x80800344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800348: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080034C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800350: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080035C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800364: jr          $ra
    // 0x80800368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800AA054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA05C: jal         0x800A9F60
    // 0x800AA060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A9F60(rdram, ctx);
        goto after_0;
    // 0x800AA060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800AA064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA06C: jr          $ra
    // 0x800AA070: nop

    return;
    // 0x800AA070: nop

;}
RECOMP_FUNC void func_8080015C_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800160: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800164: slti        $at, $a1, 0x2F
    ctx->r1 = SIGNED(ctx->r5) < 0X2F ? 1 : 0;
    // 0x80800168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080016C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800170: bne         $at, $zero, L_8080018C
    if (ctx->r1 != 0) {
        // 0x80800174: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8080018C;
    }
    // 0x80800174: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800178: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080017C: beq         $a1, $at, L_80800218
    if (ctx->r5 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: b           L_8080028C
    // 0x80800188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080028C;
    // 0x80800188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080018C:
    // 0x8080018C: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x80800190: sltiu       $at, $t6, 0x24
    ctx->r1 = ctx->r14 < 0X24 ? 1 : 0;
    // 0x80800194: beq         $at, $zero, L_80800280
    if (ctx->r1 == 0) {
        // 0x80800198: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800280;
    }
    // 0x80800198: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1468, 0X560) << 16);
    // 0x808001A0: addu        $at, $at, $t6
    gpr jr_addend_808001A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001A4: lw          $t6, 0x560($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1468, 0X560));
    // 0x808001A8: jr          $t6
    // 0x808001AC: nop

    switch (jr_addend_808001A8 >> 2) {
        case 0: goto L_808001B0; break;
        case 1: goto L_80800280; break;
        case 2: goto L_80800280; break;
        case 3: goto L_80800280; break;
        case 4: goto L_80800280; break;
        case 5: goto L_80800280; break;
        case 6: goto L_80800280; break;
        case 7: goto L_80800280; break;
        case 8: goto L_80800280; break;
        case 9: goto L_80800280; break;
        case 10: goto L_80800280; break;
        case 11: goto L_80800280; break;
        case 12: goto L_80800280; break;
        case 13: goto L_80800280; break;
        case 14: goto L_80800280; break;
        case 15: goto L_80800280; break;
        case 16: goto L_80800280; break;
        case 17: goto L_80800280; break;
        case 18: goto L_80800280; break;
        case 19: goto L_80800280; break;
        case 20: goto L_80800264; break;
        case 21: goto L_80800280; break;
        case 22: goto L_80800280; break;
        case 23: goto L_80800280; break;
        case 24: goto L_80800280; break;
        case 25: goto L_80800280; break;
        case 26: goto L_80800280; break;
        case 27: goto L_80800280; break;
        case 28: goto L_80800280; break;
        case 29: goto L_80800280; break;
        case 30: goto L_80800238; break;
        case 31: goto L_80800250; break;
        case 32: goto L_80800280; break;
        case 33: goto L_80800280; break;
        case 34: goto L_80800280; break;
        case 35: goto L_808001F4; break;
        default: switch_error(__func__, 0x808001A8, 0x80800560);
    }
    // 0x808001AC: nop

L_808001B0:
    // 0x808001B0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808001B4: bne         $a3, $at, L_808001EC
    if (ctx->r7 != ctx->r1) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001C0: jal         0x808002FC
    // 0x808001C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808002FC_chklungospiral(rdram, ctx);
        goto after_0;
    // 0x808001C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808001C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001CC: addiu       $t7, $zero, 0xAB
    ctx->r15 = ADD32(0, 0XAB);
    // 0x808001D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808001D4: addiu       $a1, $zero, 0x1638
    ctx->r5 = ADD32(0, 0X1638);
    // 0x808001D8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808001DC: jal         0x8008A208
    // 0x808001E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808001E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808001E4: b           L_8080028C
    // 0x808001E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080028C;
    // 0x808001E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808001EC:
    // 0x808001EC: b           L_8080028C
    // 0x808001F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080028C;
    // 0x808001F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001F4:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x808001FC: jal         0x808003AC
    // 0x80800200: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808003AC_chklungospiral(rdram, ctx);
        goto after_2;
    // 0x80800200: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80102424
    // 0x8080020C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080020C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800210: b           L_8080028C
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800218:
    // 0x80800218: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080021C: and         $a2, $a3, $at
    ctx->r6 = ctx->r7 & ctx->r1;
    // 0x80800220: srl         $t8, $a2, 16
    ctx->r24 = S32(U32(ctx->r6) >> 16);
    // 0x80800224: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80800228: jal         0x808002A0
    // 0x8080022C: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_808002A0_chklungospiral(rdram, ctx);
        goto after_4;
    // 0x8080022C: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_4:
    // 0x80800230: b           L_80800290
    // 0x80800234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800290;
    // 0x80800234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800238:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800240: jal         0x800897C0
    // 0x80800244: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800244: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    after_5:
    // 0x80800248: b           L_8080028C
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800250:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x800897C8
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080025C: b           L_8080028C
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800264:
    // 0x80800264: jal         0x801015D0
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_7;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080026C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800270: jal         0x800DF744
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800278: b           L_8080028C
    // 0x8080027C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x8080027C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800280:
    // 0x80800280: b           L_8080028C
    // 0x80800284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080028C;
    // 0x80800284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080028C:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800290:
    // 0x80800290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_80019224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019224: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019228: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001922C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80019230: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x80019234: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019238: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001923C: addiu       $a0, $a0, -0x4350
    ctx->r4 = ADD32(ctx->r4, -0X4350);
    // 0x80019240: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x80019244: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019248: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8001924C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019250: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80019254: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80019258: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001925C: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80019260: beq         $v1, $a1, L_800192B4
    if (ctx->r3 == ctx->r5) {
        // 0x80019264: addu        $v0, $t6, $v1
        ctx->r2 = ADD32(ctx->r14, ctx->r3);
            goto L_800192B4;
    }
    // 0x80019264: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
L_80019268:
    // 0x80019268: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001926C: lwc1        $f14, 0x4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80019270: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019274: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019278: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001927C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019280: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80019284: lwc1        $f14, 0x30($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80019288: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001928C: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019290: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80019294: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80019298: add.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8001929C: add.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800192A0: swc1        $f8, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800192A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800192A8: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800192AC: bne         $v1, $a1, L_80019268
    if (ctx->r3 != ctx->r5) {
        // 0x800192B0: addu        $v0, $t6, $v1
        ctx->r2 = ADD32(ctx->r14, ctx->r3);
            goto L_80019268;
    }
    // 0x800192B0: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
L_800192B4:
    // 0x800192B4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800192B8: lwc1        $f14, 0x4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800192BC: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800192C0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800192C4: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800192C8: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800192CC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800192D0: lwc1        $f14, 0x30($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800192D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800192D8: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800192DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800192E0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800192E4: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800192E8: add.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x800192EC: add.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800192F0: swc1        $f8, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800192F4: jr          $ra
    // 0x800192F8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800192F8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_808004A4_chdinofamilymissing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: beq         $a1, $at, L_80800588
    if (ctx->r5 == ctx->r1) {
        // 0x808004B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800588;
    }
    // 0x808004B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808004B8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808004BC: beq         $a1, $at, L_808004F4
    if (ctx->r5 == ctx->r1) {
        // 0x808004C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808004F4;
    }
    // 0x808004C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004C4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808004C8: beq         $a1, $at, L_808004E4
    if (ctx->r5 == ctx->r1) {
        // 0x808004CC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808004E4;
    }
    // 0x808004CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004D0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808004D4: beq         $a1, $at, L_80800564
    if (ctx->r5 == ctx->r1) {
        // 0x808004D8: addiu       $a0, $a3, 0x4
        ctx->r4 = ADD32(ctx->r7, 0X4);
            goto L_80800564;
    }
    // 0x808004D8: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x808004DC: b           L_80800618
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800618;
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004E4:
    // 0x808004E4: jal         0x80800324
    // 0x808004E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800324_chdinofamilymissing(rdram, ctx);
        goto after_0;
    // 0x808004E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808004EC: b           L_8080061C
    // 0x808004F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080061C;
    // 0x808004F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F4:
    // 0x808004F4: jal         0x801015D0
    // 0x808004F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x808004F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808004FC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800500: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2260, 0X664) << 16);
    // 0x80800504: addiu       $at, $zero, 0x14D
    ctx->r1 = ADD32(0, 0X14D);
    // 0x80800508: lhu         $t6, 0x72($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X72);
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800510: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800514: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800518: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080051C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800520: lhu         $t9, 0x664($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(2260, 0X664));
    // 0x80800524: bne         $t9, $at, L_8080053C
    if (ctx->r25 != ctx->r1) {
        // 0x80800528: nop
    
            goto L_8080053C;
    }
    // 0x80800528: nop

    // 0x8080052C: jal         0x800DF744
    // 0x80800530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800530: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80800534: b           L_80800618
    // 0x80800538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800618;
    // 0x80800538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080053C:
    // 0x8080053C: jal         0x800DF744
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800544: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800548: jal         0x800DF744
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800550: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800554: jal         0x800DF744
    // 0x80800558: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800558: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080055C: b           L_80800618
    // 0x80800560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800618;
    // 0x80800560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800564:
    // 0x80800564: jal         0x80088098
    // 0x80800568: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800568: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_6:
    // 0x8080056C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800570: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2260, 0X6CC) << 16);
    // 0x80800574: addiu       $a0, $a0, 0x6CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2260, 0X6CC));
    // 0x80800578: jal         0x80088090
    // 0x8080057C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080057C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_7:
    // 0x80800580: b           L_80800618
    // 0x80800584: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800618;
    // 0x80800584: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800588:
    // 0x80800588: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080058C: bne         $a2, $at, L_80800610
    if (ctx->r6 != ctx->r1) {
        // 0x80800590: nop
    
            goto L_80800610;
    }
    // 0x80800590: nop

    // 0x80800594: jal         0x80088840
    // 0x80800598: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x80800598: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_8:
    // 0x8080059C: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005A0: nop
    
            goto L_80800610;
    }
    // 0x808005A0: nop

    // 0x808005A4: jal         0x800DA298
    // 0x808005A8: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808005A8: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_9:
    // 0x808005AC: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005B0: nop
    
            goto L_808005D8;
    }
    // 0x808005B0: nop

    // 0x808005B4: jal         0x800DA298
    // 0x808005B8: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808005B8: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_10:
    // 0x808005BC: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005C0: addiu       $a0, $zero, 0x114
        ctx->r4 = ADD32(0, 0X114);
            goto L_808005D8;
    }
    // 0x808005C0: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x808005C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808005C8: jal         0x80088868
    // 0x808005CC: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_11;
    // 0x808005CC: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_11:
    // 0x808005D0: b           L_80800618
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800618;
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005D8:
    // 0x808005D8: jal         0x800DA298
    // 0x808005DC: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x808005DC: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_12:
    // 0x808005E0: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005E4: nop
    
            goto L_80800608;
    }
    // 0x808005E4: nop

    // 0x808005E8: jal         0x800DA298
    // 0x808005EC: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x808005EC: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_13:
    // 0x808005F0: bne         $v0, $zero, L_80800608
    if (ctx->r2 != 0) {
        // 0x808005F4: nop
    
            goto L_80800608;
    }
    // 0x808005F4: nop

    // 0x808005F8: jal         0x800DA298
    // 0x808005FC: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808005FC: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_14:
    // 0x80800600: bne         $v0, $zero, L_80800610
    if (ctx->r2 != 0) {
        // 0x80800604: nop
    
            goto L_80800610;
    }
    // 0x80800604: nop

L_80800608:
    // 0x80800608: jal         0x80088830
    // 0x8080060C: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_15;
    // 0x8080060C: nop

    after_15:
L_80800610:
    // 0x80800610: b           L_80800618
    // 0x80800614: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800618;
    // 0x80800614: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080061C:
    // 0x8080061C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800620: jr          $ra
    // 0x80800624: nop

    return;
    // 0x80800624: nop

;}
RECOMP_FUNC void func_80800994_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080099C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009A0: jal         0x8008CABC
    // 0x808009A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808009A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009AC: jal         0x8008AF24
    // 0x808009B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808009B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x8008B1A0
    // 0x808009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C4: jal         0x8008B188
    // 0x808009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_3;
    // 0x808009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x8008AED4
    // 0x808009D4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808009D4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x808009D8: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808009DC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808009E0: jal         0x8008B1BC
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: jal         0x8008B134
    // 0x808009F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808009F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808009F4: jal         0x8008B064
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808009FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800A00: sw          $zero, 0x15C($t6)
    MEM_W(0X15C, ctx->r14) = 0;
    // 0x80800A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A10: jr          $ra
    // 0x80800A14: nop

    return;
    // 0x80800A14: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866D8: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866D8);
    return;
    // 0x800866DC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80090528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009052C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090534: jal         0x800F54E4
    // 0x80090538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009053C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090540: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090544: jal         0x800F7C0C
    // 0x80090548: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7C0C(rdram, ctx);
        goto after_1;
    // 0x80090548: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8009054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090554: jr          $ra
    // 0x80090558: nop

    return;
    // 0x80090558: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F80: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F80);
    return;
    // 0x80087F84: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_808000D0_chfactorylobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2212, 0X1A8) << 16);
    // 0x808000DC: addiu       $a2, $a2, 0x1A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2212, 0X1A8));
    // 0x808000E0: jal         0x8008A1E8
    // 0x808000E4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808000E4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808000E8: beql        $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x808000EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000FC;
    }
    goto skip_0;
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000F0: jal         0x80086B58
    // 0x808000F4: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000F4: nop

    after_1:
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000FC:
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034B4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808034B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808034BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808034C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808034C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808034C8: jal         0x800F53D0
    // 0x808034CC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808034CC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x808034D0: lw          $s2, 0x188($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X188);
    // 0x808034D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808034D8: jal         0x808027A8
    // 0x808034DC: lh          $a0, 0xE8($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XE8);
    func_808027A8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808034DC: lh          $a0, 0xE8($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XE8);
    after_1:
    // 0x808034E0: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x808034E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808034E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808034EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034F0: jal         0x808035EC
    // 0x808034F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_808035EC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808034F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x808034F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808034FC: jal         0x800EF368
    // 0x80803500: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x80803500: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    after_3:
    // 0x80803504: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80803508: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8080350C: jal         0x800EE780
    // 0x80803510: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x80803510: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80803514: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80803518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080351C: jal         0x800EF368
    // 0x80803520: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x80803520: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x80803524: jal         0x8009C984
    // 0x80803528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_6;
    // 0x80803528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080352C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80803530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803534: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA45C) << 16);
    // 0x80803538: lwc1        $f10, -0x5BA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA45C));
    // 0x8080353C: lwc1        $f8, 0x1D4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X1D4);
    // 0x80803540: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80803544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803548: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080354C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80803550: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80803554: jal         0x800EF1B8
    // 0x80803558: nop

    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x80803558: nop

    after_7:
    // 0x8080355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803560: jal         0x8009E0AC
    // 0x80803564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009E0AC(rdram, ctx);
        goto after_8;
    // 0x80803564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80803568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080356C: jal         0x80802A40
    // 0x80803570: lh          $a1, 0xE8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XE8);
    func_80802A40_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80803570: lh          $a1, 0xE8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XE8);
    after_9:
    // 0x80803574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803578: jal         0x8009E0AC
    // 0x8080357C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E0AC(rdram, ctx);
        goto after_10;
    // 0x8080357C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80803580: jal         0x80084AF0
    // 0x80803584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80803584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80803588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080358C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803590: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80803594: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803598: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080359C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808035A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808035A8: jal         0x800854E0
    // 0x808035AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _bainvisible_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x808035AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x808035B0: lh          $a1, 0xE8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XE8);
    // 0x808035B4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x808035B8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808035BC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x808035C0: jal         0x80084A50
    // 0x808035C4: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    _baeggsetup_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808035C4: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_13:
    // 0x808035C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035CC: jal         0x80802CD8
    // 0x808035D0: lh          $a1, 0xE8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XE8);
    func_80802CD8_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x808035D0: lh          $a1, 0xE8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XE8);
    after_14:
    // 0x808035D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808035D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808035DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808035E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808035E4: jr          $ra
    // 0x808035E8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808035E8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mlspline_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017E0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808017E4: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x808017E8: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x808017EC: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x808017F0: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808017F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808017F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808017FC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80801800: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x80801804: sw          $s4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r20;
    // 0x80801808: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8080180C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80801810: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80801814: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80801818: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8080181C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801820: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801824: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80801828: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x8080182C: bne         $at, $zero, L_80801840
    if (ctx->r1 != 0) {
        // 0x80801830: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80801840;
    }
    // 0x80801830: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80801834: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80801838: b           L_80801848
    // 0x8080183C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
        goto L_80801848;
    // 0x8080183C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
L_80801840:
    // 0x80801840: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801844: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
L_80801848:
    // 0x80801848: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8080184C: jal         0x800F2100
    // 0x80801850: lwc1        $f12, 0xBC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XBC);
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x80801850: lwc1        $f12, 0xBC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XBC);
    after_0:
    // 0x80801854: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C70) << 16);
    // 0x80801858: lwc1        $f28, 0x1C70($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C70));
    // 0x8080185C: lw          $s0, 0xC4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC4);
    // 0x80801860: addiu       $s5, $sp, 0x8C
    ctx->r21 = ADD32(ctx->r29, 0X8C);
    // 0x80801864: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x80801868: lwc1        $f12, 0xB8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8080186C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801870: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801874: bc1f        L_80801884
    if (!c1cs) {
        // 0x80801878: nop
    
            goto L_80801884;
    }
    // 0x80801878: nop

    // 0x8080187C: b           L_80801C08
    // 0x80801880: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
        goto L_80801C08;
    // 0x80801880: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
L_80801884:
    // 0x80801884: jalr        $s0
    // 0x80801888: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r16)(rdram, ctx);
        goto after_1;
    // 0x80801888: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_1:
    // 0x8080188C: jal         0x800EEF94
    // 0x80801890: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EEF94(rdram, ctx);
        goto after_2;
    // 0x80801890: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x80801894: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x80801898: lwc1        $f12, 0xBC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8080189C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808018A0: nop

    // 0x808018A4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808018A8: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808018AC: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x808018B0: div.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x808018B4: jal         0x800F2100
    // 0x808018B8: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808018B8: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808018BC: lwc1        $f2, 0xB8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x808018C0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x808018C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808018CC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x808018D0: lwc1        $f30, 0xC0($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x808018D4: add.s       $f24, $f2, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x808018D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808018DC:
    // 0x808018DC: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x808018E0: lwc1        $f2, 0xB8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x808018E4: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x808018E8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808018EC: nop

    // 0x808018F0: bc1fl       L_808019F8
    if (!c1cs) {
        // 0x808018F4: c.eq.s      $f30, $f26
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl == ctx->f26.fl;
            goto L_808019F8;
    }
    goto skip_0;
    // 0x808018F4: c.eq.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl == ctx->f26.fl;
    skip_0:
    // 0x808018F8: c.le.s      $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f26.fl <= ctx->f24.fl;
    // 0x808018FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801900: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801904: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80801908: bc1fl       L_808019D8
    if (!c1cs) {
        // 0x8080190C: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_808019D8;
    }
    goto skip_1;
    // 0x8080190C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x80801910: c.eq.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl == ctx->f26.fl;
    // 0x80801914: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801918: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080191C: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80801920: bc1fl       L_80801968
    if (!c1cs) {
        // 0x80801924: add.s       $f22, $f24, $f30
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f30.fl;
            goto L_80801968;
    }
    goto skip_2;
    // 0x80801924: add.s       $f22, $f24, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f30.fl;
    skip_2:
    // 0x80801928: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080192C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80801930: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x80801934: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801938: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x8080193C: jal         0x80801488
    // 0x80801940: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_4;
    // 0x80801940: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_4:
    // 0x80801944: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80801948: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080194C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801950: nop

    // 0x80801954: bc1f        L_80801B28
    if (!c1cs) {
        // 0x80801958: nop
    
            goto L_80801B28;
    }
    // 0x80801958: nop

    // 0x8080195C: b           L_80801B28
    // 0x80801960: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80801B28;
    // 0x80801960: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80801964: add.s       $f22, $f24, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f30.fl;
L_80801968:
    // 0x80801968: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080196C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80801970: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80801974: trunc.w.s   $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80801978: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080197C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801980: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801984: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80801988: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x8080198C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801990: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80801994: nop

    // 0x80801998: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080199C: jal         0x80801488
    // 0x808019A0: sub.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f8.fl;
    func_80801488_mlspline(rdram, ctx);
        goto after_5;
    // 0x808019A0: sub.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f8.fl;
    after_5:
    // 0x808019A4: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808019A8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808019AC: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x808019B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808019B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808019B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808019BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808019C0: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x808019C4: jal         0x80801488
    // 0x808019C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_6;
    // 0x808019C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_6:
    // 0x808019CC: b           L_80801B28
    // 0x808019D0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
        goto L_80801B28;
    // 0x808019D0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x808019D4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_808019D8:
    // 0x808019D8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808019DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808019E0: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x808019E4: jal         0x80801488
    // 0x808019E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_7;
    // 0x808019E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_7:
    // 0x808019EC: b           L_80801B28
    // 0x808019F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80801B28;
    // 0x808019F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808019F4: c.eq.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl == ctx->f26.fl;
L_808019F8:
    // 0x808019F8: nop

    // 0x808019FC: bc1fl       L_80801A84
    if (!c1cs) {
        // 0x80801A00: c.lt.s      $f24, $f30
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f24.fl < ctx->f30.fl;
            goto L_80801A84;
    }
    goto skip_3;
    // 0x80801A00: c.lt.s      $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f24.fl < ctx->f30.fl;
    skip_3:
    // 0x80801A04: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80801A08: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x80801A0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801A10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801A14: bc1f        L_80801A60
    if (!c1cs) {
        // 0x80801A18: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_80801A60;
    }
    // 0x80801A18: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80801A1C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801A20: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801A24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80801A28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801A2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801A30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801A34: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80801A38: jal         0x80801488
    // 0x80801A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_8;
    // 0x80801A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_8:
    // 0x80801A40: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80801A44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801A48: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80801A4C: nop

    // 0x80801A50: bc1f        L_80801B28
    if (!c1cs) {
        // 0x80801A54: nop
    
            goto L_80801B28;
    }
    // 0x80801A54: nop

    // 0x80801A58: b           L_80801B28
    // 0x80801A5C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80801B28;
    // 0x80801A5C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801A60:
    // 0x80801A60: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801A64: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801A68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801A6C: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80801A70: jal         0x80801488
    // 0x80801A74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_9;
    // 0x80801A74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_9:
    // 0x80801A78: b           L_80801B28
    // 0x80801A7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80801B28;
    // 0x80801A7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801A80: c.lt.s      $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f24.fl < ctx->f30.fl;
L_80801A84:
    // 0x80801A84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801A88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801A8C: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80801A90: bc1fl       L_80801B10
    if (!c1cs) {
        // 0x80801A94: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80801B10;
    }
    goto skip_4;
    // 0x80801A94: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_4:
    // 0x80801A98: sub.s       $f22, $f24, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x80801A9C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801AA0: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80801AA4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80801AA8: trunc.w.s   $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    ctx->f16.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80801AAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801AB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801AB8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80801ABC: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80801AC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AC4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80801AC8: nop

    // 0x80801ACC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801AD0: sub.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x80801AD4: jal         0x80801488
    // 0x80801AD8: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    func_80801488_mlspline(rdram, ctx);
        goto after_10;
    // 0x80801AD8: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    after_10:
    // 0x80801ADC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80801AE0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801AE4: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x80801AE8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801AEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801AF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801AF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801AF8: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80801AFC: jal         0x80801488
    // 0x80801B00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_11;
    // 0x80801B00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_11:
    // 0x80801B04: b           L_80801B28
    // 0x80801B08: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
        goto L_80801B28;
    // 0x80801B08: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80801B0C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80801B10:
    // 0x80801B10: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801B14: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801B18: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80801B1C: jal         0x80801488
    // 0x80801B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80801488_mlspline(rdram, ctx);
        goto after_12;
    // 0x80801B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_12:
    // 0x80801B24: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80801B28:
    // 0x80801B28: bne         $s3, $zero, L_80801BEC
    if (ctx->r19 != 0) {
        // 0x80801B2C: lwc1        $f6, 0x7C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_80801BEC;
    }
    // 0x80801B2C: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80801B30: jal         0x800F2100
    // 0x80801B34: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_13;
    // 0x80801B34: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    after_13:
    // 0x80801B38: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x80801B3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801B40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801B44: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80801B48: bc1fl       L_80801BF0
    if (!c1cs) {
        // 0x80801B4C: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_80801BF0;
    }
    goto skip_5;
    // 0x80801B4C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    skip_5:
    // 0x80801B50: jalr        $s0
    // 0x80801B54: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    LOOKUP_FUNC(ctx->r16)(rdram, ctx);
        goto after_14;
    // 0x80801B54: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_14:
    // 0x80801B58: jal         0x800EEF94
    // 0x80801B5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EEF94(rdram, ctx);
        goto after_15;
    // 0x80801B5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_15:
    // 0x80801B60: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801B64: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80801B68: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801B6C: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80801B70: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80801B74: jal         0x800F2100
    // 0x80801B78: sub.s       $f24, $f22, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = ctx->f22.fl - ctx->f12.fl;
    mlAbsF(rdram, ctx);
        goto after_16;
    // 0x80801B78: sub.s       $f24, $f22, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = ctx->f22.fl - ctx->f12.fl;
    after_16:
    // 0x80801B7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C74) << 16);
    // 0x80801B80: lwc1        $f4, 0x1C74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C74));
    // 0x80801B84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801B88: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80801B8C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801B90: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80801B94: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80801B98: bc1fl       L_80801BA8
    if (!c1cs) {
        // 0x80801B9C: c.lt.s      $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
            goto L_80801BA8;
    }
    goto skip_6;
    // 0x80801B9C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    skip_6:
    // 0x80801BA0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80801BA4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
L_80801BA8:
    // 0x80801BA8: nop

    // 0x80801BAC: bc1fl       L_80801BD4
    if (!c1cs) {
        // 0x80801BB0: c.lt.s      $f18, $f24
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
            goto L_80801BD4;
    }
    goto skip_7;
    // 0x80801BB0: c.lt.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
    skip_7:
    // 0x80801BB4: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    // 0x80801BB8: nop

    // 0x80801BBC: bc1f        L_80801BF0
    if (!c1cs) {
        // 0x80801BC0: nop
    
            goto L_80801BF0;
    }
    // 0x80801BC0: nop

    // 0x80801BC4: sub.s       $f10, $f26, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f30.fl;
    // 0x80801BC8: b           L_80801BF0
    // 0x80801BCC: add.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f10.fl;
        goto L_80801BF0;
    // 0x80801BCC: add.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x80801BD0: c.lt.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
L_80801BD4:
    // 0x80801BD4: nop

    // 0x80801BD8: bc1f        L_80801BF0
    if (!c1cs) {
        // 0x80801BDC: nop
    
            goto L_80801BF0;
    }
    // 0x80801BDC: nop

    // 0x80801BE0: sub.s       $f4, $f26, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f30.fl;
    // 0x80801BE4: b           L_80801BF0
    // 0x80801BE8: sub.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f4.fl;
        goto L_80801BF0;
    // 0x80801BE8: sub.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f4.fl;
L_80801BEC:
    // 0x80801BEC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801BF0:
    // 0x80801BF0: bne         $s3, $zero, L_80801C04
    if (ctx->r19 != 0) {
        // 0x80801BF4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80801C04;
    }
    // 0x80801BF4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80801BF8: slti        $at, $s4, 0xA
    ctx->r1 = SIGNED(ctx->r20) < 0XA ? 1 : 0;
    // 0x80801BFC: bnel        $at, $zero, L_808018DC
    if (ctx->r1 != 0) {
        // 0x80801C00: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808018DC;
    }
    goto skip_8;
    // 0x80801C00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_8:
L_80801C04:
    // 0x80801C04: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_80801C08:
    // 0x80801C08: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80801C0C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801C10: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801C14: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80801C18: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80801C1C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80801C20: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80801C24: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x80801C28: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80801C2C: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80801C30: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x80801C34: lw          $s4, 0x64($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X64);
    // 0x80801C38: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x80801C3C: jr          $ra
    // 0x80801C40: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80801C40: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80801C44: nop

    // 0x80801C48: nop

    // 0x80801C4C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080067C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800680: jr          $ra
    // 0x80800684: sh          $a0, 0x75EC($at)
    MEM_H(0X75EC, ctx->r1) = ctx->r4;
    return;
    // 0x80800684: sh          $a0, 0x75EC($at)
    MEM_H(0X75EC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _gczoombox_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C28: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C28);
    return;
    // 0x80087C2C: addi        $t0, $zero, 0xA4
    ctx->r8 = ADD32(0, 0XA4);
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891D8: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x800891D8);
    return;
    // 0x800891DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E6950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6950: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E6954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E6958: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E695C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800E6960: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E6964: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E6968: jal         0x800D5A6C
    // 0x800E696C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D5A6C(rdram, ctx);
        goto after_0;
    // 0x800E696C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E6970: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800E6974: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E6978: jal         0x8001E210
    // 0x800E697C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800E697C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800E6980: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800E6984: srl         $t6, $a0, 16
    ctx->r14 = S32(U32(ctx->r4) >> 16);
    // 0x800E6988: sll         $s1, $t6, 4
    ctx->r17 = S32(ctx->r14 << 4);
    // 0x800E698C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6990: jal         0x800D5FDC
    // 0x800E6994: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    func_800D5FDC(rdram, ctx);
        goto after_2;
    // 0x800E6994: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    after_2:
    // 0x800E6998: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800E699C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E69A0: bnel        $v0, $zero, L_800E69C4
    if (ctx->r2 != 0) {
        // 0x800E69A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800E69C4;
    }
    goto skip_0;
    // 0x800E69A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_0:
    // 0x800E69A8: jal         0x8001ACEC
    // 0x800E69AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    heap_alloc_sided(rdram, ctx);
        goto after_3;
    // 0x800E69AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800E69B0: bne         $v0, $zero, L_800E69C4
    if (ctx->r2 != 0) {
        // 0x800E69B4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800E69C4;
    }
    // 0x800E69B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E69B8: b           L_800E69EC
    // 0x800E69BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E69EC;
    // 0x800E69BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E69C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800E69C4:
    // 0x800E69C4: jal         0x800D5950
    // 0x800E69C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800D5950(rdram, ctx);
        goto after_4;
    // 0x800E69C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x800E69CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E69D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E69D4: jal         0x80117248
    // 0x800E69D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80117248(rdram, ctx);
        goto after_5;
    // 0x800E69D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800E69DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E69E0: jal         0x8002E660
    // 0x800E69E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_6;
    // 0x800E69E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800E69E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800E69EC:
    // 0x800E69EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E69F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E69F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E69F8: jr          $ra
    // 0x800E69FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800E69FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800000_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8009EA64
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009EA64(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800018: jal         0x80089C30
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800020: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080002C: jal         0x8009B9B0
    // 0x80800030: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800030: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
    after_2:
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x800A34E4
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A34E4(rdram, ctx);
        goto after_3;
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x800961AC
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x8080004C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80800050: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080005C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800060: jal         0x8009FFD8
    // 0x80800064: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800070: jal         0x800947EC
    // 0x80800074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_6;
    // 0x80800074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80800078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080007C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void _anseq_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082630: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082630);
    return;
    // 0x80082634: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chboilerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D70: syscall     238
    recomp_syscall_handler(rdram, ctx, 0x80085D70);
    return;
    // 0x80085D74: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chflowerbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086650: syscall     353
    recomp_syscall_handler(rdram, ctx, 0x80086650);
    return;
    // 0x80086654: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bssnowball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A70: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A70);
    return;
    // 0x80083A74: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80103C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80103CA0: jal         0x80103BF0
    // 0x80103CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103BF0(rdram, ctx);
        goto after_0;
    // 0x80103CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80103CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103CB0: jr          $ra
    // 0x80103CB4: nop

    return;
    // 0x80103CB4: nop

;}
RECOMP_FUNC void func_808001F8_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x808001FC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800204: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800208: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8080020C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800210: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800214: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800218: jal         0x800D8FF8
    // 0x8080021C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080021C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x80800220: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80800224: lw          $t6, 0x78($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X78);
    // 0x80800228: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x8080022C: bgezl       $t8, L_8080025C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800230: lw          $t0, 0x64($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X64);
            goto L_8080025C;
    }
    goto skip_0;
    // 0x80800230: lw          $t0, 0x64($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X64);
    skip_0:
    // 0x80800234: lwc1        $f4, 0x50($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80800238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080023C: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    // 0x80800240: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800244: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800248: jal         0x800D0778
    // 0x8080024C: nop

    func_800D0778(rdram, ctx);
        goto after_1;
    // 0x8080024C: nop

    after_1:
    // 0x80800250: b           L_808002EC
    // 0x80800254: lw          $t3, 0x7C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X7C);
        goto L_808002EC;
    // 0x80800254: lw          $t3, 0x7C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X7C);
    // 0x80800258: lw          $t0, 0x64($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X64);
L_8080025C:
    // 0x8080025C: addiu       $s1, $sp, 0x94
    ctx->r17 = ADD32(ctx->r29, 0X94);
    // 0x80800260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800264: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80800268: bgez        $t2, L_808002E8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080026C: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_808002E8;
    }
    // 0x8080026C: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80800270: jal         0x800EE7F8
    // 0x80800274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800278: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080027C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800280: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80800284: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80800288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080028C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800290: jal         0x800EE7F8
    // 0x80800294: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800294: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80800298: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080029C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A0: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A8: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x808002AC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808002B0: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x808002B4: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x808002B8: jal         0x800BEF00
    // 0x808002BC: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x808002BC: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    after_4:
    // 0x808002C0: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002C4: lwc1        $f16, 0xA0($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_808002D4;
    }
    // 0x808002C4: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x808002C8: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808002CC: b           L_808002E8
    // 0x808002D0: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
        goto L_808002E8;
    // 0x808002D0: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_808002D4:
    // 0x808002D4: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x808002D8: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x808002DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002E0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x808002E4: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
L_808002E8:
    // 0x808002E8: lw          $t3, 0x7C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X7C);
L_808002EC:
    // 0x808002EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808002F0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808002F4: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x808002F8: bgezl       $t5, L_8080040C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808002FC: lhu         $t6, 0x72($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X72);
            goto L_8080040C;
    }
    goto skip_1;
    // 0x808002FC: lhu         $t6, 0x72($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X72);
    skip_1:
    // 0x80800300: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800304: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800308: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
L_8080030C:
    // 0x8080030C: jal         0x800DC0C0
    // 0x80800310: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800310: nop

    after_5:
    // 0x80800314: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(704, 0X760) << 16);
    // 0x80800318: lwc1        $f8, 0x760($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(704, 0X760));
    // 0x8080031C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800320: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800324: nop

    // 0x80800328: bc1fl       L_80800374
    if (!c1cs) {
        // 0x8080032C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800374;
    }
    goto skip_2;
    // 0x8080032C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80800330: jal         0x80103DFC
    // 0x80800334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80103DFC(rdram, ctx);
        goto after_6;
    // 0x80800334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800338: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8080033C: jal         0x800DC178
    // 0x80800340: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800340: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_7:
    // 0x80800344: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800348: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8080034C: jal         0x800DC178
    // 0x80800350: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800350: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_8:
    // 0x80800354: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800358: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: jal         0x800EF214
    // 0x80800364: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800EF214(rdram, ctx);
        goto after_9;
    // 0x80800364: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_9:
    // 0x80800368: jal         0x80088AA8
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800370: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800374:
    // 0x80800374: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800378: bne         $s1, $at, L_8080030C
    if (ctx->r17 != ctx->r1) {
        // 0x8080037C: nop
    
            goto L_8080030C;
    }
    // 0x8080037C: nop

    // 0x80800380: lwc1        $f10, 0x58($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800384: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80800388: nop

    // 0x8080038C: bc1fl       L_8080040C
    if (!c1cs) {
        // 0x80800390: lhu         $t6, 0x72($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X72);
            goto L_8080040C;
    }
    goto skip_3;
    // 0x80800390: lhu         $t6, 0x72($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X72);
    skip_3:
    // 0x80800394: jal         0x800DC0C0
    // 0x80800398: nop

    func_800DC0C0(rdram, ctx);
        goto after_11;
    // 0x80800398: nop

    after_11:
    // 0x8080039C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808003A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003A4: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808003A8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808003AC: div.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x808003B0: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808003B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003B8: nop

    // 0x808003BC: bc1fl       L_80800400
    if (!c1cs) {
        // 0x808003C0: lwc1        $f18, 0xA0($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_80800400;
    }
    goto skip_4;
    // 0x808003C0: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    skip_4:
    // 0x808003C4: jal         0x800B5BE4
    // 0x808003C8: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    func_800B5BE4(rdram, ctx);
        goto after_12;
    // 0x808003C8: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    after_12:
    // 0x808003CC: jal         0x80088AF8
    // 0x808003D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    _fxgenlist_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808003D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_13:
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808003E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003E4: jal         0x800BABB8
    // 0x808003E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_14;
    // 0x808003E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_14:
    // 0x808003EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003F0: jal         0x800BA22C
    // 0x808003F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_15;
    // 0x808003F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808003F8: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808003FC: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
L_80800400:
    // 0x80800400: sub.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80800404: swc1        $f6, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f6.u32l;
    // 0x80800408: lhu         $t6, 0x72($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X72);
L_8080040C:
    // 0x8080040C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800410: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800414: bnel        $t7, $at, L_80800480
    if (ctx->r15 != ctx->r1) {
        // 0x80800418: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800480;
    }
    goto skip_5;
    // 0x80800418: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x8080041C: lw          $v0, 0x78($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X78);
    // 0x80800420: sll         $t9, $v0, 28
    ctx->r25 = S32(ctx->r2 << 28);
    // 0x80800424: bgez        $t9, L_80800474
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800428: nop
    
            goto L_80800474;
    }
    // 0x80800428: nop

    // 0x8080042C: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x80800430: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x8080043C: beq         $t1, $zero, L_80800474
    if (ctx->r9 == 0) {
        // 0x80800440: nop
    
            goto L_80800474;
    }
    // 0x80800440: nop

    // 0x80800444: jal         0x800EE7F8
    // 0x80800448: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80800448: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_16:
    // 0x8080044C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800450: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800454: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080045C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800460: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x80800464: lw          $a0, 0x6C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X6C);
    // 0x80800468: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x8080046C: jal         0x800C8CB8
    // 0x80800470: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_17;
    // 0x80800470: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_17:
L_80800474:
    // 0x80800474: jal         0x8080011C
    // 0x80800478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080011C_chjigsaw(rdram, ctx);
        goto after_18;
    // 0x80800478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_18:
    // 0x8080047C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800480:
    // 0x80800480: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800484: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800488: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8080048C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800490: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800494: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800498: jr          $ra
    // 0x8080049C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8080049C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void _cheggclockwork_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871D8: syscall     534
    recomp_syscall_handler(rdram, ctx, 0x800871D8);
    return;
    // 0x800871DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800AE40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE40C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800AE410: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AE414: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800AE418: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800AE41C: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800AE420: sll         $a0, $t6, 16
    ctx->r4 = S32(ctx->r14 << 16);
    // 0x800AE424: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AE428: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AE42C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE430: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AE434: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800AE438: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800AE43C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800AE440: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AE444: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AE448: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AE44C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AE450: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AE454: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x800AE458: jal         0x800AE080
    // 0x800AE45C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800AE45C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800AE460: lh          $s2, 0x4($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X4);
    // 0x800AE464: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AE468: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AE46C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800AE470: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800AE474: beq         $at, $zero, L_800AE49C
    if (ctx->r1 == 0) {
        // 0x800AE478: sra         $t9, $a0, 16
        ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
            goto L_800AE49C;
    }
    // 0x800AE478: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE47C: sll         $a1, $s2, 6
    ctx->r5 = S32(ctx->r18 << 6);
    // 0x800AE480: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x800AE484: jal         0x8001B710
    // 0x800AE488: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800AE488: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800AE48C: lh          $t0, 0x4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4);
    // 0x800AE490: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800AE494: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800AE498: lh          $s2, 0x4($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X4);
L_800AE49C:
    // 0x800AE49C: sll         $t2, $s2, 6
    ctx->r10 = S32(ctx->r18 << 6);
    // 0x800AE4A0: addu        $s4, $t2, $v0
    ctx->r20 = ADD32(ctx->r10, ctx->r2);
    // 0x800AE4A4: addiu       $s4, $s4, 0x50
    ctx->r20 = ADD32(ctx->r20, 0X50);
    // 0x800AE4A8: addiu       $s0, $v0, 0x50
    ctx->r16 = ADD32(ctx->r2, 0X50);
    // 0x800AE4AC: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x800AE4B0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800AE4B4: beq         $at, $zero, L_800AE568
    if (ctx->r1 == 0) {
        // 0x800AE4B8: addiu       $s1, $s3, 0x8
        ctx->r17 = ADD32(ctx->r19, 0X8);
            goto L_800AE568;
    }
    // 0x800AE4B8: addiu       $s1, $s3, 0x8
    ctx->r17 = ADD32(ctx->r19, 0X8);
    // 0x800AE4BC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x800AE4C0: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
    // 0x800AE4C4: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800AE4C8: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x800AE4CC: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_800AE4D0:
    // 0x800AE4D0: lh          $a1, 0xC($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XC);
    // 0x800AE4D4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x800AE4D8: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x800AE4DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800AE4E0: jal         0x800DFB7C
    // 0x800AE4E4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800DFB7C(rdram, ctx);
        goto after_2;
    // 0x800AE4E4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_2:
    // 0x800AE4E8: lh          $v0, 0xE($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XE);
    // 0x800AE4EC: addiu       $v1, $s5, 0x50
    ctx->r3 = ADD32(ctx->r21, 0X50);
    // 0x800AE4F0: subu        $t3, $s0, $v1
    ctx->r11 = SUB32(ctx->r16, ctx->r3);
    // 0x800AE4F4: bne         $fp, $v0, L_800AE50C
    if (ctx->r30 != ctx->r2) {
        // 0x800AE4F8: sra         $t4, $t3, 6
        ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
            goto L_800AE50C;
    }
    // 0x800AE4F8: sra         $t4, $t3, 6
    ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
    // 0x800AE4FC: jal         0x80019CD4
    // 0x800AE500: nop

    func_80019CD4(rdram, ctx);
        goto after_3;
    // 0x800AE500: nop

    after_3:
    // 0x800AE504: b           L_800AE520
    // 0x800AE508: nop

        goto L_800AE520;
    // 0x800AE508: nop

L_800AE50C:
    // 0x800AE50C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800AE510: beq         $t4, $t5, L_800AE520
    if (ctx->r12 == ctx->r13) {
        // 0x800AE514: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_800AE520;
    }
    // 0x800AE514: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800AE518: jal         0x80018EFC
    // 0x800AE51C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    mlMtxSet(rdram, ctx);
        goto after_4;
    // 0x800AE51C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_4:
L_800AE520:
    // 0x800AE520: jal         0x800D9C4C
    // 0x800AE524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800D9C4C(rdram, ctx);
        goto after_5;
    // 0x800AE524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800AE528: bne         $v0, $zero, L_800AE540
    if (ctx->r2 != 0) {
        // 0x800AE52C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AE540;
    }
    // 0x800AE52C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AE530: jal         0x800D9CE8
    // 0x800AE534: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800D9CE8(rdram, ctx);
        goto after_6;
    // 0x800AE534: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x800AE538: jal         0x80019BB8
    // 0x800AE53C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80019BB8(rdram, ctx);
        goto after_7;
    // 0x800AE53C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800AE540:
    // 0x800AE540: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800AE544: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AE548: jal         0x80019D30
    // 0x800AE54C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    mlMtxScale_xyz(rdram, ctx);
        goto after_8;
    // 0x800AE54C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    after_8:
    // 0x800AE550: jal         0x80018AD0
    // 0x800AE554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlMtxGet(rdram, ctx);
        goto after_9;
    // 0x800AE554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800AE558: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800AE55C: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x800AE560: bne         $at, $zero, L_800AE4D0
    if (ctx->r1 != 0) {
        // 0x800AE564: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800AE4D0;
    }
    // 0x800AE564: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_800AE568:
    // 0x800AE568: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800AE56C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AE570: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AE574: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AE578: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE57C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800AE580: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800AE584: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800AE588: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE58C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800AE590: jr          $ra
    // 0x800AE594: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800AE594: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_808000C8_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2004, 0X520) << 16);
    // 0x808000DC: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2004, 0X520));
    // 0x808000E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: jal         0x80089D50
    // 0x808000E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808000EC: jal         0x800D9078
    // 0x808000F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808000F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x808000F4: beql        $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000F8: lw          $t6, 0x7C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7C);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000F8: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x808000FC: jal         0x8010A590
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_2;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800104: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800108:
    // 0x80800108: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080010C: bgez        $t8, L_8080014C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800110: nop
    
            goto L_8080014C;
    }
    // 0x80800110: nop

    // 0x80800114: jal         0x800DA298
    // 0x80800118: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800118: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_3:
    // 0x8080011C: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800120: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2004, 0X510) << 16);
            goto L_8080014C;
    }
    // 0x80800120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2004, 0X510) << 16);
    // 0x80800124: jal         0x800DC298
    // 0x80800128: lwc1        $f12, 0x510($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2004, 0X510));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80800128: lwc1        $f12, 0x510($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2004, 0X510));
    after_4:
    // 0x8080012C: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800130: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080014C;
    }
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80100094
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800144: jal         0x800862C0
    // 0x80800148: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    _chelectricfence_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800148: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    after_6:
L_8080014C:
    // 0x8080014C: jal         0x80086240
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_808034CC_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808034D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808034D4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808034D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808034DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808034E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808034E4: jal         0x800EE7F8
    // 0x808034E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808034E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808034EC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808034F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808034F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808034F8: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808034FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80803500: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80803504: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80803508: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080350C: jal         0x800EF1B8
    // 0x80803510: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80803510: nop

    after_1:
    // 0x80803514: jal         0x800CBD84
    // 0x80803518: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800CBD84(rdram, ctx);
        goto after_2;
    // 0x80803518: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8080351C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80803520: bne         $v0, $at, L_80803530
    if (ctx->r2 != ctx->r1) {
        // 0x80803524: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_80803530;
    }
    // 0x80803524: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80803528: b           L_80803580
    // 0x8080352C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803580;
    // 0x8080352C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803530:
    // 0x80803530: jal         0x800EE7F8
    // 0x80803534: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80803534: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80803538: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8080353C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80803540: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803544: lwc1        $f10, 0x48($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80803548: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8080354C: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80803550: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80803554: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80803558: jal         0x800EF1B8
    // 0x8080355C: nop

    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x8080355C: nop

    after_4:
    // 0x80803560: jal         0x800CBD84
    // 0x80803564: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800CBD84(rdram, ctx);
        goto after_5;
    // 0x80803564: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80803568: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080356C: bnel        $v0, $at, L_80803580
    if (ctx->r2 != ctx->r1) {
        // 0x80803570: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80803580;
    }
    goto skip_0;
    // 0x80803570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80803574: b           L_80803580
    // 0x80803578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803580;
    // 0x80803578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080357C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803580:
    // 0x80803580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803584: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803588: jr          $ra
    // 0x8080358C: nop

    return;
    // 0x8080358C: nop

;}
RECOMP_FUNC void func_808017F0_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808017FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801800: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801804: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80801808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080180C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80801810: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80801814: beq         $t6, $zero, L_80801830
    if (ctx->r14 == 0) {
        // 0x80801818: addiu       $a1, $zero, 0x2A
        ctx->r5 = ADD32(0, 0X2A);
            goto L_80801830;
    }
    // 0x80801818: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080181C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801820: beq         $t6, $at, L_80801838
    if (ctx->r14 == ctx->r1) {
        // 0x80801824: nop
    
            goto L_80801838;
    }
    // 0x80801824: nop

    // 0x80801828: b           L_80801870
    // 0x8080182C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_80801870;
    // 0x8080182C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80801830:
    // 0x80801830: jal         0x800856B0
    // 0x80801834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80801838:
    // 0x80801838: jal         0x800856E0
    // 0x8080183C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080183C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80801840: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80801844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801848: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8080184C: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80801850: jal         0x800880A8
    // 0x80801854: sh          $t9, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r25;
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801854: sh          $t9, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r25;
    after_2:
    // 0x80801858: jal         0x800880B8
    // 0x8080185C: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x8080185C: nop

    after_3:
    // 0x80801860: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80801864: jal         0x800856D8
    // 0x80801868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80801868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080186C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80801870:
    // 0x80801870: addiu       $t0, $zero, 0x6A
    ctx->r8 = ADD32(0, 0X6A);
    // 0x80801874: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801878: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080187C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801880: jal         0x8008A208
    // 0x80801884: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801884: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80801888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080188C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801890: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801894: jr          $ra
    // 0x80801898: nop

    return;
    // 0x80801898: nop

;}
RECOMP_FUNC void _subaddieaudioquick_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D10: syscall     809
    recomp_syscall_handler(rdram, ctx, 0x80089D10);
    return;
    // 0x80089D14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800008_chTalTorpWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: bne         $a1, $at, L_80800054
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800054;
    }
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080001C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800020: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800024: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800028: jal         0x80086670
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2040, 0X80) << 16);
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800038: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080003C: jal         0x80089D18
    // 0x80800040: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2040, 0X80));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2040, 0X80));
    after_1:
    // 0x80800044: jal         0x800DA544
    // 0x80800048: addiu       $a0, $zero, 0x3AA
    ctx->r4 = ADD32(0, 0X3AA);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a0, $zero, 0x3AA
    ctx->r4 = ADD32(0, 0X3AA);
    after_2:
    // 0x8080004C: b           L_80800058
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800058;
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800054:
    // 0x80800054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800058:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_808000F0_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x808000FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800100: jal         0x80800020
    // 0x80800104: addiu       $a3, $zero, 0x63
    ctx->r7 = ADD32(0, 0X63);
    func_80800020_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x80800104: addiu       $a3, $zero, 0x63
    ctx->r7 = ADD32(0, 0X63);
    after_0:
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080010C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083068: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083068);
    return;
    // 0x8008306C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsfirstp_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808032B0: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB474) << 16);
    // 0x808032B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808032B8: jr          $ra
    // 0x808032BC: lw          $v0, -0x4B8C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB474));
    return;
    // 0x808032BC: lw          $v0, -0x4B8C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB474));
;}
RECOMP_FUNC void func_800C8C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8C94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C8C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8C9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8CA0: jal         0x800EE830
    // 0x800C8CA4: addiu       $a0, $a0, -0x54FC
    ctx->r4 = ADD32(ctx->r4, -0X54FC);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800C8CA4: addiu       $a0, $a0, -0x54FC
    ctx->r4 = ADD32(ctx->r4, -0X54FC);
    after_0:
    // 0x800C8CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8CB0: jr          $ra
    // 0x800C8CB4: nop

    return;
    // 0x800C8CB4: nop

;}
RECOMP_FUNC void func_800F88A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F88A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F88A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800F88A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F88AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F88B0: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    // 0x800F88B4: jal         0x800B28C4
    // 0x800F88B8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800F88B8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F88BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F88C0: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    // 0x800F88C4: jal         0x800B296C
    // 0x800F88C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800F88C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800F88CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800F88D0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800F88D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F88D8: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800F88DC: beq         $at, $zero, L_800F8908
    if (ctx->r1 == 0) {
        // 0x800F88E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F8908;
    }
    // 0x800F88E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F88E4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_800F88E8:
    // 0x800F88E8: bnel        $a1, $t6, L_800F88FC
    if (ctx->r5 != ctx->r14) {
        // 0x800F88EC: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_800F88FC;
    }
    goto skip_0;
    // 0x800F88EC: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    skip_0:
    // 0x800F88F0: b           L_800F890C
    // 0x800F88F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800F890C;
    // 0x800F88F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F88F8: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
L_800F88FC:
    // 0x800F88FC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800F8900: bnel        $at, $zero, L_800F88E8
    if (ctx->r1 != 0) {
        // 0x800F8904: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_800F88E8;
    }
    goto skip_1;
    // 0x800F8904: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_1:
L_800F8908:
    // 0x800F8908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F890C:
    // 0x800F890C: jr          $ra
    // 0x800F8910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F8910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800000_fxrain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800004: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800010: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800014: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800018: jal         0x800B2928
    // 0x8080001C: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x8080001C: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x80800020: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80800024: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800028: beql        $at, $zero, L_808001D4
    if (ctx->r1 == 0) {
        // 0x8080002C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808001D4;
    }
    goto skip_0;
    // 0x8080002C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800030: jal         0x800E3980
    // 0x80800034: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_1:
    // 0x80800038: jal         0x800E3958
    // 0x8080003C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800E3958(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x80800040: jal         0x800E3A58
    // 0x80800044: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800E3A58(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x80800048: jal         0x800B2974
    // 0x8080004C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    vector_push_back(rdram, ctx);
        goto after_4;
    // 0x8080004C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_4:
    // 0x80800050: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800054: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800058: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8080005C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800060: jal         0x800DC178
    // 0x80800064: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800064: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800068: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080006C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800070: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800074: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800078: jal         0x800DC178
    // 0x8080007C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080007C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x80800080: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x80800084: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800088: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8080008C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800090: jal         0x800EFA4C
    // 0x80800094: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800094: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800098: jal         0x800EEFD4
    // 0x8080009C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800EEFD4(rdram, ctx);
        goto after_8;
    // 0x8080009C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_8:
    // 0x808000A0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808000A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000A8: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x808000AC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808000B0: nop

    // 0x808000B4: bc1fl       L_808000EC
    if (!c1cs) {
        // 0x808000B8: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_808000EC;
    }
    goto skip_1;
    // 0x808000B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x808000BC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808000C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808000C8: jal         0x800DC178
    // 0x808000CC: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808000CC: nop

    after_9:
    // 0x808000D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000D8: jal         0x800EF934
    // 0x808000DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EF934(rdram, ctx);
        goto after_10;
    // 0x808000DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x808000E0: b           L_8080011C
    // 0x808000E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
        goto L_8080011C;
    // 0x808000E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_808000EC:
    // 0x808000EC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F4: jal         0x800DC178
    // 0x808000F8: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x808000F8: nop

    after_11:
    // 0x808000FC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800100: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800104: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800108: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8080010C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800110: jal         0x800EF934
    // 0x80800114: nop

    func_800EF934(rdram, ctx);
        goto after_12;
    // 0x80800114: nop

    after_12:
    // 0x80800118: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_8080011C:
    // 0x8080011C: jal         0x800EF04C
    // 0x80800120: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x80800120: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_13:
    // 0x80800124: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800128: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080012C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800130: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800134: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80800138: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080013C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800140: bc1fl       L_8080019C
    if (!c1cs) {
        // 0x80800144: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080019C;
    }
    goto skip_2;
    // 0x80800144: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x80800148: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080014C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800150: jal         0x800E3F8C
    // 0x80800154: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    func_800E3F8C(rdram, ctx);
        goto after_14;
    // 0x80800154: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    after_14:
    // 0x80800158: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x8080015C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80800198;
    }
    // 0x8080015C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800160: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800164: nop

    // 0x80800168: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
L_8080016C:
    // 0x8080016C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800170: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80800174: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80800178: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080017C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800180: beq         $at, $zero, L_80800198
    if (ctx->r1 == 0) {
        // 0x80800184: swc1        $f6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
            goto L_80800198;
    }
    // 0x80800184: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800188: jal         0x800E3F8C
    // 0x8080018C: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    func_800E3F8C(rdram, ctx);
        goto after_15;
    // 0x8080018C: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    after_15:
    // 0x80800190: bnel        $v0, $zero, L_8080016C
    if (ctx->r2 != 0) {
        // 0x80800194: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8080016C;
    }
    goto skip_3;
    // 0x80800194: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    skip_3:
L_80800198:
    // 0x80800198: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_8080019C:
    // 0x8080019C: jal         0x800EE7F8
    // 0x808001A0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x808001A0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x808001A4: lui         $at, 0xC4C8
    ctx->r1 = S32(0XC4C8 << 16);
    // 0x808001A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8D0) << 16);
    // 0x808001B0: jal         0x800DC178
    // 0x808001B4: lwc1        $f14, 0x8D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8D0));
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x808001B4: lwc1        $f14, 0x8D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8D0));
    after_17:
    // 0x808001B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808001C4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808001C8: jal         0x800EFA4C
    // 0x808001CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_18;
    // 0x808001CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_18:
    // 0x808001D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001D4:
    // 0x808001D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001D8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808001DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808001E0: jr          $ra
    // 0x808001E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808001E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800D8840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8840: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D8844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8848: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D884C: jr          $ra
    // 0x800D8850: lwc1        $f0, -0x469C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X469C);
    return;
    // 0x800D8850: lwc1        $f0, -0x469C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X469C);
;}
